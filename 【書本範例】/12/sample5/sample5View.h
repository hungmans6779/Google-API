// sample5View.h : interface of the CSample5View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE5VIEW_H__7C76317F_4364_4BE3_BE57_F0CB14976B71__INCLUDED_)
#define AFX_SAMPLE5VIEW_H__7C76317F_4364_4BE3_BE57_F0CB14976B71__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample5View : public CView
{
protected: // create from serialization only
	CSample5View();
	DECLARE_DYNCREATE(CSample5View)

// Attributes
public:
	CSample5Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample5View)
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
	BOOL m_active;
	IApplicationGE m_geApplication;
	virtual ~CSample5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample5View)
	afx_msg void OnStart();
	afx_msg void OnExit();
	afx_msg void OnOpen();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sample5View.cpp
inline CSample5Doc* CSample5View::GetDocument()
   { return (CSample5Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE5VIEW_H__7C76317F_4364_4BE3_BE57_F0CB14976B71__INCLUDED_)
