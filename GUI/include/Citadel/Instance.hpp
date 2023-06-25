/*
** EPITECH PROJECT, 2023
** Citadel/Citadel.hpp
** File description:
** -
*/

/// @file
/// @brief Base instance of the GUI logic

#pragma once

#include <map>
#include <vector>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include "Citadel/Character.hpp"
#include "Citadel/Ground.hpp"
#include "Citadel/Playlist.hpp"
#include "Mortymere/Button.hpp"
#include "Mortymere/Instance.hpp"

namespace Citadel {

enum class InstanceCurrentMenu {
    None,
    MainMenu,
};

/// @brief Class representing a Citadel for the game to take place
class Instance {

private: // PROTECTED MEMBERS
    /// @brief Font used for texts
    sf::Font _font;
    /// @brief If _font is loaded
    bool _isFontLoaded = false;
    /// @brief Texture of mainMenuCover
    sf::Texture _mainMenuCoverTexture;
    /// @brief Texture of mainMenuTitle
    sf::Texture _mainMenuTitleTexture;
    /// @brief Clock measuring time since last menu transition
    sf::Clock _menuTransitionClock;
    /// @brief Variable used for the changeCurrentMenu function
    Citadel::InstanceCurrentMenu _nextMenu = InstanceCurrentMenu::MainMenu;
    /// @brief Texture of portraitLevel
    sf::Texture _portraitLevelTexture;

protected: // PROTECTED MEMBERS
    /// @brief Regerence to a Mortymere instance
    Mortymere::Instance &_engine;

public: // PUBLIC MEMBERS
    /// @brief List of all characters in the Citadel
    std::map<Citadel::CharacterNumber, Citadel::Character> characters;
    /// @brief Current menu that the player is in
    Citadel::InstanceCurrentMenu currentMenu = InstanceCurrentMenu::MainMenu;
    /// @brief Last menu the player was in, or current is the transition time
    ///     is over
    Citadel::InstanceCurrentMenu lastMenu = InstanceCurrentMenu::MainMenu;
    /// @brief Ground of the Citadel
    Citadel::Ground ground;
    /// @brief If the menu is transitioning to another
    bool isInMenuTransition = false;
    /// @brief If _mainMenuCoverTexture is loaded
    bool isMainMenuCoverTextureLoaded = false;
    /// @brief If _mainMenuTitleTexture is loaded
    bool isMainMenuTitleTextureLoaded = false;
    /// @brief If _portraitLevelTexture is loaded
    bool isPortraitLevelTextureLoaded = false;
    /// @brief Shape used for covering the entire screen during the Main Menu
    sf::RectangleShape mainMenuCover;
    /// @brief Default TextureRect of mainMenuCover
    sf::IntRect mainMenuCoverTextureRect;
    /// @brief Shape used for covering the entire screen during the Main Menu
    ///     with a title
    sf::RectangleShape mainMenuTitle;
    /// @brief Default TextureRect of mainMenuTitle
    sf::IntRect mainMenuTitleTextureRect;
    /// @brief Button for exiting the game
    Mortymere::Button mainMenuButtonExit;
    /// @brief Button for using the fullscreen mode
    Mortymere::Button mainMenuButtonFullscreen;
    /// @brief Button for leaving the main menu
    Mortymere::Button mainMenuButtonPlay;
    /// @brief Time since the last menu (from 0.0f to 1.0f)
    float menuTransition = 1.0f;
    /// @brief Button for re-entering the main menu
    Mortymere::Button noneButtonSettings;
    /// @brief Button for zooming
    Mortymere::Button noneButtonZoomIn;
    /// @brief Button for de-zooming
    Mortymere::Button noneButtonZoomOut;
    /// @brief Playlist managing everything related to music
    Citadel::Playlist playlist;
    /// @brief Shape used for displaying the characters' levels
    sf::Sprite portraitLevel;
    /// @brief Default TextureRect of portraitLevel
    sf::IntRect portraitLevelTextureRect;
    /// @brief Text used for displaying a name
    sf::Text portraitText;
    /// @brief String contained inside portraitText
    std::string portraitTextString;
    /// @brief Text used for displaying a team
    sf::Text portraitTextTeam;
    /// @brief String contained inside portraitTextTeam
    std::string portraitTextTeamString;
    /// @brief Currently selected character. If no cbaracter is
    ///     selected, selectedCharacter should be equal to 0
    Citadel::CharacterNumber selectedCharacter = 0;
    /// @brief Currently selected character's portrait. If no portrait is
    ///     selected, selectedPortrait should be equal to 0
    Citadel::CharacterNumber selectedPortrait = 0;
    /// @brief List of all teams
    std::vector<Citadel::CharacterTeam> teams = {};
    /// @brief List of all loaded portrait textures
    std::map<std::string, sf::Texture> portraitTextures;

public: // PUBLIC FUNCTIONS
    void changeCurrentMenu(InstanceCurrentMenu const newMenu);
    /// @brief Enters a new server command to the Citadel
    void enterCommand(std::string const &cmd);
    /// @return Reference to _engine
    Mortymere::Instance &engine(void);
    /// @return Returns true, or false if the window is closed
    bool udpate(void);

public: // PUBLIC
    /// @brief Enters a new server command to the Citadel.
    ///     Equivalent of enterCommand
    void operator<<(std::string const &cmd);

public: // PUBLIC MEMBERS
    Instance(Mortymere::Instance &engine);

};

};
