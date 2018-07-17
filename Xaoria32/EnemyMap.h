// 二重インクルード防止
#ifndef __ENEMY_MAP_H__
#define __ENEMY_MAP_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "EnemyMapData.h"	// 構造体EnemyMapData
#include "SharedObject.h"	// CSharedObject
#include "BinaryFile.h"	// CBinaryFile

// マップクラスCEnemyMap
class CEnemyMap : public CSharedObject{

	// publicメンバ
	public:

		// publicメンバ変数
		std::vector<EnemyMapData *> m_vecEnemyMapDataList;	// エネミーマップデータリスト.
	
		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CEnemyMap();	// コンストラクタCEnemyMap
		CEnemyMap(CScene *pScene);	// コンストラクタCEnemyMap(CScene *pScene)
		virtual ~CEnemyMap();	// デストラクタ~CEnemyMap

		// メンバ関数
		virtual int Proc();	// 処理をするProc.
		virtual void Draw();	// 描画をするDraw.
		void RemoveAll();	// 全て削除.

};

#endif