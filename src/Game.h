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
    void handleDrawing();

    bool handleMovement(Block& block, MoveDir direction);
    void handleLevelWin();
};


#endif //PROJECTSFML_GAME_H
