// PaintDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Cpaint.h"
#include "PaintDlg.h"
#include "afxdialogex.h"


// CPaintDlg �Ի���

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


// CPaintDlg ��Ϣ�������


BOOL CPaintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CSpinButtonCtrl *pSpin =
		(CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_LINE_WIDTh);
	pSpin->SetRange(0, 50);

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_COMBO_LINE_TYPE);
	pCB->AddString(L"ʵ��");
	pCB->AddString(L"����");
	pCB->AddString(L"����");
	pCB->AddString(L"�����");
	pCB->AddString(L"������");
	pCB->AddString(L"�ձ�");
	pCB->AddString(L"����");
	pCB->SetCurSel(3);

	
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CComboBox* pCB_1 = (CComboBox*)GetDlgItem(IDC_COMBO_HATCH);
	pCB_1->AddString(L"ˮƽ��");
	pCB_1->AddString(L"��ֱ��");
	pCB_1->AddString(L"��б��");
	pCB_1->AddString(L"��б��");
	pCB_1->AddString(L"ʮ����(������)");
	pCB_1->AddString(L"бʮ����(б����)");
		pCB->SetCurSel(3);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CPaintDlg::OnBnClickedRadioStraightLine()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 0;
}


void CPaintDlg::OnBnClickedRadioRectangle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 1;
}


void CPaintDlg::OnBnClickedRadioRoundRect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 2;
}


void CPaintDlg::OnBnClickedRadioCircle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 3;
}


void CPaintDlg::OnBnClickedRadioEllipse()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 4;
}


void CPaintDlg::OnBnClickedRadioPolyline()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 5;
}


void CPaintDlg::OnBnClickedRadioPolygon()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 6;
}


void CPaintDlg::OnBnClickedRadioText()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 7;
}


void CPaintDlg::OnBnClickedRadioEmpty()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_radio_brush = 0;
}


void CPaintDlg::OnBnClickedRadioReal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_radio_brush = 1;
}


void CPaintDlg::OnBnClickedRadioHatch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_radio_brush = 2;
}


void CPaintDlg::OnBnClickedRadioPattern()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_radio_brush = 3;
}


void CPaintDlg::OnStnClickedStaticPicture()
{
	if (is_load_new)
	{
		img.Detach();
		img_1.Detach();
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	wchar_t *filters = L"λͼ�ļ�(*.bmp)|*.bmp|�ɽ���ͼ�θ�ʽ�ļ�(*.gif)|*.gif|����ͼ��ר�����ļ�(*.jpg)|*.jpg|����ֲ����ͼ���ļ�(*.png)|*.png|�����ļ�(*.*)|*.*||";
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
	//��ʾͼ��
	CStatic *pWnd = (CStatic*)GetDlgItem(IDC_STATIC_PICTURE); //���pictrue�ؼ����ڵľ��
	CRect rect;
	pWnd->GetClientRect(&rect); //���pictrue�ؼ����ڵľ�������
	CBitmap bmp_1;
	bmp_1.Attach(img_1);
	CDC *pDC_1 = pWnd->GetDC(); //���pictrue�ؼ���DC
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


