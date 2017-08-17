
// CpaintView.cpp : CCpaintView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include"Cpaint.h"
#include"Character.h"
#endif
#include "PaintDlg.h"
#include "CpaintDoc.h"
#include "DukeDlg.h"
#include "CpaintView.h"
#include "MainFrm.h"
#include "PenSize.h"
#include "InputString.h"
#include <cmath>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCpaintView

IMPLEMENT_DYNCREATE(CCpaintView, CView)

BEGIN_MESSAGE_MAP(CCpaintView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PAINT_SET, &CCpaintView::OnPaintSet)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_CLEAR, &CCpaintView::OnClear)
	ON_COMMAND(ID_SHOW_CHARACTER, &CCpaintView::OnShowCharacter)
ON_COMMAND(ID_SCREEN, &CCpaintView::OnScreen)
ON_COMMAND(ID_SCREEN_INTERFACE, &CCpaintView::OnScreenInterface)
ON_COMMAND(ID_DRAW_LINE, &CCpaintView::OnDrawLine)
ON_COMMAND(ID_DRAW_RCETANGLE, &CCpaintView::OnDrawRcetangle)
ON_COMMAND(ID_DRAW_ROUND_RECT, &CCpaintView::OnDrawRoundRect)
ON_COMMAND(ID_DRAW_ROUND, &CCpaintView::OnDrawRound)
ON_COMMAND(ID_DRAW_ELLPISE, &CCpaintView::OnDrawEllpise)
ON_COMMAND(ID_DRAW_POLYLINE, &CCpaintView::OnDrawPolyline)
ON_COMMAND(ID_DRAW_PLOYGON, &CCpaintView::OnDrawPloygon)
ON_COMMAND(ID_PEN_COLOR, &CCpaintView::OnPenColor)
ON_COMMAND(ID_PEN_STYLE_SOLID, &CCpaintView::OnPenStyleSolid)
ON_COMMAND(ID_PEN_STLYE_DASH, &CCpaintView::OnPenStlyeDash)
ON_COMMAND(ID_PEN_STYLE_POT, &CCpaintView::OnPenStylePot)
ON_COMMAND(ID_PEN_STYLE_DASH_DOT, &CCpaintView::OnPenStyleDashDot)
ON_COMMAND(ID_PEN_STYLE_DASH_DOT_DOT, &CCpaintView::OnPenStyleDashDotDot)
ON_COMMAND(ID_PEN_WIDTH_1, &CCpaintView::OnPenWidth1)
ON_COMMAND(ID_PEN_WIDTH_2, &CCpaintView::OnPenWidth2)
ON_COMMAND(ID_PEN_WIDTH_4, &CCpaintView::OnPenWidth4)
ON_COMMAND(ID_PEN_WIDTH_8, &CCpaintView::OnPenWidth8)
ON_COMMAND(ID_PEN_WIDTH_10, &CCpaintView::OnPenWidth10)
ON_COMMAND(ID_PEN_WIDTH_15, &CCpaintView::OnPenWidth15)
ON_COMMAND(ID_WIDTH_20, &CCpaintView::OnWidth20)
ON_COMMAND(ID_PEN_WIDTH_30, &CCpaintView::OnPenWidth30)
ON_COMMAND(ID_PEN_WIDTH_50, &CCpaintView::OnPenWidth50)
ON_COMMAND(ID_PEN_WIDTH_100, &CCpaintView::OnPenWidth100)
ON_COMMAND(ID_PEN_WIDTH_200, &CCpaintView::OnPenWidth200)
ON_COMMAND(ID_PEN_WIDTH_N, &CCpaintView::OnPenWidthN)
ON_COMMAND(ID_BRUSH_COLOR, &CCpaintView::OnBrushColor)
ON_COMMAND(ID_BRUSH_FILL, &CCpaintView::OnBrushFill)
ON_UPDATE_COMMAND_UI(ID_BRUSH_FILL, &CCpaintView::OnUpdateBrushFill)
ON_COMMAND(ID_BRUSH_TYPE_SOLID, &CCpaintView::OnBrushTypeSolid)
ON_COMMAND(ID_BRUSH_TYPE_EMPTY, &CCpaintView::OnBrushTypeEmpty)
ON_COMMAND(ID_HS_HORIZONTAL, &CCpaintView::OnHsHorizontal)
ON_COMMAND(ID_HS_VERTICAL, &CCpaintView::OnHsVertical)
ON_COMMAND(ID_HS_FDIAGONAL, &CCpaintView::OnHsFdiagonal)
ON_COMMAND(ID_HS_BDIAGONAL, &CCpaintView::OnHsBdiagonal)
ON_COMMAND(ID_HS_CROSS, &CCpaintView::OnHsCross)
ON_COMMAND(ID_HS_DIAGCROSS, &CCpaintView::OnHsDiagcross)
ON_UPDATE_COMMAND_UI(ID_BRUSH_TYPE_SOLID, &CCpaintView::OnUpdateBrushTypeSolid)
ON_UPDATE_COMMAND_UI(ID_BRUSH_TYPE_EMPTY, &CCpaintView::OnUpdateBrushTypeEmpty)
ON_UPDATE_COMMAND_UI(ID_PEN_STYLE_SOLID, &CCpaintView::OnUpdatePenStyleSolid)
ON_UPDATE_COMMAND_UI(ID_PEN_STLYE_DASH, &CCpaintView::OnUpdatePenStlyeDash)
ON_UPDATE_COMMAND_UI(ID_PEN_STYLE_POT, &CCpaintView::OnUpdatePenStylePot)
ON_UPDATE_COMMAND_UI(ID_PEN_STYLE_DASH_DOT, &CCpaintView::OnUpdatePenStyleDashDot)
ON_UPDATE_COMMAND_UI(ID_PEN_STYLE_DASH_DOT_DOT, &CCpaintView::OnUpdatePenStyleDashDotDot)
ON_UPDATE_COMMAND_UI(ID_PEN_WIDTH_1, &CCpaintView::OnUpdatePenWidth1)
ON_UPDATE_COMMAND_UI(ID_PEN_WIDTH_2, &CCpaintView::OnUpdatePenWidth2)
ON_UPDATE_COMMAND_UI(ID_PEN_WIDTH_4, &CCpaintView::OnUpdatePenWidth4)
ON_UPDATE_COMMAND_UI(ID_PEN_WIDTH_8, &CCpaintView::OnUpdatePenWidth8)
ON_UPDATE_COMMAND_UI(ID_PEN_WIDTH_10, &CCpaintView::OnUpdatePenWidth10)
ON_UPDATE_COMMAND_UI(ID_PEN_WIDTH_15, &CCpaintView::OnUpdatePenWidth15)
ON_UPDATE_COMMAND_UI(ID_WIDTH_20, &CCpaintView::OnUpdateWidth20)
ON_UPDATE_COMMAND_UI(ID_PEN_WIDTH_30, &CCpaintView::OnUpdatePenWidth30)
ON_UPDATE_COMMAND_UI(ID_PEN_WIDTH_50, &CCpaintView::OnUpdatePenWidth50)
ON_UPDATE_COMMAND_UI(ID_PEN_WIDTH_100, &CCpaintView::OnUpdatePenWidth100)
ON_UPDATE_COMMAND_UI(ID_PEN_WIDTH_200, &CCpaintView::OnUpdatePenWidth200)
ON_COMMAND(ID_BRUSH_TYPE_PICTURE, &CCpaintView::OnBrushTypePicture)
ON_COMMAND(ID_BRUSH_TYPE_CHANGE, &CCpaintView::OnBrushTypeChange)
ON_UPDATE_COMMAND_UI(ID_BRUSH_TYPE_PICTURE, &CCpaintView::OnUpdateBrushTypePicture)
ON_COMMAND(ID_CHAR_SELECT, &CCpaintView::OnCharSelect)
ON_COMMAND(ID_CHAR_COLOR, &CCpaintView::OnCharColor)
ON_COMMAND(ID_CHAR_INPUT, &CCpaintView::OnCharInput)
ON_COMMAND(ID_CHAR_OUPUT, &CCpaintView::OnCharOuput)
ON_COMMAND(ID_CHAR_SIZE, &CCpaintView::OnCharSize)
ON_COMMAND(ID_CHAR_ROTATE, &CCpaintView::OnCharRotate)
ON_COMMAND(ID_BITMAP_OPEN, &CCpaintView::OnBitmapOpen)
ON_UPDATE_COMMAND_UI(ID_BITMAP_NO, &CCpaintView::OnUpdateBitmapNo)
ON_UPDATE_COMMAND_UI(ID_BITMAP_ORIGIN, &CCpaintView::OnUpdateBitmapOrigin)
ON_UPDATE_COMMAND_UI(ID_BITMAP_STRECH, &CCpaintView::OnUpdateBitmapStrech)
ON_COMMAND(ID_BITMAP_NO, &CCpaintView::OnBitmapNo)
ON_COMMAND(ID_BITMAP_ORIGIN, &CCpaintView::OnBitmapOrigin)
ON_COMMAND(ID_BITMAP_STRECH, &CCpaintView::OnBitmapStrech)
ON_UPDATE_COMMAND_UI(ID_BITMAP_MAINTAIN, &CCpaintView::OnUpdateBitmapMaintain)
ON_COMMAND(ID_BITMAP_MAINTAIN, &CCpaintView::OnBitmapMaintain)
ON_COMMAND(ID_BITMAP_FILL_CLIENT, &CCpaintView::OnBitmapFillClient)
ON_UPDATE_COMMAND_UI(ID_BITMAP_FILL_CLIENT, &CCpaintView::OnUpdateBitmapFillClient)
ON_COMMAND(ID_BITMAP_BLACK, &CCpaintView::OnBitmapBlack)
ON_COMMAND(ID_BITMAP_WHITE, &CCpaintView::OnBitmapWhite)
ON_COMMAND(ID_BITMAP_COLOR, &CCpaintView::OnBitmapColor)
ON_COMMAND(ID_BITMAP_HALF, &CCpaintView::OnBitmapHalf)
ON_COMMAND(ID_TOOLBAR_PAINT, &CCpaintView::OnToolbarPaint)
ON_UPDATE_COMMAND_UI(ID_TOOLBAR_PAINT, &CCpaintView::OnUpdateToolbarPaint)
ON_UPDATE_COMMAND_UI(ID_HS_HORIZONTAL, &CCpaintView::OnUpdateHsHorizontal)
ON_UPDATE_COMMAND_UI(ID_HS_VERTICAL, &CCpaintView::OnUpdateHsVertical)
ON_UPDATE_COMMAND_UI(ID_HS_FDIAGONAL, &CCpaintView::OnUpdateHsFdiagonal)
ON_UPDATE_COMMAND_UI(ID_HS_BDIAGONAL, &CCpaintView::OnUpdateHsBdiagonal)
ON_UPDATE_COMMAND_UI(ID_HS_CROSS, &CCpaintView::OnUpdateHsCross)
ON_UPDATE_COMMAND_UI(ID_HS_DIAGCROSS, &CCpaintView::OnUpdateHsDiagcross)
ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CCpaintView::OnUpdateDrawLine)
ON_UPDATE_COMMAND_UI(ID_DRAW_RCETANGLE, &CCpaintView::OnUpdateDrawRcetangle)
ON_UPDATE_COMMAND_UI(ID_DRAW_ROUND_RECT, &CCpaintView::OnUpdateDrawRoundRect)
ON_UPDATE_COMMAND_UI(ID_DRAW_ROUND, &CCpaintView::OnUpdateDrawRound)
ON_UPDATE_COMMAND_UI(ID_DRAW_ELLPISE, &CCpaintView::OnUpdateDrawEllpise)
ON_UPDATE_COMMAND_UI(ID_DRAW_POLYLINE, &CCpaintView::OnUpdateDrawPolyline)
ON_UPDATE_COMMAND_UI(ID_DRAW_PLOYGON, &CCpaintView::OnUpdateDrawPloygon)
ON_UPDATE_COMMAND_UI(ID_CHAR_OUPUT, &CCpaintView::OnUpdateCharOuput)
ON_COMMAND(ID_DUKE, &CCpaintView::OnDuke)
ON_COMMAND(ID_ELLIPSE_DIRECT, &CCpaintView::OnEllipseDirect)
ON_WM_TIMER()
ON_COMMAND(ID_ELLIPSE_BUFFER, &CCpaintView::OnEllipseBuffer)
ON_COMMAND(ID_STOP, &CCpaintView::OnStop)
ON_COMMAND(ID_DRAW_FOOTBALL, &CCpaintView::OnDrawFootball)
ON_UPDATE_COMMAND_UI(ID_DRAW_FOOTBALL, &CCpaintView::OnUpdateDrawFootball)
END_MESSAGE_MAP()

