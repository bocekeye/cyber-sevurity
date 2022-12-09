#include "SceneExplain.h"
#include "SceneMain.h"
#include <DxLib.h>
namespace
{
	//表示文字列
	const char* const kExplainText1 = "ワンクリック詐欺に引っかかってしまった！";
	const char* const kExplainText2 = "";

	const char* const kExplainGuide = "2ボタンを押してゲームスタート";
}



SceneExplain::SceneExplain()
{
}

void SceneExplain::init()
{
}

SceneBase* SceneExplain::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		return(new SceneMain);
	}
	return this;
}

void SceneExplain::draw()
{
	SetFontSize(20);
	DrawString(200, 50, kExplainText1, GetColor(255,255,255));
//	DrawString(200, 100, );

	DrawString(200, 350, kExplainGuide, GetColor(255, 255, 255));
}
