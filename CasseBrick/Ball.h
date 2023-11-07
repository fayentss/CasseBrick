#pragma once
#include "GameObj.h"

class Ball : GameObj
{
private:
	//vitesse ?

public:
	Ball(int iDiametre, int iPosX, int iPosY, sf::Color cColor);
	void Collider(sf::RenderWindow oWindow, int iPosX, int iPosY);
};

