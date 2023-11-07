#pragma once
#include "GameObj.h"

class Ball : GameObj
{
private:
	//vitesse ?

public:
	Ball(int iDiametre, int iPosX, int iPosY, sf::Color cColor);
	sf::Vector2f GetBallPosition();

};

