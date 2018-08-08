// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "resource.h"	// ���\�[�X
#include "GameScene.h"	// CGameScene

// �R���X�g���N�^CGameScene
CGameScene::CGameScene() : CScene(){

	// �����o�̏�����.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1��NULL���Z�b�g.
	m_pSharedObject2 = NULL;	// m_pSharedObject2��NULL���Z�b�g.
	m_pSharedObject3 = NULL;	// m_pSharedObject3��NULL���Z�b�g.
#endif
	m_pMap = NULL;	// m_pMap��NULL���Z�b�g.
	//m_pCharacter = NULL;	// m_pCharacter��NULL���Z�b�g.
	//m_pEnemy = NULL;	// m_pEnemy��NULL���Z�b�g.
	m_pEnemyMap = NULL;	// m_pEnemyMap��NULL���Z�b�g.
	m_pPlayer = NULL;	// m_pPlayer��NULL���Z�b�g.
	m_pGameTimeBox = NULL;	// m_pGameTimeBox��NULL�ŏ�����.
	m_pStatusBox = NULL;	// m_pStatusBox��NULL�ŏ�����.
	m_pMessageArea = NULL;	// m_pMessageArea��NULL�ŏ�����.

}

// �R���X�g���N�^CGameScene(const CWindow *pWnd)
CGameScene::CGameScene(const CWindow *pWnd) : CScene(pWnd){

	// �����o�̏�����.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1��NULL���Z�b�g.
	m_pSharedObject2 = NULL;	// m_pSharedObject2��NULL���Z�b�g.
	m_pSharedObject3 = NULL;	// m_pSharedObject3��NULL���Z�b�g.
#endif
	m_pMap = NULL;	// m_pMap��NULL���Z�b�g.
	//m_pCharacter = NULL;	// m_pCharacter��NULL���Z�b�g.
	//m_pEnemy = NULL;	// m_pEnemy��NULL���Z�b�g.
	m_pEnemyMap = NULL;	// m_pEnemyMap��NULL���Z�b�g.
	m_pPlayer = NULL;	// m_pPlayer��NULL���Z�b�g.
	m_pGameTimeBox = NULL;	// m_pGameTimeBox��NULL�ŏ�����.
	m_pStatusBox = NULL;	// m_pStatusBox��NULL�ŏ�����.
	m_pMessageArea = NULL;	// m_pMessageArea��NULL�ŏ�����.

}

// �R���X�g���N�^CGameScene(const CWindow *pWnd, CGameTime *pTime)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime) : CScene(pWnd, pTime){

	// �����o�̏�����.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1��NULL���Z�b�g.
	m_pSharedObject2 = NULL;	// m_pSharedObject2��NULL���Z�b�g.
	m_pSharedObject3 = NULL;	// m_pSharedObject3��NULL���Z�b�g.
#endif
	m_pMap = NULL;	// m_pMap��NULL���Z�b�g.
	//m_pCharacter = NULL;	// m_pCharacter��NULL���Z�b�g.
	//m_pEnemy = NULL;	// m_pEnemy��NULL���Z�b�g.
	m_pEnemyMap = NULL;	// m_pEnemyMap��NULL���Z�b�g.
	m_pPlayer = NULL;	// m_pPlayer��NULL���Z�b�g.
	m_pGameTimeBox = NULL;	// m_pGameTimeBox��NULL�ŏ�����.
	m_pStatusBox = NULL;	// m_pStatusBox��NULL�ŏ�����.
	m_pMessageArea = NULL;	// m_pMessageArea��NULL�ŏ�����.

}

// �R���X�g���N�^CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem) : CScene(pWnd, pTime, pSystem){

	// �����o�̏�����.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1��NULL���Z�b�g.
	m_pSharedObject2 = NULL;	// m_pSharedObject2��NULL���Z�b�g.
	m_pSharedObject3 = NULL;	// m_pSharedObject3��NULL���Z�b�g.
#endif
	m_pMap = NULL;	// m_pMap��NULL���Z�b�g.
	//m_pCharacter = NULL;	// m_pCharacter��NULL���Z�b�g.
	//m_pEnemy = NULL;	// m_pEnemy��NULL���Z�b�g.
	m_pEnemyMap = NULL;	// m_pEnemyMap��NULL���Z�b�g.
	m_pPlayer = NULL;	// m_pPlayer��NULL���Z�b�g.
	m_pGameTimeBox = NULL;	// m_pGameTimeBox��NULL�ŏ�����.
	m_pMessageArea = NULL;	// m_pMessageArea��NULL�ŏ�����.

}

