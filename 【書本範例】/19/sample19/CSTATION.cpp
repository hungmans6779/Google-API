// CSTATION.cpp : implementation file
//

#include "stdafx.h"
#include "sample19.h"
#include "CSTATION.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CCSTATION dialog
CCSTATION::CCSTATION(CWnd* pParent /*=NULL*/)
	: CDialog(CCSTATION::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCSTATION)
	//}}AFX_DATA_INIT
}


void CCSTATION::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCSTATION)
	DDX_Control(pDX, IDC_EDIT1, m_lineText);
	DDX_Control(pDX, IDC_LIST1, m_stations);
	//}}AFX_DATA_MAP
	//為列表框添加表項
	m_stations.AddString("工人體育館");
	m_stations.AddString("國家體育館");
	m_stations.AddString("首都體育館");
}


BEGIN_MESSAGE_MAP(CCSTATION, CDialog)
	//{{AFX_MSG_MAP(CCSTATION)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCSTATION message handlers

void CCSTATION::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	line=m_stations.GetCurSel()+1;
	switch(line)
	{
	case 1:
		m_lineText.SetWindowText("403路直達");
		break;
	case 2:
		m_lineText.SetWindowText("地鐵2號線換乘328路");
		break;
	case 3:
		m_lineText.SetWindowText("地鐵2號線換乘714路");
		break;
	}
}

void CCSTATION::OnOK() 
{
	// TODO: Add extra validation here
	CDialog::OnOK();
}
