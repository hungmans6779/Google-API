// sample13View.h : interface of the CSample13View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE13VIEW_H__F1CE9982_1CA1_427D_93BA_DBB1B68A0047__INCLUDED_)
#define AFX_SAMPLE13VIEW_H__F1CE9982_1CA1_427D_93BA_DBB1B68A0047__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample13View : public CView
{
protected: // create from serialization only
	CSample13View();
	DECLARE_DYNCREATE(CSample13View)

// Attributes
public:
	CSample13Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample13View)
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
	double distance(double x1,double y1,double x2,double y2);
	IApplicationGE m_geApplication;
	BOOL m_active;
	double m_geLat[100];
	double m_geLon[100];
	double m_geAlt[100];
	double m_x[100];
	double m_y[100];
	CString m_str[100];
	int count;
	CString strSearch;
	BOOL isVisible;
	virtual ~CSample13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample13View)
	afx_msg void OnExit();
	afx_msg void OnSearch();
	afx_msg void OnStart();
	afx_msg void OnRecords();
	afx_msg void OnVisible();
	afx_msg void OnClearresults();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sample13View.cpp
inline CSample13Doc* CSample13View::GetDocument()
   { return (CSample13Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE13VIEW_H__F1CE9982_1CA1_427D_93BA_DBB1B68A0047__INCLUDED_)
