// 二重インクルード防止
#ifndef __EXPLOSION_H__
#define __EXPLOSION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "SharedObject.h"	// CSharedObject

// エクスプロージョンクラスCExplosion
class CExplosion : public CSharedObject{

	// publicメンバ
	public:

		// publicメンバ変数
		std::vector<CSharedObject *> m_vecpMaskList;	// マスクリストm_vecpMaskList.
		int m_iState;	// 状態.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CExplosion();	// コンストラクタCExplosion()
		CExplosion(CScene *pScene);	// デストラクタCExplosion(CScene *pScene)
		virtual ~CExplosion();	// デストラクタ~CExplosion()
		// メンバ関数
		virtual void Add(int sx, int sy, int iWidth, int iHeight, int nID);	// アニメーションの追加Add.
		virtual void AddMask(int sx, int sy, int iWidth, int iHeight, int nID);	// マスクの追加AddMask.
		virtual void Destroy();	// エクスプロージョンの破棄Destroy.
		virtual void Draw(int x, int y, int iNo);	// シェアードオブジェクトの描画Draw.
		virtual void DrawSprite(int x, int y, int iNo);	// スプライトの描画DrawSprite.
		virtual BOOL DrawAnimation(int x, int y);	// アニメーション描画DrawAnimation.
		virtual void Set(int x, int y);	// 位置をセットするSet.
		virtual void Set(int iState);	// 状態のセット.
		virtual int Get();	// 状態の取得.

};

#endif