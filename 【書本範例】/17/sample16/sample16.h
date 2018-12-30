// sample16.h : main header file for the SAMPLE16 application
//

#if !defined(AFX_SAMPLE16_H__2EEEAF84_2407_48F3_AA35_820A6D6071E6__INCLUDED_)
#define AFX_SAMPLE16_H__2EEEAF84_2407_48F3_AA35_820A6D6071E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample16App:
// See sample16.cpp for the implementation of this class
//

class CSample16App : public CWinApp
{
public:
	CSample16App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample16App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSample16App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE16_H__2EEEAF84_2407_48F3_AA35_820A6D6071E6__INCLUDED_)
