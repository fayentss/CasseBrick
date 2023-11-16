#include "Canon.h"
#include "GameObj.h"
#include "Ball.h"
#include <cmath>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Mouse.hpp>

Canon::Canon(sf::RenderWindow* pWindow, GameObjManager* pObjManager, sf::Color cColor) : GameObj(pWindow, pObjManager, pWindow->getSize().x * 0.05, (pWindow->getSize().x * 0.1)*1.1, pWindow->getSize().x / 2, pWindow->getSize().y - pWindow->getSize().y * 0.1, cColor)
{
	SetOrigine(GetSize().x / 2, GetSize().y * (3 / 4));
	_oClock.restart();
}

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

	if (vMousePos.y < vCanonPoint.y - (0.4 * GetSize().y))
	{
		if (vMousePos.x <= vCanonPoint.x)
			SetRotation(-fAngle - 270);
		else
			SetRotation(-fAngle - 90);
	}
}

const std::vector<Ball*>& Canon::GetBallList() const
{
	return _vBallList;
}
void Canon::DeleteBall(Ball* pBall)
{
	_vBallList.erase(std::remove(_vBallList.begin(), _vBallList.end(), pBall), _vBallList.end());
}

void Canon::ShootBall()
{
	if (_oClock.getElapsedTime().asSeconds() >= 1)
	{
		float fBallDiametre = 20;

		sf::Vector2i vMousePos = sf::Mouse::getPosition(*_pWindow);
		sf::Vector2f vCanonPos = GetPosition();

		if (vMousePos.y > GetPosition().y - (0.4 * GetSize().y))
			return;

		sf::Vector2f vDirection;
		vDirection.x = vMousePos.x - vCanonPos.x;
		vDirection.y = vMousePos.y - vCanonPos.y;

		float fNorme = sqrt((vDirection.x * vDirection.x) + (vDirection.y * vDirection.y));

		vDirection.x = vDirection.x / fNorme;
		vDirection.y = vDirection.y / fNorme;

		sf::Vector2f vBallPos;
		vBallPos.x = GetPosition().x - fBallDiametre + (vDirection.x * (GetSize().y * 0.9));
		vBallPos.y = GetPosition().y + (vDirection.y * (GetSize().y * 0.9));

		Ball* oBall = new Ball(_pWindow, _pObjManager, fBallDiametre, vBallPos.x, vBallPos.y, this);
		_vBallList.push_back(oBall);
		oBall->IsMoving(true, vDirection);

		_oClock.restart();
	}
	
}