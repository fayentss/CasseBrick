#pragma once
#include "GameObj.h"

class Ball : public GameObj
{
private:
	bool _bIsMoving;
	sf::Vector2f _vDirection;

public:
	Ball(sf::RenderWindow* pWindow, float iDiametre, float iPosX, float iPosY, sf::Color cColor);
	sf::Vector2f GetBallPosition();
	void IsMoving(bool bIsMoving, sf::Vector2f vDirection);
	void Movement(float fDeltaTime);
	

};

