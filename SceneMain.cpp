#include "DxLib.h"
#include "game.h"

#include "SceneMain.h"
#include "SceneGameOver.h"
#include "SceneGameClear.h"

namespace
{
	const char* const kPlayerFilename = "Data/player.bmp";	//プレイヤー
	const char* const kEnemyFilename = "Data/enemy.bmp";	//エネミー
	const char* const kKeyFilename = "Data/koin.jpeg";		//コイン

	// 同時に登場する敵の最大数
	constexpr int kEnemyMax = 30;
	constexpr int kEnemyInterval = 50;

	// 同時に登場するコインの最大数
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
	//メモリの開放
	delete m_pPlayer;
	//デストラクタ
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

		//当たり判定
		if (m_pPlayer->isCol(*pEnemy))
		{
			m_pPlayer->setExist(false);
			return (new SceneGameOver);		//プレイヤーがエネミーに当たるとSceneGameOverに移動する
		}
		if (!pEnemy->isExist())
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "Hit : %d", m_getKeyCount);	//コインの取得枚数の表示

	for (auto& pKey : m_pKey)
	{
		if (!pKey) continue;
		pKey->update();

		//当たり判定
		if (m_pPlayer->isCol(*pKey))
		{
			m_getKeyCount++;			//コインを取得したらカウント１プラスする

			pKey->setExist(false);

			if (m_getKeyCount >= 1)	//10枚取得したらSceneGameClearに移動する
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
	//弾の生成
	m_enemyInterval++;
	if (m_enemyInterval > kEnemyInterval)
	{
		for (auto& pEnemy : m_pEnemy)
		{
			if (!pEnemy) //null
			{
				pEnemy = new Enemy;

				pEnemy->init();														//初期化
				pEnemy->setHandle(m_hEnemy);										//グラフィック
				pEnemy->setExist(true);												
				Vec2 pos{Game::kScreenWidth,static_cast<float> (GetRand(479))};		//ランダムな位置に生成
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
	
	//プレイヤーの描画
	m_pPlayer->draw();

	//エネミーの描画
	for (auto& pEnemy : m_pEnemy)
	{
		if (pEnemy)
		{
			pEnemy->draw();
		}
	}
	//コインの描画
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
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "敵の数: %d", num);
}
