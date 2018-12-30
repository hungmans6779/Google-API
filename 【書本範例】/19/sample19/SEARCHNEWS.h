#if !defined(AFX_SEARCHNEWS_H__2F60DE4F_EEE5_4045_B673_83352C5E68B0__INCLUDED_)
#define AFX_SEARCHNEWS_H__2F60DE4F_EEE5_4045_B673_83352C5E68B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SEARCHNEWS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSEARCHNEWS dialog

class CSEARCHNEWS : public CDialog
{
// Construction
public:
	CSEARCHNEWS(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSEARCHNEWS)
	enum { IDD = IDD_DIALOG5 };
	CString	m_begintime;
	CString	m_endtime;
	CString	m_stadium;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSEARCHNEWS)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSEARCHNEWS)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHNEWS_H__2F60DE4F_EEE5_4045_B673_83352C5E68B0__INCLUDED_)
