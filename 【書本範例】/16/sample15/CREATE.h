#if !defined(AFX_CREATE_H__2EC63460_EC0A_4435_847F_30460493D369__INCLUDED_)
#define AFX_CREATE_H__2EC63460_EC0A_4435_847F_30460493D369__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CREATE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCREATE dialog

class CCREATE : public CDialog
{
// Construction
public:
	CCREATE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCREATE)
	enum { IDD = IDD_CREATE };
	CString	m_lineFile;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCREATE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCREATE)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATE_H__2EC63460_EC0A_4435_847F_30460493D369__INCLUDED_)
