#pragma once

#include "SceneBase.h"

class SceneGameClear : public SceneBase
{
public:
	SceneGameClear() {};

	virtual ~SceneGameClear() {};

	virtual void init();

	virtual SceneBase* update()  override;
	virtual void draw();



};

