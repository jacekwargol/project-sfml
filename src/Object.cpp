#include "Object.h"

Object::Object(TileType type, const sf::Color &color, const sf::Vector2f &position) :
        tile{type, color, true, position} {}

Object::Object(const Tile &tile) : tile{tile} {}

Object::~Object() = default;


void Object::draw(Window &window) {
    tile.draw(window);
}

void Object::move(MOVE_DIR direction) {
    sf::Vector2f newPos{};
    switch (direction) {
        case UP:
            newPos = {tile.getPosition().x,
                tile.getPosition().y - TILE_SIZE};
            break;
        case DOWN:
            newPos = {tile.getPosition().x,
                tile.getPosition().y + TILE_SIZE};
            break;
        case LEFT:
            newPos = {tile.getPosition().x - TILE_SIZE,
                tile.getPosition().y};
            break;
        case RIGHT:
            newPos = {tile.getPosition().x + TILE_SIZE,
                tile.getPosition().y};
            break;

        default:
            break;
        }

    tile.setPosition(newPos);
}

bool Object::isCollision(const sf::Vector2f pos) {
    return false;
}


