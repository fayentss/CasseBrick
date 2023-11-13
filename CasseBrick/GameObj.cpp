#include "GameObj.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


GameObj::GameObj(sf::RenderWindow* pWindow, int iDiametre, int iPosX, int iPosY, sf::Color cColor)
{
	_iPosX = iPosX;
	_iPosY = iPosY;
	_iWidth = iDiametre;
	_iHeight = iDiametre;
	_cColor = cColor;
	_bEnable = true;

	_pWindow = pWindow;
	_pShape = new sf::CircleShape(iDiametre);
	_pShape->setPosition(_iPosX, _iPosY);
	_pShape->setFillColor(_cColor);
};

GameObj::GameObj(sf::RenderWindow* pWindow, int iWidth, int iHeight, int iPosX, int iPosY, sf::Color cColor)
{
	_iPosX = iPosX;
	_iPosY = iPosY;
	_iWidth = iWidth;
	_iHeight = iHeight;
	_cColor = cColor;
	_bEnable = true;

	_pWindow = pWindow;
	_pShape = new sf::RectangleShape(sf::Vector2f(iWidth, iHeight));
	_pShape->setPosition(_iPosX, _iPosY);
	_pShape->setFillColor(_cColor);
};

sf::Vector2f GameObj::GetCenterPoint()
{
	sf::Vector2f vPos = _pShape->getPosition();
	vPos.x = vPos.x + _iWidth / 2;
	vPos.y = vPos.y + _iHeight / 2;

	return vPos;
}

sf::Shape* GameObj::GetShape()
{
	return _pShape;
};
sf::Shape* GameObj::SetShape(int x,int y)
{
	_pShape->setPosition(x, y);
	return _pShape;
};

