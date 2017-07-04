#if !defined(AFX_CMY03_H__4A597A26_82EE_451F_9D92_84A1519B4CD1__INCLUDED_)
#define AFX_CMY03_H__4A597A26_82EE_451F_9D92_84A1519B4CD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Cmy03.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCmy03 dialog

class CCmy03 : public CDialog
{
// Construction
public:
	CCmy03(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCmy03)
	enum { IDD = _UNKNOWN_RESOURCE_ID_ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCmy03)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCmy03)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMY03_H__4A597A26_82EE_451F_9D92_84A1519B4CD1__INCLUDED_)
