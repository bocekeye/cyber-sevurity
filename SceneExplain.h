#pragma once
#include "SceneBase.h"
class SceneExplain : public SceneBase
{
public:
	SceneExplain();
	virtual ~SceneExplain(){}

	virtual void init();
	virtual SceneBase* update();
	virtual void draw();

private:

	int m_frashTime;		//�����̓_�ł܂ł̎���
	int m_InTextTime;		//�����̕\���܂ł̎���
};

