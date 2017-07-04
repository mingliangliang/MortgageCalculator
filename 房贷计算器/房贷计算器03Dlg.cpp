// 房贷计算器03Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "房贷计算器03.h"
#include "房贷计算器03Dlg.h"
#include "BtnTest.h"
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )
#include "cmath"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()  
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)

	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy03Dlg dialog

CMy03Dlg::CMy03Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy03Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy03Dlg)
	m_fFkze1 = 0.0f;
	m_fFkze2 = 0.0f;
	m_fArea = 0.0f;
	m_nCshu = 2;
	m_bMeth1 = TRUE;
	m_bMeth2 = FALSE;
	m_fDkze1 = 0.0f;
	m_fDkze2 = 0.0f;
	m_nDkys2 = 0;
	m_nDkys1 = 0;
	m_fHkze1 = 0.0f;
	m_fHkze2 = 0.0f;
	m_fSqfk1 = 0.0f;
	m_fSqfk2 = 0.0f;
	m_fYjhk1 = 0.0f;
	m_fYjhk2 = 0.0f;
	m_fZflx1 = 0.0f;
	m_fZflx2 = 0.0f;
	m_fDj = 0.0f;
	m_nDarea = -1;
	m_nYears = 4;
	m_fMydj = 0.0f;
	m_fLilv1 = 6.55f;
	m_fLilv2 = 4.5f;
	m_fTotal1 = 0.0f;
	m_fTotal2 = 0.0f;
	m_nLoan1 = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_brush.CreateSolidBrush(RGB(174,221,129));
	m_font.CreatePointFont(200,"方正舒体");
	m_font2.CreatePointFont(100,"华文行楷");
	m_font3.CreatePointFont(110,"黑体");
}

void CMy03Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy03Dlg)
	DDX_Control(pDX, IDC_BUTT, m_butt);
	DDX_Control(pDX, IDC_EXP, m_exp);
	DDX_Control(pDX, IDC_OPENKEYBORD, m_open);
	DDX_Control(pDX, IDC_RESET, m_reset);
	DDX_Control(pDX, IDC_BEGIN, m_begin);
	DDX_Control(pDX, IDOK, m_TestBtn);
	DDX_Text(pDX, IDC_REFK1, m_fFkze1);
	DDX_Text(pDX, IDC_REFK2, m_fFkze2);
	DDX_Text(pDX, IDC_AREA, m_fArea);
	DDV_MinMaxFloat(pDX, m_fArea, 0.f, 5000.f);
	DDX_CBIndex(pDX, IDC_CSHU, m_nCshu);
	DDX_Check(pDX, IDC_METH1, m_bMeth1);
	DDX_Check(pDX, IDC_METH2, m_bMeth2);
	DDX_Text(pDX, IDC_REDK1, m_fDkze1);
	DDX_Text(pDX, IDC_REDK2, m_fDkze2);
	DDX_Text(pDX, IDC_REDKY2, m_nDkys2);
	DDX_Text(pDX, IDC_REDKY1, m_nDkys1);
	DDX_Text(pDX, IDC_REHK1, m_fHkze1);
	DDX_Text(pDX, IDC_REHK2, m_fHkze2);
	DDX_Text(pDX, IDC_RESQ1, m_fSqfk1);
	DDX_Text(pDX, IDC_RESQ2, m_fSqfk2);
	DDX_Text(pDX, IDC_REYJ1, m_fYjhk1);
	DDX_Text(pDX, IDC_REYJ2, m_fYjhk2);
	DDX_Text(pDX, IDC_REZF1, m_fZflx1);
	DDX_Text(pDX, IDC_REZF2, m_fZflx2);
	DDX_Text(pDX, IDC_UNITP, m_fDj);
	DDV_MinMaxFloat(pDX, m_fDj, 0.f, 5.e+006f);
	DDX_Radio(pDX, IDC_DAREA, m_nDarea);
	DDX_CBIndex(pDX, IDC_YEARS, m_nYears);
	DDX_Text(pDX, IDC_REDJ, m_fMydj);
	DDX_Text(pDX, IDC_LILV1, m_fLilv1);
	DDV_MinMaxFloat(pDX, m_fLilv1, 1.e-004f, 10.f);
	DDX_Text(pDX, IDC_LILV2, m_fLilv2);
	DDV_MinMaxFloat(pDX, m_fLilv2, 1.e-004f, 10.f);
	DDX_Text(pDX, IDC_TOTAL1, m_fTotal1);
	DDV_MinMaxFloat(pDX, m_fTotal1, 0.f, 250000.f);
	DDX_Text(pDX, IDC_TOTAL2, m_fTotal2);
	DDV_MinMaxFloat(pDX, m_fTotal2, 0.f, 250000.f);
	DDX_Radio(pDX, IDC_LOAN1, m_nLoan1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy03Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy03Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BEGIN, OnBegin)
	ON_BN_CLICKED(IDC_BUTT, OnButt)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_BN_CLICKED(IDC_DAREA, OnDarea)
	ON_BN_CLICKED(IDC_DTOTAL, OnDtotal)
	ON_BN_CLICKED(IDC_LOAN1, OnLoan1)
	ON_BN_CLICKED(IDC_LOAN2, OnLoan2)
	ON_BN_CLICKED(IDC_LOAN3, OnLoan3)
	ON_BN_CLICKED(IDC_EXP, OnExp)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_OPENKEYBORD, OnOpenkeybord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy03Dlg message handlers

