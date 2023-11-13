#include "Ball.h"
#include "GameObj.h"

Ball::Ball(sf::RenderWindow* pWindow, float iDiametre, float iPosX, float iPosY,sf::Color cColor) : GameObj(pWindow, iDiametre, 310, 230, cColor)
{
	_bIsMoving = false;
}
sf::Vector2f Ball::GetBallPosition()
{
	return GetPosition();
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
		float fNewX = GetPosition().x + (_vDirection.x * 200) * fDeltaTime;
		float fNewY = GetPosition().y + (_vDirection.y * 200) * fDeltaTime;
		SetPostion(fNewX, fNewY);
	}
}
