#if !defined(AFX_COORD_H__7184C705_2540_4941_B00A_A5C84E37E6D7__INCLUDED_)
#define AFX_COORD_H__7184C705_2540_4941_B00A_A5C84E37E6D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// COORD.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCOORD dialog

class CCOORD : public CDialog
{
// Construction
public:
	CCOORD(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCOORD)
	enum { IDD = IDD_COORD };
	int		m_x;
	int		m_y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCOORD)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCOORD)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORD_H__7184C705_2540_4941_B00A_A5C84E37E6D7__INCLUDED_)
