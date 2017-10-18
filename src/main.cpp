#include "Game.h"
#include "PlayState.h"

int main() {
    Game game{};
    game.pushState(std::make_shared<PlayState>());
    game.gameLoop();
}