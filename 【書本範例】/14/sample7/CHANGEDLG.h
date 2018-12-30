#if !defined(AFX_CHANGEDLG_H__EA49FFD3_2E19_45D8_AFB2_A46FA5799029__INCLUDED_)
#define AFX_CHANGEDLG_H__EA49FFD3_2E19_45D8_AFB2_A46FA5799029__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CHANGEDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCHANGEDLG dialog

class CCHANGEDLG : public CDialog
{
// Construction
public:
	int m_viewCount;
	BOOL IsTimer;
	CCHANGEDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCHANGEDLG)
	enum { IDD = IDD_CHANGEDLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCHANGEDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCHANGEDLG)
	afx_msg void OnChangebtn();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEDLG_H__EA49FFD3_2E19_45D8_AFB2_A46FA5799029__INCLUDED_)
