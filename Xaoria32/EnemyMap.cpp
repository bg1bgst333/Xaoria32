// ヘッダのインクルード
// 独自のヘッダ
#include "EnemyMap.h"	// CEnemyMap
#include "BinaryResource.h"	// CBinaryResource
#include "GameScene.h"	// CGameScene
#include "resource.h"	// リソース.

// コンストラクタCEnemyMap
CEnemyMap::CEnemyMap() : CSharedObject(){

	// メンバの初期化.
	m_vecEnemyMapDataList.clear();	// クリア.
	m_pEnemies = NULL;	// NULLをセット.

}

// コンストラクタCEnemyMap(CScene *pScene)
CEnemyMap::CEnemyMap(CScene *pScene) : CSharedObject(pScene){

	// メンバの初期化.
	m_vecEnemyMapDataList.clear();	// クリア.
	m_pEnemies = NULL;	// NULLをセット.

}

// デストラクタ~CEnemyMap
CEnemyMap::~CEnemyMap(){

	// メンバの終了処理.
	Destroy();	// Destroyで終了処理.

}

// 作成するCreate.
int CEnemyMap::Create(){

	// エネミー図の作成.
	m_pEnemies = new CEnemies(m_pScene);	// m_pEnemiesの作成.
	return 0;	// 0を返す.
}

// エネミー追加.
int CEnemyMap::AddEnemy(int x, int y, int iWidth, int iHeight){

	// エネミー作成.
	CEnemy *pEnemy = new CEnemy(m_pScene);	// pEnemy作成.
	pEnemy->Set(x, y);	// xとyをセット.
	pEnemy->m_iWidth = iWidth;	// iWidthをセット.
	pEnemy->m_iHeight = iHeight;	// iHeightをセット.
	int iNo = m_pEnemies->m_vecEnemiesList.size();	// iNo == 挿入前のサイズ.
	m_pEnemies->m_vecEnemiesList.push_back(pEnemy);	// pEnemyを追加.
	return iNo;	// iNoを返す.

}

// 指定のエネミーにアニメーションイメージを追加. 
void CEnemyMap::AddEnemyAnimation(int iEnemyNo, RECT *lprcImgSrc, int nImgSrcID, RECT *lprcMaskSrc, int nMaskSrcID){

	// iEnemyNo番目があるかチェック.
	if (iEnemyNo < m_pEnemies->m_vecEnemiesList.size()){	// インデックスを超えないかチェック.
		CEnemy *pEnemy = m_pEnemies->m_vecEnemiesList[iEnemyNo];	// iEnemyNo番目を取り出す.
		pEnemy->Add(lprcImgSrc->left, lprcImgSrc->top, lprcImgSrc->right - lprcImgSrc->left, lprcImgSrc->bottom - lprcImgSrc->top, nImgSrcID);	// アニメーションイメージ追加.
		pEnemy->AddMask(lprcMaskSrc->left, lprcMaskSrc->top, lprcMaskSrc->right - lprcMaskSrc->left, lprcMaskSrc->bottom - lprcMaskSrc->top, nMaskSrcID);	// アニメーションマスク追加.
	}

}

