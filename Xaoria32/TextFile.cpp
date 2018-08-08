// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "TextFile.h"	// CTextFile
#include "cpp_string_utility.h"	// class_cpp_string_utility

// �R���X�g���N�^CTextFile
CTextFile::CTextFile() : CBinaryFile(){

	// �����o�̏�����
	m_tstrText.clear();	// m_tstrText.clear�ŃN���A.
	m_Encoding = ENCODING_NONE;	// m_Encoding��ENCODING_NONE�ŏ�����.
	m_Bom = BOM_NONE;	// m_Bom��BOM_NONE�ŏ�����.
	m_NewLine = NEW_LINE_NONE;	// m_NewLine��NEW_LINE_NONE�ŏ�����.

}

// �f�X�g���N�^~CTextFile
CTextFile::~CTextFile(){

	// �t�@�C���ƃo�b�t�@���N���A����.
	Close();	// �t�@�C�������.
	Clear();	// �o�b�t�@��j��.

}

// BOM�̃`�F�b�N.
CTextFile::BOM CTextFile::CheckBom(){

	// BOM�̔���.
	if (m_dwSize >= 2 && m_pBytes[0] == 0xff && m_pBytes[1] == 0xfe) {	// UTF-16LE�̏ꍇ.
		m_Bom = BOM_UTF16LE;	// BOM_UTF16LE���Z�b�g.
	}
	else {	// ����ȊO��Shift_JIS.
		m_Bom = BOM_NONE;	// BOM_NONE���Z�b�g.
	}
	return m_Bom;	// m_Bom��Ԃ�.

}

// ���s�̃`�F�b�N.
CTextFile::NEW_LINE CTextFile::CheckNewLine(){

	// �܂�CR('\r')��T��.
	size_t f = m_tstrText.find_first_of(_T('\r'));	// '\r'�̈ʒu��f�Ɋi�[.
	if (f != -1 && f < m_tstrText.length() - 1){	// f('\r')�����������ꍇ.
		if (m_tstrText[f + 1] == '\n'){	// ����'\n'�̏ꍇ.
			m_NewLine = NEW_LINE_CRLF;	// NEW_LINE_CRLF���Z�b�g.
		}
		else{	// '\r'����.
			m_NewLine = NEW_LINE_CR;	// NEW_LINE_CR���Z�b�g.
		}
	}
	else{	// '\r'�͂Ȃ��̂�, '\n'��T��.
		f = m_tstrText.find_first_of(_T('\n'));	// '\n'�̈ʒu��f�Ɋi�[.
		if (f != -1){	// f('\n')�����������ꍇ.
			m_NewLine = NEW_LINE_LF;	// NEW_LINE_LF���Z�b�g.
		}
		else{	// '\n'���Ȃ�.
			m_NewLine = NEW_LINE_NONE;	// NEW_LINE_NONE���Z�b�g.
		}
	}

	// ���s�R�[�h��Ԃ�.
	return m_NewLine;	// ��Ԃ�.

}

// UTF16LE�̃o�C�g�f�[�^���e�L�X�g�Ƀf�R�[�h.
void CTextFile::DecodeUtf16LE(){

	// UTF16LE�`���o�C�i����tstring�ɕϊ�.
	TCHAR *ptszText = new TCHAR[m_dwSize - 2 + 1];	// (�S�̂̃o�C�g�� - BOM�̃o�C�g��) + NULL����.
	wmemset(ptszText, _T('\0'), m_dwSize - 2 + 1);	// wmemset��ptszText��0�Ŗ��߂�.
	memcpy(ptszText, m_pBytes + 2, m_dwSize - 2);	// memcpy��m_pBytes��3�o�C�g�ڂ���ptszText�ɃR�s�[.
	m_tstrText = ptszText;	// m_tstrText��ptszText���Z�b�g.
	delete [] ptszText;	// delete[]��ptszText�����.

}

// Shift_JIS�̃o�C�g�f�[�^���e�L�X�g�Ƀf�R�[�h.
void CTextFile::DecodeShiftJis(){

	// Shift_JIS�`���o�C�i����tstring�ɕϊ�.
	int len = MultiByteToWideChar(CP_ACP, 0, (char *)m_pBytes, -1, NULL, NULL);	// MultiByteToWideChar�Ńo�C�g��̕ϊ��ɕK�v�ȃo�b�t�@�̒���len�����߂�.
	TCHAR *ptszText = new TCHAR[len];	// len�̕���TCHAR���I�z���p�ӂ�, �|�C���^��ptszText�Ɋi�[.
	wmemset(ptszText, _T('\0'), len);	// wmemset��ptszText��0�Ŗ��߂�.
	MultiByteToWideChar(CP_ACP, 0, (char *)m_pBytes, -1, ptszText, len);	// MultiByteToWideChar�Ń}���`�o�C�g�������烏�C�h�����ւ̕ϊ�.
	m_tstrText = ptszText;	// m_tstrText��ptszText���Z�b�g.
	delete [] ptszText;	// delete[]��ptszText�����.

}

