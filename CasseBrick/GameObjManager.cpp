#include "GameObjManager.h"

GameObjManager::GameObjManager()
{}

void GameObjManager::AddObjToDelete(GameObj* pObj)
{
	_vObjToDelete.push_back(pObj);
}
const std::vector<GameObj*>& GameObjManager::GetObjToDelete() const
{
	return (_vObjToDelete);
}
void GameObjManager::DeleteObjToDelete(GameObj* pObj)
{
	_vObjToDelete.erase(std::remove(_vObjToDelete.begin(), _vObjToDelete.end(), pObj), _vObjToDelete.end());
}