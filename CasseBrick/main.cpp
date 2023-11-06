#include "GameObj.h"
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    GameObj* oBall = new GameObj(10.f, 10.f, 10.f, sf::Color::Green);

    

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

        oWindow.draw(oBall);
        oWindow.draw(oRectangle);

        oWindow.display();
    }

    return 0;

}