BOOL CMy03Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.
	CBtnTest m_Btn;
     //设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
    m_Btn.SetDownColor(RGB(0,0,0));
     //设置Button Up的背景色
    m_Btn.SetUpColor(RGB(0,255,0));
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy03Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy03Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
/*
HBRUSH CHouseLoadDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	

//	CBrush b1;
//	b1.CreateSolidBrush(RGB(255,0,0));
	
	// TODO: Change any attributes of the DC here

	if(pWnd->GetDlgCtrlID()==IDC_A1)
	{
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkColor(RGB(2,7,77));
	}
*/

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy03Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy03Dlg::OnBegin() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
//	float Fun(float total,float time,float lilv)
	int cs,ys;
	switch(m_nYears) //贷款月数转换
	{
	case 0:
		ys=12;
		break;
	case 1:
		ys=24;
		break;
	case 2:
		ys=36;
		break;
	case 3:
		ys=48;
		break;
	case 4:
		ys=60;
		break;
	case 5:
		ys=72;
		break;
	case 6:
		ys=84;
		break;
	case 7:
		ys=96;
		break;
	case 8:
		ys=108;
		break;
	case 9:
		ys=120;
		break;
	case 10:
		ys=132;
		break;
	case 11:
		ys=144;
		break;
	case 12:
		ys=156;
		break;
	case 13:
		ys=168;
		break;
	case 14:
		ys=180;
		break;
	case 15:
		ys=192;
		break;
	case 16:
		ys=204;
		break;
	case 17:
		ys=216;
		break;
	case 18:
		ys=228;
		break;
	case 19:
		ys=240;
		break;
	case 20:
		ys=300;
		break;
	case 21:
		ys=360;
		break;
	default :
		return;
	}
	switch(m_nCshu) //按揭成数转换
	{
	case 0:
		cs=9;
		break;
	case 1:
		cs=8;
		break;
	case 2:
		cs=7;
		break;
	case 3:
		cs=6;
		break;
	case 7:
		cs=2;
		break;
	case 4:
		cs=5;
		break;
	case 5:
		cs=4;
		break;
	case 6:
		cs=3;
		break;
	default :
		return;
	}
	switch(m_nLoan1)
	{
	case 0:      //商业贷款计算
		
		switch(m_nDarea)   
		{
		case 0:         //根据面积计算
			{
			m_fTotal1=m_fArea*m_fDj/10000;
			if(m_bMeth1)
			{
				m_fDkze1=m_fTotal1*cs/10;   
				m_fSqfk1=m_fTotal1-m_fDkze1; 
			}
			else
				m_fDkze1=m_fSqfk1=0.0f;
			if(m_bMeth2)
			{
				m_fDkze2=m_fTotal1*cs/10;   
				m_fSqfk2=m_fTotal1-m_fDkze1;
			}
			else
				m_fDkze2=m_fSqfk2=0.0f;
			break;
			}
		case 1:      //根据贷款总额计算
			m_fArea=m_fDj=0;
			if(m_bMeth1)
			{
				m_fDkze1=m_fTotal1;
				m_fSqfk1=0;
			}
			else
				m_fDkze1=m_fSqfk1=0.0f;
			if(m_bMeth2)
			{
				m_fDkze2=m_fTotal1;
				m_fSqfk2=0;
			}
			else
				m_fDkze2=m_fSqfk2=0.0f;
			break;
		}
		if(m_bMeth1)        //等额本息计算
		{
			m_fYjhk1=(m_fDkze1*m_fLilv1/1200*pow(1+m_fLilv1/1200,ys))/(pow(1+m_fLilv1/1200,ys)-1); //计算月均还款1
			m_fHkze1=m_fYjhk1*ys; //计算还款总额1
			m_fZflx1=m_fHkze1-m_fDkze1;  //计算支付利息1
			m_nDkys1=ys;
			m_fFkze1=m_fTotal1;
		}
		else
		{
			m_fYjhk1=m_fHkze1=m_fZflx1=m_fFkze1=0.0f;
			m_nDkys1=0;
		}
		if(m_bMeth2)      //等额本金计算
		{
			m_fYjhk2=m_fDkze2/ys+(m_fDkze2-0)*m_fLilv1/1200;  //首月付款
			m_fMydj=(m_fYjhk2-(m_fDkze2/ys+(m_fDkze2-m_fYjhk2)*m_fLilv1/12/100))*10000;  //每月递减
	
			m_fZflx2=m_fDkze2*m_fLilv1/1200*(ys+1)/2;   //支付利息2
			m_fHkze2=m_fDkze2+m_fZflx2;	    //计算还款总额2
		
			m_nDkys2=ys;
			m_fFkze2=m_fTotal1;  //计算房款总额
		}
		else
		{
			m_fYjhk2=m_fHkze2=m_fZflx2=m_fFkze2=m_fMydj=0.0f;
			m_nDkys2=0;
		}
//		m_fDkze1=m_fDkze2=m_fTotal*m_nCshu*100;
		break;
	case 1:      //公积金贷款计算
		switch(m_nDarea)   
		{  
		case 0:
			m_fTotal2=m_fArea*m_fDj/10000;
			if(m_bMeth1)
			{
				m_fDkze1=m_fTotal2*cs/10;
				m_fSqfk1=m_fTotal2-m_fDkze1;
			}
			else
				m_fDkze1=m_fSqfk1=0.0f;
			if(m_bMeth2)
			{
				m_fDkze2=m_fTotal2*cs/10;
				m_fSqfk2=m_fTotal2-m_fDkze1;
			}
			else
				m_fDkze2=m_fSqfk2=0.0f;
			break;
		case 1:
			m_fArea=m_fDj=0;
			if(m_bMeth1)
			{
				m_fDkze1=m_fTotal2;
				m_fSqfk1=0;
			}
			else
				m_fDkze1=m_fSqfk1=0.0f;
			if(m_bMeth2)
			{
				m_fDkze2=m_fTotal2;
				m_fSqfk2=0;
			}
			else
				m_fDkze2=m_fSqfk2=0.0f;
			break;
		}
		if(m_bMeth1)
		{
			m_fYjhk1=(m_fDkze1*m_fLilv2/100/12*pow(1+m_fLilv2/100/12,ys))/(pow(1+m_fLilv2/100/12,ys)-1);
			m_fHkze1=m_fYjhk1*ys;
			m_fZflx1=m_fHkze1-m_fDkze1;
			m_nDkys1=ys;
			m_fFkze1=m_fTotal2; 
		}
		else
		{
			m_fYjhk1=m_fHkze1=m_fZflx1=m_fFkze1=0.0f;
			m_nDkys1=0;
		}
		if(m_bMeth2)
		{
			m_nDkys2=ys;
			m_fFkze2=m_fTotal2; 
			m_fYjhk2=m_fDkze2/ys+(m_fDkze2-0)*m_fLilv2/12/100;
			m_fMydj=(m_fYjhk2-(m_fDkze2/ys+(m_fDkze2-m_fYjhk2)*m_fLilv2/12/100))*10000;

			m_fZflx2=m_fDkze2*m_fLilv2/1200*(ys+1)/2;   //计算还款总额2
			m_fHkze2=m_fDkze2+m_fZflx2;	    //支付利息2
		}
		else
		{
			m_fYjhk2=m_fHkze2=m_fZflx2=m_fFkze2=m_fMydj=0.0f;
			m_nDkys2=0;
		}

	//	m_fDkze1=m_fDkze2=m_fTotal*m_nCshu/100;
		break;	
	case 2:    //组合型贷款计算
		
//组合型贷款等额本息还款
		if(m_bMeth1)
		{
			m_fDkze1=m_fTotal1+m_fTotal2; //贷款总额计算
			m_fSqfk1=0;    //组合贷款首付0
			m_fFkze1=m_fDkze1;  //房款总额  
			m_nDkys1=ys;  
			m_fYjhk1=(m_fTotal1*m_fLilv1/100/12*pow(1+m_fLilv1/100/12,ys))/(pow(1+m_fLilv1/100/12,ys)-1)+(m_fTotal2*m_fLilv2/100/12*pow(1+m_fLilv2/100/12,ys))/(pow(1+m_fLilv2/100/12,ys)-1);
			m_fHkze1=m_fYjhk1*ys;
			m_fZflx1=m_fHkze1-m_fDkze1;
		}
		else
		{
			m_fSqfk1=m_fFkze1=m_fDkze1=m_fYjhk1=m_fHkze1=m_fZflx1=m_fTotal1=m_fTotal2=0.0f;
			m_nDkys1=0;
		}
//等额本金还款
		if(m_bMeth2)
		{
			m_fDkze2=m_fTotal1+m_fTotal2; //贷款总额计算
			m_fSqfk2=0;    //组合贷款首付0
			m_fFkze2=m_fDkze2;  //房款总额 
			m_nDkys2=ys;  //月数
			m_fYjhk2=m_fTotal1/ys+(m_fTotal1-0)*m_fLilv1/12/100+m_fTotal2/ys+(m_fTotal2-0)*m_fLilv2/12/100;  //首月付款
			m_fMydj=(m_fYjhk2-(m_fTotal1/ys+(m_fTotal1-(m_fTotal1/ys+(m_fTotal1-0)*m_fLilv1/12/100))*m_fLilv1/12/100)-(m_fTotal2/ys+(m_fTotal2-(m_fTotal2/ys+(m_fTotal2-0)*m_fLilv2/12/100))*m_fLilv2/12/100))*10000;  //每月递减
	
			m_fZflx2=m_fTotal2*m_fLilv2/1200*(ys+1)/2+m_fTotal1*m_fLilv1/1200*(ys+1)/2;   
			m_fHkze2=m_fDkze2+m_fZflx2;	   
		}
		else
		{
			m_fSqfk2=m_fFkze2=m_fDkze2=m_fYjhk2=m_fHkze2=m_fZflx2=m_fMydj=m_fTotal1=m_fTotal2=0.0f;
			m_nDkys2=0;
		}
		break;
	default:
		return;
	}
	UpdateData(FALSE);

}

