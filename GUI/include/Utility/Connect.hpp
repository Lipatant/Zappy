/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Connect
*/

/// @file
/// @brief Contain function to the connection to the server

#ifndef CONNECT_HPP_
    #define CONNECT_HPP_

    #include <arpa/inet.h>
    #include <string>
    #include <sys/socket.h>

class Connect {
    public:

        /// @brief Constructor of the class Connect
        /// @param string std::string ip
        /// @param int int for the recuperation of the port4
        Connect(std::string ip, int port);

        /// @brief Destructor of the class Connect
        ~Connect();

        /// @brief Getter of the IP
        std::string getIp() const { return _ip; };

        /// @brief Getter of the Port
        int getPort() const { return _port; };

        /// @brief Receive the message from the server
        std::string receive(void);

        /// @brief Send the GUI authentification to the server
        /// @param string std::string for sending GUI to the server
        void sender(std::string);

        /// @brief Connection to the server
        void join(void);

    protected:
    private:
        std::string _ip;
        int _port;
        int _sockfd;
        int _connect;
        struct sockaddr_in _serverAddress;
        class Exception : public std::exception {
            public:

                ///@brief Exeception handles error feedback
                ///@param string std::string message
                Exception(std::string message) : _message(message) {};

                ///@brief DestructorExeception handles error feedback
                ///@param string std::string message
                ~Exception() = default;

                const char *what() const noexcept override { return _message.c_str(); };
            private:
                std::string _message;
        };
};

#endif /* !CONNECT_HPP_ */
