// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Enemies.h"	// CEnemies

// �R���X�g���N�^CEnemies
CEnemies::CEnemies() : CSharedObject(){

	// �����o�̏�����.
	m_vecEnemiesList.clear();	// �N���A.

}

// �R���X�g���N�^CEnemies(CScene *pScene)
CEnemies::CEnemies(CScene *pScene) : CSharedObject(pScene){

	// �����o�̏�����.
	m_vecEnemiesList.clear();	// �N���A.

}

// �f�X�g���N�^~CEnemies
CEnemies::~CEnemies(){

	// �����o�̏I������.
	Destroy();	// �j��.

}

// �S�č폜.
void CEnemies::RemoveAll(){

	// �S�č폜.
	for (int i = 0; i < m_vecEnemiesList.size(); i++){
		delete m_vecEnemiesList[i];	// i�Ԗڂ�j��.
		m_vecEnemiesList[i] = NULL;	// NULL���Z�b�g.
	}
	m_vecEnemiesList.clear();	// �N���A.

}

// �j��Destroy.
void CEnemies::Destroy(){

	// �S�č폜.
	RemoveAll();	// RemoveAll�őS�č폜.

}