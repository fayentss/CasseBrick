#pragma once
#include "Ball.h"
#include "Brick.h"
#include <iostream>

class LevelCreator
{
private:
	sf::RenderWindow* _pWindow;
	std::vector<Brick*> _vBrickList;
public:	
	LevelCreator(sf::RenderWindow* pWindow);
	void Level1();//cette fonctione ne fonctionne qu'avec le builder ci-dessus
	std::vector<Brick*> GetBrick();
	void AddBrick(Brick* pBrick);
	void DeleteBrick(int BrickID);
};

