#ifndef PROJECTSFML_OBJECT_H
#define PROJECTSFML_OBJECT_H


#include "Tile.h"

enum MOVE_DIR {UP, DOWN, LEFT, RIGHT};

class Object {
public:
    Object(TileType type, const sf::Color& color, const sf::Vector2f& position);
    explicit Object(const Tile& tile);
    ~Object();

    void move(MOVE_DIR direction);

    Tile getTile() const { return tile; }
    sf::Vector2f getPosition() const { return tile.getPosition(); }
    void draw(Window& window);
private:
    Tile tile;

    bool isCollision(const sf::Vector2f pos);
};


#endif //PROJECTSFML_OBJECT_H
