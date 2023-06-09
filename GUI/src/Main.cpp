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
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
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

int connectServer(const std::string serverIP, int port)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        std::cerr << "Erreur lors de la création du socket." << std::endl;
        return 1;
    }
    struct sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = inet_addr(serverIP.c_str());
    if (connect(sockfd, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) < 0) {
        std::cerr << "Échec de la connexion au serveur." << std::endl;
        close(sockfd);
        return 1;
    }
    close(sockfd);
    return 0;
}

static void engineThread(Citadel::Instance &citadel, bool &close, \
    Locks_s &locks, char const * const * const av)
{
    std::string userInput;
    std::string ip = "127.0.0.1";
    int port = std::stoi(av[1]);

    if (av[2] != nullptr)
        ip = av[2];
    if (connectServer(ip, port) == 1) {
        close = true;
        return;
    }
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

int main(FLAG_UNUSED int const ac, char const * const * const av)
{
    bool close = false;
    Mortymere::Instance engine;
    if (ac < 2 || ac > 3)
        return 84;
    Locks_s locks = {std::mutex(), std::mutex(), std::mutex()};
    Citadel::Instance citadel(engine);
    std::thread thread(engineThread, std::ref(citadel), std::ref(close), \
        std::ref(locks), av);

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
