// ��d�C���N���[�h�h�~
#ifndef __ENEMY_MAP_DATA_H__
#define __ENEMY_MAP_DATA_H__

// �G�l�~�[�}�b�v�f�[�^�\����EnemyMapData
struct EnemyMapData{
	int m_x;	// x���W.
	int m_y;	// y���W.
	int m_nEnemyNo;	// �G�l�~�[�ԍ�.
	int m_nLife;	// ���C�t.
	int m_nState;	// ���.
	int m_nScore;	// �l���X�R�A.
	int m_nExplosionAnimation;	// �����A�j��.
	int m_nMoveType;	// ����^�C�v.
	int m_nMoveState;	// ������.
	int m_nMoveValue;	// ���쎞�̒l.
};

#endif
