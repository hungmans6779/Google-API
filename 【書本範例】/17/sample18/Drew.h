#if !defined(AFX_DREW_H__85FD762E_F98A_4A99_BB0D_19FF99865AA0__INCLUDED_)
#define AFX_DREW_H__85FD762E_F98A_4A99_BB0D_19FF99865AA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Drew.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Drew dialog

class Drew : public CDialog
{
// Construction
public:
	Drew(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Drew)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Drew)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Drew)
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DREW_H__85FD762E_F98A_4A99_BB0D_19FF99865AA0__INCLUDED_)
