#include "Ball.h"
#include "GameObj.h"
#include <iostream>;

Ball::Ball(int iDiametre, int iPosX, int iPosY, sf::Color cColor) : GameObj(iDiametre, iPosX, iPosY, cColor)
{
	// pos initial
	//
}
void Ball::Collider(sf::RenderWindow oWindow, int iPosX, int iPosY)
{
	if ( iPosX > oWindow.getSize().x )
	{
		std::cout << "colide a droit connard";
	}
	else if (iPosX < 0)
	{
		std::cout << "colide a gauche connard";
	}

	if (iPosY > oWindow.getSize().y)
	{
		std::cout << "colide en haut connard";
	}
	else if (iPosY < 0)
	{
		std::cout << "colide en bas connard";
	}

	if (iPosX < 0 && iPosY < 0) 
	{
		std::cout << "colide coin en bas a gauche connard";
	}
	else if (iPosX < oWindow.getSize().x && iPosY < oWindow.getSize().y) 
	{
		std::cout << "colide coin en haut a droit connard";
	}
	else if (iPosX < 0 && iPosY < oWindow.getSize().y)
	{
		std::cout << "colide coin en haut a gauche connard";
	}
	else if (iPosX < 0 && iPosY < 0) 
	{

	}
};