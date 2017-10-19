//
// Created by ricen on 10/10/17.
//

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "Game.h"
#include "Level.h"
#include "IState.h"
#include "LevelWinState.h"

Game::Game() : window{} {}

Game::~Game() = default;


void Game::gameLoop() {
    while (window.isOpen()) {
        handleDrawing();
        handleInput();
    }
}

void Game::handleInput() {
    states.top()->handleInput(*this);
}

void Game::handleDrawing() {
    window.clear(sf::Color::Black);
    states.top()->draw(*this);
    window.display();
}


void Game::handleLevelWin() {
    Level::getInstance().nextLevel();
    changeState(std::make_shared<LevelWinState>());
}

bool Game::handleMovement(Block &block, MoveDir direction) {
    auto newPos = block.getNewPosition(direction);
    auto collidingBlock = Level::getInstance().getCollidingObject(newPos);
    if (collidingBlock) {
        if (handleMovement(*collidingBlock, direction)) {
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

void Game::changeState(std::shared_ptr<IState> state) {
    PopState();
    states.push(state);
    states.top()->init();
}

void Game::pushState(std::shared_ptr<IState> state) {
    states.push(state);
    states.top()->init();
}

void Game::PopState() {
    if(!states.empty()) {
        states.pop();
    }
}
