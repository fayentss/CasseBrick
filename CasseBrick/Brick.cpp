#include "Brick.h"
Brick::Brick(sf::RenderWindow* pWindow, float iWidth, float iHeight, float iPosX, float iPosY, int iID) : GameObj(pWindow, iWidth, iHeight, iPosX, iPosY, sf::Color(0, 255, 0))
{
	_iHp = 5;
	_iID = iID;
};
Brick::~Brick()
{
	
}
void Brick::TakeDamage(int iDamage)
{
	_iHp -= iDamage;

	switch (_iHp)
	{
	case 0:
		delete(this);
	case 1:
		SetColor(sf::Color(255, 0, 0));
	case 2:
		SetColor(sf::Color(255, 128, 0));
	case 3:
		SetColor(sf::Color(255, 255, 0));
	case 4:
		SetColor(sf::Color(128, 255, 0));
	case 5:
		SetColor(sf::Color(0, 255, 0));

	default:
		break;
	}
}