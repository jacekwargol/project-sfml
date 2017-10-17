#ifndef PROJECTSFML_TEXTMANAGER_H
#define PROJECTSFML_TEXTMANAGER_H

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

class TextManager {
public:
    static void draw(const std::string& text, sf::RenderWindow& window, sf::Vector2u pos, int size,
        sf::Color color = sf::Color::White, const std::string& fontName = "Roboto-Medium.ttf");
    static void drawAtCenter(const std::string& text, sf::RenderWindow& window, int size,
        sf::Color color = sf::Color::White, const std::string& fontName = "Roboto-Medium.ttf");
};


#endif //PROJECTSFML_TEXTMANAGER_H
