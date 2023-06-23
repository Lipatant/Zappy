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
#define COLOR_ALPHA(CLR, ALP) sf::Color( \
    static_cast<float>(CLR.r) * ALP, static_cast<float>(CLR.g) * ALP, \
    static_cast<float>(CLR.b) * ALP, static_cast<float>(CLR.a) * ALP)

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

/// USING BASIC HIGH CONSTRAST COLOR PALETTE
static const sf::Color COLORS_DEFAULT(sf::Color::White);
static const sf::Color COLORS[] = {
    {255, 155, 0}, {155, 0, 255}, {0, 255, 155},
    {255, 0, 0}, /*{0, 0, 255},*/ {0, 255, 0}
};
static const std::size_t COLORS_LENGTH = sizeof(COLORS) / sizeof(COLORS[0]);

/// USING COLORBLIND-FRIENDLY COLOR PALETTE
/// #601A4A | #EE442F | #63ACBE | #F9F4EC
static const sf::Color COLORS_COLORBLIND[] = {
    {96, 26, 74}, {238, 68, 47}, {99, 172, 190}, {249, 244, 236}
};
static const std::size_t COLORS_COLORBLIND_LENGTH = \
    sizeof(COLORS_COLORBLIND) / sizeof(COLORS_COLORBLIND[0]);

static sf::Color getTeamColor(Citadel::Instance *citadel, \
    Citadel::CharacterTeam const &team)
{
    std::size_t teamsSize = citadel->teams.size();

    for (std::size_t i = 0; i < teamsSize; i++)
        if (citadel->teams[i] == team)
            return teamsSize < 2 ? COLORS_DEFAULT : COLORS[i % COLORS_LENGTH];
    citadel->teams.push_back(team);
    return teamsSize < 2 ? COLORS_DEFAULT : COLORS[teamsSize % COLORS_LENGTH];
}

MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleCharacterList)
{
    if (!data) return;
    Citadel::Instance *citadel = reinterpret_cast<Citadel::Instance *>(data);
    float const colorInactive = 200.0 / 255.0;
    bool isHorizontal = true;
    float scale;
    std::size_t characterListPosition = 0;
    std::size_t charactersSize = citadel->characters.size();
    sf::Color color;
    sf::FloatRect bounds;
    sf::Sprite items;
    sf::IntRect itemsTextureRect;
    float itemsScale;
    sf::Vector2f position(0, 0);
    sf::Vector2f const windowSize = instance.window.getView().getSize();
    sf::View view(instance.window.getView());
    sf::View viewSaved(view);
    Citadel::CharacterNumber newSelectedPortrait = 0;
    float newSelectedPortraitDistance = 0;

    if (citadel->ground.hasItemTexture) {
        items.setTexture(citadel->ground.itemTexture);
        itemsTextureRect = items.getTextureRect();
        itemsTextureRect.width = itemsTextureRect.height;
    }
    view.setCenter(0, 0);
    instance.window.setView(view);
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
        color = getTeamColor(citadel, character.second.getTeam());
        character.second.sprite->setFillColor(color);
        if (citadel->selectedCharacter == character.first || \
            citadel->selectedPortrait == character.first)
            SPRITE_PORTRAIT.setColor(color);
        else
            SPRITE_PORTRAIT.setColor(COLOR_ALPHA(color, colorInactive));
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
        if (!citadel->ground.hasItemTexture)
            continue;
        itemsScale = scale;
        items.setScale(itemsScale, itemsScale);
        position.x += SPRITE_PORTRAIT.getTextureRect().width * scale * 0.5 - \
            itemsTextureRect.width * itemsScale * 0.5;
        position.y += SPRITE_PORTRAIT.getTextureRect().height * scale - \
            itemsTextureRect.height * itemsScale;
        for (std::size_t i = 0; i < CITADEL_INVENTORY_SIZE; i++) {
            if (character.second.inventory[i] < 1)
                continue;
            itemsTextureRect.left = itemsTextureRect.width * i;
            items.setTextureRect(itemsTextureRect);
            position.x += character.second.inventory[i] * \
                itemsTextureRect.width * itemsScale * 0.2 * 0.5;
            for (Citadel::InventoryCount j = 0; j < \
                character.second.inventory[i]; j++) {
                items.setPosition(position);
                instance.window.draw(items);
                position.x -= itemsTextureRect.width * itemsScale * 0.2;
            }
            position.x += itemsTextureRect.width * itemsScale * 0.2 * \
                (character.second.inventory[i]);
            position.x -= character.second.inventory[i] * \
                itemsTextureRect.width * itemsScale * 0.2 * 0.5;
            position.y -= itemsTextureRect.height * itemsScale * 0.5;
        }
    }
    instance.window.setView(viewSaved);
    citadel->selectedPortrait = newSelectedPortrait;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        citadel->selectedCharacter = newSelectedPortrait;
}
