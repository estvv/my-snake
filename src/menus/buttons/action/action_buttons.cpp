#include "buttons.hpp"
#include "all.hpp"
#include <iostream>

actionButtons::actionButtons(All &all, const std::string &txt, sf::Vector2f size, sf::Vector2f new_pos, actionButtonFunc func) :
    func(func),
    mouseHoverSound(&all.assets.sounds.at(SOUND_HOVER)),
    mouseClickSound(&all.assets.sounds.at(SOUND_CLICK)),
    state(isNone)
{
    button_rect = sf::RectangleShape(size);
    button_rect.setOutlineThickness(2);
    button_rect.setFillColor(all.colors.menusColors.mainColor);
    button_rect.setOutlineColor(all.colors.menusColors.button);
    button_rect.setPosition(new_pos);
    button_text.setString(txt);
    button_text.setCharacterSize(30);
    button_text.setPosition(
        new_pos.x + (button_rect.getSize().x / 2) - (txt.length() * 10),
        new_pos.y + 5
    );
    button_text.setFont(all.assets.fonts.at(0).font);
}

void actionButtons::isHover(MenusColors menusColors, sf::RenderWindow &window)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::FloatRect rect_pos;

    rect_pos = button_rect.getGlobalBounds();
    if (rect_pos.contains(mouse_pos.x, mouse_pos.y)) {
        if (state != mouseHover)
            mouseHoverSound->sound.play();
        if (button_text.getString().getSize() != 0)
            button_rect.setFillColor(menusColors.buttonHover);
        state = mouseHover;
    } else {
        if (button_text.getString().getSize() != 0)
            button_rect.setFillColor(menusColors.mainColor);
        state = isNone;
    }
}

void actionButtons::isClicked(MenusColors menusColors)
{
    if (state == mouseHover) {
        if (button_text.getString().getSize() != 0)
            button_rect.setFillColor(menusColors.buttonClicked);
        state = mouseClicked;
        mouseClickSound->sound.play();
    } else {
        if (button_text.getString().getSize() != 0)
            button_rect.setFillColor(menusColors.mainColor);
        state = isNone;
    }
}

void actionButtons::onClick(All *all)
{
    func(*all);
}

void actionButtons::displayButtons(sf::RenderWindow &window)
{
    window.draw(button_rect);
    window.draw(button_text);
}
