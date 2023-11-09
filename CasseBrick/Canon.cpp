#include "Canon.h"
#include "GameObj.h"
#include "Ball.h"
#include <SFML/Graphics/RectangleShape.hpp>

Canon::Canon(sf::RenderWindow* pWindow, sf::Color cColor) : GameObj(pWindow, 0, 0, 0, 0, cColor)
{
	int iWidth = pWindow->getSize().x * 0.1;
	int iHeight = iWidth * 1.5;
	int iPosX = (pWindow->getSize().x / 2) - (iWidth / 2);
	int iPosY = pWindow->getSize().y - (iHeight * 1.5);

	_iPosX = iPosX;
	_iPosY = iPosY;
	_iWidth = iWidth;
	_iHeight = iHeight;
	
	_pShape = new sf::RectangleShape(sf::Vector2f(iWidth, iHeight));
	_pShape->setPosition(iPosX,iPosY);
	_pShape->setFillColor(cColor);
}

void Canon::SpawnBallWithDirection()
{
	int iBallDiametre = 20.f;
	int iBallPosX = _iPosX + (_iWidth - iBallDiametre) / 2;
	int iBallPosY = _iPosY - iBallDiametre - 10;
	Ball* oBall = new Ball(_pWindow, iBallDiametre, iBallPosX, iBallPosY, sf::Color::Green);


}