// PenSize.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Cpaint.h"
#include "PenSize.h"
#include "afxdialogex.h"


// CPenSize �Ի���

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


// CPenSize ��Ϣ�������


BOOL CPenSize::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CSpinButtonCtrl *pSpin =
		(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_PEN_SIZE);
	pSpin->SetRange(0, 100);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
