// 二重インクルード防止
#ifndef __ENEMY_H__
#define __ENEMY_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Character.h"	// CCharacter

// エネミークラスCEnemy
class CEnemy : public CCharacter{

	// publicメンバ
	public:

		// publicメンバ変数
		int m_iNo;	// アニメーション番号m_iNo.
		CSharedObject *m_pExplosion;	// エクスプロージョンオブジェクトm_pExplosion.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CEnemy();	// コンストラクタCEnemy
		CEnemy(CScene *pScene);	// デストラクタCEnemy(CScene *pScene)
		virtual ~CEnemy();	// デストラクタ~CEnemy()
		virtual void Destroy();	// キャラクターの破棄Destroy.
		virtual int Proc();	// 処理をするProc.
		virtual void Set(int x, int y);	// 位置をセットするSet.
		virtual void Set(int iNo);	// アニメーションをセットするSet.
		virtual void Draw();	// 描画をするDraw.
		virtual void CreateExplosion(int nFirstX, int nFirstY, int iWidth, int iHeight, int nID);	// エクスプロージョンの作成CreateExplosion.
		virtual void DrawExplosion(int x, int y, int nAnimationNo);	// エクスプロージョンを描画するDrawExplosion.

};

#endif