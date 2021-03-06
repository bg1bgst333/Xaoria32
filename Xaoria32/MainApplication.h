// 二重インクルード防止
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "GameApplication.h"	// CGameApplication

// メインアプリケーションクラスCMainApplication
class CMainApplication : public CGameApplication{

	// publicメンバ
	public:

		// publicメンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance.
		virtual int Main();	// ゲームメイン処理関数Main.

};

#endif