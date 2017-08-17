
// CpaintView.cpp : CCpaintView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CCpaintView 构造/析构

CCpaintView::CCpaintView()
{
	// TODO: 在此处添加构造代码
	radio_draw_select = IDC_RADIO_STRAIGHT_LINE;
	m_bLButtonDown = FALSE; // 设左鼠标键按下为假
	m_bErase = FALSE; // 设需要擦除为假
	pGrayPen = new CPen(PS_DOT, 0, RGB(128, 128, 128)); // 创建灰色点线笔
	pLinePen = new CPen(PS_SOLID, 10, RGB(255, 0, 0)); // 创建红色的直线笔
	m_brush = new CBrush(RGB(128, 128, 128));
	is_fill = 0;
	line_width = 1;
	point_count = 0;
	color = RGB(0, 0, 255);
	brush_color=RGB(255, 0, 0);
	lppoint = new POINT[100];

	wcscpy_s(m_fontName, LF_FACESIZE, L"宋体");
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
	input_string = L"请输入字符串";
	screen = m_screen=false;

	is_load_bitmap = FALSE;
	output_string = FALSE;
	is_load_show_bitmap = FALSE;
	Show_1 = Show_2 = Show_3 = FALSE;
	is_load_new = FALSE;
	Show_4 = Show_5 = Show_6 = Show_7 = Show_8 = Show_9 = FALSE;
	M_TOOL = TRUE;
	HICON hIcon = theApp.LoadIcon(IDI_ICON_MINE);

	shrink = true; // 初始为缩小
	COLORREF greenCol = RGB(0, 0, 255), //定义绿色
		whiteCol = RGB(255, 255, 255); //定义白色
	pen.CreatePen(0, 0, greenCol); // 实心单像素宽的绿色笔
	brush.CreateSolidBrush(greenCol); // 实心绿色刷
	whiteBrush.CreateSolidBrush(whiteCol); // 实心白色刷

	m_bCreated = false; // 初始为未创建
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

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
	CFont font; // m_font.DeleteObject(); 并用m_font代替font：
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
	if (pRect == NULL) { // 充满整个客户区
		pRect = new CRect();
		GetClientRect(pRect);
	}
	pDC->SetStretchBltMode(HALFTONE);
	pDC->StretchBlt(pRect->left, pRect->top, pRect->Width(),
		pRect->Height(), &dc, 0, 0, bs.bmWidth, bs.bmHeight,
		SRCCOPY);
}


// CCpaintView 绘制

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
	// TODO: 在此处为本机数据添加绘制代码

	RECT rect;  GetClientRect(&rect); // 获取当前客户区矩形
	if (!imgbk.IsNull())// 绘制底图
		imgbk.Draw(pDC->m_hDC, rect,
			Gdiplus::InterpolationModeHighQuality);
	// 利用位块传送将背景块复制到内存DC
	dc0.BitBlt(0, 0, w, h, pDC, x0, y0, SRCCOPY);
	// 将客户区复制到与客户区对应的内存DC
	memDC_1.BitBlt(0, 0, W, H, pDC, 0, 0, SRCCOPY);
	// 绘制图像块到与客户区对应的内存DC
	memDC_1.TransparentBlt(x0, y0, w, h, &dc, 0, 0, w, h, transpCol);
	// 将与客户区对应的内存DC中的图像，传送到屏幕上
	pDC->BitBlt(0, 0, W, H, &memDC_1, 0, 0, SRCCOPY);

}


// CCpaintView 打印

CString CCpaintView::GetFontNumber(int size)
{
	switch (size) {
	case 420: return L"初号";
	case 360: return L"小初";
	case 260: return L"一号";
	case 240: return L"小一";
	case 220: return L"二号";
	case 180: return L"小二";
	case 160: return L"三号";
	case 150: return L"小三";
	case 140: return L"四号";
	case 120: return L"小四";
	case 105: return L"五号";
	case  90: return L"小五";
	case  75: return L"六号";
	case  65: return L"小六";
	case  55: return L"七号";
	case  50: return L"八号";
	}
	return L"未知";

}

BOOL CCpaintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCpaintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCpaintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCpaintView 诊断

#ifdef _DEBUG
void CCpaintView::AssertValid() const
{
	CView::AssertValid();
}

void CCpaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCpaintDoc* CCpaintView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCpaintDoc)));
	return (CCpaintDoc*)m_pDocument;
}
#endif //_DEBUG


// CCpaintView 消息处理程序


