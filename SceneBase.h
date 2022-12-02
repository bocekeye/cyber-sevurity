#pragma once

//ゲームシーン基底クラス
class SceneBase
{
public:

	SceneBase();
	virtual ~SceneBase() {}

	virtual void init(){}
	virtual void end() {}
	
	virtual SceneBase* update() { return this; }
	virtual void draw(){}

	void FadeUpdate(); //フェードの更新

	void FadeOut();	   //フェードアウト
	void FadeDraw();   //フェードの描画

private:

	int m_fadeValue;
	int m_fadeTimer;
};