// エネミーズデータをファイルとしてエクスポートExportFileEnemies.
BOOL CEnemyMap::ExportFileEnemies(LPCTSTR lpctszFileName){

	// エネミーズがあれば.
	if (m_pEnemies != NULL){	// NULLでない.
		if (m_pEnemies->m_vecEnemiesList.size() > 0){	// 0より大きいなら.
			// バイナリファイルの作成.
			CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFileオブジェクトpBinaryFileの生成.
			int n = m_pEnemies->m_vecEnemiesList.size();	// 最初にエネミー数を取得.
			pBinaryFile->Set((BYTE *)&n, sizeof(int));	// エネミー数を書き込む.
			pBinaryFile->Write(lpctszFileName);	// lpctszFileNameに書き込み.
			for (int i = 0; i < m_pEnemies->m_vecEnemiesList.size(); i++){	// エネミーズのサイズ繰り返す.
				CEnemy *pEnemy = m_pEnemies->m_vecEnemiesList[i];	// pEnemy取得.
				pBinaryFile->Set((BYTE *)&pEnemy->m_x, sizeof(int));	// m_x.
				pBinaryFile->Write();	// 書き込み.
				pBinaryFile->Set((BYTE *)&pEnemy->m_y, sizeof(int));	// m_y.
				pBinaryFile->Write();	// 書き込み.
				pBinaryFile->Set((BYTE *)&pEnemy->m_iWidth, sizeof(int));	// m_iWidth.
				pBinaryFile->Write();	// 書き込み.
				pBinaryFile->Set((BYTE *)&pEnemy->m_iHeight, sizeof(int));	// m_iHeight.
				pBinaryFile->Write();	// 書き込み.
				int iSize = pEnemy->m_vecpSharedObjectList.size();	// iSizeの取得.
				pBinaryFile->Set((BYTE *)&iSize, sizeof(int));	// iSizeのセット.
				pBinaryFile->Write();	// 書き込み.
				for (int j = 0; j < iSize; j++){	// iSize分繰り返す.
					CSharedObject *pSO = pEnemy->m_vecpSharedObjectList[j];	// pSO取得.
					pBinaryFile->Set((BYTE *)&pSO->m_sx, sizeof(int));	// m_sx.
					pBinaryFile->Write();	// 書き込み.
					pBinaryFile->Set((BYTE *)&pSO->m_sy, sizeof(int));	// m_sy.
					pBinaryFile->Write();	// 書き込み.
					pBinaryFile->Set((BYTE *)&pSO->m_iWidth, sizeof(int));	// m_iWidth.
					pBinaryFile->Write();	// 書き込み.
					pBinaryFile->Set((BYTE *)&pSO->m_iHeight, sizeof(int));	// m_iHeight.
					pBinaryFile->Write();	// 書き込み.
					pBinaryFile->Set((BYTE *)&pSO->m_nID, sizeof(int));	// m_nID.
					pBinaryFile->Write();	// 書き込み.
					CSharedObject *pMask = pEnemy->m_vecpMaskList[j];	// pMask取得.
					pBinaryFile->Set((BYTE *)&pMask->m_sx, sizeof(int));	// m_sx.
					pBinaryFile->Write();	// 書き込み.
					pBinaryFile->Set((BYTE *)&pMask->m_sy, sizeof(int));	// m_sy.
					pBinaryFile->Write();	// 書き込み.
					pBinaryFile->Set((BYTE *)&pMask->m_iWidth, sizeof(int));	// m_iWidth.
					pBinaryFile->Write();	// 書き込み.
					pBinaryFile->Set((BYTE *)&pMask->m_iHeight, sizeof(int));	// m_iHeight.
					pBinaryFile->Write();	// 書き込み.
					pBinaryFile->Set((BYTE *)&pMask->m_nID, sizeof(int));	// m_nID.
					pBinaryFile->Write();	// 書き込み.
				}
			}
			delete pBinaryFile;	// pBinaryFileの終了処理.
			return TRUE;	// TRUE.
		}
	}
	return FALSE;	// FALSE.

}

