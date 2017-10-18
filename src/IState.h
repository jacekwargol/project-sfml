#ifndef PROJECTSFML_ISTATE_H
#define PROJECTSFML_ISTATE_H

#include <memory>
#include "Game.h"

class StateManager;

class IState{
public:
    virtual ~IState() = default;

    virtual void init() = 0;

    virtual void handleInput(Game& game) = 0;
    virtual void draw(Game& game) = 0;
};

#endif //PROJECTSFML_ISTATE_H
