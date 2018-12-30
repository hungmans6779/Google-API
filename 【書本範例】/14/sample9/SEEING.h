#if !defined(AFX_SEEING_H__E9DC1109_91A6_41F5_862E_61959C7E0E1B__INCLUDED_)
#define AFX_SEEING_H__E9DC1109_91A6_41F5_862E_61959C7E0E1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SEEING.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSEEING dialog

class CSEEING : public CDialog
{
// Construction
public:
	CSEEING(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSEEING)
	enum { IDD = IDD_SEEING };
	CString	m_tip;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSEEING)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSEEING)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEEING_H__E9DC1109_91A6_41F5_862E_61959C7E0E1B__INCLUDED_)