void CCpaintView::OnPaintSet()
{
	CPaintDlg dlg;
	// TODO: 在此添加命令处理程序代码
	dlg.m_Radio = radio_draw_select;
	dlg.m_fill = is_fill;
	dlg.m_brush_color.SetColor(brush_color);
	dlg.INT_LINE_WIDTH = line_width;
	dlg.m_ColorPicker.SetColor(color);
	if (dlg.DoModal() == IDOK) { // 显示对话框

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

		if(dlg.m_hatch_style=="水平线")
			hatchstyle = HS_HORIZONTAL;
		else if(dlg.m_hatch_style == "垂直线")
			hatchstyle = HS_VERTICAL;
		else if (dlg.m_hatch_style == "正斜线")
			hatchstyle = HS_FDIAGONAL;
		else if (dlg.m_hatch_style == "反斜线")
			hatchstyle = HS_BDIAGONAL;
		else if (dlg.m_hatch_style == "十字线(正网格)")
			hatchstyle = HS_CROSS;
		else if (dlg.m_hatch_style == "斜十字线(斜网格)")
			hatchstyle = HS_DIAGCROSS;

		if (dlg.m_combo_line == "实心")
			nPenStyle = PS_SOLID;
		else if (dlg.m_combo_line == "虚线")
			nPenStyle = PS_DASH;
		else if (dlg.m_combo_line == "点线")
			nPenStyle = PS_DOT;
		else if (dlg.m_combo_line == "虚点线")
			nPenStyle = PS_DASHDOT;
		else if (dlg.m_combo_line == "虚点点线")
			nPenStyle = PS_DASHDOTDOT;
		else if (dlg.m_combo_line == "空笔")
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (screen)
	{
		SetCapture(); // 设置鼠标捕获
		p0 = point; // 保存直线的起点
		pm = p0; // 让直线的终点等于起点
		m_screen = true;
	}
	if (!output_string)
	{
		if (radio_draw_select != IDC_RADIO_POLYLINE && radio_draw_select != IDC_RADIO_POLYGON)
		{
			SetCapture(); // 设置鼠标捕获
			m_bLButtonDown = TRUE; // 设左鼠标键按下为真
			p0 = point; // 保存直线的起点
			pm = p0; // 让直线的终点等于起点
		}
		else
		{
			SetCapture(); // 设置鼠标捕获
			m_bLButtonDown = TRUE; // 设左鼠标键按下为真
			p0 = point; // 保存直线的起点
			pm = p0; // 让直线的终点等于起点
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
		if (nFlags & MK_LBUTTON) { //  判断左鼠标键是否被按下
			CDC *pDC = GetDC();	// 获取视图DC
								// 恢复背景块
			memDC_1.BitBlt(x0, y0, w, h, &dc0, 0, 0, SRCCOPY);
			// 由鼠标位置，计算图像块新位置的左上角坐标
			int x = point.x - w / 2;
			int y = point.y - h / 2;
			dc0.BitBlt(0, 0, w, h, &memDC_1, x, y, SRCCOPY); // 保存背景块
														   // 绘制图像块到内存DC
			memDC_1.TransparentBlt(x, y, w, h, &dc, 0, 0, w, h, transpCol);
			// 显示内存DC中的图像
			pDC->BitBlt(0, 0, W, H, &memDC_1, 0, 0, SRCCOPY);
			// 记录当前图像块位置坐标，供下次恢复背景块时使用
			x0 = x;
			y0 = y;
			ReleaseDC(pDC); // 释放视图DC
		}

	}
	else if (m_screen)
	{
		CDC* pDC = GetDC(); // 获取设备上下文
		pDC->SelectObject(pGrayPen); // 选取灰色点线笔
		pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
		pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
		pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
											// 用于动态画封闭图形（如矩形、椭圆等）
		rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
			max(p0.x, point.x), max(p0.y, point.y));
		if (m_bErase) { // 需要擦除为真
			pDC->Rectangle(rect);
		}
		else // 需要擦除为假
			m_bErase = TRUE; // 设需要擦除为真
		pm = point; // 更新老终点
		pDC->Rectangle(rect);
		ReleaseDC(pDC); // 释放设备上下文
	}
	else
	{
		if (radio_draw_select == IDC_RADIO_STRAIGHT_LINE)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真（拖动画图）
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pGrayPen); // 选取灰色点线笔
				pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
				pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
											 //pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
											 // 用于动态画封闭图形（如矩形、椭圆等）
				if (m_bErase) { // 需要擦除为真
					pDC->MoveTo(p0); pDC->LineTo(pm); // 擦除原直线
				}
				else // 需要擦除为假
					m_bErase = TRUE; // 设需要擦除为真
				pDC->MoveTo(p0);
				pDC->LineTo(point); // 绘制新直线
				pm = point; // 更新老终点
				ReleaseDC(pDC); // 释放设备上下文
			}
		}
		else if (radio_draw_select == IDC_RADIO_RECTANGLE)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真（拖动画图）
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pGrayPen); // 选取灰色点线笔
				pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
				pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
				pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
													// 用于动态画封闭图形（如矩形、椭圆等）
				rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
					max(p0.x, point.x), max(p0.y, point.y));
				if (m_bErase) { // 需要擦除为真
					pDC->Rectangle(rect);
				}
				else // 需要擦除为假
					m_bErase = TRUE; // 设需要擦除为真
				pm = point; // 更新老终点
				pDC->Rectangle(rect);
				ReleaseDC(pDC); // 释放设备上下文
			}
		}
		else if (radio_draw_select == IDC_RADIO_ROUND_RECT)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真（拖动画图）
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pGrayPen); // 选取灰色点线笔
				pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
				pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
				pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
													// 用于动态画封闭图形（如矩形、椭圆等）
				rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
					max(p0.x, point.x), max(p0.y, point.y));
				int d = min(rect.Width(), rect.Height()) / 4;
				if (m_bErase) { // 需要擦除为真
					pDC->RoundRect(&rect, CPoint(d, d));
				}
				else // 需要擦除为假
					m_bErase = TRUE; // 设需要擦除为真
				pDC->RoundRect(&rect, CPoint(d, d));
				pm = point; // 更新老终点
				ReleaseDC(pDC); // 释放设备上下文
			}
		}
		else if (radio_draw_select == IDC_RADIO_ELLIPSE)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真（拖动画图）
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pGrayPen); // 选取灰色点线笔
				pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
				pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
				pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
													// 用于动态画封闭图形（如矩形、椭圆等）
				rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
					max(p0.x, point.x), max(p0.y, point.y));
				if (m_bErase) { // 需要擦除为真
					pDC->Ellipse(rect);
				}
				else // 需要擦除为假
					m_bErase = TRUE; // 设需要擦除为真
				pDC->Ellipse(rect);
				pm = point; // 更新老终点
				ReleaseDC(pDC); // 释放设备上下文
			}
		}
		else if (radio_draw_select == IDC_RADIO_CIRCLE)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真（拖动画图）
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pGrayPen); // 选取灰色点线笔
				pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
				pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
				pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
													// 用于动态画封闭图形（如矩形、椭圆等）
				if (m_bErase) { // 需要擦除为真
					Circle(pDC, p0, point);
				}
				else // 需要擦除为假
					m_bErase = TRUE; // 设需要擦除为真
				Circle(pDC, p0, point);
				pm = point; // 更新老终点
				ReleaseDC(pDC); // 释放设备上下文
			}
		}
		else if (radio_draw_select == IDC_RADIO_POLYLINE)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真（拖动画图）
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pGrayPen); // 选取灰色点线笔
				pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
				pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
											 //pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
											 // 用于动态画封闭图形（如矩形、椭圆等）
				if (m_bErase) { // 需要擦除为真
					pDC->MoveTo(p0); pDC->LineTo(pm); // 擦除原直线
				}
				else // 需要擦除为假
					m_bErase = TRUE; // 设需要擦除为真
				pDC->MoveTo(p0);
				pDC->LineTo(point); // 绘制新直线
				pm = point; // 更新老终点
				ReleaseDC(pDC); // 释放设备上下文
			}
		}
		else if (radio_draw_select == IDC_RADIO_POLYGON)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真（拖动画图）
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pGrayPen); // 选取灰色点线笔
				pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
				pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
											 //pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
											 // 用于动态画封闭图形（如矩形、椭圆等）
				if (m_bErase) { // 需要擦除为真
					pDC->MoveTo(p0); pDC->LineTo(pm); // 擦除原直线
				}
				else // 需要擦除为假
					m_bErase = TRUE; // 设需要擦除为真
				pDC->MoveTo(p0);
				pDC->LineTo(point); // 绘制新直线
				pm = point; // 更新老终点
				ReleaseDC(pDC); // 释放设备上下文
			}
		}
	}	
	CView::OnMouseMove(nFlags, point);
}


void CCpaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (FOOTBALL)
	{
		CDC *pDC = GetDC();	// 获取视图DC
		memDC_1.BitBlt(x0, y0, w, h, &dc0, 0, 0, SRCCOPY); // 恢复背景块
														 // 由鼠标位置，计算图像块新位置的左上角坐标
		int x = point.x - w / 2;
		int y = point.y - h / 2;
		dc0.BitBlt(0, 0, w, h, &memDC_1, x, y, SRCCOPY); // 保存背景块
													   // 绘制图像块到内存DC
		memDC_1.TransparentBlt(x, y, w, h, &dc, 0, 0, w, h, transpCol);
		// 显示内存DC中的图像
		pDC->BitBlt(0, 0, W, H, &memDC_1, 0, 0, SRCCOPY);
		// 记录当前图像块位置坐标，供下次恢复背景块时使用
		x0 = x;
		y0 = y;
		ReleaseDC(pDC); // 释放视图DC
	}
	else if (output_string)
	{
		CDC* pDC = GetDC(); // 获取设备上下文
		SetMyFont(pDC, m_fontName, m_iFontSize, m_textColor,
			0, m_bItalic, m_bBold, m_bUnderline, m_bStrikeOut);
		pDC->TextOut(point.x, point.y, input_string);
		ReleaseDC(pDC); // 释放设备上下文
		ReleaseCapture();
	}
	else if (m_screen)
	{
		screen = m_screen=false;
		CDC* pDC = GetDC(); // 获取设备上下文
		pDC->SelectObject(pGrayPen); // 选取灰色点线笔
		pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
		pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
		pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
											// 用于动态画封闭图形（如矩形、椭圆等）
		rect = CRect(min(p0.x, point.x), min(p0.y, point.y),
			max(p0.x, point.x), max(p0.y, point.y));
		if (m_bErase) { // 需要擦除为真
			pDC->Rectangle(rect);
		}
		else // 需要擦除为假
			m_bErase = TRUE; // 设需要擦除为真
		pm = point; // 更新老终点
		pDC->Rectangle(rect);
		CDC mdc; // 定义内存DC
		mdc.CreateCompatibleDC(pDC); // 创建与当前DC兼容的内存DC
		CBitmap bmp; // 定义位图对象（用作内存DC中的画布）
					 // 创建宽高为w、h并与当前DC兼容的位图
		bmp.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
		mdc.SelectObject(&bmp); // 将该位图选入内存DC
								// 将指定矩形传入内存DC（中的位图）
		mdc.BitBlt(0, 0, rect.Width(),rect.Height(), pDC, p0.x, p0.y, SRCCOPY);
		wchar_t filters[] = L"位图文件(*.bmp)|*.bmp|图形交换格式文件(*.gif)|*.gif|\
        联合图象专家组[JPEG]文件(*.jpg)|*.jpg|可移植网络图形文件(*.png)|*.png|\标记图像文件格式[TIFF]文件(*.tif)|*.tif|所有文件(*.*)|*.*||";
		CFileDialog fileDlg(FALSE, L"jpg", L"s.jpg", OFN_HIDEREADONLY, filters);
		if (fileDlg.DoModal() == IDOK) {
			CImage img;
			img.Attach(bmp);
			img.Save(fileDlg.GetPathName());
		}
		m_bLButtonDown = FALSE; // 重设左鼠标键按下为假
		m_bErase = FALSE; // 重需要擦除为假
		ReleaseDC(pDC); // 释放设备上下文
		ReleaseCapture();
	}
	else
	{
		if (radio_draw_select == IDC_RADIO_STRAIGHT_LINE)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pGrayPen); // 选入灰色点线笔
				pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
				pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
											 // pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
											 // 用于动态画封闭图形（如矩形、椭圆等）
				pDC->MoveTo(p0); pDC->LineTo(pm); // 擦除原直线
				pDC->SelectObject(pLinePen); // 选择直线笔
				pDC->SetROP2(R2_COPYPEN); // 设置为覆盖绘图方式
				pDC->MoveTo(p0); pDC->LineTo(point); // 绘制最终的直线
				m_bLButtonDown = FALSE; // 重设左鼠标键按下为假
				m_bErase = FALSE; // 重需要擦除为假
				ReleaseDC(pDC); // 释放设备上下文
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_RECTANGLE)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pLinePen); // 选择直线笔
				pDC->SetROP2(R2_COPYPEN); // 设置为覆盖绘图方式
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
				m_bLButtonDown = FALSE; // 重设左鼠标键按下为假
				m_bErase = FALSE; // 重需要擦除为假
				ReleaseDC(pDC); // 释放设备上下文
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_ROUND_RECT)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pLinePen); // 选择直线笔
				pDC->SetROP2(R2_COPYPEN); // 设置为覆盖绘图方式
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
				m_bLButtonDown = FALSE; // 重设左鼠标键按下为假
				m_bErase = FALSE; // 重需要擦除为假
				ReleaseDC(pDC); // 释放设备上下文
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_ELLIPSE)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pLinePen); // 选择直线笔
				pDC->SetROP2(R2_COPYPEN); // 设置为覆盖绘图方式
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
				m_bLButtonDown = FALSE; // 重设左鼠标键按下为假
				m_bErase = FALSE; // 重需要擦除为假
				ReleaseDC(pDC); // 释放设备上下文
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_CIRCLE)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pLinePen); // 选择直线笔
				pDC->SetROP2(R2_COPYPEN); // 设置为覆盖绘图方式
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
				m_bLButtonDown = FALSE; // 重设左鼠标键按下为假
				m_bErase = FALSE; // 重需要擦除为假
				ReleaseDC(pDC); // 释放设备上下文
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_POLYLINE)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pGrayPen); // 选入灰色点线笔
				pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
				pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
											 // pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
											 // 用于动态画封闭图形（如矩形、椭圆等）
				pDC->MoveTo(p0);
				pDC->LineTo(pm); // 擦除原直线

				m_bErase = FALSE; // 重需要擦除为假
				ReleaseDC(pDC); // 释放设备上下文
				ReleaseCapture();
			}
		}
		else if (radio_draw_select == IDC_RADIO_POLYGON)
		{
			if (m_bLButtonDown) { // 左鼠标键按下为真
				CDC* pDC = GetDC(); // 获取设备上下文
				pDC->SelectObject(pGrayPen); // 选入灰色点线笔
				pDC->SetROP2(R2_XORPEN); // 设置为异或绘图方式
				pDC->SetBkMode(TRANSPARENT); // 设置透明背景模式
											 // pDC->SelectStockObject(NULL_BRUSH); // 选入空刷
											 // 用于动态画封闭图形（如矩形、椭圆等）
				pDC->MoveTo(p0);
				pDC->LineTo(pm); // 擦除原直线

				m_bErase = FALSE; // 重需要擦除为假
				ReleaseDC(pDC); // 释放设备上下文
				ReleaseCapture();
			}
		}
	}
	CView::OnLButtonUp(nFlags, point);
}



