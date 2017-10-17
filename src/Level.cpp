#include <iostream>
#include <fstream>
#include "Level.h"


std::vector<Tile> Level::map{};
std::vector<std::shared_ptr<Block>> Level::objects{};
std::vector<Tile> Level::plates{};


Level &Level::getInstance() {
    static Level instance;
    return instance;
}


Level::Level() {
    objects.emplace_back(std::make_shared<Block>(
            Block{TileType::BLOCK, sf::Color::Green, {150, 75}}
    ));
    plates.emplace_back(Tile{TileType::PLATE, sf::Color::Green, true, {300, 75}});
}

Level::~Level() = default;

void Level::draw(Window &window) {
    for (auto &tile : map) {
        tile.draw(window);
    }
    for (auto &plate : plates) {
        plate.draw(window);
    }
    for (auto &obj : objects) {
        obj->draw(window);
    }
}

void Level::load(const std::string &filename) {
    map.clear();

    std::ifstream level(filename);
    std::string typeStr, redStr, greenStr, blueStr, alphaStr,
            isBlockingStr, posxStr, posyStr;
    while (level >> typeStr >> redStr >> greenStr >> blueStr >> alphaStr >>
                 isBlockingStr >> posxStr >> posyStr) {
        auto type = static_cast<TileType>(std::stoi(typeStr));
        sf::Color color{
                static_cast<sf::Uint8>(std::stoi(redStr)),
                static_cast<sf::Uint8>(std::stoi(greenStr)),
                static_cast<sf::Uint8>(std::stoi(blueStr)),
                static_cast<sf::Uint8>(std::stoi(alphaStr))
        };
        auto isBlocking = static_cast<bool>(std::stoi(isBlockingStr));
        sf::Vector2f pos{std::stof(posxStr) * TILE_SIZE, std::stof(posyStr) * TILE_SIZE};
        map.emplace_back(Tile{type, color, isBlocking, pos});
    }

}

void Level::save(const std::string &filename) {
    std::ofstream level(filename);

    for (Tile &tile : map) {
        level << tile.getType() << " ";
        level << static_cast<unsigned>(tile.getColor().r) << " ";
        level << static_cast<unsigned>(tile.getColor().g) << " ";
        level << static_cast<unsigned>(tile.getColor().b) << " ";
        level << static_cast<unsigned>(tile.getColor().a) << " ";
        level << tile.isBlocking() << " ";
        level << tile.getPosition().x / TILE_SIZE << " ";
        level << tile.getPosition().y / TILE_SIZE << "\n";
    }

    level.close();
}

bool Level::isCollisionWithTile(const sf::Vector2f &pos) {
    return std::find_if(map.cbegin(), map.cend(),
                        [&](const Tile &tile) {
                            return tile.getPosition() == pos && tile.isBlocking();
                        }) != map.cend();
}

std::shared_ptr<Block> Level::getCollidingObject(const sf::Vector2f &pos) {
    auto obj = std::find_if(objects.cbegin(), objects.cend(),
                            [&](const std::shared_ptr<Block> object) {
                                return object->getPosition() == pos;
                            });
    return obj != objects.cend() ? *obj : nullptr;
}

bool Level::isBlockAtCorrectPlate(const Block &block) {
    return std::find_if(plates.cbegin(), plates.cend(),
                        [&](const Tile &plate) {
                            return plate.getPosition() == block.getPosition() && plate.getColor() == block.getColor();
                        }) != plates.cend();
}
