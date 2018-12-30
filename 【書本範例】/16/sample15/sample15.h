// sample15.h : main header file for the SAMPLE15 application
//

#if !defined(AFX_SAMPLE15_H__5AE0136A_268F_41D4_BC5D_822A9CDE8048__INCLUDED_)
#define AFX_SAMPLE15_H__5AE0136A_268F_41D4_BC5D_822A9CDE8048__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample15App:
// See sample15.cpp for the implementation of this class
//

class CSample15App : public CWinApp
{
public:
	CSample15App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample15App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSample15App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE15_H__5AE0136A_268F_41D4_BC5D_822A9CDE8048__INCLUDED_)