void CMy03Dlg::OnButt()     //计算器隐藏计算结果
{
	// TODO: Add your control notification handler code here

	CString str;
	if(GetDlgItemText(IDC_BUTT,str),str=="隐藏结果<<")
	{
		SetDlgItemText(IDC_BUTT,"显示结果>>");
	}
	else
	{
		SetDlgItemText(IDC_BUTT,"隐藏结果<<");
	}
	static CRect rectLarge;
	static CRect rectSmall;
	if(rectLarge.IsRectNull())
	{
		CRect rectSeparator;
		GetWindowRect(&rectLarge);
		GetDlgItem(IDC_STA)->GetWindowRect(&rectSeparator);
		rectSmall.left=rectLarge.left;
		rectSmall.top=rectLarge.top;
		rectSmall.right=rectSeparator.right;
		rectSmall.bottom=rectLarge.bottom;
	}
	if(str=="隐藏结果<<")
	{
		SetWindowPos(NULL,0,0,rectSmall.Width(),rectSmall.Height(),SWP_NOMOVE|SWP_NOZORDER);
	}
	else
	{
		SetWindowPos(NULL,0,0,rectLarge.Width(),rectLarge.Height(),SWP_NOMOVE|SWP_NOZORDER);
	}
	
}

void CMy03Dlg::OnReset()    //计算器数据全部清零
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
	m_fTotal1 = 0.0f;
	m_fTotal2 = 0.0f;
	m_fFkze1 = 0.0f;
	m_fFkze2 = 0.0f;
	m_nLoan1 = -1;
	m_fArea = 0.0f;
	m_nCshu = 0;
	m_bMeth1 = FALSE;
	m_bMeth2 = FALSE;
	m_fDkze1 = 0.0f;
	m_fDkze2 = 0.0f;
	m_nDkys2 = 0;
	m_nDkys1 = 0;
	m_fHkze1 = 0.0f;
	m_fHkze2 = 0.0f;
	m_fSqfk1 = 0.0f;
	m_fSqfk2 = 0.0f;
	m_fYjhk1 = 0.0f;
	m_fYjhk2 = 0.0f;
	m_fZflx1 = 0.0f;
	m_fZflx2 = 0.0f;
	m_fDj = 0.0f;
	m_nDarea = -1;
	m_nYears = 0;
	m_fMydj = 0.0f;
	m_fLilv1 = 0.1f;
	m_fLilv2 = 0.1f;
	GetDlgItem(IDC_TOTAL2)->EnableWindow(TRUE);
	GetDlgItem(IDC_LILV2)->EnableWindow(TRUE);
	GetDlgItem(IDC_TOTAL1)->EnableWindow(TRUE);
	GetDlgItem(IDC_LILV1)->EnableWindow(TRUE);
	GetDlgItem(IDC_AREA)->EnableWindow(TRUE);  
	GetDlgItem(IDC_UNITP)->EnableWindow(TRUE);
	GetDlgItem(IDC_CSHU)->EnableWindow(TRUE);
	GetDlgItem(IDC_DAREA)->EnableWindow(TRUE);
	GetDlgItem(IDC_DTOTAL)->EnableWindow(TRUE);
	UpdateData(FALSE);
	
}

