#include "Brick.h"
Brick::Brick(sf::RenderWindow* pWindow, int iWidth, int iHeight, int iPosX, int iPosY, sf::Color cColor) : GameObj(pWindow, iWidth, iHeight, iPosX, iPosY, cColor)
{

};
std::vector<float> Brick::GetAllPos()
{
	/*
	* l'empacement :
	* 0 c'est iPosX
	* 1 c'est iPosY
	* 2 c'est iWidth
	* 3 c'est iHeight
	*/
	std::vector<float> Allpos{
		GetPosition().x - _iWidth / 2,
		GetPosition().y - _iHeight / 2,
		GetPosition().x + _iWidth / 2,
		GetPosition().y + _iHeight / 2
	};
	return Allpos;
};