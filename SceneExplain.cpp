#include "SceneExplain.h"
#include "SceneMain.h"
#include <DxLib.h>
namespace
{
	//�\��������
	const char* const kExplainText1 = "�����N���b�N���\�Ɉ����������Ă��܂����I";
	const char* const kExplainText2 = "�E���痈��G�ɓ�����Ȃ��悤�ɃR�C�����W�߂Ċ�����h�����I";
	const char* const kExplainText3 = "�E��{�^�� : �W�����v";
	const char* const kExplainText4 = "�E�������Ă��Ȃ���Ԃ͉��ɂ�����̂ŋC��t���悤";
	const char* const kExplainText5 = "�E�R�C����10���W�߂���Q�[���N���A";

	const char* const kExplainGuide = "2�{�^���������ăQ�[���X�^�[�g";


	constexpr int kFrashFrame = 120;   //�_�Ŏ���
	constexpr int kInTextTime = 140;   //�e�L�X�g��\������܂ł̎���

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

	if (m_frashTime < kFrashFrame)										//�����̓_��
	{
		DrawString(450, 450, kExplainGuide, GetColor(255, 255, 255));
	}	
}
