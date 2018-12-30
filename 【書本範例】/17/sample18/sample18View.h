// sample18View.h : interface of the CSample18View class
//
/////////////////////////////////////////////////////////////////////////////
#include "googleearth.h"

#if !defined(AFX_SAMPLE18VIEW_H__961C3E27_AD8C_4CCB_BBFD_93094875A8A3__INCLUDED_)
#define AFX_SAMPLE18VIEW_H__961C3E27_AD8C_4CCB_BBFD_93094875A8A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample18View : public CView
{
protected: // create from serialization only
	CSample18View();
	DECLARE_DYNCREATE(CSample18View)

// Attributes
public:
	CSample18Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample18View)
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
	bool m_active,dia;
	int Width,Height;
	IApplicationGE m_geApplication;
	int geoLon1,geoLon2,geoLon3;
	int geoLat1,geoLat2,geoLat3;
	double geoElv;
	double plon,plat,tlon,tlat;
	double mlon,mlat;
	int j;
	virtual ~CSample18View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample18View)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sample18View.cpp
inline CSample18Doc* CSample18View::GetDocument()
   { return (CSample18Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE18VIEW_H__961C3E27_AD8C_4CCB_BBFD_93094875A8A3__INCLUDED_)
