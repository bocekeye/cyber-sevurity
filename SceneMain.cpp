#include "DxLib.h"
#include "game.h"

#include "SceneMain.h"
#include "SceneGameOver.h"
#include "SceneGameClear.h"

namespace
{
	const char* const kPlayerFilename = "Data/player.bmp";
	const char* const kEnemyFilename = "Data/enemy.bmp";
	const char* const kKeyFilename = "Data/koin.jpeg";

	// “¯‚É“oê‚·‚é“G‚ÌÅ‘å”
	constexpr int kEnemyMax = 30;
	constexpr int kEnemyInterval = 50;

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
	//ƒƒ‚ƒŠ‚ÌŠJ•ú
	delete m_pPlayer;
	//ƒfƒXƒgƒ‰ƒNƒ^
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

	m_map.load();

	m_enemyInterval = 0;
}

void SceneMain::end()
{
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hEnemy);
	DeleteGraph(m_hKey);
	m_map.unload();
}

SceneBase* SceneMain::update()
{
	m_map.update();
	m_pPlayer->update();
	
	for (auto& pEnemy : m_pEnemy)
	{
		if (!pEnemy) continue;
		
		pEnemy->update();

		//“–‚½‚è”»’è
		if (m_pPlayer->isCol(*pEnemy))
		{
			DrawString(0, 30, "Hit", GetColor(255, 255, 255));

			//m_pPlayer->setExist(false);
			//return (new SceneGameOver);
		}
		else
		{
			DrawString(0, 45, "NoHit", GetColor(255, 255, 255));
		}
		
		if (!pEnemy->isExist())
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
	}

	for (auto& pKey : m_pKey)
	{
		if (!pKey) continue;

		pKey->update();
		//“–‚½‚è”»’è
		if (m_pPlayer->isCol(*pKey))
		{
			m_getKeyCount++;

			DrawFormatString(0, 60,  GetColor(255, 255, 255), "Hit : %d", m_getKeyCount );
			pKey->setExist(false);

			if (m_getKeyCount >= 5)
			{
				//return (new SceneGameClear);
			}
		}
		else
		{
			DrawString(0, 75, "NoHit", GetColor(255, 255, 255));
		}
		
		if (!pKey->isExist())
		{
			delete pKey;
			pKey = nullptr;
		}
	}
	//’e‚Ì¶¬
	m_enemyInterval++;
	if (m_enemyInterval > kEnemyInterval)
	{
		for (auto& pEnemy : m_pEnemy)
		{
			if (!pEnemy) //null
			{
				pEnemy = new Enemy;

				pEnemy->init();
				pEnemy->setHandle(m_hEnemy);
				pEnemy->setExist(true);
				Vec2 pos{Game::kScreenWidth,static_cast<float> (GetRand(479))};
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
	//m_map.draw();

	m_pPlayer->draw();

	for (auto& pEnemy : m_pEnemy)
	{
		if (pEnemy)
		{
			pEnemy->draw();
		}
	}
	for (auto& pKey : m_pKey)
	{
		if (pKey)
		{
			pKey->draw();
		}
	}

	int num = 0;

	for (auto& pEnemy : m_pEnemy)
	{
		if ((pEnemy) && pEnemy->isExist())
		{
			num++;
		}
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "“G‚Ì”: %d", num);
}
