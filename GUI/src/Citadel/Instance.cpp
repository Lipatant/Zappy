/*
** EPITECH PROJECT, 2023
** Citadel/Instance.cpp
** File description:
** -
*/

#include <vector>
#include "Citadel/Exception.hpp"
#include "Citadel/Instance.hpp"
#include "Utility/Regex.hpp"

#define REGEX_INT "^([1-9]\\d*|\\d)$"
#define REGEX_UNINT "^-?([1-9]\\d*|\\d)$"

#define REGEX_NUMBER REGEX_UNINT
#define REGEX_ORIENTATION "^[1-4]$"
#define REGEX_POSITION REGEX_INT
#define REGEX_RESSOURCE REGEX_UNINT
#define REGEX_LEVEL REGEX_UNINT
#define REGEX_TEAM ""

#define INSTANCE Citadel::Instance
#define INSTANCECMD Citadel::InstanceCmd
#define INSTANCECMD_FUNCTION(NAME) \
    static void NAME(INSTANCE &instance, std::vector<std::string> const &av)

struct Command_s {
    std::string name;
    std::size_t arguments;
    std::string argumentExpressions[9];
    void (*function)(INSTANCE &instance, std::vector<std::string> const &av);
};
static const char CMD_SEPARATORS[] = {' ', '\t', '\n'};
static const std::size_t CMD_SEPARATORS_LENGTH = \
    sizeof(CMD_SEPARATORS) / sizeof(CMD_SEPARATORS[0]);

template <class T>
static T toRotation(std::string const &str)
{
    return static_cast<T>(str[0] - '0');
}

template <class T>
static T toNumber(std::string const &str)
{
    T returned = 0;

    for (char const c: str) {
        if (c < '0' || c > '9')
            continue;
        returned = returned * 10 + c - '0';
    }
    return returned;
}

INSTANCECMD_FUNCTION(instanceCmdPnw)
{
    Citadel::CharacterNumber characterNumber = toNumber<std::size_t>(av[1]);

    instance.characters.emplace(characterNumber, \
        Citadel::Character(
        toNumber<Citadel::CharacterNumber>(av[1]),
        toNumber<Citadel::CharacterPosition>(av[2]),
        toNumber<Citadel::CharacterPosition>(av[3]),
        toRotation<Citadel::CharacterRotation>(av[4]),
        characterNumber,
        av[6]
    ));
    instance.engine().addObject( \
        instance.characters.at(characterNumber).sprite);
}

INSTANCECMD_FUNCTION(instanceCmdPpo)
{
    Citadel::CharacterNumber characterNumber = toNumber<std::size_t>(av[1]);

    if (instance.characters.find(characterNumber) == instance.characters.end())
        return;
    instance.characters.at(characterNumber).setPosition(\
        toNumber<Citadel::CharacterNumber>(av[2]), \
        toNumber<Citadel::CharacterNumber>(av[3]));
    instance.characters.at(characterNumber).setRotation( \
        toRotation<Citadel::CharacterRotation>(av[4]));
}

static const struct Command_s COMMANDS[] = {
    {"pnw", 6, {REGEX_NUMBER, REGEX_POSITION, REGEX_POSITION, \
        REGEX_ORIENTATION, REGEX_LEVEL, REGEX_TEAM}, instanceCmdPnw},
    {"ppo", 4, {REGEX_NUMBER, REGEX_POSITION, REGEX_POSITION, \
        REGEX_ORIENTATION}, instanceCmdPpo}
};
static const std::size_t COMMANDS_LENGTH = \
    sizeof(COMMANDS) / sizeof(COMMANDS[0]);

static void convertCommand(std::string const &cmd, size_t &ac, \
    std::vector<std::string> &av)
{
    std::string segment;
    bool isSeparator;

    for (char const c: cmd) {
        isSeparator = false;
        for (std::size_t i = 0; i < CMD_SEPARATORS_LENGTH; i++)
            if (c == CMD_SEPARATORS[i])
                isSeparator = true;
        if (isSeparator) {
            if (!segment.empty()) {
                ac++;
                av.push_back(segment);
                segment.clear();
            }
        } else {
            segment += c;
        }
    }
    if (!segment.empty()) {
        ac++;
        av.push_back(segment);
    }
}

INSTANCE::Instance(Mortymere::Instance &engine) : _engine(engine)
{ }

Mortymere::Instance &INSTANCE::engine(void)
{
    return _engine;
}

void INSTANCE::enterCommand(std::string const &cmd)
{
    size_t ac = 0;
    std::vector<std::string> av = {};

    convertCommand(cmd, ac, av);
    if (ac < 1)
        throw Citadel::Exception::Command::Empty();
    for (std::size_t i = 0; i < COMMANDS_LENGTH; i++) {
        if (!COMMANDS[i].function || av[0] != COMMANDS[i].name)
            continue;
        if ((ac - 1) < COMMANDS[i].arguments)
            throw Citadel::Exception::Command::InvalidAmountArguments();
        for (std::size_t j = 0; j < COMMANDS[i].arguments; j++) {
            if (COMMANDS[i].argumentExpressions[j].empty())
                continue;
            if (!utility::regex::quickTest(av[j + 1], \
                COMMANDS[i].argumentExpressions[j]))
                throw Citadel::Exception::Command::InvalidArgument();
        }
        COMMANDS[i].function(*this, av);
    }
}

void INSTANCE::operator<<(std::string const &cmd)
{
    return enterCommand(cmd);
}
