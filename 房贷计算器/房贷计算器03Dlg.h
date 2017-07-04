// ·¿´û¼ÆËãÆ÷03Dlg.h : header file
//
#if !defined(AFX_03DLG_H__64407F95_6748_4E1E_B233_4B0401F8C5B4__INCLUDED_)
#define AFX_03DLG_H__64407F95_6748_4E1E_B233_4B0401F8C5B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy03Dlg dialog
#include "BtnTest.h"
class CMy03Dlg : public CDialog
{
// Construction
public:
	CBrush m_brush;
	CMy03Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy03Dlg)
	enum { IDD = IDD_MY03_DIALOG };
	CBtnTest	m_butt;
	CBtnTest	m_exp;
	CBtnTest	m_open;
	CBtnTest	m_reset;
	CBtnTest	m_begin;
	CBtnTest	m_TestBtn;
	float	m_fFkze1;
	float	m_fFkze2;
	float	m_fArea;
	int		m_nCshu;
	BOOL	m_bMeth1;
	BOOL	m_bMeth2;
	float	m_fDkze1;
	float	m_fDkze2;
	int		m_nDkys2;
	int		m_nDkys1;
	float	m_fHkze1;
	float	m_fHkze2;
	float	m_fSqfk1;
	float	m_fSqfk2;
	float	m_fYjhk1;
	float	m_fYjhk2;
	float	m_fZflx1;
	float	m_fZflx2;
	float	m_fDj;
	int		m_nDarea;
	int		m_nYears;
	float	m_fMydj;
	float	m_fLilv1;
	float	m_fLilv2;
	float	m_fTotal1;
	float	m_fTotal2;
	int		m_nLoan1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy03Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy03Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBegin();
	afx_msg void OnButt();
	afx_msg void OnReset();
	afx_msg void OnDarea();
	afx_msg void OnDtotal();
	afx_msg void OnLoan1();
	afx_msg void OnLoan2();
	afx_msg void OnLoan3();
	afx_msg void OnExp();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnOpenkeybord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFont m_font3;
	CFont m_font2;
	CFont m_font;
	CBrush m_cbrush;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_03DLG_H__64407F95_6748_4E1E_B233_4B0401F8C5B4__INCLUDED_)
