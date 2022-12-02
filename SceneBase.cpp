#include <DxLib.h>

#include "SceneBase.h"
#include "game.h"

SceneBase::SceneBase():
	m_fadeValue(255),
	m_fadeTimer(0)
{



}
void SceneBase::FadeUpdate()
{
	m_fadeValue--;
}
void SceneBase::FadeOut()
{
	m_fadeValue++;
}

void SceneBase::FadeDraw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeValue);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}