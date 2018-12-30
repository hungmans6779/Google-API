// sample6View.h : interface of the CSample6View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE6VIEW_H__DC99FF40_8CCF_4650_A18F_B13989E70C5C__INCLUDED_)
#define AFX_SAMPLE6VIEW_H__DC99FF40_8CCF_4650_A18F_B13989E70C5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ADJUSTDLG.h"
#include "googleearth.h"	// Added by ClassView
class CSample6View : public CView
{
protected: // create from serialization only
	CSample6View();
	DECLARE_DYNCREATE(CSample6View)

// Attributes
public:
	CSample6Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample6View)
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
	ICameraInfoGE m_geCamera;
	BOOL m_active;
	IApplicationGE m_geApplication;
	int dlgRange;		//对话框的当前视高
	int dlgTilt;		//对话框的当前倾斜视角
	int dlgAzimuth;		//对话框的当前方位视角
	double oldRange;
	double geMutiple;	//缩放的倍数
	CADJUSTDLG *pAdjustDlg;
	virtual ~CSample6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample6View)
	afx_msg void OnStart();
	afx_msg void OnOpen();
	afx_msg void OnAdjust();
	afx_msg void OnSave();
	afx_msg void OnExit();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sample6View.cpp
inline CSample6Doc* CSample6View::GetDocument()
   { return (CSample6Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE6VIEW_H__DC99FF40_8CCF_4650_A18F_B13989E70C5C__INCLUDED_)
