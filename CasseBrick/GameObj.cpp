#include "GameObj.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


GameObj::GameObj(int diametre, int iposX, int iposY, sf::Color color)
{
	_iposX = iposX;
	_iposY = iposY;
	_iwidth = diametre;
	_iheight = diametre;
	_ccolor = color;

	sf::CircleShape oCircle(_iwidth);
	oCircle.setPosition(_iposX, _iposY);
	oCircle.setFillColor(_ccolor);

}

GameObj::GameObj(int iwidth, int iheight, int iposX, int iposY, sf::Color color)
{
	_iposX = iposX;
	_iposY = iposY;
	_iwidth = iwidth;
	_iheight = iheight;
	_ccolor = color;

	sf::RectangleShape oRectangle(sf::Vector2f(_iwidth, _iheight));
	oRectangle.setPosition(_iposX, _iposY);
	oRectangle.setFillColor(_ccolor);
}