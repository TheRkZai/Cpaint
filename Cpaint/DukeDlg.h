#pragma once


// CDukeDlg �Ի���

class CDukeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDukeDlg)

public:
	CDukeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDukeDlg();
	CBitmap *m_pBmp[10]; // λͼָ������
	BITMAP m_bs; // λͼ�ṹ����
	bool m_bStarted; // �б𶯻��Ƿ���������ʼ��Ϊfalse��
	int m_nCurFrame, // ��ǰ֡�ţ���ֵΪ0��
		m_nFramesPerSecond; // ÿ��֡������ֵΪ10��
	CSliderCtrl *m_pSlider;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DUKE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
