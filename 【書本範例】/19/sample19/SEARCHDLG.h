#if !defined(AFX_SEARCHDLG_H__EBA11DAD_CC3F_40A3_A7E0_7F407A6810AC__INCLUDED_)
#define AFX_SEARCHDLG_H__EBA11DAD_CC3F_40A3_A7E0_7F407A6810AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SEARCHDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSEARCHDLG dialog

class CSEARCHDLG : public CDialog
{
// Construction
public:
	int m_item;
	CSEARCHDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSEARCHDLG)
	enum { IDD = IDD_DIALOG4 };
	CComboBox	m_select;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSEARCHDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSEARCHDLG)
	afx_msg void OnSelendokCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHDLG_H__EBA11DAD_CC3F_40A3_A7E0_7F407A6810AC__INCLUDED_)
