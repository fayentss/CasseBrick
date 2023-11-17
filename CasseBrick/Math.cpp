#include "Math.h"
#include <utility>
#include <limits>
bool Math::IsInside(int v, int vMin, int vMax) 
{
	if (v > vMin && v < vMax) 
		return true;

	else 
		return false;
};

void Math::CreateSegment(Math::Segment* result)
{
	result->_sfA = (result->_svP2.y - result->_svP1.y) / (result->_svP2.x - result->_svP1.x);
	result->_sfB = result->_svP1.y - result->_sfA * result->_svP1.x;
};
float Math::DivisionEclidien(sf::Vector2f Point1, sf::Vector2f Point2) 
{
	return sqrt(pow(Point2.x - Point1.x, 2) + pow(Point2.y - Point1.y, 2));
};
float Math::ValeurMinOrMaxVector(std::vector<float> vValeur, bool MinOrMax) //false = min, true = Max
{
	float MinMax;
	if (MinOrMax == false)
	{
		MinMax = std::numeric_limits<float>::max();
		for (float i = 0; i < vValeur.size(); i++)
		{
			if (vValeur[i] < MinMax) {
				MinMax = vValeur[i];
			}
		}
	}
	else
	{
		MinMax = std::numeric_limits<float>::min();
		for (float i = 0; i < vValeur.size(); i++)
		{
			if (vValeur[i] > MinMax) {
				MinMax = vValeur[i];
			}
		}
	}
	return MinMax;
};

Math::Segment Intersection(std::vector<Math::Segment> CourbeBall, std::vector<Math::Segment> CourbeBrick)
{
	struct Vector2fSegment
	{
		Math::Segment SegmentBrickRebon;
		sf::Vector2f Point;
		float ResultFromDE;
	};
	std::vector<float> GetSaveInter;
	float Result = 0;
	sf::Vector2f Inter;
	std::vector<Vector2fSegment> RecupInter; 
	std::vector <float> ResultFromVMOrMVect;//VMOrMVect fait référrence a la fonction Math::ValeurMinOrMaxVector(std::vector<float> vValeur, bool MinOrMax)
	std::vector<Math::Segment> GetCourbeBrick;
	for (int i = 0; i < CourbeBall.size(); i++)
	{
		Math::CreateSegment(&CourbeBall[i]);
	};

	for (int i = 0; i < CourbeBrick.size(); i++)
	{
		Math::CreateSegment(&CourbeBrick[i]);
	};

	for (int i = 0; i < CourbeBall.size(); i++) 
	{
		RecupInter.clear();
		for (int j = 0; j < CourbeBrick.size(); j++) 
		{
			if (CourbeBall[i]._sfA == CourbeBrick[j]._sfA)
				continue;

			Inter.x = (CourbeBrick[j]._sfA - CourbeBall[i]._sfA) / (CourbeBall[i]._sfB - CourbeBrick[j]._sfB);
			Inter.y = CourbeBall[i]._sfA * Inter.x + CourbeBall[i]._sfB;

			if (Inter.x >= std::min(CourbeBall[i]._svP1.x, CourbeBall[i]._svP2.x) && Inter.x <= std::max(CourbeBall[i]._svP1.x, CourbeBall[i]._svP2.x) &&
				Inter.x >= std::min(CourbeBrick[j]._svP1.x, CourbeBrick[j]._svP2.x) && Inter.x <= std::max(CourbeBrick[j]._svP1.x, CourbeBrick[j]._svP2.x) &&
				Inter.y >= std::min(CourbeBall[i]._svP1.y, CourbeBall[i]._svP2.y) && Inter.y <= std::max(CourbeBall[i]._svP1.y, CourbeBall[i]._svP2.y) &&
				Inter.y >= std::min(CourbeBrick[j]._svP1.y, CourbeBrick[j]._svP2.y) && Inter.y <= std::max(CourbeBrick[j]._svP1.y, CourbeBrick[j]._svP2.y)) 
			{
				Vector2fSegment recup;
				recup.Point = Inter;
				recup.SegmentBrickRebon = CourbeBrick[j];
				RecupInter.push_back(recup);
			}
		}
		for (int j = 0; j < RecupInter.size(); j++) 
		{
			RecupInter[j].ResultFromDE = (Math::DivisionEclidien(CourbeBall[i]._svP1, RecupInter[j].Point));
			GetSaveInter.push_back(RecupInter[j].ResultFromDE);
		}
		ResultFromVMOrMVect.push_back(Math::ValeurMinOrMaxVector(GetSaveInter, false));
	}
	for (int j = 0; j < ResultFromVMOrMVect.size(); j++)
	{
		Result = Math::ValeurMinOrMaxVector(ResultFromVMOrMVect, false);
	}
	for (int j = 0; j < GetSaveInter.size(); j++)
	{
		if (Result == GetSaveInter[j])
			return RecupInter[j].SegmentBrickRebon;
	}
};