// Character.cpp : 实现文件
//

#include "stdafx.h"
#include "Cpaint.h"
#include "Character.h"
#include "afxdialogex.h"


// Character 对话框

IMPLEMENT_DYNAMIC(Character, CDialogEx)

Character::Character(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CHARACTER, pParent)
	, x_axis(0)
	, y_axis(0)
	, input_string(_T(""))
{
	wcscpy_s(m_fontName, LF_FACESIZE, L"宋体");
	m_iFontSize = 120;
	m_font.CreatePointFont(m_iFontSize, m_fontName);
	m_font.GetLogFont(&m_logFont);
	m_textColor = RGB(0, 0, 0);
	m_bItalic = false;
	m_bBold = false;
	m_bUnderline = false;
	m_bStrikeOut = false;
	x_axis = 0;
	y_axis = 0;
	input_string = L"请输入字符串";
}

Character::~Character()
{
}

void Character::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X, x_axis);
	DDV_MinMaxInt(pDX, x_axis, 0, 900);
	DDX_Text(pDX, IDC_EDIT_Y, y_axis);
	DDV_MinMaxInt(pDX, y_axis, 0, 300);
	DDX_Text(pDX, IDC_EDIT_STRING, input_string);
}


BEGIN_MESSAGE_MAP(Character, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CHARACTER, &Character::OnBnClickedButtonCharacter)
END_MESSAGE_MAP()


// Character 消息处理程序


void Character::OnBnClickedButtonCharacter()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	CFontDialog fontDlg(&m_logFont);
	fontDlg.m_cf.rgbColors = m_textColor;
	if (fontDlg.DoModal() == IDOK) {
		wcscpy_s(m_fontName, LF_FACESIZE, fontDlg.GetFaceName());
		m_iFontSize = fontDlg.GetSize();
		m_textColor = fontDlg.GetColor();
		m_bItalic = fontDlg.IsItalic();
		m_bBold = fontDlg.IsBold();
		m_bStrikeOut = fontDlg.IsStrikeOut();
		m_bUnderline = fontDlg.IsUnderline();
	}
}


BOOL Character::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	input_string = L"请输入字符串";
	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT_STRING);
	pBoxOne->SetWindowTextW(input_string);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
