// sample5.h : main header file for the SAMPLE5 application
//

#if !defined(AFX_SAMPLE5_H__E2FAF745_69D4_44FF_9775_31D8822955FC__INCLUDED_)
#define AFX_SAMPLE5_H__E2FAF745_69D4_44FF_9775_31D8822955FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample5App:
// See sample5.cpp for the implementation of this class
//

class CSample5App : public CWinApp
{
public:
	CSample5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSample5App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE5_H__E2FAF745_69D4_44FF_9775_31D8822955FC__INCLUDED_)
