// InputString.cpp : 实现文件
//

#include "stdafx.h"
#include "Cpaint.h"
#include "InputString.h"
#include "afxdialogex.h"


// CInputString 对话框

IMPLEMENT_DYNAMIC(CInputString, CDialogEx)

CInputString::CInputString(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_INPUT_STRING, pParent)
	, input_string(_T(""))
{

}

CInputString::~CInputString()
{
}

void CInputString::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, input_string);
}


BEGIN_MESSAGE_MAP(CInputString, CDialogEx)
END_MESSAGE_MAP()


// CInputString 消息处理程序


BOOL CInputString::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	input_string = L"请输入字符串";
	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT_INPUT);
	pBoxOne->SetWindowTextW(input_string);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
