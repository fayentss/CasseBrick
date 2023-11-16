#pragma once
#include "GameObj.h"

class LevelCreator;
class Brick : public GameObj
{
private:
	int _iHp;
	LevelCreator* _pLevel;
public:
	Brick(sf::RenderWindow* pWindow, GameObjManager* pObjManager, float fWidth, float fHeight, float fPosX, float fPosY, LevelCreator* pLevel);
	~Brick();
	void TakeDamage(int iDamage);

};


