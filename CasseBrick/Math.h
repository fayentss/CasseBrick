#pragma once
#include <SFML/System/Vector2.hpp>
#include "Brick.h"

namespace Math
{
	struct Square_Points
	{
		sf::Vector2f vTopLeft;
		sf::Vector2f vTopRight;
		sf::Vector2f vBotLeft;
		sf::Vector2f vBotRight;
	};
	struct Point_Info
	{
		sf::Vector2f vCoordPoint;
		float Norme;
		const char* cSideTouch;
		float fCoeff;
	};
	bool IsInside(int v, int vMin, int vMax);
	float FindCoeff(sf::Vector2f A, sf::Vector2f B);
	float FindCoeffInvers(sf::Vector2f A, sf::Vector2f B);
	sf::Vector2f GetInterPoint(sf::Vector2f Previous, sf::Vector2f Next, Brick* pBrick, const char* side);
	bool InterPointExist(sf::Vector2f InterPoint, Brick* pBrick, const char* side);
	float FindNorme(sf::Vector2f A, sf::Vector2f B);
};

