#include "SceneGameClear.h"

#include "SceneTitle.h"

#include <DxLib.h>

namespace
{
	const char* const  kClearText = "感染を防いだ！";

	constexpr int kTimeCount = 300;						//タイトル画面に移動するまでの時間
}

SceneGameClear::SceneGameClear():
	m_timeCount(0)
{

}

void SceneGameClear::init()
{
}

SceneBase* SceneGameClear::update()
{
	m_timeCount++;
	if (m_timeCount > kTimeCount)	//シーン切り替え
	{
		return (new SceneTitle);
	}
	return this;
}

void SceneGameClear::draw()
{
	SetFontSize(25);												//フォントサイズの変更		

	DrawString(300, 200, "GAME Clear", GetColor(255, 255, 255));
	DrawString(300, 250, kClearText, GetColor(255, 255, 255));
}
