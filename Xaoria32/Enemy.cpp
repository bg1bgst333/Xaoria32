// ヘッダのインクルード
// 独自のヘッダ
#include "Enemy.h"	// CEnemy
#include "Explosion.h"	// CExplosion
#include "resource.h"	// リソース.

// コンストラクタCEnemy
CEnemy::CEnemy() : CCharacter(){

	// メンバの初期化.
	m_iNo = 0;	// m_iNoに0をセット.
	m_pExplosion = NULL;	// m_pExplosionにNULLをセット.

}

// デストラクタCEnemy(CScene *pScene)
CEnemy::CEnemy(CScene *pScene) : CCharacter(pScene){

	// メンバの初期化.
	m_iNo = 0;	// m_iNoに0をセット.
	m_pExplosion = NULL;	// m_pExplosionにNULLをセット.

}

// デストラクタ~CEnemy()
CEnemy::~CEnemy(){

	// メンバの終了処理.
	m_iNo = 0;	// m_iNoに0をセット.

	// 破棄.
	Destroy();	// Destroyで破棄.

}

// キャラクターの破棄Destroy.
void CEnemy::Destroy(){

	// エクスプロージョンの破棄.
	if (m_pExplosion != NULL){	// m_pExplosionがNULLでない.
		m_pExplosion->Destroy();	// 破棄.
		delete m_pExplosion;	// 削除.
		m_pExplosion = NULL;	// NULLをセット.
	}

	// 親クラスのメンバ関数.
	CCharacter::Destroy();	// CCharacter::Destroyで破棄.

}

// 処理をするProc.
int CEnemy::Proc(){

	// アニメーションは0をセット.
	Set(0);	// 0をセット.

	// シーン継続なら0.
	return 0;	// 0を返す.

}

// 位置をセットするSet.
void CEnemy::Set(int x, int y){

	// メンバのセット.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.

}

// アニメーションをセットするSet.
void CEnemy::Set(int iNo){

	// アニメーションのセット.
	m_iNo = iNo;	// m_iNoにiNoをセット.

}

// 描画をするDraw.
void CEnemy::Draw(){

	// 描画.
	//CCharacter::Draw(m_x, m_y, m_iNo);	// CCharacter::Drawで描画.
	CCharacter::DrawSprite(m_x, m_y, m_iNo);	// CCharacter::DrawSpriteで描画.

}

// エクスプロージョンの作成CreateExplosion.
void CEnemy::CreateExplosion(int nFirstX, int nFirstY, int iWidth, int iHeight, int nID){

	// CExplosionの作成.
	CExplosion *pExplosion = new CExplosion(m_pScene);	// pExplosionの生成.
	pExplosion->Add(nFirstX, nFirstY, iWidth, iHeight, nID);	// イメージ追加.
	pExplosion->AddMask(320 + nFirstX, nFirstY, iWidth, iHeight, nID);	// マスク追加.
	pExplosion->Add(nFirstX + iWidth, nFirstY, iWidth, iHeight, nID);	// イメージ追加.
	pExplosion->AddMask(320 + nFirstX + iWidth, nFirstY, iWidth, iHeight, nID);	// マスク追加.
	pExplosion->Add(nFirstX + iWidth * 2, nFirstY, iWidth, iHeight, nID);	// イメージ追加.
	pExplosion->AddMask(320 + nFirstX + iWidth * 2, nFirstY, iWidth, iHeight, nID);	// マスク追加.
	pExplosion->Add(nFirstX + iWidth * 3, nFirstY, iWidth, iHeight, nID);	// イメージ追加.
	pExplosion->AddMask(320 + nFirstX + iWidth * 3, nFirstY, iWidth, iHeight, nID);	// マスク追加.
	pExplosion->Set(m_x, m_y);	// 位置のセット.
	m_pExplosion = pExplosion;	// m_pExplosionにpExplosionをセット.

}

// エクスプロージョンを描画するDrawExplosion.
void CEnemy::DrawExplosion(int x, int y, int nAnimationNo){

	// 爆発描画.
	if (m_pExplosion != NULL){	// NULLでない.
		((CExplosion *)m_pExplosion)->DrawSprite(x, y, nAnimationNo);	// 敵の場合は指定のアニメーション番号を描画.
	}

}