#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class GameObj
{
private:
	sf::Color _cColor;
	sf::Shape* _pShape;

protected:
	bool _bEnable;

	float _iWidth;
	float _iHeight;

	sf::RenderWindow* _pWindow;

public:
	

	GameObj(sf::RenderWindow* pWindow, float iDiametre, float iPosX, float iPosY, sf::Color cColor); //cercle
	GameObj(sf::RenderWindow* pWindow , float iWidth, float iHeight, float iPosX, float iPosY, sf::Color cColor); //Rect

	void Draw() 
	{
		_pWindow->draw(*_pShape);
	}

	sf::Vector2f GetPosition();
	void SetPostion(float iPosX, float iPosY);
	float GetRotation();
	void SetRotation(float fAngle);
	void SetOrigine(float iPosX, float iPosY);
};


