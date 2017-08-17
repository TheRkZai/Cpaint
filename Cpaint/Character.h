#pragma once


// Character 对话框

class Character : public CDialogEx
{
	DECLARE_DYNAMIC(Character)

public:
	Character(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Character();
	CFont m_font;
	LOGFONT m_logFont;
	wchar_t m_fontName[LF_FACESIZE];
	int m_iFontSize;
	COLORREF m_textColor;
	BOOL m_bItalic, m_bBold, m_bUnderline, m_bStrikeOut;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHARACTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCharacter();
	int x_axis;
	int y_axis;
	CString input_string;
	virtual BOOL OnInitDialog();
};
