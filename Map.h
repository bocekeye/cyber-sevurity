#pragma once


#include <vector>

class Map
{
public:
	Map();
	virtual ~Map();

	//グラフィックデータのロード、アンロード
	void load();
	void unload();

	void update();

	//描画
	void draw();

private:
	//マップの描画
	void drawMap(int offsetX, int offsetY);

	//マップチップの数を取得する
	int chipNumX();
	int chipNumY();
	int chipNum();

private:

	//グラフィックハンドルのデータ
	int m_handle;

	//グラフィックのデータ
	int m_graphWidth;
	int m_graphHeight;

	std::vector <int> m_mapData;

	//スクロールする
	int m_scrollX;
	int m_scrollY;

};
