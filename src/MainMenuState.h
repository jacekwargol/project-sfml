#ifndef PROJECTSFML_MAINMENUSTATE_H
#define PROJECTSFML_MAINMENUSTATE_H


#include "IState.h"

class MainMenuState : public IState {
public:
    MainMenuState();
    ~MainMenuState();

    void init() override;

    void handleInput(Game& game) override;

    void draw(Game& game) override;
};


#endif //PROJECTSFML_MAINMENUSTATE_H
