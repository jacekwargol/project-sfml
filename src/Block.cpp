#include <iostream>
#include "Block.h"
#include "Level.h"

Block::Block(TileType type, const sf::Color &color, const sf::Vector2f &position) :
        tile{type, color, true, position} {}

Block::~Block() = default;


void Block::draw(Window &window) {
    tile.draw(window);
}

bool Block::move(MoveDir direction) {
    sf::Vector2f newPos = getNewPosition(direction);

    if(!Level::getInstance().isCollisionWithTile(newPos)) {
        tile.setPosition(newPos);
        return true;
    }
}

sf::Vector2f Block::getNewPosition(MoveDir direction) {
    switch (direction) {
        case MoveDir::Up:
            return  {tile.getPosition().x,
                      tile.getPosition().y - TILE_SIZE};
        case MoveDir::Down:
            return  {tile.getPosition().x,
                      tile.getPosition().y + TILE_SIZE};
        case MoveDir::Left:
            return  {tile.getPosition().x - TILE_SIZE,
                      tile.getPosition().y};
        case MoveDir::Right:
            return  {tile.getPosition().x + TILE_SIZE,
                      tile.getPosition().y};
    }
}

