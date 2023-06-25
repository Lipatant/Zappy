/*
** EPITECH PROJECT, 2023
** Citadel/Exception.hpp
** File description:
** -
*/

/// @file
/// @brief Error exceptions used by Citadel

#pragma once

#include <exception>
#include <string>

#define EXCEPTION(NAME, WHAT) \
    class NAME : public std::exception { \
    private: std::string _msg; \
    public: NAME(void) : _msg("") {} \
    public: NAME(std::string const &msg) : _msg(msg) {} \
    public: std::string const what() \
        { if (_msg.empty()) return WHAT; return _msg; } \
    };

namespace Citadel { namespace Exception { namespace Command {

EXCEPTION(Empty, "Command is empty")
EXCEPTION(InvalidAmountArguments, "Invalid amount of arguments in command")
EXCEPTION(InvalidArgument, "Argument not matching the regular expression")
EXCEPTION(TooFewArguments, "Too few arguments in command")
EXCEPTION(TooManyArguments, "Too many arguments in command")

}}};
