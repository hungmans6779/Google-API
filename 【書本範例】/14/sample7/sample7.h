// sample7.h : main header file for the SAMPLE7 application
//

#if !defined(AFX_SAMPLE7_H__B535B426_1786_4B95_B392_2454B1B6619C__INCLUDED_)
#define AFX_SAMPLE7_H__B535B426_1786_4B95_B392_2454B1B6619C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample7App:
// See sample7.cpp for the implementation of this class
//

class CSample7App : public CWinApp
{
public:
	CSample7App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample7App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSample7App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE7_H__B535B426_1786_4B95_B392_2454B1B6619C__INCLUDED_)
