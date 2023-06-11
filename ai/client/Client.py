##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## ai/Client/Client.py
##

## @file Client.py

from ai.arguments import arguments
from ai.error import print_error_exit
import socket
import re

class Client:
    port: int
    ip: str
    team: str
    x: int
    y: int
    socket: socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def __init__(self, args: arguments):
        self.ip = args.ip
        self.port = args.port
        self.team = args.team

    ## @author Damien and Pierre-Louis
    ## @brief Connact to the server, sent and received message
    ## @param args contain the machine's port, name and machine address
    ## @return None or exit 84 in case of error
    def connect_to_server(self) -> None:
        try:
            self.socket.connect((self.ip, self.port))
            print("Connected to the server.")
        except socket.error as error:
            print_error_exit("Error:", error)


    # this method is the initialization with the server
    def communicate(self) -> str:
        received_data = self.socket.recv(1024).decode()
        print("Received from server:", received_data)

        to_send = self.team + "\n"
        self.socket.send(to_send.encode())
        print("Sent to server:", to_send)

        received_data = self.socket.recv(1024).decode()
        print("Received from server:", received_data)
        if (received_data == "ko\n"):
            print("error server")
            exit(84)
        return received_data



    def disconnect_from_server(self) -> None:
        self.socket.close()
        print("Connection closed.")

## @author Pierre-Louis
## @brief Parse the received data of server
## @param received_data is give by the server
## @return None
    def parsing_data(self, str_nb):
        nb = re.findall(r'\d+', str_nb)
        if (int(nb[0]) <= 0):
            print("error: too many trantorians in this team")
            exit(84)
        self.x = int(nb[1])
        self.y = int(nb[2])
    # no need to make error handling here, since the server can't be wrong
