#include "DxLib.h"

#include "Enemy.h"

namespace
{
	//敵のスピード
	constexpr int kSpeed = 2;

}


Enemy::Enemy() :
	m_hGraph(-1),
	m_isExist(false),
	m_pos(),
	m_vec(),
	m_size(2.0)
{



}

Enemy::~Enemy()
{



}
void Enemy::init()
{
	m_isExist = true;

}
void Enemy::end()
{



}
void Enemy::update()
{

	if (!m_isExist) return;

	if (m_pos.x < 0.0f)
	{
		m_isExist = false;
	}
	m_pos.x -= kSpeed;

	m_size -= 0.01;

}
void Enemy::draw()
{
	if (!m_isExist) return;

	int width = 0;
	int height = 0;

	GetGraphSize(m_hGraph, &width, &height);
	
	//DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_hGraph, true);
	DrawRotaGraph(static_cast<int>(m_pos.x) + width / 2, static_cast<int>(m_pos.y) + height / 2, m_size , 0.0, m_hGraph, true, true);
}

float Enemy::getColWidth() //左上の座標の取得
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_hGraph, &tempX, &tempY);
	return tempX;
}
float Enemy::getColHeight() //右下の座標の取得
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_hGraph, &tempX, &tempY);
	return tempY;
}
