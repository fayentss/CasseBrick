#include "GameObjManager.h"
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
    sf::RenderWindow oWindow(sf::VideoMode(1920, 1080), "SFML");
    GameObjManager* ObjManager = new GameObjManager();
    LevelCreator* oLevel = new LevelCreator(&oWindow, ObjManager);
    Canon* oCanon = new Canon(&oWindow, ObjManager, sf::Color::Yellow);
    oLevel->Level1();

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
        const std::vector<Ball*>& oBalls = oCanon->GetBallList();
        for (int i = 0; i < oBalls.size(); i++)
        {
            Ball* pBall = oBalls[i];
            pBall->Movement(fDeltaTime);
            pBall->WindowCollider();

            const std::vector<Brick*>& oBricks = oLevel->GetBrick();
            for (int j = 0; j < oBricks.size(); j++) 
            {
                Brick* pBrick = oBricks[j];
                pBall->BlocCollider(pBrick);
            }
        }

        //Check to destroy
        const std::vector<GameObj*>& vObjToDelete = ObjManager->GetObjToDelete();
        for (int i = 0; i < vObjToDelete.size(); i++)
        {
            GameObj* pToDelete = vObjToDelete[i];
            ObjManager->DeleteObjToDelete(pToDelete);
            delete pToDelete;
        }

        //DRAW
        oWindow.clear();

        std::vector<int*> test;
        int blabla = 3;
        test.push_back(&blabla);
        test.erase(std::remove(test.begin(), test.end(), &blabla), test.end());
        int n = test.size();

        for (int i = 0; i < oLevel->GetBrick().size(); i++)
        {
            oLevel->GetBrick()[i]->Draw();
        }
        
        oCanon->Draw();
        
        for (int i = 0; i < oCanon->GetBallList().size(); i++)
        {
            oCanon->GetBallList()[i]->Draw();
        }

        oWindow.display();

        fDeltaTime = oClock.restart().asSeconds();

        //WinCheck
        if (oLevel->GetBrick().size() == 0)
        {
            std::cout << "You Win" << std::endl;
            oWindow.close();
        }
    }

    return 0;

}



