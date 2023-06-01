##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## AI/Client/Client.py
##

## @file Client.py

from AI.Arguments import Arguments
from AI.Main import print_error_exit
import socket

## @author Damien and Pierre-Louis
## @brief Connact to the server, sent and received message
## @param args contain the machine's port, name and machine address
## @return None or exit 84 in case of error
def connect_to_server(args: Arguments) -> None:
    server_ip = args.machine
    server_port = args.port
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        client_socket.connect((server_ip, server_port))
        print("Connected to the server.")
    except socket.error as error:
        print_error_exit("Error:", error)

    received_data = client_socket.recv(1024).decode()
    print("Received from server:", received_data)

    to_send = args.name + "\n"
    client_socket.send(to_send.encode())
    print("Sent to server:", to_send)

    received_data = client_socket.recv(1024).decode()
    print("Received from server:", received_data)

    client_socket.close()
    print("Connection closed.")
