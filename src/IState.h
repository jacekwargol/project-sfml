#ifndef PROJECTSFML_ISTATE_H
#define PROJECTSFML_ISTATE_H

#include <bits/shared_ptr.h>
#include "Game.h"

class StateManager;

class IState{
public:
    virtual ~IState() = 0;

    virtual void init() = 0;

    virtual void handleInput(Game &game) = 0;
    virtual void update(Game& game) = 0;
    virtual void draw(Game& game) = 0;
};

#endif //PROJECTSFML_ISTATE_H
