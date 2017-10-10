//
// Created by ricen on 10/10/17.
//

#include "Game.h"
#include "states/GameState.h"

Game::Game(sf::Vector2i windowSize) : windowSize {windowSize}{
    window.create(sf::VideoMode(windowSize.x, windowSize.y), "Flow");
    window.setFramerateLimit(60);
}

Game::~Game() {
    while(!states.empty()) popState();
}

void Game::pushState(std::shared_ptr<GameState> state) {
    states.push(state);
}


void Game::popState() {
    states.pop();
}

void Game::changeState(std::shared_ptr<GameState> state) {
    if(!states.empty()) popState();
    pushState(state);
}

std::shared_ptr<GameState> Game::peekState() {
    return (states.empty() ? nullptr : states.top());
}

void Game::gameLoop() {
    sf::Clock clock;

    while (window.isOpen()) {
        auto elapsed = clock.restart();
        auto dt = elapsed.asSeconds();

        if(peekState() == nullptr) continue;

        peekState()->handleInput();
        peekState()->update(dt);
        window.clear(sf::Color::Black);
        peekState()->draw(dt);
        window.display();
    }
}