#include "Ball.h"
#include "GameObj.h"
#include <iostream>
#include "Math.h"

struct Point 
{
	float x;
	float y;
};

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
		_vLastPos.x = GetPosition().x;
		_vLastPos.y = GetPosition().y;
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
		//by the way, quand tu regardera comment fonctionne les fonction car je sais que tu vas look petit chenipan, PointA doit être forçément _vLastPos et point B doit être forcément la pos actuelle (celle qui a colide)
		//car je sais tu vas pleurait, dans les nom de variable, H c'est en haut, D a droite, G a gauche, B en bas, donc si tu connecte tout les neurone enssemble HG sa fait ? et oui en haut a gauche hihi aled
		sf::Vector2f XY;
		struct StructCourbe
		{
			sf::Vector2f LastXY;
			float m;
			float b;
		};
		struct StructCourbeBrick
		{
			sf::Vector2f PointUn;
			sf::Vector2f PointDeux;
			float m;
			float b;
		};
		struct StructBrick
		{
			StructCourbeBrick PointAB;
			StructCourbeBrick PointAC;
			StructCourbeBrick PointBD;
			StructCourbeBrick PointDC;	
		};
		StructCourbe HGBall;
		StructCourbe HDBall;
		StructCourbe BGBall;
		StructCourbe BDBall;
		HGBall.m = Math::CoefM(_vLastPos, fBallPos);
		HGBall.b = Math::OrigineB(_vLastPos, HGBall.m);

		HDBall.LastXY.x = _vLastPos.x + fBallSize.x;
		HDBall.LastXY.y = _vLastPos.y;
		XY.x = fBallPos.x + fBallSize.x;
		XY.y = fBallPos.y;
		HDBall.m = Math::CoefM(HDBall.LastXY, XY);
		HDBall.b = Math::OrigineB(HDBall.LastXY, HDBall.m);

		BGBall.LastXY.x = _vLastPos.x;
		BGBall.LastXY.y = _vLastPos.y + fBallSize.y;
		XY.x = fBallPos.x;
		XY.y = fBallPos.y + fBallSize.y;
		BGBall.m = Math::CoefM(BGBall.LastXY, XY);
		BGBall.b = Math::OrigineB(BGBall.LastXY, BGBall.m);

		BDBall.LastXY.x = _vLastPos.x + fBallSize.x;
		BDBall.LastXY.y = _vLastPos.y + fBallSize.y;
		XY.x = fBallPos.x + fBallSize.x;
		XY.y = fBallPos.y + fBallSize.y;
		BDBall.m = Math::CoefM(BDBall.LastXY, XY);
		BDBall.b = Math::OrigineB(BDBall.LastXY, BDBall.m);

		StructBrick Brick;
		Brick.PointAB.PointUn = fBrickPos;
		Brick.PointAB.PointDeux.x = fBrickPos.x + fBrickSize.x;
		Brick.PointAB.PointDeux.y = fBrickPos.y;
		Brick.PointAB.m = Math::CoefM(Brick.PointAB.PointUn, Brick.PointAB.PointDeux);
		Brick.PointAB.b = Math::OrigineB(Brick.PointAB.PointUn, Brick.PointAB.m);

		Brick.PointAC.PointUn = fBrickPos;
		Brick.PointAC.PointDeux.x = fBrickPos.x;
		Brick.PointAC.PointDeux.y = fBrickPos.y + fBrickSize.y;
		Brick.PointAC.m = Math::CoefM(Brick.PointAC.PointUn, Brick.PointAC.PointDeux);
		Brick.PointAC.b = Math::OrigineB(Brick.PointAC.PointUn, Brick.PointAC.m);

		Brick.PointBD.PointUn.x = fBrickPos.x + fBrickSize.x;
		Brick.PointBD.PointUn.y = fBrickPos.y;
		Brick.PointBD.PointDeux.x = fBrickPos.x + fBrickSize.x;
		Brick.PointBD.PointDeux.y = fBrickPos.y + fBrickSize.y;
		Brick.PointBD.m = Math::CoefM(Brick.PointBD.PointUn, Brick.PointBD.PointDeux);
		Brick.PointBD.b = Math::OrigineB(Brick.PointBD.PointUn, Brick.PointBD.m);

		Brick.PointDC.PointUn.x = fBrickPos.x + fBrickSize.x;
		Brick.PointDC.PointUn.y = fBrickPos.y + fBrickSize.y;
		Brick.PointDC.PointDeux.x = fBrickPos.x;
		Brick.PointDC.PointDeux.y = fBrickPos.y + fBrickSize.y;
		Brick.PointDC.m = Math::CoefM(Brick.PointDC.PointUn, Brick.PointDC.PointDeux);
		Brick.PointDC.b = Math::OrigineB(Brick.PointDC.PointUn, Brick.PointDC.m);

		Math::Intersection();
	}
}
