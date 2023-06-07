/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** src/Main.cpp
*/

#include <mutex>
#include <thread>
#include "Flags.hpp"
#include "Citadel/Instance.hpp"
#include "Mortymere/Instance.hpp"

#include <iostream>
#include "Citadel/Exception.hpp"

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
    Locks_s &locks)
{
    std::string userInput;

    locks.citadel.lock();
    locks.citadel.unlock();
    while (1) {
        locks.close.lock();
        if (close)
            break;
        locks.close.unlock();
        std::getline(std::cin, userInput);
        if (userInput.empty())
            continue;
        if (userInput == "exit") {
            locks.close.lock();
            close = true;
            break;
        }
        locks.citadel.lock();
        try { citadel << userInput; }
        CATCH_EXCEPTION_COMMAND(InvalidAmountArguments, e)
        CATCH_EXCEPTION_COMMAND(TooFewArguments, e)
        CATCH_EXCEPTION_COMMAND(TooManyArguments, e)
        CATCH_EXCEPTION_COMMAND(InvalidArgument, e)
        locks.citadel.unlock();
    }
    locks.close.unlock();
}

int main(FLAG_UNUSED int const ac, FLAG_UNUSED char const * const * const av)
{
    bool close = false;
    Mortymere::Instance engine;
    Locks_s locks = {std::mutex(), std::mutex(), std::mutex()};
    Citadel::Instance citadel(engine);
    std::thread thread(engineThread, std::ref(citadel), std::ref(close), \
        std::ref(locks));

    while (engine.udpate()) {
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
    return 0;
}
