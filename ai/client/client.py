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
    data: str
    broadcast_msg: str
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
        except:
            print_error_exit("\nError: cannot connect to the server")

    # this method is the initialization with the server
    def communicate(self) -> str:
        self.data = self.socket.recv(1024).decode()
        to_send = self.team + "\n"
        self.socket.send(to_send.encode())
        print("Sent to server:", to_send)

        self.data = self.socket.recv(1024).decode()
        print("Received from server:", self.data)
        if (self.data == "ko\n"):
            print_error_exit("error server")
        return self.data



    def disconnect_from_server(self) -> None:
        self.socket.close()
        print("Connection closed.")
        exit(0)
## @author Pierre-Louis
## @brief Parse the received data of server
## @param self.client.data is give by the server
## @return None
    def parsing_data(self, str_nb):
        nb = re.findall(r'\d+', str_nb)
        if (int(nb[0]) <= 0):
            print_error_exit("error: too many trantorians in this team")
        self.x = int(nb[1])
        self.y = int(nb[2])

## @author Damien
## @brief check if the client is still alive
## @return disconnect and exit if the client is dead
    def check_client(self):
        if self.data == "dead\n":
            self.disconnect_from_server()
            exit(0)

    def write_to_server(self, msg):
        self.socket.send(msg.encode())
        print("Sent to server:", msg)

    def read_server(self):
        self.data = self.socket.recv(1024).decode()
        print("Received from server:", self.data)
