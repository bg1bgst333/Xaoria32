// 二重インクルード防止
#ifndef __BINARY_FILE_H__
#define __BINARY_FILE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "File.h"	// CFile

// バイナリファイルクラスCBinaryFile
class CBinaryFile : public CFile{

	// publicメンバ
	public:

		// publicメンバ変数
		BYTE *m_pBytes;	// バイト列へのポインタ.
		DWORD m_dwSize;	// ファイルサイズ.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CBinaryFile();	// コンストラクタCBinaryFile
		virtual ~CBinaryFile();	// デストラクタ~CBinaryFile
		virtual BOOL Read(LPCTSTR lpctszFileName);	// 指定のバイナリファイルを全部一斉読み込み.
		virtual BOOL Read(LPCTSTR lpctszFileName, DWORD dwStart, DWORD dwSize);	// 指定のバイナリファイルを指定の位置から指定のサイズ分読み込む.
		virtual BOOL Read(DWORD dwSize);	// 以前のファイルで以前読み込んだ後の位置から指定のサイズを読み込む.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// 指定のバイナリファイルに全部一斉書き込み.
		virtual BOOL Write();	// 開いているバイナリファイルへの追加書き込み.
		virtual BOOL Append(LPCTSTR lpctszFileName);	// 指定のバイナリファイルに追加書き込み.
		virtual void Set(BYTE *pBytes, DWORD dwSize);	// 全部一斉に書き込むバッファのセット.
		virtual void Clear();	// バッファのクリア.

};

#endif