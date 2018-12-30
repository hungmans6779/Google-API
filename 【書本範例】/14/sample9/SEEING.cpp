// SEEING.cpp : implementation file
//

#include "stdafx.h"
#include "sample9.h"
#include "SEEING.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSEEING dialog


CSEEING::CSEEING(CWnd* pParent /*=NULL*/)
	: CDialog(CSEEING::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSEEING)
	m_tip = _T("");
	//}}AFX_DATA_INIT
}


void CSEEING::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSEEING)
	DDX_Text(pDX, IDC_SEEING, m_tip);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSEEING, CDialog)
	//{{AFX_MSG_MAP(CSEEING)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSEEING message handlers