// CCpaintView ����/����

CCpaintView::CCpaintView()
{
	// TODO: �ڴ˴���ӹ������
	radio_draw_select = IDC_RADIO_STRAIGHT_LINE;
	m_bLButtonDown = FALSE; // ������������Ϊ��
	m_bErase = FALSE; // ����Ҫ����Ϊ��
	pGrayPen = new CPen(PS_DOT, 0, RGB(128, 128, 128)); // ������ɫ���߱�
	pLinePen = new CPen(PS_SOLID, 10, RGB(255, 0, 0)); // ������ɫ��ֱ�߱�
	m_brush = new CBrush(RGB(128, 128, 128));
	is_fill = 0;
	line_width = 1;
	point_count = 0;
	color = RGB(0, 0, 255);
	brush_color=RGB(255, 0, 0);
	lppoint = new POINT[100];

	wcscpy_s(m_fontName, LF_FACESIZE, L"����");
	m_iFontSize = 120;
	m_font.CreatePointFont(m_iFontSize, m_fontName);
	m_font.GetLogFont(&m_logFont);
	m_textColor = RGB(0, 0, 0);
	m_bItalic = false;
	m_bBold = false;
	m_bUnderline = false;
	m_bStrikeOut = false;

	x_axis = 0;
	y_axis = 0;
	input_string = L"�������ַ���";
	screen = m_screen=false;

	is_load_bitmap = FALSE;
	output_string = FALSE;
	is_load_show_bitmap = FALSE;
	Show_1 = Show_2 = Show_3 = FALSE;
	is_load_new = FALSE;
	Show_4 = Show_5 = Show_6 = Show_7 = Show_8 = Show_9 = FALSE;
	M_TOOL = TRUE;
	HICON hIcon = theApp.LoadIcon(IDI_ICON_MINE);

	shrink = true; // ��ʼΪ��С
	COLORREF greenCol = RGB(0, 0, 255), //������ɫ
		whiteCol = RGB(255, 255, 255); //�����ɫ
	pen.CreatePen(0, 0, greenCol); // ʵ�ĵ����ؿ����ɫ��
	brush.CreateSolidBrush(greenCol); // ʵ����ɫˢ
	whiteBrush.CreateSolidBrush(whiteCol); // ʵ�İ�ɫˢ

	m_bCreated = false; // ��ʼΪδ����
	M_BUFFER = FALSE;
	FOOTBALL = FALSE;
	red = green = blue = 0;
	is_increment = TRUE;
}

CCpaintView::~CCpaintView()
{
}

BOOL CCpaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

BOOL CCpaintView::Circle(CDC * pDC, POINT centre, POINT end)
{
	int r;
	r = sqrt((centre.x - end.x)*(centre.x - end.x) + (centre.y - end.y)*(centre.y - end.y));
	return pDC->Ellipse(centre.x - r, centre.y - r, centre.x + r, centre.y + r);
}

BOOL CCpaintView::SetMyFont(CDC * pDC, LPCTSTR name, int size, COLORREF col, int angle, BOOL italic, BOOL bold, BOOL underline, BOOL strikeOut)
{
	int height = -MulDiv(size, pDC->GetDeviceCaps(LOGPIXELSY), 720);
	CFont font; // m_font.DeleteObject(); ����m_font����font��
	BOOL bOk = font.CreateFont(height, 0, angle, angle,
		bold ? 700 : 400, italic, underline, strikeOut,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_PITCH | FF_DONTCARE, name);
	if (bOk) {
		//font.GetLogFont(&m_logFont);
		pDC->SelectObject(font);
		pDC->SetTextColor(col);
	}
	return bOk;

}

void CCpaintView::StretchBmp(CDC * pDC, CBitmap * pBmp, CRect * pRect)
{
	BITMAP bs;
	pBmp->GetBitmap(&bs);
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	dc.SelectObject(pBmp);
	if (pRect == NULL) { // ���������ͻ���
		pRect = new CRect();
		GetClientRect(pRect);
	}
	pDC->SetStretchBltMode(HALFTONE);
	pDC->StretchBlt(pRect->left, pRect->top, pRect->Width(),
		pRect->Height(), &dc, 0, 0, bs.bmWidth, bs.bmHeight,
		SRCCOPY);
}


// CCpaintView ����

void CCpaintView::ShowBmp(CDC *pDC, CBitmap *pBmp, int x, int y , int xSrc, int ySrc)
{
	BITMAP bs;
	pBmp->GetBitmap(&bs);
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	dc.SelectObject(pBmp);
	pDC->BitBlt(x, y, bs.bmWidth, bs.bmHeight, &dc, xSrc, ySrc, SRCCOPY);

}

void CCpaintView::RotateBmp(CDC * pDC, CPoint p0, int degree, CBitmap * pBmp, CBitmap * pMask)
{
	BITMAP bs;
	pBmp->GetBitmap(&bs);
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	dc.SelectObject(pBmp);
	double pi = 3.14159265358979323846;
	double a = (pi * degree) / 180;
	int w = bs.bmWidth / 2, h = bs.bmHeight / 2;
	CPoint ps[3] = {
		p0 + CPoint(int(-cos(a) * w + sin(a) * h),
		int(-sin(a) * w - cos(a) * h)),
		p0 + CPoint(int(cos(a) * w + sin(a) * h),
			int(sin(a) * w - cos(a) * h)),
		p0 + CPoint(int(-cos(a) * w - sin(a) * h),
			int(-sin(a) * w + cos(a) * h)) };
	pDC->PlgBlt(ps, &dc, 0, 0, bs.bmWidth, bs.bmHeight,
		*pMask, 0, 0);

}

void CCpaintView::OnDraw(CDC* pDC)
{
	CCpaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	RECT rect;  GetClientRect(&rect); // ��ȡ��ǰ�ͻ�������
	if (!imgbk.IsNull())// ���Ƶ�ͼ
		imgbk.Draw(pDC->m_hDC, rect,
			Gdiplus::InterpolationModeHighQuality);
	// ����λ�鴫�ͽ������鸴�Ƶ��ڴ�DC
	dc0.BitBlt(0, 0, w, h, pDC, x0, y0, SRCCOPY);
	// ���ͻ������Ƶ���ͻ�����Ӧ���ڴ�DC
	memDC_1.BitBlt(0, 0, W, H, pDC, 0, 0, SRCCOPY);
	// ����ͼ��鵽��ͻ�����Ӧ���ڴ�DC
	memDC_1.TransparentBlt(x0, y0, w, h, &dc, 0, 0, w, h, transpCol);
	// ����ͻ�����Ӧ���ڴ�DC�е�ͼ�񣬴��͵���Ļ��
	pDC->BitBlt(0, 0, W, H, &memDC_1, 0, 0, SRCCOPY);

}


// CCpaintView ��ӡ

CString CCpaintView::GetFontNumber(int size)
{
	switch (size) {
	case 420: return L"����";
	case 360: return L"С��";
	case 260: return L"һ��";
	case 240: return L"Сһ";
	case 220: return L"����";
	case 180: return L"С��";
	case 160: return L"����";
	case 150: return L"С��";
	case 140: return L"�ĺ�";
	case 120: return L"С��";
	case 105: return L"���";
	case  90: return L"С��";
	case  75: return L"����";
	case  65: return L"С��";
	case  55: return L"�ߺ�";
	case  50: return L"�˺�";
	}
	return L"δ֪";

}

BOOL CCpaintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCpaintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCpaintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CCpaintView ���

