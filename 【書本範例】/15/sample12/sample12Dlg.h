// sample12Dlg.h : header file
//

#if !defined(AFX_SAMPLE12DLG_H__2138F6CF_08B2_44A5_B37E_7E240BA1AC7A__INCLUDED_)
#define AFX_SAMPLE12DLG_H__2138F6CF_08B2_44A5_B37E_7E240BA1AC7A__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSample12Dlg dialog

class CSample12Dlg : public CDialog
{
// Construction
public:
	IApplicationGE m_geApplication;
	ISearchControllerGE searchControl;
	IFeatureCollectionGE collect;
	IFeatureGE feature[10];
	BOOL m_active;
	int count;
	CSample12Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample12Dlg)
	enum { IDD = IDD_SAMPLE12_DIALOG };
	CString	m_results;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample12Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample12Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnSearch();
	afx_msg void OnExit();
	afx_msg void OnDblclkList1();
	afx_msg void OnShow();
	afx_msg void OnShow2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE12DLG_H__2138F6CF_08B2_44A5_B37E_7E240BA1AC7A__INCLUDED_)
