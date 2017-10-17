#ifndef PROJECTSFML_OBJECT_H
#define PROJECTSFML_OBJECT_H


#include "Tile.h"

enum MOVE_DIR {UP, DOWN, LEFT, RIGHT};

class Object {
public:
    Object(TileType type, const sf::Color& color, const sf::Vector2f& position);
    explicit Object(const Tile& tile);
    ~Object();

    bool move(MOVE_DIR direction);

    Tile getTile() const { return tile; }
    sf::Vector2f getPosition() const { return tile.getPosition(); }
    void draw(Window& window);
private:
    Tile tile;
    sf::Vector2f getNewPos(MOVE_DIR direction);
};


#endif //PROJECTSFML_OBJECT_H