// ���s�R�[�h�̕ϊ�.
void CTextFile::ConvertNewLine(tstring &tstrText, CTextFile::NEW_LINE dest, CTextFile::NEW_LINE src){

	// ���s�R�[�h��u��������.
	tstring before;	// �u���Obefore.
	if (src == CTextFile::NEW_LINE_CRLF){	// CRLF
		before = _T("\r\n");	// before��"\r\n"���Z�b�g.
	}
	else if (src == CTextFile::NEW_LINE_LF){	// LF
		before = _T("\n");	// before��"\n"���Z�b�g.
	}
	else if (src == CTextFile::NEW_LINE_CR){	// CR
		before = _T("\r");	// before��"\r"���Z�b�g.
	}
	tstring after;	// �u����after.
	if (dest == CTextFile::NEW_LINE_CRLF){	// CRLF
		after = _T("\r\n");	// after��"\r\n"���Z�b�g.
	}
	else if (dest == CTextFile::NEW_LINE_LF){	// LF
		after = _T("\n");	// after��"\n"���Z�b�g.
	}
	else if (dest == CTextFile::NEW_LINE_CR){	// CR
		after = _T("\r");	// after��"\r"���Z�b�g.
	}
	if (before != after){	// before��after���Ⴄ��.
		class_cpp_string_utility::replace(tstrText, before, after);	// replace�Œu��.
	}

}

// �w��̃e�L�X�g�t�@�C����S����ēǂݍ���.
BOOL CTextFile::Read(LPCTSTR lpctszFileName){

	// �t�@�C���ƃo�b�t�@���N���A����.
	Close();	// �t�@�C�������.
	Clear();	// �o�b�t�@��j��.

	// �w�肳�ꂽ�t�@�C�����̃t�@�C����ǂݍ���.
	if (CBinaryFile::Read(lpctszFileName)) {	// �ǂݍ��݂ɐ���������.
		CheckBom();	// BOM�̃`�F�b�N.
		if (m_Bom == BOM_UTF16LE){	// UTF-16LE.
			m_Encoding = ENCODING_UNICODE;	// Unicode.
			DecodeUtf16LE();	// DecodeUtf16LE�Ńo�C�g����e�L�X�g�ɕϊ�.
		}
		else{	// Shift_Jis.
			m_Encoding = ENCODING_SHIFT_JIS;	// Shift_Jis.
			DecodeShiftJis();	// DecodeShiftJis�Ńo�C�g����e�L�X�g�ɕϊ�.
		}
		CheckNewLine();	// ���s�R�[�h�̃`�F�b�N.
		if (m_NewLine != NEW_LINE_NONE){	// ���s�Ȃ��ł͂Ȃ��ꍇ.
			ConvertNewLine(m_tstrText, CTextFile::NEW_LINE_CRLF, m_NewLine);	// ConvertNewLine��CRLF�ɕϊ�.
		}
		return TRUE;	// TRUE��Ԃ�.
	}

	// FALSE.
	return FALSE;	// FAlSE��Ԃ�.

}

// �e�L�X�g�̃Z�b�g.
void CTextFile::SetText(tstring tstrText){

	// �����o�ɃZ�b�g.
	m_tstrText = tstrText;	// m_tstrText��tstrText���Z�b�g.

}

// �w��̃e�L�X�g��UTF-16LE�ɕϊ�.
void CTextFile::EncodeUtf16LEWithBom(tstring tstrText){

	// �o�C�g��̃Z�b�g.
	BYTE *pByteWithBOM = new BYTE[(tstrText.length() + 1) * 2];	// BOM�t���o�C�g����i�[����z��pByteWithBOM.
	pByteWithBOM[0] = 0xff;	// 0�Ԗڂ�0xff.
	pByteWithBOM[1] = 0xfe;	// 1�Ԗڂ�0xfe.
	memcpy(pByteWithBOM + 2, (BYTE *)tstrText.c_str(), tstrText.length() * 2);	// pByteWithBOM + 2�ȍ~�ɃR�s�[.
	Set(pByteWithBOM, (tstrText.length() + 1) * 2);	// pByteWithBOM���Z�b�g.(�T���Q�[�g�y�A��Ή�.)
	delete[] pByteWithBOM;	// delete��pByteWithBOM�����.

}

