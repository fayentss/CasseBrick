#pragma once
#include "Ball.h"

class Canon : public GameObj
{
public :
	Canon(sf::RenderWindow* pWindow, sf::Color cColor);
	void SpawnBallWithDirection();
};

