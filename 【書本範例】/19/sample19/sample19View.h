// sample19View.h : interface of the CSample19View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE19VIEW_H__982C3FCA_C87B_47D0_9397_8F8D2B5FB247__INCLUDED_)
#define AFX_SAMPLE19VIEW_H__982C3FCA_C87B_47D0_9397_8F8D2B5FB247__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample19View : public CView
{
protected: // create from serialization only
	CSample19View();
	DECLARE_DYNCREATE(CSample19View)

// Attributes
public:
	CSample19Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample19View)
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
	CString ReadFile(CString pathname);
	BOOL InOrOut(double pointx,double pointy,double focusx,double focusy);
	double* CordChange(CPoint point);
	BOOL isPlay;
	int tourOrAnimate;
	IApplicationGE m_geApplication;
	IFeatureGE m_geTempFile;
	IAnimationControllerGE m_geAnimate;
	ITourControllerGE m_geTour;
	IViewExtentsGE m_geExtents;
	ICameraInfoGE m_geCamera;
	BOOL m_active;
	double geLeft,geRight,geTop,geBottom;
	double geRange;
	virtual ~CSample19View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample19View)
	afx_msg void OnStart();
	afx_msg void OnReports();
	afx_msg void OnStation();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLeft();
	afx_msg void OnRight();
	afx_msg void OnDown();
	afx_msg void OnUp();
	afx_msg void OnLarge();
	afx_msg void OnSmall();
	afx_msg void OnSearch();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sample19View.cpp
inline CSample19Doc* CSample19View::GetDocument()
   { return (CSample19Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE19VIEW_H__982C3FCA_C87B_47D0_9397_8F8D2B5FB247__INCLUDED_)
