// ��d�C���N���[�h�h�~
#ifndef __EXPLOSION_H__
#define __EXPLOSION_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "SharedObject.h"	// CSharedObject

// �G�N�X�v���[�W�����N���XCExplosion
class CExplosion : public CSharedObject{

	// public�����o
	public:

		// public�����o�ϐ�
		std::vector<CSharedObject *> m_vecpMaskList;	// �}�X�N���X�gm_vecpMaskList.
		int m_iState;	// ���.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CExplosion();	// �R���X�g���N�^CExplosion()
		CExplosion(CScene *pScene);	// �f�X�g���N�^CExplosion(CScene *pScene)
		virtual ~CExplosion();	// �f�X�g���N�^~CExplosion()
		// �����o�֐�
		virtual void Add(int sx, int sy, int iWidth, int iHeight, int nID);	// �A�j���[�V�����̒ǉ�Add.
		virtual void AddMask(int sx, int sy, int iWidth, int iHeight, int nID);	// �}�X�N�̒ǉ�AddMask.
		virtual void Destroy();	// �G�N�X�v���[�W�����̔j��Destroy.
		virtual void Draw(int x, int y, int iNo);	// �V�F�A�[�h�I�u�W�F�N�g�̕`��Draw.
		virtual void DrawSprite(int x, int y, int iNo);	// �X�v���C�g�̕`��DrawSprite.
		virtual BOOL DrawAnimation(int x, int y);	// �A�j���[�V�����`��DrawAnimation.
		virtual void Set(int x, int y);	// �ʒu���Z�b�g����Set.
		virtual void Set(int iState);	// ��Ԃ̃Z�b�g.
		virtual int Get();	// ��Ԃ̎擾.

};

#endif