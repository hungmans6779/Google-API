// COORDINATE.cpp : implementation file
//

#include "stdafx.h"
#include "sample4.h"
#include "COORDINATE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCOORDINATE dialog


CCOORDINATE::CCOORDINATE(CWnd* pParent /*=NULL*/)
	: CDialog(CCOORDINATE::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCOORDINATE)
	m_x = 0;
	m_y = 0;
	//}}AFX_DATA_INIT
}


void CCOORDINATE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCOORDINATE)
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCOORDINATE, CDialog)
	//{{AFX_MSG_MAP(CCOORDINATE)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCOORDINATE message handlers
