// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Player.h"	// CPlayer
#include "Shot.h"	// CShot
#include "GameScene.h"	// CGameScene
#include "EnemyMap.h"	// CEnemyMap
#include "resource.h"	// ���\�[�X.

// �R���X�g���N�^CPlayer
CPlayer::CPlayer() : CCharacter(){

	// �����o�̏�����.
	m_bDown = FALSE;	// m_bDown��FALSE���Z�b�g.
	m_bUp = FALSE;	// m_bUp��FALSE���Z�b�g.
	m_bRight = FALSE;	// m_bRight��FALSE���Z�b�g.
	m_bLeft = FALSE;	// m_bLeft��FALSE���Z�b�g.
	m_iNo = 0;	// m_iNo��0���Z�b�g.
	m_vecpShotList.clear(); // m_vecpShotList.clear�ŃN���A.
	m_iShotIdx = 0;	// m_iShotIdx��0���Z�b�g.
	m_nState = 0;	// m_nState��0���Z�b�g.

}

// �f�X�g���N�^CPlayer(CScene *pScene)
CPlayer::CPlayer(CScene *pScene) : CCharacter(pScene){

	// �����o�̏�����.
	m_bDown = FALSE;	// m_bDown��FALSE���Z�b�g.
	m_bUp = FALSE;	// m_bUp��FALSE���Z�b�g.
	m_bRight = FALSE;	// m_bRight��FALSE���Z�b�g.
	m_bLeft = FALSE;	// m_bLeft��FALSE���Z�b�g.
	m_iNo = 0;	// m_iNo��0���Z�b�g.
	m_vecpShotList.clear(); // m_vecpShotList.clear�ŃN���A.
	m_iShotIdx = 0;	// m_iShotIdx��0���Z�b�g.
	m_nState = 0;	// m_nState��0���Z�b�g.

}

// �f�X�g���N�^~CPlayer()
CPlayer::~CPlayer(){

	// �����o�̏I������.
	m_iNo = 0;	// m_iNo��0���Z�b�g.

	// �N���A
	Clear();	// Clear�Ńt���O�̃N���A.

	// �j��.
	Destroy();	// Destroy�Ŕj��.

}

// �L�����N�^�[�̔j��Destroy.
void CPlayer::Destroy(){

	// �V���b�g�̔j��.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpShotList.begin(); itor != m_vecpShotList.end(); itor++){	// ���X�g�S�Ă̔j��.
		if ((*itor) != NULL){	// (*itor)��NULL����Ȃ���.
			(*itor)->Destroy();	// (*itor)->Destroy�Ŕj��.
			delete (*itor);	// delete��(*Itor)��j��.
			(*itor) = NULL;	// NULL���Z�b�g.
		}
	}
	m_vecpShotList.clear();	// �N���A.
	m_nState = 0;	// m_nState��0���Z�b�g.

	// �e�N���X�̃����o�֐�.
	CCharacter::Destroy();	// CCharacter::Destroy�Ŕj��.

}

// �}�b�v�̈ړ���Ԃ��N���A.
void CPlayer::Clear(){

	// �t���O�̃N���A.
	m_bDown = FALSE;	// m_bDown��FALSE���Z�b�g.
	m_bUp = FALSE;	// m_bUp��FALSE���Z�b�g.
	m_bRight = FALSE;	// m_bRight��FALSE���Z�b�g.
	m_bLeft = FALSE;	// m_bLeft��FALSE���Z�b�g.
	m_bShot = FALSE;	// m_bShot��FALSE���Z�b�g.

}

// �}�b�v�̎��_�����Ɉړ�Down.(�}�b�v���̂͏�Ɉړ�.)
void CPlayer::Down(){

	// ���̃t���O.
	m_bDown = TRUE;	// m_bDown��TRUE���Z�b�g.

}

// �}�b�v�̎��_����Ɉړ�Up.(�}�b�v���͉̂��Ɉړ�.)
void CPlayer::Up(){

	// ��̃t���O.
	m_bUp = TRUE;	// m_bUp��TRUE���Z�b�g.

}

// �}�b�v�̎��_���E�Ɉړ�Right.(�}�b�v���͍̂��Ɉړ�.)
void CPlayer::Right(){

	// �E�̃t���O.
	m_bRight = TRUE;	// m_bRight��TRUE���Z�b�g.

}

// �}�b�v�̎��_�����Ɉړ�Ledt.(�}�b�v���͉̂E�Ɉړ�.))
void CPlayer::Left(){

	// ���̃t���O.
	m_bLeft = TRUE;	// m_bLeft��TRUE���Z�b�g.

}

// �V���b�g����.
void CPlayer::Shot(){

	// �V���b�g�t���O.
	m_bShot = TRUE;	// m_bShot��TRUE���Z�b�g.

}

