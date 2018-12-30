// sample12Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "sample12.h"
#include "sample12Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "SEARCH.h"
static const CLSID CLSID_ApplicationGE = {0x8097D7E9,0xDB9E,0x4AEF, {0x9B,0x28,0x61,0xD8,0x2A,0x1D,0xF7,0x84}};
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample12Dlg dialog

CSample12Dlg::CSample12Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSample12Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSample12Dlg)
	m_results = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample12Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSample12Dlg)
	DDX_LBString(pDX, IDC_LIST1, m_results);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSample12Dlg, CDialog)
	//{{AFX_MSG_MAP(CSample12Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	ON_BN_CLICKED(IDC_SHOW2, OnShow2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample12Dlg message handlers

BOOL CSample12Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	::CoInitialize(NULL);
	m_active=FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSample12Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSample12Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSample12Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSample12Dlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	if(TRUE==m_active)
	{
		AfxMessageBox("客戶端已經啟動！");
		return;
	}
	m_active=TRUE;
	if(m_geApplication.IsInitialized())
	{
		m_geApplication.CreateDispatch(CLSID_ApplicationGE,NULL);
	}
}

void CSample12Dlg::OnSearch() 
{
	// TODO: Add your control notification handler code here
	CSEARCH searchDlg;
	int area;
	CString strSearch;
	if(IDOK==searchDlg.DoModal())
	{
		if(-1==searchDlg.m_area)
		{
			AfxMessageBox("未選擇地區！");
			return;
		}
		if(""==searchDlg.m_strSearch)
		{
			AfxMessageBox("未輸入位置！");
			return;
		}
		//獲取用戶的輸入信息
		area=searchDlg.m_area;
		strSearch=searchDlg.m_strSearch;
	}

	//根據用戶的輸入信息，預置地圖
	switch(area)
	{
	case 0:
		m_geApplication.SetCameraParams(30.6000,117.0500,20.0,1,1352090,0.0,0.0,4.0);
		break;
	case 1:
		m_geApplication.SetCameraParams(38.0900,92.0700,20.0,1,2279680,0.0,0.0,4.0);
		break;
	case 2:
		m_geApplication.SetCameraParams(27.6000,110.3000,20.0,1,1873930,0.0,0.0,4.0);
		break;
	case 3:
		m_geApplication.SetCameraParams(43.7500,117.0200,20.0,1,1968600,0.0,0.0,4.0);
		break;
	default:
		break;
	}

	//獲取IApplicationGE類的ISearchControllerGE屬性
	searchControl=m_geApplication.GetSearchController();
	searchControl.Search(strSearch);			//執行搜索操作
}

void CSample12Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();	
}

void CSample12Dlg::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	int i;
	UpdateData(TRUE);				//更新列表框
	//將視圖中心移動到對應的位置
	if(count>0)
	{
		for(i=0;i<count;i++)
		{
			if(m_results==feature[i].GetName())
			{
				if(TRUE==feature[i].GetHasView())
				{
					m_geApplication.SetFeatureView(feature[i],4.5);
				}
				else
				{
					AfxMessageBox("該位置沒有視圖！");
				}
			}
		}
	}
}

void CSample12Dlg::OnShow() 
{
	// TODO: Add your control notification handler code here
	int i;
	//避免非法操作
	if(searchControl==NULL)
	{
		AfxMessageBox("你未進行任何搜索！");
		return;
	}

	collect=searchControl.GetResults();			//獲取搜索結果集合

	count=collect.GetCount();
	//設置列表框的顯示範圍
	if(count>0 && count<10)
	{
		for(i=0;i<count;i++)
		{
			feature[i]=collect.GetItem(i+1);	//獲取結果集合中的要素
			UpdateData(TRUE);
			//將搜索結果逐條添加到列表框中
			((CListBox*)GetDlgItem(IDC_LIST1))->AddString(feature[i].GetName());
		}
	}
	else
	{
		if(0==count)
		{
			AfxMessageBox("沒有搜索到任何結果！");
		}
		else
		{
			AfxMessageBox("內容太多，列表框無法顯示，請刪除部分結果！");
		}
	}
}

void CSample12Dlg::OnShow2() 
{
	// TODO: Add your control notification handler code here
	int i;
	//避免非法操作
	if(searchControl==NULL)
	{
		AfxMessageBox("你未進行任何搜索！");
		return;
	}

	for(i=0;i<count;i++)
	{
		//逐條刪除列表框中的內容
		((CListBox*)GetDlgItem(IDC_LIST1))->DeleteString(i);
	}
	searchControl.ClearResults();				//清空結果集合中的內容
}
