#include "Ball.h"
#include "GameObj.h"
#include <iostream>
#include "Math.h"
#include "Canon.h"
#include "GameObjManager.h"

Ball::Ball(sf::RenderWindow* pWindow, GameObjManager* pObjManager, float fDiametre, float fPosX, float fPosY, Canon* pCanon) : GameObj(pWindow, pObjManager, fDiametre, fPosX, fPosY, sf::Color::White)
{
	_bIsMoving = false;
	_pCanon = pCanon;
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
		_vLastPos = GetPosition();
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

char Ball::FaceDetection(Brick* pBrick)
{
	Math::Square_Points PreviousPos;

	PreviousPos.vTopLeft = _vLastPos;

	PreviousPos.vTopRight.x = _vLastPos.x + GetSize().x;
	PreviousPos.vTopRight.y = _vLastPos.y;

	PreviousPos.vBotLeft.x = _vLastPos.x;
	PreviousPos.vBotLeft.y = _vLastPos.y + GetSize().y;

	PreviousPos.vBotRight.x = _vLastPos.x + GetSize().x;
	PreviousPos.vBotRight.y = _vLastPos.y + GetSize().y;


	Math::Square_Points NextPos;

	NextPos.vTopLeft = GetPosition();

	NextPos.vTopRight.x = GetPosition().x + GetSize().x;
	NextPos.vTopRight.y = GetPosition().y;

	NextPos.vBotLeft.x = GetPosition().x;
	NextPos.vBotLeft.y = GetPosition().y + GetSize().y;

	NextPos.vBotRight.x = GetPosition().x + GetSize().x;
	NextPos.vBotRight.y = GetPosition().y + GetSize().y;

	float Coeff = Math::FindCoeff(PreviousPos.vTopLeft, NextPos.vTopLeft);
	float CoeffInvers = Math::FindCoeffInvers(PreviousPos.vTopLeft, NextPos.vTopLeft);

	sf::Vector2f vTmp = Math::GetInterPoint(NextPos.vTopLeft,pBrick,"Top",Coeff);
	if (Math::InterPointExist(vTmp,pBrick,"Top"))
	{

	}


}

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
		pBrick->TakeDamage(1);
		_pObjManager->AddObjToDelete(this);
		FaceDetection(pBrick);
	}
}

Ball::~Ball()
{
	_pCanon->DeleteBall(this);
}
