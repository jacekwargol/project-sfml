//
// Created by ricen on 10/10/17.
//

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "Game.h"
#include "Level.h"

Game::Game() : window{}, player{TileType::PLAYER, sf::Color::Blue, {75, 75}} {}

Game::~Game() = default;


void Game::gameLoop() {
    sf::Clock clock;
    Level level{};
    level.load("level1.txt");
    while (window.isOpen()) {
        auto elapsed = clock.restart();
        auto dt = elapsed.asSeconds();
        window.clear(sf::Color::Green);
        level.draw(window);
        player.draw(window);
        window.display();
        handleInput();
    }
}

void Game::handleInput() {
    sf::Event event{};
    while(window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }

                else if(event.key.code == sf::Keyboard::W) {
                    player.move(MOVE_DIR::UP);
                }
                else if(event.key.code == sf::Keyboard::S) {
                    player.move(MOVE_DIR::DOWN);
                }
                else if(event.key.code == sf::Keyboard::A) {
                    player.move(MOVE_DIR::LEFT);
                }
                else if(event.key.code == sf::Keyboard::D) {
                    player.move(MOVE_DIR::RIGHT);
                }
                break;

            default:
                break;
        }
    }
}