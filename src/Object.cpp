#include "Object.h"
#include "Level.h"

Object::Object(TileType type, const sf::Color &color, const sf::Vector2f &position) :
        tile{type, color, true, position} {}

Object::Object(const Tile &tile) : tile{tile} {}

Object::~Object() = default;


void Object::draw(Window &window) {
    tile.draw(window);
}

bool Object::move(MOVE_DIR direction) {
    sf::Vector2f newPos = getNewPos(direction);
    auto collidingObject = Level::getInstance().getCollidingObject(newPos);
    if(collidingObject) {
        if(collidingObject->move(direction)) {
            tile.setPosition(newPos);
            return true;
        }
        else{
            return false;
        }
    }
    if(!Level::getInstance().isCollisionWithTile(newPos)) {
        tile.setPosition(newPos);
        return true;
    }
}

sf::Vector2f Object::getNewPos(MOVE_DIR direction) {
    switch (direction) {
        case UP:
            return  {tile.getPosition().x,
                      tile.getPosition().y - TILE_SIZE};
        case DOWN:
            return  {tile.getPosition().x,
                      tile.getPosition().y + TILE_SIZE};
        case LEFT:
            return  {tile.getPosition().x - TILE_SIZE,
                      tile.getPosition().y};
        case RIGHT:
            return  {tile.getPosition().x + TILE_SIZE,
                      tile.getPosition().y};
    }
}

