#include "GameObj.h"
#include "GameObjManager.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


GameObj::GameObj(sf::RenderWindow* pWindow, GameObjManager* pObjManager, float fDiametre, float fPosX, float fPosY, sf::Color cColor)
{
	_fWidth = fDiametre;
	_fHeight = fDiametre;

	_pWindow = pWindow;
	_pObjManager = pObjManager;
	_pShape = new sf::CircleShape(fDiametre);
	_pShape->setPosition(fPosX, fPosY);
	_pShape->setFillColor(cColor);
};

GameObj::GameObj(sf::RenderWindow* pWindow, GameObjManager* pObjManager, float fWidth, float fHeight, float fPosX, float fPosY, sf::Color cColor)
{
	_fWidth = fWidth;
	_fHeight = fHeight;

	_pWindow = pWindow;
	_pObjManager = pObjManager;
	_pShape = new sf::RectangleShape(sf::Vector2f(fWidth, fHeight));
	_pShape->setPosition(fPosX, fPosY);
	_pShape->setFillColor(cColor);
};


GameObj::~GameObj()
{
	int a = 0;
}

sf::Vector2f GameObj::GetPosition()
{
	return _pShape->getPosition();
};

void GameObj::SetPostion(float fPosX, float fPosY)
{
	_pShape->setPosition(fPosX, fPosY);
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
	return sf::Vector2f(_fWidth, _fHeight);
}

void GameObj::SetOrigine(float fPosX, float fPosY)
{
	_pShape->setOrigin(fPosX, fPosY);
}

void GameObj::SetColor(sf::Color cColor)
{
	_pShape->setFillColor(cColor);
}