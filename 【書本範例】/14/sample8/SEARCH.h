#if !defined(AFX_SEARCH_H__07DDB83C_F0A3_4403_9ADA_641A6F88E2CC__INCLUDED_)
#define AFX_SEARCH_H__07DDB83C_F0A3_4403_9ADA_641A6F88E2CC__INCLUDED_

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
	CString	m_filename;
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

#endif // !defined(AFX_SEARCH_H__07DDB83C_F0A3_4403_9ADA_641A6F88E2CC__INCLUDED_)
