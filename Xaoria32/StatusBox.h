// 二重インクルード防止
#ifndef __STATUS_BOX_H__
#define __STATUS_BOX_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string

// 独自のヘッダ
#include "GameObject.h"	// CGameObject

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// ステータスボックスクラスCStatusBox
class CStatusBox : public CGameObject{

	// publicメンバ
	public:

		// publicメンバ変数
		HFONT m_hFont;	// フォントm_hFont.
		HFONT m_hOldFont;	// 以前のフォントm_hOldFont.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CStatusBox();	// コンストラクタCStatusBox
		CStatusBox(const CScene *pScene);	// コンストラクタCStatusBox(const CScene *pScene)
		virtual ~CStatusBox();	// デストラクタ~CStatusBox

		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName);	// ゲームオブジェクトの作成Create.
		virtual void Destroy();	// ゲームオブジェクトの破棄Destroy.
		virtual void DrawText(int x, int y, int iWidth, int iHeight, LPCTSTR lpctszText, COLORREF clrColor);	// DrawTextでテキストを描画.
		virtual void DrawRest(int x, int y, int iWidth, int iHeight, COLORREF clrColor);	// DrawRestで残機を描画.
		virtual void DrawScore(int x, int y, int iWidth, int iHeight, COLORREF clrColor);	// DrawScoreでスコアを描画.
		
};

#endif