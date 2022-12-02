#include "Key.h"
#include "DxLib.h"
namespace
{
	constexpr float kSpeed = 2.0f;
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
	if (!m_isExist) return;
	float tempX = 0;
	float tempY = 0;

	if (m_pos.x < 0.0f - 220.0f)
	{
		m_isExist = false;
	}
	
	m_pos.x -= kSpeed;
}
void Key::draw()
{
	if (!m_isExist) return;

	DrawRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),0.2,0.0 ,m_hGraph, true);
}

float Key::getColWidth() //¶ã‚ÌÀ•W‚Ìæ“¾
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_hGraph, &tempX, &tempY);
	return tempX;
}
float Key::getColHeight() //‰E‰º‚ÌÀ•W‚Ìæ“¾
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_hGraph, &tempX, &tempY);
	return tempY;
}
