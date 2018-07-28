// ヘッダのインクルード
// 独自のヘッダ
#include "Explosion.h"	// CExplosion
#include "resource.h"	// リソース.

// コンストラクタCExplosion()
CExplosion::CExplosion() : CSharedObject(){

	// メンバの初期化.
	m_iState = 0;	// m_iStateに0をセット.

}

// デストラクタCExplosion(CScene *pScene)
CExplosion::CExplosion(CScene *pScene) : CSharedObject(pScene){

	// メンバの終了処理.
	m_iState = 0;	// m_iStateに0をセット.

}

// デストラクタ~CExplosion()
CExplosion::~CExplosion(){

	// 破棄.
	Destroy();	// Destroyで破棄.

}

// アニメーションの追加Add.
void CExplosion::Add(int sx, int sy, int iWidth, int iHeight, int nID){

	// 子オブジェクトを生成して追加.
	CSharedObject *pSharedObject = new CSharedObject(m_pScene);			// CSharedObjectオブジェクトを生成.
	pSharedObject->Create(sx, sy, iWidth, iHeight, nID);	// Createで生成.
	m_vecpSharedObjectList.push_back(pSharedObject);	// push_backで追加.

}

// マスクの追加AddMask.
void CExplosion::AddMask(int sx, int sy, int iWidth, int iHeight, int nID){

	// マスクの生成と追加.
	CSharedObject *pMask = new CSharedObject(m_pScene);			// CSharedObjectオブジェクトを生成.
	pMask->Create(sx, sy, iWidth, iHeight, nID);	// Createで生成.
	m_vecpMaskList.push_back(pMask);	// push_backで追加.

}

// エクスプロージョンの破棄Destroy.
void CExplosion::Destroy(){

	// 子オブジェクトを破棄.
	// マスク.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpMaskList.begin(); itor != m_vecpMaskList.end(); itor++){	// リスト全ての破棄.
		if ((*itor) != NULL){	// (*itor)がNULLじゃない時.
			(*itor)->Destroy();	// (*itor)->Destroyで破棄.
			delete (*itor);	// deleteで(*Itor)を破棄.
			(*itor) = NULL;	// NULLをセット.
		}
	}
	// イメージ.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpSharedObjectList.begin(); itor != m_vecpSharedObjectList.end(); itor++){	// リスト全ての破棄.
		if ((*itor) != NULL){	// (*itor)がNULLじゃない時.
			(*itor)->Destroy();	// (*itor)->Destroyで破棄.
			delete (*itor);	// deleteで(*Itor)を破棄.
			(*itor) = NULL;	// NULLをセット.
		}
	}
	m_vecpMaskList.clear();	// クリア.
	m_vecpSharedObjectList.clear();	// クリア.

}

// シェアードオブジェクトの描画Draw.
void CExplosion::Draw(int x, int y, int iNo){

	// iNo番目を描画.
	m_vecpSharedObjectList[iNo]->Draw(x, y);	// m_vecpSharedObjectList[iNo]->Drawで描画.

}

// スプライトの描画DrawSprite.
void CExplosion::DrawSprite(int x, int y, int iNo){

	// 描画.
	m_vecpSharedObjectList[iNo]->m_x = x;	// m_vecpSharedObjectList[iNo]->m_xにxをセット.
	m_vecpSharedObjectList[iNo]->m_y = y;	// m_vecpSharedObjectList[iNo]->m_yにyをセット.
	HDC hMemDC = m_vecpSharedObjectList[iNo]->m_pScene->m_pSharedImageBuffer->Get(m_vecpSharedObjectList[iNo]->m_nID);	// hMemDCを取得.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = m_vecpSharedObjectList[iNo]->m_iWidth;	// m_iWidthのセット.
	m_iHeight = m_vecpSharedObjectList[iNo]->m_iHeight;	// m_iHeightのセット.
	m_sx = m_vecpSharedObjectList[iNo]->m_sx;	// m_sxのセット.
	m_sy = m_vecpSharedObjectList[iNo]->m_sy;	// m_syのセット.
	HDC hMaskMemDC = m_vecpMaskList[iNo]->m_pScene->m_pSharedImageBuffer->Get(m_vecpMaskList[iNo]->m_nID);	// hMasMemDCを取得.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, hMaskMemDC, m_vecpMaskList[iNo]->m_sx, m_vecpMaskList[iNo]->m_sy, SRCPAINT);	// マスクをSRCPAINT.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, hMemDC, m_sx, m_sy, SRCAND);	// SRCANDでメインイメージを描画.

}

// アニメーション描画DrawAnimation.
BOOL CExplosion::DrawAnimation(int x, int y){

	// 順に描画.
	if (m_iState != -1){	// -1でない.
		if (m_iState < m_vecpSharedObjectList.size()){	// サイズ未満.
			DrawSprite(x, y, m_iState);	// m_iState番目を描画.
			m_iState++;	// m_iStateをインクリメント.
			return TRUE;	// TRUE.
		}
		else{
			m_iState = -1;	// -1.
			//m_iState = 0;	// ループ.
			return FALSE;	// FALSE.
		}
	}

	// 描画済み.
	return FALSE;	// FALSE.

}

// 位置をセットするSet.
void CExplosion::Set(int x, int y){

	// 位置のセット.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.

}

// 状態のセット.
void CExplosion::Set(int iState){

	// 状態のセット.
	m_iState = iState;	// m_iStateにiStateをセット.

}

// 状態の取得.
int CExplosion::Get(){

	// 状態の取得.
	return m_iState;	// m_iStateを返す.

}