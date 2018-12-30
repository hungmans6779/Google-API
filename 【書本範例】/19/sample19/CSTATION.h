#if !defined(AFX_CSTATION_H__5B799ED8_DB35_4CE5_82E2_69C10F17FCF0__INCLUDED_)
#define AFX_CSTATION_H__5B799ED8_DB35_4CE5_82E2_69C10F17FCF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CSTATION.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CCSTATION dialog

class CCSTATION : public CDialog
{
// Construction
public:
	int line;
	CCSTATION(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCSTATION)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_lineText;
	CListBox	m_stations;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSTATION)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCSTATION)
	afx_msg void OnDblclkList1();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTATION_H__5B799ED8_DB35_4CE5_82E2_69C10F17FCF0__INCLUDED_)
