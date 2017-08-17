#pragma once


// CDukeDlg 对话框

class CDukeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDukeDlg)

public:
	CDukeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDukeDlg();
	CBitmap *m_pBmp[10]; // 位图指针数组
	BITMAP m_bs; // 位图结构变量
	bool m_bStarted; // 判别动画是否启动（初始化为false）
	int m_nCurFrame, // 当前帧号（初值为0）
		m_nFramesPerSecond; // 每秒帧数（初值为10）
	CSliderCtrl *m_pSlider;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DUKE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAniStartStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeN();
};
