// 二重インクルード防止
#ifndef __ENEMIES_H__
#define __ENEMIES_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "SharedObject.h"	// CSharedObject
#include "Enemy.h"	// CEnemy

// エネミーズクラスCEnemies
class CEnemies : public CSharedObject{

	// publicメンバ
	public:

		// publicメンバ変数
		std::vector<CEnemy *> m_vecEnemiesList;	// エネミーズリスト.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CEnemies();	// コンストラクタCEnemies
		CEnemies(CScene *pScene);	// コンストラクタCEnemies(CScene *pScene)
		virtual ~CEnemies();	// デストラクタ~CEnemies

		// メンバ関数
		void RemoveAll();	// 全て削除.
		void Destroy();	// 破棄Destroy.

};

#endif