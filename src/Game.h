#ifndef PROJECTSFML_GAME_H
#define PROJECTSFML_GAME_H


#include <memory>
#include "Window.h"
#include "Block.h"


class Game {
public:
    explicit Game();
    ~Game();

    void gameLoop();

private:
    Window window;
    Block player;

    void handleInput();
    void draw();
};


#endif //PROJECTSFML_GAME_H
