#pragma once


// Character �Ի���

class Character : public CDialogEx
{
	DECLARE_DYNAMIC(Character)

public:
	Character(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Character();
	CFont m_font;
	LOGFONT m_logFont;
	wchar_t m_fontName[LF_FACESIZE];
	int m_iFontSize;
	COLORREF m_textColor;
	BOOL m_bItalic, m_bBold, m_bUnderline, m_bStrikeOut;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHARACTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCharacter();
	int x_axis;
	int y_axis;
	CString input_string;
	virtual BOOL OnInitDialog();
};
