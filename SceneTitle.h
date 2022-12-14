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
	
	int m_frashTime;			//文字の点滅までの時間

	int m_InTextTime;			//文字の表示までの時間
};
