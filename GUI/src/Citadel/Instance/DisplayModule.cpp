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
            return COLORS[i % COLORS_LENGTH];
    citadel->teams.push_back(team);
    return COLORS[teamsSize % COLORS_LENGTH];
}

MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleUIMenu)
{
    if (!data) return;
    Citadel::Instance *citadel = reinterpret_cast<Citadel::Instance *>(data);
    sf::Color screenCoverColor = sf::Color::Black;
    bool isCurrentMenu = \
        citadel->currentMenu != Citadel::InstanceCurrentMenu::None;
    bool isLastMenu = \
        citadel->lastMenu != Citadel::InstanceCurrentMenu::None;

    if (!isCurrentMenu && !isLastMenu)
        return;
    if (isCurrentMenu && isLastMenu)
        screenCoverColor.a = 220;
    else if (isLastMenu)
        screenCoverColor.a = 220 - 220 * citadel->menuTransition;
    else
        screenCoverColor.a = 220 * citadel->menuTransition;
    instance.screenCover.setFillColor(screenCoverColor);
    instance.window.draw(instance.screenCover);
}

MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleUIMainMenu)
{
    if (!data) return;
    Citadel::Instance *citadel = reinterpret_cast<Citadel::Instance *>(data);
    sf::Color buttonPlayColor = sf::Color::White;
    sf::IntRect textureRect;
    sf::IntRect textureRectOld;
    sf::Vector2f const windowSize = instance.window.getView().getSize();
    sf::Vector2f position;
    bool isCurrentMenu = \
        citadel->currentMenu == Citadel::InstanceCurrentMenu::MainMenu;
    bool isLastMenu = \
        citadel->lastMenu == Citadel::InstanceCurrentMenu::MainMenu;

    if (!isCurrentMenu) {
        citadel->mainMenuButtonPlay.reset();
        if (!isLastMenu)
            return;
    }
    if (citadel->isMainMenuCoverTextureLoaded) {
        textureRectOld = citadel->mainMenuCoverTextureRect;
        textureRect = textureRectOld;
        textureRect.left = (textureRectOld.width - windowSize.x) * \
            (static_cast<float>(instance.window.mouseUI.x) / windowSize.x / 2 \
            + 1) / 2;
        textureRect.top = (textureRectOld.height - windowSize.y) * \
            (static_cast<float>(instance.window.mouseUI.y) / windowSize.y / 2 \
            + 1) / 2;
        textureRect.height = windowSize.x;
        textureRect.width = windowSize.y;
        position = {windowSize.x / 2, windowSize.y / 2};
        position.y -= windowSize.y * 0.18;
        if (!isCurrentMenu)
            position.y -= windowSize.y * citadel->menuTransition / 2;
        else if (!isLastMenu)
            position.y -= windowSize.y * (1 - citadel->menuTransition) / 2;
        citadel->mainMenuCover.setTextureRect(textureRect);
        citadel->mainMenuCover.setSize(windowSize);
        citadel->mainMenuCover.setOrigin(position);
        instance.window.draw(citadel->mainMenuCover);
    }
    if (citadel->isMainMenuTitleTextureLoaded) {
        textureRectOld = citadel->mainMenuTitleTextureRect;
        textureRect = textureRectOld;
        textureRect.left = (textureRectOld.width - windowSize.x) / 2;
        textureRect.top = (textureRectOld.height - windowSize.y) / 2;
        textureRect.height = windowSize.x;
        textureRect.width = windowSize.y;
        position = {windowSize.x / 2, windowSize.y / 2};
//        position.y -= windowSize.y * 0.18;
        if (!isCurrentMenu)
            position.y += windowSize.y * citadel->menuTransition / 2;
        else if (!isLastMenu)
            position.y += windowSize.y * (1 - citadel->menuTransition) / 2;
        citadel->mainMenuTitle.setTextureRect(textureRect);
        citadel->mainMenuTitle.setSize(windowSize);
        citadel->mainMenuTitle.setOrigin(position);
        instance.window.draw(citadel->mainMenuTitle);
    }
    if (!isCurrentMenu)
        buttonPlayColor.a = 255 * (1 - citadel->menuTransition);
    else if (!isLastMenu)
        buttonPlayColor.a = 255 * citadel->menuTransition;
    citadel->mainMenuButtonPlay.setColor(buttonPlayColor);
    citadel->mainMenuButtonPlay.setPosition( \
        citadel->mainMenuButtonPlay.getGlobalBounds().width * -0.5, \
        citadel->mainMenuButtonPlay.getGlobalBounds().height * -0.5 + \
        windowSize.y * -0.05);
    if (isCurrentMenu && citadel->mainMenuButtonPlay.update( \
        instance.window.mouseUI, instance.window.hasFocus && \
        sf::Mouse::isButtonPressed(sf::Mouse::Left)).hasBeenPressed())
        citadel->changeCurrentMenu(Citadel::InstanceCurrentMenu::None);
    instance.window.draw(citadel->mainMenuButtonPlay);
}

MORTYMERE_INSTANCE_DISPLAY_MODULE(citadelDisplayModuleUINone)
{
    if (!data) return;
    Citadel::Instance *citadel = reinterpret_cast<Citadel::Instance *>(data);
    sf::Vector2f const windowSize = instance.window.getView().getSize();

    citadel->noneButtonSettings.setPosition(windowSize.x / -2 + 1, \
        windowSize.y / -2 + 1);
    citadel->noneButtonSettings.setScale(0.8f, 0.8f);
    if (citadel->currentMenu != Citadel::InstanceCurrentMenu::None) {
        citadel->noneButtonSettings.reset();
    } else {
        if (citadel->noneButtonSettings.update(instance.window.mouseUI, \
            instance.window.hasFocus && \
            sf::Mouse::isButtonPressed(sf::Mouse::Left)).hasBeenPressed())
            citadel->changeCurrentMenu(Citadel::InstanceCurrentMenu::MainMenu);
    }
    instance.window.draw(citadel->noneButtonSettings);
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
    Citadel::CharacterNumber newSelectedPortrait = 0;
    float newSelectedPortraitDistance = 0;

    if (citadel->ground.hasItemTexture) {
        items.setTexture(citadel->ground.itemTexture);
        itemsTextureRect = items.getTextureRect();
        itemsTextureRect.width = itemsTextureRect.height;
    }
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
            if (citadel->currentMenu == Citadel::InstanceCurrentMenu::None) {
                newSelectedPortrait = character.first;
                newSelectedPortraitDistance = std::abs( \
                    instance.window.mouseUI.x - bounds.left - bounds.width / \
                    2);
            }
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
    citadel->selectedPortrait = newSelectedPortrait;
    if (instance.window.hasFocus && \
         sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        citadel->selectedCharacter = newSelectedPortrait;
}

MORTYMERE_INSTANCE_DISPLAY_MODULE_NODATA(citadelDisplayModuleGround)
{
    sf::Color screenCoverColor(183, 196, 196);

    instance.screenCover.setFillColor(screenCoverColor);
    instance.window.draw(instance.screenCover);
}
