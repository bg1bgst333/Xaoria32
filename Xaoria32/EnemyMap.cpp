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

}

// コンストラクタCEnemyMap(CScene *pScene)
CEnemyMap::CEnemyMap(CScene *pScene) : CSharedObject(pScene){

	// メンバの初期化.
	m_vecEnemyMapDataList.clear();	// クリア.

}

// デストラクタ~CEnemyMap
CEnemyMap::~CEnemyMap(){

	// メンバの終了処理.
	m_vecEnemyMapDataList.clear();	// クリア.

}

// 処理をするProc.
int CEnemyMap::Proc(){

	// 有効なら描画状態にする.
	for (int i = 0; i < m_vecEnemyMapDataList.size(); i++){
		if (m_vecEnemyMapDataList[i] != NULL){	// NULLでなければ.
			if (((CGameScene *)m_pScene) != NULL){	// NULLでない.
				if (((CGameScene *)m_pScene)->m_pMap != NULL){	// NULLでない.
					if (((CGameScene *)m_pScene)->m_pEnemy != NULL){	// NULLでない.
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

	// シーン継続なら0.
	return 0;	// 0を返す.

}

// 描画をするDraw.
void CEnemyMap::Draw(){

	// 有効なら描画状態にする.
	for (int i = 0; i < m_vecEnemyMapDataList.size(); i++){
		if (m_vecEnemyMapDataList[i] != NULL){	// NULLでなければ.
			if (((CGameScene *)m_pScene) != NULL){	// NULLでない.
				if (((CGameScene *)m_pScene)->m_pEnemy != NULL){	// NULLでない.
					if (m_vecEnemyMapDataList[i]->m_nState == 1){
						((CGameScene *)m_pScene)->m_pEnemy->Draw();
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