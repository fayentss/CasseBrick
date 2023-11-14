#pragma once
#include "Ball.h"
#include "Brick.h"
#include <iostream>

class LevelCreator
{
private:
	std::vector<Brick*> _vBrickFolder;
	sf::RenderWindow* _pWindow;
public:	
	LevelCreator(sf::RenderWindow* pWindow);
	void Level1to5();//cette fonctione ne fonctionne qu'avec le builder ci-dessus
	std::vector<Brick*> GetvBrick();
};

