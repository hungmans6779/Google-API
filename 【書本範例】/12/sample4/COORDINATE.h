#if !defined(AFX_COORDINATE_H__DA548378_508E_4E05_A649_AE45D876B883__INCLUDED_)
#define AFX_COORDINATE_H__DA548378_508E_4E05_A649_AE45D876B883__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// COORDINATE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCOORDINATE dialog

class CCOORDINATE : public CDialog
{
// Construction
public:
	CCOORDINATE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCOORDINATE)
	enum { IDD = IDD_COORDINATE };
	int		m_x;
	int		m_y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCOORDINATE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCOORDINATE)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDINATE_H__DA548378_508E_4E05_A649_AE45D876B883__INCLUDED_)
