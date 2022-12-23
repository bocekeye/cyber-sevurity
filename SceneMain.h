#pragma once

#include "SceneBase.h"
#include "Vec2.h"
#include "Player.h"
#include "Enemy.h"
#include "Key.h"

#include <vector>

class SceneMain : public SceneBase
{
public:

	SceneMain();

	virtual ~SceneMain();

	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;

	virtual void draw() override;


private:

	//グラフィックハンドル
	int m_hPlayer;
	int m_hEnemy;
	int m_hKey;

	int m_enemyInterval;    //エネミーのインターバル
	int m_keyInterval;		//キーのーインターバル

	int m_getKeyCount;		//キーのカウント

	std::vector <Enemy*> m_pEnemy;
	Player* m_pPlayer;
	std::vector <Key*> m_pKey;

};