// LAYERSCONTROL.cpp : implementation file
//

#include "stdafx.h"
#include "sample11.h"
#include "LAYERSCONTROL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLAYERSCONTROL dialog


CLAYERSCONTROL::CLAYERSCONTROL(CWnd* pParent /*=NULL*/)
	: CDialog(CLAYERSCONTROL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLAYERSCONTROL)
	m_terrain = FALSE;
	m_web = FALSE;
	m_community = FALSE;
	m_transportation = FALSE;
	m_nature = FALSE;
	m_content = FALSE;
	m_awareness = FALSE;
	m_roads = FALSE;
	m_borders = FALSE;
	m_citys = FALSE;
	//}}AFX_DATA_INIT
}


void CLAYERSCONTROL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLAYERSCONTROL)
	DDX_Check(pDX, IDC_CHECK1, m_terrain);
	DDX_Check(pDX, IDC_CHECK3, m_web);
	DDX_Check(pDX, IDC_CHECK13, m_community);
	DDX_Check(pDX, IDC_CHECK15, m_transportation);
	DDX_Check(pDX, IDC_CHECK16, m_nature);
	DDX_Check(pDX, IDC_CHECK4, m_content);
	DDX_Check(pDX, IDC_CHECK5, m_awareness);
	DDX_Check(pDX, IDC_CHECK6, m_roads);
	DDX_Check(pDX, IDC_CHECK8, m_borders);
	DDX_Check(pDX, IDC_CHECK9, m_citys);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLAYERSCONTROL, CDialog)
	//{{AFX_MSG_MAP(CLAYERSCONTROL)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLAYERSCONTROL message handlers
