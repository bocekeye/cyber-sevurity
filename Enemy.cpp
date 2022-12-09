#include "DxLib.h"

#include "Enemy.h"

namespace
{
	//�G�̃X�s�[�h
	constexpr float kSpeed = 2.3f;

	//�摜�̑傫���ύX�p�C���^�[�o��
	constexpr int kStopFrame = 20;
}


Enemy::Enemy() :
	m_hGraph(-1),
	m_isExist(false),
	m_pos(),
	m_vec(),
	m_size(1.5),
	m_isChangeEnable(false),
	m_stopFrame(0)

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

	
	if (!m_isChangeEnable)
	{
		m_size -= 0.01;
		if (m_size < 1.0f)
		{
			m_size = 1.0f;
			m_stopFrame++;
			if (m_stopFrame > kStopFrame)	//�傫����ς��鎞�ɂ����ɕς��Ȃ��悤�ɂ���
			{
				m_isChangeEnable = true;
				m_stopFrame = 0;
			}
			
		}
	}
	else //(m_isChangeEnable)
	{
		m_size += 0.01;
		if (m_size > 2.0f)
		{
			m_size = 2.0f;
			m_stopFrame++;
			if (m_stopFrame > kStopFrame)	//�傫����ς��鎞�ɂ����ɕς��Ȃ��悤�ɂ���
			{
				m_isChangeEnable = false;
				m_stopFrame = 0;
			}
		}
	}


}
void Enemy::draw()
{
	if (!m_isExist) return;

	int width = 0;
	int height = 0;

	GetGraphSize(m_hGraph, &width, &height);
	
	//DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_hGraph, true);
	DrawRotaGraph(static_cast<int>(m_pos.x) + width / 2, static_cast<int>(m_pos.y) + height / 2,
					m_size , 0.0, m_hGraph, true, true);
}

float Enemy::getColWidth() //����̍��W�̎擾
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_hGraph, &tempX, &tempY);
	return tempX;
}
float Enemy::getColHeight() //�E���̍��W�̎擾
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_hGraph, &tempX, &tempY);
	return tempY;
}
