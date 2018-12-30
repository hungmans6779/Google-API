// sample13.h : main header file for the SAMPLE13 application
//

#if !defined(AFX_SAMPLE13_H__DD80D9E7_0CBC_4B1D_839D_76C39BD1AC6A__INCLUDED_)
#define AFX_SAMPLE13_H__DD80D9E7_0CBC_4B1D_839D_76C39BD1AC6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample13App:
// See sample13.cpp for the implementation of this class
//

class CSample13App : public CWinApp
{
public:
	CSample13App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample13App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSample13App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE13_H__DD80D9E7_0CBC_4B1D_839D_76C39BD1AC6A__INCLUDED_)
