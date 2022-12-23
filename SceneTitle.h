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
	
	int m_frashTime;			//•¶Žš‚Ì“_–Å‚Ü‚Å‚ÌŽžŠÔ

	int m_InTextTime;			//•¶Žš‚Ì•\Ž¦‚Ü‚Å‚ÌŽžŠÔ
};
