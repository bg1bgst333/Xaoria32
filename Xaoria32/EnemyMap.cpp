// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "EnemyMap.h"	// CEnemyMap
#include "BinaryResource.h"	// CBinaryResource
#include "GameScene.h"	// CGameScene
#include "resource.h"	// ���\�[�X.

// �R���X�g���N�^CEnemyMap
CEnemyMap::CEnemyMap() : CSharedObject(){

	// �����o�̏�����.
	m_vecEnemyMapDataList.clear();	// �N���A.

}

// �R���X�g���N�^CEnemyMap(CScene *pScene)
CEnemyMap::CEnemyMap(CScene *pScene) : CSharedObject(pScene){

	// �����o�̏�����.
	m_vecEnemyMapDataList.clear();	// �N���A.

}

// �f�X�g���N�^~CEnemyMap
CEnemyMap::~CEnemyMap(){

	// �����o�̏I������.
	m_vecEnemyMapDataList.clear();	// �N���A.

}

// ����������Proc.
int CEnemyMap::Proc(){

	// �L���Ȃ�`���Ԃɂ���.
	for (int i = 0; i < m_vecEnemyMapDataList.size(); i++){
		if (m_vecEnemyMapDataList[i] != NULL){	// NULL�łȂ����.
			if (((CGameScene *)m_pScene) != NULL){	// NULL�łȂ�.
				if (((CGameScene *)m_pScene)->m_pMap != NULL){	// NULL�łȂ�.
					if (((CGameScene *)m_pScene)->m_pEnemy != NULL){	// NULL�łȂ�.
						int pos = m_vecEnemyMapDataList[i]->m_y - ((CGameScene *)m_pScene)->m_pEnemy->m_iHeight;
						if (((CGameScene *)m_pScene)->m_pMap->m_iScreenUY >= pos && ((CGameScene *)m_pScene)->m_pMap->m_iScreenUY < pos + 480 + ((CGameScene *)m_pScene)->m_pEnemy->m_iHeight){
							m_vecEnemyMapDataList[i]->m_nState = 1;							
						}
						else{
							m_vecEnemyMapDataList[i]->m_nState = 2;		
						}
						if (m_vecEnemyMapDataList[i]->m_nState == 1){
							((CGameScene *)m_pScene)->m_pEnemy->Set(0);
							((CGameScene *)m_pScene)->m_pEnemy->Set(m_vecEnemyMapDataList[i]->m_x, ((CGameScene *)m_pScene)->m_pMap->m_iScreenUY - m_vecEnemyMapDataList[i]->m_y);
						}
					}
				}
			}
		}
	}

	// �V�[���p���Ȃ�0.
	return 0;	// 0��Ԃ�.

}

// �`�������Draw.
void CEnemyMap::Draw(){

	// �L���Ȃ�`���Ԃɂ���.
	for (int i = 0; i < m_vecEnemyMapDataList.size(); i++){
		if (m_vecEnemyMapDataList[i] != NULL){	// NULL�łȂ����.
			if (((CGameScene *)m_pScene) != NULL){	// NULL�łȂ�.
				if (((CGameScene *)m_pScene)->m_pEnemy != NULL){	// NULL�łȂ�.
					if (m_vecEnemyMapDataList[i]->m_nState == 1){
						((CGameScene *)m_pScene)->m_pEnemy->Draw();
					}
				}
			}
		}
	}

}

// �S�č폜.
void CEnemyMap::RemoveAll(){

	// ���ׂẴI�u�W�F�N�g��j��.
	for (int i = 0; i < m_vecEnemyMapDataList.size(); i++){
		if (m_vecEnemyMapDataList[i] != NULL){	// NULL�łȂ����.
			delete m_vecEnemyMapDataList[i];	// delete��m_vecEnemyMapDataList[i]��j��.
			m_vecEnemyMapDataList[i] = NULL;	// NULL���Z�b�g.
		}
	}
	m_vecEnemyMapDataList.clear();	// �N���A.

}