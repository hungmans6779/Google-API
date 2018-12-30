// sample10.h : main header file for the SAMPLE10 application
//

#if !defined(AFX_SAMPLE10_H__0D571DF8_6C3B_4BD8_BF0B_FAD316128544__INCLUDED_)
#define AFX_SAMPLE10_H__0D571DF8_6C3B_4BD8_BF0B_FAD316128544__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample10App:
// See sample10.cpp for the implementation of this class
//

class CSample10App : public CWinApp
{
public:
	CSample10App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample10App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSample10App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE10_H__0D571DF8_6C3B_4BD8_BF0B_FAD316128544__INCLUDED_)
