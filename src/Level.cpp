#include <iostream>
#include <fstream>
#include "Level.h"

Level::Level() : numTiles{0}, map{} {
}

Level::~Level() = default;

void Level::draw(Window &window) {
    for(auto& tile : map) {
        tile.draw(window);
    }
}

void Level::load(const std::string &filename) {
    map.clear();

    std::ifstream level(filename);
    std::string typeStr, redStr, greenStr, blueStr, alphaStr,
            isBlockingStr, posxStr, posyStr;
    while(level >> typeStr >> redStr >> greenStr >> blueStr >> alphaStr >>
                isBlockingStr >> posxStr >> posyStr) {
        auto type = static_cast<TileType>(std::stoi(typeStr));
        sf::Color color {
                std::stoi(redStr),
                std::stoi(greenStr),
                std::stoi(blueStr),
                std::stoi(alphaStr)
        };
        auto isBlocking = static_cast<bool>(std::stoi(isBlockingStr));
        sf::Vector2f pos{std::stof(posxStr), std::stof(posyStr)};
        map.push_back(Tile{type, color, false, pos});
    }

}

void Level::save(const std::string &filename) {
    std::ofstream level(filename);

    for(Tile& tile : map) {
        level << tile.getType() << " ";
        level << static_cast<unsigned>(tile.getColor().r) << " ";
        level << static_cast<unsigned>(tile.getColor().g) << " ";
        level << static_cast<unsigned>(tile.getColor().b) << " ";
        level << static_cast<unsigned>(tile.getColor().a) << " ";
        level << tile.isBlocking() << " ";
        level << tile.getPosition().x << " ";
        level << tile.getPosition().y << "\n";
    }

//    level.close();
}

bool Level::isCollision(const Object &object) {
    sf::Vector2f pos = object.getTile().getPosition();
    for(const auto& tile : map) {
        if(pos == tile.getPosition() && tile.isBlocking()) {
            return true;
        }
    }

    return false;
}
