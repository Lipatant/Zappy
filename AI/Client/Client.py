##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Client/Client.py
##

## @file Client.py

from AI.Arguments import Arguments
from AI.Error import print_error_exit
import socket
import re

class Client:
    port: int
    ip: str
    team: str
    socket: socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def __init__(self, args: Arguments):
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



    def communicate(self) -> str:
        received_data = self.socket.recv(1024).decode()
        print("Received from server:", received_data)

        to_send = self.team + "\n"
        self.socket.send(to_send.encode())
        print("Sent to server:", to_send)

        received_data = self.socket.recv(1024).decode()
        print("Received from server:", received_data)
        return received_data



    def disconnect_from_server(self) -> None:
        self.socket.close()
        print("Connection closed.")




## @author Pierre-Louis
## @brief Parse the received data of server
## @param received_data is give by the server
## @return None
def parsing_data(str_nb):
    nb = re.findall(r'\d+', str_nb)
    nb_bot = int(nb[0])
    map_x = int(nb[1])
    map_y = int(nb[2])

    print(">>>", nb_bot, map_x, map_y, "<<<")
