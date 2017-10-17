#ifndef PROJECTSFML_GAME_H
#define PROJECTSFML_GAME_H


#include <memory>
#include "Window.h"
#include "Block.h"


class Game {
public:
    explicit Game();
    ~Game();

    Window& getWindow() { return window; }

    void gameLoop();

private:
    Window window;
    Block player;

    void handleInput();
};


#endif //PROJECTSFML_GAME_H
