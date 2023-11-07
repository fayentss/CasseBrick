#include "Ball.h"
#include "GameObj.h"

Ball::Ball(int iDiametre, int iPosX, int iPosY, sf::Color cColor) : GameObj(iDiametre, iPosX, iPosY, cColor)
{
	// pos initial
	//
}
sf::Vector2f Ball::GetBallPosition()
{
	return _oShape->getPosition();
}