// エネミーズデータをファイルからインポートImportFileEnemies.
BOOL CEnemyMap::ImportFileEnemies(LPCTSTR lpctszFileName){

	// エネミーズがなければ.
	if (m_pEnemies == NULL){
		m_pEnemies = new CEnemies(m_pScene);	// m_pEnemiesの生成.
	}

	// バイナリファイルの読み込み.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFileオブジェクトpBinaryFileの生成.
	pBinaryFile->Read(lpctszFileName, 0, sizeof(int));	// pBinaryFile->Readで読み込み.
	int n = *(int *)pBinaryFile->m_pBytes;	// n.
	for (int i = 0; i < n; i++){	// n繰り返す. 
		CEnemy *pEnemy = new CEnemy(m_pScene);	// pEnemyを生成.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		pEnemy->m_x = *(int *)pBinaryFile->m_pBytes;	// x.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		pEnemy->m_y = *(int *)pBinaryFile->m_pBytes;	// y.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		pEnemy->m_iWidth = *(int *)pBinaryFile->m_pBytes;	// iWidth.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		pEnemy->m_iHeight = *(int *)pBinaryFile->m_pBytes;	// iHeight.
		int iSize = 0;	// アニメーションリストサイズ.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		iSize = *(int *)pBinaryFile->m_pBytes;	// iSize.
		for (int j = 0; j < iSize; j++){	// iSize分繰り返す.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
			int iSOSX = *(int *)pBinaryFile->m_pBytes;	// sx
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
			int iSOSY = *(int *)pBinaryFile->m_pBytes;	// sy.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
			int iSOWidth = *(int *)pBinaryFile->m_pBytes;	// iWidth.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
			int iSOHeight = *(int *)pBinaryFile->m_pBytes;	// iHeight.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
			int iSOnID = *(int *)pBinaryFile->m_pBytes;	// nID.
			pEnemy->Add(iSOSX, iSOSY, iSOWidth, iSOHeight, iSOnID);	// イメージ追加.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
			int iMaskSX = *(int *)pBinaryFile->m_pBytes;	// sx
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
			int iMaskSY = *(int *)pBinaryFile->m_pBytes;	// sy.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
			int iMaskWidth = *(int *)pBinaryFile->m_pBytes;	// iWidth.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
			int iMaskHeight = *(int *)pBinaryFile->m_pBytes;	// iHeight.
			pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
			int iMasknID = *(int *)pBinaryFile->m_pBytes;	// nID.
			pEnemy->AddMask(iMaskSX, iMaskSY, iMaskWidth, iMaskHeight, iMasknID);	// マスク追加.
		}
		m_pEnemies->m_vecEnemiesList.push_back(pEnemy);	
	}
	delete pBinaryFile;	// ファイルを削除.(内部で閉じる.)
	return TRUE;	// TRUE.

}

// エネミーズデータをリソースとしてインポートImportResourceEnemies.
BOOL CEnemyMap::ImportResourceEnemies(int nID){

	// エネミーズがなければ.
	if (m_pEnemies == NULL){
		m_pEnemies = new CEnemies(m_pScene);	// m_pEnemiesの生成.
	}

	// バイナリリソースから読み込み.
	CBinaryResource *pBinaryResource = new CBinaryResource();
	pBinaryResource->Load(m_pScene->m_pMainWnd->m_hWnd, nID, _T("BIN"));	// pBinaryResource->Loadでロード.
	int n = *(int *)pBinaryResource->Get(sizeof(int));	// リソースからn取得.
	for (int i = 0; i < n; i++){	// n繰り返す.
		CEnemy *pEnemy = new CEnemy(m_pScene);	// pEnemyを生成.
		pEnemy->m_x = *(int *)pBinaryResource->Get(sizeof(int));	// リソースからm_x取得.
		pEnemy->m_y = *(int *)pBinaryResource->Get(sizeof(int));	// リソースからm_y取得.
		pEnemy->m_iWidth = *(int *)pBinaryResource->Get(sizeof(int));	// m_iWidth.
		pEnemy->m_iHeight = *(int *)pBinaryResource->Get(sizeof(int));	// m_iHeight.
		if (pEnemy->m_iWidth == 32){	// 32
			pEnemy->CreateExplosion(0, 64, 32, 32, IDB_SHARED2);	// 32用.
		}
		else if (pEnemy->m_iWidth == 64){	// 64
			pEnemy->CreateExplosion(0, 64, 64, 64, IDB_SHARED3);	// 64用.
		}
		int iSize = 0;	// アニメーションリストサイズ.
		iSize = *(int *)pBinaryResource->Get(sizeof(int));	// リソースからiSize取得.
		for (int j = 0; j < iSize; j++){	// iSize分繰り返す.
			int iSOSX = *(int *)pBinaryResource->Get(sizeof(int));	// iSOSXを取得.
			int iSOSY = *(int *)pBinaryResource->Get(sizeof(int));	// iSOSYを取得.
			int iSOWidth = *(int *)pBinaryResource->Get(sizeof(int));	// iSOWidthを取得.
			int iSOHeight = *(int *)pBinaryResource->Get(sizeof(int));	// iSOHeightを取得.
			int iSOnID = *(int *)pBinaryResource->Get(sizeof(int));	// iSOnIDを取得.
			pEnemy->Add(iSOSX, iSOSY, iSOWidth, iSOHeight, iSOnID);	// イメージ追加.
			int iMaskSX = *(int *)pBinaryResource->Get(sizeof(int));	// iMaskSXを取得.
			int iMaskSY = *(int *)pBinaryResource->Get(sizeof(int));	// iMaskSYを取得.
			int iMaskWidth = *(int *)pBinaryResource->Get(sizeof(int));	// iMaskWidthを取得.
			int iMaskHeight = *(int *)pBinaryResource->Get(sizeof(int));	// iMaskHeightを取得.
			int iMasknID = *(int *)pBinaryResource->Get(sizeof(int));	// iMasknIDを取得.
			pEnemy->AddMask(iMaskSX, iMaskSY, iMaskWidth, iMaskHeight, iMasknID);	// マスク追加.
		}
		m_pEnemies->m_vecEnemiesList.push_back(pEnemy);		// pEnemyの追加.
	}
	// バイナリリソースオブジェクトの破棄.
	delete pBinaryResource;	// pBinaryResourceの終了処理.
	return TRUE;	// TRUEを返す.

}

