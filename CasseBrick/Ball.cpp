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
		std::vector<Math::Segment> Allbrick;
		std::vector<Math::Segment> AllBall;
		Math::Segment brick;
		Math::Segment Ball;
		
		Ball._svP1 = _vLastPos;
		Ball._svP2 = fBallPos;
		AllBall.push_back(Ball);

		Ball._svP1.x = _vLastPos.x + fBallSize.x;
		Ball._svP1.y = _vLastPos.y;
		Ball._svP2.x = fBallPos.x + fBallSize.x;
		Ball._svP2.y = fBallPos.y;
		AllBall.push_back(Ball);

		Ball._svP1.x = _vLastPos.x;
		Ball._svP1.y = _vLastPos.y + fBallSize.y;
		Ball._svP2.x = fBallPos.x;
		Ball._svP2.y = fBallPos.y + fBallSize.y;
		AllBall.push_back(Ball);

		Ball._svP2.x = _vLastPos.x + fBallSize.x;
		Ball._svP2.y = _vLastPos.y + fBallSize.y;
		Ball._svP2.x = fBallPos.x + fBallSize.x;
		Ball._svP2.y = fBallPos.y + fBallSize.y;
		AllBall.push_back(Ball);


		brick._svP1 = fBrickPos;
		brick._svP2.x = fBrickPos.x + fBrickSize.x;
		brick._svP2.y = fBrickPos.y;
		Allbrick.push_back(brick);//face du haut

		brick._svP1 = fBrickPos;
		brick._svP2.x = fBrickPos.x;
		brick._svP2.y = fBrickPos.y + fBrickSize.y;
		Allbrick.push_back(brick);//face de gauche

		brick._svP1.x = fBrickPos.x + fBrickSize.x;
		brick._svP1.y = fBrickPos.y;
		brick._svP2.x = fBrickPos.x + fBrickSize.x;
		brick._svP2.y = fBrickPos.y + fBrickSize.y;
		Allbrick.push_back(brick);//face de droite

		brick._svP1.x = fBrickPos.x + fBrickSize.x;
		brick._svP1.y = fBrickPos.y + fBrickSize.y;
		brick._svP2.x = fBrickPos.x;
		brick._svP2.y = fBrickPos.y + fBrickSize.y;
		Allbrick.push_back(brick);//face de bas

		Math::Segment Translator = Math::Intersection(AllBall, Allbrick);
		for (int i = 0; i < Allbrick.size(); i++)
		{
			if(Translator._svP1 == Allbrick[i]._svP1 && Translator._svP2 == Allbrick[i]._svP2)
			{
				if (i == 0) {
					//colide face du haut
				}
				else if (i == 1) {
					//colide face du gauche
				}
				else if (i == 2) {
					//colide face du droite
				}
				else if (i == 3) {
					//colide face du bas
				}
			}
		}
	}
}
