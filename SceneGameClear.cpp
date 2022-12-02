#include "SceneGameClear.h"

#include "SceneTitle.h"

#include <DxLib.h>

void SceneGameClear::init()
{

}

SceneBase* SceneGameClear::update()
{
	//return (new SceneTitle);

	return this;
}

void SceneGameClear::draw()
{
	DrawString(100, 100, "GAME Clear", GetColor(255, 255, 255));
}
