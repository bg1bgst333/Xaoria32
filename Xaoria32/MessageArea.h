// ��d�C���N���[�h�h�~
#ifndef __MESSAGE_AREA_H__
#define __MESSAGE_AREA_H__

// �Ǝ��̃w�b�_
#include "GameObject.h"	// CGameObject

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// ���b�Z�[�W�G���A�N���XCMessageArea
class CMessageArea : public CGameObject{

	// public�����o
	public:

		// public�����o�ϐ�
		HFONT m_hFont;	// �t�H���gm_hFont.
		HFONT m_hOldFont;	// �ȑO�̃t�H���gm_hOldFont.
		int m_iLineHeight;	// �s�̍���m_iLineHeight.
		int m_iMargin;	// �s�̊Ԋum_iMargin.
		BOOL m_bVisible;	// �\�����m_bVisible.
		DWORD m_dwVisibleInterval;	// �\���Ԋum_dwVisibleInterval.
		DWORD m_dwVisibleTimerStart;	// �\���^�C�}�[�J�n����m_dwVisibleTimerStart.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMessageArea();	// �R���X�g���N�^CMessageArea()
		CMessageArea(const CScene *pScene);	// �R���X�g���N�^CMessageArea(const CScene *pScene)
		virtual ~CMessageArea();	// �f�X�g���N�^~CMessageArea()
		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName, int iMargin);	// �Q�[���I�u�W�F�N�g�̍쐬Create.
		virtual void Destroy();	// �Q�[���I�u�W�F�N�g�̔j��Destroy.
		virtual void DrawMessage(int x, int y, LPCTSTR lpctszMessage, COLORREF clrColor);	// ���b�Z�[�W�̕`��DrawMessage.
		virtual void SetVisibleTimer(DWORD dwInterval);	// �\���^�C�}�[�̃Z�b�gSetVisibleTimer.
		virtual BOOL IsVisibleElapsed();	// �\���^�C�}�[���o�ߎ��Ԃ��߂��������`�F�b�NIsVisibleElapsed.

};

#endif