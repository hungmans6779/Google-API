// SEARCHNEWS.cpp : implementation file
//

#include "stdafx.h"
#include "sample19.h"
#include "SEARCHNEWS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSEARCHNEWS dialog


CSEARCHNEWS::CSEARCHNEWS(CWnd* pParent /*=NULL*/)
	: CDialog(CSEARCHNEWS::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSEARCHNEWS)
	m_begintime = _T("");
	m_endtime = _T("");
	m_stadium = _T("");
	//}}AFX_DATA_INIT
}


void CSEARCHNEWS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSEARCHNEWS)
	DDX_Text(pDX, IDC_BEGINTIME, m_begintime);
	DDX_Text(pDX, IDC_ENDTIME, m_endtime);
	DDX_Text(pDX, IDC_SEARCH_STADIUM, m_stadium);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSEARCHNEWS, CDialog)
	//{{AFX_MSG_MAP(CSEARCHNEWS)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSEARCHNEWS message handlers
