#include "Ball.h"
#include "GameObj.h"
#include <iostream>
#include "Math.h"

Ball::Ball(sf::RenderWindow* pWindow, float iDiametre, float iPosX, float iPosY,sf::Color cColor) : GameObj(pWindow, iDiametre, iPosX, iPosY, cColor)
{
	_bIsMoving = false;
}

sf::Vector2f Ball::GetBallPosition()
{
	return GetPosition();
}

void Ball::IsMoving(bool bIsMoving,sf::Vector2f vDirection)
{
	_bIsMoving = bIsMoving;
	_vDirection = vDirection;
}

void Ball::Movement(float fDeltaTime)
{
	if (_bIsMoving == true)
	{
		float fNewX = GetPosition().x + (_vDirection.x * 200) * fDeltaTime;
		float fNewY = GetPosition().y + (_vDirection.y * 200) * fDeltaTime;
		SetPostion(fNewX, fNewY);
	}
}

bool Ball::WindowCollider()
{
	if ( GetPosition().x + _iWidth > _pWindow->getSize().x)
	{
		std::cout << "colide a droit connard";
		return true;
	}
	else if (GetPosition().x < 0)
	{
		std::cout << "colide a gauche connard";
		return true;
	}


	if (GetPosition().y + _iHeight > _pWindow->getSize().y)
	{
		std::cout << "colide en haut connard";
		return true;
	}
	else if (GetPosition().y < 0)
	{
		std::cout << "colide en bas connard";
		return true;
	}
	return false;
};

bool Ball::BlocCollider(Brick* pBrick)
{
	std::vector<float> vAllPos = pBrick->GetAllPos();
	bool GetMath = false;
	if (_iWidth  < vAllPos[2] - vAllPos[0]) {
		GetMath = Math::IsInside(GetPosition().x, vAllPos[0], vAllPos[2]);
		if (GetMath == false) {
			GetMath = Math::IsInside(GetPosition().x + _iWidth, vAllPos[0], vAllPos[2]);
		}
	}
	else 
	{
		GetMath = Math::IsInside(vAllPos[0], GetPosition().x, GetPosition().x + _iWidth);
		if (GetMath == false) {
			GetMath = Math::IsInside(vAllPos[2], GetPosition().x, GetPosition().x + _iWidth);
		}
	}

	if (GetMath == false) {
		return false;
	}
	else
	{
		if (_iHeight < vAllPos[3] - vAllPos[1]) {
			GetMath = Math::IsInside(GetPosition().y, vAllPos[1], vAllPos[3]);
			if (GetMath == false) {
				GetMath = Math::IsInside(GetPosition().y + _iHeight, vAllPos[1], vAllPos[3]);
			}
		}
		else
		{
			GetMath = Math::IsInside(vAllPos[1], GetPosition().y, GetPosition().y + _iHeight);
			if (GetMath == false) {
				GetMath = Math::IsInside(vAllPos[3], GetPosition().y, GetPosition().y + _iHeight);
			}
		}
	}

	if (GetMath == false) {
		return false;
	}
	else
	{
		std::cout << "colide brick connard";
		return true;
	}
}
