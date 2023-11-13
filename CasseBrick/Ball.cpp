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
		_iPosX = fNewX;
		_iPosY = fNewY;
		GetShape()->setPosition(fNewX,fNewY);
	}
}

bool Ball::WindowCollider()
{
	if ( _iPosX + _iWidth > _pWindow->getSize().x )
	{
		//std::cout << "colide a droit connard";
		return true;
	}
	else if (_iPosX < 0)
	{
		//std::cout << "colide a gauche connard";
		return true;
	}


	if (_iPosY + _iHeight > _pWindow->getSize().y)
	{
		//std::cout << "colide en haut connard";
		return true;
	}
	else if (_iPosY < 0)
	{
		//std::cout << "colide en bas connard";
		return true;
	}
	return false;
};

bool Ball::BlocCollider(Brick* pBrick)
{
	std::vector<int> vAllPos = pBrick->GetAllPos();
	bool GetMath = false;
	if (_iWidth  < vAllPos[2] - vAllPos[0]) {
		GetMath = Math::IsInside(_iPosX, vAllPos[0], vAllPos[2]);
		//std::cout << "all pos"<< _iPosX <<"     "<< vAllPos[0] <<"        "<< vAllPos[2];
		if (GetMath == false) {
			GetMath = Math::IsInside(_iPosX + _iWidth, vAllPos[0], vAllPos[2]);
			//std::cout << "yo1";
		}
	}
	else 
	{
		GetMath = Math::IsInside(vAllPos[0], _iPosX, _iPosX + _iWidth);
		if (GetMath == false) {
			GetMath = Math::IsInside(vAllPos[2], _iPosX, _iPosX + _iWidth);
			//std::cout << "yo2";
		}
	}

	if (GetMath == false) {
		//std::cout << "yo3";
		return false;
		
	}
	else
	{
		if (_iHeight < vAllPos[3] - vAllPos[1]) {
			GetMath = Math::IsInside(_iPosY, vAllPos[1], vAllPos[3]);
			if (GetMath == false) {
				GetMath = Math::IsInside(_iPosY + _iHeight, vAllPos[1], vAllPos[3]);
				//std::cout << "yo4";
			}
		}
		else
		{
			GetMath = Math::IsInside(vAllPos[1], _iPosY, _iPosY + _iHeight);
			if (GetMath == false) {
				GetMath = Math::IsInside(vAllPos[3], _iPosY, _iPosY + _iHeight);
				//std::cout << "yo5";
			}
		}
	}

	if (GetMath == false) {
		//std::cout << "yo6";
		return false;
	}
	else
	{
		//std::cout << "colide brick connard";
		return true;
	}
}
