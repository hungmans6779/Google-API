// sample14Dlg.h : header file
//

#if !defined(AFX_SAMPLE14DLG_H__4B78742E_5642_43E6_A013_C5A9D6C41F62__INCLUDED_)
#define AFX_SAMPLE14DLG_H__4B78742E_5642_43E6_A013_C5A9D6C41F62__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSample14Dlg dialog

class CSample14Dlg : public CDialog
{
// Construction
public:
	IApplicationGE m_geApplication;
	ISearchControllerGE m_geSearchControl;
	BOOL m_active;
	BOOL isPlay;
	BOOL isRemove;
	int strCount;
	IFeatureGE* m_geFeature;
	ITourControllerGE m_geTour;
	CString* strFlag;
	CSample14Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample14Dlg)
	enum { IDD = IDD_SAMPLE14_DIALOG };
	CSliderCtrl	m_speed;
	int		m_cycles;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample14Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample14Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnSearchs();
	afx_msg void OnPlay();
	afx_msg void OnPause();
	afx_msg void OnExit();
	afx_msg void OnStop();
	afx_msg void OnRemove();
	afx_msg void OnClearresults();
	afx_msg void OnDblclkList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE14DLG_H__4B78742E_5642_43E6_A013_C5A9D6C41F62__INCLUDED_)
