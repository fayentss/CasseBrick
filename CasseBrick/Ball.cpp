#include "Ball.h"
#include "GameObj.h"
#include <iostream>
#include "Math.h"

Ball::Ball(sf::RenderWindow* pWindow, float iDiametre, float iPosX, float iPosY,sf::Color cColor) : GameObj(pWindow, iDiametre, iPosX, iPosY, cColor)
{
	_bIsMoving = false;
}

sf::Vector2f Ball::GetBallDirection()
{
	return _vDirection;
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
		fLastX = GetPosition().x;
		fLastY = GetPosition().y;
		float fNewX = GetPosition().x + (_vDirection.x * 350) * fDeltaTime;
		float fNewY = GetPosition().y + (_vDirection.y * 350) * fDeltaTime;
		SetPostion(fNewX, fNewY);
	}
}

void Ball::Bounce(const char* side)
{
	if (side == "Left" || side == "Right")
		_vDirection.x = -_vDirection.x;
	else if (side == "Top")
		_vDirection.y = -_vDirection.y;
}

void Ball::WindowCollider()
{
	sf::Vector2f fBallPos = GetPosition();
	sf::Vector2f fBallSize = GetSize();

	//Right Colision 
	if (fBallPos.x + fBallSize.x > _pWindow->getSize().x)
	{
		Bounce("Right");
	}
	//Left Colision 
	else if (fBallPos.x < 0)
	{
		Bounce("Left");
	}
	//Top Colision 
	else if (fBallPos.y < 0)
	{
		Bounce("Top");
	}
	//Bot Colision 
	else if (fBallPos.y < 0)
	{
		//delete;
	}
};



void Ball::BlocCollider(Brick* pBrick)
{
	bool GetMath = false;

	sf::Vector2f fBrickPos = pBrick->GetPosition();
	sf::Vector2f fBrickSize = pBrick->GetSize();
	sf::Vector2f fBallPos = GetPosition();
	sf::Vector2f fBallSize = GetSize();
	

	if (fBallSize.x < fBrickSize.x)
	{
		GetMath = Math::IsInside(fBallPos.x, fBrickPos.x, fBrickPos.x + fBrickSize.x);
		if (GetMath == false) 
			GetMath = Math::IsInside(fBallPos.x + fBallSize.x, fBrickPos.x, fBrickPos.x + fBrickSize.x);
	}
	else 
	{
		GetMath = Math::IsInside(fBrickPos.x, fBallPos.x, fBallPos.x + fBallSize.x);
		if (GetMath == false)
			GetMath = Math::IsInside(fBrickPos.x + fBrickSize.x, fBallPos.x, fBallPos.x + fBallSize.x);
	}

	if (GetMath == false) {
		return;
	}
	else
	{
		if (fBallSize.y < fBrickSize.y) {
			GetMath = Math::IsInside(fBallPos.y, fBrickPos.y, fBrickPos.y + fBrickSize.y);
			if (GetMath == false)
				GetMath = Math::IsInside(fBallPos.y + fBallSize.y, fBrickPos.y, fBrickPos.y + fBrickSize.y);

		}
		else
		{
			GetMath = Math::IsInside(fBrickPos.y, fBallPos.y, fBallPos.y + fBallSize.y);
			if (GetMath == false)
				GetMath = Math::IsInside(fBrickPos.y + fBrickSize.y, fBallPos.y, fBallPos.y + fBallSize.y);
		}
	}

	if (GetMath == true)
	{
		float m;
		float b;
		m = (fBallPos.y - fLastY) / (fBallPos.x - fLastX);

	}
}
