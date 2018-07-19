// ヘッダのインクルード
// 独自のヘッダ
#include "Enemies.h"	// CEnemies

// コンストラクタCEnemies
CEnemies::CEnemies() : CSharedObject(){

	// メンバの初期化.
	m_vecEnemiesList.clear();	// クリア.

}

// コンストラクタCEnemies(CScene *pScene)
CEnemies::CEnemies(CScene *pScene) : CSharedObject(pScene){

	// メンバの初期化.
	m_vecEnemiesList.clear();	// クリア.

}

// デストラクタ~CEnemies
CEnemies::~CEnemies(){

	// メンバの終了処理.
	Destroy();	// 破棄.

}

// 全て削除.
void CEnemies::RemoveAll(){

	// 全て削除.
	for (int i = 0; i < m_vecEnemiesList.size(); i++){
		delete m_vecEnemiesList[i];	// i番目を破棄.
		m_vecEnemiesList[i] = NULL;	// NULLをセット.
	}
	m_vecEnemiesList.clear();	// クリア.

}

// 破棄Destroy.
void CEnemies::Destroy(){

	// 全て削除.
	RemoveAll();	// RemoveAllで全て削除.

}