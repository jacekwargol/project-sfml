//
// Created by ricen on 10/10/17.
//

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "Game.h"
#include "Level.h"

Game::Game() : window{}, player{} {}

Game::~Game() = default;


void Game::gameLoop() {
    Level::getInstance().load("level1.txt");
    player = Level::getInstance().getPlayer();
    while (window.isOpen()) {
        handleDrawing();
        handleInput();
    }
}

void Game::handleInput() {
    auto player = Level::getInstance().getPlayer();
    sf::Event event{};
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                } else if (event.key.code == sf::Keyboard::W) {
                    handleMovement(*player, MoveDir::Up);
                } else if (event.key.code == sf::Keyboard::S) {
                    handleMovement(*player, MoveDir::Down);
                } else if (event.key.code == sf::Keyboard::A) {
                    handleMovement(*player, MoveDir::Left);
                } else if (event.key.code == sf::Keyboard::D) {
                    handleMovement(*player, MoveDir::Right);
                }
                break;

            default:
                break;
        }
    }
}

void Game::handleDrawing() {
    window.clear(sf::Color::Black);
    Level::getInstance().draw(window);
    window.display();
}


void Game::handleLevelWin() {
    std::cout << "level won" << std::endl;
}

bool Game::handleMovement(Block &block, MoveDir direction) {
    auto newPos = block.getNewPosition(direction);
    auto collidingBlock = Level::getInstance().getCollidingObject(newPos);
    if (collidingBlock) {
        if(handleMovement(*collidingBlock, direction)) {
            block.move(direction);
            if (Level::getInstance().isWin()) {
                handleLevelWin();
            }
            return true;
        }
        return false;
    }

    if (Level::getInstance().isCollisionWithTile(block.getNewPosition(direction))) {
        return false;
    }

    block.move(direction);
    return true;
}
