#if !defined(AFX_RECORDS_H__6249744B_939C_45D7_AFC6_D6300CD07F25__INCLUDED_)
#define AFX_RECORDS_H__6249744B_939C_45D7_AFC6_D6300CD07F25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RECORDS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRECORDS dialog

class CRECORDS : public CDialog
{
// Construction
public:
	CRECORDS(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRECORDS)
	enum { IDD = IDD_RECORDS };
	CString	m_records;
	int		m_count;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRECORDS)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRECORDS)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDS_H__6249744B_939C_45D7_AFC6_D6300CD07F25__INCLUDED_)