// ����������Proc.
int CPlayer::Proc(){

	// ��.
	if (m_bDown){	// ���������ꂽ��.
		m_y++;	// m_y�𑝂₷.
		if (m_y >= 480 - 32){	// �����.
			m_y = 480 - 32;	// ���.
		}
	}
	// ��.
	if (m_bUp){	// �オ�����ꂽ��.
		m_y--;	// m_y�����炷.
		if (m_y <= 0){		// ������.
			m_y = 0;	// ����.
		}
	}
	Set(0);	// �������Z�b�g.
	// �E.
	if (m_bRight){	// �E�������ꂽ��.
		m_x++;	// m_x�𑝂₷.
		if (m_x >= 640 - 32){	// �����.
			m_x = 640 - 32;	// ���.
		}
		Set(1);	// �E���Z�b�g.
	}
	// ��.
	if (m_bLeft){	// ���������ꂽ��.
		m_x--;	// m_x�����炷.
		if (m_x <= 0){		// ������.
			m_x = 0;	// ����.
		}
		Set(2);	// �����Z�b�g.
	}

#if 1
	// ���[�v.
	// ����.
	for (int k = 0, m = m_iShotIdx; k < m_vecpShotList.size(); k++){
		int iState = ((CShot *)m_vecpShotList[m])->Get();	// iState�擾.
		if (iState == 0){	// �V���b�g��Ԃ�0�Ȃ�.
			if (GetState() == 0){	// �v���C���[�̏�Ԃ�0�Ȃ�.
				if (m_bShot){	// �V���b�g�������ꂽ��.
					((CShot *)m_vecpShotList[m])->Set(1);	// 1���Z�b�g.
					m_iShotIdx++;	// 1���₷.
					if (m_iShotIdx >= m_vecpShotList.size()){	// �T�C�Y�ȏ�.
						m_iShotIdx = 0;	// 0�ɖ߂�.
					}
					break;	// ������.
				}
			}
		}
		else if (iState == 1){
			((CShot *)m_vecpShotList[m])->m_y--;	// y���W��1���炷.
			if (((CShot *)m_vecpShotList[m])->m_y <= -32){	// -32�ȉ�.
				((CShot *)m_vecpShotList[m])->Set(2);
			}
		}
		m++;
		if (m >= m_vecpShotList.size()){
			m = 0;
		}
	}
	// �����蔻��.
	CGameScene *pGameScene = (CGameScene *)m_pScene;	// pGameScene�ɃL���X�g.
	CEnemyMap *pEnemyMap = pGameScene->m_pEnemyMap;	// pEnemyMap���擾.
	CEnemies *pEnemies = pEnemyMap->m_pEnemies;	// pEnemies�̎擾.
	CMap *pMap = pGameScene->m_pMap;	// pMap���擾.
	int n = pEnemyMap->m_vecEnemyMapDataList.size();	// �T�C�Y���擾.
	for (int i = 0; i < n; i++){	// n�J��Ԃ�.
		// �G�ƃV���b�g�̓����蔻��.
		for (int j = 0; j < m_vecpShotList.size(); j++){
			int iState = ((CShot *)m_vecpShotList[j])->Get();	// iState�擾.
			if (iState == 1){	// 1�Ȃ�.
				if (pEnemyMap->m_vecEnemyMapDataList[i]->m_nState == 1){	// �\��.
					int ex = pEnemyMap->m_vecEnemyMapDataList[i]->m_x - pMap->m_iScreenRX;	// �G�̉�ʍ��Wex.(������͉E����, �Ȃ̂Ő�.)
					int ey = pMap->m_iScreenUY - pEnemyMap->m_vecEnemyMapDataList[i]->m_y;	// �G�̉�ʍ��Wey.(������͏オ��, �Ȃ̂ŋt.)
					int ew = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[i]->m_nEnemyNo]->m_iWidth;	// ��.
					int eh = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[i]->m_nEnemyNo]->m_iHeight;	// ����.
					int sx = ((CShot *)m_vecpShotList[j])->m_x;	// �V���b�gx.
					int sy = ((CShot *)m_vecpShotList[j])->m_y;	// �V���b�gy.
					int sw = ((CShot *)m_vecpShotList[j])->m_iWidth;	// ��.
					int sh = ((CShot *)m_vecpShotList[j])->m_iHeight;	// ����.
					if ((ex <= sx && sx <= ex + ew && ey <= sy && sy <= ey + eh)		// �V���b�g�̍���.
						|| (sx <= ex && ex <= sx + sw && ey <= sy && sy <= ey + eh)		// �V���b�g�̉E��.
						|| (ex <= sx && sx <= ex + ew && sy <= ey && ey <= sy + sh)		// �V���b�g�̍���.
						|| (sx <= ex && ex <= sx + sw && sy <= ey && ey <= sy + sh))	// �V���b�g�̉E��.
					{
						((CShot *)m_vecpShotList[j])->Set(2);	// 2�ɃZ�b�g.
						pEnemyMap->m_vecEnemyMapDataList[i]->m_nLife--;	// ���C�t�����炷.
						if (pEnemyMap->m_vecEnemyMapDataList[i]->m_nLife <= 0){	// 0�ȉ�.
							pEnemyMap->m_vecEnemyMapDataList[i]->m_nState = 3;	// ���3.
						}
					}
				}
			}
			else if (iState == 2){	// 2�Ȃ�.
				((CShot *)m_vecpShotList[j])->Set(0);	// 0�Ƀ��Z�b�g.
			}
		}
		// �G�Ǝ��@�̓����蔻��.
		if (pEnemyMap->m_vecEnemyMapDataList[i]->m_nState == 1){	// �\��.
			int ex = pEnemyMap->m_vecEnemyMapDataList[i]->m_x - pMap->m_iScreenRX;	// �G�̉�ʍ��Wex.(������͉E����, �Ȃ̂Ő�.)
			int ey = pMap->m_iScreenUY - pEnemyMap->m_vecEnemyMapDataList[i]->m_y;	// �G�̉�ʍ��Wey.(������͏オ��, �Ȃ̂ŋt.)
			int ew = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[i]->m_nEnemyNo]->m_iWidth;	// ��.
			int eh = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[i]->m_nEnemyNo]->m_iHeight;	// ����.
			int px = m_x;	// m_x.
			int py = m_y;	// m_y.
			int pw = m_iWidth;	// m_iWidth.
			int ph = m_iHeight;	// m_iHeight.
			if ((ex <= px && px <= ex + ew && ey <= py && py <= ey + eh)		// �v���C���[�̍���.
				|| (px <= ex && ex <= px + pw && ey <= py && py <= ey + eh)		// �v���C���[�̉E��.
				|| (ex <= px && px <= ex + ew && py <= ey && ey <= py + ph)		// �v���C���[�̍���.
				|| (px <= ex && ex <= px + pw && py <= ey && ey <= py + ph))	// �v���C���[�̉E��.
			{
				SetState(1);	// 1�ɂ���.
			}
		}
	}