// エネミーマップデータをファイルとしてエクスポートExportFileEnemyMapData.
BOOL CEnemyMap::ExportFileEnemyMapData(LPCTSTR lpctszFileName){

	// エネミーマップデータをファイルに書き込む.
	// バイナリファイルの作成.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFileオブジェクトpBinaryFileの生成.
	int n = m_vecEnemyMapDataList.size();	// サイズをnとする.
	pBinaryFile->Set((BYTE *)&n, sizeof(int));	// エネミー配置数をセット.
	pBinaryFile->Write(lpctszFileName);	// lpctszFileNameに書き込み.
	for (int i = 0; i < n; i++){	// リストのサイズ分繰り返す.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_x, sizeof(int));	// m_x.
		pBinaryFile->Write();	// 書き込み.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_y, sizeof(int));	// m_y.
		pBinaryFile->Write();	// 書き込み.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_nEnemyNo, sizeof(int));	// m_nEnemyNo.
		pBinaryFile->Write();	// 書き込み.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_nLife, sizeof(int));	// m_nLife.
		pBinaryFile->Write();	// 書き込み.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_nState, sizeof(int));	// m_nState.
		pBinaryFile->Write();	// 書き込み.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_nScore, sizeof(int));	// m_nScore.
		pBinaryFile->Write();	// 書き込み.
		pBinaryFile->Set((BYTE *)&m_vecEnemyMapDataList[i]->m_nMoveType, sizeof(int));	// m_nMoveType.
		pBinaryFile->Write();	// 書き込み.
	}
	delete pBinaryFile;	// 削除.
	return TRUE;	// TRUEを返す.

}

// エネミーマップデータをファイルからインポートImportFileEnemyMapData.
BOOL CEnemyMap::ImportFileEnemyMapData(LPCTSTR lpctszFileName){

	// エネミーマップデータをファイルから読み込む.
	// バイナリファイルの読み込み.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFileオブジェクトpBinaryFileの生成.
	pBinaryFile->Read(lpctszFileName, 0, sizeof(int));	// pBinaryFile->Readで読み込み.
	int n = *(int *)pBinaryFile->m_pBytes;	// n.
	for (int i = 0; i < n; i++){	// n繰り返す.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		int x = *(int *)pBinaryFile->m_pBytes;	// x.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		int y = *(int *)pBinaryFile->m_pBytes;	// y.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		int iEnemyNo = *(int *)pBinaryFile->m_pBytes;	// iEnemyNo.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		int iLife = *(int *)pBinaryFile->m_pBytes;	// iLife.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		int iState = *(int *)pBinaryFile->m_pBytes;	// iState.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		int iScore = *(int *)pBinaryFile->m_pBytes;	// iScore.
		pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
		int iMoveType = *(int *)pBinaryFile->m_pBytes;	// iMoveType.
		DeployEnemy(x, y, iEnemyNo, iLife, iState, iScore, iMoveType);	// DeployEnemyでエネミーマップデータに追加.
	}
	delete pBinaryFile;	// 削除.
	return TRUE;	// TRUEを返す.

}

