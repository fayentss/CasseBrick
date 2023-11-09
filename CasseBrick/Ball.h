#pragma once
#include "GameObj.h";
#include "Brick.h";

class Ball : public GameObj
{
private:
	//vitesse ?

public:
	Ball(sf::RenderWindow* pWindow,int iDiametre, int iPosX, int iPosY, sf::Color cColor);
	bool WindowCollider();
	bool BlocCollider(Brick* pBrick);
};

