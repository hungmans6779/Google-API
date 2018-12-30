// SEARCH.cpp : implementation file
//

#include "stdafx.h"
#include "sample8.h"
#include "SEARCH.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSEARCH dialog


CSEARCH::CSEARCH(CWnd* pParent /*=NULL*/)
	: CDialog(CSEARCH::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSEARCH)
	m_filename = _T("");
	//}}AFX_DATA_INIT
}


void CSEARCH::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSEARCH)
	DDX_Text(pDX, IDC_EDIT1, m_filename);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSEARCH, CDialog)
	//{{AFX_MSG_MAP(CSEARCH)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSEARCH message handlers
