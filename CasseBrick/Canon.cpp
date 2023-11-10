#include "Canon.h"
#include "GameObj.h"
#include "Ball.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Mouse.hpp>

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
void Canon::UpdateRot()
{
	sf::Vector2i vMousePos = sf::Mouse::getPosition(*_pWindow);

	sf::Vector2f vRefPoint;
	vRefPoint.y = vMousePos.y;
	vRefPoint.x = GetShape()->getPosition().x;

	sf::Vector2f vA;
	vA.x = vRefPoint.x - GetShape()->getPosition().x;
	vA.y = vRefPoint.y - GetShape()->getPosition().y;
	sf::Vector2f vH;
	vH.x = vMousePos.x - GetShape()->getPosition().x;
	vH.y = vMousePos.y - GetShape()->getPosition().y;

	iNormeA = 


}

std::vector<Ball*> Canon::GetBallList()
{
	return _vBallList;
}

void Canon::ShootBall()
{
	int iBallDiametre = 20;
	int iBallPosX = _iPosX + (_iWidth - iBallDiametre) / 2;
	int iBallPosY = _iPosY - iBallDiametre;
	Ball* oBall = new Ball(_pWindow, iBallDiametre, iBallPosX, iBallPosY, sf::Color::Green);

	_vBallList.push_back(oBall);

	sf::Vector2i vMousePos = sf::Mouse::getPosition(*_pWindow);
	sf::Vector2f vBallPos = oBall->GetCenterPoint();

	sf::Vector2f vDirection;
	vDirection.x = vMousePos.x - vBallPos.x;
	vDirection.y = vMousePos.y - vBallPos.y;

	float fNorme = sqrt((vDirection.x * vDirection.x) + (vDirection.y * vDirection.y));

	vDirection.x = vDirection.x / fNorme;
	vDirection.y = vDirection.y / fNorme;

	oBall->IsMoving(true, vDirection);
}