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

	//���݊m�F
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	//�����蔻��̕��A�������擾
	float getColWidth() ;
	float getColHeight();

private:

	//�O���t�B�b�N�n���h��
	int m_hGraph;

	//�������Ă��邩
	bool m_isExist;

	Vec2 m_pos;

};