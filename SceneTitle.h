#pragma once

#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:

	SceneTitle();
	

	virtual ~SceneTitle(){}

	virtual void init(); 
	virtual void end(){}
	virtual SceneBase* update();
	virtual void draw();

private:
	
	int m_frashTime;			//�����̓_�ł܂ł̎���

	int m_InTextTime;			//�����̕\���܂ł̎���
};
