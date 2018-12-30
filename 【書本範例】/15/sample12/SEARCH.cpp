// SEARCH.cpp : implementation file
//

#include "stdafx.h"
#include "sample12.h"
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
	m_area = -1;
	m_strSearch = _T("");
	//}}AFX_DATA_INIT
}


void CSEARCH::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSEARCH)
	DDX_Radio(pDX, IDC_RADIO1, m_area);
	DDX_Text(pDX, IDC_EDIT1, m_strSearch);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSEARCH, CDialog)
	//{{AFX_MSG_MAP(CSEARCH)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSEARCH message handlers
