/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Connect
*/

#include <chrono>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <cstring>
#include "Citadel/Exception.hpp"
#include "Utility/Connect.hpp"

Connect::Connect(std::string ip, int port) : _ip(ip), _port(port)
{

}

void Connect::join(void)
{
    _serverAddress.sin_family = AF_INET;
    _serverAddress.sin_port = htons(_port);
    _serverAddress.sin_addr.s_addr = inet_addr(_ip.c_str());
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (_sockfd == -1) {
        Exception Exception("Socket create failed.");
        throw Exception;
    }
    _connect = connect(_sockfd, reinterpret_cast<struct sockaddr*>(&_serverAddress), sizeof(_serverAddress));
    if (_connect < 0) {
        close(_sockfd);
        Exception Exception("Connection to the server failed");
        throw Exception;
    }
}

Connect::~Connect()
{
    close(_sockfd);
}

std::string Connect::receive()
{
    std::string buffer(10000, 0);
    std::string message;
    const std::chrono::seconds timeout(1);
    auto startTime = std::chrono::steady_clock::now();
    int flags = fcntl(_sockfd, F_GETFL, 0);
    int read_mess = 0;
    fcntl(_sockfd, F_SETFL, flags | O_NONBLOCK);

    while (1) {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
        if (elapsedTime >= timeout)
            return "";
        read_mess = read(_sockfd, &buffer[0], buffer.size() - 1);
        if (read_mess < 0) {
            if (errno == EAGAIN)
                return "";
            std::cerr << "Read error." << std::endl;
            return "";
        } else if (read_mess == 0) {
            break;
        } else {
            buffer.resize(read_mess);
            break;
        }
    }
    flags = fcntl(_sockfd, F_GETFL, 0);
    fcntl(_sockfd, F_SETFL, flags & (~O_NONBLOCK));
    message = buffer;
    return message;
}


void Connect::sender(std::string msg)
{
    int flags = fcntl(_sockfd, F_GETFL, 0);
    fcntl(_sockfd, F_SETFL, flags | O_NONBLOCK);
    int sent = 0;
    int size_mess = msg.size();
    int error_send = 0;
    const std::chrono::seconds timeout(1);
    auto startTime = std::chrono::steady_clock::now();

    while (size_mess > 0) {
        error_send = send(_sockfd, msg.c_str() + sent, size_mess, 0);
        if (error_send == -1) {
            if (errno == EAGAIN) {
                auto currentTime = std::chrono::steady_clock::now();
                auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
                if (elapsedTime >= timeout)
                    return;
            }
            if (error_send == -1) {
                Exception exception("Sending error.");
                throw exception;
            }
        } else {
            sent += error_send;
            size_mess -= error_send;
        }
    }
}
