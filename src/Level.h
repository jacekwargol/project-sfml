#ifndef PROJECTSFML_LEVEL_H
#define PROJECTSFML_LEVEL_H


#include <memory>
#include "Tile.h"
#include "Window.h"
#include "Block.h"

class Level {
public:
    static Level& getInstance();
    static void draw(Window& window);
    static void load(const std::string& filename);
    static void save(const std::string& filename);

    static bool isCollisionWithTile(const sf::Vector2f &pos);
    static std::shared_ptr<Block> getCollidingObject(const sf::Vector2f &pos);
    static bool isBlockAtCorrectPlate(const Block& block);

private:
    Level();
    ~Level();

    static std::vector<Tile> map;
    static std::vector<std::shared_ptr<Block>> objects;
    static std::vector<Tile> plates;
};


#endif //PROJECTSFML_LEVEL_Hk