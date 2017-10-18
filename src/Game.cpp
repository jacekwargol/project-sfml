//
// Created by ricen on 10/10/17.
//

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "Game.h"
#include "Level.h"
#include "IState.h"

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
    states.top()->handleInput(*this);
}

void Game::handleDrawing() {
    window.clear(sf::Color::Black);
    states.top()->draw(*this);
    window.display();
}


void Game::handleLevelWin() {
    std::cout << "level won" << std::endl;
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
    if (!states.empty()) {
        states.pop();
    }
    states.push(state);
}

void Game::pushState(std::shared_ptr<IState> state) {
    states.push(state);
}

void Game::PopState() {

}
