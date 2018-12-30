// sample4Dlg.h : header file
//

#if !defined(AFX_SAMPLE4DLG_H__8EBAF20C_F8D6_4581_B5EA_8F0A087FD24E__INCLUDED_)
#define AFX_SAMPLE4DLG_H__8EBAF20C_F8D6_4581_B5EA_8F0A087FD24E__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSample4Dlg dialog

class CSample4Dlg : public CDialog
{
// Construction
public:
	BOOL m_active;
	IApplicationGE m_geApplication;
	int geoLon1,geoLon2,geoLon3;
	int geoLat1,geoLat2,geoLat3;
	double geoElv;
	CSample4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample4Dlg)
	enum { IDD = IDD_SAMPLE4_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample4Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCoord();
	afx_msg void OnStart();
	afx_msg void OnPosition();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE4DLG_H__8EBAF20C_F8D6_4581_B5EA_8F0A087FD24E__INCLUDED_)