#ifdef _DEBUG
void CCpaintView::AssertValid() const
{
	CView::AssertValid();
}

void CCpaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCpaintDoc* CCpaintView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCpaintDoc)));
	return (CCpaintDoc*)m_pDocument;
}
#endif //_DEBUG


// CCpaintView ��Ϣ�������


void CCpaintView::OnPaintSet()
{
	CPaintDlg dlg;
	// TODO: �ڴ���������������
	dlg.m_Radio = radio_draw_select;
	dlg.m_fill = is_fill;
	dlg.m_brush_color.SetColor(brush_color);
	dlg.INT_LINE_WIDTH = line_width;
	dlg.m_ColorPicker.SetColor(color);
	if (dlg.DoModal() == IDOK) { // ��ʾ�Ի���

		switch (dlg.m_Radio)
		{
		case 0:radio_draw_select = IDC_RADIO_STRAIGHT_LINE; break;
		case 1:radio_draw_select = IDC_RADIO_RECTANGLE; break;
		case 2:radio_draw_select = IDC_RADIO_ROUND_RECT; break;
		case 3:radio_draw_select = IDC_RADIO_CIRCLE; break;
		case 4:radio_draw_select = IDC_RADIO_ELLIPSE; break;
		case 5:radio_draw_select = IDC_RADIO_POLYLINE; break;
		case 6:radio_draw_select = IDC_RADIO_POLYGON; break;
		case 7:radio_draw_select = IDC_RADIO_TEXT; break;

		}

		if(dlg.m_hatch_style=="ˮƽ��")
			hatchstyle = HS_HORIZONTAL;
		else if(dlg.m_hatch_style == "��ֱ��")
			hatchstyle = HS_VERTICAL;
		else if (dlg.m_hatch_style == "��б��")
			hatchstyle = HS_FDIAGONAL;
		else if (dlg.m_hatch_style == "��б��")
			hatchstyle = HS_BDIAGONAL;
		else if (dlg.m_hatch_style == "ʮ����(������)")
			hatchstyle = HS_CROSS;
		else if (dlg.m_hatch_style == "бʮ����(б����)")
			hatchstyle = HS_DIAGCROSS;

		if (dlg.m_combo_line == "ʵ��")
			nPenStyle = PS_SOLID;
		else if (dlg.m_combo_line == "����")
			nPenStyle = PS_DASH;
		else if (dlg.m_combo_line == "����")
			nPenStyle = PS_DOT;
		else if (dlg.m_combo_line == "�����")
			nPenStyle = PS_DASHDOT;
		else if (dlg.m_combo_line == "������")
			nPenStyle = PS_DASHDOTDOT;
		else if (dlg.m_combo_line == "�ձ�")
			nPenStyle = PS_NULL;
		else
			nPenStyle = PS_INSIDEFRAME;
		is_fill = dlg.m_fill;
		if (is_fill)
		{
			brush_color = dlg.m_brush_color.GetColor();
			m_radio_brush = dlg.m_radio_brush;
			if (m_radio_brush == 1)
			{
				m_brush = new CBrush(brush_color);
			}
			else if (m_radio_brush == 2)
			{
				m_brush = new CBrush(hatchstyle, brush_color);
			}
			else if (m_radio_brush == 3)
			{
				bmp.Attach(dlg.img);
				is_load_bitmap = 1;
				m_brush = new CBrush(&bmp);
				bmp.Detach();
			}
		}	
		color = dlg.m_ColorPicker.GetColor();
	    pLinePen = new CPen(nPenStyle, dlg.INT_LINE_WIDTH, color);
	    line_width = dlg.INT_LINE_WIDTH;
	}
}


void CCpaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (screen)
	{
		SetCapture(); // ������겶��
		p0 = point; // ����ֱ�ߵ����
		pm = p0; // ��ֱ�ߵ��յ�������
		m_screen = true;
	}
	if (!output_string)
	{
		if (radio_draw_select != IDC_RADIO_POLYLINE && radio_draw_select != IDC_RADIO_POLYGON)
		{
			SetCapture(); // ������겶��
			m_bLButtonDown = TRUE; // ������������Ϊ��
			p0 = point; // ����ֱ�ߵ����
			pm = p0; // ��ֱ�ߵ��յ�������
		}
		else
		{
			SetCapture(); // ������겶��
			m_bLButtonDown = TRUE; // ������������Ϊ��
			p0 = point; // ����ֱ�ߵ����
			pm = p0; // ��ֱ�ߵ��յ�������
			lppoint[point_count++] = point;
		}
	}

	CView::OnLButtonDown(nFlags, point);
}


void CCpaintView::OnMouseMove(UINT nFlags, CPoint point)
{

	wchar_t buf[20];
	CMainFrame *pFrmWnd = (CMainFrame*)GetTopLevelFrame();
	_itow_s(point.x, buf, 20, 10);
	pFrmWnd->m_wndStatusBar.SetPaneText(pFrmWnd->xVal, buf);
	_itow_s(point.y, buf, 20, 10);
	pFrmWnd->m_wndStatusBar.SetPaneText(pFrmWnd->yVal, buf);
	_itow_s(abs(point.x - p0.x), buf, 20, 10);
	if (m_bLButtonDown)
	{
		pFrmWnd->m_wndStatusBar.SetPaneText(pFrmWnd->dxVal, buf);
		_itow_s(abs(point.y - p0.y), buf, 20, 10);
		pFrmWnd->m_wndStatusBar.SetPaneText(pFrmWnd->dyVal, buf);
	}
	if (FOOTBALL)
	{
		if (nFlags & MK_LBUTTON) { //  �ж��������Ƿ񱻰���
			CDC *pDC = GetDC();	// ��ȡ��ͼDC
								// �ָ�������
			memDC_1.BitBlt(x0, y0, w, h, &dc0, 0, 0, SRCCOPY);
			// �����λ�ã�����ͼ�����λ�õ����Ͻ�����
			int x = point.x - w / 2;
			int y = point.y - h / 2;
			dc0.BitBlt(0, 0, w, h, &memDC_1, x, y, SRCCOPY); // ���汳����
														   // ����ͼ��鵽�ڴ�DC
			memDC_1.TransparentBlt(x, y, w, h, &dc, 0, 0, w, h, transpCol);
			// ��ʾ�ڴ�DC�е�ͼ��
			pDC->BitBlt(0, 0, W, H, &memDC_1, 0, 0, SRCCOPY);
			// ��¼��ǰͼ���λ�����꣬���´λָ�������ʱʹ��
			x0 = x;
			y0 = y;
			ReleaseDC(pDC); // �ͷ���ͼDC
		}

	}
	else if (m_screen)
	{
		CDC* pDC = GetDC(); // ��ȡ�豸������
		pDC->SelectObject(pGrayPen); // ѡȡ��ɫ���߱�
		pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
		pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
		pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
											// ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
		rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
			max(p0.x, point.x), max(p0.y, point.y));
		if (m_bErase) { // ��Ҫ����Ϊ��
			pDC->Rectangle(rect);
		}
		else // ��Ҫ����Ϊ��
			m_bErase = TRUE; // ����Ҫ����Ϊ��
		pm = point; // �������յ�
		pDC->Rectangle(rect);
		ReleaseDC(pDC); // �ͷ��豸������
	}
	else
	{
		if (radio_draw_select == IDC_RADIO_STRAIGHT_LINE)
		{
			if (m_bLButtonDown) { // ����������Ϊ�棨�϶���ͼ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pGrayPen); // ѡȡ��ɫ���߱�
				pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
				pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
											 //pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
											 // ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
				if (m_bErase) { // ��Ҫ����Ϊ��
					pDC->MoveTo(p0); pDC->LineTo(pm); // ����ԭֱ��
				}
				else // ��Ҫ����Ϊ��
					m_bErase = TRUE; // ����Ҫ����Ϊ��
				pDC->MoveTo(p0);
				pDC->LineTo(point); // ������ֱ��
				pm = point; // �������յ�
				ReleaseDC(pDC); // �ͷ��豸������
			}
		}
		else if (radio_draw_select == IDC_RADIO_RECTANGLE)
		{
			if (m_bLButtonDown) { // ����������Ϊ�棨�϶���ͼ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pGrayPen); // ѡȡ��ɫ���߱�
				pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
				pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
				pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
													// ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
				rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
					max(p0.x, point.x), max(p0.y, point.y));
				if (m_bErase) { // ��Ҫ����Ϊ��
					pDC->Rectangle(rect);
				}
				else // ��Ҫ����Ϊ��
					m_bErase = TRUE; // ����Ҫ����Ϊ��
				pm = point; // �������յ�
				pDC->Rectangle(rect);
				ReleaseDC(pDC); // �ͷ��豸������
			}
		}
		else if (radio_draw_select == IDC_RADIO_ROUND_RECT)
		{
			if (m_bLButtonDown) { // ����������Ϊ�棨�϶���ͼ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pGrayPen); // ѡȡ��ɫ���߱�
				pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
				pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
				pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
													// ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
				rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
					max(p0.x, point.x), max(p0.y, point.y));
				int d = min(rect.Width(), rect.Height()) / 4;
				if (m_bErase) { // ��Ҫ����Ϊ��
					pDC->RoundRect(&rect, CPoint(d, d));
				}
				else // ��Ҫ����Ϊ��
					m_bErase = TRUE; // ����Ҫ����Ϊ��
				pDC->RoundRect(&rect, CPoint(d, d));
				pm = point; // �������յ�
				ReleaseDC(pDC); // �ͷ��豸������
			}
		}
		else if (radio_draw_select == IDC_RADIO_ELLIPSE)
		{
			if (m_bLButtonDown) { // ����������Ϊ�棨�϶���ͼ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pGrayPen); // ѡȡ��ɫ���߱�
				pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
				pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
				pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
													// ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
				rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
					max(p0.x, point.x), max(p0.y, point.y));
				if (m_bErase) { // ��Ҫ����Ϊ��
					pDC->Ellipse(rect);
				}
				else // ��Ҫ����Ϊ��
					m_bErase = TRUE; // ����Ҫ����Ϊ��
				pDC->Ellipse(rect);
				pm = point; // �������յ�
				ReleaseDC(pDC); // �ͷ��豸������
			}
		}
		else if (radio_draw_select == IDC_RADIO_CIRCLE)
		{
			if (m_bLButtonDown) { // ����������Ϊ�棨�϶���ͼ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pGrayPen); // ѡȡ��ɫ���߱�
				pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
				pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
				pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
													// ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
				if (m_bErase) { // ��Ҫ����Ϊ��
					Circle(pDC, p0, point);
				}
				else // ��Ҫ����Ϊ��
					m_bErase = TRUE; // ����Ҫ����Ϊ��
				Circle(pDC, p0, point);
				pm = point; // �������յ�
				ReleaseDC(pDC); // �ͷ��豸������
			}
		}
		else if (radio_draw_select == IDC_RADIO_POLYLINE)
		{
			if (m_bLButtonDown) { // ����������Ϊ�棨�϶���ͼ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pGrayPen); // ѡȡ��ɫ���߱�
				pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
				pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
											 //pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
											 // ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
				if (m_bErase) { // ��Ҫ����Ϊ��
					pDC->MoveTo(p0); pDC->LineTo(pm); // ����ԭֱ��
				}
				else // ��Ҫ����Ϊ��
					m_bErase = TRUE; // ����Ҫ����Ϊ��
				pDC->MoveTo(p0);
				pDC->LineTo(point); // ������ֱ��
				pm = point; // �������յ�
				ReleaseDC(pDC); // �ͷ��豸������
			}
		}
		else if (radio_draw_select == IDC_RADIO_POLYGON)
		{
			if (m_bLButtonDown) { // ����������Ϊ�棨�϶���ͼ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pGrayPen); // ѡȡ��ɫ���߱�
				pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
				pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
											 //pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
											 // ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
				if (m_bErase) { // ��Ҫ����Ϊ��
					pDC->MoveTo(p0); pDC->LineTo(pm); // ����ԭֱ��
				}
				else // ��Ҫ����Ϊ��
					m_bErase = TRUE; // ����Ҫ����Ϊ��
				pDC->MoveTo(p0);
				pDC->LineTo(point); // ������ֱ��
				pm = point; // �������յ�
				ReleaseDC(pDC); // �ͷ��豸������
			}
		}
	}	
	CView::OnMouseMove(nFlags, point);
}


void CCpaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (FOOTBALL)
	{
		CDC *pDC = GetDC();	// ��ȡ��ͼDC
		memDC_1.BitBlt(x0, y0, w, h, &dc0, 0, 0, SRCCOPY); // �ָ�������
														 // �����λ�ã�����ͼ�����λ�õ����Ͻ�����
		int x = point.x - w / 2;
		int y = point.y - h / 2;
		dc0.BitBlt(0, 0, w, h, &memDC_1, x, y, SRCCOPY); // ���汳����
													   // ����ͼ��鵽�ڴ�DC
		memDC_1.TransparentBlt(x, y, w, h, &dc, 0, 0, w, h, transpCol);
		// ��ʾ�ڴ�DC�е�ͼ��
		pDC->BitBlt(0, 0, W, H, &memDC_1, 0, 0, SRCCOPY);
		// ��¼��ǰͼ���λ�����꣬���´λָ�������ʱʹ��
		x0 = x;
		y0 = y;
		ReleaseDC(pDC); // �ͷ���ͼDC
	}
	else if (output_string)
	{
		CDC* pDC = GetDC(); // ��ȡ�豸������
		SetMyFont(pDC, m_fontName, m_iFontSize, m_textColor,
			0, m_bItalic, m_bBold, m_bUnderline, m_bStrikeOut);
		pDC->TextOut(point.x, point.y, input_string);
		ReleaseDC(pDC); // �ͷ��豸������
		ReleaseCapture();
	}
	else if (m_screen)
	{
		screen = m_screen=false;
		CDC* pDC = GetDC(); // ��ȡ�豸������
		pDC->SelectObject(pGrayPen); // ѡȡ��ɫ���߱�
		pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
		pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
		pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
											// ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
		rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
			max(p0.x, point.x), max(p0.y, point.y));
		if (m_bErase) { // ��Ҫ����Ϊ��
			pDC->Rectangle(rect);
		}
		else // ��Ҫ����Ϊ��
			m_bErase = TRUE; // ����Ҫ����Ϊ��
		pm = point; // �������յ�
		pDC->Rectangle(rect);
		CDC mdc; // �����ڴ�DC
		mdc.CreateCompatibleDC(pDC); // �����뵱ǰDC���ݵ��ڴ�DC
		CBitmap bmp; // ����λͼ���������ڴ�DC�еĻ�����
					 // �������Ϊw��h���뵱ǰDC���ݵ�λͼ
		bmp.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
		mdc.SelectObject(&bmp); // ����λͼѡ���ڴ�DC
								// ��ָ�����δ����ڴ�DC���е�λͼ��
		mdc.BitBlt(0, 0, rect.Width(),rect.Height(), pDC, p0.x, p0.y, SRCCOPY);
		wchar_t filters[] = L"λͼ�ļ�(*.bmp)|*.bmp|ͼ�ν�����ʽ�ļ�(*.gif)|*.gif|\
        ����ͼ��ר����[JPEG]�ļ�(*.jpg)|*.jpg|����ֲ����ͼ���ļ�(*.png)|*.png|\���ͼ���ļ���ʽ[TIFF]�ļ�(*.tif)|*.tif|�����ļ�(*.*)|*.*||";
		CFileDialog fileDlg(FALSE, L"jpg", L"s.jpg", OFN_HIDEREADONLY, filters);
		if (fileDlg.DoModal() == IDOK) {
			CImage img;
			img.Attach(bmp);
			img.Save(fileDlg.GetPathName());
		}
		m_bLButtonDown = FALSE; // ��������������Ϊ��
		m_bErase = FALSE; // ����Ҫ����Ϊ��
		ReleaseDC(pDC); // �ͷ��豸������
		ReleaseCapture();
	}
	else
	{
		if (radio_draw_select == IDC_RADIO_STRAIGHT_LINE)
		{
			if (m_bLButtonDown) { // ����������Ϊ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pGrayPen); // ѡ���ɫ���߱�
				pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
				pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
											 // pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
											 // ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
				pDC->MoveTo(p0); pDC->LineTo(pm); // ����ԭֱ��
				pDC->SelectObject(pLinePen); // ѡ��ֱ�߱�
				pDC->SetROP2(R2_COPYPEN); // ����Ϊ���ǻ�ͼ��ʽ
				pDC->MoveTo(p0); pDC->LineTo(point); // �������յ�ֱ��
				m_bLButtonDown = FALSE; // ��������������Ϊ��
				m_bErase = FALSE; // ����Ҫ����Ϊ��
				ReleaseDC(pDC); // �ͷ��豸������
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_RECTANGLE)
		{
			if (m_bLButtonDown) { // ����������Ϊ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pLinePen); // ѡ��ֱ�߱�
				pDC->SetROP2(R2_COPYPEN); // ����Ϊ���ǻ�ͼ��ʽ
				rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
					max(p0.x, point.x), max(p0.y, point.y));
				if (is_fill&&nPenStyle == PS_SOLID)
				{
					if (m_radio_brush == 0)
					{
						pDC->SelectStockObject(NULL_BRUSH);
						pDC->Rectangle(rect);
					}
					else if (m_radio_brush == 1 || m_radio_brush == 2||m_radio_brush==3)
					{
						pDC->SelectObject(m_brush);
						pDC->Rectangle(rect);
						pDC->FloodFill((point.x + p0.x) / 2, (point.y + p0.y) / 2, color);
					}
				}
				pDC->Rectangle(rect);
				m_bLButtonDown = FALSE; // ��������������Ϊ��
				m_bErase = FALSE; // ����Ҫ����Ϊ��
				ReleaseDC(pDC); // �ͷ��豸������
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_ROUND_RECT)
		{
			if (m_bLButtonDown) { // ����������Ϊ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pLinePen); // ѡ��ֱ�߱�
				pDC->SetROP2(R2_COPYPEN); // ����Ϊ���ǻ�ͼ��ʽ
				rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
					max(p0.x, point.x), max(p0.y, point.y));
				int d = min(rect.Width(), rect.Height()) / 4;
				if (is_fill&&nPenStyle == PS_SOLID)
				{
					if (m_radio_brush == 0)
					{
						pDC->SelectStockObject(NULL_BRUSH);
						pDC->RoundRect(&rect, CPoint(d, d));
					}
					else if (m_radio_brush == 1 || m_radio_brush == 2 || m_radio_brush == 3)
					{
						pDC->SelectObject(m_brush);
						pDC->RoundRect(&rect, CPoint(d, d));
						pDC->FloodFill((point.x + p0.x) / 2, (point.y + p0.y) / 2, color);
					}
				}
				pDC->RoundRect(&rect, CPoint(d, d));
				m_bLButtonDown = FALSE; // ��������������Ϊ��
				m_bErase = FALSE; // ����Ҫ����Ϊ��
				ReleaseDC(pDC); // �ͷ��豸������
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_ELLIPSE)
		{
			if (m_bLButtonDown) { // ����������Ϊ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pLinePen); // ѡ��ֱ�߱�
				pDC->SetROP2(R2_COPYPEN); // ����Ϊ���ǻ�ͼ��ʽ
				rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
					max(p0.x, point.x), max(p0.y, point.y));
				if (is_fill&&nPenStyle == PS_SOLID)
				{
					if (m_radio_brush == 0)
					{
						pDC->SelectStockObject(NULL_BRUSH);
						pDC->Ellipse(rect);
					}
					else if (m_radio_brush == 1 || m_radio_brush == 2 || m_radio_brush == 3)
					{
						pDC->SelectObject(m_brush);
						pDC->Ellipse(rect);
						pDC->FloodFill((point.x + p0.x) / 2, (point.y + p0.y) / 2, color);
					}
				}
				pDC->Ellipse(rect);
				m_bLButtonDown = FALSE; // ��������������Ϊ��
				m_bErase = FALSE; // ����Ҫ����Ϊ��
				ReleaseDC(pDC); // �ͷ��豸������
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_CIRCLE)
		{
			if (m_bLButtonDown) { // ����������Ϊ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pLinePen); // ѡ��ֱ�߱�
				pDC->SetROP2(R2_COPYPEN); // ����Ϊ���ǻ�ͼ��ʽ
				if (is_fill&&nPenStyle == PS_SOLID)
				{
					if (m_radio_brush == 0)
					{
						pDC->SelectStockObject(NULL_BRUSH);
						Circle(pDC, p0, point);
					}
					else if (m_radio_brush == 1 || m_radio_brush == 2 || m_radio_brush == 3)
					{
						pDC->SelectObject(m_brush);
						Circle(pDC, p0, point);
						pDC->FloodFill((point.x + p0.x) / 2, (point.y + p0.y) / 2, color);
					}
				}
				Circle(pDC, p0, point);
				m_bLButtonDown = FALSE; // ��������������Ϊ��
				m_bErase = FALSE; // ����Ҫ����Ϊ��
				ReleaseDC(pDC); // �ͷ��豸������
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_POLYLINE)
		{
			if (m_bLButtonDown) { // ����������Ϊ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pGrayPen); // ѡ���ɫ���߱�
				pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
				pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
											 // pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
											 // ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
				pDC->MoveTo(p0);
				pDC->LineTo(pm); // ����ԭֱ��

				m_bErase = FALSE; // ����Ҫ����Ϊ��
				ReleaseDC(pDC); // �ͷ��豸������
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_POLYGON)
		{
			if (m_bLButtonDown) { // ����������Ϊ��
				CDC* pDC = GetDC(); // ��ȡ�豸������
				pDC->SelectObject(pGrayPen); // ѡ���ɫ���߱�
				pDC->SetROP2(R2_XORPEN); // ����Ϊ����ͼ��ʽ
				pDC->SetBkMode(TRANSPARENT); // ����͸������ģʽ
											 // pDC->SelectStockObject(NULL_BRUSH); // ѡ���ˢ
											 // ���ڶ�̬�����ͼ�Σ�����Ρ���Բ�ȣ�
				pDC->MoveTo(p0);
				pDC->LineTo(pm); // ����ԭֱ��

				m_bErase = FALSE; // ����Ҫ����Ϊ��
				ReleaseDC(pDC); // �ͷ��豸������
				ReleaseCapture();
			}
		}
	}
	CView::OnLButtonUp(nFlags, point);
}



void CCpaintView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (FOOTBALL)
	{
		FOOTBALL = FALSE;
	}
	else if (output_string)
	{
		output_string = FALSE;
	}
	else
	{
		if (radio_draw_select == IDC_RADIO_POLYLINE)
		{
			CDC* pDC = GetDC(); // ��ȡ�豸������
			pDC->SelectObject(pLinePen); // ѡ��ֱ�߱�
			pDC->SetROP2(R2_COPYPEN); // ����Ϊ���ǻ�ͼ��ʽ
			pDC->Polyline(lppoint, point_count);
			point_count = 0;
			m_bLButtonDown = FALSE; // ��������������Ϊ��
			m_bErase = FALSE; // ����Ҫ����Ϊ��
			ReleaseDC(pDC); // �ͷ��豸������
			ReleaseCapture();
		}
		else if (radio_draw_select == IDC_RADIO_POLYGON)
		{
			CDC* pDC = GetDC(); // ��ȡ�豸������
			pDC->SelectObject(pLinePen); // ѡ��ֱ�߱�
			pDC->SetROP2(R2_COPYPEN); // ����Ϊ���ǻ�ͼ��ʽ
			if (is_fill&&nPenStyle == PS_SOLID)
			{
				if (m_radio_brush == 0)
					pDC->SelectStockObject(NULL_BRUSH);
				else if (m_radio_brush == 1 || m_radio_brush == 2 || m_radio_brush == 3)
					pDC->SelectObject(m_brush);
			}
			pDC->Polygon(lppoint, point_count);
			point_count = 0;
			m_bLButtonDown = FALSE; // ��������������Ϊ��
			m_bErase = FALSE; // ����Ҫ����Ϊ��
			ReleaseDC(pDC); // �ͷ��豸������
			ReleaseCapture();
		}
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CCpaintView::OnClear()
{
	// TODO: �ڴ���������������
	RedrawWindow();
}





void CCpaintView::OnShowCharacter()
{
	Character cdlg;
	// TODO: �ڴ���������������
	cdlg.input_string = input_string;
	cdlg.x_axis = x_axis;
	cdlg.y_axis = y_axis;
	cdlg.m_iFontSize = m_iFontSize;
	cdlg.m_textColor = m_textColor;
	cdlg.m_bItalic = m_bItalic;
	cdlg.m_bBold = m_bBold;
	cdlg.m_bUnderline = m_bUnderline;
	cdlg.m_bStrikeOut = m_bStrikeOut;
	if (cdlg.DoModal() == IDOK)
	{
		CDC* pDC = GetDC(); // ��ȡ�豸������
		wcscpy_s(m_fontName, LF_FACESIZE, cdlg.m_fontName);
		m_iFontSize = cdlg.m_iFontSize;
		m_textColor = cdlg.m_textColor;
		m_bItalic = cdlg.m_bItalic;
		m_bBold = cdlg.m_bBold;
		m_bUnderline = cdlg.m_bUnderline;
		m_bStrikeOut = cdlg.m_bStrikeOut;
		SetMyFont(pDC, m_fontName, m_iFontSize, m_textColor,
			0, m_bItalic, m_bBold, m_bUnderline, m_bStrikeOut);
		x_axis = cdlg.x_axis;
		y_axis = cdlg.y_axis;
		input_string = cdlg.input_string;
		pDC->TextOut(x_axis,y_axis,input_string);
		ReleaseDC(pDC); // �ͷ��豸������
	}
}


void CCpaintView::OnScreen()
{
	// TODO: �ڴ���������������
	HDC hdc = ::GetDC(NULL); // ��ȡ��ĻDC�ľ��
	CDC screenDC; // �������ĻDC����
	screenDC.Attach(hdc); // ������ĻDC���
	CDC mdc; // ������ڴ�DC����
	mdc.CreateCompatibleDC(&screenDC); // ��������ĻDC���ݵ��ڴ�DC
	CBitmap bmp, *pOldBmp; // ����λͼ�����ָ��
	int w = GetDeviceCaps(hdc, HORZRES); // ��ȡ��Ļ�����أ�
	int h = GetDeviceCaps(hdc, VERTRES); // ��ȡ��Ļ�ߣ����أ�
										 // ��������ĻDC���ݵ�λͼ����
	bmp.CreateCompatibleBitmap(&screenDC, w, h);
	pOldBmp = mdc.SelectObject(&bmp); // ��λͼѡ���ڴ�DC
	GetTopLevelFrame()->ShowWindow(SW_HIDE); // ���س��򴰿�
	Sleep(500); // ����һ�Σ�0.5�룩ʱ��
				// ץȡ��Ļ��ͼ���ڴ�DC�е�ͼ��
	mdc.BitBlt(0, 0, w, h, &screenDC, 0, 0, SRCCOPY);
	GetTopLevelFrame()->ShowWindow(SW_SHOW); // ��ʾ���򴰿�
											 // �����ļ��Ի���Ҫ�õ���չ����������
	wchar_t filters[] = L"λͼ�ļ�(*.bmp)|*.bmp|ͼ�ν�����ʽ�ļ�(*.gif)|*.gif|\
   ����ͼ��ר����[JPEG]�ļ�(*.jpg)|*.jpg|����ֲ����ͼ���ļ�(*.png)|*.png|\���ͼ���ļ���ʽ[TIFF]�ļ�(*.tif)|*.tif|�����ļ�(*.*)|*.*||";
	CFileDialog fileDlg(FALSE, L"jpg", L"s.jpg", OFN_HIDEREADONLY, filters);
	if (fileDlg.DoModal() == IDOK) {
		CImage img;
		img.Attach(bmp);
		img.Save(fileDlg.GetPathName());
	}
	mdc.SelectObject(pOldBmp);
	bmp.DeleteObject();
	screenDC.Detach();
	::ReleaseDC(NULL, hdc);
}


void CCpaintView::OnScreenInterface()
{
	// TODO: �ڴ���������������
	screen = TRUE;
}


void CCpaintView::OnDrawLine()
{
	// TODO: �ڴ���������������
	radio_draw_select = IDC_RADIO_STRAIGHT_LINE;
}


void CCpaintView::OnDrawRcetangle()
{
	// TODO: �ڴ���������������
	radio_draw_select = IDC_RADIO_RECTANGLE;
}


void CCpaintView::OnDrawRoundRect()
{
	// TODO: �ڴ���������������
	radio_draw_select = IDC_RADIO_ROUND_RECT;
}



void CCpaintView::OnDrawRound()
{
	// TODO: �ڴ���������������
	radio_draw_select = IDC_RADIO_CIRCLE;
}


void CCpaintView::OnDrawEllpise()
{
	// TODO: �ڴ���������������
	radio_draw_select = IDC_RADIO_ELLIPSE;
}


void CCpaintView::OnDrawPolyline()
{
	// TODO: �ڴ���������������
	radio_draw_select = IDC_RADIO_POLYLINE;
}


void CCpaintView::OnDrawPloygon()
{
	// TODO: �ڴ���������������
	radio_draw_select = IDC_RADIO_POLYGON;
}


void CCpaintView::OnPenColor()
{
	// TODO: �ڴ���������������
	CColorDialog colDlg;
	if (colDlg.DoModal() == IDOK)
	{
		color = colDlg.GetColor();
		pLinePen = new CPen(nPenStyle, line_width, color);
	}
}


void CCpaintView::OnPenStyleSolid()
{
	// TODO: �ڴ���������������
		nPenStyle = PS_SOLID;
	pLinePen= new CPen(nPenStyle, line_width, color);
}


void CCpaintView::OnPenStlyeDash()
{
	// TODO: �ڴ���������������
	nPenStyle = PS_DASH;
	pLinePen = new CPen(nPenStyle, line_width, color);
}


void CCpaintView::OnPenStylePot()
{
	// TODO: �ڴ���������������
	nPenStyle = PS_DOT;
	pLinePen = new CPen(nPenStyle, line_width, color);
}


void CCpaintView::OnPenStyleDashDot()
{
	// TODO: �ڴ���������������
	nPenStyle = PS_DASHDOT;
	pLinePen = new CPen(nPenStyle, line_width, color);
}


void CCpaintView::OnPenStyleDashDotDot()
{
	// TODO: �ڴ���������������
	nPenStyle = PS_DASHDOTDOT;
	pLinePen = new CPen(nPenStyle, line_width, color);
}


void CCpaintView::OnPenWidth1()
{
	// TODO: �ڴ���������������
	line_width = 1;
	pLinePen = new CPen(nPenStyle,1, color);
}


void CCpaintView::OnPenWidth2()
{
	// TODO: �ڴ���������������
	line_width = 2;
	pLinePen = new CPen(nPenStyle, 2, color);
}


void CCpaintView::OnPenWidth4()
{
	// TODO: �ڴ���������������
	line_width = 4;
	pLinePen = new CPen(nPenStyle, 4, color);
}


void CCpaintView::OnPenWidth8()
{
	// TODO: �ڴ���������������
	line_width = 8;
	pLinePen = new CPen(nPenStyle, 8, color);
}


void CCpaintView::OnPenWidth10()
{
	// TODO: �ڴ���������������
	line_width = 10;
	pLinePen = new CPen(nPenStyle, 10, color);
}


void CCpaintView::OnPenWidth15()
{
	// TODO: �ڴ���������������
	line_width = 15;
	pLinePen = new CPen(nPenStyle, 15, color);
}


void CCpaintView::OnWidth20()
{
	// TODO: �ڴ���������������
	line_width = 20;
	pLinePen = new CPen(nPenStyle, 20, color);
}


void CCpaintView::OnPenWidth30()
{
	// TODO: �ڴ���������������
	line_width = 30;
	pLinePen = new CPen(nPenStyle, 30, color);
}


void CCpaintView::OnPenWidth50()
{
	// TODO: �ڴ���������������
	line_width = 50;
	pLinePen = new CPen(nPenStyle, 50, color);
}


void CCpaintView::OnPenWidth100()
{
	// TODO: �ڴ���������������
	line_width = 100;
	pLinePen = new CPen(nPenStyle, 100, color);
}


void CCpaintView::OnPenWidth200()
{
	// TODO: �ڴ���������������
	line_width = 200;
	pLinePen = new CPen(nPenStyle, 200, color);
}


void CCpaintView::OnPenWidthN()
{
	// TODO: �ڴ���������������
	pdlg.pen_size = line_width;
	if (pdlg.DoModal() == IDOK)
	{
		line_width = pdlg.pen_size;
		pLinePen = new CPen(nPenStyle, pdlg.pen_size, color);
	}
}


void CCpaintView::OnBrushColor()
{
	// TODO: �ڴ���������������
	CColorDialog colDlg;
	if (colDlg.DoModal() == IDOK)
	{
		brush_color = colDlg.GetColor();
		m_brush = new CBrush(brush_color);
	}
}


void CCpaintView::OnBrushFill()
{
	// TODO: �ڴ���������������
	is_fill = !is_fill;
}


void CCpaintView::OnUpdateBrushFill(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(nPenStyle == PS_SOLID);
	pCmdUI->SetCheck(is_fill);
}


void CCpaintView::OnBrushTypeSolid()
{
	// TODO: �ڴ���������������
	m_radio_brush = 1;
	m_brush = new CBrush(brush_color);
}


void CCpaintView::OnBrushTypeEmpty()
{
	// TODO: �ڴ���������������
	m_radio_brush = 0;
}


void CCpaintView::OnHsHorizontal()
{
	// TODO: �ڴ���������������
	m_radio_brush = 2;
	hatchstyle = HS_HORIZONTAL;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnHsVertical()
{
	// TODO: �ڴ���������������
	m_radio_brush = 2;
	hatchstyle = HS_VERTICAL;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnHsFdiagonal()
{
	// TODO: �ڴ���������������
	m_radio_brush = 2;
	hatchstyle = HS_FDIAGONAL;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnHsBdiagonal()
{
	// TODO: �ڴ���������������
	m_radio_brush = 2;
	hatchstyle = HS_BDIAGONAL;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnHsCross()
{
	// TODO: �ڴ���������������
	m_radio_brush = 2;
	hatchstyle = HS_CROSS;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnHsDiagcross()
{
	// TODO: �ڴ���������������
	m_radio_brush = 2;
	hatchstyle = HS_DIAGCROSS;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnUpdateBrushTypeSolid(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_radio_brush == 1);
}


void CCpaintView::OnUpdateBrushTypeEmpty(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_radio_brush == 0);
}


void CCpaintView::OnUpdatePenStyleSolid(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(nPenStyle == PS_SOLID);
}


void CCpaintView::OnUpdatePenStlyeDash(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(nPenStyle == PS_DASH);
}


void CCpaintView::OnUpdatePenStylePot(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(nPenStyle == PS_DOT);
}


void CCpaintView::OnUpdatePenStyleDashDot(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(nPenStyle == PS_DASHDOT);
}


void CCpaintView::OnUpdatePenStyleDashDotDot(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(nPenStyle == PS_DASHDOTDOT);
}


void CCpaintView::OnUpdatePenWidth1(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 1);
}


void CCpaintView::OnUpdatePenWidth2(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 2);
}


void CCpaintView::OnUpdatePenWidth4(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 4);
}


void CCpaintView::OnUpdatePenWidth8(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 8);
}


void CCpaintView::OnUpdatePenWidth10(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 10);
}


void CCpaintView::OnUpdatePenWidth15(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 15);
}


void CCpaintView::OnUpdateWidth20(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 20);
}


