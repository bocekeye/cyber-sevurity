#pragma once

#include "SceneBase.h"

class SceneGameOver : public SceneBase
{
public:
	SceneGameOver() {};

	virtual ~SceneGameOver() {};

	virtual void init();

	virtual SceneBase* update()  override;
	virtual void draw();



};
