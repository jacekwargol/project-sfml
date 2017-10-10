#ifndef PROJECTSFML_GAMESTATE_H
#define PROJECTSFML_GAMESTATE_H


#include <bits/unique_ptr.h>
#include "../Game.h"

class GameState {
public:
    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;
};


#endif //PROJECTSFML_GAMESTATE_H