#else
	// �V���b�g�̕`��.
	for (int i = 0, j = m_iShotIdx; i < m_vecpShotList.size(); i++){
		int iState = ((CShot *)m_vecpShotList[j])->Get();	// iState�擾.
		if (iState == 0){	// 0�Ȃ�.
			if (m_bShot){	// �V���b�g�������ꂽ��.
				((CShot *)m_vecpShotList[j])->Set(1);	// 1���Z�b�g.
				m_iShotIdx = j + 1;
				if (m_iShotIdx >= m_vecpShotList.size()){	// �T�C�Y�ȏ�.
					m_iShotIdx = 0;	// 0�ɖ߂�.
				}
				break;	// ������.
			}
		}
		else if (iState == 1){	// 1�Ȃ�.
			((CShot *)m_vecpShotList[j])->m_y--;	// y���W��1���炷.
			if (((CShot *)m_vecpShotList[j])->m_y <= -32){	// -32�ȉ�.
				((CShot *)m_vecpShotList[j])->Set(2);
			}
			else{	// �V���b�g���L���ȏꍇ.
				CGameScene *pGameScene = (CGameScene *)m_pScene;	// pGameScene�ɃL���X�g.
				CEnemyMap *pEnemyMap = pGameScene->m_pEnemyMap;	// pEnemyMap���擾.
				CEnemies *pEnemies = pEnemyMap->m_pEnemies;	// pEnemies�̎擾.
				CMap *pMap = pGameScene->m_pMap;	// pMap���擾.
				int n = pEnemyMap->m_vecEnemyMapDataList.size();	// �T�C�Y���擾.
				for (int k = 0; k < n; k++){	// n�J��Ԃ�.
					if (pEnemyMap->m_vecEnemyMapDataList[k]->m_nState == 1){	// �\��.
						int ex = pEnemyMap->m_vecEnemyMapDataList[k]->m_x - pMap->m_iScreenRX;	// �G�̉�ʍ��Wex.(������͉E����, �Ȃ̂Ő�.)
						int ey = pMap->m_iScreenUY - pEnemyMap->m_vecEnemyMapDataList[k]->m_y;	// �G�̉�ʍ��Wey.(������͏オ��, �Ȃ̂ŋt.)
						int ew = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[k]->m_nEnemyNo]->m_iWidth;	// ��.
						int eh = pEnemies->m_vecEnemiesList[pEnemyMap->m_vecEnemyMapDataList[k]->m_nEnemyNo]->m_iHeight;	// ����.
						int sx = ((CShot *)m_vecpShotList[j])->m_x;	// �V���b�gx.
						int sy = ((CShot *)m_vecpShotList[j])->m_y;	// �V���b�gy.
						int sw = ((CShot *)m_vecpShotList[j])->m_iWidth;	// ��.
						int sh = ((CShot *)m_vecpShotList[j])->m_iHeight;	// ����.
						if ((ex <= sx && sx <= ex + ew && ey <= sy && sy <= ey + eh)		// �V���b�g�̍���.
							|| (sx <= ex && ex <= sx + sw && ey <= sy && sy <= ey + eh)		// �V���b�g�̉E��.
							|| (ex <= sx && sx <= ex + ew && sy <= ey && ey <= sy + sh)		// �V���b�g�̍���.
							|| (sx <= ex && ex <= sx + sw && sy <= ey && ey <= sy + sh))	// �V���b�g�̉E��.
						{
							((CShot *)m_vecpShotList[j])->Set(2);	// 2�ɃZ�b�g.
							pEnemyMap->m_vecEnemyMapDataList[k]->m_nLife--;	// ���C�t�����炷.
							if (pEnemyMap->m_vecEnemyMapDataList[k]->m_nLife <= 0){	// 0�ȉ�.
								pEnemyMap->m_vecEnemyMapDataList[k]->m_nState = 3;	// ���3.
							}
						}
					}
				}
			}
		}
		else if (iState == 2){	// 2�Ȃ�.
			((CShot *)m_vecpShotList[j])->Set(0);	// 0�Ƀ��Z�b�g.
		}
		j++;	// j�𑝂₷.
		if (j >= m_vecpShotList.size()){	// j���T�C�Y�ȏ�.
			j = 0;	// 0�ɖ߂�.
		}
	}
