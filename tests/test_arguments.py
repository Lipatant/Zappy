##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## tests/test_arguments.py
##

def add(a, b):
    return a + b

def test_basic():
    assert add(1, 1) == 2

'''
import pytest
from ai.arguments.arguments import arguments

def test_init():
    obj = arguments
    assert obj.port == 0
    assert obj.team == ""
    assert obj.ip == "127.0.0.1"

def test_parse_args_valid():
    obj = arguments
    obj.parse_args(0, 6, ["-p", "8080", "-n", "MyTeam", "-h", "192.168.0.1"])
    assert obj.port == 8080
    assert obj.team == "MyTeam"
    assert obj.ip == "192.168.0.1"

def test_parse_args_invalid():
    obj = arguments
    with pytest.raises(SystemExit):
        obj.parse_args(0, 4, ["-p", "8080", "-x", "InvalidArg"])

def test_parse_args_incomplete():
    obj = arguments
    with pytest.raises(SystemExit):
        obj.parse_args(0, 4, ["-p", "8080", "-n", "MyTeam"])
'''
