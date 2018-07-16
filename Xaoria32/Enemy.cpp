// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Enemy.h"	// CEnemy
#include "resource.h"	// ���\�[�X.

// �R���X�g���N�^CEnemy
CEnemy::CEnemy() : CCharacter(){

	// �����o�̏�����.
	m_iNo = 0;	// m_iNo��0���Z�b�g.

}

// �f�X�g���N�^CEnemy(CScene *pScene)
CEnemy::CEnemy(CScene *pScene) : CCharacter(pScene){

	// �����o�̏�����.
	m_iNo = 0;	// m_iNo��0���Z�b�g.
	
}

// �f�X�g���N�^~CEnemy()
CEnemy::~CEnemy(){

	// �����o�̏I������.
	m_iNo = 0;	// m_iNo��0���Z�b�g.

	// �j��.
	Destroy();	// Destroy�Ŕj��.

}

// �L�����N�^�[�̔j��Destroy.
void CEnemy::Destroy(){

	// �e�N���X�̃����o�֐�.
	CCharacter::Destroy();	// CCharacter::Destroy�Ŕj��.

}

// ����������Proc.
int CEnemy::Proc(){

	// �A�j���[�V������0���Z�b�g.
	Set(0);	// 0���Z�b�g.

	// �V�[���p���Ȃ�0.
	return 0;	// 0��Ԃ�.

}

// �ʒu���Z�b�g����Set.
void CEnemy::Set(int x, int y){

	// �����o�̃Z�b�g.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.

}

// �A�j���[�V�������Z�b�g����Set.
void CEnemy::Set(int iNo){

	// �A�j���[�V�����̃Z�b�g.
	m_iNo = iNo;	// m_iNo��iNo���Z�b�g.

}

// �`�������Draw.
void CEnemy::Draw(){

	// �`��.
	//CCharacter::Draw(m_x, m_y, m_iNo);	// CCharacter::Draw�ŕ`��.
	CCharacter::DrawSprite(m_x, m_y, m_iNo);	// CCharacter::DrawSprite�ŕ`��.

}