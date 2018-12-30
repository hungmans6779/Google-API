// sample6.h : main header file for the SAMPLE6 application
//

#if !defined(AFX_SAMPLE6_H__9428D5C9_5C10_41DE_9AEC_A61EF2DE88B3__INCLUDED_)
#define AFX_SAMPLE6_H__9428D5C9_5C10_41DE_9AEC_A61EF2DE88B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample6App:
// See sample6.cpp for the implementation of this class
//

class CSample6App : public CWinApp
{
public:
	CSample6App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSample6App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE6_H__9428D5C9_5C10_41DE_9AEC_A61EF2DE88B3__INCLUDED_)