// エネミーマップデータをリソースからインポートImportResourceEnemyMapData.
BOOL CEnemyMap::ImportResourceEnemyMapData(int nID){

	// バイナリリソースから読み込み.
	CBinaryResource *pBinaryResource = new CBinaryResource();
	pBinaryResource->Load(m_pScene->m_pMainWnd->m_hWnd, nID, _T("BIN"));	// pBinaryResource->Loadでロード.
	int n = *(int *)pBinaryResource->Get(sizeof(int));	// リソースからn取得.
	for (int i = 0; i < n; i++){	// n繰り返す.
		int x = *(int *)pBinaryResource->Get(sizeof(int));	// x.
		int y = *(int *)pBinaryResource->Get(sizeof(int));	// y.
		int iEnemyNo = *(int *)pBinaryResource->Get(sizeof(int));	// iEnemyNo.
		int iLife = *(int *)pBinaryResource->Get(sizeof(int));	// iEnemyNo.
		int iState = *(int *)pBinaryResource->Get(sizeof(int));	// iState.
		int iScore = *(int *)pBinaryResource->Get(sizeof(int));	// iScore.
		int iMoveType = *(int *)pBinaryResource->Get(sizeof(int));	// iMoveType.
		DeployEnemy(x, y, iEnemyNo, iLife, iState, iScore, iMoveType);	// DeployEnemyでエネミーマップデータに追加.
	}
	// バイナリリソースオブジェクトの破棄.
	delete pBinaryResource;	// pBinaryResourceの終了処理.
	return TRUE;	// TRUEを返す.

}

// エネミー配置.
void CEnemyMap::DeployEnemy(int x, int y, int iEnemyNo, int iLife, int iState, int iScore, int iMoveType){

	// エネミーマップデータの生成.
	EnemyMapData *pEMD = new EnemyMapData();	// pEMDの生成.
	// 値の設定.
	pEMD->m_x = x;	// x
	pEMD->m_y = y;	// y
	pEMD->m_nEnemyNo = iEnemyNo;	// エネミー番号.
	pEMD->m_nLife = iLife;	// ライフ.
	pEMD->m_nState = iState;	// 状態.
	pEMD->m_nScore = iScore;	// スコア.
	pEMD->m_nExplosionAnimation = 0;	// 0.
	pEMD->m_nMoveType = iMoveType;	// 動作タイプ.
	pEMD->m_nMoveState = 0;	// 0.
	pEMD->m_nMoveValue = 0;	// 0.
	if (pEMD->m_nEnemyNo == 0 || pEMD->m_nEnemyNo == 2 || pEMD->m_nEnemyNo == 4){
		// ショットの作成.
		pEMD->m_nShotIdx = 0;
		for (int i = 0; i < 3; i++){	// 3個繰り返す.
			CShot *pShot = new CShot(m_pScene);	// CShotオブジェクトの作成.
			pShot->Add(0, 32, 4, 32, IDB_SHARED2);	// イメージ追加.
			pShot->AddMask(320 + 0, 32, 4, 32, IDB_SHARED2);	// マスク.追加.
			pShot->Set(pEMD->m_x + 32 / 2 - 4 / 2, pEMD->m_y);	// pShot->Setで座標をセット.
			pShot->Set(0);	// 状態0をセット.
			pEMD->m_vecpShotList.push_back(pShot);	// m_vecpShotList.push_backで追加.
		}
	}
	// 追加.
	m_vecEnemyMapDataList.push_back(pEMD);	// 追加.

}

