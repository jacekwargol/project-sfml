#include <SFML/Window/Event.hpp>
#include "PlayState.h"
#include "TextManager.h"
#include "GameWinState.h"
#include "Level.h"


GameWinState::GameWinState() = default;
GameWinState::~GameWinState() = default;

void GameWinState::init() {}

void GameWinState::handleInput(Game &game) {
    sf::Event event{};
    while (game.getWindow().pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    game.getWindow().close();
                } else if (event.key.code == sf::Keyboard::Space) {
                    Level::getInstance().reset();
                    game.changeState(std::make_shared<PlayState>());
                }
                break;

            default:
                break;
        }
    }
}

void GameWinState::draw(Game &game) {
    TextManager::draw("You have won the game!", game.getWindow(),
                     {game.getWindow().getSize().x / 2 - 270, game.getWindow().getSize().y / 2 - 120}, 50);
    TextManager::drawAtCenter("Press 'SPACE' to play again", game.getWindow(), 32);
    TextManager::draw("Press 'ESC' to quit", game.getWindow(),
                      {game.getWindow().getSize().x / 2 - 130, game.getWindow().getSize().y / 2 + 40}, 32);
}

