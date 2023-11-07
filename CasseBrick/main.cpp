#include "GameObj.h"
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    GameObj* oBall = new GameObj(10.f, 10.f, 10.f, sf::Color::Green);
    GameObj* oRect = new GameObj(20.f, 40.f, 50.f, 50.f, sf::Color::Red);

    oBall->Draw(oBall->GetShape());
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



