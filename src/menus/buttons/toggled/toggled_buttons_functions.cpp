#include "all.hpp"

const char *alpha[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

void resetTheme(All &all, toggledButtons &button)
{
    all.colors.mainColor = sf::Color::Black;
    all.colors.button = sf::Color::Green;
    all.colors.buttonText = sf::Color::White;
    all.colors.buttonHover = sf::Color(0, 150, 0);
    all.colors.buttonClicked = sf::Color(0, 100, 0);
    all.colors.snakeHead = sf::Color(0, 150, 0);
    all.colors.snakeBody = sf::Color(0, 200, 0);
    all.colors.apple = sf::Color::Red;
    all.updateThemeColors();
    button.button_rect.setOutlineColor(sf::Color::White);
}

void setLightBlueTheme(All &all, toggledButtons &button)
{
    all.colors.mainColor = sf::Color(204, 219, 253);
    all.colors.button = sf::Color(0, 40, 85);
    all.colors.buttonText = sf::Color(109, 118, 136);
    all.colors.buttonHover = sf::Color(183, 197, 227);
    all.colors.buttonClicked = sf::Color(146, 157, 181);
    all.colors.snakeHead = sf::Color(3, 83, 164);
    all.colors.snakeBody = sf::Color(4, 102, 200);
    all.colors.apple = sf::Color(20, 21, 25);
    all.updateThemeColors();
    button.button_rect.setOutlineColor(sf::Color::Black);
}

void setRedAndYellowTheme(All &all, toggledButtons &button)
{
    all.colors.mainColor = sf::Color(255, 102, 102);
    all.colors.button = sf::Color(244, 232, 105);
    all.colors.buttonText = sf::Color(142, 56, 56);
    all.colors.buttonHover = sf::Color(197, 187, 84);
    all.colors.buttonClicked = sf::Color(177, 168, 75);
    all.colors.snakeHead = sf::Color(216, 202, 57);
    all.colors.snakeBody = sf::Color(241, 225, 64);
    all.colors.apple = sf::Color(255, 213, 128);
    all.updateThemeColors();
    button.button_rect.setOutlineColor(sf::Color::Black);
}

void setPinkTheme(All &all, toggledButtons &button)
{
    all.colors.mainColor = sf::Color(255, 204, 230);
    all.colors.button = sf::Color(155, 123, 140);
    all.colors.buttonText = sf::Color(139, 110, 126);
    all.colors.buttonHover = sf::Color(222, 177, 200);
    all.colors.buttonClicked = sf::Color(125, 99, 113);
    all.colors.snakeBody = sf::Color(255, 155, 210);
    all.colors.snakeHead = sf::Color(229, 139, 189);
    all.colors.apple = sf::Color::White;
    all.updateThemeColors();
    button.button_rect.setOutlineColor(sf::Color::Black);
}

void setRainbowTheme(All &all, UN toggledButtons &button)
{
    all.updateThemeColors();
}

void upInputKey(All &all, toggledButtons &button)
{
    if (all.event.key.code >= 0 && all.event.key.code <= 25) {
        button.button_text.setString(alpha[all.event.key.code]);
        all.settings.up = all.event.key.code;
    }
}

void downInputKey(All &all, toggledButtons &button)
{
    if (all.event.key.code >= 0 && all.event.key.code <= 25) {
        button.button_text.setString(alpha[all.event.key.code]);
        all.settings.down = all.event.key.code;
    }
}

void rightInputKey(All &all, toggledButtons &button)
{
    if (all.event.key.code >= 0 && all.event.key.code <= 25) {
        button.button_text.setString(alpha[all.event.key.code]);
        all.settings.right = all.event.key.code;
    }
}

void leftInputKey(All &all, toggledButtons &button)
{
    if (all.event.key.code >= 0 && all.event.key.code <= 25) {
        button.button_text.setString(alpha[all.event.key.code]);
        all.settings.left = all.event.key.code;
    }
}

void noneToggled(UN All &all, UN toggledButtons &button)
{
    return;
}
