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

// �G�l�~�[�Y�f�[�^���t�@�C���Ƃ��ăG�N�X�|�[�gExportFileEnemies.
BOOL CEnemyMap::ExportFileEnemies(LPCTSTR lpctszFileName){

	// �G�l�~�[�Y�������.
	if (m_pEnemies != NULL){	// NULL�łȂ�.
		if (m_pEnemies->m_vecEnemiesList.size() > 0){	// 0���傫���Ȃ�.
			// �o�C�i���t�@�C���̍쐬.
			CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFile�I�u�W�F�N�gpBinaryFile�̐���.
			int n = m_pEnemies->m_vecEnemiesList.size();	// �ŏ��ɃG�l�~�[�����擾.
			pBinaryFile->Set((BYTE *)&n, sizeof(int));	// �G�l�~�[������������.
			pBinaryFile->Write(lpctszFileName);	// lpctszFileName�ɏ�������.
			for (int i = 0; i < m_pEnemies->m_vecEnemiesList.size(); i++){	// �G�l�~�[�Y�̃T�C�Y�J��Ԃ�.
				CEnemy *pEnemy = m_pEnemies->m_vecEnemiesList[i];	// pEnemy�擾.
				pBinaryFile->Set((BYTE *)&pEnemy->m_x, sizeof(int));	// m_x.
				pBinaryFile->Write();	// ��������.
				pBinaryFile->Set((BYTE *)&pEnemy->m_y, sizeof(int));	// m_y.
				pBinaryFile->Write();	// ��������.
				pBinaryFile->Set((BYTE *)&pEnemy->m_iWidth, sizeof(int));	// m_iWidth.
				pBinaryFile->Write();	// ��������.
				pBinaryFile->Set((BYTE *)&pEnemy->m_iHeight, sizeof(int));	// m_iHeight.
				pBinaryFile->Write();	// ��������.
				int iSize = pEnemy->m_vecpSharedObjectList.size();	// iSize�̎擾.
				pBinaryFile->Set((BYTE *)&iSize, sizeof(int));	// iSize�̃Z�b�g.
				pBinaryFile->Write();	// ��������.
				for (int j = 0; j < iSize; j++){	// iSize���J��Ԃ�.
					CSharedObject *pSO = pEnemy->m_vecpSharedObjectList[j];	// pSO�擾.
					pBinaryFile->Set((BYTE *)&pSO->m_sx, sizeof(int));	// m_sx.
					pBinaryFile->Write();	// ��������.
					pBinaryFile->Set((BYTE *)&pSO->m_sy, sizeof(int));	// m_sy.
					pBinaryFile->Write();	// ��������.
					pBinaryFile->Set((BYTE *)&pSO->m_iWidth, sizeof(int));	// m_iWidth.
					pBinaryFile->Write();	// ��������.
					pBinaryFile->Set((BYTE *)&pSO->m_iHeight, sizeof(int));	// m_iHeight.
					pBinaryFile->Write();	// ��������.
					pBinaryFile->Set((BYTE *)&pSO->m_nID, sizeof(int));	// m_nID.
					pBinaryFile->Write();	// ��������.
					CSharedObject *pMask = pEnemy->m_vecpMaskList[j];	// pMask�擾.
					pBinaryFile->Set((BYTE *)&pMask->m_sx, sizeof(int));	// m_sx.
					pBinaryFile->Write();	// ��������.
					pBinaryFile->Set((BYTE *)&pMask->m_sy, sizeof(int));	// m_sy.
					pBinaryFile->Write();	// ��������.
					pBinaryFile->Set((BYTE *)&pMask->m_iWidth, sizeof(int));	// m_iWidth.
					pBinaryFile->Write();	// ��������.
					pBinaryFile->Set((BYTE *)&pMask->m_iHeight, sizeof(int));	// m_iHeight.
					pBinaryFile->Write();	// ��������.
					pBinaryFile->Set((BYTE *)&pMask->m_nID, sizeof(int));	// m_nID.
					pBinaryFile->Write();	// ��������.
				}
			}
			delete pBinaryFile;	// pBinaryFile�̏I������.
			return TRUE;	// TRUE.
		}
	}
	return FALSE;	// FALSE.

}

