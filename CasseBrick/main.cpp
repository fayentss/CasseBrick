#include "GameObj.h"
#include "Ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Brick.h"

sf::Vector2f GetMoveDirection(sf::Vector2i vMousePos, sf::Vector2f vBallPos, sf::RenderWindow* pWindow)
{
    sf::Vector2f vDirection;
    vDirection.x = vMousePos.x - vBallPos.x;
    vDirection.y = vMousePos.y - vBallPos.y;

    float fNorme = sqrt((vDirection.x * vDirection.x) + (vDirection.y * vDirection.y));

    vDirection.x = vDirection.x / fNorme;
    vDirection.y = vDirection.y / fNorme;

    return vDirection;
}

int main(int argc, char** argv)
{
    //Cr�ation d'une fen�tre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    Ball* oBall = new Ball(&oWindow, 20.f, sf::Color::Green);
    Brick* oBrick = new Brick(&oWindow, 40.f, 80.f, 50, 50, sf::Color::Red);
    float fDeltaTime = 0;
    //GameLoop
    while (oWindow.isOpen())
    {
        sf::Clock oClock;
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
                    oBall->IsMoving(false, vDirectionNull);
                }
            }
        }

        //UPDATE
        oBall->Movement(fDeltaTime);
        if (oBall->WindowCollider() == true)
        {
            sf::Vector2f vDirectionNull;
            vDirectionNull.x = 0;
            vDirectionNull.y = 0;
            oBall->IsMoving(false, vDirectionNull);
        }
        if (oBall->BlocCollider(oBrick) == true)
        {
            sf::Vector2f vDirectionNull;
            vDirectionNull.x = 0;
            vDirectionNull.y = 0;
            oBall->IsMoving(false, vDirectionNull);
        }

        //DRAW
        oWindow.clear();

        oWindow.draw(*oBrick->GetShape());
        oWindow.draw(*oBall->GetShape());

        oWindow.display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;

}



