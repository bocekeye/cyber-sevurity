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

	int m_frashTime;		//•¶Žš‚Ì“_–Å‚Ü‚Å‚ÌŽžŠÔ
	int m_InTextTime;		//•¶Žš‚Ì•\Ž¦‚Ü‚Å‚ÌŽžŠÔ
};

