#ifndef EXAMPLE_HPP
    #define EXAMPLE_HPP
    #include "snake.hpp"
    #include "apple.hpp"
    #include "enum.hpp"
    #include "colors.hpp"
    #include <iostream>
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

class All;
class Game {
    public:
        Game(All *all, Colors colors, sf::RenderWindow &window);
        void displayGame(void);
        void manageGameEvent(All &all);
        void update(All &all);
        void endOfGame(All &all);
        void appelEating(All &all);
        void mooveSnake(void);

        Snake snake;
        Apple apple;
        sf::RenderWindow &window;
        sf::Clock clock;
        sf::RectangleShape arena;
        sf::Text score_txt;
        sf::Text round_txt;
        unsigned int score;
        unsigned int round;
    private:
};

#endif // EXAMPLE_HPP