void CCpaintView::OnUpdatePenWidth30(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 30);
}


void CCpaintView::OnUpdatePenWidth50(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 50);
}


void CCpaintView::OnUpdatePenWidth100(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 100);
}


void CCpaintView::OnUpdatePenWidth200(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(line_width == 200);
}


void CCpaintView::OnBrushTypePicture()
{
	// TODO: �ڴ���������������
	m_radio_brush = 3;
}


void CCpaintView::OnBrushTypeChange()
{
	// TODO: �ڴ���������������
	wchar_t *filters = L"λͼ�ļ�(*.bmp)|*.bmp|�ɽ���ͼ�θ�ʽ�ļ�(*.gif)|*.gif|����ͼ��ר�����ļ�(*.jpg)|*.jpg|����ֲ����ͼ���ļ�(*.png)|*.png|�����ļ�(*.*)|*.*||";
	CFileDialog fileDlg(TRUE, L"bmp", L"*.bmp",
		OFN_HIDEREADONLY, filters);
	CString sFileName;
	if (fileDlg.DoModal() == IDOK)
		sFileName = fileDlg.GetPathName();
	else 
		return;
	CImage img_1;
	img_1.Load(sFileName);
	if (img_1.IsNull()) return;
	bmp.Attach(img_1);
	m_brush = new CBrush(&bmp);
	bmp.Detach();
	is_load_bitmap = TRUE;
}


