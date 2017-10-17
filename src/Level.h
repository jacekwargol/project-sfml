#ifndef PROJECTSFML_LEVEL_H
#define PROJECTSFML_LEVEL_H


#include "Tile.h"
#include "Window.h"
#include "Object.h"

class Level {
public:
    Level();
    ~Level();

    void draw(Window& window);
    void load(const std::string& filename);
    void save(const std::string& filename);

    bool isCollision(const Object& object);
private:
    std::vector<Tile> map;
    int numTiles;
};


#endif //PROJECTSFML_LEVEL_Hk