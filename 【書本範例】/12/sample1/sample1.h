// sample1.h : main header file for the SAMPLE1 application
//

#if !defined(AFX_SAMPLE1_H__759AE569_660D_4FF3_BF35_A59D1421815D__INCLUDED_)
#define AFX_SAMPLE1_H__759AE569_660D_4FF3_BF35_A59D1421815D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample1App:
// See sample1.cpp for the implementation of this class
//

class CSample1App : public CWinApp
{
public:
	CSample1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSample1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE1_H__759AE569_660D_4FF3_BF35_A59D1421815D__INCLUDED_)
