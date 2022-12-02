#include "SceneManager.h"
#include <cassert>
#include "SceneTitle.h"
#include "SceneMain.h"
#include "Pad.h"

SceneManager::SceneManager()
{
	m_pScene = nullptr;
}
SceneManager::~SceneManager()
{

}

// ������
void SceneManager::init()
{
	m_pScene = new SceneTitle;
	m_pScene->init();
}
// �I��
void SceneManager::end()
{
	// �m�F����
	assert(m_pScene);
	if (!m_pScene)	return;

	m_pScene->end();
	delete m_pScene;
}
// ���t���[���̏���
void SceneManager::update()
{
	// �m�F����
	assert(m_pScene);
	Pad::update();
	if (!m_pScene)	return;
	// SceneBase��update�����Ăяo��
	SceneBase* pScene = m_pScene->update();
	if (pScene != m_pScene)
	{
		m_pScene->end();
		delete m_pScene;
		// ������
		m_pScene = pScene;
		m_pScene->init();
	}
}
// �`��
void SceneManager::draw()
{
	assert(m_pScene);
	if (!m_pScene)	return;
	m_pScene->draw();
}