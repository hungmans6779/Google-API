// sample15Dlg.h : header file
//

#if !defined(AFX_SAMPLE15DLG_H__76F85369_3991_4095_8CCA_FE6916063DE2__INCLUDED_)
#define AFX_SAMPLE15DLG_H__76F85369_3991_4095_8CCA_FE6916063DE2__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSample15Dlg dialog

class CSample15Dlg : public CDialog
{
// Construction
public:
	IApplicationGE m_geApplication;
	ITourControllerGE tourControl;
	BOOL m_active;
	BOOL isPlay;
	BOOL isSearch;
    CString pathName;
	CSample15Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample15Dlg)
	enum { IDD = IDD_SAMPLE15_DIALOG };
	CString	m_from;
	CString	m_to;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample15Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample15Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnPathSearch();
	afx_msg void OnExit();
	afx_msg void OnPlay();
	afx_msg void OnPause();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE15DLG_H__76F85369_3991_4095_8CCA_FE6916063DE2__INCLUDED_)
