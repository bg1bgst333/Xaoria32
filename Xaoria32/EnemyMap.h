// 二重インクルード防止
#ifndef __ENEMY_MAP_H__
#define __ENEMY_MAP_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "EnemyMapData.h"	// 構造体EnemyMapData
#include "Enemies.h"	// CEnemies
#include "SharedObject.h"	// CSharedObject
#include "BinaryFile.h"	// CBinaryFile

// マップクラスCEnemyMap
class CEnemyMap : public CSharedObject{

	// publicメンバ
	public:

		// publicメンバ変数
		std::vector<EnemyMapData *> m_vecEnemyMapDataList;	// エネミーマップデータリスト.
		CEnemies *m_pEnemies;	// エネミーズオブジェクトポインタm_pEnemies.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CEnemyMap();	// コンストラクタCEnemyMap
		CEnemyMap(CScene *pScene);	// コンストラクタCEnemyMap(CScene *pScene)
		virtual ~CEnemyMap();	// デストラクタ~CEnemyMap

		// メンバ関数
		int Create();	// 作成するCreate.
		int AddEnemy(int x, int y, int iWidth, int iHeight);	// エネミー追加.
		void AddEnemyAnimation(int iEnemyNo, RECT *lprcImgSrc, int nImgSrcID, RECT *lprcMaskSrc, int nMaskSrcID);	// 指定のエネミーにアニメーションイメージを追加.
		BOOL ExportFileEnemies(LPCTSTR lpctszFileName);	// エネミーズデータをファイルとしてエクスポートExportFileEnemies.
		BOOL ImportFileEnemies(LPCTSTR lpctszFileName);	// エネミーズデータをファイルからインポートImportFileEnemies.
		BOOL ImportResourceEnemies(int nID);	// エネミーズデータをリソースとしてインポートImportResourceEnemies.
		BOOL ExportFileEnemyMapData(LPCTSTR lpctszFileName);	// エネミーマップデータをファイルとしてエクスポートExportFileEnemyMapData.
		BOOL ImportFileEnemyMapData(LPCTSTR lpctszFileName);	// エネミーマップデータをファイルからインポートImportFileEnemyMapData.
		BOOL ImportResourceEnemyMapData(int nID);	// エネミーマップデータをリソースからインポートImportResourceEnemyMapData.
		void DeployEnemy(int x, int y, int iEnemyNo, int iState);	// エネミー配置.
		virtual int Proc();	// 処理をするProc.
		virtual void Draw();	// 描画をするDraw.
		void RemoveAll();	// 全て削除.
		void Destroy();	// 破棄Destroy.

};

#endif