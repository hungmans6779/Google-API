// SEARCHDLG.cpp : implementation file
//

#include "stdafx.h"
#include "sample19.h"
#include "SEARCHDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSEARCHDLG dialog


CSEARCHDLG::CSEARCHDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CSEARCHDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSEARCHDLG)
	//}}AFX_DATA_INIT
}


void CSEARCHDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSEARCHDLG)
	DDX_Control(pDX, IDC_COMBO1, m_select);
	//}}AFX_DATA_MAP
	m_select.AddString("田徑");
	m_select.AddString("足球");
	m_select.AddString("乒乓球");
	m_select.AddString("籃球");
	m_select.AddString("舉重");
	m_select.AddString("射擊");
}


BEGIN_MESSAGE_MAP(CSEARCHDLG, CDialog)
	//{{AFX_MSG_MAP(CSEARCHDLG)
	ON_CBN_SELENDOK(IDC_COMBO1, OnSelendokCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSEARCHDLG message handlers


void CSEARCHDLG::OnSelendokCombo1() 
{
	// TODO: Add your control notification handler code here
	m_item=m_select.GetCurSel();
}
