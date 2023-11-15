#include "LevelCreator.h"


LevelCreator::LevelCreator(sf::RenderWindow* pWindow)
{
	_pWindow = pWindow;
}

void LevelCreator::Level1() 
{
	_vBrickList[0]->SetPostion(50, 50);
	int w = 50;
	int h = 50;
	for (int i = 1; i < 15; i++)
	{
		w = w + 85;
		_vBrickList[i]->SetPostion(w, h);
	}
}

std::vector<Brick*> LevelCreator::GetBrick()
{
	return _vBrickList;
}

void LevelCreator::AddBrick(Brick* pBrick)
{
	_vBrickList.push_back(pBrick);
}

void LevelCreator::DeleteBrick(int BrickID)
{
	_vBrickList.erase(_vBrickList.begin()+BrickID);
}