// �G�l�~�[�Y�f�[�^���t�@�C������C���|�[�gImportFileEnemies.
BOOL CEnemyMap::ImportFileEnemies(LPCTSTR lpctszFileName){

	// �G�l�~�[�Y���Ȃ����.
	if (m_pEnemies == NULL){
		m_pEnemies = new CEnemies(m_pScene);	// m_pEnemies�̐���.
	}

	// �o�C�i���t�@�C���̓ǂݍ���.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFile�I�u�W�F�N�gpBinaryFile�̐���.
	pBinaryFile->Read(lpctszFileName, 0, sizeof(int));	// pBinaryFile->Read�œǂݍ���.
	int n = *(int *)pBinaryFile->m_pBytes;	// n.
	for (int i = 0; i < n; i++){	// n�J��Ԃ�. 
		CEnemy *pEnemy = new CEnemy(m_pScene);	// pEnemy�𐶐�.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
		pEnemy->m_x = *(int *)pBinaryFile->m_pBytes;	// x.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
		pEnemy->m_y = *(int *)pBinaryFile->m_pBytes;	// y.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
		pEnemy->m_iWidth = *(int *)pBinaryFile->m_pBytes;	// iWidth.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
		pEnemy->m_iHeight = *(int *)pBinaryFile->m_pBytes;	// iHeight.
		int iSize = 0;	// �A�j���[�V�������X�g�T�C�Y.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
		iSize = *(int *)pBinaryFile->m_pBytes;	// iSize.
		for (int j = 0; j < iSize; j++){	// iSize���J��Ԃ�.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
			int iSOSX = *(int *)pBinaryFile->m_pBytes;	// sx
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
			int iSOSY = *(int *)pBinaryFile->m_pBytes;	// sy.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
			int iSOWidth = *(int *)pBinaryFile->m_pBytes;	// iWidth.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
			int iSOHeight = *(int *)pBinaryFile->m_pBytes;	// iHeight.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
			int iSOnID = *(int *)pBinaryFile->m_pBytes;	// nID.
			pEnemy->Add(iSOSX, iSOSY, iSOWidth, iSOHeight, iSOnID);	// �C���[�W�ǉ�.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
			int iMaskSX = *(int *)pBinaryFile->m_pBytes;	// sx
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
			int iMaskSY = *(int *)pBinaryFile->m_pBytes;	// sy.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
			int iMaskWidth = *(int *)pBinaryFile->m_pBytes;	// iWidth.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
			int iMaskHeight = *(int *)pBinaryFile->m_pBytes;	// iHeight.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
			int iMasknID = *(int *)pBinaryFile->m_pBytes;	// nID.
			pEnemy->AddMask(iMaskSX, iMaskSY, iMaskWidth, iMaskHeight, iMasknID);	// �}�X�N�ǉ�.
		}
		m_pEnemies->m_vecEnemiesList.push_back(pEnemy);	
	}
	delete pBinaryFile;	// �t�@�C�����폜.(�����ŕ���.)
	return TRUE;	// TRUE.

}

// �G�l�~�[�Y�f�[�^�����\�[�X�Ƃ��ăC���|�[�gImportResourceEnemies.
BOOL CEnemyMap::ImportResourceEnemies(int nID){

	// �G�l�~�[�Y���Ȃ����.
	if (m_pEnemies == NULL){
		m_pEnemies = new CEnemies(m_pScene);	// m_pEnemies�̐���.
	}

	// �o�C�i�����\�[�X����ǂݍ���.
	CBinaryResource *pBinaryResource = new CBinaryResource();
	pBinaryResource->Load(m_pScene->m_pMainWnd->m_hWnd, nID, _T("BIN"));	// pBinaryResource->Load�Ń��[�h.
	int n = *(int *)pBinaryResource->Get(sizeof(int));	// ���\�[�X����n�擾.
	for (int i = 0; i < n; i++){	// n�J��Ԃ�.
		CEnemy *pEnemy = new CEnemy(m_pScene);	// pEnemy�𐶐�.
		pEnemy->m_x = *(int *)pBinaryResource->Get(sizeof(int));	// ���\�[�X����m_x�擾.
		pEnemy->m_y = *(int *)pBinaryResource->Get(sizeof(int));	// ���\�[�X����m_y�擾.
		pEnemy->m_iWidth = *(int *)pBinaryResource->Get(sizeof(int));	// m_iWidth.
		pEnemy->m_iHeight = *(int *)pBinaryResource->Get(sizeof(int));	// m_iHeight.
		int iSize = 0;	// �A�j���[�V�������X�g�T�C�Y.
		iSize = *(int *)pBinaryResource->Get(sizeof(int));	// ���\�[�X����iSize�擾.
		for (int j = 0; j < iSize; j++){	// iSize���J��Ԃ�.
			int iSOSX = *(int *)pBinaryResource->Get(sizeof(int));	// iSOSX���擾.
			int iSOSY = *(int *)pBinaryResource->Get(sizeof(int));	// iSOSY���擾.
			int iSOWidth = *(int *)pBinaryResource->Get(sizeof(int));	// iSOWidth���擾.
			int iSOHeight = *(int *)pBinaryResource->Get(sizeof(int));	// iSOHeight���擾.
			int iSOnID = *(int *)pBinaryResource->Get(sizeof(int));	// iSOnID���擾.
			pEnemy->Add(iSOSX, iSOSY, iSOWidth, iSOHeight, iSOnID);	// �C���[�W�ǉ�.
			int iMaskSX = *(int *)pBinaryResource->Get(sizeof(int));	// iMaskSX���擾.
			int iMaskSY = *(int *)pBinaryResource->Get(sizeof(int));	// iMaskSY���擾.
			int iMaskWidth = *(int *)pBinaryResource->Get(sizeof(int));	// iMaskWidth���擾.
			int iMaskHeight = *(int *)pBinaryResource->Get(sizeof(int));	// iMaskHeight���擾.
			int iMasknID = *(int *)pBinaryResource->Get(sizeof(int));	// iMasknID���擾.
			pEnemy->AddMask(iMaskSX, iMaskSY, iMaskWidth, iMaskHeight, iMasknID);	// �}�X�N�ǉ�.
		}
		m_pEnemies->m_vecEnemiesList.push_back(pEnemy);		// pEnemy�̒ǉ�.
	}
	// �o�C�i�����\�[�X�I�u�W�F�N�g�̔j��.
	delete pBinaryResource;	// pBinaryResource�̏I������.
	return TRUE;	// TRUE��Ԃ�.

}

