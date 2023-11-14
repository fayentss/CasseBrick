#include "GameObj.h"
#include "Ball.h"
#include "Canon.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Brick.h"
#include "LevelCreator.h"

int main(int argc, char** argv)
{
    //Cr�ation d'une fen�tre
    sf::RenderWindow oWindow(sf::VideoMode(1280, 720), "SFML");
    
    LevelCreator* oLevel = new LevelCreator(&oWindow);
    GameObj* oRect = new GameObj(&oWindow, 20.f, 40.f, 50.f, 50.f, sf::Color::Red);
    Canon* oCanon = new Canon(&oWindow, sf::Color::Yellow);
    


    float fDeltaTime = 0;

    oLevel->Level1to5();
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
        /*oBall->Movement(fDeltaTime);
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
            oBall->IsMoving(false, vDirectionNull);*/
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



