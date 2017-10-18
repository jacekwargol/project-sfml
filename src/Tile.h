#ifndef PROJECTSFML_TILE_H
#define PROJECTSFML_TILE_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Window.h"

enum class TileType {Floor, Wall, Plate, Player, Block };
const int TILE_SIZE = 75;

class Tile {
public:
    Tile(TileType type, const sf::Color& color, bool isBlocking,
         const sf::Vector2f& pos);
    ~Tile();

    void draw(Window& window);

    TileType getType() const { return type; }
    sf::Color getColor() const { return color; }
    sf::Vector2f getPosition() const { return pos; }
    void setPosition(const sf::Vector2f& newPos);
    bool isBlocking() const { return blocking; }

private:
    bool blocking;
    TileType type;
    sf::Vector2f pos;
    sf::RectangleShape shape;
    sf::Color color;
};


#endif //PROJECTSFML_TILE_H
