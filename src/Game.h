#ifndef PROJECTSFML_GAME_H
#define PROJECTSFML_GAME_H


#include <memory>
#include <stack>
#include "Window.h"
#include "Block.h"

class IState;

class Game {
public:
    explicit Game();
    ~Game();

    void gameLoop();

    void changeState(std::shared_ptr<IState> state);
    void pushState(std::shared_ptr<IState> state);
    void PopState();
    Window& getWindow() { return window; }
    bool handleMovement(Block& block, MoveDir direction);

private:
    Window window;
//    std::shared_ptr<Block> player;
    std::stack<std::shared_ptr<IState>> states;

    void handleInput();
    void handleDrawing();

    void handleLevelWin();
};


#endif //PROJECTSFML_GAME_H
