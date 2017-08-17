// InputString.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Cpaint.h"
#include "InputString.h"
#include "afxdialogex.h"


// CInputString �Ի���

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


// CInputString ��Ϣ�������


BOOL CInputString::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	input_string = L"�������ַ���";
	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT_INPUT);
	pBoxOne->SetWindowTextW(input_string);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
