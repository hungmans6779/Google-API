// sample7View.h : interface of the CSample7View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE7VIEW_H__152179FE_A62C_4477_8A60_2A9FF30D5B69__INCLUDED_)
#define AFX_SAMPLE7VIEW_H__152179FE_A62C_4477_8A60_2A9FF30D5B69__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CHANGEDLG.h"
class CSample7View : public CView
{
protected: // create from serialization only
	CSample7View();
	DECLARE_DYNCREATE(CSample7View)

// Attributes
public:
	CSample7Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample7View)
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
	IFeatureGE m_geFeature;
	IFeatureCollectionGE m_geCollection;
	BOOL m_active;
	int m_viewCount;
	int fileSum;
	IFeatureGE* bFeature;
    CCHANGEDLG* pChangeDlg;
	virtual ~CSample7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample7View)
	afx_msg void OnStart();
	afx_msg void OnOpen();
	afx_msg void OnSave();
	afx_msg void OnChange();
	afx_msg void OnExit();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sample7View.cpp
inline CSample7Doc* CSample7View::GetDocument()
   { return (CSample7Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE7VIEW_H__152179FE_A62C_4477_8A60_2A9FF30D5B69__INCLUDED_)
