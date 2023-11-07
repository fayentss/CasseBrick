#include "GameObj.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


GameObj::GameObj(int iDiametre, int iPosX, int iPosY, sf::Color cColor)
{
	_iPosX = iPosX;
	_iPosY = iPosY;
	_iWidth = iDiametre;
	_iHeight = iDiametre;
	_cColor = cColor;

	_oShape = new sf::CircleShape(iDiametre);
};

GameObj::GameObj(int iWidth, int iHeight, int iPosX, int iPosY, sf::Color cColor)
{
	_iPosX = iPosX;
	_iPosY = iPosY;
	_iWidth = iWidth;
	_iHeight = iHeight;
	_cColor = cColor;

	_oShape = new sf::RectangleShape(sf::Vector2f(iWidth, iHeight));
};

void GameObj::Draw(sf::Shape* oShape)
{
	oShape->setPosition(_iPosX, _iPosY);
	oShape->setFillColor(_cColor);
};

sf::Shape* GameObj::GetShape()
{
	return _oShape;
};

