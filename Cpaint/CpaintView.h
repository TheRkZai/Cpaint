
// CpaintView.h : CCpaintView ��Ľӿ�
//

#pragma once


#include "PenSize.h"
#include "Cpaint.h"
#include "Character.h"
class CCpaintView : public CView
{
protected: // �������л�����
	CCpaintView();
	DECLARE_DYNCREATE(CCpaintView)

public:
	
// ����
public:
	CCpaintDoc* GetDocument() const;

// ����
public:
	int radio_draw_select;
	BOOL m_bLButtonDown, // �ж��Ƿ���������
		m_bErase; // �Ƿ���Ҫ����ͼ��
	CPoint p0, pm; // ��¼ֱ�����Ͷ�̬�յ�
	CPen *pGrayPen, *pLinePen; // �����ɫ��ֱ�߱ʵĶ���ָ��
	CBrush *m_brush;
	COLORREF color;
	COLORREF brush_color;
	int nPenStyle;
	int hatchstyle;
	LPPOINT lppoint;
	int line_width;
	int point_count;
	int m_radio_brush;
	CString nPenStyleString;
	CRect rect;
	BOOL is_fill;
	int x_axis;
	int y_axis;
	CString input_string;
	CFont m_font;
	LOGFONT m_logFont;
	wchar_t m_fontName[LF_FACESIZE];
	int m_iFontSize;
	COLORREF m_textColor;
	BOOL screen,m_screen;
	BOOL m_bItalic, m_bBold, m_bUnderline, m_bStrikeOut;
	BOOL is_load_bitmap;
	BOOL output_string;
	bool shrink; // �����ж�����
	int r, w, h, // ��ǰ��Բ�Ķ���뾶�Ϳ��
		R, W, H, // �����Բ�Ķ���뾶�Ϳ��
		xc, yc; // ��Բ����������
	CPen pen; // ������Բ�߿�ıʣ���ˢͬɫ��
	CBrush brush, whiteBrush; // ������Բ�ڲ���ˢ��ɾ��ԭ��Բ�İ�ˢ
	CBitmap bmp_buffer, *pOldBmp_buffer; // ��λͼ�������λͼ����ָ��
	bool m_bCreated; // �Ƿ񴴽����ڴ�DC��λͼ����
	BOOL M_BUFFER;
	int x0, y0; // W ��HΪ�ͻ����Ŀ�ߡ�w��hΪͼ����
				// ��ߡ�x0��y0Ϊͼ����ϴ�λ�õ�����
	COLORREF transpCol; // ͸��ɫ
	CDC memDC; 
	CDC memDC_1, dc, dc0;// memDC���ͻ�����dc��ͼ��顢dc0��������
	CBitmap *pOldBmp,bmp_1,memBmp,bmp0; // memBmp���ڿͻ�����
										 // bmp����ͼ��顢bmp0���ڱ����顢pOldBmp����ѡ��λͼ
	CImage imgbk; // ���ڵ�ͼ
	BOOL FOOTBALL;
	int red, green, blue;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	BOOL Circle(CDC * pDC, POINT centre, POINT end);
	BOOL SetMyFont(CDC *pDC, LPCTSTR name, int size,
		COLORREF col = RGB(0, 0, 0), int angle = 0,
		BOOL italic = FALSE, BOOL bold = FALSE,
		BOOL underline = FALSE, BOOL strikeOut = FALSE);
	void StretchBmp(CDC *pDC, CBitmap *pBmp, CRect *pRect = NULL);
	void ShowBmp(CDC *pDC, CBitmap *pBmp, int x = 0, int y = 0, int xSrc = 0, int ySrc = 0);
	void RotateBmp(CDC *pDC, CPoint p0, int degree, CBitmap* pBmp,
		CBitmap* pMask);
	CPenSize pdlg;
	CBitmap bmp;
	CBitmap bmp_show_1;
	CBitmap bmp_show_2;
	BOOL is_load_show_bitmap;
	BOOL Show_1, Show_2, Show_3;
	BOOL Show_4, Show_5, Show_6, Show_7, Show_8, Show_9;
	CString GetFontNumber(int size);
	CImage img_1,img_2;
	BOOL is_load_new;
	BOOL M_TOOL;
	BOOL is_increment;
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
// ʵ��
public:
	virtual ~CCpaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaintSet();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnClear();
	afx_msg void OnShowCharacter();
	afx_msg void OnScreen();
	afx_msg void OnScreenInterface();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRcetangle();
	afx_msg void OnDrawRoundRect();
	afx_msg void OnDrawRound();
	afx_msg void OnDrawEllpise();
	afx_msg void OnDrawPolyline();
	afx_msg void OnDrawPloygon();
	afx_msg void OnPenColor();
	afx_msg void OnPenStyleSolid();
	afx_msg void OnPenStlyeDash();
	afx_msg void OnPenStylePot();
	afx_msg void OnPenStyleDashDot();
	afx_msg void OnPenStyleDashDotDot();
	afx_msg void OnPenWidth1();
	afx_msg void OnPenWidth2();
	afx_msg void OnPenWidth4();
	afx_msg void OnPenWidth8();
	afx_msg void OnPenWidth10();
	afx_msg void OnPenWidth15();
	afx_msg void OnWidth20();
	afx_msg void OnPenWidth30();
	afx_msg void OnPenWidth50();
	afx_msg void OnPenWidth100();
	afx_msg void OnPenWidth200();
	afx_msg void OnPenWidthN();
	afx_msg void OnBrushColor();
	afx_msg void OnBrushFill();
	afx_msg void OnUpdateBrushFill(CCmdUI *pCmdUI);
	afx_msg void OnBrushTypeSolid();
	afx_msg void OnBrushTypeEmpty();
	afx_msg void OnHsHorizontal();
	afx_msg void OnHsVertical();
	afx_msg void OnHsFdiagonal();
	afx_msg void OnHsBdiagonal();
	afx_msg void OnHsCross();
	afx_msg void OnHsDiagcross();
	afx_msg void OnUpdateBrushTypeSolid(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushTypeEmpty(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenStyleSolid(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenStlyeDash(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenStylePot(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenStyleDashDot(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenStyleDashDotDot(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenWidth1(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenWidth2(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenWidth4(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenWidth8(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenWidth10(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenWidth15(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWidth20(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenWidth30(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenWidth50(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenWidth100(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenWidth200(CCmdUI *pCmdUI);
	afx_msg void OnBrushTypePicture();
	afx_msg void OnBrushTypeChange();
	afx_msg void OnUpdateBrushTypePicture(CCmdUI *pCmdUI);
	afx_msg void OnCharSelect();
	afx_msg void OnCharColor();
	afx_msg void OnCharInput();
	afx_msg void OnCharOuput();
	afx_msg void OnCharSize();
	afx_msg void OnCharRotate();
	afx_msg void OnBitmapOpen();
	afx_msg void OnUpdateBitmapNo(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBitmapOrigin(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBitmapStrech(CCmdUI *pCmdUI);
	afx_msg void OnBitmapNo();
	afx_msg void OnBitmapOrigin();
	afx_msg void OnBitmapStrech();
	afx_msg void OnUpdateBitmapMaintain(CCmdUI *pCmdUI);
	afx_msg void OnBitmapMaintain();
	afx_msg void OnBitmapFillClient();
	afx_msg void OnUpdateBitmapFillClient(CCmdUI *pCmdUI);
	afx_msg void OnBitmapBlack();
	afx_msg void OnBitmapWhite();
	afx_msg void OnBitmapColor();
	afx_msg void OnBitmapHalf();
	afx_msg void OnToolbarPaint();
	afx_msg void OnUpdateToolbarPaint(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHsHorizontal(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHsVertical(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHsFdiagonal(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHsBdiagonal(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHsCross(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHsDiagcross(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawRcetangle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawRoundRect(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawRound(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawEllpise(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawPolyline(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawPloygon(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCharOuput(CCmdUI *pCmdUI);
	afx_msg void OnDuke();
	afx_msg void OnEllipseDirect();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEllipseBuffer();
	afx_msg void OnStop();
	virtual void OnInitialUpdate();
	afx_msg void OnDrawFootball();
	afx_msg void OnUpdateDrawFootball(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // CpaintView.cpp �еĵ��԰汾
inline CCpaintDoc* CCpaintView::GetDocument() const
   { return reinterpret_cast<CCpaintDoc*>(m_pDocument); }
#endif

