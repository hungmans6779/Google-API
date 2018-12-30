// CREATE.cpp : implementation file
//

#include "stdafx.h"
#include "sample15.h"
#include "CREATE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCREATE dialog


CCREATE::CCREATE(CWnd* pParent /*=NULL*/)
	: CDialog(CCREATE::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCREATE)
	m_lineFile = _T("");
	//}}AFX_DATA_INIT
}


void CCREATE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCREATE)
	DDX_Text(pDX, IDC_EDIT1, m_lineFile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCREATE, CDialog)
	//{{AFX_MSG_MAP(CCREATE)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCREATE message handlers
