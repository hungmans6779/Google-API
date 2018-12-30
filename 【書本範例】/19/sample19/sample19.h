// sample19.h : main header file for the SAMPLE19 application
//

#if !defined(AFX_SAMPLE19_H__688E7F64_3705_45E6_8622_3C9EC6F4B84E__INCLUDED_)
#define AFX_SAMPLE19_H__688E7F64_3705_45E6_8622_3C9EC6F4B84E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSample19App:
// See sample19.cpp for the implementation of this class
//

class CSample19App : public CWinApp
{
public:
	CSample19App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample19App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSample19App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE19_H__688E7F64_3705_45E6_8622_3C9EC6F4B84E__INCLUDED_)
