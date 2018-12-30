// sample17.h : main header file for the SAMPLE17 application
//

#if !defined(AFX_SAMPLE17_H__2BB233C0_0CCC_4D80_9A62_CE73B979DF61__INCLUDED_)
#define AFX_SAMPLE17_H__2BB233C0_0CCC_4D80_9A62_CE73B979DF61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample17App:
// See sample17.cpp for the implementation of this class
//

class CSample17App : public CWinApp
{
public:
	CSample17App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample17App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSample17App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE17_H__2BB233C0_0CCC_4D80_9A62_CE73B979DF61__INCLUDED_)
