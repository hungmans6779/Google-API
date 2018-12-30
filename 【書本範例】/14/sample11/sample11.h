// sample11.h : main header file for the SAMPLE11 application
//

#if !defined(AFX_SAMPLE11_H__1DFD7DDA_0665_44E3_8C38_8E679F470455__INCLUDED_)
#define AFX_SAMPLE11_H__1DFD7DDA_0665_44E3_8C38_8E679F470455__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample11App:
// See sample11.cpp for the implementation of this class
//

class CSample11App : public CWinApp
{
public:
	CSample11App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample11App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSample11App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE11_H__1DFD7DDA_0665_44E3_8C38_8E679F470455__INCLUDED_)
