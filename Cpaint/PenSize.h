#pragma once


// CPenSize �Ի���

class CPenSize : public CDialogEx
{
	DECLARE_DYNAMIC(CPenSize)

public:
	CPenSize(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPenSize();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHAR_SET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int pen_size;
	virtual BOOL OnInitDialog();
};
