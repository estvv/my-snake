#include "menus.hpp"
#include "all.hpp"

Menu::Menu(sf::RenderWindow &window) :
    window(window)
{
}

void Menu::manageMenusEvent(All &all)
{
    while (all.window.pollEvent(all.event)) {
        if (all.event.type == sf::Event::Closed)
            window.close();
        if (all.event.type != sf::Event::MouseButtonReleased and
            all.event.type == sf::Event::MouseButtonPressed)
            inputClickPressed(all);
        if (all.event.type == sf::Event::MouseButtonReleased and
            all.event.type != sf::Event::MouseButtonPressed)
            inputClickReleased(all);
        if (all.event.type == sf::Event::KeyPressed and
            all.event.type != sf::Event::KeyReleased)
            inputKey(all);
    }
}

void Menu::inputClickPressed(All &all)
{
    if (all.event.mouseButton.button == sf::Mouse::Left) {
        for (toggledButtons &button : toggledButtonsList)
            button.isClicked(all.colors.menusColors);
        for (actionButtons &button : actionButtonsList)
            button.isClicked(all.colors.menusColors);
    }
}

void Menu::inputClickReleased(All &all)
{
    if (all.event.mouseButton.button == sf::Mouse::Left) {
        for (toggledButtons &button : toggledButtonsList) {
            if (button.state == mouseClicked) {
                button.onClick(&all);
            }
        }
        for (actionButtons &button : actionButtonsList) {
            if (button.state == mouseClicked) {
                button.onClick(&all);
                button.state = isNone;
            }
        }
    }
}

void Menu::inputKey(All &all)
{
    if (all.event.key.code == sf::Keyboard::Escape) {
        all.assets.sounds.at(SOUND_ESCAPE).sound.play();
        for (toggledButtons &button : toggledButtonsList)
            button.state = isNone;
        if (all.screen_id == pauseMenu)
            all.screen_id = snakePlayScreen;
        else if (all.screen_id != mainMenu)
            all.screen_id = mainMenu;
        else
            window.close();
    }
    for (toggledButtons &button : toggledButtonsList) {
        if (button.state == mouseClicked) {
            button.inputKeyFunction(all, button);
            button.mouseInputSound->sound.play();
        }
    }
}

void Menu::updateMenus(Colors colors)
{
    for (toggledButtons &button : toggledButtonsList) {
        if (button.state == mouseClicked)
            continue;
        button.isHover(colors.menusColors, window);
    }
    for (actionButtons &button : actionButtonsList) {
        if (button.state == mouseClicked)
            continue;
        button.isHover(colors.menusColors, window);
    }
    for (Buttons &button : buttonsList) {
        if (button.state == mouseClicked)
            continue;
        button.isHover(colors.menusColors, window);
    }
}

void Menu::displayMenus(void)
{
    for (toggledButtons &button : toggledButtonsList)
        button.displayButtons(window);
    for (actionButtons &button : actionButtonsList)
        button.displayButtons(window);
    for (Buttons &button : buttonsList)
        button.displayButtons(window);
}
