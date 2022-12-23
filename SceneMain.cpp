#include "DxLib.h"
#include "game.h"

#include "SceneMain.h"
#include "SceneGameOver.h"
#include "SceneGameClear.h"

namespace
{
	const char* const kPlayerFilename = "Data/player.bmp";	//�v���C���[
	const char* const kEnemyFilename = "Data/enemy.bmp";	//�G�l�~�[
	const char* const kKeyFilename = "Data/koin.jpeg";		//�R�C��

	// �����ɓo�ꂷ��G�̍ő吔
	constexpr int kEnemyMax = 30;
	constexpr int kEnemyInterval = 50;

	// �����ɓo�ꂷ��R�C���̍ő吔
	constexpr int kKeyMax = 5;
	constexpr int kKeyInterval = 300;
}

SceneMain::SceneMain():
	m_hPlayer(-1), 
	m_hEnemy(-1),
	m_hKey(-1),
	m_enemyInterval(0),
	m_keyInterval(0),
	m_getKeyCount(0),
	m_pPlayer(nullptr),
	m_pEnemy(kEnemyMax,nullptr),
	m_pKey(kKeyMax, nullptr)

{
	m_pPlayer = new Player;
}

SceneMain::~SceneMain()
{
	//�������̊J��
	delete m_pPlayer;
	//�f�X�g���N�^
	for (auto& pEnemy : m_pEnemy)
	{
		if (pEnemy)
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
	}

	for (auto& pKey : m_pKey)
	{
		if (pKey)
		{
			delete pKey;
			pKey = nullptr;
		}
	}
}

void SceneMain::init()
{
	m_hPlayer = LoadGraph(kPlayerFilename);
	m_hEnemy = LoadGraph(kEnemyFilename);
	m_hKey = LoadGraph(kKeyFilename);

	m_pPlayer->init();
	m_pPlayer->setHandle(m_hPlayer);

	m_enemyInterval = 0;
}

void SceneMain::end()
{
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hEnemy);
	DeleteGraph(m_hKey);
}

SceneBase* SceneMain::update()
{
	m_pPlayer->update();
	
	for (auto& pEnemy : m_pEnemy)
	{
		if (!pEnemy) continue;
		
		pEnemy->update();

		//�����蔻��
		if (m_pPlayer->isCol(*pEnemy))
		{
			m_pPlayer->setExist(false);
			return (new SceneGameOver);		//�v���C���[���G�l�~�[�ɓ������SceneGameOver�Ɉړ�����
		}
		if (!pEnemy->isExist())
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "Hit : %d", m_getKeyCount);	//�R�C���̎擾�����̕\��

	for (auto& pKey : m_pKey)
	{
		if (!pKey) continue;
		pKey->update();

		//�����蔻��
		if (m_pPlayer->isCol(*pKey))
		{
			m_getKeyCount++;			//�R�C�����擾������J�E���g�P�v���X����

			pKey->setExist(false);

			if (m_getKeyCount >= 1)	//10���擾������SceneGameClear�Ɉړ�����
			{
				return (new SceneGameClear);
			}
		}	
		if (!pKey->isExist())
		{
			delete pKey;
			pKey = nullptr;
		}
	}
	//�e�̐���
	m_enemyInterval++;
	if (m_enemyInterval > kEnemyInterval)
	{
		for (auto& pEnemy : m_pEnemy)
		{
			if (!pEnemy) //null
			{
				pEnemy = new Enemy;

				pEnemy->init();														//������
				pEnemy->setHandle(m_hEnemy);										//�O���t�B�b�N
				pEnemy->setExist(true);												
				Vec2 pos{Game::kScreenWidth,static_cast<float> (GetRand(479))};		//�����_���Ȉʒu�ɐ���
				pEnemy->setPos(pos);												

				break;
			}
		}
		m_enemyInterval = 0;
	}

	m_keyInterval++;
	if (m_keyInterval > kKeyInterval)
	{
		for (auto& pKey : m_pKey)
		{
			if (!pKey) //null
			{
				pKey = new Key;

				pKey->init();
				pKey->setHandle(m_hKey);
				pKey->setExist(true);

				Vec2 pos{ Game::kScreenWidth,static_cast<float> (GetRand(259)) };
				pKey->setPos(pos);
				break;
			}
		}
		m_keyInterval = 0;
	}

	return this;
}

void SceneMain::draw()
{
	 
	SetFontSize(20);			
	
	//�v���C���[�̕`��
	m_pPlayer->draw();

	//�G�l�~�[�̕`��
	for (auto& pEnemy : m_pEnemy)
	{
		if (pEnemy)
		{
			pEnemy->draw();
		}
	}
	//�R�C���̕`��
	for (auto& pKey : m_pKey)
	{
		if (pKey)
		{
			pKey->draw();
		}
	}

	/*int num = 0;

	for (auto& pEnemy : m_pEnemy)
	{
		if ((pEnemy) && pEnemy->isExist())
		{
			num++;
		}
	}*/
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "�G�̐�: %d", num);
}
