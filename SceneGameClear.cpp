#include "SceneGameClear.h"

#include "SceneTitle.h"

#include <DxLib.h>

namespace
{
	const char* const  kClearText = "������h�����I";

	constexpr int kTimeCount = 300;						//�^�C�g����ʂɈړ�����܂ł̎���
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
	if (m_timeCount > kTimeCount)	//�V�[���؂�ւ�
	{
		return (new SceneTitle);
	}
	return this;
}

void SceneGameClear::draw()
{
	SetFontSize(25);												//�t�H���g�T�C�Y�̕ύX		

	DrawString(300, 200, "GAME Clear", GetColor(255, 255, 255));
	DrawString(300, 250, kClearText, GetColor(255, 255, 255));
}
