// sample9Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "sample9.h"
#include "sample9Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "SEEING.h"
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
// CSample9Dlg dialog

CSample9Dlg::CSample9Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSample9Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSample9Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample9Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSample9Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSample9Dlg, CDialog)
	//{{AFX_MSG_MAP(CSample9Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_DYNAMIC, OnDynamic)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample9Dlg message handlers

BOOL CSample9Dlg::OnInitDialog()
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

void CSample9Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSample9Dlg::OnPaint() 
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
HCURSOR CSample9Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSample9Dlg::OnStart() 
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
	m_geApplication.OpenKmlFile("E:\\beijing4qu.kml",TRUE);	
}

void CSample9Dlg::OnDynamic() 
{
	// TODO: Add your control notification handler code here
	int i(0);
	BOOL isClick,isArea,isView;
	BOOL isSeeing1,isSeeing2,isSeeing3,isSeeing4;		//控制導航對話框的顯示
	isSeeing1=TRUE;
	isSeeing2=TRUE;
	isSeeing3=TRUE;
	isSeeing4=TRUE;
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}
	
	//定義導航對話框類
	CSEEING seeDlg;

	ICameraInfoGE camera;
	camera.AttachDispatch(m_geApplication.GetCamera(1),TRUE);
	camera.SetTilt(30.0);
	m_geApplication.SetCamera(camera,2.0);

	IFeatureGE tempFeature;
	IFeatureCollectionGE tempCollect;
	tempFeature.AttachDispatch(m_geApplication.GetTemporaryPlaces(),TRUE);
	tempCollect.AttachDispatch(tempFeature.GetChildren());

	IFeatureGE feature;
	IFeatureCollectionGE collect;
	feature.AttachDispatch(tempCollect.GetItem(1),TRUE);
	collect.AttachDispatch(feature.GetChildren(),TRUE);

	int childCount;
	childCount=collect.GetCount();

	IFeatureGE* childFeature;
	childFeature=new IFeatureGE[childCount];
	//將beijing4qu.kml下的路徑要素和圖片要素定義為一個要素數組
	for(i=0;i<childCount;i++)
	{
		childFeature[i]=collect.GetItem(i+1);
	}

	OLE_HANDLE hRenderWnd;
	hRenderWnd=m_geApplication.GetRenderHwnd();
	CWnd* pWnd=CWnd::FromHandle((HWND)hRenderWnd);

	//獲取視圖窗口區域
	CRect viewRect;
	pWnd->GetClientRect(&viewRect);
	pWnd->ClientToScreen(&viewRect);
	//計算視圖中心屏幕坐標
	double viewCenterx,viewCentery;
	viewCenterx=(viewRect.left+viewRect.right)/2.0;
	viewCentery=(viewRect.top+viewRect.bottom)/2.0;
	isClick=TRUE;
	isArea=TRUE;
	isView=TRUE;
	double currentx,currenty;		//定義鼠標位置的屏幕坐標

	CPoint currentPot;				//定義當前鼠標點
	IPointOnTerrainGE currentPos;	//定義鼠標當前位置
	double ge_currentx,ge_currenty;	//定義當前點的GE坐標
	while(isClick==TRUE || isArea==TRUE)
	{
		::GetCursorPos(&currentPot);//獲取鼠標的當前位置
		currentx=(currentPot.x-viewCenterx)/(viewRect.right-viewRect.left);
		currenty=(currentPot.y-viewCentery)/(viewRect.bottom-viewRect.top);

		//將屏幕坐標轉換為地理坐標
		currentPos=m_geApplication.GetPointOnTerrainFromScreenCoords(currentx,currenty);
		ge_currentx=currentPos.GetLongitude();
		ge_currenty=currentPos.GetLatitude();
		
		//根據鼠標的位置進行判斷
		if(ge_currenty<ItoD(39,58,38.74) && ge_currenty>ItoD(39,51,37.33) && ge_currentx<ItoD(116,26,29.85) && ge_currentx>ItoD(116,19,21.39))
		{
			//顯示西城區
			if(ge_currenty>ItoD(39,53,58.71) && ge_currentx<ItoD(116,22,6.79))
			{
				childFeature[0].SetVisibility(0);
				childFeature[1].SetVisibility(0);
				childFeature[2].SetVisibility(1);
				childFeature[3].SetVisibility(0);
				childFeature[4].SetVisibility(0);
				childFeature[5].SetVisibility(0);
				childFeature[6].SetVisibility(1);
				childFeature[7].SetVisibility(0);
				seeDlg.m_tip="你要去北海公園嗎？";
				if(camera.GetRange()<750)
				{
					if(TRUE==isSeeing3)
					{
						//顯示北海公園
						if(IDOK==seeDlg.DoModal())
						{							
							camera.SetFocusPointLatitude(ItoD(39,54,31.41));
							camera.SetFocusPointLongitude(ItoD(116,22,48.16));
							camera.SetRange(1220.0);
							m_geApplication.SetCamera(camera,2.0);
							isSeeing3=FALSE;
						}					
					}
				}
			}
			//顯示東城區和西城區
			if(ge_currenty>ItoD(39,53,58.71) && ge_currentx>ItoD(116,22,6.79) && ge_currentx<ItoD(116,23,37.74))
			{
				childFeature[0].SetVisibility(1);
				childFeature[1].SetVisibility(0);
				childFeature[2].SetVisibility(1);
				childFeature[3].SetVisibility(0);
				childFeature[4].SetVisibility(1);
				childFeature[5].SetVisibility(0);
				childFeature[6].SetVisibility(1);
				childFeature[7].SetVisibility(0);				
			}
			//顯示東城區
			if(ge_currenty>ItoD(39,53,58.71) && ge_currentx>ItoD(116,23,37.74))
			{
				childFeature[0].SetVisibility(1);
				childFeature[1].SetVisibility(0);
				childFeature[2].SetVisibility(0);
				childFeature[3].SetVisibility(0);
				childFeature[4].SetVisibility(1);
				childFeature[5].SetVisibility(0);
				childFeature[6].SetVisibility(0);
				childFeature[7].SetVisibility(0);
				seeDlg.m_tip="你要去天安門嗎？";
				if(camera.GetRange()<750)
				{
					if(TRUE==isSeeing1)
					{
						//顯示天安門
						if(IDOK==seeDlg.DoModal())
						{
							camera.SetFocusPointLatitude(ItoD(39,54,23.47));
							camera.SetFocusPointLongitude(ItoD(116,23,29.80));
							camera.SetRange(550.0);
							m_geApplication.SetCamera(camera,2.0);
							isSeeing1=FALSE;
						}
					}
				}
			}
			//顯示宣武區
			if(ge_currenty<ItoD(39,53,44.70) && ge_currentx>ItoD(116,20,24.70) && ge_currentx<ItoD(116,23,21.79))
			{
				childFeature[0].SetVisibility(0);
				childFeature[1].SetVisibility(0);
				childFeature[2].SetVisibility(0);
				childFeature[3].SetVisibility(1);
				childFeature[4].SetVisibility(0);
				childFeature[5].SetVisibility(0);
				childFeature[6].SetVisibility(0);
				childFeature[7].SetVisibility(1);
				seeDlg.m_tip="你要去陶然亭嗎？";
				if(camera.GetRange())
				{
					if(TRUE==isSeeing4)
					{
						//顯示陶然亭
						if(IDOK==seeDlg.DoModal())
						{
							camera.SetFocusPointLatitude(ItoD(39,52,21.73));
							camera.SetFocusPointLongitude(ItoD(116,22,37.94));
							camera.SetRange(756.0);
							m_geApplication.SetCamera(camera,2.0);
							isSeeing4=FALSE;
						}
					}
				}
			}
			//顯示崇文區和宣武區
			if(ge_currenty<ItoD(39,53,44.70) && ge_currentx>ItoD(116,23,21.79) && ge_currentx<ItoD(116,23,46.63))
			{
				childFeature[0].SetVisibility(0);
				childFeature[1].SetVisibility(1);
				childFeature[2].SetVisibility(0);
				childFeature[3].SetVisibility(1);
				childFeature[4].SetVisibility(0);
				childFeature[5].SetVisibility(1);
				childFeature[6].SetVisibility(0);
				childFeature[7].SetVisibility(1);
			}
			//顯示崇文區
			if(ge_currenty<ItoD(39,53,44.70) && ge_currentx>ItoD(116,23,46.63))
			{
				childFeature[0].SetVisibility(0);
				childFeature[1].SetVisibility(1);
				childFeature[2].SetVisibility(0);
				childFeature[3].SetVisibility(0);
				childFeature[4].SetVisibility(0);
				childFeature[5].SetVisibility(1);
				childFeature[6].SetVisibility(0);
				childFeature[7].SetVisibility(0);
				seeDlg.m_tip="你要去天壇嗎？";
				if(camera.GetRange())
				{
					if(TRUE==isSeeing2)
					{
						//顯示天壇
						if(IDOK==seeDlg.DoModal())
						{
							camera.SetFocusPointLatitude(ItoD(39,52,55.75));
							camera.SetFocusPointLongitude(ItoD(116,24,25.06));
							camera.SetRange(471.0);
							m_geApplication.SetCamera(camera,2.0);
							isSeeing2=FALSE;
						}
					}
				}
			}
			//顯示西城區和宣武區
			if(ge_currenty>ItoD(39,53,44.70) && ge_currenty<ItoD(39,53,58.71) && ge_currentx>ItoD(116,20,24.70) && ge_currentx<ItoD(116,22,22.31))
			{
				childFeature[0].SetVisibility(0);
				childFeature[1].SetVisibility(0);
				childFeature[2].SetVisibility(1);
				childFeature[3].SetVisibility(1);
				childFeature[4].SetVisibility(0);
				childFeature[5].SetVisibility(0);
				childFeature[6].SetVisibility(1);
				childFeature[7].SetVisibility(1);
			}
			//同時顯示四個區
			if(ge_currenty>ItoD(39,53,44.70) && ge_currenty<ItoD(39,53,58.71) && ge_currentx>ItoD(116,22,22.31) && ge_currentx<ItoD(116,23,47.94))
			{
				childFeature[0].SetVisibility(1);
				childFeature[1].SetVisibility(1);
				childFeature[2].SetVisibility(1);
				childFeature[3].SetVisibility(1);
				childFeature[4].SetVisibility(1);
				childFeature[5].SetVisibility(1);
				childFeature[6].SetVisibility(1);
				childFeature[7].SetVisibility(1);
			}
			//顯示東城區和崇文區
			if(ge_currenty>ItoD(39,53,44.70) && ge_currenty<ItoD(39,53,58.71) && ge_currentx<ItoD(116,25,57.36) && ge_currentx>ItoD(116,23,47.94))
			{
				childFeature[0].SetVisibility(1);
				childFeature[1].SetVisibility(1);
				childFeature[2].SetVisibility(0);
				childFeature[3].SetVisibility(0);
				childFeature[4].SetVisibility(1);
				childFeature[5].SetVisibility(1);
				childFeature[6].SetVisibility(0);
				childFeature[7].SetVisibility(0);
			}
			isClick=FALSE;
			isArea=TRUE;
		}
		else
		{
			isArea=FALSE;
		}

		//鼠標移動到視圖外，退出循環
		if(currentPot.x>viewRect.right || currentPot.x<viewRect.left || currentPot.y>viewRect.bottom || currentPot.y<viewRect.top)
		{
			isView=FALSE;
		}
	}
	AfxMessageBox("你已經出了範圍！");

}

void CSample9Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();	
}

double CSample9Dlg::ItoD(int x, int y, double z)
{
	double result;
	result=(y*60+z)/3600.0;
	result+=x;
	return result;
}
