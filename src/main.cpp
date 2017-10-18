#include "Game.h"
#include "PlayState.h"
#include "MainMenuState.h"

int main() {
    Game game{};
    game.pushState(std::make_shared<MainMenuState>());
    game.gameLoop();
}