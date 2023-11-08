#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class GameObj
{
private:
	bool _bEnable;

	sf::Color _cColor;

protected:

	int _iPosX;
	int _iPosY;

	int _iWidth;
	int _iHeight;

	sf::Window* _pWindow;
	sf::Shape* _pShape;

public:
	

	GameObj(sf::RenderWindow* pWindow, int iDiametre, int iPosX, int iPosY, sf::Color cColor); //cercle
	GameObj(sf::RenderWindow* pWindow ,int iWidth, int iHeight, int iPosX, int iPosY, sf::Color cColor); //Rect

	sf::Vector2f GetCenterPoint();

	sf::Shape* GetShape();

};





