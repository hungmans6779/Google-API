// NEWS.cpp : implementation file
//

#include "stdafx.h"
#include "sample19.h"
#include "NEWS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNEWS dialog


CNEWS::CNEWS(CWnd* pParent /*=NULL*/)
	: CDialog(CNEWS::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNEWS)
	m_time = _T("");
	m_stadium = _T("");
	m_news = _T("");
	//}}AFX_DATA_INIT
}


void CNEWS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNEWS)
	DDX_Text(pDX, IDC_TIME, m_time);
	DDX_Text(pDX, IDC_STADIUM, m_stadium);
	DDX_Text(pDX, IDC_EDIT1, m_news);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNEWS, CDialog)
	//{{AFX_MSG_MAP(CNEWS)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNEWS message handlers