void CMy03Dlg::OnLoan1() //选择商业贷款时禁用不需要的对话框
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_TOTAL2)->EnableWindow(FALSE);
	GetDlgItem(IDC_TOTAL1)->EnableWindow(TRUE);
	GetDlgItem(IDC_LILV1)->EnableWindow(TRUE);
	GetDlgItem(IDC_LILV2)->EnableWindow(FALSE);
	GetDlgItem(IDC_DAREA)->EnableWindow(TRUE);
	GetDlgItem(IDC_DTOTAL)->EnableWindow(TRUE);
}

void CMy03Dlg::OnLoan2() //选择公积金贷款时禁用不需要的对话框
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_TOTAL1)->EnableWindow(FALSE);
	GetDlgItem(IDC_TOTAL2)->EnableWindow(TRUE);
	GetDlgItem(IDC_LILV2)->EnableWindow(TRUE);
	GetDlgItem(IDC_LILV1)->EnableWindow(FALSE);
	GetDlgItem(IDC_DAREA)->EnableWindow(TRUE);
	GetDlgItem(IDC_DTOTAL)->EnableWindow(TRUE);
	
}



void CMy03Dlg::OnDarea() //选择根据面积计算时禁用不需要的对话框
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_TOTAL1)->EnableWindow(FALSE);
	GetDlgItem(IDC_TOTAL2)->EnableWindow(FALSE);
	GetDlgItem(IDC_AREA)->EnableWindow(TRUE);  
	GetDlgItem(IDC_UNITP)->EnableWindow(TRUE);
	GetDlgItem(IDC_CSHU)->EnableWindow(TRUE);
}

