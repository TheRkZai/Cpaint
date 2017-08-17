// PaintDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Cpaint.h"
#include "PaintDlg.h"
#include "afxdialogex.h"


// CPaintDlg 对话框

IMPLEMENT_DYNAMIC(CPaintDlg, CDialogEx)

CPaintDlg::CPaintDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PAINT, pParent)
	, INT_LINE_WIDTH(0)
	, m_combo_line(_T(""))
	, m_Radio(0)
	, m_fill(FALSE)
	, m_radio_brush(0)
	, m_hatch_style(_T(""))
{
	is_load_new = FALSE;
}

CPaintDlg::~CPaintDlg()
{

}


void CPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LINE_WIDTH, INT_LINE_WIDTH);
	DDV_MinMaxInt(pDX, INT_LINE_WIDTH, 0, 50);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON_PEN, m_ColorPicker);
	DDX_CBString(pDX, IDC_COMBO_LINE_TYPE, m_combo_line);
	DDX_Radio(pDX, IDC_RADIO_STRAIGHT_LINE, m_Radio);
	DDX_Check(pDX, IDC_CHECK_FILL, m_fill);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_brush_color);
	DDX_Radio(pDX, IDC_RADIO_EMPTY, m_radio_brush);
	DDX_CBString(pDX, IDC_COMBO_HATCH, m_hatch_style);
}


BEGIN_MESSAGE_MAP(CPaintDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_STRAIGHT_LINE, &CPaintDlg::OnBnClickedRadioStraightLine)
	ON_BN_CLICKED(IDC_RADIO_RECTANGLE, &CPaintDlg::OnBnClickedRadioRectangle)
	ON_BN_CLICKED(IDC_RADIO_ROUND_RECT, &CPaintDlg::OnBnClickedRadioRoundRect)
	ON_BN_CLICKED(IDC_RADIO_CIRCLE, &CPaintDlg::OnBnClickedRadioCircle)
	ON_BN_CLICKED(IDC_RADIO_ELLIPSE, &CPaintDlg::OnBnClickedRadioEllipse)
	ON_BN_CLICKED(IDC_RADIO_POLYLINE, &CPaintDlg::OnBnClickedRadioPolyline)
	ON_BN_CLICKED(IDC_RADIO_POLYGON, &CPaintDlg::OnBnClickedRadioPolygon)
	ON_BN_CLICKED(IDC_RADIO_TEXT, &CPaintDlg::OnBnClickedRadioText)
	ON_BN_CLICKED(IDC_RADIO_EMPTY, &CPaintDlg::OnBnClickedRadioEmpty)
	ON_BN_CLICKED(IDC_RADIO_REAL, &CPaintDlg::OnBnClickedRadioReal)
	ON_BN_CLICKED(IDC_RADIO_HATCH, &CPaintDlg::OnBnClickedRadioHatch)
	ON_BN_CLICKED(IDC_RADIO_PATTERN, &CPaintDlg::OnBnClickedRadioPattern)
	ON_STN_CLICKED(IDC_STATIC_PICTURE, &CPaintDlg::OnStnClickedStaticPicture)
END_MESSAGE_MAP()


// CPaintDlg 消息处理程序


BOOL CPaintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CSpinButtonCtrl *pSpin =
		(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_LINE_WIDTh);
	pSpin->SetRange(0, 50);

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_COMBO_LINE_TYPE);
	pCB->AddString(L"实心");
	pCB->AddString(L"虚线");
	pCB->AddString(L"点线");
	pCB->AddString(L"虚点线");
	pCB->AddString(L"虚点点线");
	pCB->AddString(L"空笔");
	pCB->AddString(L"框内");
	pCB->SetCurSel(3);

	
	// TODO:  在此添加额外的初始化
	CComboBox* pCB_1 = (CComboBox*)GetDlgItem(IDC_COMBO_HATCH);
	pCB_1->AddString(L"水平线");
	pCB_1->AddString(L"垂直线");
	pCB_1->AddString(L"正斜线");
	pCB_1->AddString(L"反斜线");
	pCB_1->AddString(L"十字线(正网格)");
	pCB_1->AddString(L"斜十字线(斜网格)");
		pCB->SetCurSel(3);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CPaintDlg::OnBnClickedRadioStraightLine()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 0;
}


void CPaintDlg::OnBnClickedRadioRectangle()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 1;
}


void CPaintDlg::OnBnClickedRadioRoundRect()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 2;
}


void CPaintDlg::OnBnClickedRadioCircle()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 3;
}


void CPaintDlg::OnBnClickedRadioEllipse()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 4;
}


void CPaintDlg::OnBnClickedRadioPolyline()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 5;
}


void CPaintDlg::OnBnClickedRadioPolygon()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 6;
}


void CPaintDlg::OnBnClickedRadioText()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 7;
}


void CPaintDlg::OnBnClickedRadioEmpty()
{
	// TODO: 在此添加控件通知处理程序代码
	m_radio_brush = 0;
}


void CPaintDlg::OnBnClickedRadioReal()
{
	// TODO: 在此添加控件通知处理程序代码
	m_radio_brush = 1;
}


void CPaintDlg::OnBnClickedRadioHatch()
{
	// TODO: 在此添加控件通知处理程序代码
	m_radio_brush = 2;
}


void CPaintDlg::OnBnClickedRadioPattern()
{
	// TODO: 在此添加控件通知处理程序代码
	m_radio_brush = 3;
}


void CPaintDlg::OnStnClickedStaticPicture()
{
	if (is_load_new)
	{
		img.Detach();
		img_1.Detach();
	}
	// TODO: 在此添加控件通知处理程序代码
	wchar_t *filters = L"位图文件(*.bmp)|*.bmp|可交换图形格式文件(*.gif)|*.gif|联合图像专家组文件(*.jpg)|*.jpg|可移植网络图形文件(*.png)|*.png|所有文件(*.*)|*.*||";
	CFileDialog fileDlg(TRUE, L"bmp", L"*.bmp",
		OFN_HIDEREADONLY, filters);
	CString sFileName;
	if (fileDlg.DoModal() == IDOK)
		sFileName = fileDlg.GetPathName();
	else return;
	img.Load(sFileName);
	if (img.IsNull()) return;
	img_1.Load(sFileName);
	if (img.IsNull()) return;
	//显示图像
	CStatic *pWnd = (CStatic*)GetDlgItem(IDC_STATIC_PICTURE); //获得pictrue控件窗口的句柄
	CRect rect;
	pWnd->GetClientRect(&rect); //获得pictrue控件所在的矩形区域
	CBitmap bmp_1;
	bmp_1.Attach(img_1);
	CDC *pDC_1 = pWnd->GetDC(); //获得pictrue控件的DC
	CDC dc_1;
	dc_1.CreateCompatibleDC(pDC_1);
	dc_1.SelectObject(&bmp_1);
	BITMAP bs;
	bmp_1.GetBitmap(&bs);
	pDC_1->SetStretchBltMode(COLORONCOLOR);
	pDC_1->StretchBlt(0, 0, rect.right, rect.bottom, &dc_1, 0, 0,
		bs.bmWidth, bs.bmHeight, SRCCOPY);
	bmp_1.Detach();
	ReleaseDC(pDC_1);
	is_load_new = TRUE;
}