void CCpaintView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
			CDC* pDC = GetDC(); // 获取设备上下文
			pDC->SelectObject(pLinePen); // 选择直线笔
			pDC->SetROP2(R2_COPYPEN); // 设置为覆盖绘图方式
			pDC->Polyline(lppoint, point_count);
			point_count = 0;
			m_bLButtonDown = FALSE; // 重设左鼠标键按下为假
			m_bErase = FALSE; // 重需要擦除为假
			ReleaseDC(pDC); // 释放设备上下文
			ReleaseCapture();
		}
		else if (radio_draw_select == IDC_RADIO_POLYGON)
		{
			CDC* pDC = GetDC(); // 获取设备上下文
			pDC->SelectObject(pLinePen); // 选择直线笔
			pDC->SetROP2(R2_COPYPEN); // 设置为覆盖绘图方式
			if (is_fill&&nPenStyle == PS_SOLID)
			{
				if (m_radio_brush == 0)
					pDC->SelectStockObject(NULL_BRUSH);
				else if (m_radio_brush == 1 || m_radio_brush == 2 || m_radio_brush == 3)
					pDC->SelectObject(m_brush);
			}
			pDC->Polygon(lppoint, point_count);
			point_count = 0;
			m_bLButtonDown = FALSE; // 重设左鼠标键按下为假
			m_bErase = FALSE; // 重需要擦除为假
			ReleaseDC(pDC); // 释放设备上下文
			ReleaseCapture();
		}
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CCpaintView::OnClear()
{
	// TODO: 在此添加命令处理程序代码
	RedrawWindow();
}





void CCpaintView::OnShowCharacter()
{
	Character cdlg;
	// TODO: 在此添加命令处理程序代码
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
		CDC* pDC = GetDC(); // 获取设备上下文
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
		ReleaseDC(pDC); // 释放设备上下文
	}
}


