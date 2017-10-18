#ifndef PROJECTSFML_PLAYSTATE_H
#define PROJECTSFML_PLAYSTATE_H


#include "IState.h"

class PlayState : public IState {
public:
    PlayState();

    ~PlayState() override;

    void init() override;

    void handleInput(Game& game) override;

    void draw(Game& game) override;
};


#endif //PROJECTSFML_PLAYSTATE_H
//