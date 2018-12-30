// sample17Dlg.h : header file
//

#if !defined(AFX_SAMPLE17DLG_H__F93094AF_B8D2_434E_94DB_0EFF1631975C__INCLUDED_)
#define AFX_SAMPLE17DLG_H__F93094AF_B8D2_434E_94DB_0EFF1631975C__INCLUDED_

#include "googleearth.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSample17Dlg dialog

class CSample17Dlg : public CDialog
{
// Construction
public:
	CString* GetFilename(CString addline);
	CString FormatName(CString name);
	CString GetResultsList(CString addline);
	int* OrderLine(int* lineNum);
	CString GetInsection(CString linepart);
	int* GetLine2(int line1,int line2);
	IApplicationGE m_geApplication;
	BOOL m_active;
	int solution;
	CString addline;
	CString* addlineN;
	CString temp_languageAll;
	CString temp_linepartAll;
	CString temp_intersectionAll;
	CString temp_linerelationAll;
	CSample17Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSample17Dlg)
	enum { IDD = IDD_SAMPLE17_DIALOG };
	CString	m_startName;
	CString	m_endName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample17Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSample17Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnExit();
	afx_msg void OnQuery1();
	afx_msg void OnDblclkList1();
	afx_msg void OnInitialize();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE17DLG_H__F93094AF_B8D2_434E_94DB_0EFF1631975C__INCLUDED_)
