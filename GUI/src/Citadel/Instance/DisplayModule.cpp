/*
** EPITECH PROJECT, 2023
** Citadel/Instance.cpp
** File description:
** -
*/

#include <vector>
#include "Citadel/Instance.hpp"

#define SPRITE_PORTRAIT character.second.spritePortrait
#define SPRITE_PORTRAIT_TEXTURES character.second.spritePortraitTextures
#define PORTRAIT_TEXTURES citadel->portraitTextures

#define SET_SPRITE_POSITION \
        if (isHorizontal) { \
            position.x = windowSize.x * -0.5 + \
                static_cast<float>(characterListPosition + 1) / \
                    (charactersSize + 1) * windowSize.x - \
                    SPRITE_PORTRAIT.getTextureRect().width * scale * 0.5; \
            position.y = windowSize.y * 0.5 - \
                SPRITE_PORTRAIT.getTextureRect().height * scale; \
            SPRITE_PORTRAIT.setScale(scale, scale); \
        } else { \
            position.x = windowSize.x * -0.5 + \
                SPRITE_PORTRAIT.getTextureRect().width * scale * 0.5 + 50; \
            position.y = windowSize.y * -0.5 + \
                static_cast<float>(characterListPosition + 1) / \
                (charactersSize + 1) * windowSize.y - \
                SPRITE_PORTRAIT.getTextureRect().height * scale * 0.5; \
            SPRITE_PORTRAIT.setScale(-scale, scale); \
        } \
        SPRITE_PORTRAIT.setPosition(position);

MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleCharacterList)
{
    if (!data) return;
    Citadel::Instance *citadel = reinterpret_cast<Citadel::Instance *>(data);
    bool isHorizontal = true;
    float scale;
    std::size_t characterListPosition = 0;
    std::size_t charactersSize = citadel->characters.size();
    sf::Color color(200, 200, 200, 200);
    sf::FloatRect bounds;
    sf::Vector2f position(0, 0);
    sf::Vector2f const windowSize = instance.window.getView().getSize();
    Citadel::CharacterNumber newSelectedPortrait = 0;
    float newSelectedPortraitDistance = 0;

    for (auto &character: citadel->characters) {
        if (SPRITE_PORTRAIT_TEXTURES.empty())
            continue;
        for (auto const &filepath: SPRITE_PORTRAIT_TEXTURES) {
            if (PORTRAIT_TEXTURES.find(filepath) != PORTRAIT_TEXTURES.end()) {
                SPRITE_PORTRAIT.setTexture(PORTRAIT_TEXTURES.at(filepath));
                break;
            }
            PORTRAIT_TEXTURES[filepath] = sf::Texture();
            if (!PORTRAIT_TEXTURES[filepath].loadFromFile(filepath))
                continue;
            SPRITE_PORTRAIT.setTexture(PORTRAIT_TEXTURES[filepath]);
            break;
        }
        if (citadel->selectedPortrait == character.first)
            SPRITE_PORTRAIT.setColor(sf::Color::White);
        else
            SPRITE_PORTRAIT.setColor(color);
        scale = 0.3;
        SET_SPRITE_POSITION;
        bounds = SPRITE_PORTRAIT.getGlobalBounds();
        if (instance.window.hasFocus && \
            (!newSelectedPortrait || std::abs(instance.window.mouseUI.x - \
            bounds.left - bounds.width / 2) < newSelectedPortraitDistance) && \
            bounds.left <= instance.window.mouseUI.x && \
            instance.window.mouseUI.x <= bounds.left + bounds.width && \
            bounds.top <= instance.window.mouseUI.y && \
            instance.window.mouseUI.y <= bounds.top + bounds.height) {
            newSelectedPortrait = character.first;
            newSelectedPortraitDistance = std::abs(instance.window.mouseUI.x \
                - bounds.left - bounds.width / 2);
        }
        if (citadel->selectedPortrait == character.first) {
            scale = 0.4;
            SET_SPRITE_POSITION;
        }
        instance.window.draw(SPRITE_PORTRAIT);
        characterListPosition++;
    }
    citadel->selectedPortrait = newSelectedPortrait;
}
