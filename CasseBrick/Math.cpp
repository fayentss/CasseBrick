#include "Math.h"
bool Math::IsInside(int v, int vMin, int vMax) 
{
	if (v > vMin && v < vMax) 
		return true;

	else 
		return false;
};
float Math::CoefM(std::vector<float> PointA, std::vector<float> PointB) 
{
	//[0] = x; [1] = y; 
	float result;
	result = (PointB[1] - PointA[1]) / (PointB[0] - PointA[0]);
	return result;
};