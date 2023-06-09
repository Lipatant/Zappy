##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-viktor.bruggeman
## File description:
## tests/test_arguments.py
##

'''
port: int
team: str
ip: str

def __init__(self) -> None:
    self.port = 0
    self.team = ""
    self.ip = "127.0.0.1"

self = 0
__init__(self)
'''
#import sys
#sys.path.append("../")
import pytest

#from ai.arguments.arguments import arguments
from arguments import Arguments
'''
def test_init():
    obj = Arguments
    assert obj.port == 0
    assert obj.team == ""
    assert obj.ip == "127.0.0.1"
'''
def test_parse_args_valid():
    obj = Arguments
    obj.parse_args(0, 6, ["-p", "8080", "-n", "MyTeam", "-h", "192.168.0.1"])
    assert obj.port == 8080
    assert obj.team == "MyTeam"
    assert obj.ip == "192.168.0.1"

def test_parse_args_invalid():
    obj = Arguments
    with pytest.raises(SystemExit):
        obj.parse_args(0, 4, ["-p", "8080", "-x", "InvalidArg"])

def test_parse_args_incomplete():
    obj = Arguments
    with pytest.raises(SystemExit):
        obj.parse_args(0, 4, ["-p", "8080", "-n", "MyTeam"])
