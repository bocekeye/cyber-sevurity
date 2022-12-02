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

	//���݊m�F
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	Vec2 getPos() const { return m_pos; }

	//�����蔻��̕��A�������擾
	float getColWidth();
	float getColHeight();


private:

	//�O���t�B�b�N�n���h��
	int m_hGraph;

	//���݂��邩
	bool m_isExist;

	//���W
	Vec2 m_pos;

	//�ړ�
	Vec2 m_vec;

	double m_size;
};