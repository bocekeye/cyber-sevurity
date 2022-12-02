#pragma once

#include "Vec2.h"

class Enemy;
class Key;

class Player
{
public:
	Player();
	virtual ~Player();

	virtual void init();

	virtual void end();

	virtual void update();

	virtual void draw();

	void setHandle(int handle) { m_hGraph = handle; }

	void setPos(Vec2 pos) { m_pos = pos; }

	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	Vec2 getPos() const { return m_pos; }

	bool isCol(Enemy& enemy);

	bool isCol(Key& key);

private:

	//グラフィックハンドル
	int m_hGraph;

	//存在するか
	bool m_isExist;

	//左上座標
	Vec2 m_pos;

	//移動
	Vec2 m_vec;

};
