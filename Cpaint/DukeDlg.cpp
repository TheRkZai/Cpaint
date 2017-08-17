// DukeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Cpaint.h"
#include "DukeDlg.h"
#include "afxdialogex.h"


// CDukeDlg �Ի���

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


// CDukeDlg ��Ϣ�������




void CDukeDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


BOOL CDukeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	for (int i = 0; i < 10; i++) { // װ��λͼ��Դ
		m_pBmp[i] = new CBitmap;
		m_pBmp[i]->LoadBitmap(IDB_DUKE1 + i);
	}
	m_pBmp[0]->GetBitmap(&m_bs); //��ȡλͼ�ṹ
	m_bStarted = false; // �����ѿ�ʼ����Ϊ��
	m_nCurFrame = 0; // ���ó�ʼ�ĵ�ǰ֡Ϊ0
	m_nFramesPerSecond = 10; // ���ó�ʼ�����ٶ�Ϊÿ��10֡
	m_pSlider = (CSliderCtrl *)GetDlgItem(IDC_SLIDER_N);
	m_pSlider->SetRange(1, 100);
	m_pSlider->SetPos(m_nFramesPerSecond);
	SetDlgItemInt(IDC_DUKE, m_nFramesPerSecond); // ���ñ༭���ֵ

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDukeDlg::OnBnClickedAniStartStop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_bStarted) { // �ѿ�ʼ����
		m_bStarted = false; // �����ѿ�ʼ����Ϊ��
		KillTimer(1); // ֹͣ��ʱ��
					  // ���ð�ť�ı�Ϊ����ʼ������
		SetDlgItemText(IDC_ANI_START_STOP, L"��ʼ����");
	}
	else { // δ��ʼ����
		m_bStarted = true; // �����ѿ�ʼ����Ϊ��
		m_nCurFrame = 0; // // ���õ�ǰ֡Ϊ0
						 // ��ȡ�༭���е�֡��ֵ
		m_nFramesPerSecond = GetDlgItemInt(IDC_N);
		if (m_nFramesPerSecond <= 0) // ������С֡��ֵΪ1
			m_nFramesPerSecond = 1;
		else if (m_nFramesPerSecond > 100) // ���֡��ֵΪ100
			m_nFramesPerSecond = 100;
		// �õ�����֡��ֵ�������ñ༭�������
		SetDlgItemInt(IDC_N, m_nFramesPerSecond);
		// ����֡��ֵ�����ü�ʱ��
		SetTimer(1, (UINT)(1000.0 / m_nFramesPerSecond + 0.5), NULL);
		// ���ð�ť�ı�Ϊ��ֹͣ������
		SetDlgItemText(IDC_ANI_START_STOP, L"ֹͣ����");
	}

}


void CDukeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC *pDC = GetDlgItem(IDC_DUKE)->GetDC(); // ��ȡͼƬ��DC
	CDC dc; // �����ڴ�DC
	dc.CreateCompatibleDC(pDC); // ��������DC
	dc.SelectObject(m_pBmp[m_nCurFrame]); // ѡ�뵱ǰ֡λͼ
	pDC->BitBlt(0, 0, m_bs.bmWidth, m_bs.bmHeight, &dc,
		0, 0, SRCCOPY); // ��ʾ��ǰ֡λͼ
	m_nCurFrame++; // ��ǰ֡��1��������һ��Ҫ��ʾ��λͼ��ţ�
	m_nCurFrame %= 10; // ��ǰ֡��10�����ⳬ��λͼ���飬ʵ��ѭ����

	CDialogEx::OnTimer(nIDEvent);
}


void CDukeDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetDlgItemInt(IDC_N, m_pSlider->GetPos());
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDukeDlg::OnEnChangeN()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	m_pSlider->SetPos(GetDlgItemInt(IDC_N));
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
