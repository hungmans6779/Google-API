// sample14.h : main header file for the SAMPLE14 application
//

#if !defined(AFX_SAMPLE14_H__B926655C_E5E9_4E31_A9BF_FC4375095C2E__INCLUDED_)
#define AFX_SAMPLE14_H__B926655C_E5E9_4E31_A9BF_FC4375095C2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample14App:
// See sample14.cpp for the implementation of this class
//

class CSample14App : public CWinApp
{
public:
	CSample14App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample14App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSample14App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE14_H__B926655C_E5E9_4E31_A9BF_FC4375095C2E__INCLUDED_)
