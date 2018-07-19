// ��d�C���N���[�h�h�~
#ifndef __ENEMIES_H__
#define __ENEMIES_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "SharedObject.h"	// CSharedObject
#include "Enemy.h"	// CEnemy

// �G�l�~�[�Y�N���XCEnemies
class CEnemies : public CSharedObject{

	// public�����o
	public:

		// public�����o�ϐ�
		std::vector<CEnemy *> m_vecEnemiesList;	// �G�l�~�[�Y���X�g.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CEnemies();	// �R���X�g���N�^CEnemies
		CEnemies(CScene *pScene);	// �R���X�g���N�^CEnemies(CScene *pScene)
		virtual ~CEnemies();	// �f�X�g���N�^~CEnemies

		// �����o�֐�
		void RemoveAll();	// �S�č폜.
		void Destroy();	// �j��Destroy.

};

#endif