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
	//���C��زK�[��
	m_stations.AddString("�u�H��|�]");
	m_stations.AddString("��a��|�]");
	m_stations.AddString("������|�]");
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
		m_lineText.SetWindowText("403�����F");
		break;
	case 2:
		m_lineText.SetWindowText("�a�K2���u����328��");
		break;
	case 3:
		m_lineText.SetWindowText("�a�K2���u����714��");
		break;
	}
}

void CCSTATION::OnOK() 
{
	// TODO: Add extra validation here
	CDialog::OnOK();
}
