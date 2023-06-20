/*
** EPITECH PROJECT, 2023
** Mortymere/Citadel.hpp
** File description:
** -
*/

/// @file
/// @brief Base instance of the GUI logic

#pragma once

#include <map>
#include "Citadel/Character.hpp"
#include "Citadel/Ground.hpp"
#include "Mortymere/Instance.hpp"

namespace Citadel {

/// @brief Class representing a Citadel for the game to take place
class Instance {

protected: // PROTECTED MEMBERS
    /// @brief Regerence to a Mortymere instance
    Mortymere::Instance &_engine;

public: // PUBLIC MEMBERS
    /// @brief List of all characters in the Citadel
    std::map<Citadel::CharacterNumber, Citadel::Character> characters;
    /// @brief Ground of the Citadel
    Citadel::Ground ground;
    /// @brief Currently selected character. If no cbaracter is
    ///     selected, selectedCharacter should be equal to 0
    Citadel::CharacterNumber selectedCharacter = 0;
    /// @brief Currently selected character's portrait. If no portrait is
    ///     selected, selectedPortrait should be equal to 0
    Citadel::CharacterNumber selectedPortrait = 0;
    /// @brief List of all loaded portrait textures
    std::map<std::string, sf::Texture> portraitTextures;

public: // PUBLIC FUNCTIONS
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
