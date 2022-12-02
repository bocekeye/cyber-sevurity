#pragma once

//�Q�[���V�[�����N���X
class SceneBase
{
public:

	SceneBase();
	virtual ~SceneBase() {}

	virtual void init(){}
	virtual void end() {}
	
	virtual SceneBase* update() { return this; }
	virtual void draw(){}

	void FadeUpdate(); //�t�F�[�h�̍X�V

	void FadeOut();	   //�t�F�[�h�A�E�g
	void FadeDraw();   //�t�F�[�h�̕`��

private:

	int m_fadeValue;
	int m_fadeTimer;
};
