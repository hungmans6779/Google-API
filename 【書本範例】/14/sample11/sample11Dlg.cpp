// sample11Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "sample11.h"
#include "sample11Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "LAYERSCONTROL.h"
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
// CSample11Dlg dialog

CSample11Dlg::CSample11Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSample11Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSample11Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample11Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSample11Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSample11Dlg, CDialog)
	//{{AFX_MSG_MAP(CSample11Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_LAYERS, OnLayers)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_VIEWINIT, OnViewinit)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample11Dlg message handlers

BOOL CSample11Dlg::OnInitDialog()
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

void CSample11Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSample11Dlg::OnPaint() 
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
HCURSOR CSample11Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSample11Dlg::OnStart() 
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

void CSample11Dlg::OnLayers() 
{
	// TODO: Add your control notification handler code here
	int i;
	CLAYERSCONTROL layersDlg;
	BOOL* boolLayer1=new BOOL[countSum];	//當前圖層設置
	BOOL* boolLayer2=new BOOL[countSum];	//用戶圖層設置
	//獲取當前的圖層設置
	for(i=0;i<countSum;i++)
	{
		boolLayer1[i]=m_geFeature[i].GetVisibility();
	}
	//初始化用戶設置
	for(i=0;i<countSum;i++)
	{
		boolLayer2[i]=FALSE;
	}
	//獲取用戶對圖層的選擇
	if(IDOK==layersDlg.DoModal())
	{
		boolLayer2[0]=layersDlg.m_terrain;
		boolLayer2[2]=layersDlg.m_web;
		boolLayer2[3]=layersDlg.m_content;
		boolLayer2[4]=layersDlg.m_awareness;
		boolLayer2[5]=layersDlg.m_roads;
		boolLayer2[7]=layersDlg.m_borders;
		boolLayer2[8]=layersDlg.m_citys;
		boolLayer2[12]=layersDlg.m_community;
		boolLayer2[14]=layersDlg.m_transportation;
		boolLayer2[15]=layersDlg.m_nature;
	}
	
	//根據用戶的選擇重新設置圖層
	for(i=0;i<countSum;i++)
	{
		if(boolLayer1[i]!=boolLayer2[i])
		{
			if(TRUE==boolLayer2[i])
			{
				m_geFeature[i].SetVisibility(TRUE);
			}
			else
			{
				m_geFeature[i].SetVisibility(FALSE);
			}
		}
	}
	//釋放數組
	delete [] boolLayer1;
	delete [] boolLayer2;
}

void CSample11Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();	
}

void CSample11Dlg::OnViewinit() 
{
	// TODO: Add your control notification handler code here
	IFeatureGE feature;
	IFeatureCollectionGE collect;
	int i;

	timeControl=0;						//控制OnTimer()函數
	//獲取Goolge Earth的圖層數據集
	m_geCollect=m_geApplication.GetLayersDatabases();
	feature=m_geCollect.GetItem(1);
	collect=feature.GetChildren();
	countSum=collect.GetCount();

	m_geFeature=new IFeatureGE[countSum];
	m_geFeature[0]=collect.GetItem(1);	//獲取Terrain圖層
	m_geFeature[0].SetVisibility(TRUE);	//設置Terrain圖層可見

	//設置其它圖層不可見
	for(i=1;i<countSum;i++)
	{
		m_geFeature[i]=collect.GetItem(i+1);
		if(TRUE==m_geFeature[i].GetVisibility())
		{
			m_geFeature[i].SetVisibility(FALSE);
		}
	}

	SetTimer(1,2000,NULL);				//啟動定時器
}

void CSample11Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	timeControl++;
	switch(timeControl)
	{
	case 1:
		//顯示國家邊界
		m_geApplication.SetCameraParams(31.5233,108.9261,50.0,1,7098550,0.0,0.0,1.5);
		m_geFeature[7].SetVisibility(TRUE);
		break;
	case 2:
		//顯示省和市
		m_geApplication.SetCameraParams(31.5233,108.9261,50.0,1,2254490,0.0,0.0,0.05);
		m_geFeature[8].SetVisibility(TRUE);
		break;
	case 3:
		//顯示交通設施
		m_geApplication.SetCameraParams(39.2267,117.4622,50.0,1,838950,0.0,0.0,0.5);
		m_geFeature[14].SetVisibility(TRUE);
		break;
	case 4:
		//延緩交通設施的顯示時間
		m_geApplication.SetCameraParams(39.2267,117.4622,50.0,1,838000,0.0,0.0,0.05);
		break;
	case 5:
		//顯示湖泊等自然地物
		m_geApplication.SetCameraParams(30.2764,114.1250,50.0,1,166860,0.0,0.0,0.05);
		m_geFeature[15].SetVisibility(TRUE);
		m_geFeature[14].SetVisibility(FALSE);
		break;
	case 6:
		KillTimer(1);					//關閉定時器
		break;
	default:
		break;
	}
	CDialog::OnTimer(nIDEvent);
}