void CMy03Dlg::OnDtotal() //选择根据贷款总额计算时禁用不需要的对话框
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_TOTAL1)->EnableWindow(TRUE);
	GetDlgItem(IDC_TOTAL2)->EnableWindow(TRUE);
	GetDlgItem(IDC_AREA)->EnableWindow(FALSE);  
	GetDlgItem(IDC_UNITP)->EnableWindow(FALSE);
	GetDlgItem(IDC_CSHU)->EnableWindow(FALSE);
}

void CMy03Dlg::OnLoan3() //选择组合贷款时禁用不需要的对话框
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_TOTAL2)->EnableWindow(TRUE);
	GetDlgItem(IDC_LILV2)->EnableWindow(TRUE);
	GetDlgItem(IDC_TOTAL1)->EnableWindow(TRUE);
	GetDlgItem(IDC_LILV1)->EnableWindow(TRUE);
	GetDlgItem(IDC_AREA)->EnableWindow(FALSE);  
	GetDlgItem(IDC_UNITP)->EnableWindow(FALSE);
	GetDlgItem(IDC_CSHU)->EnableWindow(FALSE);
	GetDlgItem(IDC_DAREA)->EnableWindow(FALSE);
	GetDlgItem(IDC_DTOTAL)->EnableWindow(FALSE);
}

