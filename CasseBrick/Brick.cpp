#include "Brick.h"
#include "LevelCreator.h"
#include "GameObjManager.h"
Brick::Brick(sf::RenderWindow* pWindow, GameObjManager* pObjManager, float fWidth, float fHeight, float fPosX, float fPosY, LevelCreator* pLevel) : GameObj(pWindow, pObjManager, fWidth, fHeight, fPosX, fPosY, sf::Color(0, 255, 0))
{
	_iHp = 3;
	_pLevel = pLevel;
};
Brick::~Brick()
{
	_pLevel->DeleteBrick(this);
}
void Brick::TakeDamage(int iDamage)
{
	_iHp = _iHp - iDamage;

	switch (_iHp)
	{
	case 0:
		_pObjManager->AddObjToDelete(this);
	case 1:
		SetColor(sf::Color(255, 0, 0));
		break;
	case 2:
		SetColor(sf::Color(255, 255, 0));
		break;
	case 3:
		SetColor(sf::Color(128, 255, 0));
		break;

	default:
		break;
	}
}