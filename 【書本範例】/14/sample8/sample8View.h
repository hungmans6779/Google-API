// sample8View.h : interface of the CSample8View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE8VIEW_H__0044E50B_678D_416A_A2EF_DCDC918E13E2__INCLUDED_)
#define AFX_SAMPLE8VIEW_H__0044E50B_678D_416A_A2EF_DCDC918E13E2__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample8View : public CView
{
protected: // create from serialization only
	CSample8View();
	DECLARE_DYNCREATE(CSample8View)

// Attributes
public:
	CSample8Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample8View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	IApplicationGE m_geApplication;
	BOOL m_active;
	virtual ~CSample8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample8View)
	afx_msg void OnStart();
	afx_msg void OnOpen();
	afx_msg void OnLocalsearch();
	afx_msg void OnSave();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sample8View.cpp
inline CSample8Doc* CSample8View::GetDocument()
   { return (CSample8Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE8VIEW_H__0044E50B_678D_416A_A2EF_DCDC918E13E2__INCLUDED_)