// ショットを描画するDrawShot.
void CEnemyMap::DrawShot(){

	CGameScene *pGameScene = (CGameScene *)m_pScene;	// pGameSceneにキャスト.
	CMap *pMap = pGameScene->m_pMap;	// pMapに保持.
	int iScreenUY = pMap->m_iScreenUY;	// スクリーン座標y.

	int n = m_vecEnemyMapDataList.size();
	for (int j = 0; j < n; j++){
		// ショットの描画.
		for (int i = 0; i <  m_vecEnemyMapDataList[j]->m_vecpShotList.size(); i++){
			int iState = ((CShot *)m_vecEnemyMapDataList[j]->m_vecpShotList[i])->Get();	// iState取得.
			int x = m_vecEnemyMapDataList[j]->m_vecpShotList[i]->m_x + 32 / 2 - 4 / 2;
			int y = iScreenUY - m_vecEnemyMapDataList[j]->m_vecpShotList[i]->m_y;
			if (iState == 1){	// 状態が1なら描画.
				((CShot *)m_vecEnemyMapDataList[j]->m_vecpShotList[i])->DrawSprite(x, y, 0);	// 描画.
			}
		}
	}

}

// 処理をするProc.
int CEnemyMap::Proc(){

	// 有効なら描画状態にする.
	if (m_pEnemies != NULL){	// NULLでない.
		CGameScene *pGameScene = (CGameScene *)m_pScene;	// pGameSceneにキャスト.
		CMap *pMap = pGameScene->m_pMap;	// pMapに保持.
		int iScreenUY = pMap->m_iScreenUY;	// スクリーン座標y.
		if (pGameScene != NULL && pMap != NULL){	// どちらもNULLでない.
			for (int i = 0; i < m_vecEnemyMapDataList.size(); i++){
				if (m_vecEnemyMapDataList[i]->m_nState == 1){	// 表示時のみ.
					if (m_vecEnemyMapDataList[i]->m_nMoveType == 0){	// 移動タイプ0.
						// 移動しない.
					}
					else if (m_vecEnemyMapDataList[i]->m_nMoveType == 1){	// 移動タイプ1.
						m_vecEnemyMapDataList[i]->m_x++;	// 右へ移動.
					}
					else if (m_vecEnemyMapDataList[i]->m_nMoveType == 2){	// 移動タイプ2.
						m_vecEnemyMapDataList[i]->m_y--;	// 下へ移動.(下からの通算位置なので--で下がる.)
					}
					else if (m_vecEnemyMapDataList[i]->m_nMoveType == 3){	// 移動タイプ3.
						m_vecEnemyMapDataList[i]->m_x--;	// 左へ移動.
					}
					else if (m_vecEnemyMapDataList[i]->m_nMoveType == 4){	// 移動タイプ4.
						if (m_vecEnemyMapDataList[i]->m_nMoveState == 0){	// 表示しきっていない.
							int v = m_vecEnemyMapDataList[i]->m_nMoveValue;
							int h = m_pEnemies->m_vecEnemiesList[m_vecEnemyMapDataList[i]->m_nEnemyNo]->m_iHeight;
							if (v > h+32){	// 高さ超えたら.(+32しないと変なブレがおきる.)
								m_vecEnemyMapDataList[i]->m_nMoveState = 1;	// 1にする.
							}
							else{
								m_vecEnemyMapDataList[i]->m_nMoveValue++;
							}
						}
						else{
							//m_vecEnemyMapDataList[i]->m_y++;	// 上へ移動.(下からの通算位置なので++で上がる.) <- これだと上に行ってしまう.
							m_vecEnemyMapDataList[i]->m_y = iScreenUY;	// これだと画面内にとどまる.
						}
					}
					else if (m_vecEnemyMapDataList[i]->m_nMoveType == 5){	// 移動タイプ5.
						if (m_vecEnemyMapDataList[i]->m_nMoveValue >= 128){
							if (m_vecEnemyMapDataList[i]->m_nMoveState == 0){
								m_vecEnemyMapDataList[i]->m_nMoveState = 1;
								m_vecEnemyMapDataList[i]->m_nMoveValue = 0;
							}
							else{
								m_vecEnemyMapDataList[i]->m_nMoveState = 0;
								m_vecEnemyMapDataList[i]->m_nMoveValue = 0;
							}
						}
						else{
							m_vecEnemyMapDataList[i]->m_nMoveValue++;
							if (m_vecEnemyMapDataList[i]->m_nMoveState == 0){
								m_vecEnemyMapDataList[i]->m_x++;
							}
							else{
								m_vecEnemyMapDataList[i]->m_x--;
							}
						}
					}
				}
				int iDrawPos = m_vecEnemyMapDataList[i]->m_y;	// 配置場所.
				int nEnemyNo = m_vecEnemyMapDataList[i]->m_nEnemyNo;	// エネミー番号.
				if (nEnemyNo < m_pEnemies->m_vecEnemiesList.size()){	// 番号がサイズ未満.
					int iHeight = m_pEnemies->m_vecEnemiesList[nEnemyNo]->m_iHeight;	// 高さ.
					int iDrawPosStart = iDrawPos - iHeight;	// 配置場所から高さを引く.
					int iDrawPosEnd = iDrawPosStart + iHeight + 480;	// 描画開始にエネミー高さとスクリーン高さを足す.
					if (m_vecEnemyMapDataList[i]->m_nLife <= 0){	// ライフが0以下.
						m_vecEnemyMapDataList[i]->m_nState = 3;	// 表示状態3.
						EnemyMapData *pEMD = m_vecEnemyMapDataList[i];
						if (m_vecEnemyMapDataList[i]->m_nEnemyNo == 0 || m_vecEnemyMapDataList[i]->m_nEnemyNo == 2 || m_vecEnemyMapDataList[i]->m_nEnemyNo == 4){
							if (((CShot *)pEMD->m_vecpShotList[pEMD->m_nShotIdx])->Get() == 1){
								//((CShot *)pEMD->m_vecpShotList[pEMD->m_nShotIdx])->Set(pEMD->m_x, pEMD->m_y);	// pShot->Setで座標をセット.
								int x = ((CShot *)(pEMD->m_vecpShotList[pEMD->m_nShotIdx]))->m_x;
								int y = ((CShot *)(pEMD->m_vecpShotList[pEMD->m_nShotIdx]))->m_y;
								y = y - 4;
								((CShot *)(pEMD->m_vecpShotList[pEMD->m_nShotIdx]))->Set(x, y);
							}
						}
					}
					else{
						if (iDrawPosStart <= iScreenUY && iDrawPosEnd > iScreenUY){	// 描画位置.
							m_vecEnemyMapDataList[i]->m_nState = 1;	// 表示状態.
							if (m_vecEnemyMapDataList[i]->m_nEnemyNo == 0 || m_vecEnemyMapDataList[i]->m_nEnemyNo == 2 || m_vecEnemyMapDataList[i]->m_nEnemyNo == 4){
								EnemyMapData *pEMD = m_vecEnemyMapDataList[i];
								if (((CShot *)pEMD->m_vecpShotList[pEMD->m_nShotIdx])->Get() == 0){
									((CShot *)pEMD->m_vecpShotList[pEMD->m_nShotIdx])->Set(1);	// 敵ショットを表示状態にする.
									((CShot *)pEMD->m_vecpShotList[pEMD->m_nShotIdx])->Set(pEMD->m_x, pEMD->m_y);	// pShot->Setで座標をセット.
								}
								else if (((CShot *)pEMD->m_vecpShotList[pEMD->m_nShotIdx])->Get() == 1 || ((CShot *)pEMD->m_vecpShotList[pEMD->m_nShotIdx])->Get() == 3){
									//((CShot *)pEMD->m_vecpShotList[pEMD->m_nShotIdx])->Set(pEMD->m_x, pEMD->m_y);	// pShot->Setで座標をセット.
									int x = ((CShot *)(pEMD->m_vecpShotList[pEMD->m_nShotIdx]))->m_x;
									int y = ((CShot *)(pEMD->m_vecpShotList[pEMD->m_nShotIdx]))->m_y;
									y = y - 4;
									((CShot *)(pEMD->m_vecpShotList[pEMD->m_nShotIdx]))->Set(x, y);
								}
							}
						}
						else if (iDrawPosEnd <= iScreenUY){	// 超えたら.
							m_vecEnemyMapDataList[i]->m_nState = 2;	// 通過非表示状態.
						}
					}
				}
			}
		}
	}

	// シーン継続なら0.
	return 0;	// 0を返す.

}

