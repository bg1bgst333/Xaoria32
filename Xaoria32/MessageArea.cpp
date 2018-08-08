// ヘッダのインクルード
// 独自のヘッダ
#include "MessageArea.h"	// CMessageArea

// コンストラクタCMessageArea()
CMessageArea::CMessageArea() : CGameObject(){

	// メンバの初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.
	m_iLineHeight = 0;	// m_iLineHeightを0で初期化.
	m_iMargin = 0;	// m_iMarginを0で初期化.
	m_bVisible = FALSE;	// m_bVisibleをFALSEで初期化.
	m_dwVisibleInterval = 0;	// m_dwVisibleIntervalを0で初期化.
	m_dwVisibleTimerStart = 0;	// m_dwVisibleTimerStartを0で初期化.

}

// コンストラクタCMessageArea(const CScene *pScene)
CMessageArea::CMessageArea(const CScene *pScene) : CGameObject(pScene){

	// メンバの初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.
	m_iLineHeight = 0;	// m_iLineHeightを0で初期化.
	m_iMargin = 0;	// m_iMarginを0で初期化.
	m_bVisible = FALSE;	// m_bVisibleをFALSEで初期化.
	m_dwVisibleInterval = 0;	// m_dwVisibleIntervalを0で初期化.
	m_dwVisibleTimerStart = 0;	// m_dwVisibleTimerStartを0で初期化.

}

// デストラクタ~CMessageArea()
CMessageArea::~CMessageArea(){

}

// ゲームオブジェクトの作成Create.
BOOL CMessageArea::Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName, int iMargin){

	// 位置とサイズの取得.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = iWidth;	// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.
	m_bVisible = FALSE;	// m_bVisibleにFALSEをセット.

	// フォントの作成.
	m_hFont = CreateFont(nFontSize, 0, 0, 0, FW_REGULAR, TRUE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, lpctszFontName);	// CreateFontでフォントを作成し, m_hFontに格納.
	if (m_hFont == NULL){	// m_hFontがNULLなら.
		return FALSE;	// FALSEを返す.
	}

	// フォントの選択.
	m_hOldFont = (HFONT)SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.

	// テキストの高さを取得.
	TEXTMETRIC tm;	// フォント情報を持つTEXTMETRIC構造体変数tm.
	GetTextMetrics(m_pScene->m_hMemDC, &tm);	// GetTextMetricsでtmの内容を取得.
	m_iLineHeight = tm.tmHeight;	// m_iLineHeightにtm.tmHeightをセット.

	// 行の間隔のセット.
	m_iMargin = iMargin;	// m_iMarginにiMarginをセット.

	// 成功なのでTRUE.
	return TRUE;	// TRUEを返す.

}

// ゲームオブジェクトの破棄Destroy.
void CMessageArea::Destroy(){

	// メンバの終了処理.
	m_x = 0;	// m_xに0を代入.
	m_y = 0;	// m_yに0を代入.
	m_iWidth = 0;	// m_iWidthに0を代入.
	m_iHeight = 0;	// m_iHeightに0を代入.
	m_iMargin = 0;	// m_iMarginに0を代入.
	m_iLineHeight = 0;	// m_iLineHeightに0を代入.

	// フォントを戻す.
	if (m_hOldFont != NULL){	// m_hOldFontがNULLでなければ.
		SelectObject(m_pScene->m_hMemDC, m_hOldFont);	// SelectObjectでm_hOldFontに戻す.
		m_hOldFont = NULL;	// m_hOldFontにNULLをセット.
	}

	// フォントの削除.
	if (m_hFont != NULL){	// m_hFontがNULLでなければ.
		DeleteObject(m_hFont);	// DeleteObjectでm_hFontを削除.
		m_hFont = NULL;	// m_hFontにNULLをセット.
	}

}

// メッセージの描画DrawMessage.
void CMessageArea::DrawMessage(int x, int y, LPCTSTR lpctszMessage, COLORREF clrColor){

	// 影.
	// 前準備.
	SetTextColor(m_pScene->m_hMemDC, RGB(89, 34, 13));	// SetTextColorで色はclrColorを指定.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkModeで背景は透過.
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.
	// 描画.
	RECT rc = {0};
	rc.left = x + 2;
	rc.top = y + 2;
	rc.right = x + m_iWidth + 2;
	rc.bottom = y + m_iHeight + 2;
	if (m_bVisible){	// TRUEなら表示.
		::DrawText(m_pScene->m_hMemDC, lpctszMessage, _tcslen(lpctszMessage), &rc, DT_LEFT | DT_SINGLELINE);	// DrawTextで描画.
	}

	// メインテキスト.
	// 前準備.
	SetTextColor(m_pScene->m_hMemDC, clrColor);	// SetTextColorで色はclrColorを指定.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkModeで背景は透過.
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.
	// 描画.
	RECT rc2 = {0};
	rc2.left = x;
	rc2.top = y;
	rc2.right = x + m_iWidth;
	rc2.bottom = y + m_iHeight;
	if (m_bVisible){	// TRUEなら表示.
		::DrawText(m_pScene->m_hMemDC, lpctszMessage, _tcslen(lpctszMessage), &rc2, DT_LEFT | DT_SINGLELINE);	// DrawTextで描画.
	}

}

// 表示タイマーのセットSetVisibleTimer.
void CMessageArea::SetVisibleTimer(DWORD dwInterval){

	// 表示インターバルのセット.
	m_dwVisibleInterval = dwInterval;	// m_dwVisibleIntervalにdwIntervalをセット.

	// タイマーのセット.
	const CScene *pScene = m_pScene;	// m_pSceneをpSceneに格納.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTimeをpTimeに格納.
	m_dwVisibleTimerStart = pTime->GetSystemTime();	// pTime->GetSystemTimeで取得した時刻をm_dwVisibleTimerStartに格納.


}

// 表示タイマーが経過時間を過ぎたかをチェックIsVisibleElapsed.
BOOL CMessageArea::IsVisibleElapsed(){

	// 現在時刻の取得.
	const CScene *pScene = m_pScene;	// m_pSceneをpSceneに格納.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTimeをpTimeに格納.
	DWORD dwNow = pTime->GetSystemTime();	// pTime->GetSystemTimeで取得した時刻をdwNowに格納.

	// 経過時間チェック.
	if (dwNow - m_dwVisibleTimerStart >= m_dwVisibleInterval){	// m_dwVisibleInterval以上なら.
		m_dwVisibleTimerStart = dwNow;	// dwNowをm_dwVisibleTimerStartにセット.
		return TRUE;	// TRUEを返す.
	}
	else{
		return FALSE;	// FALSEを返す.
	}

}