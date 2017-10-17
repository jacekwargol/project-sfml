#include <SFML/Graphics/Text.hpp>
#include "TextManager.h"

void TextManager::draw(const std::string &text, sf::RenderWindow &window, sf::Vector2u pos, int size,
   sf::Color color, const std::string& fontName) {
    sf::Font font;
    font.loadFromFile("../" + fontName);
    sf::Text txt;
    txt.setFont(font);
    txt.setString(text);
    txt.setCharacterSize(size);
    txt.setColor(color);
    txt.setPosition(pos.x, pos.y);
    window.draw(txt);

}

void TextManager::drawAtCenter(const std::string &text, sf::RenderWindow &window, int size,
  sf::Color color, const std::string &fontName) {
    sf::Font font;
    font.loadFromFile("../" + fontName);
    sf::Text txt;
    txt.setFont(font);
    txt.setString(text);
    txt.setCharacterSize(size);
    txt.setColor(color);

    auto txtRect = txt.getLocalBounds();
    txt.setOrigin(txtRect.left + txtRect.width / 2, txtRect.top + txtRect.height / 2);
    txt.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    window.draw(txt);
}


