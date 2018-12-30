// RECORDS.cpp : implementation file
//

#include "stdafx.h"
#include "sample13.h"
#include "RECORDS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRECORDS dialog


CRECORDS::CRECORDS(CWnd* pParent /*=NULL*/)
	: CDialog(CRECORDS::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRECORDS)
	m_records = _T("");
	m_count = 0;
	//}}AFX_DATA_INIT
}


void CRECORDS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRECORDS)
	DDX_Text(pDX, IDC_EDIT1, m_records);
	DDX_Text(pDX, IDC_EDIT2, m_count);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRECORDS, CDialog)
	//{{AFX_MSG_MAP(CRECORDS)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRECORDS message handlers
