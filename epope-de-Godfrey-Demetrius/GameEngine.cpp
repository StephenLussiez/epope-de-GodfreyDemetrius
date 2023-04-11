#include "managers/GameEngine.h"
#include <iostream>
#include "managers/WindowManager.h"


GameEngine::GameEngine() {}

void GameEngine::GameInputs(sf::RenderWindow* window)
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }
    }
}

void GameDrawing() { }

int GameEngine::Gameloop()
{
    WindowManager* windowBox = new WindowManager();
    sf::RenderWindow* window = windowBox->CreateWindow(1920, 1080, "L'épopée de Goldfey Dimitrius");

    while (window->isOpen()) { }
    return (0);
}
