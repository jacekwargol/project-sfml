#ifndef PROJECTSFML_GAME_H
#define PROJECTSFML_GAME_H


#include <stack>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class GameState;

class Game {
public:
    explicit Game(sf::Vector2i windowSize = {800, 600});
    ~Game();

    std::stack<std::shared_ptr<GameState>> states;
    sf::RenderWindow window;

    void pushState(std::shared_ptr<GameState> state);
    void popState();
    void changeState(std::shared_ptr<GameState> state);
    std::shared_ptr<GameState> peekState();

    void gameLoop();

private:
    sf::Vector2u windowSize;
};


#endif //PROJECTSFML_GAME_H
