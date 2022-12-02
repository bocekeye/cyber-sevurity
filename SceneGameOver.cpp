#include "SceneGameOver.h"
#include "SceneTitle.h"

#include <DxLib.h>

void SceneGameOver::init()
{

}

SceneBase* SceneGameOver::update()
{
	return (new SceneTitle);

	return this;
}

void SceneGameOver::draw()
{
	DrawString(100, 100, "GAME OVER", GetColor(255, 255, 255));
}