void CMy03Dlg::OnExp()  //显示弹窗
{
	// TODO: Add your control notification handler code here
	PlaySound("230.wav",NULL,SND_ALIAS|SND_ASYNC);
	CAboutDlg dlg;
	dlg.DoModal();
}

HBRUSH CMy03Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) //对话框颜色字体控制
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here

	if(pWnd->GetDlgCtrlID()==IDC_LOAN1)  
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_LOAN2)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_LOAN3)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_DAREA)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_DTOTAL)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_UNITP)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_AREA)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_TOTAL1)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_TOTAL2)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STAT6)  
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STAT5)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STAT2)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STAT1)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STAT3)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STAT4)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_METH1)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_METH2)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
		if(pWnd->GetDlgCtrlID()==IDC_CSHU)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_YEARS)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_LILV2)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_LILV1)
	{
		pDC->SetTextColor(RGB(38,157,128));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC3)  //
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATI3)
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATI)  
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATI1)
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC2)  
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC5)
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC4) 
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC6)  
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC7)
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC9)  
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC8)
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STAT7)  
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STAT8)
	{
		pDC->SelectObject(&m_font3);
		pDC->SetTextColor(RGB(89,69,61));
		pDC->SetBkColor(RGB(174,221,129));
	}
	
	if(pWnd->GetDlgCtrlID()==IDC_STATIC)  //输出框控制
	{
		pDC->SelectObject(&m_font2);
		pDC->SetTextColor(RGB(6,128,67));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_WORD)
	{
		pDC->SelectObject(&m_font);
		pDC->SetTextColor(RGB(0,200,255));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDC_LEFTK) //左边框控制
	{
		pDC->SetTextColor(RGB(247,68,97));
		pDC->SetBkColor(RGB(174,221,129));
	}	
	if(pWnd->GetDlgCtrlID()==IDC_RIGHTK) //右边框控制
	{
		pDC->SetTextColor(RGB(247,68,97));
		pDC->SetBkColor(RGB(174,221,129));
	}
	if(pWnd->GetDlgCtrlID()==IDOK)
	{
		m_TestBtn.SetDownColor(RGB(224,30,10));
		m_TestBtn.SetUpColor(RGB(255,232,130));
		pDC->SetTextColor(RGB(255,0,0));
	}
	if(pWnd->GetDlgCtrlID()==IDC_BEGIN)
	{
		m_begin.SetDownColor(RGB(224,160,158));
		m_begin.SetUpColor(RGB(0,200,255));
		pDC->SetTextColor(RGB(0,0,0));
	}
	if(pWnd->GetDlgCtrlID()==IDC_RESET)
	{
		m_reset.SetDownColor(RGB(224,160,158));
		m_reset.SetUpColor(RGB(0,200,255));
		pDC->SetTextColor(RGB(0,0,0));
	}
	if(pWnd->GetDlgCtrlID()==IDC_OPENKEYBORD)
	{
		m_open.SetDownColor(RGB(224,160,158));
		m_open.SetUpColor(RGB(255,232,130));
		pDC->SetTextColor(RGB(0,0,0));
	}
	if(pWnd->GetDlgCtrlID()==IDC_EXP)
	{
		m_exp.SetDownColor(RGB(224,160,158));
		m_exp.SetUpColor(RGB(255,232,130));
		pDC->SetTextColor(RGB(0,0,0));
	}
	if(pWnd->GetDlgCtrlID()==IDC_BUTT)
	{
		m_butt.SetDownColor(RGB(224,160,158));
		m_butt.SetUpColor(RGB(255,232,130));
		pDC->SetTextColor(RGB(0,0,0));
	}
	// TODO: Return a different brush if the default is not desired
	return m_brush;
}

void CMy03Dlg::OnOpenkeybord() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL, _T("open"), _T("osk.exe"), NULL, NULL, SW_SHOW);
}
