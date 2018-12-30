// sample2Dlg.h : header file
//

#if !defined(AFX_SAMPLE2DLG_H__E453E069_98F8_458C_B037_42CEAC42A6CE__INCLUDED_)
#define AFX_SAMPLE2DLG_H__E453E069_98F8_458C_B037_42CEAC42A6CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
// CSample2Dlg dialog
#include "googleearth.h"
class CSample2Dlg : public CDialog
{
// Construction
public:
	int lon1;
	int lon2;
	int lon3;
	int lat1;
	int lat2;
	int lat3;
	IApplicationGE m_geApplication;
	CSample2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample2Dlg)
	enum { IDD = IDD_SAMPLE2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnPosition();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE2DLG_H__E453E069_98F8_458C_B037_42CEAC42A6CE__INCLUDED_)
