#include "GameObj.h"
#include "Ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>

sf::Vector2f GetMoveDirection(sf::Vector2i vMousePos, sf::Vector2f vBallPos, sf::RenderWindow* pWindow)
{
    sf::Vector2f vDirection;
    vDirection.x = (vMousePos.x - pWindow->getSize().x / 2) - vBallPos.x;
    vDirection.y = (vMousePos.y - pWindow->getSize().y / 2) - vBallPos.y;

    float fNorme = sqrt((vDirection.x * vDirection.x) + (vDirection.y * vDirection.y));

    vDirection.x = vDirection.x / fNorme;
    vDirection.y = vDirection.y / fNorme;

    return vDirection;
}

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    Ball* oBall = new Ball(&oWindow, 20.f, sf::Color::Green);
    GameObj* oRect = new GameObj(&oWindow, 20.f, 40.f, 50.f, 50.f, sf::Color::Red);


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
                    sf::Vector2i vMousePos = sf::Mouse::getPosition(oWindow);
                    sf::Vector2f vBallPos = oBall->GetCenterPoint();
                    sf::Vector2f vDirection = GetMoveDirection(sf::Mouse::getPosition(oWindow), oBall->GetCenterPoint(), &oWindow);
                    oBall->IsMoving(true, vDirection);
                }
                else if (oEvent.mouseButton.button == sf::Mouse::Right)
                {
                    oBall->GetShape()->setPosition(310, 230);
                    sf::Vector2f vDirectionNull; 
                    vDirectionNull.x = 0;
                    vDirectionNull.y = 0;
                    oBall->IsMoving(true, vDirectionNull);
                }
            }
        }

        //UPDATE
        oBall->Movement();

        //DRAW
        oWindow.clear();

        oWindow.draw(*oBall->GetShape());
        oWindow.draw(*oRect->GetShape());

        oWindow.display();
    }

    return 0;

}



