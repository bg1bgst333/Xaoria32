// ヘッダのインクルード
// 既定のヘッダ
#include <shlobj.h>	// シェルオブジェクト.
// 独自のヘッダ
#include "GameSystem.h"	// CGameSystem

// コンストラクタCGameSystem
CGameSystem::CGameSystem(){

	// メンバの初期化.
	m_iMode = 0;	// m_iModeを0で初期化.
	m_pSharedResources = NULL;	// m_pSharedResourcesをNULLで初期化.

}

// デストラクタ~CGameSystem
CGameSystem::~CGameSystem(){

	// メンバの終了処理.
	m_iMode = 0;	// m_iModeに0をセット.
	Exit();	// 終了処理.

}

// モードの設定SetMode.
void CGameSystem::SetMode(int iMode){

	// メンバに設定.
	m_iMode = iMode;	// m_iModeにiModeをセット.

}

// モードの取得GetMode.
int CGameSystem::GetMode(){

	// メンバを取得.
	return m_iMode;	// m_iModeを返す.

}

// スコアを出力AppendScore.
void CGameSystem::AppendScore(HWND hWnd){

	// スコアログはこの辺で書き込まないといけない.
	CTextFile *pTextFile = new CTextFile();	// CTextFileオブジェクト生成.
	TCHAR tszScore[1024] = {0};	// tszScoreを{0}で初期化.
	_stprintf(tszScore, _T("%d"), m_nScore);	// m_nScoreをtszScoreに変換.
	SYSTEMTIME st;	// SYSTEMTIME構造体st.
	TCHAR *tszWeek[] = {_T("Sun"), _T("Mon"), _T("Tue"), _T("Wed"), _T("Thu"), _T("Fri"), _T("Sat")};	// tszWeekを初期化.
	GetLocalTime(&st);	// ローカル時間を取得.
	TCHAR tszTimeStamp[1024] = {0};	// tszTimeStampを{0}で初期化.
	_stprintf(tszTimeStamp, _T("[%04d/%02d/%02d %s %02d:%02d:%02d.%03d] : "), st.wYear, st.wMonth, st.wDay, tszWeek[st.wDayOfWeek], st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);	// tszTimeStampに時刻文字列格納.
	tstring tstrText = tszTimeStamp;	// tszTextにtszTimeStamp連結.
	tstrText = tstrText + tszScore;	// tszScore連結.
	tstrText = tstrText + _T("\r\n");	// 改行連結.
	pTextFile->SetText(tstrText);	// セット.
	TCHAR tszPath[1024] = {0};	// CSIDL_PERSONALなパスを格納する配列tszPathを{0}で初期化.
	::SHGetSpecialFolderPath(hWnd, tszPath, CSIDL_PERSONAL, FALSE);	// SHGetSpecialFolderPathでCSIDL_PERSONALなパスを取得.
	tstring tstrPath = tszPath;	// tstrPathに格納.
	tstrPath = tstrPath + _T("\\xaoria_score.log");	// "\\score.log"を連結.
	pTextFile->Append(tstrPath.c_str());	// Appendで追記.
	delete pTextFile;	// pTextFileをdeleteで削除.

}

// 初期化.
void CGameSystem::Init(HINSTANCE hInstance){

	// シェアードリソース生成.
	m_pSharedResources = new CSharedResources(hInstance);	// CSharedResourcesのコンストラクタにhInstanceを渡して生成.
	m_nRest = 3;	// 残機は3とする.
	m_nScore = 0;	// スコアは0とする.

}

// 終了処理.
void CGameSystem::Exit(){

	// シェアードリソース破棄.
	if (m_pSharedResources != NULL){	// m_pSharedResourcesがNULL.
		delete m_pSharedResources;	// deleteでm_pSharedResourcesを削除.
		m_pSharedResources = NULL;	// m_pSharedResourcesにNULLをセット.
	}

}