// 描画をするDraw.
void CEnemyMap::Draw(){

	// 有効なら描画状態にする.
	if (m_pEnemies != NULL){	// NULLでない.
		CGameScene *pGameScene = (CGameScene *)m_pScene;	// pGameSceneにキャスト.
		CMap *pMap = pGameScene->m_pMap;	// pMapに保持.
		int iScreenUY = pMap->m_iScreenUY;	// スクリーン座標y.
		for (int i = 0; i < m_vecEnemyMapDataList.size(); i++){
			if (m_vecEnemyMapDataList[i] != NULL){	// NULLでなければ.
				int nEnemyNo = m_vecEnemyMapDataList[i]->m_nEnemyNo;
				if (nEnemyNo < m_pEnemies->m_vecEnemiesList.size()){	// 番号がサイズ未満.
					CEnemy *pEnemy = m_pEnemies->m_vecEnemiesList[nEnemyNo];	// pEnemyを取り出し.
					if (m_vecEnemyMapDataList[i]->m_nState == 1){	// 1の時は表示.
						pEnemy->Set(0);	// アニメーション0.
						int x = m_vecEnemyMapDataList[i]->m_x;	// x
						int y = iScreenUY - m_vecEnemyMapDataList[i]->m_y;	// スクリーン位置yからエネミーyを引く.
						pEnemy->Set(x, y);	// セット.
						pEnemy->Draw();	// 描画.
					}
					else if (m_vecEnemyMapDataList[i]->m_nState == 3){	// 3の時は表示.
						pEnemy->Set(0);	// アニメーション0.
						int x = m_vecEnemyMapDataList[i]->m_x;	// x
						int y = iScreenUY - m_vecEnemyMapDataList[i]->m_y;	// スクリーン位置yからエネミーyを引く.
						pEnemy->Set(x, y);	// セット.
						if (m_vecEnemyMapDataList[i]->m_nExplosionAnimation != -1){	// -1でない.
							if (m_vecEnemyMapDataList[i]->m_nExplosionAnimation <= 3){	// 3以下なら.
								pEnemy->DrawExplosion(x, y, m_vecEnemyMapDataList[i]->m_nExplosionAnimation);	// 爆発.
								m_vecEnemyMapDataList[i]->m_nExplosionAnimation++;	// アニメーション加算.
							}
						}
						else if (m_vecEnemyMapDataList[i]->m_nExplosionAnimation >= 4){	// 4以上.
							m_vecEnemyMapDataList[i]->m_nExplosionAnimation = -1;	// -1にする.
						}
					}
				}
			}
		}
	}

}

