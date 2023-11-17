#pragma once
#include "GameObj.h";
#include "Brick.h";

class Canon;

class Ball : public GameObj
{
private:
	bool _bIsMoving;
	sf::Vector2f _vDirection;
	Canon* _pCanon;
	sf::Vector2f _vLastPos;

public:
	Ball(sf::RenderWindow* pWindow, GameObjManager* pObjManager, float iDiametre, float iPosX, float iPosY, Canon* pCanon);
	sf::Vector2f GetBallDirection();
	void IsMoving(bool bIsMoving, sf::Vector2f vDirection);
	void Movement(float fDeltaTime);
	void Bounce(const char* side);
	void WindowCollider();
	void BlocCollider(Brick* pBrick);
	char FaceDetection(Brick* pBrick);

	~Ball();
};

