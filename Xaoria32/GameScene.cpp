// ヘッダのインクルード
// 独自のヘッダ
#include "resource.h"	// リソース
#include "GameScene.h"	// CGameScene

// コンストラクタCGameScene
CGameScene::CGameScene() : CScene(){

	// メンバの初期化.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1にNULLをセット.
	m_pSharedObject2 = NULL;	// m_pSharedObject2にNULLをセット.
	m_pSharedObject3 = NULL;	// m_pSharedObject3にNULLをセット.
#endif
	m_pMap = NULL;	// m_pMapにNULLをセット.
	//m_pCharacter = NULL;	// m_pCharacterにNULLをセット.
	//m_pEnemy = NULL;	// m_pEnemyにNULLをセット.
	m_pEnemyMap = NULL;	// m_pEnemyMapにNULLをセット.
	m_pPlayer = NULL;	// m_pPlayerにNULLをセット.
	m_pGameTimeBox = NULL;	// m_pGameTimeBoxをNULLで初期化.
	m_pStatusBox = NULL;	// m_pStatusBoxをNULLで初期化.
	m_pMessageArea = NULL;	// m_pMessageAreaをNULLで初期化.

}

// コンストラクタCGameScene(const CWindow *pWnd)
CGameScene::CGameScene(const CWindow *pWnd) : CScene(pWnd){

	// メンバの初期化.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1にNULLをセット.
	m_pSharedObject2 = NULL;	// m_pSharedObject2にNULLをセット.
	m_pSharedObject3 = NULL;	// m_pSharedObject3にNULLをセット.
#endif
	m_pMap = NULL;	// m_pMapにNULLをセット.
	//m_pCharacter = NULL;	// m_pCharacterにNULLをセット.
	//m_pEnemy = NULL;	// m_pEnemyにNULLをセット.
	m_pEnemyMap = NULL;	// m_pEnemyMapにNULLをセット.
	m_pPlayer = NULL;	// m_pPlayerにNULLをセット.
	m_pGameTimeBox = NULL;	// m_pGameTimeBoxをNULLで初期化.
	m_pStatusBox = NULL;	// m_pStatusBoxをNULLで初期化.
	m_pMessageArea = NULL;	// m_pMessageAreaをNULLで初期化.

}

// コンストラクタCGameScene(const CWindow *pWnd, CGameTime *pTime)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime) : CScene(pWnd, pTime){

	// メンバの初期化.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1にNULLをセット.
	m_pSharedObject2 = NULL;	// m_pSharedObject2にNULLをセット.
	m_pSharedObject3 = NULL;	// m_pSharedObject3にNULLをセット.
#endif
	m_pMap = NULL;	// m_pMapにNULLをセット.
	//m_pCharacter = NULL;	// m_pCharacterにNULLをセット.
	//m_pEnemy = NULL;	// m_pEnemyにNULLをセット.
	m_pEnemyMap = NULL;	// m_pEnemyMapにNULLをセット.
	m_pPlayer = NULL;	// m_pPlayerにNULLをセット.
	m_pGameTimeBox = NULL;	// m_pGameTimeBoxをNULLで初期化.
	m_pStatusBox = NULL;	// m_pStatusBoxをNULLで初期化.
	m_pMessageArea = NULL;	// m_pMessageAreaをNULLで初期化.

}

// コンストラクタCGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem) : CScene(pWnd, pTime, pSystem){

	// メンバの初期化.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1にNULLをセット.
	m_pSharedObject2 = NULL;	// m_pSharedObject2にNULLをセット.
	m_pSharedObject3 = NULL;	// m_pSharedObject3にNULLをセット.
#endif
	m_pMap = NULL;	// m_pMapにNULLをセット.
	//m_pCharacter = NULL;	// m_pCharacterにNULLをセット.
	//m_pEnemy = NULL;	// m_pEnemyにNULLをセット.
	m_pEnemyMap = NULL;	// m_pEnemyMapにNULLをセット.
	m_pPlayer = NULL;	// m_pPlayerにNULLをセット.
	m_pGameTimeBox = NULL;	// m_pGameTimeBoxをNULLで初期化.
	m_pMessageArea = NULL;	// m_pMessageAreaをNULLで初期化.

}

