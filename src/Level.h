#ifndef PROJECTSFML_LEVEL_H
#define PROJECTSFML_LEVEL_H


#include <memory>
#include "Tile.h"
#include "Window.h"
#include "Object.h"

class Level {
public:
    static Level& getInstance();
    static void draw(Window& window);
    static void load(const std::string& filename);
    static void save(const std::string& filename);

    bool isCollisionWithTile(const sf::Vector2f &pos);
    std::shared_ptr<Object> getCollidingObject(const sf::Vector2f &pos);

private:
    Level();
    ~Level();

    static std::vector<Tile> map;
    static std::vector<std::shared_ptr<Object>> objects;

};


#endif //PROJECTSFML_LEVEL_Hk