#pragma once
#include "GameObj.h";
#include "Brick.h";

class Ball : public GameObj
{
private:
	bool _bIsMoving;
	sf::Vector2f _vDirection;

public:
	Ball(sf::RenderWindow* pWindow, int iDiametre, sf::Color cColor);
	sf::Vector2f GetBallPosition();
	void IsMoving(bool bIsMoving, sf::Vector2f vDirection);
	void Movement(float fDeltaTime);
	bool WindowCollider();
	bool BlocCollider(Brick* pBrick);
};

