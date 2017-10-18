#ifndef PROJECTSFML_OBJECT_H
#define PROJECTSFML_OBJECT_H


#include "Tile.h"

enum class MoveDir {Up, Down, Left, Right};

class Block {
public:
    explicit Block(TileType type, const sf::Color& color, const sf::Vector2f& position);
    ~Block();

    bool move(MoveDir direction);

    sf::Vector2f getPosition() const { return tile.getPosition(); }
    sf::Vector2f getNewPosition(MoveDir direction);
    sf::Color getColor() const { return tile.getColor(); }
    void draw(Window& window);

private:
    Tile tile;
};


#endif //PROJECTSFML_OBJECT_H
