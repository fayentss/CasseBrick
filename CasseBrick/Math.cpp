#include "Math.h"
#include "Brick.h"
bool Math::IsInside(int v, int vMin, int vMax) 
{
	if (v > vMin && v < vMax) 
		return true;

	else 
		return false;
};

float Math::FindCoeff(sf::Vector2f A, sf::Vector2f B)
{
	sf::Vector2f vector;
	vector = A - B;
	return(vector.x / vector.y);
}
float Math::FindCoeffInvers(sf::Vector2f A, sf::Vector2f B)
{
	sf::Vector2f vector;
	vector = A - B;
	return(vector.y / vector.x);
}
sf::Vector2f Math::GetInterPoint(sf::Vector2f Previous, sf::Vector2f Next, Brick* pBrick,const char* side)
{
	if (side == "Top")
	{
		sf::Vector2f InterPoint;
		InterPoint.y = pBrick->GetPosition().y;
		InterPoint.x = Previous.x + (((InterPoint.y - Previous.y) * (Next.x - Previous.x))/(Next.y - Previous.y));
		return InterPoint;
	}
	else if (side == "Bot")
	{
		sf::Vector2f InterPoint;
		InterPoint.y = pBrick->GetPosition().y + pBrick->GetSize().y;
		InterPoint.x = Previous.x + (((InterPoint.y - Previous.y) * (Next.x - Previous.x)) / (Next.y - Previous.y));
		return InterPoint;
	}
	else if (side == "Left")
	{
		sf::Vector2f InterPoint;
		InterPoint.x = pBrick->GetPosition().x;
		InterPoint.y = Previous.y + (((InterPoint.x - Previous.x) * (Next.y - Previous.y)) / (Next.x - Previous.x));
		return InterPoint;
	}
	else if (side == "Right")
	{
		sf::Vector2f InterPoint;
		InterPoint.x = (pBrick->GetPosition().x + pBrick->GetSize().x);
		InterPoint.y = Previous.y + (((InterPoint.x - Previous.x) * (Next.y - Previous.y)) / (Next.x - Previous.x));
		return InterPoint;
	}
}
bool Math::InterPointExist(sf::Vector2f InterPoint, Brick* pBrick, const char* side)
{
	if (side == "Top" || side == "Bot")
	{
		if ((pBrick->GetPosition().x < InterPoint.x) && (InterPoint.x < pBrick->GetPosition().x + pBrick->GetSize().x))
			return true;
		else
			return false;
	}
	else if (side == "Left" || side == "Right")
	{
		if ((pBrick->GetPosition().y < InterPoint.y) && (InterPoint.y < pBrick->GetPosition().y + pBrick->GetSize().y))
			return true;
		else
			return false;
	}
}
float Math::FindNorme(sf::Vector2f A, sf::Vector2f B)
{
	sf::Vector2f vector = B - A;
	float fNorme = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	return fNorme;
}