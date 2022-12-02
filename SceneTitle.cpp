#include "DxLib.h"
#include "game.h"

#include "SceneTitle.h"
#include "SceneMain.h"

namespace
{
	//�\��������
	const char* const kTitleText1 = "[����] �V�����o��I";
	const char* const kTitleText2 = "[�{��] ���Ȃ������ɑf�G��";
	const char* const kTitleText3 = "���m�点������܂��B";
	const char* const kTitleText4 = "���S�̏o��n�T�C�g";
	const char* const kGuideText = "1�{�^�����N���b�N�I";

	//�\���t�@�C��
	const char* const kBACKFilename = "Data/title.png";

	constexpr int kFrashFrame = 150;   //�_�Ŏ���
	constexpr int kInTextTime = 170;   //�e�L�X�g��\������܂ł̎���
}


SceneTitle::SceneTitle():
	m_textX(0),
	m_textY(0),
	m_frashTime(0),
	m_InTextTime(0),
	m_alpha(0)

{
	
}


void SceneTitle::init()
{
	m_textX = Game::kScreenWidth / 2;
 	m_textY = Game::kScreenHeight / 2;
}

SceneBase* SceneTitle::update()
{
	//(this->*m_func)();

	m_InTextTime++;
	m_frashTime++;
	if (m_frashTime >= kFrashFrame + 20)
	{
		m_frashTime = 0;
	}
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
//		SceneBase::FadeOut();
		return(new SceneMain);
	}

//	SceneBase::FadeUpdate();

	return this;
}

void SceneTitle::draw()
{
	SetFontSize(30);

	if (m_InTextTime > kInTextTime)
	{
		DrawString(100, 100, kTitleText1, GetColor(255, 0, 255));
		DrawString(100, 150, kTitleText2, GetColor(255, 0, 255));
		DrawString(100, 200, kTitleText3, GetColor(255, 0, 255));
		DrawString(100, 250, kTitleText4, GetColor(255, 0, 255));

		if (m_frashTime < kFrashFrame)
		{
			DrawString(100, 300, kGuideText, 0x00ffff);
		}
	}

//	SceneBase::FadeDraw();
	
}
