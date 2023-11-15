#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class GameObj
{
private:
	sf::Shape* _pShape;
	float _iWidth;
	float _iHeight;

protected:

	sf::RenderWindow* _pWindow;

public:
	

	GameObj(sf::RenderWindow* pWindow, float iDiametre, float iPosX, float iPosY, sf::Color cColor); //cercle
	GameObj(sf::RenderWindow* pWindow , float iWidth, float iHeight, float iPosX, float iPosY, sf::Color cColor); //Rect

	void Draw() 
	{
		_pWindow->draw(*_pShape);
	}

	sf::Vector2f GetPosition();
	sf::Vector2f GetPositionTopLeft();
	void SetPostion(float iPosX, float iPosY);
	float GetRotation();
	void SetRotation(float fAngle);
	sf::Vector2f GetSize();
	void SetOrigine(float iPosX, float iPosY);
	void SetColor(sf::Color cColor);
};


