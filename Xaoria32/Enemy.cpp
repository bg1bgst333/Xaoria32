// ヘッダのインクルード
// 独自のヘッダ
#include "Enemy.h"	// CEnemy
#include "resource.h"	// リソース.

// コンストラクタCEnemy
CEnemy::CEnemy() : CCharacter(){

	// メンバの初期化.
	m_iNo = 0;	// m_iNoに0をセット.

}

// デストラクタCEnemy(CScene *pScene)
CEnemy::CEnemy(CScene *pScene) : CCharacter(pScene){

	// メンバの初期化.
	m_iNo = 0;	// m_iNoに0をセット.
	
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