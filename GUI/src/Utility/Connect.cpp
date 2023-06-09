/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Connect
*/

#include "Utility/Connect.hpp"
#include <iostream>
#include <unistd.h>

Connect::Connect(std::string ip, int port) : _ip(ip), _port(port)
{
    _serverAddress.sin_family = AF_INET;
    _serverAddress.sin_port = htons(_port);
    _serverAddress.sin_addr.s_addr = inet_addr(_ip.c_str());
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (_sockfd == -1) {
        close(_sockfd);
        Exception exception("Erreur lors de la création du socket.");
        throw exception;
    }
    _connect = connect(_sockfd, reinterpret_cast<struct sockaddr*>(&_serverAddress), sizeof(_serverAddress));
    if (_connect < 0) {
        close(_sockfd);
        Exception exception("Échec de la connexion au serveur.");
        throw exception;
    }
}

Connect::~Connect()
{
    close(_sockfd);
}

std::string Connect::receive()
{
    char buffer[1024] = {0};
    std::string message;

    read(_sockfd, buffer, 1024);
    message = buffer;
    return message;
}
