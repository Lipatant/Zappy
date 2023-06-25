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
#include "Citadel/Sprites/Items.hpp"
#include "Utility/Regex.hpp"

#define REGEX_INT "^([1-9]\\d*|\\d)$"
#define REGEX_UNINT "^-?([1-9]\\d*|\\d)$"

#define REGEX_EGG_NUMBER REGEX_UNINT
#define REGEX_LEVEL "^[1-8]$"
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

#define LOAD_FROM_FILE(OBJECT, PATH) \
    (OBJECT.loadFromFile(std::string("GUI/") + PATH) || \
    OBJECT.loadFromFile(PATH))

MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleCharacterList);
MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleGround);
MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleUIMainMenu);
MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleUIMenu);
MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleUINone);
MORTYMERE_INSTANCE_DISPLAY_MODULE(playlistDisplayModuleBase);

struct Command_s {
    std::string name;
    std::size_t arguments;
    std::string argumentExpressions[10];
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

INSTANCECMD_FUNCTION(instanceCmdBct)
{
    Citadel::GroundInventoryKey tile = std::make_pair(
        toNumber<Citadel::CharacterPosition>(av[1]),
        toNumber<Citadel::CharacterPosition>(av[2])
    );

    if (instance.ground.inventories.find(tile) == \
        instance.ground.inventories.end()) {
        instance.ground.inventories[tile] = Citadel::Inventory();
    }
    for (std::size_t i = 0; i < CITADEL_INVENTORY_SIZE; i++)
        instance.ground.inventories[tile][i] = \
            toNumber<Citadel::InventoryCount>(av[3 + i]);
    instance.ground.itemSprites.push_back(Mortymere::createSprite< \
        Citadel::Sprites::Items>(&instance.ground, tile));
    instance.engine().addObject(instance.ground.itemSprites.back());
}

INSTANCECMD_FUNCTION(instanceCmdMsz)
{
    instance.ground.changeSize(toNumber<std::size_t>(av[1]), \
        toNumber<std::size_t>(av[2]));
    for (Mortymere::Sprite tile: instance.ground.sprites)
        instance.engine().addObject(tile);
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
        toNumber<Citadel::CharacterLevel>(av[5]),
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


INSTANCECMD_FUNCTION(instanceCmdPpv)
{
    Citadel::CharacterNumber characterNumber = toNumber<std::size_t>(av[1]);

    if (instance.characters.find(characterNumber) == instance.characters.end())
        return;
    instance.characters.at(characterNumber).setLevel(\
        toNumber<Citadel::CharacterLevel>(av[2]));
}

INSTANCECMD_FUNCTION(instanceCmdPin)
{
    Citadel::CharacterNumber characterNumber = toNumber<std::size_t>(av[1]);

    if (instance.characters.find(characterNumber) == instance.characters.end())
        return;
    instance.characters.at(characterNumber).setPosition(\
        toNumber<Citadel::CharacterNumber>(av[2]), \
        toNumber<Citadel::CharacterNumber>(av[3]));
    for (std::size_t i = 0; i < CITADEL_INVENTORY_SIZE; i++)
        instance.characters.at(characterNumber).inventory[i] = \
            toNumber<Citadel::InventoryCount>(av[4 + i]);
}

INSTANCECMD_FUNCTION(instanceCmdPdr)
{
    Citadel::CharacterNumber characterNumber = toNumber<std::size_t>(av[1]);
    std::size_t ressource = toNumber<std::size_t>(av[2]);
    Citadel::GroundInventoryKey tile;

    if (instance.characters.find(characterNumber) == instance.characters.end())
        return;
    if (instance.characters.at(characterNumber).inventory[ressource] > 0)
        instance.characters.at(characterNumber).inventory[ressource] -= 1;
    tile = std::make_pair( \
        instance.characters.at(characterNumber).getPositionX(), \
        instance.characters.at(characterNumber).getPositionY());
    if (instance.ground.inventories.find(tile) == \
        instance.ground.inventories.end()) {
        instance.ground.inventories[tile] = Citadel::Inventory();
        instance.ground.itemSprites.push_back(Mortymere::createSprite< \
            Citadel::Sprites::Items>(&instance.ground, tile));
        instance.engine().addObject(instance.ground.itemSprites.back());
    }
    instance.ground.inventories.at(tile)[ressource] += 1;
}

INSTANCECMD_FUNCTION(instanceCmdPgt)
{
    Citadel::CharacterNumber characterNumber = toNumber<std::size_t>(av[1]);
    std::size_t ressource = toNumber<std::size_t>(av[2]);
    Citadel::GroundInventoryKey tile;

    if (instance.characters.find(characterNumber) == instance.characters.end())
        return;
    instance.characters.at(characterNumber).inventory[ressource] += 1;
    tile = std::make_pair( \
        instance.characters.at(characterNumber).getPositionX(), \
        instance.characters.at(characterNumber).getPositionY());
    if (instance.ground.inventories.find(tile) == \
        instance.ground.inventories.end())
        return;
    if (instance.ground.inventories.at(tile)[ressource] > 0)
        instance.ground.inventories.at(tile)[ressource] -= 1;
}

INSTANCECMD_FUNCTION(instanceCmdPdi)
{
    Citadel::CharacterNumber characterNumber = toNumber<std::size_t>(av[1]);

    if (instance.characters.find(characterNumber) == instance.characters.end())
        return;
    instance.characters.erase(characterNumber);
}

static const struct Command_s COMMANDS[] = {
    // Map size
    {"msz", 2, {REGEX_POSITION, REGEX_POSITION}, instanceCmdMsz},
    // Content of a tile
    {"bct", 9, {REGEX_POSITION, REGEX_POSITION, REGEX_RESSOURCE, \
        REGEX_RESSOURCE, REGEX_RESSOURCE, REGEX_RESSOURCE, REGEX_RESSOURCE, \
        REGEX_RESSOURCE, REGEX_RESSOURCE}, instanceCmdBct},
    // Name of a team
    {"tna", 1, {REGEX_TEAM}, 0},
    // Connection of a new player
    {"pnw", 6, {REGEX_NUMBER, REGEX_POSITION, REGEX_POSITION, \
        REGEX_ORIENTATION, REGEX_LEVEL, REGEX_TEAM}, instanceCmdPnw},
    // Player's position
    {"ppo", 4, {REGEX_NUMBER, REGEX_POSITION, REGEX_POSITION, \
        REGEX_ORIENTATION}, instanceCmdPpo},
    // Player's level
    {"plv", 2, {REGEX_NUMBER, REGEX_LEVEL}, instanceCmdPpv},
    // Player's inventory
    {"pin", 10, {REGEX_NUMBER, REGEX_POSITION, REGEX_POSITION, \
        REGEX_RESSOURCE, REGEX_RESSOURCE, REGEX_RESSOURCE, REGEX_RESSOURCE, \
        REGEX_RESSOURCE, REGEX_RESSOURCE, REGEX_RESSOURCE}, instanceCmdPin},
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
    {"pdr", 2, {REGEX_NUMBER, REGEX_RESSOURCE_ID}, instanceCmdPdr},
    // Ressource collecting
    {"pgt", 2, {REGEX_NUMBER, REGEX_RESSOURCE_ID}, instanceCmdPgt},
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

INSTANCE::Instance(Mortymere::Instance &engine) : _engine(engine), \
    mainMenuButtonExit("graphics/buttons/Exit.png"), \
    mainMenuButtonFullscreen("graphics/buttons/Fullscreen.png"), \
    mainMenuButtonPlay("graphics/buttons/Play.png"), \
    noneButtonSettings("graphics/buttons/Settings.png"), \
    noneButtonZoomIn("graphics/buttons/Plus.png"), \
    noneButtonZoomOut("graphics/buttons/Less.png")
{
    sf::Color zoomInOutColor(sf::Color::White);

    srand(time(NULL));
    playlist.next();
    zoomInOutColor.a = 200;
    noneButtonZoomIn.setColor(zoomInOutColor);
    noneButtonZoomOut.setColor(zoomInOutColor);
    _engine.addDisplayModule("preobj", citadelDisplayModuleGround);
    _engine.addDisplayModule("ui", citadelDisplayModuleCharacterList, this);
    _engine.addDisplayModule("ui", citadelDisplayModuleUINone, this);
    _engine.addDisplayModule("ui", citadelDisplayModuleUIMenu, this);
    _engine.addDisplayModule("ui", citadelDisplayModuleUIMainMenu, this);
    _engine.addDisplayModule("ui", playlistDisplayModuleBase, this);
    _engine.window.setViewCenter(0, 0);
    if (_mainMenuCoverTexture.loadFromFile("GUI/graphics/MainMenu.png") || \
        _mainMenuCoverTexture.loadFromFile("graphics/MainMenu.png")) {
        mainMenuCover.setTexture(&_mainMenuCoverTexture);
        mainMenuCoverTextureRect = mainMenuCover.getTextureRect();
        isMainMenuCoverTextureLoaded = true;
    }
    if (_mainMenuTitleTexture.loadFromFile("GUI/graphics/MainTitle.png") || \
        _mainMenuTitleTexture.loadFromFile("graphics/MainTitle.png")) {
        mainMenuTitle.setTexture(&_mainMenuTitleTexture);
        mainMenuTitleTextureRect = mainMenuTitle.getTextureRect();
        isMainMenuTitleTextureLoaded = true;
    }
    if (_portraitLevelTexture.loadFromFile("GUI/graphics/Levels.png") || \
        _portraitLevelTexture.loadFromFile("graphics/Levels.png")) {
        portraitLevel.setTexture(_portraitLevelTexture);
        portraitLevelTextureRect = portraitLevel.getTextureRect();
        portraitLevelTextureRect.width = portraitLevelTextureRect.height;
        portraitLevel.setTextureRect(portraitLevelTextureRect);
        isPortraitLevelTextureLoaded = true;
    }
    if (LOAD_FROM_FILE(_font, "fonts/AileronBold.otf"))
        _isFontLoaded = true;
    if (_isFontLoaded) {
        portraitText.setFont(_font);
        portraitText.setString("");
        portraitText.setCharacterSize(36);
        portraitText.setOutlineThickness(4);
        portraitText.setFillColor(sf::Color::White);
        portraitText.setOutlineColor(sf::Color::Black);
        portraitTextString = "";
        portraitTextTeam.setFont(_font);
        portraitTextTeam.setString("");
        portraitTextTeam.setCharacterSize(36);
        portraitTextTeam.setOutlineThickness(4);
        portraitTextTeam.setFillColor(sf::Color::White);
        portraitTextTeam.setOutlineColor(sf::Color::Black);
        portraitTextTeamString = "";
    }
}

Mortymere::Instance &INSTANCE::engine(void)
{
    return _engine;
}

void INSTANCE::changeCurrentMenu(InstanceCurrentMenu const newMenu)
{
    _nextMenu = newMenu;
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
    bool returned;
    std::size_t groundSizeX;
    std::size_t groundSizeY;

    if (selectedCharacter && characters.find(selectedCharacter) != \
        characters.end())
        _engine.camera.center = \
            characters.at(selectedCharacter).sprite->anchor();
    else {
        groundSizeX = ground.getSizeX();
        groundSizeY = ground.getSizeY();
        selectedCharacter = 0;
        _engine.camera.center = {0, 0, 0};
        if (groundSizeX > 0)
            _engine.camera.center.x = static_cast<float>( \
                ground.getSizeX() - 1) / 2;
        if (groundSizeY > 0)
            _engine.camera.center.z = static_cast<float>( \
                ground.getSizeY() - 1) / 2;
    }
    if (currentMenu != lastMenu) {
        menuTransition = static_cast<double>( \
            _menuTransitionClock.getElapsedTime().asMilliseconds()) / 1000 * 4;
        if (menuTransition >= 1.0) {
            lastMenu = currentMenu;
            menuTransition = 1.0;
            isInMenuTransition = false;
        }
    }
    returned = _engine.udpate();
    if (_nextMenu != currentMenu) {
        _menuTransitionClock.restart();
        menuTransition = 0;
        lastMenu = currentMenu;
        currentMenu = _nextMenu;
        isInMenuTransition = true;
    }
    for (auto &character: characters)
        character.second.update();
    return returned;
}

void INSTANCE::operator<<(std::string const &cmd)
{
    return enterCommand(cmd);
}
