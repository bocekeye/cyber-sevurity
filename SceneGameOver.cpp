#include "SceneGameOver.h"
#include "SceneTitle.h"
#include "SceneMain.h"

#include <DxLib.h>

namespace
{
	const char* const kText1 = "1ボタンでゲームタイトル";
	const char* const kText2 = "2ボタンでもう一度プレイ";
}

void SceneGameOver::init()
{

}

SceneBase* SceneGameOver::update()
{

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_1)
	{
		return(new SceneTitle);
	}
	if (padState & PAD_INPUT_2)
	{
		return(new SceneMain);
	}


	return this;
}

void SceneGameOver::draw()
{
	SetFontSize(25);												//フォントサイズの変更			
	DrawString(300, 200, "GAME OVER", GetColor(255, 255, 255));

	SetFontSize(20);
	DrawString(400, 300, kText1, GetColor(255, 255, 255));
	DrawString(400, 350, kText2, GetColor(255, 255, 255));
}