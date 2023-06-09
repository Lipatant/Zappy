/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Connect
*/

#ifndef CONNECT_HPP_
    #define CONNECT_HPP_

    #include <arpa/inet.h>
    #include <string>
    #include <sys/socket.h>

class Connect {
    public:
        Connect(char *ip, int port);
        ~Connect();
        char *getIp() const { return _ip; };
        int getPort() const { return _port; };
        std::string receive();

    protected:
    private:
        char *_ip;
        int _port;
        int _sockfd;
        int _connect;
        struct sockaddr_in _serverAddress;
        class Exception : public std::exception {
            public:
                Exception(std::string message) : _message(message) {};
                ~Exception() = default;
                const char *what() const noexcept override { return _message.c_str(); };
            private:
                std::string _message;
        };
};

#endif /* !CONNECT_HPP_ */
