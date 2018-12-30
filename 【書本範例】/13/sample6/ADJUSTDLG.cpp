// ADJUSTDLG.cpp : implementation file
//

#include "stdafx.h"
#include "sample6.h"
#include "ADJUSTDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADJUSTDLG dialog


CADJUSTDLG::CADJUSTDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CADJUSTDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADJUSTDLG)
	m_geRange = 20;
	m_geTilt = 0;
	IsTimer=TRUE;
	m_geAzimuth = 0;
	//}}AFX_DATA_INIT
}


void CADJUSTDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADJUSTDLG)
	DDX_Control(pDX, IDC_SLIDER3, m_slide3);
	DDX_Control(pDX, IDC_SLIDER2, m_slide2);
	DDX_Control(pDX, IDC_SLIDER1, m_slide1);
	DDX_Text(pDX, IDC_EDIT1, m_geRange);
	DDX_Text(pDX, IDC_EDIT2, m_geTilt);
	DDX_Text(pDX, IDC_EDIT3, m_geAzimuth);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CADJUSTDLG, CDialog)
	//{{AFX_MSG_MAP(CADJUSTDLG)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, OnCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, OnCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, OnCustomdrawSlider3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADJUSTDLG message handlers

void CADJUSTDLG::OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); 
	//在文本框显示滑块值
	m_geRange=(50-m_slide1.GetPos())/10; 
	UpdateData(FALSE);  
	
	*pResult = 0;
}

void CADJUSTDLG::OnOK() 
{
	// TODO: Add extra validation here
	IsTimer=FALSE;
    CDialog::OnOK();
}

void CADJUSTDLG::OnCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); 
	//在文本框显示滑块值
	m_geTilt=(m_slide2.GetPos()*90)/100;
	UpdateData(FALSE); 
	
	*pResult = 0;
}

void CADJUSTDLG::OnCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); 
	//在文本框显示滑块值
	m_geAzimuth=((m_slide3.GetPos()-50)*180)/50;
	UpdateData(FALSE); 
	
	*pResult = 0;
}
