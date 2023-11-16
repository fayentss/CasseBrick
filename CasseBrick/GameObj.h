#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class GameObjManager;

class GameObj
{
private:
	sf::Shape* _pShape;
	float _fWidth;
	float _fHeight;

protected:

	sf::RenderWindow* _pWindow;
	GameObjManager* _pObjManager;

public:
	

	GameObj(sf::RenderWindow* pWindow, GameObjManager* _pObjManager, float fDiametre, float fPosX, float fPosY, sf::Color cColor); //cercle
	GameObj(sf::RenderWindow* pWindow, GameObjManager* _pObjManager, float fWidth, float fHeight, float fPosX, float fPosY, sf::Color cColor); //Rect

	virtual ~GameObj();

	void Draw() 
	{
		_pWindow->draw(*_pShape);
	}

	sf::Vector2f GetPosition();
	void SetPostion(float fPosX, float fPosY);
	float GetRotation();
	void SetRotation(float fAngle);
	sf::Vector2f GetSize();
	void SetOrigine(float fPosX, float fPosY);
	void SetColor(sf::Color cColor);
};


