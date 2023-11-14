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
        for (int i = 0; i < oCanon->GetBallList().size(); i++) 
        {
            oCanon->GetBallList()[i]->Movement(fDeltaTime);
            if (oCanon->GetBallList()[i]->WindowCollider() == true)
            {
                sf::Vector2f vDirectionNull;
                vDirectionNull.x = 0;
                vDirectionNull.y = 0;
                oCanon->GetBallList()[i]->IsMoving(false, vDirectionNull);
            }
            for (int j = 0; j < oLevel->GetvBrick().size(); j++) 
            {
                if (oCanon->GetBallList()[i]->BlocCollider(oLevel->GetvBrick()[j]) == true)
                {
                    sf::Vector2f vDirectionNull;
                    vDirectionNull.x = 0;
                    vDirectionNull.y = 0;
                    oCanon->GetBallList()[i]->IsMoving(false, vDirectionNull);
                }
            }
            oCanon->GetBallList()[i]->Movement(fDeltaTime);
        }
        //DRAW
        oWindow.clear();
        for (int j = 0; j < oLevel->GetvBrick().size(); j++)
        {
            oLevel->GetvBrick()[j]->Draw();
        }
        
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



