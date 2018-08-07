// 二重インクルード防止
#ifndef __MESSAGE_AREA_H__
#define __MESSAGE_AREA_H__

// 独自のヘッダ
#include "GameObject.h"	// CGameObject

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// メッセージエリアクラスCMessageArea
class CMessageArea : public CGameObject{

	// publicメンバ
	public:

		// publicメンバ変数
		HFONT m_hFont;	// フォントm_hFont.
		HFONT m_hOldFont;	// 以前のフォントm_hOldFont.
		int m_iLineHeight;	// 行の高さm_iLineHeight.
		int m_iMargin;	// 行の間隔m_iMargin.
		BOOL m_bVisible;	// 表示状態m_bVisible.
		DWORD m_dwVisibleInterval;	// 表示間隔m_dwVisibleInterval.
		DWORD m_dwVisibleTimerStart;	// 表示タイマー開始時刻m_dwVisibleTimerStart.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMessageArea();	// コンストラクタCMessageArea()
		CMessageArea(const CScene *pScene);	// コンストラクタCMessageArea(const CScene *pScene)
		virtual ~CMessageArea();	// デストラクタ~CMessageArea()
		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName, int iMargin);	// ゲームオブジェクトの作成Create.
		virtual void Destroy();	// ゲームオブジェクトの破棄Destroy.
		virtual void DrawMessage(int x, int y, LPCTSTR lpctszMessage, COLORREF clrColor);	// メッセージの描画DrawMessage.
		virtual void SetVisibleTimer(DWORD dwInterval);	// 表示タイマーのセットSetVisibleTimer.
		virtual BOOL IsVisibleElapsed();	// 表示タイマーが経過時間を過ぎたかをチェックIsVisibleElapsed.

};

#endif