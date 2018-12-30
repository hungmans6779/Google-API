// sample11Dlg.h : header file
//

#if !defined(AFX_SAMPLE11DLG_H__1E55F679_51DA_4478_9E7E_CB00E619D8DD__INCLUDED_)
#define AFX_SAMPLE11DLG_H__1E55F679_51DA_4478_9E7E_CB00E619D8DD__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSample11Dlg dialog

class CSample11Dlg : public CDialog
{
// Construction
public:
	IApplicationGE m_geApplication;
	IFeatureGE* m_geFeature;
	IFeatureCollectionGE m_geCollect;
	int countSum;
	int timeControl;
	BOOL m_active;
	CSample11Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample11Dlg)
	enum { IDD = IDD_SAMPLE11_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample11Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample11Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnLayers();
	afx_msg void OnExit();
	afx_msg void OnViewinit();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE11DLG_H__1E55F679_51DA_4478_9E7E_CB00E619D8DD__INCLUDED_)
