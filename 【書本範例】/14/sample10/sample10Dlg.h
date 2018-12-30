// sample10Dlg.h : header file
//

#if !defined(AFX_SAMPLE10DLG_H__C40C7582_6042_45A8_A37B_E5A763264247__INCLUDED_)
#define AFX_SAMPLE10DLG_H__C40C7582_6042_45A8_A37B_E5A763264247__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSample10Dlg dialog

class CSample10Dlg : public CDialog
{
// Construction
public:
	IApplicationGE m_geApplication;
	BOOL m_active;
	int m_count;
	CSample10Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample10Dlg)
	enum { IDD = IDD_SAMPLE10_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample10Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample10Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnFeatureId();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE10DLG_H__C40C7582_6042_45A8_A37B_E5A763264247__INCLUDED_)