void CCpaintView::OnUpdateBrushTypePicture(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(is_load_bitmap);
	pCmdUI->SetCheck(m_radio_brush == 3);
}


void CCpaintView::OnCharSelect()
{
	// TODO: �ڴ���������������
	CFontDialog fontDlg(&m_logFont);
	fontDlg.m_cf.rgbColors = m_textColor;
	if (fontDlg.DoModal() == IDOK) {
		wcscpy_s(m_fontName, LF_FACESIZE, fontDlg.GetFaceName());
		m_iFontSize = fontDlg.GetSize();
		m_textColor = fontDlg.GetColor();
		m_bItalic = fontDlg.IsItalic();
		m_bBold = fontDlg.IsBold();
		m_bStrikeOut = fontDlg.IsStrikeOut();
		m_bUnderline = fontDlg.IsUnderline();
	}
}


void CCpaintView::OnCharColor()
{
	// TODO: �ڴ���������������
	CColorDialog colDlg;
	if (colDlg.DoModal() == IDOK)
	{
		m_textColor = colDlg.GetColor();
	}
}


void CCpaintView::OnCharInput()
{
	// TODO: �ڴ���������������
	CInputString isDlg;
	if (isDlg.DoModal() == IDOK)
	{
		input_string = isDlg.input_string;
	}
}


void CCpaintView::OnCharOuput()
{
	// TODO: �ڴ���������������
	output_string = TRUE;
}


void CCpaintView::OnCharSize()
{
	// TODO: �ڴ���������������
	CDC* pDC = GetDC(); // ��ȡ�豸������
	CFont font, *pOldFont; // ������������ָ��
	int iSize, y = 0; // ���������С�����ʹ�ֱ�������
					  // �����Ӧ�ں����ֺŵ�nPointSizeֵ����
	int fs[16] = { 420, 360, 260, 240, 220, 180, 160, 150, 140, 120,
		105, 90, 75, 65, 55, 50 };
	wchar_t buf[40]; // �����ַ���������
					 // �����ֺ����������Ƶ��ַ�������
	CString sFontNum, sFontName = L"����";
	for (int i = 0; i < 16; i++) { // �ֺ�ѭ��
		iSize = fs[i]; // ��ȡ��ǰ�ֺŵ�nPointSizeֵ
		font.CreatePointFont(iSize, sFontName); // �����������
		pOldFont = pDC->SelectObject(&font); // ѡ���������
		sFontNum = GetFontNumber(iSize); // ��ȡ��ǰ�ֺ�
		swprintf_s(buf, 40, L"����%s%s��(%g��)", sFontName,
			sFontNum, iSize / 10.0); // ����������ַ���
		pDC->TextOut(0, y, buf); // ����ַ���
		pDC->SelectObject(pOldFont); // ѡ������
		font.DeleteObject(); // ɾ���������
		y += fs[i] / 6; // ����yֵ
	}
	ReleaseDC(pDC);
}


