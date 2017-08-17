// DukeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Cpaint.h"
#include "DukeDlg.h"
#include "afxdialogex.h"


// CDukeDlg 对话框

IMPLEMENT_DYNAMIC(CDukeDlg, CDialogEx)

CDukeDlg::CDukeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_DUKE, pParent)
{

}

CDukeDlg::~CDukeDlg()
{
	for (int i = 0; i < 10; i++) delete m_pBmp[i];
}

void CDukeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDukeDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDukeDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_ANI_START_STOP, &CDukeDlg::OnBnClickedAniStartStop)
	ON_WM_TIMER()
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_N, &CDukeDlg::OnEnChangeN)
END_MESSAGE_MAP()


// CDukeDlg 消息处理程序




void CDukeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL CDukeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for (int i = 0; i < 10; i++) { // 装入位图资源
		m_pBmp[i] = new CBitmap;
		m_pBmp[i]->LoadBitmap(IDB_DUKE1 + i);
	}
	m_pBmp[0]->GetBitmap(&m_bs); //获取位图结构
	m_bStarted = false; // 设置已开始动画为假
	m_nCurFrame = 0; // 设置初始的当前帧为0
	m_nFramesPerSecond = 10; // 设置初始动画速度为每秒10帧
	m_pSlider = (CSliderCtrl *)GetDlgItem(IDC_SLIDER_N);
	m_pSlider->SetRange(1, 100);
	m_pSlider->SetPos(m_nFramesPerSecond);
	SetDlgItemInt(IDC_DUKE, m_nFramesPerSecond); // 设置编辑框初值

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDukeDlg::OnBnClickedAniStartStop()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_bStarted) { // 已开始动画
		m_bStarted = false; // 设置已开始动画为假
		KillTimer(1); // 停止计时器
					  // 设置按钮文本为“开始动画”
		SetDlgItemText(IDC_ANI_START_STOP, L"开始动画");
	}
	else { // 未开始动画
		m_bStarted = true; // 设置已开始动画为真
		m_nCurFrame = 0; // // 设置当前帧为0
						 // 获取编辑框中的帧速值
		m_nFramesPerSecond = GetDlgItemInt(IDC_N);
		if (m_nFramesPerSecond <= 0) // 限制最小帧速值为1
			m_nFramesPerSecond = 1;
		else if (m_nFramesPerSecond > 100) // 最大帧速值为100
			m_nFramesPerSecond = 100;
		// 用调整后帧速值重新设置编辑框的内容
		SetDlgItemInt(IDC_N, m_nFramesPerSecond);
		// 利用帧速值来设置计时器
		SetTimer(1, (UINT)(1000.0 / m_nFramesPerSecond + 0.5), NULL);
		// 设置按钮文本为“停止动画”
		SetDlgItemText(IDC_ANI_START_STOP, L"停止动画");
	}

}


void CDukeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC = GetDlgItem(IDC_DUKE)->GetDC(); // 获取图片框DC
	CDC dc; // 定义内存DC
	dc.CreateCompatibleDC(pDC); // 创建兼容DC
	dc.SelectObject(m_pBmp[m_nCurFrame]); // 选入当前帧位图
	pDC->BitBlt(0, 0, m_bs.bmWidth, m_bs.bmHeight, &dc,
		0, 0, SRCCOPY); // 显示当前帧位图
	m_nCurFrame++; // 当前帧加1（设置下一次要显示的位图序号）
	m_nCurFrame %= 10; // 当前帧余10（避免超出位图数组，实现循环）

	CDialogEx::OnTimer(nIDEvent);
}


void CDukeDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetDlgItemInt(IDC_N, m_pSlider->GetPos());
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDukeDlg::OnEnChangeN()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	m_pSlider->SetPos(GetDlgItemInt(IDC_N));
	// TODO:  在此添加控件通知处理程序代码
}
