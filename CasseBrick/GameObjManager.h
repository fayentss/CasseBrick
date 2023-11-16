#pragma once
#include<vector>
#include "GameObj.h"

class GameObjManager
{
private:
	std::vector<GameObj*> _vObjToDelete;

public:
	GameObjManager();
	void AddObjToDelete(GameObj* pObj);
	const std::vector<GameObj*>& GetObjToDelete() const;
	void DeleteObjToDelete(GameObj* pObj);
};

