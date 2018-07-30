// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Enemy.h"	// CEnemy
#include "Explosion.h"	// CExplosion
#include "resource.h"	// ���\�[�X.

// �R���X�g���N�^CEnemy
CEnemy::CEnemy() : CCharacter(){

	// �����o�̏�����.
	m_iNo = 0;	// m_iNo��0���Z�b�g.
	m_pExplosion = NULL;	// m_pExplosion��NULL���Z�b�g.

}

// �f�X�g���N�^CEnemy(CScene *pScene)
CEnemy::CEnemy(CScene *pScene) : CCharacter(pScene){

	// �����o�̏�����.
	m_iNo = 0;	// m_iNo��0���Z�b�g.
	m_pExplosion = NULL;	// m_pExplosion��NULL���Z�b�g.

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

	// �G�N�X�v���[�W�����̔j��.
	if (m_pExplosion != NULL){	// m_pExplosion��NULL�łȂ�.
		m_pExplosion->Destroy();	// �j��.
		delete m_pExplosion;	// �폜.
		m_pExplosion = NULL;	// NULL���Z�b�g.
	}

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

// �G�N�X�v���[�W�����̍쐬CreateExplosion.
void CEnemy::CreateExplosion(int nFirstX, int nFirstY, int iWidth, int iHeight, int nID){

	// CExplosion�̍쐬.
	CExplosion *pExplosion = new CExplosion(m_pScene);	// pExplosion�̐���.
	pExplosion->Add(nFirstX, nFirstY, iWidth, iHeight, nID);	// �C���[�W�ǉ�.
	pExplosion->AddMask(320 + nFirstX, nFirstY, iWidth, iHeight, nID);	// �}�X�N�ǉ�.
	pExplosion->Add(nFirstX + iWidth, nFirstY, iWidth, iHeight, nID);	// �C���[�W�ǉ�.
	pExplosion->AddMask(320 + nFirstX + iWidth, nFirstY, iWidth, iHeight, nID);	// �}�X�N�ǉ�.
	pExplosion->Add(nFirstX + iWidth * 2, nFirstY, iWidth, iHeight, nID);	// �C���[�W�ǉ�.
	pExplosion->AddMask(320 + nFirstX + iWidth * 2, nFirstY, iWidth, iHeight, nID);	// �}�X�N�ǉ�.
	pExplosion->Add(nFirstX + iWidth * 3, nFirstY, iWidth, iHeight, nID);	// �C���[�W�ǉ�.
	pExplosion->AddMask(320 + nFirstX + iWidth * 3, nFirstY, iWidth, iHeight, nID);	// �}�X�N�ǉ�.
	pExplosion->Set(m_x, m_y);	// �ʒu�̃Z�b�g.
	m_pExplosion = pExplosion;	// m_pExplosion��pExplosion���Z�b�g.

}

// �G�N�X�v���[�W������`�悷��DrawExplosion.
void CEnemy::DrawExplosion(int x, int y, int nAnimationNo){

	// �����`��.
	if (m_pExplosion != NULL){	// NULL�łȂ�.
		((CExplosion *)m_pExplosion)->DrawSprite(x, y, nAnimationNo);	// �G�̏ꍇ�͎w��̃A�j���[�V�����ԍ���`��.
	}

}