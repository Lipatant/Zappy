/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** src/Main.cpp
*/

#include <iostream>
#include <mutex>
#include <string.h>
#include <thread>
#include "Citadel/Exception.hpp"
#include "Citadel/Instance.hpp"
#include "Mortymere/Instance.hpp"
#include "Utility/Connect.hpp"
#include "Utility/Regex.hpp"

//    citadel << "pnw 1 0 0 3 0 0\n";
//    citadel << "pnw 2 1 0 2 0 0\n";
//    citadel << "ppo 2 2 2 1\n";

#define CATCH_EXCEPTION_COMMAND(EXCEPTION, VARIABLE) \
    catch (Citadel::Exception::Command::EXCEPTION &VARIABLE) \
    { std::cerr << e.what() << std::endl; }

struct Locks_s {
    std::mutex citadel;
    std::mutex close;
    std::mutex closeEngine;
};

static void engineThread(Citadel::Instance &citadel, bool &close, \
    Locks_s &locks, int const port, std::string const &ip, bool isManualUsed, \
    bool const isDisplayInputUsed)
{
    std::string infoServ;
    Connect Connect(ip, port);

    if (!isManualUsed) {
        try {
            Connect.join();
            Connect.sender("GRAPHIC\n");
        } catch (std::exception const& e) {
                std::cerr << e.what() << std::endl;
                close = true;
                return;
        }
    }
    while (1) {
        locks.close.lock();
        if (close)
            break;
        locks.close.unlock();
        if (isManualUsed) {
            std::getline(std::cin, infoServ);
            if (infoServ.empty())
                continue;
            if (infoServ == "exit") {
                locks.close.lock();
                close = true;
                break;
            }
        } else {
            try {
                infoServ = Connect.receive();
            } catch (std::exception const& e) {
                infoServ = "";
                break;
            }
            if (infoServ.empty())
                continue;
        }
        locks.citadel.lock();
        if (isDisplayInputUsed)
            std::cerr << infoServ << std::endl;
        try { citadel << infoServ; }
        CATCH_EXCEPTION_COMMAND(InvalidAmountArguments, e)
        CATCH_EXCEPTION_COMMAND(TooFewArguments, e)
        CATCH_EXCEPTION_COMMAND(TooManyArguments, e)
        CATCH_EXCEPTION_COMMAND(InvalidArgument, e)
        locks.citadel.unlock();
    }
    locks.close.unlock();
}

static bool start(int const port, std::string const &machine, bool const \
    isManualUsed, bool const isDisplayInputUsed)
{
    bool close = false;
    Mortymere::Instance engine;
    Locks_s locks = {std::mutex(), std::mutex(), std::mutex()};
    Citadel::Instance citadel(engine);
    std::thread thread(engineThread, std::ref(citadel), std::ref(close), \
        std::ref(locks), port, std::ref(machine), isManualUsed, \
        isDisplayInputUsed);

    while (citadel.udpate()) {
        locks.close.lock();
        if (close) {
            locks.close.unlock();
            break;
        }
        locks.close.unlock();
    }
    locks.close.lock();
    close = true;
    locks.close.unlock();
    thread.join();
    return true;
}

#define REGEX_MACHINE "^.+$"
#define REGEX_PORT "^\\d+$"

int main(int const ac, char const * const * const av)
{
    bool isPortDefined = false;
    bool isMachineDefined = false;
    bool isManualUsed = false;
    bool isDisplayInputUsed = false;
    int port = -1;
    std::string machine = "127.0.0.1";

    for (int i = 1; i < ac; i++) {
        if (strcmp("-p", av[i]) == 0) {
            if (isPortDefined) {
                std::cerr << "-p is already defined as '" << port << '\'' << \
                    std::endl;
                return 84;
            }
            if (!utility::regex::quickTest(av[i + 1], REGEX_PORT)) {
                std::cerr << '\'' << av[i + 1] << \
                    "' doesn't match the expression '" << REGEX_PORT << '\'' \
                    << std::endl;
                return 84;
            }
            port = std::stoi(av[i + 1]);
            isPortDefined = true;
            i++;
            continue;
        }
        if (strcmp("-m", av[i]) == 0) {
            if (isMachineDefined) {
                std::cerr << "-m is already defined as '" << machine << '\'' \
                    << std::endl;
                return 84;
            }
            if (!utility::regex::quickTest(av[i + 1], REGEX_MACHINE)) {
                std::cerr << '\'' << av[i + 1] << \
                    "' doesn't match the expression '" << REGEX_MACHINE << \
                    '\'' << std::endl;
                return 84;
            }
            machine = av[i + 1];
            isMachineDefined = true;
            i++;
            continue;
        }
        if (strcmp("--manual", av[i]) == 0) {
            isManualUsed = true;
            continue;
        }
        if (strcmp("--displayInput", av[i]) == 0) {
            isDisplayInputUsed = true;
            continue;
        }
        std::cerr << "Unknown flag '" << av[i] << '\'' << std::endl;
        return 84;
    }
    if (!isPortDefined && !isManualUsed) {
        std::cerr << "Port is undefined" << std::endl;
        return 84;
    }
    if (!start(port, machine, isManualUsed, isDisplayInputUsed))
        return 84;
    return 0;
}
