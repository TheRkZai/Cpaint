#pragma once


// CInputString 对话框

class CInputString : public CDialogEx
{
	DECLARE_DYNAMIC(CInputString)

public:
	CInputString(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInputString();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INPUT_STRING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString input_string;
	virtual BOOL OnInitDialog();
};
