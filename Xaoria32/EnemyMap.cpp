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
	m_pEnemies = NULL;	// NULL���Z�b�g.

}

// �R���X�g���N�^CEnemyMap(CScene *pScene)
CEnemyMap::CEnemyMap(CScene *pScene) : CSharedObject(pScene){

	// �����o�̏�����.
	m_vecEnemyMapDataList.clear();	// �N���A.
	m_pEnemies = NULL;	// NULL���Z�b�g.

}

// �f�X�g���N�^~CEnemyMap
CEnemyMap::~CEnemyMap(){

	// �����o�̏I������.
	Destroy();	// Destroy�ŏI������.

}

// �쐬����Create.
int CEnemyMap::Create(){

	// �G�l�~�[�}�̍쐬.
	m_pEnemies = new CEnemies(m_pScene);	// m_pEnemies�̍쐬.
	return 0;	// 0��Ԃ�.
}

// �G�l�~�[�ǉ�.
int CEnemyMap::AddEnemy(int x, int y, int iWidth, int iHeight){

	// �G�l�~�[�쐬.
	CEnemy *pEnemy = new CEnemy(m_pScene);	// pEnemy�쐬.
	pEnemy->Set(x, y);	// x��y���Z�b�g.
	pEnemy->m_iWidth = iWidth;	// iWidth���Z�b�g.
	pEnemy->m_iHeight = iHeight;	// iHeight���Z�b�g.
	int iNo = m_pEnemies->m_vecEnemiesList.size();	// iNo == �}���O�̃T�C�Y.
	m_pEnemies->m_vecEnemiesList.push_back(pEnemy);	// pEnemy��ǉ�.
	return iNo;	// iNo��Ԃ�.

}

// �w��̃G�l�~�[�ɃA�j���[�V�����C���[�W��ǉ�. 
void CEnemyMap::AddEnemyAnimation(int iEnemyNo, RECT *lprcImgSrc, int nImgSrcID, RECT *lprcMaskSrc, int nMaskSrcID){

	// iEnemyNo�Ԗڂ����邩�`�F�b�N.
	if (iEnemyNo < m_pEnemies->m_vecEnemiesList.size()){	// �C���f�b�N�X�𒴂��Ȃ����`�F�b�N.
		CEnemy *pEnemy = m_pEnemies->m_vecEnemiesList[iEnemyNo];	// iEnemyNo�Ԗڂ����o��.
		pEnemy->Add(lprcImgSrc->left, lprcImgSrc->top, lprcImgSrc->right - lprcImgSrc->left, lprcImgSrc->bottom - lprcImgSrc->top, nImgSrcID);	// �A�j���[�V�����C���[�W�ǉ�.
		pEnemy->AddMask(lprcMaskSrc->left, lprcMaskSrc->top, lprcMaskSrc->right - lprcMaskSrc->left, lprcMaskSrc->bottom - lprcMaskSrc->top, nMaskSrcID);	// �A�j���[�V�����}�X�N�ǉ�.
	}

}

// �G�l�~�[�z�u.
void CEnemyMap::DeployEnemy(int x, int y, int iEnemyNo, int iState){

	// �G�l�~�[�}�b�v�f�[�^�̐���.
	EnemyMapData *pEMD = new EnemyMapData();	// pEMD�̐���.
	// �l�̐ݒ�.
	pEMD->m_x = x;	// x
	pEMD->m_y = y;	// y
	pEMD->m_nEnemyNo = iEnemyNo;	// �G�l�~�[�ԍ�.
	pEMD->m_nState = iState;	// ���.
	// �ǉ�.
	m_vecEnemyMapDataList.push_back(pEMD);	// �ǉ�.

}

// ����������Proc.
int CEnemyMap::Proc(){

	// �L���Ȃ�`���Ԃɂ���.
	if (m_pEnemies != NULL){	// NULL�łȂ�.
		CGameScene *pGameScene = (CGameScene *)m_pScene;	// pGameScene�ɃL���X�g.
		CMap *pMap = pGameScene->m_pMap;	// pMap�ɕێ�.
		int iScreenUY = pMap->m_iScreenUY;	// �X�N���[�����Wy.
		if (pGameScene != NULL && pMap != NULL){	// �ǂ����NULL�łȂ�.
			for (int i = 0; i < m_vecEnemyMapDataList.size(); i++){
				int iDrawPos = m_vecEnemyMapDataList[i]->m_y;	// �z�u�ꏊ.
				int nEnemyNo = m_vecEnemyMapDataList[i]->m_nEnemyNo;	// �G�l�~�[�ԍ�.
				if (nEnemyNo < m_pEnemies->m_vecEnemiesList.size()){	// �ԍ����T�C�Y����.
					int iHeight = m_pEnemies->m_vecEnemiesList[nEnemyNo]->m_iHeight;	// ����.
					int iDrawPosStart = iDrawPos - iHeight;	// �z�u�ꏊ���獂��������.
					int iDrawPosEnd = iDrawPosStart + iHeight + 480;	// �`��J�n�ɃG�l�~�[�����ƃX�N���[�������𑫂�.
					if (iDrawPosStart <= iScreenUY && iDrawPosEnd > iScreenUY){	// �`��ʒu.
						m_vecEnemyMapDataList[i]->m_nState = 1;	// �\�����.
					}
					else if (iDrawPosEnd <= iScreenUY){	// ��������.
						m_vecEnemyMapDataList[i]->m_nState = 2;	// �ʉߔ�\�����.
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
	if (m_pEnemies != NULL){	// NULL�łȂ�.
		CGameScene *pGameScene = (CGameScene *)m_pScene;	// pGameScene�ɃL���X�g.
		CMap *pMap = pGameScene->m_pMap;	// pMap�ɕێ�.
		int iScreenUY = pMap->m_iScreenUY;	// �X�N���[�����Wy.
		for (int i = 0; i < m_vecEnemyMapDataList.size(); i++){
			if (m_vecEnemyMapDataList[i] != NULL){	// NULL�łȂ����.
				int nEnemyNo = m_vecEnemyMapDataList[i]->m_nEnemyNo;
				if (nEnemyNo < m_pEnemies->m_vecEnemiesList.size()){	// �ԍ����T�C�Y����.
					CEnemy *pEnemy = m_pEnemies->m_vecEnemiesList[nEnemyNo];	// pEnemy�����o��.
					if (m_vecEnemyMapDataList[i]->m_nState == 1){	// 1�̎��͕\��.
						pEnemy->Set(0);	// �A�j���[�V����0.
						int x = m_vecEnemyMapDataList[i]->m_x;	// x
						int y = iScreenUY - m_vecEnemyMapDataList[i]->m_y;	// �X�N���[���ʒuy����G�l�~�[y������.
						pEnemy->Set(x, y);	// �Z�b�g.
						pEnemy->Draw();	// �`��.
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

// �L�����N�^�[�̔j��Destroy.
void CEnemyMap::Destroy(){

	// �S�č폜.
	RemoveAll();	// RemoveAll�őS�č폜.
	if (m_pEnemies != NULL){	// NULL�łȂ�.
		m_pEnemies->Destroy();	// �j��.
		delete m_pEnemies;	// �폜.
		m_pEnemies = NULL;	// NULL���Z�b�g.
	}

}