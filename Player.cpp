#include <DxLib.h>

#include "Player.h"
#include "Enemy.h"
#include "Key.h"
#include "Pad.h"
#include "game.h"
namespace
{
	//プレイヤースピード
	constexpr float kSpeed = 3.0f;

	constexpr float kGravity = 0.8f;
}

Player::Player() :
	m_hGraph(-1),
	m_isExist(false),
	m_pos(Game::kScreenWidth / 2,Game::kScreenHeight / 2),
	m_vec()
{
}

Player::~Player()
{
}

void Player::init()
{
	m_vec.y = kGravity;
	m_isExist = true;
}

void Player::end()
{
}

void Player::update()
{
	if (!m_isExist) return;

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (Pad::isPress(PAD_INPUT_LEFT))
	{
		m_pos.x -= kSpeed;
	}
	if (Pad::isPress(PAD_INPUT_RIGHT))
	{
		m_pos.x += kSpeed;
	}	
	
	if (Pad::isTrigger(PAD_INPUT_UP))
	{
		m_pos.y -= 50.0f;
	}

	//プレイヤーの移動制限
	if (m_pos.x < 0.0f)
	{
		m_pos.x = 0.0f;
	}
	if (m_pos.x > Game::kScreenWidth - 64.0f)
	{
		m_pos.x = Game::kScreenWidth - 64.0f;
	}
	if (m_pos.y < 0.0f)
	{
		m_pos.y = 0.0f;
	}
	if (m_pos.y > Game::kScreenHeight - 80.0f)
	{
		m_pos.y = Game::kScreenHeight - 80.0f;
	}

	m_pos += m_vec;
}

void Player::draw()
{
	//死んでいる場合は表示しない
	if (!m_isExist) return;

	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_hGraph, true);
}

bool Player::isCol(Enemy& enemy)
{
	//存在しない敵は当たらない
	if (!enemy.isExist()) return false;

	float width = 0;
	float height = 0;

	GetGraphSizeF(m_hGraph, &width, &height);

	float playerLeft = m_pos.x;
	float playerTop = m_pos.y;
	float playerRight = m_pos.x + width;
	float playerBottom = m_pos.y + height;

	float enemyLeft = enemy.getPos().x;
	float enemyTop = enemy.getPos().y;
	float enemyRight = enemy.getPos().x + enemy.getColWidth();
	float enemyBottom = enemy.getPos().y + enemy.getColHeight();

	if (playerLeft > enemyRight) return false;
	if (playerRight < enemyLeft) return false;
	if (playerTop > enemyBottom) return false;
	if (playerBottom < enemyTop) return false;

	return true;
}

bool Player::isCol(Key& key)
{
	//存在しない敵は当たらない
	if (!key.isExist()) return false;

	float width = 0;
	float height = 0;

	GetGraphSizeF(m_hGraph, &width, &height);

	float playerLeft = m_pos.x;
	float playerTop = m_pos.y;
	float playerRight = m_pos.x + width;
	float playerBottom = m_pos.y + height;

	float enemyLeft = key.getPos().x;
	float enemyTop = key.getPos().y;
	float enemyRight = key.getPos().x + key.getColWidth();
	float enemyBottom = key.getPos().y + key.getColHeight();

	if (playerLeft > enemyRight) return false;
	if (playerRight < enemyLeft) return false;
	if (playerTop > enemyBottom) return false;
	if (playerBottom < enemyTop) return false;

	return true;
}















