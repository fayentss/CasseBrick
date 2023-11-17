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

void Ball::FaceDetection(Brick* pBrick)
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

	std::vector<Math::Point_Info> vValidePoint;

	///TopLeft
	sf::Vector2f vTmp = Math::GetInterPoint(PreviousPos.vTopLeft, NextPos.vTopLeft,pBrick,"Top",Coeff);
	if (Math::InterPointExist(vTmp,pBrick,"Top") == true)
	{
		Math::Point_Info TopLeftColTop;
		TopLeftColTop.fCoeff = Coeff;
		TopLeftColTop.cSideTouch = "Top";
		TopLeftColTop.vCoordPoint = vTmp;
		TopLeftColTop.Norme = Math::FindNorme( PreviousPos.vTopLeft, vTmp);
		vValidePoint.push_back(TopLeftColTop);
	}

	vTmp = Math::GetInterPoint(PreviousPos.vTopLeft, NextPos.vTopLeft, pBrick, "Bot", Coeff);
	if (Math::InterPointExist(vTmp, pBrick, "Bot") == true)
	{
		Math::Point_Info TopLeftColBot;
		TopLeftColBot.fCoeff = Coeff;
		TopLeftColBot.cSideTouch = "Bot";
		TopLeftColBot.vCoordPoint = vTmp;
		TopLeftColBot.Norme = Math::FindNorme(PreviousPos.vTopLeft, vTmp);
		vValidePoint.push_back(TopLeftColBot);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vTopLeft, NextPos.vTopLeft, pBrick, "Left", CoeffInvers);
	if (Math::InterPointExist(vTmp, pBrick, "Left") == true)
	{
		Math::Point_Info TopLeftColLeft;
		TopLeftColLeft.fCoeff = CoeffInvers;
		TopLeftColLeft.cSideTouch = "Left";
		TopLeftColLeft.vCoordPoint = vTmp;
		TopLeftColLeft.Norme = Math::FindNorme(PreviousPos.vTopLeft, vTmp);
		vValidePoint.push_back(TopLeftColLeft);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vTopLeft, NextPos.vTopLeft, pBrick, "Right", CoeffInvers);
	if (Math::InterPointExist(vTmp, pBrick, "Right") == true)
	{
		Math::Point_Info TopLeftColRight;
		TopLeftColRight.fCoeff = CoeffInvers;
		TopLeftColRight.cSideTouch = "Right";
		TopLeftColRight.vCoordPoint = vTmp;
		TopLeftColRight.Norme = Math::FindNorme(PreviousPos.vTopLeft, vTmp);
		vValidePoint.push_back(TopLeftColRight);
	}


	//TopRight
	vTmp = Math::GetInterPoint(PreviousPos.vTopRight, NextPos.vTopRight, pBrick, "Top", Coeff);
	if (Math::InterPointExist(vTmp, pBrick, "Top") == true)
	{
		Math::Point_Info TopRightColTop;
		TopRightColTop.fCoeff = Coeff;
		TopRightColTop.cSideTouch = "Top";
		TopRightColTop.vCoordPoint = vTmp;
		TopRightColTop.Norme = Math::FindNorme(PreviousPos.vTopRight, vTmp);
		vValidePoint.push_back(TopRightColTop);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vTopRight, NextPos.vTopRight, pBrick, "Bot", Coeff);
	if (Math::InterPointExist(vTmp, pBrick, "Bot") == true)
	{
		Math::Point_Info TopRightColBot;
		TopRightColBot.fCoeff = Coeff;
		TopRightColBot.cSideTouch = "Bot";
		TopRightColBot.vCoordPoint = vTmp;
		TopRightColBot.Norme = Math::FindNorme(PreviousPos.vTopRight, vTmp);
		vValidePoint.push_back(TopRightColBot);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vTopRight, NextPos.vTopRight, pBrick, "Left", CoeffInvers);
	if (Math::InterPointExist(vTmp, pBrick, "Left") == true)
	{
		Math::Point_Info TopRightColLeft;
		TopRightColLeft.fCoeff = CoeffInvers;
		TopRightColLeft.cSideTouch = "Left";
		TopRightColLeft.vCoordPoint = vTmp;
		TopRightColLeft.Norme = Math::FindNorme(PreviousPos.vTopRight, vTmp);
		vValidePoint.push_back(TopRightColLeft);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vTopRight, NextPos.vTopRight, pBrick, "Right", CoeffInvers);
	if (Math::InterPointExist(vTmp, pBrick, "Right") == true)
	{
		Math::Point_Info TopRightColRight;
		TopRightColRight.fCoeff = CoeffInvers;
		TopRightColRight.cSideTouch = "Right";
		TopRightColRight.vCoordPoint = vTmp;
		TopRightColRight.Norme = Math::FindNorme(PreviousPos.vTopRight, vTmp);
		vValidePoint.push_back(TopRightColRight);
	}

	////BotLeft
	vTmp = Math::GetInterPoint(PreviousPos.vBotLeft, NextPos.vBotLeft, pBrick, "Top", Coeff);
	if (Math::InterPointExist(vTmp, pBrick, "Top") == true)
	{
		Math::Point_Info BotLeftColTop;
		BotLeftColTop.fCoeff = Coeff;
		BotLeftColTop.cSideTouch = "Top";
		BotLeftColTop.vCoordPoint = vTmp;
		BotLeftColTop.Norme = Math::FindNorme(PreviousPos.vBotLeft, vTmp);
		vValidePoint.push_back(BotLeftColTop);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vBotLeft, NextPos.vBotLeft, pBrick, "Bot", Coeff);
	if (Math::InterPointExist(vTmp, pBrick, "Bot") == true)
	{
		Math::Point_Info BotLeftColBot;
		BotLeftColBot.fCoeff = Coeff;
		BotLeftColBot.cSideTouch = "Bot";
		BotLeftColBot.vCoordPoint = vTmp;
		BotLeftColBot.Norme = Math::FindNorme(PreviousPos.vBotLeft, vTmp);
		vValidePoint.push_back(BotLeftColBot);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vBotLeft, NextPos.vBotLeft, pBrick, "Left", CoeffInvers);
	if (Math::InterPointExist(vTmp, pBrick, "Left") == true)
	{
		Math::Point_Info BotLeftColLeft;
		BotLeftColLeft.fCoeff = CoeffInvers;
		BotLeftColLeft.cSideTouch = "Left";
		BotLeftColLeft.vCoordPoint = vTmp;
		BotLeftColLeft.Norme = Math::FindNorme(PreviousPos.vBotLeft, vTmp);
		vValidePoint.push_back(BotLeftColLeft);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vBotLeft, NextPos.vBotLeft, pBrick, "Right", CoeffInvers);
	if (Math::InterPointExist(vTmp, pBrick, "Right") == true)
	{
		Math::Point_Info BotLeftColRight;
		BotLeftColRight.fCoeff = CoeffInvers;
		BotLeftColRight.cSideTouch = "Right";
		BotLeftColRight.vCoordPoint = vTmp;
		BotLeftColRight.Norme = Math::FindNorme(PreviousPos.vBotLeft, vTmp);
		vValidePoint.push_back(BotLeftColRight);
	}

	//BotRight
	vTmp = Math::GetInterPoint(PreviousPos.vBotRight, NextPos.vBotRight, pBrick, "Top", Coeff);
	if (Math::InterPointExist(vTmp, pBrick, "Top") == true)
	{
		Math::Point_Info BotRightColTop;
		BotRightColTop.fCoeff = Coeff;
		BotRightColTop.cSideTouch = "Top";
		BotRightColTop.vCoordPoint = vTmp;
		BotRightColTop.Norme = Math::FindNorme(PreviousPos.vBotRight, vTmp);
		vValidePoint.push_back(BotRightColTop);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vBotRight, NextPos.vBotRight, pBrick, "Bot", Coeff);
	if (Math::InterPointExist(vTmp, pBrick, "Bot") == true)
	{
		Math::Point_Info BotRightColBot;
		BotRightColBot.fCoeff = Coeff;
		BotRightColBot.cSideTouch = "Bot";
		BotRightColBot.vCoordPoint = vTmp;
		BotRightColBot.Norme = Math::FindNorme(PreviousPos.vBotRight, vTmp);
		vValidePoint.push_back(BotRightColBot);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vBotRight, NextPos.vBotRight, pBrick, "Left", CoeffInvers);
	if (Math::InterPointExist(vTmp, pBrick, "Left") == true)
	{
		Math::Point_Info BotRightColLeft;
		BotRightColLeft.fCoeff = CoeffInvers;
		BotRightColLeft.cSideTouch = "Left";
		BotRightColLeft.vCoordPoint = vTmp;
		BotRightColLeft.Norme = Math::FindNorme(PreviousPos.vBotRight, vTmp);
		vValidePoint.push_back(BotRightColLeft);
	}
	vTmp = Math::GetInterPoint(PreviousPos.vBotRight, NextPos.vBotRight, pBrick, "Right", CoeffInvers);
	if (Math::InterPointExist(vTmp, pBrick, "Right") == true)
	{
		Math::Point_Info BotRightColRight;
		BotRightColRight.fCoeff = CoeffInvers;
		BotRightColRight.cSideTouch = "Right";
		BotRightColRight.vCoordPoint = vTmp;
		BotRightColRight.Norme = Math::FindNorme(PreviousPos.vBotRight, vTmp);
		vValidePoint.push_back(BotRightColRight);
	}

	if (vValidePoint.size() > 1)
	{
		Math::Point_Info* ShorterNorme = &vValidePoint[0];
		for (int i = 0; i < vValidePoint.size(); i++)
		{
			if (vValidePoint[i].Norme < ShorterNorme->Norme)
			{
				ShorterNorme = &vValidePoint[i];
			}
		}

		if (ShorterNorme->cSideTouch == "Top")
		{
			Bounce("Bot");
		}
		else if (ShorterNorme->cSideTouch == "Bot")
		{
			Bounce("Top");
		}
		else if (ShorterNorme->cSideTouch == "Left")
		{
			Bounce("Right");
		}
		else if (ShorterNorme->cSideTouch == "Right")
		{
			Bounce("Left");
		}
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
		FaceDetection(pBrick);
	}
}

Ball::~Ball()
{
	_pCanon->DeleteBall(this);
}
