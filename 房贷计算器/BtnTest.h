#if !defined(AFX_BTNTEST_H__BA6490A6_0D91_45BA_8AF7_694A42FB92F9__INCLUDED_)
#define AFX_BTNTEST_H__BA6490A6_0D91_45BA_8AF7_694A42FB92F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BtnTest.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBtnTest window

class CBtnTest : public CButton
{  
 public:
   //三种颜色分别为文字，Button Down的背景颜色，Button Up的背景颜色
   COLORREF m_TextColor, m_DownColor,m_UpColor;
   CBtnTest(); //原有的
   //设置Button Down的背景颜色
   void SetDownColor(COLORREF color);
   //设置Button Up的背景颜色
   void SetUpColor(COLORREF color);
   BOOL Attach(const UINT nID, CWnd* pParent);
	virtual ~CBtnTest();

	// Generated message map functions
protected:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);   //必需重载的函数
	//{{AFX_MSG(CBtnTest)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BTNTEST_H__BA6490A6_0D91_45BA_8AF7_694A42FB92F9__INCLUDED_)
