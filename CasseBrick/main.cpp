#include "GameObj.h"
#include "Ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    Ball* oBall = new Ball(10.f, 10.f, 10.f, sf::Color::Green);
    GameObj* oRect = new GameObj(20.f, 40.f, 50.f, 50.f, sf::Color::Red);

    oBall->;
    oRect->Draw(oRect->GetShape());

    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
            else if (oEvent.type == sf::Event::MouseButtonReleased)
            {
                if (oEvent.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i iMousePos = sf::Mouse::getPosition(oWindow);

                }
            }
        }

        //UPDATE

        //DRAW
        oWindow.clear();

        oWindow.draw(*oBall->GetShape());
        oWindow.draw(*oRect->GetShape());

        oWindow.display();
    }

    return 0;

}



