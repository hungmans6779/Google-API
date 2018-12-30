// CHANGEDLG.cpp : implementation file
//

#include "stdafx.h"
#include "sample7.h"
#include "CHANGEDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCHANGEDLG dialog


CCHANGEDLG::CCHANGEDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CCHANGEDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCHANGEDLG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_viewCount=0;
	IsTimer=TRUE;
}


void CCHANGEDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCHANGEDLG)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCHANGEDLG, CDialog)
	//{{AFX_MSG_MAP(CCHANGEDLG)
	ON_BN_CLICKED(IDC_CHANGEBTN, OnChangebtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCHANGEDLG message handlers

void CCHANGEDLG::OnChangebtn() 
{
	// TODO: Add your control notification handler code here
	m_viewCount++;
}

void CCHANGEDLG::OnOK() 
{
	// TODO: Add extra validation here
	IsTimer=FALSE;
	CDialog::OnOK();
}
