// ヘッダのインクルード
// 独自のヘッダ
#include "BinaryFile.h"	// CBinaryFile

// コンストラクタCBinaryFile
CBinaryFile::CBinaryFile() : CFile(){

	// メンバの初期化
	m_pBytes = NULL;	// m_pBytesをNULLにセット.
	m_dwSize = 0;		// m_dwSizeを0にセット.

}

// デストラクタ~CBinaryFile
CBinaryFile::~CBinaryFile() {

	// ファイルとバッファをクリアする.
	Close();	// ファイルを閉じる.
	Clear();	// バッファを破棄.

}

// 指定のバイナリファイルを全部一斉読み込み.
BOOL CBinaryFile::Read(LPCTSTR lpctszFileName) {

	// いったんファイルを閉じて, バッファもクリアする.
	Close();	// ファイルを閉じる.
	Clear();	// バッファを破棄.

	// ファイルのオープン
	BOOL bRet = Open(lpctszFileName, GENERIC_READ, OPEN_EXISTING);	// Openで指定のファイルを開く.
	if (bRet) {	// 成功.

		// ファイルサイズの取得.
		DWORD dwSize = GetFileSize(m_hFile, NULL);	// GetFileSizeでサイズを取得し, dwSizeに格納.

		// バッファの作成.
		m_pBytes = new BYTE[dwSize + 1];	// newでdwSize + 1のバイト列を作成し, ポインタをm_pBytesに格納.
		ZeroMemory(m_pBytes, dwSize + 1);	// ZeroMemoryでm_pBytesを(dwSize + 1)分, 0で埋める.

		// ファイルの読み込み.
		m_dwSize = CFile::Read(m_pBytes, dwSize);	// CFile::Readでデータを読み込む.
		if (m_dwSize == dwSize) {	// 全て読み込めたら.
			return TRUE;	// 成功.
		}

	}

	// 失敗.
	return FALSE;	// FALSEを返す.

}

// 指定のバイナリファイルを指定の位置から指定のサイズ分読み込む.
BOOL CBinaryFile::Read(LPCTSTR lpctszFileName, DWORD dwStart, DWORD dwSize){

	// いったんファイルを閉じて, バッファもクリアする.
	Close();	// ファイルを閉じる.
	Clear();	// バッファを破棄.

	// ファイルのオープン
	BOOL bRet = Open(lpctszFileName, GENERIC_READ, OPEN_EXISTING);	// Openで指定のファイルを開く.
	if (bRet) {	// 成功.

		// ファイルポインタの移動.
		SetFilePointer(m_hFile, (LONG)dwStart, NULL, FILE_BEGIN);	// SetFilePointerでdwStartの位置まで移動.

		// バッファの作成.
		m_pBytes = new BYTE[dwSize + 1];	// newでdwSize + 1のバイト列を作成し, ポインタをm_pBytesに格納.
		ZeroMemory(m_pBytes, dwSize + 1);	// ZeroMemoryでm_pBytesを(dwSize + 1)分, 0で埋める.

		// ファイルの読み込み.
		m_dwSize = CFile::Read(m_pBytes, dwSize);	// CFile::Readでデータを読み込む.
		if (m_dwSize == dwSize) {	// 全て読み込めたら.
			return TRUE;	// 成功.
		}

	}

	// 失敗.
	return FALSE;	// FALSEを返す.

}

// 以前のファイルで以前読み込んだ後の位置から指定のサイズを読み込む.
BOOL CBinaryFile::Read(DWORD dwSize){

	// ファイルを開いていない場合はエラー, 開いている場合読み込む.
	if (m_tstrFileName.c_str() == _T("") && m_hFile == NULL) {
		return FALSE;	// ファイルを開いていない場合はFALSEを返す.
	}
	else {	// ファイルを開いている場合.

		// バッファを破棄.
		Clear();	// バッファを破棄.

		// バッファの作成.
		m_pBytes = new BYTE[dwSize + 1];	// newでdwSize + 1のバイト列を作成し, ポインタをm_pBytesに格納.
		ZeroMemory(m_pBytes, dwSize + 1);	// ZeroMemoryでm_pBytesを(dwSize + 1)分, 0で埋める.

		// ファイルの読み込み.
		m_dwSize = CFile::Read(m_pBytes, dwSize);	// CFile::Readでデータを読み込む.
		if (m_dwSize == dwSize) {	// 全て読み込めたら.
			return TRUE;	// 成功.
		}
		
	}

	// 失敗.
	return FALSE;	// FALSEを返す.

}

// 指定のバイナリファイルに全部一斉書き込み.
BOOL CBinaryFile::Write(LPCTSTR lpctszFileName) {

	// ファイルのオープン
	BOOL bRet = Open(lpctszFileName, GENERIC_WRITE, CREATE_ALWAYS);	// Openで指定のファイルを開く.
	if (bRet) {	// 成功.

		// ファイルの書き込み.
		CFile::Write(m_pBytes, m_dwSize);	// CFile::Writeでデータを書き込む.

	}

	// bRetで成功かどうかがわかる.
	return bRet;	// bRetを返す.

}

// 開いているバイナリファイルへの追加書き込み.
BOOL CBinaryFile::Write() {

	// 引数なしバージョンは, 既にファイルを開いている前提で, Setで新たにバッファにセットしたバイト列を継続して書き込む.
	if (m_tstrFileName.c_str() == _T("") && m_hFile == NULL) {
		return FALSE;	// ファイルを開いていない場合はFALSEを返す.
	}
	else {	// ファイルを開いている場合.
		CFile::Write(m_pBytes, m_dwSize);	// CFile::Writeでデータを書き込む.
		return TRUE;	// 書き込んだのでTRUE.
	}

}

// 指定のバイナリファイルに追加書き込み.
BOOL CBinaryFile::Append(LPCTSTR lpctszFileName){
	
	// ファイルのオープン
	BOOL bRet = Open(lpctszFileName, FILE_APPEND_DATA, OPEN_ALWAYS);	// Openで指定のファイルを開く.
	if (bRet) {	// 成功.

		// ファイルの書き込み.
		::SetFilePointer(m_hFile, 0, NULL, FILE_END);	// SetFilePointerで末尾に.
		CFile::Write(m_pBytes, m_dwSize);	// CFile::Writeでデータを書き込む.

	}

	// bRetで成功かどうかがわかる.
	return bRet;	// bRetを返す.

}

// 全部一斉に書き込むバッファのセット.
void CBinaryFile::Set(BYTE * pBytes, DWORD dwSize) {

	// バッファをクリアする.
	Clear();	// バッファを破棄.

	// メンバにセット.
	m_dwSize = dwSize;	// m_dwSizeにdwSizeをセット.

	// バッファの作成.
	m_pBytes = new BYTE[m_dwSize + 1];	// newでm_dwSize + 1のバイト列を作成し, ポインタをm_pBytesに格納.
	ZeroMemory(m_pBytes, m_dwSize + 1);	// ZeroMemoryでm_pBytesを(m_dwSize + 1)分, 0で埋める.

	// データのコピー.
	CopyMemory(m_pBytes, pBytes, m_dwSize);	// CopyMemoryでコピー.

}

// バッファのクリア.
void CBinaryFile::Clear() {

	// バッファの破棄.
	if (m_pBytes != NULL) {	// バッファが残っていたら.
		delete[] m_pBytes;	// delete[]でm_pBytesを解放.
		m_pBytes = NULL;	// m_pBytesにNULLをセット.
	}
	m_dwSize = 0;	// サイズも0にする.

}