// �G�l�~�[�}�b�v�f�[�^���t�@�C���Ƃ��ăG�N�X�|�[�gExportFileEnemyMapData.
BOOL CEnemyMap::ExportFileEnemyMapData(LPCTSTR lpctszFileName){

	// �G�l�~�[�}�b�v�f�[�^���t�@�C���ɏ�������.
	// �o�C�i���t�@�C���̍쐬.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFile�I�u�W�F�N�gpBinaryFile�̐���.
	int n = m_vecEnemyMapDataList.size();	// �T�C�Y��n�Ƃ���.
	pBinaryFile->Set((BYTE *)&n, sizeof(int));	// �G�l�~�[�z�u�����Z�b�g.
	pBinaryFile->Write(lpctszFileName);	// lpctszFileName�ɏ�������.
	for (int i = 0; i < n; i++){	// ���X�g�̃T�C�Y���J��Ԃ�.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_x, sizeof(int));	// m_x.
		pBinaryFile->Write();	// ��������.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_y, sizeof(int));	// m_y.
		pBinaryFile->Write();	// ��������.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_nEnemyNo, sizeof(int));	// m_nEnemyNo.
		pBinaryFile->Write();	// ��������.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_nState, sizeof(int));	// m_nState.
		pBinaryFile->Write();	// ��������.
	}
	delete pBinaryFile;	// �폜.
	return TRUE;	// TRUE��Ԃ�.

}

// �G�l�~�[�}�b�v�f�[�^���t�@�C������C���|�[�gImportFileEnemyMapData.
BOOL CEnemyMap::ImportFileEnemyMapData(LPCTSTR lpctszFileName){

	// �G�l�~�[�}�b�v�f�[�^���t�@�C������ǂݍ���.
	// �o�C�i���t�@�C���̓ǂݍ���.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFile�I�u�W�F�N�gpBinaryFile�̐���.
	pBinaryFile->Read(lpctszFileName, 0, sizeof(int));	// pBinaryFile->Read�œǂݍ���.
	int n = *(int *)pBinaryFile->m_pBytes;	// n.
	for (int i = 0; i < n; i++){	// n�J��Ԃ�.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
		int x = *(int *)pBinaryFile->m_pBytes;	// x.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
		int y = *(int *)pBinaryFile->m_pBytes;	// y.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
		int iEnemyNo = *(int *)pBinaryFile->m_pBytes;	// iEnemyNo.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
		int iState = *(int *)pBinaryFile->m_pBytes;	// iState.
		DeployEnemy(x, y, iEnemyNo, iState);	// DeployEnemy�ŃG�l�~�[�}�b�v�f�[�^�ɒǉ�.
	}
	delete pBinaryFile;	// �폜.
	return TRUE;	// TRUE��Ԃ�.

}

// �G�l�~�[�}�b�v�f�[�^�����\�[�X����C���|�[�gImportResourceEnemyMapData.
BOOL CEnemyMap::ImportResourceEnemyMapData(int nID){

	// �o�C�i�����\�[�X����ǂݍ���.
	CBinaryResource *pBinaryResource = new CBinaryResource();
	pBinaryResource->Load(m_pScene->m_pMainWnd->m_hWnd, nID, _T("BIN"));	// pBinaryResource->Load�Ń��[�h.
	int n = *(int *)pBinaryResource->Get(sizeof(int));	// ���\�[�X����n�擾.
	for (int i = 0; i < n; i++){	// n�J��Ԃ�.
		int x = *(int *)pBinaryResource->Get(sizeof(int));	// x.
		int y = *(int *)pBinaryResource->Get(sizeof(int));	// y.
		int iEnemyNo = *(int *)pBinaryResource->Get(sizeof(int));	// iEnemyNo.
		int iState = *(int *)pBinaryResource->Get(sizeof(int));	// iState.
		DeployEnemy(x, y, iEnemyNo, iState);	// DeployEnemy�ŃG�l�~�[�}�b�v�f�[�^�ɒǉ�.
	}
	// �o�C�i�����\�[�X�I�u�W�F�N�g�̔j��.
	delete pBinaryResource;	// pBinaryResource�̏I������.
	return TRUE;	// TRUE��Ԃ�.

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