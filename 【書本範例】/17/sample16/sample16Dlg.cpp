// sample16Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "sample16.h"
#include "sample16Dlg.h"

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
// CSample16Dlg dialog

CSample16Dlg::CSample16Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSample16Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSample16Dlg)
	m_hour = 21;
	m_min = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample16Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSample16Dlg)
	DDX_Control(pDX, IDC_SLIDER1, m_time);
	DDX_Text(pDX, IDC_EDIT1, m_hour);
	DDX_Text(pDX, IDC_EDIT2, m_min);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSample16Dlg, CDialog)
	//{{AFX_MSG_MAP(CSample16Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_GO, OnGo)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_ANIMATION, OnAnimation)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample16Dlg message handlers

BOOL CSample16Dlg::OnInitDialog()
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
	isAnimate=FALSE;
	isPlay=FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSample16Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSample16Dlg::OnPaint() 
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
HCURSOR CSample16Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSample16Dlg::OnStart() 
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
	m_geApplication.OpenKmlFile("E:\\A-B.kml",1);	//打開路況文件
//	m_geApplication.OpenKmlFile("E:\\subway\\2-3.kml",1);
}

void CSample16Dlg::OnGo() 
{
	// TODO: Add your control notification handler code here
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}
    //防止誤操作
	if(FALSE==isAnimate)
	{
		AfxMessageBox("請先瀏覽當前路況！");
		return;
	}

	ITimeIntervalGE interval;
	ITimeGE time;
	BOOL isGo;
	int hour,min;
	isGo=FALSE;
    m_geAnimate.SetCurrentTimeInterval(startInterval);
    UpdateData(TRUE);
	m_geAnimate.Play();
    //控制文本框的輸入
	if(m_hour>23 || m_hour<0 || m_min>60 || m_min<0)
	{
		AfxMessageBox("出發時間輸入不正確！");
		return;
	}
	//如果當前時間於用戶輸入的出發時間相同，則暫停時間播放
	while(FALSE==isGo)
	{
		interval=m_geAnimate.GetCurrentTimeInterval();
		time=interval.GetBeginTime();
		hour=time.GetHour();
		min=time.GetMinute();
		m_time.SetPos(hour*100/23);			//設置滑塊位置
		if(hour==m_hour && (min-m_min)<=10 && (min-m_min)>=0)
		{
			isGo=TRUE;
			m_geAnimate.Pause();
		}
	}

	double double_time;
	double_time=(hour*60+min)/60.0;
	m_geTour.AttachDispatch(m_geApplication.GetTourController(),TRUE);
	//根據出發時間選擇可行的道路，並執行路徑播放
	if((double_time>=12.5 && double_time<=14.5) || (double_time>=17.5 && double_time<=19.0))
	{
		AfxMessageBox("高峰期，道路擁堵，無法到達B點！");
	}
	else if((double_time>=14.5 && double_time<=17.5) || (double_time>=11.5 && double_time<=12.5) || (double_time>=19.0 && double_time<=20.0))
	{
		AfxMessageBox("1號線擁堵，繞道行駛！");
		line2.Highlight();
		m_geTour.PlayOrPause();				//播放2#線
		isPlay=TRUE;
	}
	else
	{
		line1.Highlight();
		m_geTour.PlayOrPause();				//播放1#線
		isPlay=TRUE;
	}
}

void CSample16Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}

void CSample16Dlg::OnAnimation() 
{
	// TODO: Add your control notification handler code here
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}

	IFeatureCollectionGE collect1,collect2;
	IFeatureGE feature1,feature2,feature3;
	int hour,min;
	ITimeIntervalGE CurrentInterval1,CurrentInterval2;
	ITimeGE CurrentTime1,CurrentTime2;
	feature1=m_geApplication.GetTemporaryPlaces();
	collect1=feature1.GetChildren();
	feature2=collect1.GetItem(1);			//獲取到A-B.kml
	collect2=feature2.GetChildren();
	feature3=collect2.GetItem(18);			//獲取time要素
	line1=collect2.GetItem(19);				//獲取1#要素
	line2=collect2.GetItem(20);				//獲取2#要素
	if(FALSE==isAnimate)
	{
		isAnimate=TRUE;
	}
	//獲取IAnimationControllerGE對象
	m_geAnimate.AttachDispatch(m_geApplication.GetAnimationController(),TRUE);
	isExit=FALSE;
	//獲取播放過程中的瞬時時刻
	startInterval=feature3.GetTimeInterval();
	CurrentInterval1=m_geAnimate.GetCurrentTimeInterval();
	CurrentTime1=CurrentInterval1.GetBeginTime();
	hour=CurrentTime1.GetHour();			//獲取小時數
	min=CurrentTime1.GetMinute();			//獲取分鐘數
	//如果當前播放結束，將當前時刻重置為0時0分
	if(23==hour && 59==min)
	{
		m_geAnimate.SetCurrentTimeInterval(startInterval);
	}
	m_geAnimate.Play();						//開始動態播放
	while(FALSE==isExit)
	{
		CurrentInterval2=m_geAnimate.GetCurrentTimeInterval();
		CurrentTime2=CurrentInterval2.GetBeginTime();
		hour=CurrentTime2.GetHour();
		min=CurrentTime2.GetMinute();
		m_time.SetPos(hour*100/23);			//設置滑塊位置
		if(23==hour && 59==min)				//避免循環播放
		{
			isExit=TRUE;
			m_geAnimate.Pause();
		}
	}
	isExit=FALSE;
}

void CSample16Dlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}
    //防止誤操作
	if(FALSE==isPlay)
	{
		AfxMessageBox("請先出發！");
		return;
	}
	m_geTour.Stop();				//停止路徑播放
	IFeatureGE feature;
	//獲取要素A
	feature.AttachDispatch(m_geApplication.GetFeatureByName("A"),TRUE);
	//將視圖中心重新移動到A點
	m_geApplication.SetFeatureView(feature,4.5);
}