// 全て削除.
void CEnemyMap::RemoveAll(){

	// すべてのオブジェクトを破棄.
	for (int i = 0; i < m_vecEnemyMapDataList.size(); i++){
		if (m_vecEnemyMapDataList[i] != NULL){	// NULLでなければ.
			if (m_vecEnemyMapDataList[i]->m_vecpShotList.size() > 0){
				for (int j = 0; j < m_vecEnemyMapDataList[i]->m_vecpShotList.size(); j++){
					m_vecEnemyMapDataList[i]->m_vecpShotList[j]->Destroy();
					delete m_vecEnemyMapDataList[i]->m_vecpShotList[j];
				}
				m_vecEnemyMapDataList[i]->m_vecpShotList.clear();
			}
			delete m_vecEnemyMapDataList[i];	// deleteでm_vecEnemyMapDataList[i]を破棄.
			m_vecEnemyMapDataList[i] = NULL;	// NULLをセット.
		}
	}
	m_vecEnemyMapDataList.clear();	// クリア.

}

// キャラクターの破棄Destroy.
void CEnemyMap::Destroy(){

	// 全て削除.
	RemoveAll();	// RemoveAllで全て削除.
	if (m_pEnemies != NULL){	// NULLでない.
		m_pEnemies->Destroy();	// 破棄.
		delete m_pEnemies;	// 削除.
		m_pEnemies = NULL;	// NULLをセット.
	}

}