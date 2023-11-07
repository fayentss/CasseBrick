#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class GameObj
{
private:
	int _iPosX;
	int _iPosY;

	int _iWidth;
	int _iHeight;

	sf::Color _cColor;

protected:
	sf::Shape* _oShape;

public:

	GameObj(int iDiametre, int iPosX, int iPosY, sf::Color cColor); //cercle
	GameObj(int iWidth, int iHeight, int iPosX, int iPosY, sf::Color cColor); //Rect

	void Draw(sf::Shape* oShape);

	sf::Shape* GetShape();

};