// �w��̃e�L�X�g��Shift_JIS�ɕϊ�.
void CTextFile::EncodeShiftJis(tstring tstrText){

	// �o�C�g��̃Z�b�g.
	int len = WideCharToMultiByte(CP_ACP, 0, tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// �ϊ��ɕK�v�ȃo�b�t�@�̒������擾.
	BYTE *pByte = new BYTE[len];	// �o�C�g����i�[����z��pByte.
	ZeroMemory(pByte, sizeof(BYTE) * len);	// pByte��0�Ŗ��߂�.
	WideCharToMultiByte(CP_ACP, 0, tstrText.c_str(), -1, (char *)pByte, len, NULL, NULL);	// ���C�h��������}���`�o�C�g�����ւ̕ϊ�.
	if (len > 0) {	// len��0���傫���ꍇ.
		Set(pByte, len - 1);	// pByte��(len - 1)���Z�b�g.
	}
	delete[] pByte;	// delete��pByte�����.

}

// �w��̃e�L�X�g�t�@�C���ɑS����ď�������.
BOOL CTextFile::Write(LPCTSTR lpctszFileName){

	// �e�L�X�g���ꎞ�ۑ�.
	tstring tstrTemp = m_tstrText;	// tstrTemp��m_tstrText���i�[.
	ENCODING encoding = m_Encoding;	// encoding��m_Encoding���i�[.
	BOM bom = m_Bom;	// bom��m_Bom���i�[.
	NEW_LINE newline = m_NewLine;	// newline��m_NewLine���i�[.

	// �t�@�C���ƃo�b�t�@���N���A����.
	Close();	// �t�@�C�������.
	Clear();	// �o�b�t�@��j��.

	// ����.
	m_tstrText = tstrTemp;	// m_tstrText��tstrTemp���i�[.
	m_Encoding = encoding;	// m_Encoding��encoding���i�[.
	m_Bom = bom;	// m_Bom��bom���i�[.
	m_NewLine = newline;	// m_NewLine��newline���i�[.

	// ���s�R�[�h�̃`�F�b�N.(CRLF�Ȃ�ύX���Ȃ�.)
	if (newline == NEW_LINE_CR){	// CR.
		ConvertNewLine(tstrTemp, NEW_LINE_CR, NEW_LINE_CRLF);	// ConverNewLine��CRLF����CR�ɕϊ�.
	}
	else if (newline == NEW_LINE_LF){	// LF.
		ConvertNewLine(tstrTemp, NEW_LINE_LF, NEW_LINE_CRLF);	// ConverNewLine��CRLF����LF�ɕϊ�.
	}

	// �����R�[�h�̃`�F�b�N.
	if (encoding == ENCODING_UNICODE){	// Unicode.
		EncodeUtf16LEWithBom(tstrTemp);	// �e�L�X�g�������UTF-16LE�o�C�g��ɕϊ�,
	}
	else{	// Shift_JIS.
		EncodeShiftJis(tstrTemp);	// �e�L�X�g�������Shift_JIS�o�C�g��ɕϊ�.
	}

	// ��������.
	CBinaryFile::Write(lpctszFileName);	// CBinaryFile:Write�ŏ�������.

	// TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �w��̃e�L�X�g�t�@�C���ɒǉ���������.
BOOL CTextFile::Append(LPCTSTR lpctszFileName){

	// �e�L�X�g���ꎞ�ۑ�.
	tstring tstrTemp = m_tstrText;	// tstrTemp��m_tstrText���i�[.
	ENCODING encoding = m_Encoding;	// encoding��m_Encoding���i�[.
	BOM bom = m_Bom;	// bom��m_Bom���i�[.
	NEW_LINE newline = m_NewLine;	// newline��m_NewLine���i�[.

	// �t�@�C���ƃo�b�t�@���N���A����.
	Close();	// �t�@�C�������.
	Clear();	// �o�b�t�@��j��.

	// ����.
	m_tstrText = tstrTemp;	// m_tstrText��tstrTemp���i�[.
	m_Encoding = encoding;	// m_Encoding��encoding���i�[.
	m_Bom = bom;	// m_Bom��bom���i�[.
	m_NewLine = newline;	// m_NewLine��newline���i�[.

	// ���s�R�[�h�̃`�F�b�N.(CRLF�Ȃ�ύX���Ȃ�.)
	if (newline == NEW_LINE_CR){	// CR.
		ConvertNewLine(tstrTemp, NEW_LINE_CR, NEW_LINE_CRLF);	// ConverNewLine��CRLF����CR�ɕϊ�.
	}
	else if (newline == NEW_LINE_LF){	// LF.
		ConvertNewLine(tstrTemp, NEW_LINE_LF, NEW_LINE_CRLF);	// ConverNewLine��CRLF����LF�ɕϊ�.
	}

	// �����R�[�h�̃`�F�b�N.
	if (encoding == ENCODING_UNICODE){	// Unicode.
		EncodeUtf16LEWithBom(tstrTemp);	// �e�L�X�g�������UTF-16LE�o�C�g��ɕϊ�,
	}
	else{	// Shift_JIS.
		EncodeShiftJis(tstrTemp);	// �e�L�X�g�������Shift_JIS�o�C�g��ɕϊ�.
	}

	// �ǉ���������.
	CBinaryFile::Append(lpctszFileName);	// CBinaryFile::Append�Œǉ���������.

	// TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �o�b�t�@�̃N���A.
void CTextFile::Clear(){

	// �����o�̏I������.
	m_tstrText.clear();	// m_tstrText.clear�ŃN���A.
	m_Encoding = ENCODING_NONE;	// m_Encoding��ENCODING_NONE���Z�b�g.
	m_Bom = BOM_NONE;	// m_Bom��BOM_NONE���Z�b�g.
	m_NewLine = NEW_LINE_NONE;	// m_NewLine��NEW_LINE_NONE���Z�b�g.

	// �e�N���X��Clear���Ă�.
	CBinaryFile::Clear();	// CBinaryFile::Clear�Ńo�b�t�@�Ȃǂ��N���A.

}