#include "Ball.h"
#include "GameObj.h"
#include <iostream>
#include "Math.h"

Ball::Ball(sf::RenderWindow* pWindow, int iDiametre, sf::Color cColor) : GameObj(pWindow, iDiametre, 310, 230, cColor)
{
	_bIsMoving = false;
}

sf::Vector2f Ball::GetBallPosition()
{
	return _pShape->getPosition();
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
		float fNewX = GetShape()->getPosition().x + (_vDirection.x * 200) * fDeltaTime;
		float fNewY = GetShape()->getPosition().y + (_vDirection.y * 200) * fDeltaTime;
		GetShape()->setPosition(fNewX,fNewY);
	}
}

bool Ball::WindowCollider()
{
	if ( _iPosX + _iWidth > _pWindow->getSize().x )
	{
		std::cout << "colide a droit connard";
		return true;
	}
	else if (_iPosX < 0)
	{
		std::cout << "colide a gauche connard";
		return true;
	}


	if (_iPosY + _iHeight > _pWindow->getSize().y)
	{
		std::cout << "colide en haut connard";
		return true;
	}
	else if (_iPosY < 0)
	{
		std::cout << "colide en bas connard";
		return true;
	}
	return false;
};

bool Ball::BlocCollider(Brick* pBrick)
{
	bool GetMath = false;
	if (_iWidth  < pBrick->GetAllPos()[2] - pBrick->GetAllPos()[0]) {
		GetMath = Math::IsInside(_iPosX, pBrick->GetAllPos()[0], pBrick->GetAllPos()[2]);
		if (GetMath == false) {
			GetMath = Math::IsInside(_iPosX + _iWidth, pBrick->GetAllPos()[0], pBrick->GetAllPos()[2]);
		}
	}
	else 
	{
		GetMath = Math::IsInside(pBrick->GetAllPos()[0], _iPosX, _iPosX + _iWidth);
		if (GetMath == false) {
			GetMath = Math::IsInside(pBrick->GetAllPos()[2], _iPosX, _iPosX + _iWidth);
		}
	}

	if (GetMath == false) {
		std::cout << "PAS de colide brick connard";
		return false;
	}
	else
	{
		if (_iHeight < pBrick->GetAllPos()[3] - pBrick->GetAllPos()[1]) {
			GetMath = Math::IsInside(_iPosY, pBrick->GetAllPos()[1], pBrick->GetAllPos()[3]);
			if (GetMath == false) {
				GetMath = Math::IsInside(_iPosY + _iHeight, pBrick->GetAllPos()[1], pBrick->GetAllPos()[3]);
			}
		}
		else
		{
			GetMath = Math::IsInside(pBrick->GetAllPos()[1], _iPosY, _iPosY + _iHeight);
			if (GetMath == false) {
				GetMath = Math::IsInside(pBrick->GetAllPos()[3], _iPosY, _iPosY + _iHeight);
			}
		}
	}

	if (GetMath == false) {
		std::cout << "PAS de colide brick connard";
		return false;
	}
	else
	{
		std::cout << "colide brick connard";
		return true;
	}
}
