// sample3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "sample3.h"
#include "sample3Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
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
// CSample3Dlg dialog

CSample3Dlg::CSample3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSample3Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSample3Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSample3Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSample3Dlg, CDialog)
	//{{AFX_MSG_MAP(CSample3Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_POSITION, OnPosition)
	ON_BN_CLICKED(IDC_MOVE, OnMove)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample3Dlg message handlers

BOOL CSample3Dlg::OnInitDialog()
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
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSample3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSample3Dlg::OnPaint() 
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
HCURSOR CSample3Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSample3Dlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	if(m_geApplication.IsInitialized())
	{
		m_geApplication.CreateDispatch(CLSID_ApplicationGE,NULL);
		if(!m_geApplication.IsOnline())
		{
			AfxMessageBox("已經連接上服務器！");
		}
	}	
}

void CSample3Dlg::OnPosition() 
{
	// TODO: Add your control notification handler code here
	//關閉定時器
	KillTimer(1);
	int lon1,lon2,lon3;
	int lat1,lat2,lat3;
	double dlon,dlat;
	int ilon,ilat;
	//定義常量GEPI，用於把經緯度轉換為小數形式
	const double GEPI=3600.0;
	char chlon1[10],chlon2[10],chlon3[10];
	char chlat1[10],chlat2[10],chlat3[10];
	//將文本編輯框中的數據傳遞給字符串變量
	GetDlgItem(IDC_EDIT1)->GetWindowText(chlon1,10);
	GetDlgItem(IDC_EDIT2)->GetWindowText(chlon2,10);
	GetDlgItem(IDC_EDIT3)->GetWindowText(chlon3,10);
	GetDlgItem(IDC_EDIT4)->GetWindowText(chlat1,10);
	GetDlgItem(IDC_EDIT5)->GetWindowText(chlat2,10);
	GetDlgItem(IDC_EDIT6)->GetWindowText(chlat3,10);
	//將字符串變量轉換為整數變量
	lon1=atoi(chlon1);
	lon2=atoi(chlon2);
	lon3=atoi(chlon3);
	lat1=atoi(chlat1);
	lat2=atoi(chlat2);
	lat3=atoi(chlat3);
	//對文本編輯框的輸入進行檢查
	if(abs(lon1)>179)
	{
		AfxMessageBox("“經度”非法輸入，請輸入-180和180之間的整數！");
	}
	if(abs(lat1)>89)
	{
		AfxMessageBox("“緯度”非法輸入，請輸入-90和90之間的整數！");
	}
	if(lon2>59 || lon2<0 || lat2>59 || lat2<0)
	{
		AfxMessageBox("“分”非法輸入，請輸入0和60之間的整數！");
	}
	if(lon3>59 || lon3<0 || lat3>59 || lat3<0)
	{
		AfxMessageBox("“秒”非法輸入，請輸入0和60之間的整數！");
	}
	//在輸入合法數據的前提下進行地圖定位操作
	if(abs(lon1)<=179 && abs(lat1)<=89 && lon2<=59 && lon2>=0 && lon3<=59 && lat2<=59
		&& lat2>=0 && lat3<=59 && lat3>=0)
	{
		//將經緯度的整數形式轉換為小數形式
		ilon=lon1*3600+lon2*60+lon3;
		dlon=ilon/GEPI;
		ilat=lat1*3600+lat2*60+lat3;
		dlat=ilat/GEPI;
		//調用SetCameraParams()函數
		m_geApplication.SetCameraParams(dlat,dlon,100.0,1,10000,0.0,0.0,2.0);
	}	
}

void CSample3Dlg::OnMove() 
{
	// TODO: Add your control notification handler code here
	//判斷用戶是否選擇平移方向
	m_direction=GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO4);
	if(m_direction>1006 || m_direction<1003)
	{
		AfxMessageBox("請選擇方向！");
		return;
	}
	//定義視口
	IViewExtentsGE m_geView;
	deltax=0;
	deltay=0;
	//獲取視口
	m_geView=m_geApplication.GetViewExtents();

	//獲取當前視圖的視高
	ICameraInfoGE m_geCamera;
	m_geCamera=m_geApplication.GetCamera(1);
	geRange=m_geCamera.GetRange();

	//獲取視口四條邊界的經緯度值
	geLeft=m_geView.GetWest();
	geRight=m_geView.GetEast();
	geTop=m_geView.GetNorth();
	geBottom=m_geView.GetSouth();
	//設置定時器的響應時間為0.1秒
	SetTimer(1,100,NULL);
}

void CSample3Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}

void CSample3Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//根據用戶選擇的方向移動當前視圖
	switch(m_direction)
	{
	case 1003:
		deltax+=0.001;
		xFocus=(geLeft+geRight)/2+deltax;
		yFocus=(geTop+geBottom)/2;
		break;
	case 1004:
		deltay+=0.001;
		xFocus=(geLeft+geRight)/2;
		yFocus=(geTop+geBottom)/2-deltay;
		break;
	case 1005:
		deltax+=0.001;
		xFocus=(geLeft+geRight)/2-deltax;
		yFocus=(geTop+geBottom)/2;
		break;
	case 1006:
		deltay+=0.001;
		xFocus=(geLeft+geRight)/2;
		yFocus=(geTop+geBottom)/2+deltay;
		break;
	}
	m_geApplication.SetCameraParams(yFocus,xFocus,100.0,1,geRange,0.0,0.0,1.5);
	CDialog::OnTimer(nIDEvent);
}
