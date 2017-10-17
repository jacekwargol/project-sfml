#include <SFML/Window/Event.hpp>
#include "Window.h"

Window::Window(const std::string &title, const sf::Vector2u &size) :
        RenderWindow({size.x, size.y}, title, sf::Style::Titlebar | sf::Style::Close) {}

Window::~Window() = default;