#include "Math.h"
bool Math::IsInside(int v, int vMin, int vMax) 
{
	if (v > vMin && v < vMax) 
	{
		return true;
	}
	else 
	{
		return false;
	}
};