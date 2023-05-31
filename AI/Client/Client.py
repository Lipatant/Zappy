##
## EPITECH PROJECT, 2022
## zappy
## File description:
## Client.py
##

import socket

def connect_to_server(port, name, machine):
    server_ip = machine
    server_port = port
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    client_socket.connect((server_ip, server_port))
    print('Connected to the server.')

    received_data = client_socket.recv(1024).decode()
    print('Received from server:', received_data)

    test = name + '\n'
    client_socket.send(test.encode())
    print('Sent to server:', test)

    received_data = client_socket.recv(1024).decode()
    print('Received from server:', received_data)

    client_socket.close()
    print('Connection closed.')
