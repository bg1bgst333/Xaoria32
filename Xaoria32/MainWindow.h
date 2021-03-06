// 二重インクルード防止
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string
// 独自のヘッダ
#include "MenuWindow.h"	// CMenuWindow
#include "resource.h"	// リソース.

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// メインウィンドウクラスCMainWindow
class CMainWindow : public CMenuWindow{

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMainWindow();	// コンストラクタCMainWindow()
		virtual ~CMainWindow();	// デストラクタ~CMainWindow()
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpszMenuName);	// ウィンドウクラス登録関数RegisterClass.(メニュー名指定バージョン.)
		// メンバ関数バージョン.
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual void Destroy();	// ウィンドウの破棄と終了処理関数Destroy.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.
		virtual void OnPaint();	// ウィンドウの描画を要求された時のハンドラOnPaint.
		virtual int OnClose();	// ウィンドウを閉じた時.
		virtual int OnAppExit(WPARAM wParam, LPARAM lParam);	// "アプリケーションの終了"を選択された時のハンドラ.

};

#endif