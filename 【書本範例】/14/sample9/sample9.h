// sample9.h : main header file for the SAMPLE9 application
//

#if !defined(AFX_SAMPLE9_H__5BBBE16F_20FA_4145_ADA6_E26A36FFBCFC__INCLUDED_)
#define AFX_SAMPLE9_H__5BBBE16F_20FA_4145_ADA6_E26A36FFBCFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample9App:
// See sample9.cpp for the implementation of this class
//

class CSample9App : public CWinApp
{
public:
	CSample9App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample9App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSample9App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE9_H__5BBBE16F_20FA_4145_ADA6_E26A36FFBCFC__INCLUDED_)
