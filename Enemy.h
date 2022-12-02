#pragma once

#include "Vec2.h"
#include "Player.h"

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	void init();

	void end();

	void update();
	void draw();

	void setHandle(int handle) { m_hGraph = handle; }

	void setPos(Vec2 pos) { m_pos = pos; }

	//存在確認
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	Vec2 getPos() const { return m_pos; }

	//当たり判定の幅、高さを取得
	float getColWidth();
	float getColHeight();


private:

	//グラフィックハンドル
	int m_hGraph;

	//存在するか
	bool m_isExist;

	//座標
	Vec2 m_pos;

	//移動
	Vec2 m_vec;

	double m_size;
};