// sample14Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "sample14.h"
#include "sample14Dlg.h"

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
// CSample14Dlg dialog

CSample14Dlg::CSample14Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSample14Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSample14Dlg)
	m_cycles = 1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample14Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSample14Dlg)
	DDX_Control(pDX, IDC_SLIDER1, m_speed);
	DDX_Text(pDX, IDC_EDIT1, m_cycles);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSample14Dlg, CDialog)
	//{{AFX_MSG_MAP(CSample14Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_SEARCHS, OnSearchs)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_CLEARRESULTS, OnClearresults)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample14Dlg message handlers

BOOL CSample14Dlg::OnInitDialog()
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
	isPlay=FALSE;
	isRemove=FALSE;
	strCount=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSample14Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSample14Dlg::OnPaint() 
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
HCURSOR CSample14Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSample14Dlg::OnStart() 
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

void CSample14Dlg::OnSearchs() 
{
	// TODO: Add your control notification handler code here
	CStdioFile file;
	CString* strSearch;					   //用來保存.txt文件中的字符串
	CString strTemp;
	CString pathName;					   //文件路徑名
	int i(0);
	int count(0);
	strTemp="";

	//設置打開文件對話框
	CFileDialog geOpenDlg(TRUE);
	geOpenDlg.m_ofn.lpstrTitle="請打開批量搜索的數據文件";
	geOpenDlg.m_ofn.lpstrFilter="TXT Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
    
	if(IDOK==geOpenDlg.DoModal())
	{
		pathName=geOpenDlg.GetPathName();
		file.Open(geOpenDlg.GetPathName(),CFile::modeRead);
	}	
	else
	{
		return;
	}

	//讀取文件的搜索字符串數目
	while(file.ReadString(strTemp))
	{
		count++;
	}
	file.Close();
	//重新打開文件，獲取搜索字符串
	file.Open(pathName,CFile::modeRead);
	strSearch=new CString[count];
	while(file.ReadString(strTemp))
	{
		//將搜索字符串保存在strSearch數組中
		strSearch[i]=strTemp;
		i++;
	}
	file.Close();

	//開始搜索
	m_geSearchControl.AttachDispatch(m_geApplication.GetSearchController(),TRUE);
	for(i=0;i<count;i++)
	{
		m_geSearchControl.Search(strSearch[i]);
	}

	i=0;
	IFeatureCollectionGE collect;
	strCount+=count;					   //獲取多個文件的搜索字符串之和
	while(i<strCount)
	{
		//獲取搜索結果的要素集合
		collect=m_geSearchControl.GetResults();
		i++;
	}

	m_geFeature=new IFeatureGE[strCount];
	//每次打開新的文件，清空以前的列表框內容
	((CListBox*)GetDlgItem(IDC_LIST1))->ResetContent();
	//將搜索結果集合中的要素名逐一添加到列表框中
	for(i=0;i<strCount;i++)
	{
		m_geFeature[i]=collect.GetItem(i+1);
		((CListBox*)GetDlgItem(IDC_LIST1))->AddString(m_geFeature[i].GetName());
	}

	strFlag=new CString[strCount];		   //用來記錄不需要顯示的要素
	for(i=0;i<strCount;i++)
	{
		strFlag[i]="";
	}
}

void CSample14Dlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	int i,j;
	//判斷是否有播放內容
	if(0==strCount)
	{
		return;
	}
	//獲取ITourControllerGE類
	m_geTour.AttachDispatch(m_geApplication.GetTourController(),TRUE);
	if(FALSE==isPlay)
	{
		for(i=0;i<strCount;i++)
		{
			//將結果集合中的所有內容初始化到播放內容中
			m_geFeature[i].SetVisibility(TRUE);
			for(j=0;j<strCount;j++)
			{
				//根據用戶選擇，移除不需要播放的要素
				if(0==strcmp(m_geFeature[i].GetName(),strFlag[j]))
				{
					m_geFeature[i].SetVisibility(FALSE);
				}
			}
		}
		m_speed.SetPos(10);				//初始化播放速度
		m_geFeature[0].Highlight();		//選中Search面板中第一個要素
		UpdateData(TRUE);
		//根據文本框內容，設置播放的循環次數
		m_geTour.SetCycles(m_cycles);
		//根據滑塊值，設置播放速度
		m_geTour.SetSpeed(m_speed.GetPos()*0.05);
		m_geTour.PlayOrPause();			//執行播放操作
		isPlay=TRUE;
	}
}

void CSample14Dlg::OnPause() 
{
	// TODO: Add your control notification handler code here
	//判斷是否有播放內容
	if(0==strCount)
	{
		return;
	}
	//在播放的過程中暫停
	if(TRUE==isPlay)
	{
		m_geTour.PlayOrPause();
		isPlay=FALSE;
	}
}

void CSample14Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}

void CSample14Dlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	int i;
	//判斷是否有播放內容
	if(0==strCount)
	{
		return;
	}
    //在播放的過程中停止
	if(TRUE==isPlay)
	{
		//將當前搜索結果集合中的所有要素都移出播放內容
		for(i=0;i<strCount;i++)
		{
			m_geFeature[i].SetVisibility(FALSE);
		}
		//將當前播放的內容重新定位到Search控制面板中
		if(FALSE==m_geFeature[0].GetHighlighted())
		{
			m_geFeature[0].Highlight();
		}
		m_geTour.Stop();					//停止當前的動態顯示
		isPlay=FALSE;
	}	
}

void CSample14Dlg::OnRemove() 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("請雙擊列表框中要移除的內容！");
	isRemove=TRUE;							//響應雙擊列表框的事件
}

void CSample14Dlg::OnClearresults() 
{
	// TODO: Add your control notification handler code here
	//判斷列表框是否為空
	if(0==strCount)
	{
		return;
	}
	//清空搜索結果集中的內容
	m_geSearchControl.ClearResults();
	//清空列表框中的內容
    ((CListBox*)GetDlgItem(IDC_LIST1))->ResetContent();
	strCount=0;
}

void CSample14Dlg::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	int item(0);
	int i;
	CString strItem="";
	if(TRUE==isRemove)
	{
		//獲取列表框中雙擊的內容
		item=((CListBox*)GetDlgItem(IDC_LIST1))->GetCurSel();
		((CListBox*)GetDlgItem(IDC_LIST1))->GetText(item,strItem);
		//根據雙擊的內容確定不顯示的要素
		for(i=0;i<strCount;i++)
		{
			if(0==strcmp(m_geFeature[i].GetName(),strItem))
			{
				strFlag[i]=strItem;
			}
		}
		//刪除列表框中對應的內容
		((CListBox*)GetDlgItem(IDC_LIST1))->DeleteString(item);
	}
	isRemove=FALSE;					//一次只能移除一條記錄
}
