#pragma once
#include <SFML/System/Vector2.hpp>

namespace Math
{
	struct Segment 
	{
		float _sfA;
		float _sfB;

		sf::Vector2f _svP1;
		sf::Vector2f _svP2;
	};
	sf::Vector2f _vResult;
	Segment CreateSegment(sf::Vector2f a, sf::Vector2f b);

	bool IsInside(int v, int vMin, int vMax);
	sf::Vector2f Intersection(Segment CourbeBall, Segment CourbeBrick);//todo faire 2 vector de segment pour tout look !
};


