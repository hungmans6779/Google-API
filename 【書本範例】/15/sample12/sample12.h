// sample12.h : main header file for the SAMPLE12 application
//

#if !defined(AFX_SAMPLE12_H__80E1849D_1D7D_426A_8BEF_EFB016EEAA0D__INCLUDED_)
#define AFX_SAMPLE12_H__80E1849D_1D7D_426A_8BEF_EFB016EEAA0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample12App:
// See sample12.cpp for the implementation of this class
//

class CSample12App : public CWinApp
{
public:
	CSample12App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample12App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSample12App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE12_H__80E1849D_1D7D_426A_8BEF_EFB016EEAA0D__INCLUDED_)
