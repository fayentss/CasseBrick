#include "Canon.h"
#include "GameObj.h"
#include "Ball.h"
#include <cmath>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Mouse.hpp>

Canon::Canon(sf::RenderWindow* pWindow, sf::Color cColor) : GameObj(pWindow, pWindow->getSize().x * 0.1, (pWindow->getSize().x * 0.1)*1.5, pWindow->getSize().x / 2, pWindow->getSize().y / 2, cColor)
{}

void Canon::UpdateRot()
{
	sf::Vector2i vMousePos = sf::Mouse::getPosition(*_pWindow);
	sf::Vector2f vCanonPoint = GetPosition();
	sf::Vector2f vRefPoint;
	vRefPoint.y = vCanonPoint.y;
	vRefPoint.x = vMousePos.x;

	float fA = vCanonPoint.x - vRefPoint.x;
	float fO = vMousePos.y - vRefPoint.y;

	float fAngle = (atan(fO / fA) * (180 / 3.1415));

	SetRotation(-fAngle - 90);
}

std::vector<Ball*> Canon::GetBallList()
{
	return _vBallList;
}

void Canon::ShootBall()
{
	float iBallDiametre = 20;
	float iBallPosX = GetPosition().x;
	float iBallPosY = GetPosition().y;
	Ball* oBall = new Ball(_pWindow, iBallDiametre, iBallPosX, iBallPosY, sf::Color::Green);

	_vBallList.push_back(oBall);

	sf::Vector2i vMousePos = sf::Mouse::getPosition(*_pWindow);
	sf::Vector2f vBallPos = oBall->GetPosition();

	sf::Vector2f vDirection;
	vDirection.x = vMousePos.x - vBallPos.x;
	vDirection.y = vMousePos.y - vBallPos.y;

	float fNorme = sqrt((vDirection.x * vDirection.x) + (vDirection.y * vDirection.y));

	vDirection.x = vDirection.x / fNorme;
	vDirection.y = vDirection.y / fNorme;

	oBall->IsMoving(true, vDirection);
}