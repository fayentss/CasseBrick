#include "Ball.h"
#include "GameObj.h"

Ball::Ball(sf::RenderWindow* pWindow, int iDiametre, int iPosX, int iPosY,sf::Color cColor) : GameObj(pWindow, iDiametre, 310, 230, cColor)
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
void Ball::Movement(float fDeltaTime)
{
	if (_bIsMoving == true)
	{
		float fNewX = GetShape()->getPosition().x + (_vDirection.x * 200) * fDeltaTime;
		float fNewY = GetShape()->getPosition().y + (_vDirection.y * 200) * fDeltaTime;
		GetShape()->setPosition(fNewX,fNewY);
	}
}