void CCpaintView::OnScreen()
{
	// TODO: 在此添加命令处理程序代码
	HDC hdc = ::GetDC(NULL); // 获取屏幕DC的句柄
	CDC screenDC; // 定义空屏幕DC对象
	screenDC.Attach(hdc); // 连接屏幕DC句柄
	CDC mdc; // 定义空内存DC对象
	mdc.CreateCompatibleDC(&screenDC); // 创建与屏幕DC兼容的内存DC
	CBitmap bmp, *pOldBmp; // 定义位图对象和指针
	int w = GetDeviceCaps(hdc, HORZRES); // 获取屏幕宽（像素）
	int h = GetDeviceCaps(hdc, VERTRES); // 获取屏幕高（像素）
										 // 创建与屏幕DC兼容的位图对象
	bmp.CreateCompatibleBitmap(&screenDC, w, h);
	pOldBmp = mdc.SelectObject(&bmp); // 将位图选入内存DC
	GetTopLevelFrame()->ShowWindow(SW_HIDE); // 隐藏程序窗口
	Sleep(500); // 休眠一段（0.5秒）时间
				// 抓取屏幕截图到内存DC中的图像
	mdc.BitBlt(0, 0, w, h, &screenDC, 0, 0, SRCCOPY);
	GetTopLevelFrame()->ShowWindow(SW_SHOW); // 显示程序窗口
											 // 保存文件对话框要用的扩展名过滤器串
	wchar_t filters[] = L"位图文件(*.bmp)|*.bmp|图形交换格式文件(*.gif)|*.gif|\
   联合图象专家组[JPEG]文件(*.jpg)|*.jpg|可移植网络图形文件(*.png)|*.png|\标记图像文件格式[TIFF]文件(*.tif)|*.tif|所有文件(*.*)|*.*||";
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
	// TODO: 在此添加命令处理程序代码
	screen = TRUE;
}


void CCpaintView::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	radio_draw_select = IDC_RADIO_STRAIGHT_LINE;
}


void CCpaintView::OnDrawRcetangle()
{
	// TODO: 在此添加命令处理程序代码
	radio_draw_select = IDC_RADIO_RECTANGLE;
}


void CCpaintView::OnDrawRoundRect()
{
	// TODO: 在此添加命令处理程序代码
	radio_draw_select = IDC_RADIO_ROUND_RECT;
}



void CCpaintView::OnDrawRound()
{
	// TODO: 在此添加命令处理程序代码
	radio_draw_select = IDC_RADIO_CIRCLE;
}


void CCpaintView::OnDrawEllpise()
{
	// TODO: 在此添加命令处理程序代码
	radio_draw_select = IDC_RADIO_ELLIPSE;
}


void CCpaintView::OnDrawPolyline()
{
	// TODO: 在此添加命令处理程序代码
	radio_draw_select = IDC_RADIO_POLYLINE;
}


void CCpaintView::OnDrawPloygon()
{
	// TODO: 在此添加命令处理程序代码
	radio_draw_select = IDC_RADIO_POLYGON;
}


void CCpaintView::OnPenColor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog colDlg;
	if (colDlg.DoModal() == IDOK)
	{
		color = colDlg.GetColor();
		pLinePen = new CPen(nPenStyle, line_width, color);
	}
}


void CCpaintView::OnPenStyleSolid()
{
	// TODO: 在此添加命令处理程序代码
		nPenStyle = PS_SOLID;
	pLinePen= new CPen(nPenStyle, line_width, color);
}


void CCpaintView::OnPenStlyeDash()
{
	// TODO: 在此添加命令处理程序代码
	nPenStyle = PS_DASH;
	pLinePen = new CPen(nPenStyle, line_width, color);
}


void CCpaintView::OnPenStylePot()
{
	// TODO: 在此添加命令处理程序代码
	nPenStyle = PS_DOT;
	pLinePen = new CPen(nPenStyle, line_width, color);
}


void CCpaintView::OnPenStyleDashDot()
{
	// TODO: 在此添加命令处理程序代码
	nPenStyle = PS_DASHDOT;
	pLinePen = new CPen(nPenStyle, line_width, color);
}


void CCpaintView::OnPenStyleDashDotDot()
{
	// TODO: 在此添加命令处理程序代码
	nPenStyle = PS_DASHDOTDOT;
	pLinePen = new CPen(nPenStyle, line_width, color);
}


void CCpaintView::OnPenWidth1()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 1;
	pLinePen = new CPen(nPenStyle,1, color);
}


void CCpaintView::OnPenWidth2()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 2;
	pLinePen = new CPen(nPenStyle, 2, color);
}


void CCpaintView::OnPenWidth4()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 4;
	pLinePen = new CPen(nPenStyle, 4, color);
}


void CCpaintView::OnPenWidth8()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 8;
	pLinePen = new CPen(nPenStyle, 8, color);
}


void CCpaintView::OnPenWidth10()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 10;
	pLinePen = new CPen(nPenStyle, 10, color);
}


void CCpaintView::OnPenWidth15()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 15;
	pLinePen = new CPen(nPenStyle, 15, color);
}


void CCpaintView::OnWidth20()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 20;
	pLinePen = new CPen(nPenStyle, 20, color);
}


void CCpaintView::OnPenWidth30()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 30;
	pLinePen = new CPen(nPenStyle, 30, color);
}


void CCpaintView::OnPenWidth50()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 50;
	pLinePen = new CPen(nPenStyle, 50, color);
}


void CCpaintView::OnPenWidth100()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 100;
	pLinePen = new CPen(nPenStyle, 100, color);
}


void CCpaintView::OnPenWidth200()
{
	// TODO: 在此添加命令处理程序代码
	line_width = 200;
	pLinePen = new CPen(nPenStyle, 200, color);
}


void CCpaintView::OnPenWidthN()
{
	// TODO: 在此添加命令处理程序代码
	pdlg.pen_size = line_width;
	if (pdlg.DoModal() == IDOK)
	{
		line_width = pdlg.pen_size;
		pLinePen = new CPen(nPenStyle, pdlg.pen_size, color);
	}
}


void CCpaintView::OnBrushColor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog colDlg;
	if (colDlg.DoModal() == IDOK)
	{
		brush_color = colDlg.GetColor();
		m_brush = new CBrush(brush_color);
	}
}


