#ifndef PROJECTSFML_LEVEL_H
#define PROJECTSFML_LEVEL_H


#include <memory>
#include "Tile.h"
#include "Window.h"
#include "Block.h"

class Level {
public:
    static Level& getInstance();

    void draw(Window& window);

    void load(const std::string& filename);
    void save(const std::string& filename);

    bool isCollisionWithTile(const sf::Vector2f &pos);
    std::shared_ptr<Block> getCollidingObject(const sf::Vector2f &pos);
    bool isBlockAtCorrectPlate(const Block& block);

private:
    Level();
    ~Level();

    std::vector<Tile> map;
    std::vector<std::shared_ptr<Block>> objects;
    std::vector<Tile> plates;
};


#endif //PROJECTSFML_LEVEL_Hk