// �f�X�g���N�^~CGameScene
CGameScene::~CGameScene(){

}

// �Q�[���I�u�W�F�N�g�̏�����.
int CGameScene::InitGameObjects(){

	// ���N���X�̏�����.
	int iRet = CScene::InitGameObjects();	// CScene::InitGameObjects�ŏ�����.

	// �V�F�A�[�h�C���[�W�o�b�t�@�̒ǉ�.
	m_pSharedImageBuffer->Add(IDB_SHARED1);	// �ǉ�.
	m_pSharedImageBuffer->Add(IDB_SHARED2);	// �ǉ�.
	m_pSharedImageBuffer->Add(IDB_SHARED3);	// �ǉ�.

	// �V�F�A�[�h�I�u�W�F�N�g�̐���.
#if 0
	m_pSharedObject1 = new CSharedObject(this);	// ����.
	m_pSharedObject1->Create(0 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject1->Create�Ő���.
	m_pSharedObject2 = new CSharedObject(this);	// ����.
	m_pSharedObject2->Create(1 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject2->Create�Ő���.
	m_pSharedObject3 = new CSharedObject(this);	// ����.
	m_pSharedObject3->Create(2 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject3->Create�Ő���.
#endif
	m_pMap = new CMap(this);	// CMap�̃I�u�W�F�N�g����.

	// �}�b�v�̕`��.
#if 0
	m_pMap->Create(32, 32, 21, 17);	// Create�Ő���.
#else
	//m_pMap->ImportFile(_T("testmap1.bin"));	// m_pMap->ImportFile�ŃC���|�[�g.
	m_pMap->ImportResource(IDR_TESTMAP1);	// m_pMap->ImportResource�ŃC���|�[�g.
	m_pMap->m_bLoop = TRUE;	// ���[�v.
	m_pMap->m_bLoopX = FALSE;	// �����[�v.
	m_pMap->m_bLoopY = TRUE;	// �c���[�v.
	m_pMap->SetScrollTimer(16);	// 16�~���b��ɃX�N���[��.(����ȏ��FPS�l60�ł͑����Ȃ�Ȃ�.)
#endif

	// �G�l�~�[�̕`��.
	//m_pEnemy = new CEnemy(this);	// CEnemy�I�u�W�F�N�g�𐶐�.
	//m_pEnemy->Add(0, 0, 64, 64, IDB_SHARED3);	// Add�Œǉ�.
	//m_pEnemy->Add(64, 0, 64, 64, IDB_SHARED3);	// Add	�Œǉ�.
	//m_pEnemy->AddMask(320 + 0, 0, 64, 64, IDB_SHARED3);	// AddMask�Œǉ�.
	//m_pEnemy->AddMask(320 + 64, 0, 64, 64, IDB_SHARED3);	// AddMask�Œǉ�.
	//m_pEnemy->Set(640 / 2 - 64 / 2, 0);	// Set�Œ�����ŏ����ʒu���Z�b�g.
	//m_pEnemy->m_iHeight = 64;	// �b��I�ɍ��������Ă���.(���ۂ�Enemies���X�g�ɓ����.)

	// �G�l�~�[�}�b�v�̕`��.
	m_pEnemyMap = new CEnemyMap(this);	// CEnemyMap�I�u�W�F�N�g�𐶐�.
	//m_pEnemyMap->Create();	// �쐬.
#if 1
	// �G�l�~�[�Y�̒ǉ�.
#if 0
	// �G�l�~�[�Y�G�N�X�|�[�g.
	// �G�l�~�[�ǉ�.
	int iEnemyNo = m_pEnemyMap->AddEnemy(640 / 2 - 64 / 2, 0, 64, 64);	// �G�l�~�[�ǉ�.
	// �A�j���[�V�����ǉ�.
	RECT rcImg = {0, 0, 64, 64};	// ����.
	RECT rcMask = {320, 0, 320 + 64, 0 + 64};	// �^�񒆂��獶��.
	m_pEnemyMap->AddEnemyAnimation(iEnemyNo, &rcImg, IDB_SHARED3, &rcMask, IDB_SHARED3);
	m_pEnemyMap->ExportFileEnemies(_T("testenemies1.bin"));	// "testenemies1.bin"�Ƃ��ăG�N�X�|�[�g.
#else
	// �G�l�~�[�Y�C���|�[�g.
	//m_pEnemyMap->ImportFileEnemies(_T("testenemies1.bin"));	// "testenemies1.bin"����C���|�[�g.
	m_pEnemyMap->ImportResourceEnemies(IDR_TESTENEMIES1);	// ���\�[�X����C���|�[�g.
#endif
	// �G�l�~�[�z�u.
#if 0
	m_pEnemyMap->DeployEnemy(200, 600, 0, 1, 0, 1);	// (200, 600)�ɃG�l�~�[0�����C�t1���0�X�R�A1�Ŕz�u.
	m_pEnemyMap->DeployEnemy(400, 1000, 0, 1, 0, 1);	// (400, 1000)�ɃG�l�~�[0�����C�t1���0�X�R�A1�Ŕz�u.
	m_pEnemyMap->DeployEnemy(200, 1400, 0, 1, 0, 1);	// (200, 1400)�ɃG�l�~�[0�����C�t1���0�X�R�A1�Ŕz�u.
	m_pEnemyMap->DeployEnemy(400, 1800, 0, 1, 0, 1);	// (400, 1800)�ɃG�l�~�[0�����C�t1���0�X�R�A1�Ŕz�u.
	m_pEnemyMap->DeployEnemy(200, 2200, 0, 1, 0, 1);	// (200, 2200)�ɃG�l�~�[0�����C�t1���0�X�R�A1�Ŕz�u.
	m_pEnemyMap->DeployEnemy(400, 2600, 0, 1, 0, 1);	// (400, 2600)�ɃG�l�~�[0�����C�t1���0�X�R�A1�Ŕz�u.
	m_pEnemyMap->DeployEnemy(200, 3000, 0, 1, 0, 1);	// (200, 3000)�ɃG�l�~�[0�����C�t1���0�X�R�A1�Ŕz�u.
	m_pEnemyMap->DeployEnemy(400, 3400, 0, 1, 0, 1);	// (400, 3400)�ɃG�l�~�[0�����C�t1���0�X�R�A1�Ŕz�u.
#endif
#endif
	//m_pEnemyMap->ExportFileEnemyMapData(_T("testenemymapdata1.bin"));	// �G�l�~�[�}�b�v�f�[�^���t�@�C���ɃG�N�X�|�[�g.
	//m_pEnemyMap->ImportFileEnemyMapData(_T("testenemymapdata1.bin"));	// �G�l�~�[�}�b�v�f�[�^���t�@�C������C���|�[�g.
	m_pEnemyMap->ImportResourceEnemyMapData(IDR_TESTENEMYMAPDATA1);	// ���\�[�X����C���|�[�g.
	// �v���C���[�̕`��.
#if 1
	m_pPlayer = new CPlayer(this);	// CPlayer�I�u�W�F�N�g�𐶐�.
	m_pPlayer->Add(0, 0, 32, 32, IDB_SHARED2);	// Add�Œǉ�.
	m_pPlayer->Add(32, 0, 32, 32, IDB_SHARED2);	// Add�Œǉ�.
	m_pPlayer->Add(64, 0, 32, 32, IDB_SHARED2);	// Add�Œǉ�.
	m_pPlayer->AddMask(320 + 0, 0, 32, 32, IDB_SHARED2);	// AddMask�Œǉ�.
	m_pPlayer->AddMask(320 + 32, 0, 32, 32, IDB_SHARED2);	// AddMask�Œǉ�.
	m_pPlayer->AddMask(320 + 64, 0, 32, 32, IDB_SHARED2);	// AddMask�Œǉ�.
	m_pPlayer->Set(640 / 2 - 32 / 2, 480 - 32);	// Set�ŏ����ʒu���Z�b�g.
	m_pPlayer->CreateShot(3);	// �V���b�g��3�쐬.
	m_pPlayer->CreateExplosion();	// �G�N�X�v���[�W�������쐬.
#else
	m_pCharacter = new CCharacter(this);	// CCharacter�I�u�W�F�N�g�𐶐�.
	m_pCharacter->Add(0, 0, 32, 32, IDB_SHARED2);	// Add�Œǉ�.
	m_pCharacter->Add(32, 0, 32, 32, IDB_SHARED2);	// Add�Œǉ�.
	m_pCharacter->Add(64, 0, 32, 32, IDB_SHARED2);	// Add�Œǉ�.
#endif

	// �Q�[���^�C���{�b�N�X�̕`��.
	m_pGameTimeBox = new CGameTimeBox(this);	// CGameTimeBox�I�u�W�F�N�g�𐶐�(this��n��.), �|�C���^��m_pGameTimeBox�Ɋi�[.
	m_pGameTimeBox->Create(0, 0, 160, 30, 36, _T("�l�r �S�V�b�N"));	// m_pGameTimeBox->Create�ō쐬.

	// �X�e�[�^�X�{�b�N�X�̕`��.
	m_pStatusBox = new CStatusBox(this);	// CStatusBox�I�u�W�F�N�g�𐶐�(this��n��.), �|�C���^��m_pStatusBox�Ɋi�[.
	m_pStatusBox->Create(320, 0, 160, 30, 24, _T("�l�r �S�V�b�N"));	// m_pStatusBox->Create�ō쐬.

	// ���b�Z�[�W�G���A�̕`��.
	m_pMessageArea = new CMessageArea(this);	// CMessageArea�I�u�W�F�N�g�𐶐�(this��n��.), �|�C���^��m_pMessageArea�Ɋi�[.
	m_pMessageArea->Create(300, 200, 300, 100, 32, _T("�l�r �S�V�b�N"), 0);	// m_pMessageArea->Create�ō쐬.
	
	// iRet.
	return iRet;	// iRet��Ԃ�.

}

// �L�[�{�[�h�̏�����.
int CGameScene::InitKeyboard(){

	// �L�[�{�[�h�I�u�W�F�N�g�̍쐬.
	m_pKeyboard = new CKeyboard();	// CKeyboard�I�u�W�F�N�g���쐬��, �|�C���^��m_pKeyboard�Ɋi�[.
	
	// �Ď��L�[�̒ǉ�.
	m_pKeyboard->AddKey(VK_DOWN);	// ���L�[��ǉ�.
	m_pKeyboard->AddKey(VK_UP);	// ��L�[��ǉ�.
	m_pKeyboard->AddKey(VK_RIGHT);	// �E�L�[��ǉ�.
	m_pKeyboard->AddKey(VK_LEFT);	// ���L�[��ǉ�.
	m_pKeyboard->AddKey('Z');	// Z�L�[��ǉ�.

	// �����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �L�[�{�[�h�̃`�F�b�N.
int CGameScene::CheckKeyboard(){

	// �}�b�v�̃L�[��ԃN���A.
	//m_pMap->Clear();	// �N���A.
	m_pPlayer->Clear();	// �N���A.

	// �L�[��Ԃ̎擾.
	m_pKeyboard->Check();	// m_pKeyboard->Check�ŏ�Ԋm�F.

	// 0�Ԗڂ̃L�[(�����ł͉��L�[.)�������ꂽ��.
	if (m_pKeyboard->IsDown(0)){	// m_pKeyboard->IsDown(0)��TRUE�Ȃ�.
		//m_pMap->Down();	// ��.
		m_pPlayer->Down();	// ��.
	}

	// 1�Ԗڂ̃L�[(�����ł͏�L�[.)�������ꂽ��.
	if (m_pKeyboard->IsDown(1)){	// m_pKeyboard->IsDown(1)��TRUE�Ȃ�.
		//m_pMap->Up();	// ��.
		m_pPlayer->Up();	// ��.
	}

	// 2�Ԗڂ̃L�[(�����ł͉E�L�[.)�������ꂽ��.
	if (m_pKeyboard->IsDown(2)){	// m_pKeyboard->IsDown(2)��TRUE�Ȃ�.
		//m_pMap->Right();	// �E.
		m_pPlayer->Right();	// �E.
	}

	// 3�Ԗڂ̃L�[(�����ł͍��L�[.)�������ꂽ��.
	if (m_pKeyboard->IsDown(3)){	// m_pKeyboard->IsDown(3)��TRUE�Ȃ�.
		//m_pMap->Left();	// ��.
		m_pPlayer->Left();	// ��.
	}

	// 4�Ԗڂ̃L�[(�����ł�Z�L�[.)�������ꂽ�u��.
	if (m_pKeyboard->IsPress(4)){	// m_pKeyboard->IsPress(4)��TRUE�Ȃ�.
		m_pPlayer->Shot();	// �V���b�g.
	}

	// �����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �L�[���͂⎞�ԂȂǂ��珈�����v�Z.
int CGameScene::RunProc(){

	// �}�b�v����.
	if (m_pMap != NULL){	// m_pMap��NULL�łȂ����.
		m_pMap->Proc();	// m_pMap->Proc�ŏ���.
	}

	// �G�l�~�[����.
	//if (m_pEnemy != NULL){	// m_pEnemy��NULL�łȂ����.
	//	m_pEnemy->Proc();	// m_pEnemy->Proc�ŏ���.
	//}

	// �G�l�~�[�}�b�v����.
	if (m_pEnemyMap != NULL){
		m_pEnemyMap->Proc();
	}

	// �v���C���[����.
	if (m_pPlayer != NULL){	// m_pPlayer��NULL�łȂ����.
		int iRet = m_pPlayer->Proc();	// m_pPlayer->Proc�ŏ���.
		if (iRet == 1){	// 1�Ȃ�.
			return 1;	// 1��Ԃ�.
		}
	}

	// �Q�[���^�C���{�b�N�X����.
	if (m_pGameTimeBox != NULL){	// m_pGameTimeBox��NULL�łȂ���.
		m_pGameTimeBox->Proc();	// m_pGameTimeBox->Proc�ŏ���.
	}

	// �����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̕`��.
int CGameScene::DrawGameObjects(){

	// �V�F�A�[�h�I�u�W�F�N�g�̕`��.
#if 0
	m_pSharedObject1->Draw(0 * 32, 0 * 32);	// m_pSharedObject1->Draw�ŕ`��.
	m_pSharedObject2->Draw(1 * 32, 0 * 32);	// m_pSharedObject2->Draw�ŕ`��.
	m_pSharedObject3->Draw(2 * 32, 0 * 32);	// m_pSharedObject3->Draw�ŕ`��.
#endif

	// �}�b�v�̕`��.
	if (m_pMap != NULL){	// m_pMap��NULL�łȂ����.
		m_pMap->Draw();	// m_pMap->Draw�Ń}�b�v��`��.
	}

	// �G�l�~�[�̕`��.
	//if (m_pEnemy != NULL){	// m_pEnemy��NULL�łȂ����.
	//	m_pEnemy->Draw();	// m_pEnemy->Draw�ŃG�l�~�[��`��.
	//}

	// �G�l�~�[�}�b�v�`��.
	if (m_pEnemyMap != NULL){
		m_pEnemyMap->Draw();
	}

	// �L�����̕`��.
#if 1
	if (m_pPlayer != NULL){	// m_pPlayer��NULL�łȂ����.
		m_pPlayer->Draw();	// m_pPlayer->Draw�ŃL������`��.
		m_pPlayer->DrawShot();	// m_pPlayer->DrawShot�ŃV���b�g��`��.
	}
#else
	if (m_pMap->m_bRight){
		m_pCharacter->Draw(0, 0, 1);	// m_pCharacter->Draw�ŃL����(�E)��`��.
	}
	else if (m_pMap->m_bLeft){
		m_pCharacter->Draw(0, 0, 2);	// m_pCharacter->Draw�ŃL����(��)��`��.
	}
	else{
		m_pCharacter->Draw(0, 0, 0);	// m_pCharacter->Draw�ŃL����(��)��`��.
	}
#endif

	// ���b�Z�[�W�G���A�̕`��.
	if (m_pMessageArea != NULL){	// m_pMessageArea��NULL�łȂ���.
		m_pMessageArea->DrawMessage(248, 220, _T("GAME OVER"), RGB(0xff, 0x0, 0x0));	// "GAME OVER"��\��.
	}

	// �Q�[���^�C���{�b�N�X�̕`��.
	if (m_pGameTimeBox != NULL){	// m_pGameTimeBox��NULL�łȂ���.
		m_pGameTimeBox->DrawTime(0, 0, 160, 30, RGB(0x98, 0xfb, 0x98));	// m_pGameTimeBox->DrawTime�Ŏ�����`��.
		//m_pGameTimeBox->DrawFPS(0, 30, 160, 30, RGB(0x98, 0xfb, 0x98));	// m_pGameTimeBox->DrawFPS��FPS��`��.
		m_pGameTimeBox->DrawRunFPS(0, 30, 160, 30, RGB(0x98, 0xfb, 0x98));	// m_pGameTimeBox->DrawRunFPS�Ŏ��sPFS��`��.
		m_pGameTimeBox->DrawFrameIntervalMilliTime(0, 60, 160, 30, RGB(0x98, 0xfb, 0x98));	// m_pGameTimeBox->DrawFrameIntervalMilliTime�Ńt���[���Ԋu��`��.
	}

	// �X�e�[�^�X�{�b�N�X�̕`��.
	if (m_pStatusBox != NULL){	// m_pStatusBox��NULL�łȂ���.
		m_pStatusBox->DrawRest(480, 0, 160, 30, RGB(0x0, 0x0, 0xff));	// m_pStatusBox->DrawRest�Ŏc�@��`��.
		m_pStatusBox->DrawScore(480, 30, 160, 30, RGB(0x0, 0x0, 0xff));	// m_pStatusBox->DrawScore�ŃX�R�A��`��.
	}

	// �}�b�v���̕`��.
	if (m_pMap != NULL){	// m_pMap��NULL�łȂ����.
		m_pMap->DrawScreenRXUY(0, 90, 160, 30, RGB(0x98, 0xfb, 0x98));	// m_pMap->DrawScreenRXUY�ŃX�N���[�����W��`��.
	}

	// �Q�[���I�[�o�[�^�C�}�[�̃f�o�b�O�p.
#if 0
	CGameTime *pTime = this->m_pGameTime;
	DWORD dwNow = pTime->GetSystemTime();
	DWORD t = dwNow - ((CGameScene *)this)->m_pMessageArea->m_dwVisibleTimerStart;
	TCHAR tt[128] = {0};
	_stprintf(tt, _T("%lu"), t);
	((CGameScene *)this)->m_pGameTimeBox->DrawText(400, 300, 100, 100, tt, RGB(0x0, 0x0, 0x0));
#endif

	// ���N���X�̏���.
	return CScene::DrawGameObjects();	// CScene::DrawGameObjects���Ă�.

}

// �Q�[���I�u�W�F�N�g�̏I������.
int CGameScene::ExitGameObjects(){

	// ���b�Z�[�W�G���A�̔j��.
	if (m_pMessageArea != NULL){
		m_pMessageArea->Destroy();	// m_pMessageArea->Destroy�Ŕj��.
		delete m_pMessageArea;	// delete��m_pMessageArea�����.
		m_pMessageArea = NULL;	// m_pMessageArea��NULL���Z�b�g.
	}

	// �X�e�[�^�X�{�b�N�X�̔j��.
	if (m_pStatusBox != NULL){	// m_pStatusBox��NULL�łȂ���.
		m_pStatusBox->Destroy();	// m_pStatusBox->Destroy�Ŕj��.
		delete m_pStatusBox;	// delete��m_pStatusBox�����.
		m_pStatusBox = NULL;	// m_pStatusBox��NULL���Z�b�g.
	}

	// �Q�[���^�C���{�b�N�X�̔j��.
	if (m_pGameTimeBox != NULL){	// m_pGameTimeBox��NULL�łȂ���.
		m_pGameTimeBox->Destroy();	// m_pGameTimeBox->Destroy�Ŕp��.
		delete m_pGameTimeBox;	// delete��m_pGameTimeBox�����.
		m_pGameTimeBox = NULL;	// m_pGameTimeBox��NULL���Z�b�g.
	}

	// �V�F�A�[�h�I�u�W�F�N�g�̔j��.
#if 0
	delete m_pSharedObject1;	// m_pSharedObject1��j��.
	delete m_pSharedObject2;	// m_pSharedObject2��j��.
	delete m_pSharedObject3;	// m_pSharedObject3��j��.
#endif
#if 1
	m_pPlayer->Destroy();	// Destroy�Ŕj��.
	delete m_pPlayer;	// m_pPlayer���폜.
#else
	m_pCharacter->Destroy();	// Destroy�Ŕj��.
	delete m_pCharacter;	// m_pCharacter���폜.
#endif
	//m_pEnemy->Destroy();	// Destroy�Ŕj��.
	//delete m_pEnemy;	// m_pEnemy���폜.
	m_pEnemyMap->Destroy();	// �j��.
	delete m_pEnemyMap;	// �폜.
	m_pMap->Destroy();	// Destroy�Ŕj��.
	delete m_pMap;	// m_pMap���폜.
	m_pMap = NULL;	// m_pMap��NULL���Z�b�g.
	// ���N���X�̏���.
	return CScene::ExitGameObjects();	// CScene::ExitGameObjects�ŏI������.

}