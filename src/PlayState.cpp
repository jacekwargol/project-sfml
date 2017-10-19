#include <SFML/Window/Event.hpp>
#include "PlayState.h"
#include "Level.h"

PlayState::PlayState() = default;

PlayState::~PlayState() = default;

void PlayState::init() {
    Level::getInstance().load(Level::getInstance().getLevelNum());
}

void PlayState::handleInput(Game& game) {
    auto player = Level::getInstance().getPlayer();
    sf::Event event{};
    while (game.getWindow().pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    game.getWindow().close();
                } else if (event.key.code == sf::Keyboard::W) {
                    game.handleMovement(*player, MoveDir::Up);
                } else if (event.key.code == sf::Keyboard::S) {
                    game.handleMovement(*player, MoveDir::Down);
                } else if (event.key.code == sf::Keyboard::A) {
                    game.handleMovement(*player, MoveDir::Left);
                } else if (event.key.code == sf::Keyboard::D) {
                    game.handleMovement(*player, MoveDir::Right);
                }
                break;

            default:
                break;
        }
    }
}

void PlayState::draw(Game& game) {
    Level::getInstance().draw(game.getWindow());
}