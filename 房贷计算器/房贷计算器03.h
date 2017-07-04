// 房贷计算器03.h : main header file for the 房贷计算器03 application
//

#if !defined(AFX_03_H__7F7EE6A4_29E0_4ABE_80E6_3D7DC0145D96__INCLUDED_)
#define AFX_03_H__7F7EE6A4_29E0_4ABE_80E6_3D7DC0145D96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy03App:
// See 房贷计算器03.cpp for the implementation of this class
//

class CMy03App : public CWinApp
{
public:
	CMy03App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy03App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy03App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_03_H__7F7EE6A4_29E0_4ABE_80E6_3D7DC0145D96__INCLUDED_)
