// PenSize.cpp : 实现文件
//

#include "stdafx.h"
#include "Cpaint.h"
#include "PenSize.h"
#include "afxdialogex.h"


// CPenSize 对话框

IMPLEMENT_DYNAMIC(CPenSize, CDialogEx)

CPenSize::CPenSize(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CHAR_SET, pParent)
	, pen_size(0)
{

}

CPenSize::~CPenSize()
{
}

void CPenSize::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PEN_SIZE, pen_size);
	DDV_MinMaxInt(pDX, pen_size, 0, 300);
}


BEGIN_MESSAGE_MAP(CPenSize, CDialogEx)
END_MESSAGE_MAP()


// CPenSize 消息处理程序


BOOL CPenSize::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CSpinButtonCtrl *pSpin =
		(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_PEN_SIZE);
	pSpin->SetRange(0, 100);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
