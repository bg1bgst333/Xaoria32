// ��d�C���N���[�h�h�~
#ifndef __ENEMY_H__
#define __ENEMY_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Character.h"	// CCharacter

// �G�l�~�[�N���XCEnemy
class CEnemy : public CCharacter{

	// public�����o
	public:

		// public�����o�ϐ�
		int m_iNo;	// �A�j���[�V�����ԍ�m_iNo.
		CSharedObject *m_pExplosion;	// �G�N�X�v���[�W�����I�u�W�F�N�gm_pExplosion.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CEnemy();	// �R���X�g���N�^CEnemy
		CEnemy(CScene *pScene);	// �f�X�g���N�^CEnemy(CScene *pScene)
		virtual ~CEnemy();	// �f�X�g���N�^~CEnemy()
		virtual void Destroy();	// �L�����N�^�[�̔j��Destroy.
		virtual int Proc();	// ����������Proc.
		virtual void Set(int x, int y);	// �ʒu���Z�b�g����Set.
		virtual void Set(int iNo);	// �A�j���[�V�������Z�b�g����Set.
		virtual void Draw();	// �`�������Draw.
		virtual void CreateExplosion(int nFirstX, int nFirstY, int iWidth, int iHeight, int nID);	// �G�N�X�v���[�W�����̍쐬CreateExplosion.
		virtual void DrawExplosion(int x, int y, int nAnimationNo);	// �G�N�X�v���[�W������`�悷��DrawExplosion.

};

#endif