#include "LevelCreator.h"

LevelCreator::LevelCreator(sf::RenderWindow* pWindow) {
	_pWindow = pWindow;
	for (int i = 0; i < 15; i++)
	{
		_vBrickFolder.push_back(new Brick(_pWindow, 80.f, 40.f, 50.f, 50.f, sf::Color::Red));
	}
}
void LevelCreator::Level1to5() {
	_vBrickFolder[0]->SetPostion(50, 50);
	int w = 50;
	int h = 50;
	for (int i = 1; i < 15; i++)
	{
		w = w + 85;
		_vBrickFolder[i]->SetPostion(w, h);
	}
}
std::vector<Brick*> LevelCreator::GetvBrick() {
	return _vBrickFolder;
}