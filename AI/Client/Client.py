##
## EPITECH PROJECT, 2022
## zappy
## File description:
## Client.py
##

from AI.Arguments import Arguments
import socket

def connect_to_server(args: Arguments):
    server_ip = args.machine
    server_port = args.port
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        client_socket.connect((server_ip, server_port))
        print('Connected to the server.')
    except socket.error as e:
        print("Error:", e)
        exit(84)

    received_data = client_socket.recv(1024).decode()
    print('Received from server:', received_data)

    to_send = args.name + '\n'
    client_socket.send(to_send.encode())
    print('Sent to server:', to_send)

    received_data = client_socket.recv(1024).decode()
    print('Received from server:', received_data)

    client_socket.close()
    print('Connection closed.')
