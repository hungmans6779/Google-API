// COORD.cpp : implementation file
//

#include "stdafx.h"
#include "sample4.h"
#include "COORD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCOORD dialog


CCOORD::CCOORD(CWnd* pParent /*=NULL*/)
	: CDialog(CCOORD::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCOORD)
	m_x = 0;
	m_y = 0;
	//}}AFX_DATA_INIT
}


void CCOORD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCOORD)
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT4, m_y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCOORD, CDialog)
	//{{AFX_MSG_MAP(CCOORD)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCOORD message handlers
