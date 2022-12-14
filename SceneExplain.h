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

	int m_frashTime;		//文字の点滅までの時間
	int m_InTextTime;		//文字の表示までの時間
};

