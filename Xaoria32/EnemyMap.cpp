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

// エネミー配置.
void CEnemyMap::DeployEnemy(int x, int y, int iEnemyNo, int iState){

	// エネミーマップデータの生成.
	EnemyMapData *pEMD = new EnemyMapData();	// pEMDの生成.
	// 値の設定.
	pEMD->m_x = x;	// x
	pEMD->m_y = y;	// y
	pEMD->m_nEnemyNo = iEnemyNo;	// エネミー番号.
	pEMD->m_nState = iState;	// 状態.
	// 追加.
	m_vecEnemyMapDataList.push_back(pEMD);	// 追加.

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
				int iDrawPos = m_vecEnemyMapDataList[i]->m_y;	// 配置場所.
				int nEnemyNo = m_vecEnemyMapDataList[i]->m_nEnemyNo;	// エネミー番号.
				if (nEnemyNo < m_pEnemies->m_vecEnemiesList.size()){	// 番号がサイズ未満.
					int iHeight = m_pEnemies->m_vecEnemiesList[nEnemyNo]->m_iHeight;	// 高さ.
					int iDrawPosStart = iDrawPos - iHeight;	// 配置場所から高さを引く.
					int iDrawPosEnd = iDrawPosStart + iHeight + 480;	// 描画開始にエネミー高さとスクリーン高さを足す.
					if (iDrawPosStart <= iScreenUY && iDrawPosEnd > iScreenUY){	// 描画位置.
						m_vecEnemyMapDataList[i]->m_nState = 1;	// 表示状態.
					}
					else if (iDrawPosEnd <= iScreenUY){	// 超えたら.
						m_vecEnemyMapDataList[i]->m_nState = 2;	// 通過非表示状態.
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