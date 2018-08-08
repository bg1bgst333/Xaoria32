// ��d�C���N���[�h�h�~
#ifndef __STATUS_BOX_H__
#define __STATUS_BOX_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string

// �Ǝ��̃w�b�_
#include "GameObject.h"	// CGameObject

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �X�e�[�^�X�{�b�N�X�N���XCStatusBox
class CStatusBox : public CGameObject{

	// public�����o
	public:

		// public�����o�ϐ�
		HFONT m_hFont;	// �t�H���gm_hFont.
		HFONT m_hOldFont;	// �ȑO�̃t�H���gm_hOldFont.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CStatusBox();	// �R���X�g���N�^CStatusBox
		CStatusBox(const CScene *pScene);	// �R���X�g���N�^CStatusBox(const CScene *pScene)
		virtual ~CStatusBox();	// �f�X�g���N�^~CStatusBox

		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName);	// �Q�[���I�u�W�F�N�g�̍쐬Create.
		virtual void Destroy();	// �Q�[���I�u�W�F�N�g�̔j��Destroy.
		virtual void DrawText(int x, int y, int iWidth, int iHeight, LPCTSTR lpctszText, COLORREF clrColor);	// DrawText�Ńe�L�X�g��`��.
		virtual void DrawRest(int x, int y, int iWidth, int iHeight, COLORREF clrColor);	// DrawRest�Ŏc�@��`��.
		virtual void DrawScore(int x, int y, int iWidth, int iHeight, COLORREF clrColor);	// DrawScore�ŃX�R�A��`��.
		
};

#endif