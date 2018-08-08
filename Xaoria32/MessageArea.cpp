// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MessageArea.h"	// CMessageArea

// �R���X�g���N�^CMessageArea()
CMessageArea::CMessageArea() : CGameObject(){

	// �����o�̏�����.
	m_hFont = NULL;	// m_hFont��NULL�ŏ�����.
	m_hOldFont = NULL;	// m_hOldFont��NULL�ŏ�����.
	m_iLineHeight = 0;	// m_iLineHeight��0�ŏ�����.
	m_iMargin = 0;	// m_iMargin��0�ŏ�����.
	m_bVisible = FALSE;	// m_bVisible��FALSE�ŏ�����.
	m_dwVisibleInterval = 0;	// m_dwVisibleInterval��0�ŏ�����.
	m_dwVisibleTimerStart = 0;	// m_dwVisibleTimerStart��0�ŏ�����.

}

// �R���X�g���N�^CMessageArea(const CScene *pScene)
CMessageArea::CMessageArea(const CScene *pScene) : CGameObject(pScene){

	// �����o�̏�����.
	m_hFont = NULL;	// m_hFont��NULL�ŏ�����.
	m_hOldFont = NULL;	// m_hOldFont��NULL�ŏ�����.
	m_iLineHeight = 0;	// m_iLineHeight��0�ŏ�����.
	m_iMargin = 0;	// m_iMargin��0�ŏ�����.
	m_bVisible = FALSE;	// m_bVisible��FALSE�ŏ�����.
	m_dwVisibleInterval = 0;	// m_dwVisibleInterval��0�ŏ�����.
	m_dwVisibleTimerStart = 0;	// m_dwVisibleTimerStart��0�ŏ�����.

}

// �f�X�g���N�^~CMessageArea()
CMessageArea::~CMessageArea(){

}

// �Q�[���I�u�W�F�N�g�̍쐬Create.
BOOL CMessageArea::Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName, int iMargin){

	// �ʒu�ƃT�C�Y�̎擾.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	m_iWidth = iWidth;	// m_iWidth��iWidth���Z�b�g.
	m_iHeight = iHeight;	// m_iHeight��iHeight���Z�b�g.
	m_bVisible = FALSE;	// m_bVisible��FALSE���Z�b�g.

	// �t�H���g�̍쐬.
	m_hFont = CreateFont(nFontSize, 0, 0, 0, FW_REGULAR, TRUE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, lpctszFontName);	// CreateFont�Ńt�H���g���쐬��, m_hFont�Ɋi�[.
	if (m_hFont == NULL){	// m_hFont��NULL�Ȃ�.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �t�H���g�̑I��.
	m_hOldFont = (HFONT)SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObject��m_hFont��I��.

	// �e�L�X�g�̍������擾.
	TEXTMETRIC tm;	// �t�H���g��������TEXTMETRIC�\���̕ϐ�tm.
	GetTextMetrics(m_pScene->m_hMemDC, &tm);	// GetTextMetrics��tm�̓��e���擾.
	m_iLineHeight = tm.tmHeight;	// m_iLineHeight��tm.tmHeight���Z�b�g.

	// �s�̊Ԋu�̃Z�b�g.
	m_iMargin = iMargin;	// m_iMargin��iMargin���Z�b�g.

	// �����Ȃ̂�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̔j��Destroy.
void CMessageArea::Destroy(){

	// �����o�̏I������.
	m_x = 0;	// m_x��0����.
	m_y = 0;	// m_y��0����.
	m_iWidth = 0;	// m_iWidth��0����.
	m_iHeight = 0;	// m_iHeight��0����.
	m_iMargin = 0;	// m_iMargin��0����.
	m_iLineHeight = 0;	// m_iLineHeight��0����.

	// �t�H���g��߂�.
	if (m_hOldFont != NULL){	// m_hOldFont��NULL�łȂ����.
		SelectObject(m_pScene->m_hMemDC, m_hOldFont);	// SelectObject��m_hOldFont�ɖ߂�.
		m_hOldFont = NULL;	// m_hOldFont��NULL���Z�b�g.
	}

	// �t�H���g�̍폜.
	if (m_hFont != NULL){	// m_hFont��NULL�łȂ����.
		DeleteObject(m_hFont);	// DeleteObject��m_hFont���폜.
		m_hFont = NULL;	// m_hFont��NULL���Z�b�g.
	}

}

// ���b�Z�[�W�̕`��DrawMessage.
void CMessageArea::DrawMessage(int x, int y, LPCTSTR lpctszMessage, COLORREF clrColor){

	// �e.
	// �O����.
	SetTextColor(m_pScene->m_hMemDC, RGB(89, 34, 13));	// SetTextColor�ŐF��clrColor���w��.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkMode�Ŕw�i�͓���.
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObject��m_hFont��I��.
	// �`��.
	RECT rc = {0};
	rc.left = x + 2;
	rc.top = y + 2;
	rc.right = x + m_iWidth + 2;
	rc.bottom = y + m_iHeight + 2;
	if (m_bVisible){	// TRUE�Ȃ�\��.
		::DrawText(m_pScene->m_hMemDC, lpctszMessage, _tcslen(lpctszMessage), &rc, DT_LEFT | DT_SINGLELINE);	// DrawText�ŕ`��.
	}

	// ���C���e�L�X�g.
	// �O����.
	SetTextColor(m_pScene->m_hMemDC, clrColor);	// SetTextColor�ŐF��clrColor���w��.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkMode�Ŕw�i�͓���.
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObject��m_hFont��I��.
	// �`��.
	RECT rc2 = {0};
	rc2.left = x;
	rc2.top = y;
	rc2.right = x + m_iWidth;
	rc2.bottom = y + m_iHeight;
	if (m_bVisible){	// TRUE�Ȃ�\��.
		::DrawText(m_pScene->m_hMemDC, lpctszMessage, _tcslen(lpctszMessage), &rc2, DT_LEFT | DT_SINGLELINE);	// DrawText�ŕ`��.
	}

}

// �\���^�C�}�[�̃Z�b�gSetVisibleTimer.
void CMessageArea::SetVisibleTimer(DWORD dwInterval){

	// �\���C���^�[�o���̃Z�b�g.
	m_dwVisibleInterval = dwInterval;	// m_dwVisibleInterval��dwInterval���Z�b�g.

	// �^�C�}�[�̃Z�b�g.
	const CScene *pScene = m_pScene;	// m_pScene��pScene�Ɋi�[.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTime��pTime�Ɋi�[.
	m_dwVisibleTimerStart = pTime->GetSystemTime();	// pTime->GetSystemTime�Ŏ擾����������m_dwVisibleTimerStart�Ɋi�[.


}

// �\���^�C�}�[���o�ߎ��Ԃ��߂��������`�F�b�NIsVisibleElapsed.
BOOL CMessageArea::IsVisibleElapsed(){

	// ���ݎ����̎擾.
	const CScene *pScene = m_pScene;	// m_pScene��pScene�Ɋi�[.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTime��pTime�Ɋi�[.
	DWORD dwNow = pTime->GetSystemTime();	// pTime->GetSystemTime�Ŏ擾����������dwNow�Ɋi�[.

	// �o�ߎ��ԃ`�F�b�N.
	if (dwNow - m_dwVisibleTimerStart >= m_dwVisibleInterval){	// m_dwVisibleInterval�ȏ�Ȃ�.
		m_dwVisibleTimerStart = dwNow;	// dwNow��m_dwVisibleTimerStart�ɃZ�b�g.
		return TRUE;	// TRUE��Ԃ�.
	}
	else{
		return FALSE;	// FALSE��Ԃ�.
	}

}