#include "GameObj.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


GameObj::GameObj(sf::RenderWindow* pWindow, float iDiametre, float iPosX, float iPosY, sf::Color cColor)
{
	_iWidth = iDiametre;
	_iHeight = iDiametre;
	_cColor = cColor;
	_bEnable = true;

	_pWindow = pWindow;
	_pShape = new sf::CircleShape(iDiametre);
	_pShape->setPosition(iPosX, iPosY);
	_pShape->setFillColor(_cColor);
};

GameObj::GameObj(sf::RenderWindow* pWindow, float iWidth, float iHeight, float iPosX, float iPosY, sf::Color cColor)
{
	_iWidth = iWidth;
	_iHeight = iHeight;
	_cColor = cColor;
	_bEnable = true;

	_pWindow = pWindow;
	_pShape = new sf::RectangleShape(sf::Vector2f(iWidth, iHeight));
	_pShape->setPosition(iPosX, iPosY);
	_pShape->setFillColor(_cColor);
};

sf::Vector2f GameObj::GetPosition()
{
	return _pShape->getPosition();
};

void GameObj::SetPostion(float iPosX, float iPosY)
{
	_pShape->setPosition(iPosX, iPosY);
}

float GameObj::GetRotation()
{
	return _pShape->getRotation();
};

void GameObj::SetRotation(float fAngle)
{
	_pShape->setRotation(fAngle);
}

sf::Vector2f GameObj::GetSize()
{
	return sf::Vector2f(_iWidth, _iHeight);
}

void GameObj::SetOrigine(float iPosX, float iPosY)
{
	_pShape->setOrigin(iPosX, iPosY);
}