void CCpaintView::OnCharRotate()
{
	// TODO: �ڴ���������������
	CDC *pDC = GetDC();
	RECT rect;
	GetClientRect(&rect);
	for (int angle = 0; angle <= 360; angle += 10) {
		SetMyFont(pDC, L"����", 105, RGB(0, 0, 0), angle * 10);
		pDC->TextOut(rect.right / 2, rect.bottom / 2,
			L"����:����=����,�ֺ�=5,��С=10.5��");
	}
	ReleaseDC(pDC);

}


void CCpaintView::OnBitmapOpen()
{
	// TODO: �ڴ���������������
	// TODO: �ڴ���������������
	if (is_load_new)
	{
		img_1.Detach();
		img_2.Detach();
	}
	wchar_t *filters = L"λͼ�ļ�(*.bmp)|*.bmp|�ɽ���ͼ�θ�ʽ�ļ�(*.gif)|*.gif|����ͼ��ר�����ļ�(*.jpg)|*.jpg|����ֲ����ͼ���ļ�(*.png)|*.png|�����ļ�(*.*)|*.*||";
	CFileDialog fileDlg(TRUE, L"bmp", L"*.bmp",
		OFN_HIDEREADONLY, filters);
	CString sFileName;
	if (fileDlg.DoModal() == IDOK)
		sFileName = fileDlg.GetPathName();
	else return;
	img_1.Load(sFileName);
	if (img_1.IsNull()) return;
	img_2.Load(sFileName);
	if (img_2.IsNull()) return;
	is_load_show_bitmap = TRUE;
	is_load_new = TRUE;
}


void CCpaintView::OnUpdateBitmapNo(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(is_load_show_bitmap);
	pCmdUI->SetCheck(Show_1);
}


void CCpaintView::OnUpdateBitmapOrigin(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(is_load_show_bitmap);
	pCmdUI->SetCheck(Show_2);
}


void CCpaintView::OnUpdateBitmapStrech(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(is_load_show_bitmap);
	pCmdUI->SetCheck(Show_3);
}


void CCpaintView::OnBitmapNo()
{
	// TODO: �ڴ���������������
	Show_1 = !Show_1;
	if (Show_1)
	{
		Show_2 = Show_3 = FALSE;
		RedrawWindow();
	}
}


void CCpaintView::OnBitmapOrigin()
{
	// TODO: �ڴ���������������
	Show_2 = !Show_2;
	if (Show_2)
	{
		Show_1 = Show_3 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // ��ȡDC����OnDraw������ʡ��
		bmp_show_1.Attach(img_1);
		BITMAP bs; // ����λͼ�ṹ����
		bmp_show_1.GetBitmap(&bs); // ��ȡλͼ�ṹ
		CDC dc; // �����ڴ��DC
		dc.CreateCompatibleDC(pDC); // ��������DC
		dc.SelectObject(&bmp_show_1); // ѡ��λͼ����
									  // ����λͼ��
		pDC->BitBlt(0, 0, bs.bmWidth, bs.bmHeight, &dc, 0, 0, SRCCOPY);
		bmp_show_1.Detach();
		bmp_show_1.DeleteObject();
		ReleaseDC(pDC);
	}
}


void CCpaintView::OnBitmapStrech()
{
	// TODO: �ڴ���������������
	Show_3 = !Show_3;
	if (Show_3)
	{
		Show_1 = Show_2 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // ��ȡDC����OnDraw������ʡ��
		bmp_show_2.Attach(img_2);
		RECT rect;
		GetClientRect(&rect);
		BITMAP bs;
		bmp_show_2.GetBitmap(&bs);
		CDC dc;
		dc.CreateCompatibleDC(pDC);
		dc.SelectObject(&bmp_show_2);
		//pDC->SetStretchBltMode(HALFTONE);
		pDC->StretchBlt(0, 0, rect.right, rect.bottom, &dc, 0, 0,
			bs.bmWidth, bs.bmHeight, SRCCOPY);
		bmp_show_2.Detach();
		bmp_show_2.DeleteObject();
		ReleaseDC(pDC);
	}
}


void CCpaintView::OnUpdateBitmapMaintain(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(Show_3);
	pCmdUI->SetCheck(Show_4);
}


void CCpaintView::OnBitmapMaintain()
{
	// TODO: �ڴ���������������
	Show_4 = !Show_4;
	if (Show_4)
	{
		Show_5 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // ��ȡDC����OnDraw������ʡ��
		bmp_show_2.Attach(img_2);
		RECT rect;
		GetClientRect(&rect);
		BITMAP bs;
		bmp_show_2.GetBitmap(&bs);
		CDC dc;
		dc.CreateCompatibleDC(pDC);
		dc.SelectObject(&bmp_show_2);
		pDC->StretchBlt(0, 0, rect.bottom*(bs.bmWidth / bs.bmHeight), rect.bottom, &dc, 0, 0,
			bs.bmWidth, bs.bmHeight, SRCCOPY);
		bmp_show_2.Detach();
		bmp_show_2.DeleteObject();
		ReleaseDC(pDC);
	}
}


void CCpaintView::OnBitmapFillClient()
{
	// TODO: �ڴ���������������
	Show_5 = !Show_5;
	if (Show_5)
	{
		Show_4 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // ��ȡDC����OnDraw������ʡ��
		bmp_show_2.Attach(img_2);
		RECT rect;
		GetClientRect(&rect);
		BITMAP bs;
		bmp_show_2.GetBitmap(&bs);
		CDC dc;
		dc.CreateCompatibleDC(pDC);
		dc.SelectObject(&bmp_show_2);
		//pDC->SetStretchBltMode(HALFTONE);
		pDC->StretchBlt(0, 0, rect.right, rect.bottom, &dc, 0, 0,
			bs.bmWidth, bs.bmHeight, SRCCOPY);
		bmp_show_2.Detach();
		bmp_show_2.DeleteObject();
		ReleaseDC(pDC);
	}
}


void CCpaintView::OnUpdateBitmapFillClient(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(Show_3);
	pCmdUI->SetCheck(Show_5);
}


void CCpaintView::OnBitmapBlack()
{
	// TODO: �ڴ���������������
	Show_6 = !Show_6;
	if (Show_6)
	{
		Show_7 = Show_8 = Show_9 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // ��ȡDC����OnDraw������ʡ��
		bmp_show_2.Attach(img_2);
		RECT rect;
		GetClientRect(&rect);
		BITMAP bs;
		bmp_show_2.GetBitmap(&bs);
		CDC dc;
		dc.CreateCompatibleDC(pDC);
		dc.SelectObject(&bmp_show_2);
		pDC->SetStretchBltMode(BLACKONWHITE);
		if (Show_5)
			pDC->StretchBlt(0, 0, rect.right, rect.bottom, &dc, 0, 0,
				bs.bmWidth, bs.bmHeight, SRCCOPY);
		else if(Show_4)
			pDC->StretchBlt(0, 0, rect.bottom*(bs.bmWidth / bs.bmHeight), rect.bottom, &dc, 0, 0,
				bs.bmWidth, bs.bmHeight, SRCCOPY);
		bmp_show_2.Detach();
		bmp_show_2.DeleteObject();
		ReleaseDC(pDC);
	}
}


void CCpaintView::OnBitmapWhite()
{
	// TODO: �ڴ���������������
	Show_7 = !Show_7;
	if (Show_7)
	{
		Show_6 = Show_8 = Show_9 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // ��ȡDC����OnDraw������ʡ��
		bmp_show_2.Attach(img_2);
		RECT rect;
		GetClientRect(&rect);
		BITMAP bs;
		bmp_show_2.GetBitmap(&bs);
		CDC dc;
		dc.CreateCompatibleDC(pDC);
		dc.SelectObject(&bmp_show_2);
		pDC->SetStretchBltMode(WHITEONBLACK);
		if (Show_5)
			pDC->StretchBlt(0, 0, rect.right, rect.bottom, &dc, 0, 0,
				bs.bmWidth, bs.bmHeight, SRCCOPY);
		else if (Show_4)
			pDC->StretchBlt(0, 0, rect.bottom*(bs.bmWidth / bs.bmHeight), rect.bottom, &dc, 0, 0,
				bs.bmWidth, bs.bmHeight, SRCCOPY);
		bmp_show_2.Detach();
		bmp_show_2.DeleteObject();
		ReleaseDC(pDC);
	}
}


void CCpaintView::OnBitmapColor()
{
	// TODO: �ڴ���������������
	Show_8 = !Show_8;
	if (Show_8)
	{
		Show_6 = Show_7 = Show_9 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // ��ȡDC����OnDraw������ʡ��
		bmp_show_2.Attach(img_2);
		RECT rect;
		GetClientRect(&rect);
		BITMAP bs;
		bmp_show_2.GetBitmap(&bs);
		CDC dc;
		dc.CreateCompatibleDC(pDC);
		dc.SelectObject(&bmp_show_2);
		pDC->SetStretchBltMode(COLORONCOLOR);
		if (Show_5)
			pDC->StretchBlt(0, 0, rect.right, rect.bottom, &dc, 0, 0,
				bs.bmWidth, bs.bmHeight, SRCCOPY);
		else if (Show_4)
			pDC->StretchBlt(0, 0, rect.bottom*(bs.bmWidth / bs.bmHeight), rect.bottom, &dc, 0, 0,
				bs.bmWidth, bs.bmHeight, SRCCOPY);
		bmp_show_2.Detach();
		bmp_show_2.DeleteObject();
		ReleaseDC(pDC);
	}
}