// デストラクタ~CGameScene
CGameScene::~CGameScene(){

}

// ゲームオブジェクトの初期化.
int CGameScene::InitGameObjects(){

	// 基底クラスの初期化.
	int iRet = CScene::InitGameObjects();	// CScene::InitGameObjectsで初期化.

	// シェアードイメージバッファの追加.
	m_pSharedImageBuffer->Add(IDB_SHARED1);	// 追加.
	m_pSharedImageBuffer->Add(IDB_SHARED2);	// 追加.
	m_pSharedImageBuffer->Add(IDB_SHARED3);	// 追加.

	// シェアードオブジェクトの生成.
#if 0
	m_pSharedObject1 = new CSharedObject(this);	// 生成.
	m_pSharedObject1->Create(0 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject1->Createで生成.
	m_pSharedObject2 = new CSharedObject(this);	// 生成.
	m_pSharedObject2->Create(1 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject2->Createで生成.
	m_pSharedObject3 = new CSharedObject(this);	// 生成.
	m_pSharedObject3->Create(2 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject3->Createで生成.
#endif
	m_pMap = new CMap(this);	// CMapのオブジェクト生成.

	// マップの描画.
#if 0
	m_pMap->Create(32, 32, 21, 17);	// Createで生成.
#else
	//m_pMap->ImportFile(_T("testmap1.bin"));	// m_pMap->ImportFileでインポート.
	m_pMap->ImportResource(IDR_TESTMAP1);	// m_pMap->ImportResourceでインポート.
	m_pMap->m_bLoop = TRUE;	// ループ.
	m_pMap->m_bLoopX = FALSE;	// 横ループ.
	m_pMap->m_bLoopY = TRUE;	// 縦ループ.
	m_pMap->SetScrollTimer(16);	// 16ミリ秒後にスクロール.(これ以上はFPS値60では速くならない.)
#endif

	// エネミーの描画.
	//m_pEnemy = new CEnemy(this);	// CEnemyオブジェクトを生成.
	//m_pEnemy->Add(0, 0, 64, 64, IDB_SHARED3);	// Addで追加.
	//m_pEnemy->Add(64, 0, 64, 64, IDB_SHARED3);	// Add	で追加.
	//m_pEnemy->AddMask(320 + 0, 0, 64, 64, IDB_SHARED3);	// AddMaskで追加.
	//m_pEnemy->AddMask(320 + 64, 0, 64, 64, IDB_SHARED3);	// AddMaskで追加.
	//m_pEnemy->Set(640 / 2 - 64 / 2, 0);	// Setで中央上で初期位置をセット.
	//m_pEnemy->m_iHeight = 64;	// 暫定的に高さを入れておく.(実際はEnemiesリストに入れる.)

	// エネミーマップの描画.
	m_pEnemyMap = new CEnemyMap(this);	// CEnemyMapオブジェクトを生成.
	//m_pEnemyMap->Create();	// 作成.
#if 1
	// エネミーズの追加.
#if 0
	// エネミーズエクスポート.
	// エネミー追加.
	int iEnemyNo = m_pEnemyMap->AddEnemy(640 / 2 - 64 / 2, 0, 64, 64);	// エネミー追加.
	// アニメーション追加.
	RECT rcImg = {0, 0, 64, 64};	// 左上.
	RECT rcMask = {320, 0, 320 + 64, 0 + 64};	// 真ん中から左上.
	m_pEnemyMap->AddEnemyAnimation(iEnemyNo, &rcImg, IDB_SHARED3, &rcMask, IDB_SHARED3);
	m_pEnemyMap->ExportFileEnemies(_T("testenemies1.bin"));	// "testenemies1.bin"としてエクスポート.
#else
	// エネミーズインポート.
	//m_pEnemyMap->ImportFileEnemies(_T("testenemies1.bin"));	// "testenemies1.bin"からインポート.
	m_pEnemyMap->ImportResourceEnemies(IDR_TESTENEMIES1);	// リソースからインポート.
#endif
	// エネミー配置.
#if 0
	m_pEnemyMap->DeployEnemy(200, 600, 0, 1, 0, 1);	// (200, 600)にエネミー0をライフ1状態0スコア1で配置.
	m_pEnemyMap->DeployEnemy(400, 1000, 0, 1, 0, 1);	// (400, 1000)にエネミー0をライフ1状態0スコア1で配置.
	m_pEnemyMap->DeployEnemy(200, 1400, 0, 1, 0, 1);	// (200, 1400)にエネミー0をライフ1状態0スコア1で配置.
	m_pEnemyMap->DeployEnemy(400, 1800, 0, 1, 0, 1);	// (400, 1800)にエネミー0をライフ1状態0スコア1で配置.
	m_pEnemyMap->DeployEnemy(200, 2200, 0, 1, 0, 1);	// (200, 2200)にエネミー0をライフ1状態0スコア1で配置.
	m_pEnemyMap->DeployEnemy(400, 2600, 0, 1, 0, 1);	// (400, 2600)にエネミー0をライフ1状態0スコア1で配置.
	m_pEnemyMap->DeployEnemy(200, 3000, 0, 1, 0, 1);	// (200, 3000)にエネミー0をライフ1状態0スコア1で配置.
	m_pEnemyMap->DeployEnemy(400, 3400, 0, 1, 0, 1);	// (400, 3400)にエネミー0をライフ1状態0スコア1で配置.
#endif
#endif
	//m_pEnemyMap->ExportFileEnemyMapData(_T("testenemymapdata1.bin"));	// エネミーマップデータをファイルにエクスポート.
	//m_pEnemyMap->ImportFileEnemyMapData(_T("testenemymapdata1.bin"));	// エネミーマップデータをファイルからインポート.
	m_pEnemyMap->ImportResourceEnemyMapData(IDR_TESTENEMYMAPDATA1);	// リソースからインポート.
	// プレイヤーの描画.
#if 1
	m_pPlayer = new CPlayer(this);	// CPlayerオブジェクトを生成.
	m_pPlayer->Add(0, 0, 32, 32, IDB_SHARED2);	// Addで追加.
	m_pPlayer->Add(32, 0, 32, 32, IDB_SHARED2);	// Addで追加.
	m_pPlayer->Add(64, 0, 32, 32, IDB_SHARED2);	// Addで追加.
	m_pPlayer->AddMask(320 + 0, 0, 32, 32, IDB_SHARED2);	// AddMaskで追加.
	m_pPlayer->AddMask(320 + 32, 0, 32, 32, IDB_SHARED2);	// AddMaskで追加.
	m_pPlayer->AddMask(320 + 64, 0, 32, 32, IDB_SHARED2);	// AddMaskで追加.
	m_pPlayer->Set(640 / 2 - 32 / 2, 480 - 32);	// Setで初期位置をセット.
	m_pPlayer->CreateShot(3);	// ショットを3つ作成.
	m_pPlayer->CreateExplosion();	// エクスプロージョンを作成.
#else
	m_pCharacter = new CCharacter(this);	// CCharacterオブジェクトを生成.
	m_pCharacter->Add(0, 0, 32, 32, IDB_SHARED2);	// Addで追加.
	m_pCharacter->Add(32, 0, 32, 32, IDB_SHARED2);	// Addで追加.
	m_pCharacter->Add(64, 0, 32, 32, IDB_SHARED2);	// Addで追加.
#endif

	// ゲームタイムボックスの描画.
	m_pGameTimeBox = new CGameTimeBox(this);	// CGameTimeBoxオブジェクトを生成(thisを渡す.), ポインタをm_pGameTimeBoxに格納.
	m_pGameTimeBox->Create(0, 0, 160, 30, 36, _T("ＭＳ ゴシック"));	// m_pGameTimeBox->Createで作成.

	// ステータスボックスの描画.
	m_pStatusBox = new CStatusBox(this);	// CStatusBoxオブジェクトを生成(thisを渡す.), ポインタをm_pStatusBoxに格納.
	m_pStatusBox->Create(320, 0, 160, 30, 24, _T("ＭＳ ゴシック"));	// m_pStatusBox->Createで作成.

	// メッセージエリアの描画.
	m_pMessageArea = new CMessageArea(this);	// CMessageAreaオブジェクトを生成(thisを渡す.), ポインタをm_pMessageAreaに格納.
	m_pMessageArea->Create(300, 200, 300, 100, 32, _T("ＭＳ ゴシック"), 0);	// m_pMessageArea->Createで作成.
	
	// iRet.
	return iRet;	// iRetを返す.

}

// キーボードの初期化.
int CGameScene::InitKeyboard(){

	// キーボードオブジェクトの作成.
	m_pKeyboard = new CKeyboard();	// CKeyboardオブジェクトを作成し, ポインタをm_pKeyboardに格納.
	
	// 監視キーの追加.
	m_pKeyboard->AddKey(VK_DOWN);	// 下キーを追加.
	m_pKeyboard->AddKey(VK_UP);	// 上キーを追加.
	m_pKeyboard->AddKey(VK_RIGHT);	// 右キーを追加.
	m_pKeyboard->AddKey(VK_LEFT);	// 左キーを追加.
	m_pKeyboard->AddKey('Z');	// Zキーを追加.

	// 成功なので0.
	return 0;	// 0を返す.

}

// キーボードのチェック.
int CGameScene::CheckKeyboard(){

	// マップのキー状態クリア.
	//m_pMap->Clear();	// クリア.
	m_pPlayer->Clear();	// クリア.

	// キー状態の取得.
	m_pKeyboard->Check();	// m_pKeyboard->Checkで状態確認.

	// 0番目のキー(ここでは下キー.)が押された時.
	if (m_pKeyboard->IsDown(0)){	// m_pKeyboard->IsDown(0)がTRUEなら.
		//m_pMap->Down();	// 下.
		m_pPlayer->Down();	// 下.
	}

	// 1番目のキー(ここでは上キー.)が押された時.
	if (m_pKeyboard->IsDown(1)){	// m_pKeyboard->IsDown(1)がTRUEなら.
		//m_pMap->Up();	// 上.
		m_pPlayer->Up();	// 上.
	}

	// 2番目のキー(ここでは右キー.)が押された時.
	if (m_pKeyboard->IsDown(2)){	// m_pKeyboard->IsDown(2)がTRUEなら.
		//m_pMap->Right();	// 右.
		m_pPlayer->Right();	// 右.
	}

	// 3番目のキー(ここでは左キー.)が押された時.
	if (m_pKeyboard->IsDown(3)){	// m_pKeyboard->IsDown(3)がTRUEなら.
		//m_pMap->Left();	// 左.
		m_pPlayer->Left();	// 左.
	}

	// 4番目のキー(ここではZキー.)が押された瞬間.
	if (m_pKeyboard->IsPress(4)){	// m_pKeyboard->IsPress(4)がTRUEなら.
		m_pPlayer->Shot();	// ショット.
	}

	// 成功なので0.
	return 0;	// 0を返す.

}

// キー入力や時間などから処理を計算.
int CGameScene::RunProc(){

	// マップ処理.
	if (m_pMap != NULL){	// m_pMapがNULLでなければ.
		m_pMap->Proc();	// m_pMap->Procで処理.
	}

	// エネミー処理.
	//if (m_pEnemy != NULL){	// m_pEnemyがNULLでなければ.
	//	m_pEnemy->Proc();	// m_pEnemy->Procで処理.
	//}

	// エネミーマップ処理.
	if (m_pEnemyMap != NULL){
		m_pEnemyMap->Proc();
	}

	// プレイヤー処理.
	if (m_pPlayer != NULL){	// m_pPlayerがNULLでなければ.
		int iRet = m_pPlayer->Proc();	// m_pPlayer->Procで処理.
		if (iRet == 1){	// 1なら.
			return 1;	// 1を返す.
		}
	}

	// ゲームタイムボックス処理.
	if (m_pGameTimeBox != NULL){	// m_pGameTimeBoxがNULLでない時.
		m_pGameTimeBox->Proc();	// m_pGameTimeBox->Procで処理.
	}

	// 成功なので0.
	return 0;	// 0を返す.

}

// ゲームオブジェクトの描画.
int CGameScene::DrawGameObjects(){

	// シェアードオブジェクトの描画.
#if 0
	m_pSharedObject1->Draw(0 * 32, 0 * 32);	// m_pSharedObject1->Drawで描画.
	m_pSharedObject2->Draw(1 * 32, 0 * 32);	// m_pSharedObject2->Drawで描画.
	m_pSharedObject3->Draw(2 * 32, 0 * 32);	// m_pSharedObject3->Drawで描画.
#endif

	// マップの描画.
	if (m_pMap != NULL){	// m_pMapがNULLでなければ.
		m_pMap->Draw();	// m_pMap->Drawでマップを描画.
	}

	// エネミーの描画.
	//if (m_pEnemy != NULL){	// m_pEnemyがNULLでなければ.
	//	m_pEnemy->Draw();	// m_pEnemy->Drawでエネミーを描画.
	//}

	// エネミーマップ描画.
	if (m_pEnemyMap != NULL){
		m_pEnemyMap->Draw();
	}

	// キャラの描画.
#if 1
	if (m_pPlayer != NULL){	// m_pPlayerがNULLでなければ.
		m_pPlayer->Draw();	// m_pPlayer->Drawでキャラを描画.
		m_pPlayer->DrawShot();	// m_pPlayer->DrawShotでショットを描画.
	}
#else
	if (m_pMap->m_bRight){
		m_pCharacter->Draw(0, 0, 1);	// m_pCharacter->Drawでキャラ(右)を描画.
	}
	else if (m_pMap->m_bLeft){
		m_pCharacter->Draw(0, 0, 2);	// m_pCharacter->Drawでキャラ(左)を描画.
	}
	else{
		m_pCharacter->Draw(0, 0, 0);	// m_pCharacter->Drawでキャラ(中)を描画.
	}
#endif

	// メッセージエリアの描画.
	if (m_pMessageArea != NULL){	// m_pMessageAreaがNULLでない時.
		m_pMessageArea->DrawMessage(248, 220, _T("GAME OVER"), RGB(0xff, 0x0, 0x0));	// "GAME OVER"を表示.
	}

	// ゲームタイムボックスの描画.
	if (m_pGameTimeBox != NULL){	// m_pGameTimeBoxがNULLでない時.
		m_pGameTimeBox->DrawTime(0, 0, 160, 30, RGB(0x98, 0xfb, 0x98));	// m_pGameTimeBox->DrawTimeで時刻を描画.
		//m_pGameTimeBox->DrawFPS(0, 30, 160, 30, RGB(0x98, 0xfb, 0x98));	// m_pGameTimeBox->DrawFPSでFPSを描画.
		m_pGameTimeBox->DrawRunFPS(0, 30, 160, 30, RGB(0x98, 0xfb, 0x98));	// m_pGameTimeBox->DrawRunFPSで実行PFSを描画.
		m_pGameTimeBox->DrawFrameIntervalMilliTime(0, 60, 160, 30, RGB(0x98, 0xfb, 0x98));	// m_pGameTimeBox->DrawFrameIntervalMilliTimeでフレーム間隔を描画.
	}

	// ステータスボックスの描画.
	if (m_pStatusBox != NULL){	// m_pStatusBoxがNULLでない時.
		m_pStatusBox->DrawRest(480, 0, 160, 30, RGB(0x0, 0x0, 0xff));	// m_pStatusBox->DrawRestで残機を描画.
		m_pStatusBox->DrawScore(480, 30, 160, 30, RGB(0x0, 0x0, 0xff));	// m_pStatusBox->DrawScoreでスコアを描画.
	}

	// マップ情報の描画.
	if (m_pMap != NULL){	// m_pMapがNULLでなければ.
		m_pMap->DrawScreenRXUY(0, 90, 160, 30, RGB(0x98, 0xfb, 0x98));	// m_pMap->DrawScreenRXUYでスクリーン座標を描画.
	}

	// ゲームオーバータイマーのデバッグ用.
#if 0
	CGameTime *pTime = this->m_pGameTime;
	DWORD dwNow = pTime->GetSystemTime();
	DWORD t = dwNow - ((CGameScene *)this)->m_pMessageArea->m_dwVisibleTimerStart;
	TCHAR tt[128] = {0};
	_stprintf(tt, _T("%lu"), t);
	((CGameScene *)this)->m_pGameTimeBox->DrawText(400, 300, 100, 100, tt, RGB(0x0, 0x0, 0x0));
#endif

	// 基底クラスの処理.
	return CScene::DrawGameObjects();	// CScene::DrawGameObjectsを呼ぶ.

}

// ゲームオブジェクトの終了処理.
int CGameScene::ExitGameObjects(){

	// メッセージエリアの破棄.
	if (m_pMessageArea != NULL){
		m_pMessageArea->Destroy();	// m_pMessageArea->Destroyで破棄.
		delete m_pMessageArea;	// deleteでm_pMessageAreaを解放.
		m_pMessageArea = NULL;	// m_pMessageAreaにNULLをセット.
	}

	// ステータスボックスの破棄.
	if (m_pStatusBox != NULL){	// m_pStatusBoxがNULLでない時.
		m_pStatusBox->Destroy();	// m_pStatusBox->Destroyで破棄.
		delete m_pStatusBox;	// deleteでm_pStatusBoxを解放.
		m_pStatusBox = NULL;	// m_pStatusBoxにNULLをセット.
	}

	// ゲームタイムボックスの破棄.
	if (m_pGameTimeBox != NULL){	// m_pGameTimeBoxがNULLでない時.
		m_pGameTimeBox->Destroy();	// m_pGameTimeBox->Destroyで廃棄.
		delete m_pGameTimeBox;	// deleteでm_pGameTimeBoxを解放.
		m_pGameTimeBox = NULL;	// m_pGameTimeBoxにNULLをセット.
	}

	// シェアードオブジェクトの破棄.
#if 0
	delete m_pSharedObject1;	// m_pSharedObject1を破棄.
	delete m_pSharedObject2;	// m_pSharedObject2を破棄.
	delete m_pSharedObject3;	// m_pSharedObject3を破棄.
#endif
#if 1
	m_pPlayer->Destroy();	// Destroyで破棄.
	delete m_pPlayer;	// m_pPlayerを削除.
#else
	m_pCharacter->Destroy();	// Destroyで破棄.
	delete m_pCharacter;	// m_pCharacterを削除.
#endif
	//m_pEnemy->Destroy();	// Destroyで破棄.
	//delete m_pEnemy;	// m_pEnemyを削除.
	m_pEnemyMap->Destroy();	// 破棄.
	delete m_pEnemyMap;	// 削除.
	m_pMap->Destroy();	// Destroyで破棄.
	delete m_pMap;	// m_pMapを削除.
	m_pMap = NULL;	// m_pMapにNULLをセット.
	// 基底クラスの処理.
	return CScene::ExitGameObjects();	// CScene::ExitGameObjectsで終了処理.

}