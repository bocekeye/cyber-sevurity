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
	

//	int m_alpha;

	int m_frashTime;

	int m_InTextTime;

};
