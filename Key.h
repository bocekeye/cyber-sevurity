#pragma once
#include "Vec2.h"

class Player;

class Key 
{
public:

	Key();
	virtual ~Key();

	void init();
	void end();

	void update();
	void draw();

	void setHandle(int handle) { m_hGraph = handle;}

	void setPos(Vec2 pos) { m_pos = pos; }

	Vec2 getPos() const { return m_pos; }

	//存在確認
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	//当たり判定の幅、高さを取得
	float getColWidth() ;
	float getColHeight();

private:

	//グラフィックハンドル
	int m_hGraph;

	//生存しているか
	bool m_isExist;

	Vec2 m_pos;

};