#pragma once


#include <vector>

class Map
{
public:
	Map();
	virtual ~Map();

	//�O���t�B�b�N�f�[�^�̃��[�h�A�A�����[�h
	void load();
	void unload();

	void update();

	//�`��
	void draw();

private:
	//�}�b�v�̕`��
	void drawMap(int offsetX, int offsetY);

	//�}�b�v�`�b�v�̐����擾����
	int chipNumX();
	int chipNumY();
	int chipNum();

private:

	//�O���t�B�b�N�n���h���̃f�[�^
	int m_handle;

	//�O���t�B�b�N�̃f�[�^
	int m_graphWidth;
	int m_graphHeight;

	std::vector <int> m_mapData;

	//�X�N���[������
	int m_scrollX;
	int m_scrollY;

};
