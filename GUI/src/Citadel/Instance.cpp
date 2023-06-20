/*
** EPITECH PROJECT, 2023
** Citadel/Instance.cpp
** File description:
** -
*/

#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Citadel/Exception.hpp"
#include "Citadel/Instance.hpp"
#include "Utility/Regex.hpp"

#define REGEX_INT "^([1-9]\\d*|\\d)$"
#define REGEX_UNINT "^-?([1-9]\\d*|\\d)$"

#define REGEX_EGG_NUMBER REGEX_UNINT
#define REGEX_LEVEL REGEX_UNINT
#define REGEX_MESSAGE ""
#define REGEX_NUMBER REGEX_UNINT
#define REGEX_ORIENTATION "^[1-4]$"
#define REGEX_POSITION REGEX_INT
#define REGEX_RESSOURCE REGEX_UNINT
#define REGEX_RESSOURCE_ID "^[0-6]$"
#define REGEX_TEAM ""
#define REGEX_TIME REGEX_UNINT
#define REGEX_INCANTATION_RESULT ""

#define INSTANCE Citadel::Instance
#define INSTANCECMD Citadel::InstanceCmd
#define INSTANCECMD_FUNCTION(NAME) \
    static void NAME(INSTANCE &instance, std::vector<std::string> const &av)

MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleCharacterList);

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
    short sign = 1;

    for (char const c: str) {
        if (c == '-')
            sign *= -1;
        if (c < '0' || c > '9')
            continue;
        returned = returned * 10 + (c - '0') * 1;
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

INSTANCECMD_FUNCTION(instanceCmdPdi)
{
    Citadel::CharacterNumber characterNumber = toNumber<std::size_t>(av[1]);

    if (instance.characters.find(characterNumber) == instance.characters.end())
        return;
    instance.characters.erase(characterNumber);
}

INSTANCECMD_FUNCTION(instanceCmdMsz)
{
    instance.ground.changeSize(toNumber<std::size_t>(av[1]), \
        toNumber<std::size_t>(av[2]));
    for (Mortymere::Sprite tile: instance.ground.sprites)
        instance.engine().addObject(tile);
}

static const struct Command_s COMMANDS[] = {
    // Map size
    {"msz", 2, {REGEX_POSITION, REGEX_POSITION}, instanceCmdMsz},
    // Content of a tile
    {"btc", 9, {REGEX_POSITION, REGEX_POSITION, REGEX_RESSOURCE, \
        REGEX_RESSOURCE, REGEX_RESSOURCE, REGEX_RESSOURCE, REGEX_RESSOURCE, \
        REGEX_RESSOURCE, REGEX_RESSOURCE}, 0},
    // Name of a team
    {"tna", 1, {REGEX_TEAM}, 0},
    // Connection of a new player
    {"pnw", 6, {REGEX_NUMBER, REGEX_POSITION, REGEX_POSITION, \
        REGEX_ORIENTATION, REGEX_LEVEL, REGEX_TEAM}, instanceCmdPnw},
    // Player's position
    {"ppo", 4, {REGEX_NUMBER, REGEX_POSITION, REGEX_POSITION, \
        REGEX_ORIENTATION}, instanceCmdPpo},
    // Player's level
    {"plv", 2, {REGEX_NUMBER, REGEX_LEVEL}, 0},
    // Player's inventory
    {"pin", 8, {REGEX_NUMBER, REGEX_RESSOURCE, REGEX_RESSOURCE, \
        REGEX_RESSOURCE, REGEX_RESSOURCE, REGEX_RESSOURCE, REGEX_RESSOURCE, \
        REGEX_RESSOURCE}, 0},
    // Expulsion
    {"pex", 1, {REGEX_NUMBER}, 0},
    // Broadcast
    {"pbc", 2, {REGEX_NUMBER, REGEX_MESSAGE}, 0},
    // Start of incantation (by the first player)
    {"pic", 4, {REGEX_POSITION, REGEX_POSITION, REGEX_LEVEL, REGEX_NUMBER}, 0},
    {"pic", 5, {REGEX_POSITION, REGEX_POSITION, REGEX_LEVEL, REGEX_NUMBER, \
        REGEX_NUMBER}, 0},
    {"pic", 7, {REGEX_POSITION, REGEX_POSITION, REGEX_LEVEL, REGEX_NUMBER, \
        REGEX_NUMBER, REGEX_NUMBER, REGEX_NUMBER}, 0},
    {"pic", 9, {REGEX_POSITION, REGEX_POSITION, REGEX_LEVEL, REGEX_NUMBER, \
        REGEX_NUMBER, REGEX_NUMBER, REGEX_NUMBER, REGEX_NUMBER, \
        REGEX_NUMBER}, 0},
    // End of incantation
    {"pie", 3, {REGEX_POSITION, REGEX_POSITION, REGEX_INCANTATION_RESULT}, 0},
    // Egg layed by the player
    {"pfk", 1, {REGEX_NUMBER}, 0},
    // Ressource dropping
    {"pdr", 2, {REGEX_NUMBER, REGEX_RESSOURCE_ID}, 0},
    // Ressource collecting
    {"pgt", 2, {REGEX_NUMBER, REGEX_RESSOURCE_ID}, 0},
    // Death of a player
    {"pdi", 1, {REGEX_NUMBER}, instanceCmdPdi},
    // An egg was layed by a player
    {"enw", 4, {REGEX_EGG_NUMBER, REGEX_NUMBER, REGEX_POSITION, \
        REGEX_POSITION}, 0},
    // Player connection to an egg
    {"ebo", 1, {REGEX_EGG_NUMBER}, 0},
    // Death of an egg
    {"edi", 1, {REGEX_EGG_NUMBER}, 0},
    // Time unit request
    {"sgt", 1, {REGEX_TIME}, 0},
    // Time unit modfication
    {"sst", 1, {REGEX_TIME}, 0},
    // End of the game
    {"seg", 1, {REGEX_TEAM}, 0},
    // Message from the server
    {"smg", 1, {REGEX_MESSAGE}, 0},
    // Unknown command
    {"suc", 0, {}, 0},
    // Command parameter
    {"sbp", 0, {}, 0},
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
{
    srand(time(NULL));
    _engine.addDisplayModule(citadelDisplayModuleCharacterList, this);
    _engine.window.setViewCenter(0, 0);
}

Mortymere::Instance &INSTANCE::engine(void)
{
    return _engine;
}

void INSTANCE::enterCommand(std::string const &cmd)
{
    size_t ac = 0;
    bool invalidAmountArguments = false;
    std::vector<std::string> av = {};

    convertCommand(cmd, ac, av);
    if (ac < 1)
        throw Citadel::Exception::Command::Empty();
    for (std::size_t i = 0; i < COMMANDS_LENGTH; i++) {
        if (!COMMANDS[i].function || av[0] != COMMANDS[i].name)
            continue;
        if ((ac - 1) != COMMANDS[i].arguments) {
            invalidAmountArguments = true;
            continue;
        }
        for (std::size_t j = 0; j < COMMANDS[i].arguments; j++) {
            if (COMMANDS[i].argumentExpressions[j].empty())
                continue;
            if (!utility::regex::quickTest(av[j + 1], \
                COMMANDS[i].argumentExpressions[j]))
                throw Citadel::Exception::Command::InvalidArgument();
        }
        COMMANDS[i].function(*this, av);
        return;
    }
    if (invalidAmountArguments)
        throw Citadel::Exception::Command::InvalidAmountArguments();
}

bool INSTANCE::udpate(void)
{
    if (selectedCharacter && characters.find(selectedCharacter) != characters.end())
        _engine.camera.center = characters.at(selectedCharacter).sprite->anchor();
    else {
        _engine.camera.center = {0, 0, 0};
        _engine.camera.center.x = static_cast<float>(ground.getSizeX() - 1) / 2;
        _engine.camera.center.z = static_cast<float>(ground.getSizeY() - 1) / 2;
    }
//    if (ground.getSizeX() < 1 || ground.getSizeY() < 1)
//        _engine.camera.center = {0, 0, 0};
//    else
//        _engine.camera.center = {0, 0, 0};
    return _engine.udpate();
}

void INSTANCE::operator<<(std::string const &cmd)
{
    return enterCommand(cmd);
}
