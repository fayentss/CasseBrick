#include "GameObj.h"
#include "Ball.h"
#include "Canon.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    //Cr�ation d'une fen�tre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    GameObj* oRect = new GameObj(&oWindow, 20.f, 40.f, 50.f, 50.f, sf::Color::Red);
    Canon* oCanon = new Canon(&oWindow, sf::Color::Yellow);
    


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
            else if (oEvent.type == sf::Event::MouseMoved)
            {
                oCanon->UpdateRot();
            }
            else if (oEvent.type == sf::Event::MouseButtonReleased)
            {
                if (oEvent.mouseButton.button == sf::Mouse::Left)
                {   
                    oCanon->ShootBall();
                }
            }
        }

        //UPDATE
        for (int i = 0; i < oCanon->GetBallList().size(); i++)
        {
            oCanon->GetBallList()[i]->Movement(fDeltaTime);
        }

        //DRAW
        oWindow.clear();

        oRect->Draw();
        oCanon->Draw();
        
        for (int i = 0; i < oCanon->GetBallList().size(); i++)
        {
            oCanon->GetBallList()[i]->Draw();
        }

        oWindow.display();

        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;

}



