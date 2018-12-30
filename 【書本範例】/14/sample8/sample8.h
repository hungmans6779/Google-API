// sample8.h : main header file for the SAMPLE8 application
//

#if !defined(AFX_SAMPLE8_H__71004CEB_2CE2_427B_ADFA_46936E1AA3BA__INCLUDED_)
#define AFX_SAMPLE8_H__71004CEB_2CE2_427B_ADFA_46936E1AA3BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample8App:
// See sample8.cpp for the implementation of this class
//

class CSample8App : public CWinApp
{
public:
	CSample8App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample8App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSample8App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE8_H__71004CEB_2CE2_427B_ADFA_46936E1AA3BA__INCLUDED_)
