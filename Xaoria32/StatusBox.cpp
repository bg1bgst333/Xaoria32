// ヘッダのインクルード
// 独自のヘッダ
#include "StatusBox.h"	// CStatusBox

// コンストラクタCStatusBox
CStatusBox::CStatusBox() : CGameObject(){

	// メンバの初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.

}

// コンストラクタCStatusBox(const CScene *pScene)
CStatusBox::CStatusBox(const CScene *pScene) : CGameObject(pScene){

	// メンバの初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.

}

// デストラクタ~CStatusBox
CStatusBox::~CStatusBox(){

}

// ゲームオブジェクトの作成Create.
BOOL CStatusBox::Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName){

	// 位置とサイズの取得.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = iWidth;	// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.

	// フォントの作成.
	m_hFont = CreateFont(nFontSize, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, lpctszFontName);	// CreateFontでフォントを作成し, m_hFontに格納.
	if (m_hFont == NULL){	// m_hFontがNULLなら.
		return FALSE;	// FALSEを返す.
	}

	// フォントの選択.
	m_hOldFont = (HFONT)SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.

	// 成功なのでTRUE.
	return TRUE;	// TRUEを返す.

}

// ゲームオブジェクトの破棄Destroy.
void CStatusBox::Destroy(){

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

// DrawTextでテキストを描画.
void CStatusBox::DrawText(int x, int y, int iWidth, int iHeight, LPCTSTR lpctszText, COLORREF clrColor){
	
	// テキストを描画.
	RECT rc = {x, y, x + iWidth, y + iHeight};	// rcを引数を使って初期化.
	SetTextColor(m_pScene->m_hMemDC, clrColor);	// SetTextColorで色はclrColorを指定.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkModeで背景は透過.
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.
	::DrawText(m_pScene->m_hMemDC, lpctszText, _tcslen(lpctszText), &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);	// WindowsAPIのDrawTextでタイトル文字列の描画.

}

// DrawRestで残機を描画.
void CStatusBox::DrawRest(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// 残機を取得.
	TCHAR tszRest[256] = {0};	// TCHAR配列tszRestを{0}で初期化.
	_stprintf(tszRest, _T("REST : %lu"), m_pScene->m_pGameSystem->m_nRest);	// _stprintfでm_pScene->m_pGameSystem->m_nRestからtszRestに変換.
	DrawText(x, y, iWidth, iHeight, tszRest, clrColor);	// DrawTextで残機を描画.

}

// DrawScoreでスコアを描画.
void CStatusBox::DrawScore(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// スコアを取得.
	TCHAR tszScore[256] = {0};	// TCHAR配列tszScoreを{0}で初期化.
	_stprintf(tszScore, _T("SCORE: %lu"), m_pScene->m_pGameSystem->m_nScore);	// _stprintfでm_pScene->m_pGameSystem->m_nScoreからtszScoreに変換.
	DrawText(x, y, iWidth, iHeight, tszScore, clrColor);	// DrawTextでスコアを描画.

}