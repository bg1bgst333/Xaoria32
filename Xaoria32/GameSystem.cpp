// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <shlobj.h>	// �V�F���I�u�W�F�N�g.
// �Ǝ��̃w�b�_
#include "GameSystem.h"	// CGameSystem

// �R���X�g���N�^CGameSystem
CGameSystem::CGameSystem(){

	// �����o�̏�����.
	m_iMode = 0;	// m_iMode��0�ŏ�����.
	m_pSharedResources = NULL;	// m_pSharedResources��NULL�ŏ�����.

}

// �f�X�g���N�^~CGameSystem
CGameSystem::~CGameSystem(){

	// �����o�̏I������.
	m_iMode = 0;	// m_iMode��0���Z�b�g.
	Exit();	// �I������.

}

// ���[�h�̐ݒ�SetMode.
void CGameSystem::SetMode(int iMode){

	// �����o�ɐݒ�.
	m_iMode = iMode;	// m_iMode��iMode���Z�b�g.

}

// ���[�h�̎擾GetMode.
int CGameSystem::GetMode(){

	// �����o���擾.
	return m_iMode;	// m_iMode��Ԃ�.

}

// �X�R�A���o��AppendScore.
void CGameSystem::AppendScore(HWND hWnd){

	// �X�R�A���O�͂��̕ӂŏ������܂Ȃ��Ƃ����Ȃ�.
	CTextFile *pTextFile = new CTextFile();	// CTextFile�I�u�W�F�N�g����.
	TCHAR tszScore[1024] = {0};	// tszScore��{0}�ŏ�����.
	_stprintf(tszScore, _T("%d"), m_nScore);	// m_nScore��tszScore�ɕϊ�.
	SYSTEMTIME st;	// SYSTEMTIME�\����st.
	TCHAR *tszWeek[] = {_T("Sun"), _T("Mon"), _T("Tue"), _T("Wed"), _T("Thu"), _T("Fri"), _T("Sat")};	// tszWeek��������.
	GetLocalTime(&st);	// ���[�J�����Ԃ��擾.
	TCHAR tszTimeStamp[1024] = {0};	// tszTimeStamp��{0}�ŏ�����.
	_stprintf(tszTimeStamp, _T("[%04d/%02d/%02d %s %02d:%02d:%02d.%03d] : "), st.wYear, st.wMonth, st.wDay, tszWeek[st.wDayOfWeek], st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);	// tszTimeStamp�Ɏ���������i�[.
	tstring tstrText = tszTimeStamp;	// tszText��tszTimeStamp�A��.
	tstrText = tstrText + tszScore;	// tszScore�A��.
	tstrText = tstrText + _T("\r\n");	// ���s�A��.
	pTextFile->SetText(tstrText);	// �Z�b�g.
	TCHAR tszPath[1024] = {0};	// CSIDL_PERSONAL�ȃp�X���i�[����z��tszPath��{0}�ŏ�����.
	::SHGetSpecialFolderPath(hWnd, tszPath, CSIDL_PERSONAL, FALSE);	// SHGetSpecialFolderPath��CSIDL_PERSONAL�ȃp�X���擾.
	tstring tstrPath = tszPath;	// tstrPath�Ɋi�[.
	tstrPath = tstrPath + _T("\\xaoria_score.log");	// "\\score.log"��A��.
	pTextFile->Append(tstrPath.c_str());	// Append�ŒǋL.
	delete pTextFile;	// pTextFile��delete�ō폜.

}

// ������.
void CGameSystem::Init(HINSTANCE hInstance){

	// �V�F�A�[�h���\�[�X����.
	m_pSharedResources = new CSharedResources(hInstance);	// CSharedResources�̃R���X�g���N�^��hInstance��n���Đ���.
	m_nRest = 3;	// �c�@��3�Ƃ���.
	m_nScore = 0;	// �X�R�A��0�Ƃ���.

}

// �I������.
void CGameSystem::Exit(){

	// �V�F�A�[�h���\�[�X�j��.
	if (m_pSharedResources != NULL){	// m_pSharedResources��NULL.
		delete m_pSharedResources;	// delete��m_pSharedResources���폜.
		m_pSharedResources = NULL;	// m_pSharedResources��NULL���Z�b�g.
	}

}