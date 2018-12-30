// sample16Dlg.h : header file
//

#if !defined(AFX_SAMPLE16DLG_H__932BE67A_C927_488B_9AB1_39F5583A689F__INCLUDED_)
#define AFX_SAMPLE16DLG_H__932BE67A_C927_488B_9AB1_39F5583A689F__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSample16Dlg dialog

class CSample16Dlg : public CDialog
{
// Construction
public:
	IApplicationGE m_geApplication;
	IAnimationControllerGE m_geAnimate;
	ITourControllerGE m_geTour;
    ITimeIntervalGE startInterval;
	IFeatureGE line1,line2;
	BOOL m_active;
	BOOL isExit;
	BOOL isAnimate;
	BOOL isPlay;
	CSample16Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample16Dlg)
	enum { IDD = IDD_SAMPLE16_DIALOG };
	CSliderCtrl	m_time;
	int		m_hour;
	int		m_min;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample16Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample16Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnGo();
	afx_msg void OnExit();
	afx_msg void OnAnimation();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE16DLG_H__932BE67A_C927_488B_9AB1_39F5583A689F__INCLUDED_)
