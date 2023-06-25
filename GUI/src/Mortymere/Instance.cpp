/*
** EPITECH PROJECT, 2023
** Mortymere/Instance.cpp
** File description:
** -
*/

#include "Mortymere/Instance.hpp"
#include "Mortymere/Sprite.hpp"
#include "Mortymere/Sprites/Character.hpp"

#define INSTANCE Mortymere::Instance
#define DISPLAY_MODULES(TYPE) \
    for (Mortymere::InstanceDisplayModule module: displayModules) \
    if (module.type == TYPE) module.function(*this, module.data)

static bool sortObjects(Mortymere::SpritePtr const object1, \
    Mortymere::SpritePtr const object2)
{
    if (Mortymere::Sprite sprite1 = object1.lock()) {
        if (Mortymere::Sprite sprite2 = object2.lock()) {
            if (sprite1->layer() != sprite2->layer())
                return sprite1->layer() < sprite2->layer();
            return sprite1->anchor().z < sprite2->anchor().z;
        } else return false;
    } else return true;
}

INSTANCE::Instance(void) : camera(window)
{ }

void INSTANCE::addDisplayModule(std::string const &type, \
    Mortymere::InstanceDisplayModuleType function)
{
    displayModules.push_back({function, type, nullptr});
}

void INSTANCE::addDisplayModule(std::string const &type, \
    Mortymere::InstanceDisplayModuleType \
    function, void *data)
{
    displayModules.push_back({function, type, data});
}

void INSTANCE::addObject(Mortymere::SpritePtr objectPtr)
{
    _objects.push_back(objectPtr);
}

void INSTANCE::operator<<(Mortymere::SpritePtr objectPtr)
{
    _objects.push_back(objectPtr);
}

bool INSTANCE::udpate(void)
{
    sf::View view;
    sf::View viewSaved;
    sf::Event event;
    sf::Vector2f screenSize;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::LostFocus)
            window.hasFocus = false;
        if (event.type == sf::Event::GainedFocus)
            window.hasFocus = true;
    }
    if (window.hasFocus || window.isFullscreen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        if (!window.isFullscreen()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                window.setFullscreen(true);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            window.setFullscreen(false);
    }
    window.update();
    window.clear(sf::Color::Black);
    window.draw(_ground);
    DISPLAY_MODULES("preobj");
    _objects.sort(sortObjects);
    for (auto object = _objects.begin(); object != _objects.end();) {
        if (Mortymere::Sprite sprite = object->lock())
            sprite->drawOn(*this);
        else
            _objects.erase(object++);
        object++;
    }
    DISPLAY_MODULES("postobj");
    view = window.getView();
    viewSaved = view;
    view.setCenter(0, 0);
    screenSize = window.getView().getSize();
    screenCover.setSize({static_cast<float>(screenSize.x), \
        static_cast<float>(screenSize.y)});
    screenCover.setOrigin(screenSize.x / 2, screenSize.y / 2);
    DISPLAY_MODULES("ui");
    window.setView(viewSaved);
    window.display();
    return window.isOpen();
}
