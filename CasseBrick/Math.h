#pragma once
#include <vector>

namespace Math
{
	bool IsInside(int v, int vMin, int vMax);
	float CoefM(std::vector<float> PointA, std::vector<float> PointB);//les 2 vector on que 2 valeur x puis y dans cette orde ! donc [0] = x; [1] = y
	float OrigineB();
};


