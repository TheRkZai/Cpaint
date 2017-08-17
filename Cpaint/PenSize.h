#pragma once


// CPenSize 对话框

class CPenSize : public CDialogEx
{
	DECLARE_DYNAMIC(CPenSize)

public:
	CPenSize(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPenSize();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHAR_SET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int pen_size;
	virtual BOOL OnInitDialog();
};
