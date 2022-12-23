#include "Key.h"
#include "DxLib.h"
namespace
{
	constexpr float kSpeed = 2.0f;		//コインの速さ
}

Key::Key() :
	m_hGraph(-1),
	m_isExist(false),
	m_pos()
{
}
Key::~Key()
{

}

void Key::init()
{
	m_isExist = false;
}
void Key::end()
{

}

void Key::update()
{
	if (!m_isExist) return;			//存在しない場合

	if (m_pos.x < 0.0f - 220.0f)	//画面外にある場合falseにする
	{
		m_isExist = false;
	}
	
	m_pos.x -= kSpeed;
}
void Key::draw()
{
	if (!m_isExist) return;			//存在しない場合

	DrawRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),1,0.0 ,m_hGraph, false);		
}

float Key::getColWidth() //左上の座標の取得
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_hGraph, &tempX, &tempY);
	return tempX;
}
float Key::getColHeight() //右下の座標の取得
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_hGraph, &tempX, &tempY);
	return tempY;
}
