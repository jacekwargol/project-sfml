#ifndef PROJECTSFML_LEVELWINSTATE_H
#define PROJECTSFML_LEVELWINSTATE_H


#include "IState.h"

class LevelWinState : public IState {
public:
    LevelWinState();
    ~LevelWinState() override;

    void init() override;

    void handleInput(Game& game) override;

    void draw(Game& game) override;
};


#endif //PROJECTSFML_LEVELWINSTATE_H
