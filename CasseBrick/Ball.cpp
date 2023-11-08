#include "Ball.h"
#include "GameObj.h"

Ball::Ball(sf::RenderWindow* pWindow, int iDiametre, sf::Color cColor) : GameObj(pWindow, iDiametre, 310, 230, cColor)
{
	_bIsMoving = false;
}
sf::Vector2f Ball::GetBallPosition()
{
	return _pShape->getPosition();
}
void Ball::IsMoving(bool bIsMoving,sf::Vector2f vDirection)
{
	_bIsMoving = bIsMoving;
	_vDirection = vDirection;
}
void Ball::Movement()
{
	if (_bIsMoving == true)
	{
		GetShape()->setPosition(GetShape()->getPosition() + _vDirection);
	}
}
