#include "Math.h"
bool Math::IsInside(int v, int vMin, int vMax) 
{
	if (v > vMin && v < vMax) 
		return true;

	else 
		return false;
};

Math::Segment Math::CreateSegment(sf::Vector2f a, sf::Vector2f b) 
{
	Math::Segment result;
	result._sfA = (b.y - a.y) / (b.x - a.x);
	result._sfB = a.y - result._sfA * a.x;
};
sf::Vector2f Intersection(Math::Segment CourbeBall, Math::Segment CourbeBrick)
{
	float Interx;
	float Intery;
	Interx = (CoefMDeux - CoefMUn) / (OrigineBUn - OrigineBDeux);
	Intery = CoefMUn * Interx + OrigineBUn;
	sf::Vector2f Inter;
	Inter.x = Interx;
	Inter.y = Intery;
	return Inter;
};