#pragma once
#include "Ball.h"
#include <iostream>
#include <vector>

class Canon : public GameObj
{
private:
	std::vector<Ball*> _vBallList;
	float _fCooldown;
	sf::Clock _oClock;

public :
	Canon(sf::RenderWindow* pWindow, GameObjManager* pObjManager, sf::Color cColor);
	void UpdateRot();
	const std::vector<Ball*>& GetBallList() const;
	void DeleteBall(Ball* pBall);
	void ShootBall();
};