void CCpaintView::OnBrushFill()
{
	// TODO: 在此添加命令处理程序代码
	is_fill = !is_fill;
}


void CCpaintView::OnUpdateBrushFill(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(nPenStyle == PS_SOLID);
	pCmdUI->SetCheck(is_fill);
}


void CCpaintView::OnBrushTypeSolid()
{
	// TODO: 在此添加命令处理程序代码
	m_radio_brush = 1;
	m_brush = new CBrush(brush_color);
}


void CCpaintView::OnBrushTypeEmpty()
{
	// TODO: 在此添加命令处理程序代码
	m_radio_brush = 0;
}


void CCpaintView::OnHsHorizontal()
{
	// TODO: 在此添加命令处理程序代码
	m_radio_brush = 2;
	hatchstyle = HS_HORIZONTAL;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnHsVertical()
{
	// TODO: 在此添加命令处理程序代码
	m_radio_brush = 2;
	hatchstyle = HS_VERTICAL;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnHsFdiagonal()
{
	// TODO: 在此添加命令处理程序代码
	m_radio_brush = 2;
	hatchstyle = HS_FDIAGONAL;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnHsBdiagonal()
{
	// TODO: 在此添加命令处理程序代码
	m_radio_brush = 2;
	hatchstyle = HS_BDIAGONAL;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnHsCross()
{
	// TODO: 在此添加命令处理程序代码
	m_radio_brush = 2;
	hatchstyle = HS_CROSS;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnHsDiagcross()
{
	// TODO: 在此添加命令处理程序代码
	m_radio_brush = 2;
	hatchstyle = HS_DIAGCROSS;
	m_brush = new CBrush(hatchstyle, brush_color);
}


void CCpaintView::OnUpdateBrushTypeSolid(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_radio_brush == 1);
}


void CCpaintView::OnUpdateBrushTypeEmpty(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_radio_brush == 0);
}


void CCpaintView::OnUpdatePenStyleSolid(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(nPenStyle == PS_SOLID);
}


void CCpaintView::OnUpdatePenStlyeDash(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(nPenStyle == PS_DASH);
}


void CCpaintView::OnUpdatePenStylePot(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(nPenStyle == PS_DOT);
}


void CCpaintView::OnUpdatePenStyleDashDot(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(nPenStyle == PS_DASHDOT);
}


void CCpaintView::OnUpdatePenStyleDashDotDot(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(nPenStyle == PS_DASHDOTDOT);
}


void CCpaintView::OnUpdatePenWidth1(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 1);
}


void CCpaintView::OnUpdatePenWidth2(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 2);
}


void CCpaintView::OnUpdatePenWidth4(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 4);
}


void CCpaintView::OnUpdatePenWidth8(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 8);
}


void CCpaintView::OnUpdatePenWidth10(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 10);
}


void CCpaintView::OnUpdatePenWidth15(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 15);
}


void CCpaintView::OnUpdateWidth20(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 20);
}


void CCpaintView::OnUpdatePenWidth30(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 30);
}


void CCpaintView::OnUpdatePenWidth50(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 50);
}


void CCpaintView::OnUpdatePenWidth100(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 100);
}


void CCpaintView::OnUpdatePenWidth200(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(line_width == 200);
}


void CCpaintView::OnBrushTypePicture()
{
	// TODO: 在此添加命令处理程序代码
	m_radio_brush = 3;
}


void CCpaintView::OnBrushTypeChange()
{
	// TODO: 在此添加命令处理程序代码
	wchar_t *filters = L"位图文件(*.bmp)|*.bmp|可交换图形格式文件(*.gif)|*.gif|联合图像专家组文件(*.jpg)|*.jpg|可移植网络图形文件(*.png)|*.png|所有文件(*.*)|*.*||";
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
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(is_load_bitmap);
	pCmdUI->SetCheck(m_radio_brush == 3);
}


void CCpaintView::OnCharSelect()
{
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
	CColorDialog colDlg;
	if (colDlg.DoModal() == IDOK)
	{
		m_textColor = colDlg.GetColor();
	}
}


void CCpaintView::OnCharInput()
{
	// TODO: 在此添加命令处理程序代码
	CInputString isDlg;
	if (isDlg.DoModal() == IDOK)
	{
		input_string = isDlg.input_string;
	}
}


void CCpaintView::OnCharOuput()
{
	// TODO: 在此添加命令处理程序代码
	output_string = TRUE;
}


void CCpaintView::OnCharSize()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC(); // 获取设备上下文
	CFont font, *pOldFont; // 定义字体对象和指针
	int iSize, y = 0; // 定义字体大小变量和垂直坐标变量
					  // 定义对应于汉字字号的nPointSize值数组
	int fs[16] = { 420, 360, 260, 240, 220, 180, 160, 150, 140, 120,
		105, 90, 75, 65, 55, 50 };
	wchar_t buf[40]; // 定义字符串缓冲区
					 // 定义字号与字体名称的字符串对象
	CString sFontNum, sFontName = L"宋体";
	for (int i = 0; i < 16; i++) { // 字号循环
		iSize = fs[i]; // 获取当前字号的nPointSize值
		font.CreatePointFont(iSize, sFontName); // 创建字体对象
		pOldFont = pDC->SelectObject(&font); // 选入字体对象
		sFontNum = GetFontNumber(iSize); // 获取当前字号
		swprintf_s(buf, 40, L"这是%s%s字(%g磅)", sFontName,
			sFontNum, iSize / 10.0); // 生成输出的字符串
		pDC->TextOut(0, y, buf); // 输出字符串
		pDC->SelectObject(pOldFont); // 选出字体
		font.DeleteObject(); // 删除字体对象
		y += fs[i] / 6; // 更新y值
	}
	ReleaseDC(pDC);
}


