#include "SceneExplain.h"
#include "SceneMain.h"
#include <DxLib.h>
namespace
{
	//表示文字列
	const char* const kExplainText1 = "ワンクリック詐欺に引っかかってしまった！";
	const char* const kExplainText2 = "右から来る敵に当たらないようにコインを集めて感染を防ごう！";
	const char* const kExplainText3 = "・上ボタン : ジャンプ";
	const char* const kExplainText4 = "・何もしていない状態は下におちるので気を付けよう";
	const char* const kExplainText5 = "・コインを10枚集めたらゲームクリア";

	const char* const kExplainGuide = "2ボタンを押してゲームスタート";


	constexpr int kFrashFrame = 120;   //点滅時間
	constexpr int kInTextTime = 140;   //テキストを表示するまでの時間

}



SceneExplain::SceneExplain():
	m_frashTime(0),
	m_InTextTime(0)
{
}

void SceneExplain::init()
{
}

SceneBase* SceneExplain::update()
{
	m_frashTime++;
	if (m_frashTime > kFrashFrame + 40)
	{
		m_frashTime = 0;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		return(new SceneMain);
	}
	return this;
}

void SceneExplain::draw()
{
	SetFontSize(30);
	DrawString(100, 100, kExplainText1, GetColor(0,255,255));
	
	SetFontSize(20);
	DrawString(100, 200, kExplainText2, GetColor(255, 255, 255));
	DrawString(100, 300, kExplainText3, GetColor(255, 255, 255));
	DrawString(100, 340, kExplainText4, GetColor(255, 255, 255));
	DrawString(100, 380, kExplainText5, GetColor(255, 255, 255));

	if (m_frashTime < kFrashFrame)										//文字の点滅
	{
		DrawString(450, 450, kExplainGuide, GetColor(255, 255, 255));
	}	
}
