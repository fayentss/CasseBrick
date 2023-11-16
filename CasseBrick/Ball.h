#pragma once
#include "GameObj.h";
#include "Brick.h";

class Ball : public GameObj
{
private:
	bool _bIsMoving;
	sf::Vector2f _vDirection;
	sf::Vector2f _vLastPos;


public:
	Ball(sf::RenderWindow* pWindow, float iDiametre, float iPosX, float iPosY, sf::Color cColor);
	sf::Vector2f GetBallDirection();
	void IsMoving(bool bIsMoving, sf::Vector2f vDirection);
	void Movement(float fDeltaTime);
	void Bounce(const char* side);
	void WindowCollider();
	void BlocCollider(Brick* pBrick);

	~Ball();
};

