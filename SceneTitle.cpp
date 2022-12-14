#include "DxLib.h"
#include "game.h"

#include "SceneTitle.h"
#include "SceneExplain.h"

namespace
{
	//表示文字列
	const char* const kTitleText1 = "[件名] 新しい出会い！";
	const char* const kTitleText2 = "[本文] あなただけに素敵な";
	const char* const kTitleText3 = "お知らせがあります。";
	const char* const kTitleText4 = "安心の出会い系サイト";
	const char* const kGuideText = "1ボタンをクリック！";

	//表示ファイル
	const char* const kBACKFilename = "Data/title.png";

	constexpr int kFrashFrame = 120;   //点滅時間
	constexpr int kInTextTime = 140;   //テキストを表示するまでの時間
}


SceneTitle::SceneTitle():
	m_frashTime(0),
	m_InTextTime(0)
{
	
}

void SceneTitle::init()
{
}

SceneBase* SceneTitle::update()
{
	m_InTextTime++;
	m_frashTime++;
	if (m_frashTime >= kFrashFrame + 20)
	{
		m_frashTime = 0;
	}
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		return(new SceneExplain);
	}
	return this;
}

void SceneTitle::draw()
{
	SetFontSize(30);												//フォントサイズの変更

	if (m_InTextTime > kInTextTime)									//文字の表示
	{
		DrawString(100, 100, kTitleText1, GetColor(255, 0, 255));
		DrawString(100, 150, kTitleText2, GetColor(255, 0, 255));
		DrawString(100, 200, kTitleText3, GetColor(255, 0, 255));
		DrawString(100, 250, kTitleText4, GetColor(255, 0, 255));

		if (m_frashTime < kFrashFrame)								//文字の点滅
		{
			DrawString(100, 350, kGuideText, 0x00ffff);
		}
	}
	
}