void CCpaintView::OnCharRotate()
{
	// TODO: 在此添加命令处理程序代码
	CDC *pDC = GetDC();
	RECT rect;
	GetClientRect(&rect);
	for (int angle = 0; angle <= 360; angle += 10) {
		SetMyFont(pDC, L"宋体", 105, RGB(0, 0, 0), angle * 10);
		pDC->TextOut(rect.right / 2, rect.bottom / 2,
			L"字体:名称=宋体,字号=5,大小=10.5磅");
	}
	ReleaseDC(pDC);

}


void CCpaintView::OnBitmapOpen()
{
	// TODO: 在此添加命令处理程序代码
	// TODO: 在此添加命令处理程序代码
	if (is_load_new)
	{
		img_1.Detach();
		img_2.Detach();
	}
	wchar_t *filters = L"位图文件(*.bmp)|*.bmp|可交换图形格式文件(*.gif)|*.gif|联合图像专家组文件(*.jpg)|*.jpg|可移植网络图形文件(*.png)|*.png|所有文件(*.*)|*.*||";
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
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(is_load_show_bitmap);
	pCmdUI->SetCheck(Show_1);
}


void CCpaintView::OnUpdateBitmapOrigin(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(is_load_show_bitmap);
	pCmdUI->SetCheck(Show_2);
}


void CCpaintView::OnUpdateBitmapStrech(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(is_load_show_bitmap);
	pCmdUI->SetCheck(Show_3);
}


void CCpaintView::OnBitmapNo()
{
	// TODO: 在此添加命令处理程序代码
	Show_1 = !Show_1;
	if (Show_1)
	{
		Show_2 = Show_3 = FALSE;
		RedrawWindow();
	}
}


void CCpaintView::OnBitmapOrigin()
{
	// TODO: 在此添加命令处理程序代码
	Show_2 = !Show_2;
	if (Show_2)
	{
		Show_1 = Show_3 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // 获取DC（对OnDraw函数可省）
		bmp_show_1.Attach(img_1);
		BITMAP bs; // 定义位图结构变量
		bmp_show_1.GetBitmap(&bs); // 获取位图结构
		CDC dc; // 定义内存空DC
		dc.CreateCompatibleDC(pDC); // 创建兼容DC
		dc.SelectObject(&bmp_show_1); // 选入位图对象
									  // 绘制位图：
		pDC->BitBlt(0, 0, bs.bmWidth, bs.bmHeight, &dc, 0, 0, SRCCOPY);
		bmp_show_1.Detach();
		bmp_show_1.DeleteObject();
		ReleaseDC(pDC);
	}
}


