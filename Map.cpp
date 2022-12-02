#include "DxLib.h"
#include "Map.h"
#include "game.h"
#include "Pad.h"
#include <cassert>

#include <iostream>
#include <fstream>

namespace
{
	//�}�b�v�`�b�v�T�C�Y1�̃T�C�Y
	constexpr int kChipSize = 32;

	//�`�b�v�̐�
	constexpr int kBgNumX = Game::kScreenWidth / kChipSize;
	constexpr int kBgNumY = Game::kScreenHeight / kChipSize;

	//���o�̓t�@�C����
	const char* const kFileName = "map.bin";
	//	const char* const kFileName = "bin/map.bin"; �t�H���_�ɕۑ�����ꍇ

		//�}�b�v�f�[�^
	constexpr int kMapData[kBgNumY][kBgNumX] =
	{
		{0, 1 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 ,0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

}


Map::Map() :
	m_handle(-1),
	m_graphWidth(0),
	m_graphHeight(0),
	m_mapData(kBgNumX * kBgNumY, 0),
	m_scrollX(0),
	m_scrollY(0)
{

}

Map::~Map()
{

}

void Map::load()
{
	m_handle = LoadGraph("data/mapchip.png");
	GetGraphSize(m_handle, &m_graphWidth, &m_graphHeight);
}

void Map::unload()
{
	DeleteGraph(m_handle);
}

void Map::update()
{
	
	m_scrollX -= 1;

	if (m_scrollX < -Game::kScreenWidth)
	{
		m_scrollX += Game::kScreenWidth;
	}
		
}

void Map::draw()
{
	//m_scrollX > 0 �E�ɂ���Ă���
	//m_scrollX < 0 ���ɂ���Ă���
	//m_scrollY > 0 ��ɂ���Ă���
	//m_scrollY < 0 ���ɂ���Ă���

	int offsetX = m_scrollX;
	if (offsetX > 0) offsetX -= Game::kScreenWidth;

	int offsetY = m_scrollY;
	if (offsetY > 0) offsetY -= Game::kScreenHeight;

	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			drawMap(offsetX + x * Game::kScreenWidth, offsetY + y * Game::kScreenHeight);
		}
	}
}

void Map::drawMap(int offsetX, int offsetY)
{
	for (int x = 0; x < kBgNumX; x++)
	{
		for (int y = 0; y < kBgNumY; y++)
		{
#if false
			const int chipNo = m_mapData[y * kBgNumX + x];
			assert(chipNo >= 0);
			assert(chipNo < chipNum());
			int graphX = (chipNo % chipNumX()) * kChipSize;
			int graphY = (chipNo / chipNumX()) * kChipSize;
			DrawRectGraph(x * kChipSize + offsetX, y * kChipSize + offsetY,
				graphX, graphY, kChipSize, kChipSize,
				m_handle, true, false);


			
#endif

			const int chipNo = m_mapData[y * kBgNumX + x];
			assert(chipNo >= 0);
			assert(chipNo < chipNum());
			int graphX = (chipNo % chipNumX()) * kChipSize;
			int graphY = (chipNo / chipNumX()) * kChipSize;

			DrawRectGraph(x * kChipSize + offsetX, y * kChipSize + offsetY,
				graphX, graphY, kChipSize, kChipSize,
				m_handle, true, false);
		}
	}

}

int Map::chipNumX()
{
	return (m_graphWidth / kChipSize);
}
int Map::chipNumY()
{
	return (m_graphHeight / kChipSize);
}
int Map::chipNum()
{
	return (chipNumX() * chipNumY());
}










