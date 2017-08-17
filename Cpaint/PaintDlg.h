#pragma once
#include "afxcolorbutton.h"
#include "afxwin.h"

// CPaintDlg �Ի���

class CPaintDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPaintDlg)

public:
	CPaintDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPaintDlg();
	CString comboxcurstring;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAINT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int INT_LINE_WIDTH;
	CMFCColorButton m_ColorPicker;
	CString m_combo_line;
	CImage img;
	CImage img_1;
	BOOL is_load_new;
	afx_msg void OnBnClickedRadioStraightLine();
	int m_Radio;
	afx_msg void OnBnClickedRadioRectangle();
	afx_msg void OnBnClickedRadioRoundRect();
	afx_msg void OnBnClickedRadioCircle();
	afx_msg void OnBnClickedRadioEllipse();
	afx_msg void OnBnClickedRadioPolyline();
	afx_msg void OnBnClickedRadioPolygon();
	afx_msg void OnBnClickedRadioText();
	BOOL m_fill;
	CMFCColorButton m_brush_color;
	int m_radio_brush;
	afx_msg void OnBnClickedRadioEmpty();
	afx_msg void OnBnClickedRadioReal();
	afx_msg void OnBnClickedRadioHatch();
	afx_msg void OnBnClickedRadioPattern();
	CString m_hatch_style;
	afx_msg void OnStnClickedStaticPicture();
//	afx_msg void OnCharSelect();
};
