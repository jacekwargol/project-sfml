#include <SFML/Window/Event.hpp>
#include "LevelWinState.h"
#include "PlayState.h"
#include "TextManager.h"


LevelWinState::LevelWinState() = default;
LevelWinState::~LevelWinState() = default;

void LevelWinState::init() {}

void LevelWinState::handleInput(Game &game) {
    sf::Event event{};
    while (game.getWindow().pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    game.getWindow().close();
                } else if (event.key.code == sf::Keyboard::Space) {
                    game.changeState(std::make_shared<PlayState>());
                }
                break;

            default:
                break;
        }
    }
}

void LevelWinState::draw(Game &game) {
    TextManager::drawAtCenter("Level won. Press 'SPACE' to continue.", game.getWindow(), 32);
}

