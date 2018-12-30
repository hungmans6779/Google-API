// sample4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "sample4.h"
#include "sample4Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "COORDINATE.h"
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
// CSample4Dlg dialog

CSample4Dlg::CSample4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSample4Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSample4Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSample4Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSample4Dlg, CDialog)
	//{{AFX_MSG_MAP(CSample4Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COORD, OnCoord)
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_POSITION, OnPosition)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample4Dlg message handlers

BOOL CSample4Dlg::OnInitDialog()
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

void CSample4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSample4Dlg::OnPaint() 
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
HCURSOR CSample4Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSample4Dlg::OnCoord() 
{
	// TODO: Add your control notification handler code here
	//先檢查客戶端是否啟動
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}

	CCOORDINATE cordDlg;
	double x,y;
	if(IDOK==cordDlg.DoModal())
	{
		//檢查屏幕坐標對話框的輸入
		if(abs(cordDlg.m_x)>=100 || abs(cordDlg.m_y)>=100)
		{
			AfxMessageBox("請輸入絕對值小於100的整數！");
			return;
		}
		if((abs(cordDlg.m_x)<100 || cordDlg.m_x==0) && (abs(cordDlg.m_y) || cordDlg.m_y==0))
		{
			x=cordDlg.m_x/100.0;
			y=cordDlg.m_y/100.0;
		}
	}
	IPointOnTerrainGE gePoint;		//定義IPointOnTerrainGE類的對象
	//獲取用戶輸入的當前屏幕坐標
	gePoint=m_geApplication.GetPointOnTerrainFromScreenCoords(x,y);
	double dlon,dlat;
	dlon=gePoint.GetLongitude();	//獲取地理坐標的經度
	dlat=gePoint.GetLatitude();		//獲取地理坐標的緯度
	//將地理坐標轉換為度、分、秒的形式
	dlon=dlon*3600;
	dlat=dlat*3600;

	int islon,islat;
	islon=(int)dlon;
	islat=(int)dlat;

	geoLon1=islon/3600;
	islon=islon%3600;
	geoLon2=islon/60;
	geoLon3=islon%60;

	geoLat1=islat/3600;
	islat=islat%3600;
	geoLat2=islat/60;
	geoLat3=islat%60;

	geoElv=gePoint.GetAltitude();	//獲取地理坐標的海拔
	//顯示地理坐標信息
	char geoCLon1[10];
	itoa(geoLon1,geoCLon1,10);
	GetDlgItem(IDC_EDIT1)->SetWindowText(geoCLon1);
	char geoCLon2[10];
	itoa(geoLon2,geoCLon2,10);
	GetDlgItem(IDC_EDIT2)->SetWindowText(geoCLon2);
	char geoCLon3[10];
	itoa(geoLon3,geoCLon3,10);
	GetDlgItem(IDC_EDIT3)->SetWindowText(geoCLon3);

	char geoCLat1[10];
	itoa(geoLat1,geoCLat1,10);
	GetDlgItem(IDC_EDIT4)->SetWindowText(geoCLat1);
	char geoCLat2[10];
	itoa(geoLat2,geoCLat2,10);
	GetDlgItem(IDC_EDIT5)->SetWindowText(geoCLat2);
	char geoCLat3[10];
	itoa(geoLat3,geoCLat3,10);
	GetDlgItem(IDC_EDIT6)->SetWindowText(geoCLat3);

	BOOL m_pro,m_zero;
	CString strElv;
	//獲取地形點的投影信息
	m_pro=gePoint.GetProjectedOntoGlobe();
	//獲取地形點的海拔附加信息
	m_zero=gePoint.GetZeroElevationExaggeration();

	ICameraInfoGE m_camera;
	m_camera=m_geApplication.GetCamera(1);
	double range;
	range=m_camera.GetRange();	//獲取當前屏幕的視高

	if(TRUE==m_zero)
	{
		//地形點的海拔被設置為零海拔
		GetDlgItem(IDC_ELEVATION)->SetWindowText("該處海拔未知！");
	}
	else if(TRUE==m_pro)
	{
		//未考慮地球形狀
		strElv.Format("%.3fm （本海拔未考慮地球形狀）",geoElv);
		GetDlgItem(IDC_ELEVATION)->SetWindowText(strElv);
	}
	else
	{
		if(range<600000)
		{
			strElv.Format("%.3fm （本海拔考慮地球形狀）",geoElv);
			GetDlgItem(IDC_ELEVATION)->SetWindowText(strElv);
		}
		else
		{
			//當視高低於600km時，無法獲取到地形點的海拔信息
			AfxMessageBox("分辨率太低！");
		}
	}
}

void CSample4Dlg::OnStart() 
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
		if(!m_geApplication.IsOnline())
		{
			AfxMessageBox("已經連接上服務器！");
		}
	}	
}

void CSample4Dlg::OnPosition() 
{
	// TODO: Add your control notification handler code here
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}
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
	if(abs(lon2)>59 || abs(lat2)>59)
	{
		AfxMessageBox("“分”非法輸入，請輸入0和60之間的整數！");
	}
	if(abs(lon3)>59 || abs(lat3)>59)
	{
		AfxMessageBox("“秒”非法輸入，請輸入0和60之間的整數！");
	}
	//在輸入合法數據的前提下進行地圖定位操作
	if(abs(lon1)<=179 && abs(lat1)<=89 && abs(lon2)<=59 && abs(lon3)<=59 && abs(lat2)<=59 && abs(lat3)<=59)
	{
		//將經緯度的整數形式轉換為小數形式
		ilon=lon1*3600+lon2*60+lon3;
		dlon=ilon/GEPI;
		ilat=lat1*3600+lat2*60+lat3;
		dlat=ilat/GEPI;
		//調用SetCameraParams()函數
		m_geApplication.SetCameraParams(dlat,dlon,100.0,1,513,0.0,0.0,2.0);
	}
}

void CSample4Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();
}
