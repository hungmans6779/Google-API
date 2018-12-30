#if !defined(AFX_SEARCH_H__64346D0E_4C16_4584_8D91_6F4664503E0C__INCLUDED_)
#define AFX_SEARCH_H__64346D0E_4C16_4584_8D91_6F4664503E0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SEARCH.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSEARCH dialog

class CSEARCH : public CDialog
{
// Construction
public:
	CSEARCH(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSEARCH)
	enum { IDD = IDD_SEARCH };
	CString	m_strSearch;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSEARCH)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSEARCH)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCH_H__64346D0E_4C16_4584_8D91_6F4664503E0C__INCLUDED_)
