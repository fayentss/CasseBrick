#pragma once
#include <SFML/System/Vector2.hpp>

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
		const char* side;
	};
	bool IsInside(int v, int vMin, int vMax);
	float FindCoeff(sf::Vector2f A, sf::Vector2f B);
	float FindCoeffInvers(sf::Vector2f A, sf::Vector2f B);
	sf::Vector2f GetInterPoint(sf::Vector2f ToCheck, Brick* pBrick, const char* side, float Coeff);
	bool InterPointExist(sf::Vector2f InterPoint, Brick* pBrick, const char* side);
	float FindNorme(sf::Vector2f A, sf::Vector2f B);
};

