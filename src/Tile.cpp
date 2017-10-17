#include "Tile.h"

Tile::Tile(TileType type, const sf::Color &color, bool isBlocking,
           const sf::Vector2f& pos) :
    type{type}, color{color}, blocking{isBlocking}, pos{pos}, shape{{TILE_SIZE, TILE_SIZE}} {

    shape.setFillColor(color);
    shape.setPosition(pos);
}


Tile::~Tile() = default;

void Tile::draw(Window &window) {
    window.draw(shape);
}

void Tile::setPosition(const sf::Vector2f &newPos) {
    pos = newPos;
    shape.setPosition(pos);
}
