#pragma once
#include "GameObjManager.h"
#include "Ball.h"
#include "Brick.h"
#include <iostream>

class LevelCreator
{
private:
	sf::RenderWindow* _pWindow;
	std::vector<Brick*> _vBrickList;
	GameObjManager* _pObjManager;
public:	
	LevelCreator(sf::RenderWindow* pWindow, GameObjManager* pObjManager);
	void Level1();//cette fonctione ne fonctionne qu'avec le builder ci-dessus
	const std::vector<Brick*>& GetBrick() const;
	void DeleteBrick(Brick* pBrick);
};

