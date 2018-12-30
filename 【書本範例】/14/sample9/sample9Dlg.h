// sample9Dlg.h : header file
//

#if !defined(AFX_SAMPLE9DLG_H__A95B3A81_17E2_4E27_91C3_58C65DC43034__INCLUDED_)
#define AFX_SAMPLE9DLG_H__A95B3A81_17E2_4E27_91C3_58C65DC43034__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSample9Dlg dialog

class CSample9Dlg : public CDialog
{
// Construction
public:
	IApplicationGE m_geApplication;
	BOOL m_active;
	double ItoD(int x,int y,double z);
	CSample9Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample9Dlg)
	enum { IDD = IDD_SAMPLE9_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample9Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample9Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnDynamic();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE9DLG_H__A95B3A81_17E2_4E27_91C3_58C65DC43034__INCLUDED_)
