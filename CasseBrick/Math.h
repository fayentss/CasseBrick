#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Math
{
	
	struct Segment 
	{
		float _sfA;
		float _sfB;

		sf::Vector2f _svP1;
		sf::Vector2f _svP2;
	};
	void CreateSegment(Math::Segment* result);

	bool IsInside(int v, int vMin, int vMax);
	float DivisionEclidien(sf::Vector2f Point1, sf::Vector2f Point2);
	float ValeurMinOrMaxVector(std::vector<float> vValeur, bool MinOrMax);//si le bool est False alors il chercher le + petit (min),sinon le plus grand (max) 
	Segment Intersection(std::vector<Segment> CourbeBall, std::vector<Segment> CourbeBrick);//todo faire 2 vector de segment pour tout look !
};


