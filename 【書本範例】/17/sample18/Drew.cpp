// Drew.cpp : implementation file
//

#include "stdafx.h"
#include "sample18.h"
#include "Drew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Drew dialog


Drew::Drew(CWnd* pParent /*=NULL*/)
	: CDialog(Drew::IDD, pParent)
{
	//{{AFX_DATA_INIT(Drew)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Drew::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Drew)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Drew, CDialog)
	//{{AFX_MSG_MAP(Drew)
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Drew message handlers

void Drew::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}
