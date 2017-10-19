#ifndef PROJECTSFML_GAMEWINSTATE_H
#define PROJECTSFML_GAMEWINSTATE_H


#include "IState.h"

class GameWinState : public IState {
public:
    GameWinState();
    ~GameWinState() override;

    void init() override;

    void handleInput(Game& game) override;

    void draw(Game& game) override;
};


#endif //PROJECTSFML_GAMEWINSTATE_H