void CCpaintView::OnBitmapHalf()
{
	// TODO: �ڴ���������������
	Show_9 = !Show_9;
	if (Show_9)
	{
		Show_7 = Show_8 = Show_6 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // ��ȡDC����OnDraw������ʡ��
		bmp_show_2.Attach(img_2);
		RECT rect;
		GetClientRect(&rect);
		BITMAP bs;
		bmp_show_2.GetBitmap(&bs);
		CDC dc;
		dc.CreateCompatibleDC(pDC);
		dc.SelectObject(&bmp_show_2);
		pDC->SetStretchBltMode(HALFTONE);
		if(Show_5)
			pDC->StretchBlt(0, 0, rect.right, rect.bottom, &dc, 0, 0,
				bs.bmWidth, bs.bmHeight, SRCCOPY);
		else if (Show_4)
			pDC->StretchBlt(0, 0, rect.bottom*(bs.bmWidth / bs.bmHeight), rect.bottom, &dc, 0, 0,
				bs.bmWidth, bs.bmHeight, SRCCOPY);
		bmp_show_2.Detach();
		bmp_show_2.DeleteObject();
		ReleaseDC(pDC);
	}
}


void CCpaintView::OnToolbarPaint()
{
	// TODO: �ڴ���������������
	CMainFrame *pFrmWnd = (CMainFrame*)GetTopLevelFrame();
	if (M_TOOL) {
		pFrmWnd->ShowControlBar(&pFrmWnd->m_ToolBar, TRUE, FALSE);
		M_TOOL = FALSE;
	}
	else {
		pFrmWnd->ShowControlBar(&pFrmWnd->m_ToolBar, FALSE, FALSE);
		M_TOOL =TRUE;
	}

}


void CCpaintView::OnUpdateToolbarPaint(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(!M_TOOL);
}


void CCpaintView::OnUpdateHsHorizontal(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(hatchstyle == HS_HORIZONTAL);
}


void CCpaintView::OnUpdateHsVertical(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(hatchstyle == HS_VERTICAL);
}


void CCpaintView::OnUpdateHsFdiagonal(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(hatchstyle == HS_FDIAGONAL);
}


void CCpaintView::OnUpdateHsBdiagonal(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(hatchstyle == HS_BDIAGONAL);
}


void CCpaintView::OnUpdateHsCross(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(hatchstyle == HS_CROSS);
}


void CCpaintView::OnUpdateHsDiagcross(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(hatchstyle == HS_DIAGCROSS);
}


void CCpaintView::OnUpdateDrawLine(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_STRAIGHT_LINE);
}


void CCpaintView::OnUpdateDrawRcetangle(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_RECTANGLE);
}


void CCpaintView::OnUpdateDrawRoundRect(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_ROUND_RECT);
}


void CCpaintView::OnUpdateDrawRound(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_CIRCLE);
}


void CCpaintView::OnUpdateDrawEllpise(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_ELLIPSE);
}


void CCpaintView::OnUpdateDrawPolyline(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_POLYLINE);
}


void CCpaintView::OnUpdateDrawPloygon(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_POLYGON);
}


void CCpaintView::OnUpdateCharOuput(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(output_string);
}


void CCpaintView::OnDuke()
{
	// TODO: �ڴ���������������
	CDukeDlg dlg;
	dlg.DoModal();
}


void CCpaintView::OnEllipseDirect()
{
	// TODO: �ڴ���������������
	CRect rect;  
	GetClientRect(&rect); // ��ȡ��ǰ�ͻ�������
	W = rect.Width();  
	H = rect.Height();
	r = R = min(W, H) / 2; // ��ʼΪ�����Բ
	w = W / 2; 
	h = H / 2;
	xc = W / 2;  
	yc = H / 2;
	SetTimer(1, 10, NULL); // �����ò�ͬ��ʱ�������������û�������
}


void CCpaintView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (M_BUFFER)
	{
		CDC *pDC = GetDC();
		// ����
		if (shrink) { // �����Ͳ���Ҫ����
			CRect rect;
			GetClientRect(&rect); // ��ȡ��ǰ�ͻ�������
			memDC.FillRect(&rect, &whiteBrush);
		}
		// �����뾶
		if (shrink) {
			w--;  h--;  r--; // ��С1����
			if (r == 0) shrink = false; // ת���ɷŴ�
		}
		else {
			w++;  h++;  r++; // �Ŵ�1����
			if (r == R) shrink = true; // ת������С
		}
		// ���������Բ
		memDC.SelectObject(&pen);
		if (is_increment)
		{
			if (++red >= 255)
			{
				red = 255;
				if (++blue >= 255)
				{
					blue = 255;
					if (++green >= 255)
					{
						is_increment = FALSE;
					}
				}
			}
		}
		else
		{
			if (--green <= 0)
			{
				green = 0;
				if (--blue <= 0)
				{
					blue = 0;
					if (--red <= 0)
					{
						is_increment = TRUE;
					}
				}
			}
		}
		brush.DeleteObject();
		brush.CreateSolidBrush(COLORREF(RGB(red, green, blue)));
		memDC.SelectObject(&brush);
		memDC.Ellipse(xc - w, yc - h, xc + w, yc + h);
		// ���ڴ�DC�е�ͼ�δ��͵���Ļ������ͼ�ͻ�����ͼ��
		pDC->BitBlt(0, 0, W, H, &memDC, 0, 0, SRCCOPY);
		ReleaseDC(pDC);
	}
	else
	{
		CDC *pDC = GetDC();
		// ����
		if (shrink) { // �����Ͳ���Ҫ����
			CRect rect(xc - w, yc - h, xc + w, yc + h);
			pDC->FillRect(rect, &whiteBrush);
		}
		// �����뾶
		if (shrink) {
			w--;  h--;  r--; // ��С1����
			if (r == 0) shrink = false; // ת���ɷŴ�
		}
		else {
			w++;  h++;  r++; // �Ŵ�1����
			if (r == R) shrink = true; // ת������С
		}
		// ���������Բ
		pDC->SelectObject(&pen);
		if (is_increment)
		{
			if (++red >= 255)
			{
				red = 255;
				if (++blue >= 255)
				{
					blue = 255;
					if (++green >= 255)
					{
						is_increment = FALSE;
					}
				}
			}
		}
		else
		{
			if (--green <= 0)
			{
				green = 0;
				if (--blue <= 0)
				{
					blue = 0;
					if (--red <= 0)
					{
						is_increment = TRUE;
					}
				}
			}
		}
		brush.DeleteObject();
		brush.CreateSolidBrush(COLORREF(RGB(red,green,blue)));
		pDC->SelectObject(&brush);
		pDC->Ellipse(xc - w, yc - h, xc + w, yc + h);
		ReleaseDC(pDC);
	}
	CView::OnTimer(nIDEvent);
}


void CCpaintView::OnEllipseBuffer()
{
	// TODO: �ڴ���������������
	CRect rect; // ���ζ������ڱ�ʾ�ͻ���
	GetClientRect(&rect); // ��ȡ�ͻ�������
	W = rect.Width();  
	H = rect.Height();
	r = R = min(W, H) / 2; // ��ʼΪ�����Բ
	w = W / 2;  
	h = H / 2;
	xc = W / 2; 
	yc = H / 2;
	CDC *pDC = GetDC();
	if (!m_bCreated) 
		memDC.CreateCompatibleDC(pDC);

	// m_bCreatedΪ��ʱ������ɾ��ԭλͼ���󣬲��ܴ�����λͼ����
	if (m_bCreated) {
		memDC.SelectObject(pOldBmp_buffer);
		bmp_buffer.DeleteObject();
	}
	bmp_buffer.CreateCompatibleBitmap(pDC, W, H); // W��H�����Ѿ��仯
	pOldBmp_buffer = memDC.SelectObject(&bmp_buffer);
	memDC.FillRect(&rect, &whiteBrush);
	m_bCreated = true; 
	shrink = true;
	M_BUFFER = TRUE;
	SetTimer(1, 10, NULL); // �������ò�ͬ��ʱ����
	ReleaseDC(pDC);
}


void CCpaintView::OnStop()
{
	// TODO: �ڴ���������������
	KillTimer(1); // ɾ����ʱ��
	M_BUFFER = FALSE;
}



void CCpaintView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	transpCol = RGB(255, 0, 0); // ����͸��ɫ
								// װ��resĿ¼�еĵ�ͼ����IDE������ʱ����ǰĿ¼Ϊ��Ŀ����Ŀ¼��
	imgbk.Load(L"res\\COD_11_1.bmp");
	bmp_1.LoadBitmap(IDB_FOOTBALL_RED); // װ��ͼ�����Դ����ɫ��������
									  // ����ͼ����Ӧ���ڴ�DC����ѡ��ͼ���------------------------
	CDC *pDC = GetDC(); // ��ȡ��ͼDC
	dc.CreateCompatibleDC(pDC);
	pOldBmp = dc.SelectObject(&bmp_1);
	// ��ȡͼ���Ŀ��-----------------------------------------
	BITMAP bm;
	bmp_1.GetBitmap(&bm);
	w = bm.bmWidth;
	h = bm.bmHeight;
	// ����������λͼ���ڴ�DC��ѡ��ͼ��----------------------------
	bmp0.CreateCompatibleBitmap(pDC, w, h);
	dc0.CreateCompatibleDC(pDC);
	pOldBmp = dc0.SelectObject(&bmp0);
	// ��ȡ�ͻ�����С-------------------------------------------
	CRect rect;
	GetClientRect(&rect);
	W = rect.Width();
	H = rect.Height();
	// ������ͻ�����Ӧ��ͼ����ڴ�DC����ѡ��ͼ�񣬻��ư�ɫ����-----
	// ��������ͼDC���ݲ���ͻ�����Сһ�µ�λͼ����
	memBmp.CreateCompatibleBitmap(pDC, W, H);
	memDC_1.CreateCompatibleDC(pDC); // ��������ͼDC���ݵ��ڴ�DC����
	pOldBmp = memDC_1.SelectObject(&memBmp); // ѡλͼ�������ڴ�DC
										   // ���ױ���ɫ��ȱʡΪ��ɫ��
	memDC_1.FillRect(&rect, &CBrush(RGB(255, 255, 255)));
	// ����λ�ڿͻ��������ͼ�������Ͻ�����-----------------------
	x0 = W / 2 - w / 2;
	y0 = H / 2 - h / 2;

}


void CCpaintView::OnDrawFootball()
{
	// TODO: �ڴ���������������
	FOOTBALL = TRUE;
}


void CCpaintView::OnUpdateDrawFootball(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(FOOTBALL);
}
