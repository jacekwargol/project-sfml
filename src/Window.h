#ifndef PROJECTSFML_WINDOW_H
#define PROJECTSFML_WINDOW_H


#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Window : public sf::RenderWindow {
public:
    explicit Window(const std::string& title = "Project SFML", const sf::Vector2u& size = {800, 600});
    ~Window();
};


#endif //PROJECTSFML_WINDOW_H
