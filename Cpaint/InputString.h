#pragma once


// CInputString �Ի���

class CInputString : public CDialogEx
{
	DECLARE_DYNAMIC(CInputString)

public:
	CInputString(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInputString();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INPUT_STRING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString input_string;
	virtual BOOL OnInitDialog();
};