void CCpaintView::OnBitmapStrech()
{
	// TODO: 在此添加命令处理程序代码
	Show_3 = !Show_3;
	if (Show_3)
	{
		Show_1 = Show_2 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // 获取DC（对OnDraw函数可省）
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
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(Show_3);
	pCmdUI->SetCheck(Show_4);
}


void CCpaintView::OnBitmapMaintain()
{
	// TODO: 在此添加命令处理程序代码
	Show_4 = !Show_4;
	if (Show_4)
	{
		Show_5 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // 获取DC（对OnDraw函数可省）
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
	// TODO: 在此添加命令处理程序代码
	Show_5 = !Show_5;
	if (Show_5)
	{
		Show_4 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // 获取DC（对OnDraw函数可省）
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
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(Show_3);
	pCmdUI->SetCheck(Show_5);
}


void CCpaintView::OnBitmapBlack()
{
	// TODO: 在此添加命令处理程序代码
	Show_6 = !Show_6;
	if (Show_6)
	{
		Show_7 = Show_8 = Show_9 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // 获取DC（对OnDraw函数可省）
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
	// TODO: 在此添加命令处理程序代码
	Show_7 = !Show_7;
	if (Show_7)
	{
		Show_6 = Show_8 = Show_9 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // 获取DC（对OnDraw函数可省）
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
	// TODO: 在此添加命令处理程序代码
	Show_8 = !Show_8;
	if (Show_8)
	{
		Show_6 = Show_7 = Show_9 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // 获取DC（对OnDraw函数可省）
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
	// TODO: 在此添加命令处理程序代码
	Show_9 = !Show_9;
	if (Show_9)
	{
		Show_7 = Show_8 = Show_6 = FALSE;
		RedrawWindow();
		CDC *pDC = GetDC(); // 获取DC（对OnDraw函数可省）
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
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(!M_TOOL);
}


void CCpaintView::OnUpdateHsHorizontal(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(hatchstyle == HS_HORIZONTAL);
}


void CCpaintView::OnUpdateHsVertical(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(hatchstyle == HS_VERTICAL);
}


void CCpaintView::OnUpdateHsFdiagonal(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(hatchstyle == HS_FDIAGONAL);
}


void CCpaintView::OnUpdateHsBdiagonal(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(hatchstyle == HS_BDIAGONAL);
}


void CCpaintView::OnUpdateHsCross(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(hatchstyle == HS_CROSS);
}


void CCpaintView::OnUpdateHsDiagcross(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(hatchstyle == HS_DIAGCROSS);
}


void CCpaintView::OnUpdateDrawLine(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_STRAIGHT_LINE);
}


void CCpaintView::OnUpdateDrawRcetangle(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_RECTANGLE);
}


void CCpaintView::OnUpdateDrawRoundRect(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_ROUND_RECT);
}


void CCpaintView::OnUpdateDrawRound(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_CIRCLE);
}


void CCpaintView::OnUpdateDrawEllpise(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_ELLIPSE);
}


void CCpaintView::OnUpdateDrawPolyline(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_POLYLINE);
}


void CCpaintView::OnUpdateDrawPloygon(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(radio_draw_select == IDC_RADIO_POLYGON);
}


void CCpaintView::OnUpdateCharOuput(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(output_string);
}


void CCpaintView::OnDuke()
{
	// TODO: 在此添加命令处理程序代码
	CDukeDlg dlg;
	dlg.DoModal();
}


void CCpaintView::OnEllipseDirect()
{
	// TODO: 在此添加命令处理程序代码
	CRect rect;  
	GetClientRect(&rect); // 获取当前客户区矩形
	W = rect.Width();  
	H = rect.Height();
	r = R = min(W, H) / 2; // 初始为最大椭圆
	w = W / 2; 
	h = H / 2;
	xc = W / 2;  
	yc = H / 2;
	SetTimer(1, 10, NULL); // 可设置不同的时间间隔，或者让用户来设置
}


void CCpaintView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (M_BUFFER)
	{
		CDC *pDC = GetDC();
		// 擦除
		if (shrink) { // 对膨胀不需要擦除
			CRect rect;
			GetClientRect(&rect); // 获取当前客户区矩形
			memDC.FillRect(&rect, &whiteBrush);
		}
		// 调整半径
		if (shrink) {
			w--;  h--;  r--; // 缩小1像素
			if (r == 0) shrink = false; // 转换成放大
		}
		else {
			w++;  h++;  r++; // 放大1像素
			if (r == R) shrink = true; // 转换成缩小
		}
		// 绘制填充椭圆
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
		// 将内存DC中的图形传送到屏幕（在视图客户区绘图）
		pDC->BitBlt(0, 0, W, H, &memDC, 0, 0, SRCCOPY);
		ReleaseDC(pDC);
	}
	else
	{
		CDC *pDC = GetDC();
		// 擦除
		if (shrink) { // 对膨胀不需要擦除
			CRect rect(xc - w, yc - h, xc + w, yc + h);
			pDC->FillRect(rect, &whiteBrush);
		}
		// 调整半径
		if (shrink) {
			w--;  h--;  r--; // 缩小1像素
			if (r == 0) shrink = false; // 转换成放大
		}
		else {
			w++;  h++;  r++; // 放大1像素
			if (r == R) shrink = true; // 转换成缩小
		}
		// 绘制填充椭圆
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
	// TODO: 在此添加命令处理程序代码
	CRect rect; // 矩形对象，用于表示客户区
	GetClientRect(&rect); // 获取客户区矩形
	W = rect.Width();  
	H = rect.Height();
	r = R = min(W, H) / 2; // 初始为最大椭圆
	w = W / 2;  
	h = H / 2;
	xc = W / 2; 
	yc = H / 2;
	CDC *pDC = GetDC();
	if (!m_bCreated) 
		memDC.CreateCompatibleDC(pDC);

	// m_bCreated为真时，需先删除原位图对象，才能创建新位图对象
	if (m_bCreated) {
		memDC.SelectObject(pOldBmp_buffer);
		bmp_buffer.DeleteObject();
	}
	bmp_buffer.CreateCompatibleBitmap(pDC, W, H); // W和H可能已经变化
	pOldBmp_buffer = memDC.SelectObject(&bmp_buffer);
	memDC.FillRect(&rect, &whiteBrush);
	m_bCreated = true; 
	shrink = true;
	M_BUFFER = TRUE;
	SetTimer(1, 10, NULL); // 可以设置不同的时间间隔
	ReleaseDC(pDC);
}


void CCpaintView::OnStop()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1); // 删除计时器
	M_BUFFER = FALSE;
}



void CCpaintView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	transpCol = RGB(255, 0, 0); // 设置透明色
								// 装入res目录中的底图（在IDE中运行时，当前目录为项目所在目录）
	imgbk.Load(L"res\\COD_11_1.bmp");
	bmp_1.LoadBitmap(IDB_FOOTBALL_RED); // 装入图像块资源（红色背景足球）
									  // 创建图像块对应的内存DC，并选入图像块------------------------
	CDC *pDC = GetDC(); // 获取视图DC
	dc.CreateCompatibleDC(pDC);
	pOldBmp = dc.SelectObject(&bmp_1);
	// 获取图像块的宽高-----------------------------------------
	BITMAP bm;
	bmp_1.GetBitmap(&bm);
	w = bm.bmWidth;
	h = bm.bmHeight;
	// 创建背景块位图和内存DC，选入图像----------------------------
	bmp0.CreateCompatibleBitmap(pDC, w, h);
	dc0.CreateCompatibleDC(pDC);
	pOldBmp = dc0.SelectObject(&bmp0);
	// 获取客户区大小-------------------------------------------
	CRect rect;
	GetClientRect(&rect);
	W = rect.Width();
	H = rect.Height();
	// 创建与客户区对应的图像和内存DC对象，选入图像，绘制白色背景-----
	// 创建与视图DC兼容并与客户区大小一致的位图对象
	memBmp.CreateCompatibleBitmap(pDC, W, H);
	memDC_1.CreateCompatibleDC(pDC); // 创建与视图DC兼容的内存DC对象
	pOldBmp = memDC_1.SelectObject(&memBmp); // 选位图对象入内存DC
										   // 填充白背景色（缺省为黑色）
	memDC_1.FillRect(&rect, &CBrush(RGB(255, 255, 255)));
	// 计算位于客户区中央的图像块的左上角坐标-----------------------
	x0 = W / 2 - w / 2;
	y0 = H / 2 - h / 2;

}


void CCpaintView::OnDrawFootball()
{
	// TODO: 在此添加命令处理程序代码
	FOOTBALL = TRUE;
}


void CCpaintView::OnUpdateDrawFootball(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(FOOTBALL);
}
