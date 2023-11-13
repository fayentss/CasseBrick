#pragma once
#include "Ball.h"
#include <iostream>
#include <vector>

class Canon : public GameObj
{
private:
	std::vector<Ball*> _vBallList;
public :
	Canon(sf::RenderWindow* pWindow, sf::Color cColor);
	void UpdateRot();
	std::vector<Ball*> GetBallList();
	void ShootBall();
};

