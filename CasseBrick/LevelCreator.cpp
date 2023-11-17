#include "LevelCreator.h"


LevelCreator::LevelCreator(sf::RenderWindow* pWindow, GameObjManager* pObjManager)
{
	_pWindow = pWindow;
	_pObjManager = pObjManager;
}

void LevelCreator::Level1() 
{
	int iOffset = 10;
	
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			if (i == 5 || i == 10 || i == 15)
				continue;
			float fWidth = (_pWindow->getSize().x - (21 * iOffset))/20;
			float fHeight = 0.4 * fWidth;
			Brick* oBrick = new Brick(_pWindow, _pObjManager, fWidth, fHeight, iOffset + (fWidth * i) + (iOffset * i), fHeight + iOffset + (fHeight * j) + (iOffset * j), this);
			_vBrickList.push_back(oBrick);
		}
	}
	
}

const std::vector<Brick*>& LevelCreator::GetBrick() const
{
	return _vBrickList;
}
void LevelCreator::DeleteBrick(Brick* pBrick)
{
	_vBrickList.erase(std::remove(_vBrickList.begin(), _vBrickList.end(), pBrick), _vBrickList.end());
}