#endif

	// �V�[���p���Ȃ�0.
	return 0;	// 0��Ԃ�.

}

// �ʒu���Z�b�g����Set.
void CPlayer::Set(int x, int y){

	// �����o�̃Z�b�g.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.

}

// �A�j���[�V�������Z�b�g����Set.
void CPlayer::Set(int iNo){

	// �A�j���[�V�����̃Z�b�g.
	m_iNo = iNo;	// m_iNo��iNo���Z�b�g.

}

// ��Ԃ��Z�b�g����SetState.
void CPlayer::SetState(int iState){

	// �����������o�ɃZ�b�g.
	m_nState = iState;	// m_nState��iState���Z�b�g.

}

// ��Ԃ��擾����GetState.
int CPlayer::GetState(){

	// ��Ԃ�Ԃ�.
	return m_nState;	// m_nState��Ԃ�.
	
}

// �`�������Draw.
void CPlayer::Draw(){

	// �`��.
	int iState = GetState();	// ��Ԃ��擾.
	if (iState == 0){	// iState��0�Ȃ�.
		//CCharacter::Draw(m_x, m_y, m_iNo);	// CCharacter::Draw�ŕ`��.
		CCharacter::DrawSprite(m_x, m_y, m_iNo);	// CCharacter::DrawSprite�ŕ`��.
	}

}

// �V���b�g��`�悷��DrawShot.
void CPlayer::DrawShot(){

	// �V���b�g�̕`��.
	for (int i = 0; i < m_vecpShotList.size(); i++){
		int iState = ((CShot *)m_vecpShotList[i])->Get();	// iState�擾.
		if (iState == 1){	// ��Ԃ�1�Ȃ�`��.
			((CShot *)m_vecpShotList[i])->DrawSprite(((CShot *)m_vecpShotList[i])->m_x, ((CShot *)m_vecpShotList[i])->m_y, 0);	// �`��.
		}
		else if (iState == 0){	// 0�Ȃ玩�@�̍��W.
			((CShot *)m_vecpShotList[i])->Set(m_x + 32 / 2 - 4 / 2, m_y);
			//((CShot *)m_vecpShotList[i])->DrawSprite(((CShot *)m_vecpShotList[i])->m_x, ((CShot *)m_vecpShotList[i])->m_y, 0);	// �`��.
		}
	}

}

// �V���b�g�̍쐬CreateShot.
void CPlayer::CreateShot(int iSize){

	// �V���b�g�̍쐬.
	for (int i = 0; i < iSize; i++){	// iSize�J��Ԃ�.
		CShot *pShot = new CShot(m_pScene);	// CShot�I�u�W�F�N�g�̍쐬.
		pShot->Add(0, 32, 4, 32, IDB_SHARED2);	// �C���[�W�ǉ�.
		pShot->AddMask(320 + 0, 32, 4, 32, IDB_SHARED2);	// �C���[�W�ǉ�.
		pShot->Set(m_x + 32 / 2 - 4 / 2, m_y);	// pShot->Set��m_x, m_y���Z�b�g.
		pShot->Set(0);	// ���0���Z�b�g.
		m_vecpShotList.push_back(pShot);	// m_vecpShotList.push_back�Œǉ�.
	}

}