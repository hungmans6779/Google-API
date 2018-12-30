// sample3Dlg.h : header file
//

#if !defined(AFX_SAMPLE3DLG_H__4AE5BDA4_3691_4B7E_A956_5FFC736C35CD__INCLUDED_)
#define AFX_SAMPLE3DLG_H__4AE5BDA4_3691_4B7E_A956_5FFC736C35CD__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSample3Dlg dialog

class CSample3Dlg : public CDialog
{
// Construction
public:
	int m_direction;
	IApplicationGE m_geApplication;
	double xFocus,yFocus;
	double geLeft,geRight,geTop,geBottom;
	double deltax,deltay;
	double geRange;
	CSample3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample3Dlg)
	enum { IDD = IDD_SAMPLE3_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnPosition();
	afx_msg void OnMove();
	afx_msg void OnExit();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE3DLG_H__4AE5BDA4_3691_4B7E_A956_5FFC736C35CD__INCLUDED_)
