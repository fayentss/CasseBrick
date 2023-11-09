#include "Brick.h"
Brick::Brick(sf::RenderWindow* pWindow, int iWidth, int iHeight, int iPosX, int iPosY, sf::Color cColor) : GameObj(pWindow, iWidth, iHeight, iPosX, iPosY, cColor)
{

};
std::vector<int> Brick::GetAllPos()
{
	/*
	* l'empacement :
	* 0 c'est iPosX
	* 1 c'est iPosY
	* 2 c'est iWidth
	* 3 c'est iHeight
	*/
	std::vector<int> Allpos{
		_iPosX,
		_iPosY,
		_iWidth + _iPosX,
		_iHeight + _iPosY
	};
	return Allpos;
};