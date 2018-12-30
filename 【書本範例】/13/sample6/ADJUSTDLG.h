#if !defined(AFX_ADJUSTDLG_H__71297772_76A9_4285_A04E_65FC3387460B__INCLUDED_)
#define AFX_ADJUSTDLG_H__71297772_76A9_4285_A04E_65FC3387460B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADJUSTDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CADJUSTDLG dialog

class CADJUSTDLG : public CDialog
{
// Construction
public:
	BOOL IsTimer;
	CADJUSTDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CADJUSTDLG)
	enum { IDD = IDD_ADJUSTDLG };
	CSliderCtrl	m_slide3;
	CSliderCtrl	m_slide2;
	CSliderCtrl	m_slide1;
	int		m_geRange;
	int		m_geTilt;
	int		m_geAzimuth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADJUSTDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CADJUSTDLG)
	afx_msg void OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADJUSTDLG_H__71297772_76A9_4285_A04E_65FC3387460B__INCLUDED_)
