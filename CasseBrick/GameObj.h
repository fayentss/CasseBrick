#pragma once
#include <SFML/Graphics/Color.hpp>

class GameObj
{
private:
	int _iposX;
	int _iposY;

	int _iwidth;
	int _iheight;

	sf::Color _ccolor;

public:
	GameObj(int diametre, int iposX, int iposY, sf::Color color); //cercle
	GameObj(int iwidth, int iheight, int iposX, int iposY, sf::Color color); //Rect

};





