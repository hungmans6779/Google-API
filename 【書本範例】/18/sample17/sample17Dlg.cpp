// sample17Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "sample17.h"
#include "sample17Dlg.h"

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
// CSample17Dlg dialog

CSample17Dlg::CSample17Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSample17Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSample17Dlg)
	m_startName = _T("");
	m_endName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample17Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSample17Dlg)
	DDX_Text(pDX, IDC_EDIT1, m_startName);
	DDX_Text(pDX, IDC_EDIT2, m_endName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSample17Dlg, CDialog)
	//{{AFX_MSG_MAP(CSample17Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_QUERY1, OnQuery1)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_INITIALIZE, OnInitialize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample17Dlg message handlers

BOOL CSample17Dlg::OnInitDialog()
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

void CSample17Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSample17Dlg::OnPaint() 
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
HCURSOR CSample17Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSample17Dlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	if(TRUE==m_active)
	{
		AfxMessageBox("め狠竒币笆");
		return;
	}
	m_active=TRUE;
	if(m_geApplication.IsInitialized())
	{
		m_geApplication.CreateDispatch(CLSID_ApplicationGE,NULL);
	}
}

void CSample17Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//蹦ノWindowsㄧ计闽超Google Earthめ狠
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();	
}

void CSample17Dlg::OnQuery1() 
{
	// TODO: Add your control notification handler code here
	//耞め狠琌币笆
	if(FALSE==m_active)
	{
		AfxMessageBox("め狠ゼ币笆");
		return;
	}
    //弄language.txtゅンいず甧temp_languageAllい
	UpdateData(TRUE);
	CFile languageFile("E:\\subway\\language.txt",CFile::modeRead);
	DWORD languageLen;
	char* languageAll;
	languageLen=languageFile.GetLength();
	languageAll=new char[languageLen];
	languageAll[languageLen]=0;
	languageFile.Read(languageAll,languageLen);
	temp_languageAll=languageAll;
	languageFile.Close();
    //弄GElinepart.txtゅンいず甧temp_linepartAllい
	CFile linepartFile("E:\\subway\\GElinepart.txt",CFile::modeRead);
	DWORD linepartLen;
	char* linepartAll;
	linepartLen=linepartFile.GetLength();
	linepartAll=new char[linepartLen];
	linepartAll[linepartLen]=0;
	linepartFile.Read(linepartAll,linepartLen);
	temp_linepartAll=linepartAll;
	linepartFile.Close();
    //弄intersection.txtゅンいず甧temp_intersectionAllい
	CFile intersectionFile("E:\\subway\\intersection.txt",CFile::modeRead);
	DWORD intersectionLen;
	char* intersectionAll;
	intersectionLen=intersectionFile.GetLength();
	intersectionAll=new char[intersectionLen];
	intersectionAll[intersectionLen]=0;
	intersectionFile.Read(intersectionAll,intersectionLen);
	temp_intersectionAll=intersectionAll;
	intersectionFile.Close();
    //弄linerelation.txtゅンいず甧temp_linerelationAllい
	CFile linerelationFile("E:\\subway\\linerelation.txt",CFile::modeRead);
	DWORD linerelationLen;
	char* linerelationAll;
	linerelationLen=linerelationFile.GetLength();
	linerelationAll=new char[linerelationLen];
	linerelationAll[linerelationLen]=0;
	linerelationFile.Read(linerelationAll,linerelationLen);
	temp_linerelationAll=linerelationAll;
	linerelationFile.Close();

	//盢ノめ块簙Α锣传莱Α
	int languagePos1,languagePos2,languagePos3,languagePos4;
	CString startTemp1,startTemp2,endTemp1,endTemp2;
	CString startEName,endEName;
	startTemp1.Format("<%s>",m_startName);
	startTemp2.Format("</%s>",m_startName);
	endTemp1.Format("<%s>",m_endName);
	endTemp2.Format("</%s>",m_endName);
	languagePos1=temp_languageAll.Find(startTemp1);
	languagePos2=temp_languageAll.Find(startTemp2);
	languagePos3=temp_languageAll.Find(endTemp1);
	languagePos4=temp_languageAll.Find(endTemp2);
	startEName=temp_languageAll.Mid(languagePos1+strlen(startTemp1),languagePos2-languagePos1-strlen(startTemp2)+1);
	endEName=temp_languageAll.Mid(languagePos3+strlen(endTemp1),languagePos4-languagePos3-strlen(endTemp2)+1);

	//琩高翴ゅンだㄢ贺薄猵ユ翴㎝獶ユ翴
	//temp_intersectionAllい琩т耞赣翴琌ユ翴
	int intersectionPos1,intersectionPos2;
	intersectionPos1=temp_intersectionAll.Find(startEName);
	intersectionPos2=temp_intersectionAll.Find(endEName);

	int startPos1,startPos2,endPos1,endPos2;
	int startlineNum,startStation,endlineNum,endStation;
	int startline1,startline2;							//癬翴┮絬隔
	int endline1,endline2;								//沧翴┮絬隔
	int option;
	int lineRelationPos1,lineRelationPos2;
	CString lineRelation;
	CString temp_startEName,temp_endEName;
	CString startNumName,endNumName;
	CString strlineRelation1,strlineRelation2;
	temp_startEName.Format("<%s>",startEName);
	temp_endEName.Format("</%s>",endEName);
	if(-1==intersectionPos1 && -1==intersectionPos2)	//癬翴㎝沧翴常ぃ琌ユ翴
	{
		option=1;
		//莉癬翴┮絬隔㎝
		startPos1=temp_linepartAll.Find(temp_startEName);
		startPos2=temp_linepartAll.Find("</",startPos1);
		startNumName=temp_linepartAll.Mid(startPos1+strlen(temp_startEName),startPos2-startPos1-strlen(temp_startEName));
		int breakStartNumName;
		breakStartNumName=startNumName.Find("-");
		startlineNum=atoi(startNumName.Left(breakStartNumName));
		startStation=atoi(startNumName.Right(strlen(startNumName)-breakStartNumName-1));
		//莉沧翴┮絬隔㎝
		endPos1=temp_linepartAll.Find(temp_endEName);
		endPos2=temp_linepartAll.Find(">",endPos1-6);
		endNumName=temp_linepartAll.Mid(endPos2+1,endPos1-endPos2-1);
		int breakEndNumName;
		breakEndNumName=endNumName.Find("-");
		endlineNum=atoi(endNumName.Left(breakEndNumName));
		endStation=atoi(endNumName.Right(strlen(endNumName)-breakEndNumName-1));
		CString str;
		str.Format("%d %d",startlineNum,endlineNum);
	}
	else if(-1==intersectionPos1 && -1!=intersectionPos2)	//沧翴琌ユ翴
	{
		option=2;
		//莉癬翴┮絬隔㎝
		startPos1=temp_linepartAll.Find(temp_startEName);
		startPos2=temp_linepartAll.Find("</",startPos1);
		startNumName=temp_linepartAll.Mid(startPos1+strlen(temp_startEName),startPos2-startPos1-strlen(temp_startEName));
		int breakStartNumName;
		breakStartNumName=startNumName.Find("-");
		startlineNum=atoi(startNumName.Left(breakStartNumName));
		startStation=atoi(startNumName.Right(strlen(startNumName)-breakStartNumName-1));

		//莉沧翴獺
		int endPos1,endPos2;
		CString strendPos1,strendPos2;
		CString endlines;
		int end_douhao;
		strendPos1.Format("<%s>",endEName);
		strendPos2.Format("</%s>",endEName);
		endPos1=temp_intersectionAll.Find(strendPos1);
		endPos2=temp_intersectionAll.Find(strendPos2);
		endlines=temp_intersectionAll.Mid(endPos1+strlen(strendPos1),endPos2-endPos1-strlen(strendPos1));
		end_douhao=endlines.Find(",");
		endline1=atoi(endlines.Left(end_douhao));
		endline2=atoi(endlines.Right(strlen(endlines)-end_douhao-1));
	}
	else if(-1==intersectionPos2 && -1!=intersectionPos1)	//癬翴琌ユ翴
	{
		option=3;
		//莉癬翴獺
		int startPos1,startPos2;
		CString strStartPos1,strStartPos2;
		CString startlines;
		int start_douhao;
		strStartPos1.Format("<%s>",startEName);
		strStartPos2.Format("</%s>",startEName);
		startPos1=temp_intersectionAll.Find(strStartPos1);
		startPos2=temp_intersectionAll.Find(strStartPos2);
		startlines=temp_intersectionAll.Mid(startPos1+strlen(strStartPos1),startPos2-startPos1-strlen(strStartPos1));
		start_douhao=startlines.Find(",");
		startline1=atoi(startlines.Left(start_douhao));
		startline2=atoi(startlines.Right(strlen(startlines)-start_douhao-1));

		//莉沧翴┮絬隔㎝
		endPos1=temp_linepartAll.Find(temp_endEName);
		endPos2=temp_linepartAll.Find(">",endPos1-6);
		endNumName=temp_linepartAll.Mid(endPos2+1,endPos1-endPos2-1);
		int breakEndNumName;
		breakEndNumName=endNumName.Find("-");
		endlineNum=atoi(endNumName.Left(breakEndNumName));
		endStation=atoi(endNumName.Right(strlen(endNumName)-breakEndNumName-1));
	}
	else													//癬翴㎝沧翴常琌ユ翴
	{
		option=4;
		//莉癬翴獺
		int startPos1,startPos2;
		CString strStartPos1,strStartPos2;
		CString startlines;
		int start_douhao;
		strStartPos1.Format("<%s>",startEName);
		strStartPos2.Format("</%s>",startEName);
		startPos1=temp_intersectionAll.Find(strStartPos1);
		startPos2=temp_intersectionAll.Find(strStartPos2);
		startlines=temp_intersectionAll.Mid(startPos1+strlen(strStartPos1),startPos2-startPos1-strlen(strStartPos1));
		start_douhao=startlines.Find(",");
		startline1=atoi(startlines.Left(start_douhao));
		startline2=atoi(startlines.Right(strlen(startlines)-start_douhao-1));
		//莉沧翴獺
		int endPos1,endPos2;
		CString strendPos1,strendPos2;
		CString endlines;
		int end_douhao;
		strendPos1.Format("<%s>",endEName);
		strendPos2.Format("</%s>",endEName);
		endPos1=temp_intersectionAll.Find(strendPos1);
		endPos2=temp_intersectionAll.Find(strendPos2);
		endlines=temp_intersectionAll.Mid(endPos1+strlen(strendPos1),endPos2-endPos1-strlen(strendPos1));
		end_douhao=endlines.Find(",");
		endline1=atoi(endlines.Left(end_douhao));
		endline2=atoi(endlines.Right(strlen(endlines)-end_douhao-1));
	}

	//絋﹚杆更絬ゅン
	int i;
	CString addlineTemp;
	addline="";
	switch(option)
	{
	case 1:
		if(startlineNum==endlineNum)
		{
			//笷
			if(2==startlineNum)				//2腹絬ㄢ贺よ
			{
				solution=2;
				addlineN=new CString[solution];
				if(endStation>startStation)
				{
					for(i=startStation;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[0]+=addlineTemp;
					}
					for(i=startStation-1;i>0;i--)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[1]+=addlineTemp;
					}
					for(i=18;i>endStation;i--)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[1]+=addlineTemp;
					}
				}
				else
				{
					for(i=startStation;i>=endStation;i--)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[0]+=addlineTemp;
					}
					for(i=startStation+1;i<=18;i++)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[1]+=addlineTemp;
					}
					for(i=1;i<endStation;i++)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[1]+=addlineTemp;
					}
				}
			}
			else							//獶2腹絬贺よ
			{
				solution=1;
				if(startStation>endStation)
				{
					for(i=endStation;i<=startStation;i++)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addline+=addlineTemp;
					}
				}
				else
				{
					for(i=startStation;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
		}
		else
		{
			strlineRelation1.Format("<%d,%d>",startlineNum,endlineNum);
			strlineRelation2.Format("</%d,%d>",startlineNum,endlineNum);
			lineRelationPos1=temp_linerelationAll.Find(strlineRelation1);
			lineRelationPos2=temp_linerelationAll.Find(strlineRelation2);
			lineRelation=temp_linerelationAll.Mid(lineRelationPos1+strlen(strlineRelation1),lineRelationPos2-lineRelationPos1-strlen(strlineRelation1));
			if(-1==lineRelation.Find(","))
			{
				if("0"==lineRelation)
				{
					//传Ω
					int* twoLines=new int[10];
					twoLines=GetLine2(startlineNum,endlineNum);
					switch(twoLines[0]+twoLines[1])
					{
					case 2:						//1腹絬㎝8腹絬
						solution=2;
						addlineN=new CString[solution];
						if(1==startlineNum)		//1腹絬传8腹絬
						{
							//硄筁ユ翴1
							for(i=startStation;i<=twoLines[2];i++)
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[0]+=addlineTemp;
							}
							for(i=twoLines[4];i<=endStation;i++)
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[0]+=addlineTemp; 
							}
							//硄筁ユ翴2
							for(i=startStation;i<=twoLines[6];i++)
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines[8];i<=endStation;i++)
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[1]+=addlineTemp; 
							}
						}
						else					//8腹絬传1腹絬
						{
							//硄筁ユ翴1
							for(i=startStation;i>=twoLines[2];i--)
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[0]+=addlineTemp;
							}
							for(i=twoLines[4];i>=endStation;i--)
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[0]+=addlineTemp;
							}
							//硄筁ユ翴2
							for(i=startStation;i>=twoLines[6];i--)
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines[8];i>=endStation;i--)
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[1]+=addlineTemp;
							}
						}
						break;
					case 3:									//13腹絬㎝2腹絬
						solution=4;
						addlineN=new CString[solution];
						if(13==startlineNum)				//13腹絬2腹絬
						{
							for(i=startStation-1;i>=twoLines[2];i--)	//13腹絬场だ
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[0]+=addlineTemp;
								addlineN[1]+=addlineTemp;
							}
							for(i=startStation;i<=twoLines[6];i++)
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[2]+=addlineTemp;
								addlineN[3]+=addlineTemp;
							}
							for(i=twoLines[4];i<=endStation;i++)		//2腹絬场だ
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[0]+=addlineTemp;
							}
							for(i=twoLines[5];i>endStation;i--)
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[1]+=addlineTemp;
							}
							if(endStation>=twoLines[9])					//沧翴狥籔﹁琿
							{
								for(i=twoLines[9];i<=endStation;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
								}
								for(i=twoLines[8];i>=1;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[3]+=addlineTemp;
								}
								for(i=18;i>endStation;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[3]+=addlineTemp;
								}

							}
							else										//沧翴2腹絬狥籔﹁玭琿
							{
								for(i=twoLines[8];i>endStation;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
								}
								for(i=twoLines[9];i<=18;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[3]+=addlineTemp;
								}
								for(i=1;i<=endStation;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[3]+=addlineTemp;
								}
							}
						}
						else								//2腹絬13腹絬
						{
							for(i=startStation;i<=18;i++)	//2腹絬场だ
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[0]+=addlineTemp;
							}
							for(i=startStation-1;i>=1;i--)
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[1]+=addlineTemp;
							}
							if(startStation>=twoLines[7])					//癬翴狥籔﹁琿
							{
								for(i=startStation-1;i>=twoLines[7];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
								}
								for(i=startStation;i<=18;i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[3]+=addlineTemp;
								}
								for(i=1;i<=twoLines[6];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[3]+=addlineTemp;
								}
							}
							else											//癬翴狥籔﹁玭琿
							{
								for(i=startStation;i<=twoLines[6];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
								}
								for(i=startStation-1;i>=1;i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[3]+=addlineTemp;
								}
								for(i=18;i>=twoLines[7];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[3]+=addlineTemp;
								}
							}
							for(i=twoLines[4];i<=endStation;i++)			//13腹絬场だ
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[0]+=addlineTemp;
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines[8];i>endStation;i--)
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[2]+=addlineTemp;
								addlineN[3]+=addlineTemp;
							}
						}
						break;
					case 4:									//1腹絬㎝2腹絬
						solution=4;
						addlineN=new CString[solution];
						if(1==startlineNum)					//1腹絬传2腹絬
						{
							if(startStation<=twoLines[2])	//癬翴確砍﹁
							{
								for(i=startStation;i<=twoLines[2];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation;i<=twoLines[6];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else if(startStation>twoLines[7])	//癬翴瓣狥
							{
								for(i=startStation-1;i>=twoLines[3];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation-1;i>=twoLines[7];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else			//癬翴確砍㎝瓣ぇ丁
							{
								for(i=startStation;i<=twoLines[6];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
								for(i=startStation-1;i>=twoLines[3];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
							}
							if(endStation<=twoLines[4])	//沧翴﹁㎝確砍ぇ丁
							{
								for(i=twoLines[4];i>endStation;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
								}
								for(i=twoLines[5];i<=18;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines[9];i<=18;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
								}
								for(i=twoLines[8];i>endStation;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[3]+=addlineTemp; 
								}
								for(i=1;i<=endStation;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[1]+=addlineTemp;
									addlineN[2]+=addlineTemp;
								}
							}
							else if(endStation<=twoLines[8])	//沧翴確砍籔瓣玭琿
							{
								for(i=twoLines[5];i<=endStation;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp; 
								}
								for(i=twoLines[4];i>=1;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[1]+=addlineTemp; 
								}
								for(i=18;i>endStation;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[1]+=addlineTemp; 
								}
								for(i=twoLines[8];i>endStation;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
								}
								for(i=twoLines[9];i<=18;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[3]+=addlineTemp;
								}
								for(i=1;i<=endStation;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[3]+=addlineTemp;
								}
							}
							else			//沧翴﹁籔瓣琿
							{
								for(i=twoLines[5];i<=endStation;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
								}
								for(i=twoLines[4];i>=1;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines[9];i<=endStation;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
								}
								for(i=twoLines[8];i>=1;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[3]+=addlineTemp;
								}
								for(i=18;i>endStation;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[1]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
						}
						else									//2腹絬1腹絬
						{
							if(startStation<=twoLines[2])		//癬翴﹁㎝確砍ぇ丁
							{
								for(i=startStation;i<=twoLines[2];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
								}
								for(i=startStation-1;i>=1;i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[1]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
								for(i=18;i>=twoLines[3];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation;i<=twoLines[6];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
								}
								for(i=18;i>=twoLines[7];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[3]+=addlineTemp;
								}
							}
							else if(startStation<=twoLines[6])	//起点在复兴门与建国门南段
							{
								for(i=startStation-1;i>=twoLines[3];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
								}
								for(i=startStation;i<=18;i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[1]+=addlineTemp;
								}
								for(i=1;i<=twoLines[2];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation;i<=twoLines[6];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
								}
								for(i=startStation-1;i>=1;i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[3]+=addlineTemp;
								}
								for(i=18;i>=twoLines[7];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[3]+=addlineTemp;
								}
							}
							else								//起点在西直门与建国门北段
							{
								for(i=startStation-1;i>=twoLines[3];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
								}
								for(i=startStation;i<=18;i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[1]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
								for(i=1;i<=twoLines[2];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation-1;i>=twoLines[7];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
								}
								for(i=1;i<=twoLines[6];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[3]+=addlineTemp;
								}
							}
							if(endStation<=twoLines[4])		//终点在复兴门西
							{
								for(i=twoLines[4];i>endStation;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines[8];i>endStation;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else if(endStation>=twoLines[9])	//终点在建国门东面
							{
								for(i=twoLines[5];i<=endStation;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines[9];i<=endStation;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else								//终点在复兴门和建国门之间
							{
								for(i=twoLines[5];i<=endStation;i++)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines[8];i>endStation;i--)
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
						}
						break;
					default:
						break;
					}
				}
				else
				{
					//换乘二次
					int* twoLines1=new int[10];
					int* twoLines2=new int[10];
					twoLines1=GetLine2(startlineNum,atoi(lineRelation));
					twoLines2=GetLine2(atoi(lineRelation),endlineNum);
					if("1"==lineRelation)			//2、1、8
					{
						solution=4;
						addlineN=new CString[solution];
						if(2==startlineNum)			//2号线换乘1号线，再换乘8号线
						{
							if(startStation<=twoLines1[2])	//起点在西直门和复兴门段
							{
								for(i=startStation;i<=twoLines1[2];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation-1;i>=1;i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
								for(i=18;i>=twoLines1[7];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else if(startStation<=twoLines1[6])	//起点在复兴门和建国门南段
							{
								for(i=startStation-1;i>=twoLines1[3];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation;i<=twoLines1[6];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else							//起点在复兴门和建国门北段
							{
								for(i=startStation;i<=18;i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=1;i<=twoLines1[2];i++)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation-1;i>=twoLines1[7];i--)
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							for(i=twoLines1[5];i<=twoLines2[2];i++)	//1号线部分（复兴门到四惠）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[0]+=addlineTemp;
							}
							for(i=twoLines1[5];i<=twoLines2[6];i++)	//1号线部分（复兴门到四惠东）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines1[9];i<=twoLines2[2];i++)	//1号线部分（建国门到四惠）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[2]+=addlineTemp;
							}
							for(i=twoLines1[9];i<=twoLines2[6];i++)	//1号线部分（建国门到四惠东）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[3]+=addlineTemp;
							}
							for(i=twoLines2[4];i<=endStation;i++)	//8号线部分（四惠）
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[0]+=addlineTemp;
								addlineN[2]+=addlineTemp;
							}
							for(i=twoLines2[8];i<=endStation;i++)	//8号线部分（四惠东）
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[1]+=addlineTemp;
								addlineN[3]+=addlineTemp;
							}
						}
						else										//8号线换乘1号线，再换乘2号线
						{
							for(i=startStation-1;i>=twoLines1[6];i--)	//8号线部分（四惠）
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[0]+=addlineTemp;
								addlineN[2]+=addlineTemp;
							}
							for(i=startStation-1;i>=twoLines1[2];i--)	//8号线部分（四惠东）
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[1]+=addlineTemp;
								addlineN[3]+=addlineTemp;
							}
						}
					}
					else											//1、2、13
					{
						solution=4;
						addlineN=new CString[solution];
						if(1==startlineNum)							//1号线换乘2号线，再换乘13号线
						{
							if(startStation<=twoLines1[2])			//起点在1号线复兴门西面
							{
								for(i=startStation;i<=twoLines1[2];i++)	//1号线部分（复兴门）
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation;i<=twoLines1[6];i++)	//1号线部分（建国门）
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else if(startStation<=twoLines1[6])		//起点在1号线复兴门与建国门之间
							{
								for(i=startStation-1;i>=twoLines1[3];i--)//1号线部分（复兴门）
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation;i<=twoLines1[6];i++)	//1号线部分（建国门）
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else									//起点在1号线建国门东面
							{
								for(i=startStation-1;i>=twoLines1[3];i--)//1号线部分（复兴门）
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation-1;i>=twoLines1[7];i--)//1号线部分（建国门）
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							for(i=twoLines1[4];i>=twoLines2[4];i--)			//2号线部分（复兴门到西直门）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[0]+=addlineTemp;
							}
							for(i=twoLines1[5];i<=twoLines2[6];i++)			//2号线部分（复兴门到东直门）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines1[8];i>=twoLines2[4];i--)			//2号线部分（建国门到西直门）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[2]+=addlineTemp;
							}
							for(i=twoLines1[9];i<=twoLines2[6];i++)			//2号线部分（建国门到东直门）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[3]+=addlineTemp;
							}
							for(i=twoLines2[4];i<=endStation;i++)			//13号线部分（西直门）
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[0]+=addlineTemp;
								addlineN[2]+=addlineTemp;
							}
							for(i=twoLines2[8];i>endStation;i--)			//13号线部分（东直门）
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[1]+=addlineTemp;
								addlineN[3]+=addlineTemp;
							}
						}
						else										//13号线换乘2号线，再换乘1号线
						{
							for(i=startStation-1;i>=twoLines1[2];i--)	//13号线部分（西直门）
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[0]+=addlineTemp;
								addlineN[2]+=addlineTemp;
							}
							for(i=startStation;i<=twoLines1[6];i++)		//13号线部分（东直门）
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[1]+=addlineTemp;
								addlineN[3]+=addlineTemp;
							}
							for(i=twoLines1[9];i<=18;i++)				//2号线部分（东直门到复兴门）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines1[4];i<=twoLines2[2];i++)		//2号线部分（西直门到复兴门）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[0]+=addlineTemp;
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines1[5];i>=twoLines2[5];i--)		//2号线部分（西直门到建国门）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[2]+=addlineTemp;
							}
							for(i=twoLines1[8];i>=twoLines2[7];i--)		//2号线部分（东直门到建国门）
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[3]+=addlineTemp;
							}
							if(endStation<=twoLines2[4])				//终点在1号线复兴门西面
							{
								for(i=twoLines2[4];i>endStation;i--)	//复兴门出发
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines2[8];i>endStation;i--)	//建国门出发
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else if(endStation<=twoLines2[8])			//终点在1号线复兴门与建国门之间
							{
								for(i=twoLines2[5];i<=endStation;i++)	//复兴门出发
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines2[8];i>endStation;i--)	//建国门出发
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else										//终点在1号线建国门东面
							{
								for(i=twoLines2[5];i<=endStation;i++)	//复兴门出发
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines2[9];i<=endStation;i++)	//建国门出发
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
						}
					}
				}
			}
			else
			{
				//换乘三次8、1、2、13
				int lineRelation1,lineRelation2;
				int lineRelationTemp;
				int* twoLines1=new int[10];
				int* twoLines2=new int[10];
				int* twoLines3=new int[10];
				lineRelationTemp=lineRelation.Find(",");
				lineRelation1=atoi(lineRelation.Left(lineRelationTemp));
				lineRelation2=atoi(lineRelation.Right(strlen(lineRelation)-lineRelationTemp-1));
				twoLines1=GetLine2(startlineNum,lineRelation1);
				twoLines2=GetLine2(lineRelation1,lineRelation2);
				twoLines3=GetLine2(lineRelation2,endlineNum);
				solution=4;
				addlineN=new CString[solution];
				if(8==startlineNum)					//8号线换乘1号线，再换乘2号线，再换乘13号线
				{
					for(i=startStation-1;i>=twoLines1[6];i--)	//8号线部分（四惠）
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[0]+=addlineTemp;
						addlineN[2]+=addlineTemp;
					}
					for(i=startStation-1;i>=twoLines1[2];i--)	//8号线部分（四惠东）
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[1]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines1[8];i>=twoLines2[3];i--)		//1号线（四惠到复兴门）
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[0]+=addlineTemp;
					}
					for(i=twoLines1[4];i>=twoLines2[3];i--)		//1号线（四惠东到复兴门）
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[1]+=addlineTemp;
					}
					for(i=twoLines1[8];i>=twoLines2[7];i--)		//1号线（四惠到建国门）
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[2]+=addlineTemp;
					}
					for(i=twoLines1[4];i>=twoLines2[7];i--)		//1号线（四惠东到建国门）
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines2[4];i>=twoLines3[2];i--)		//2号线（复兴门到西直门）
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[0]+=addlineTemp;
						addlineN[1]+=addlineTemp;
					}
					for(i=twoLines2[9];i<=twoLines3[6];i++)		//2号线（建国门到东直门）
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[2]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines3[4];i<=endStation;i++)		//13号线（西直门）
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addlineN[0]+=addlineTemp;
						addlineN[1]+=addlineTemp;
					}
					for(i=twoLines3[8];i>endStation;i--)		//13号线（东直门）
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addlineN[2]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
				}
				else								//13号线换乘2号线，再换乘1号线，再换乘8号线
				{
					for(i=startStation-1;i>=twoLines1[2];i--)		//13号线（西直门）
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[0]+=addlineTemp;
						addlineN[1]+=addlineTemp;
					}
					for(i=startStation;i<=twoLines1[6];i++)			//13号线（东直门）
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[2]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines1[4];i<=twoLines2[2];i++)			//2号线（西直门到复兴门）
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[0]+=addlineTemp;
						addlineN[1]+=addlineTemp;
					}
					for(i=twoLines1[8];i>=twoLines2[7];i--)			//2号线（东直门到建国门）
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[2]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines2[5];i<=twoLines3[2];i++)			//1号线（复兴门到四惠）
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[0]+=addlineTemp;
					}
					for(i=twoLines2[5];i<=twoLines3[6];i++)			//1号线（复兴门到四惠东）
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[1]+=addlineTemp;
					}
					for(i=twoLines2[9];i<=twoLines3[2];i++)			//1号线（建国门到四惠）
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[2]+=addlineTemp;
					}
					for(i=twoLines2[9];i<=twoLines3[6];i++)			//1号线（建国门到四惠东）
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines3[4];i<=endStation;i++)			//8号线（四惠）
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addlineN[0]+=addlineTemp;
						addlineN[2]+=addlineTemp;
					}
					for(i=twoLines3[8];i<=endStation;i++)			//8号线（四惠东）
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addlineN[1]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
				}
			}
		}
		break;
	case 2:													//终点是交点
		solution=1;
		if(startlineNum==endline1 || startlineNum==endline2)//起点与终点在同一线路
		{
			if(1==startlineNum)								//起点与终点同在1号线
			{
				endlineNum=1;
				if("fuxingmen"==endEName)					//终点在复兴门
				{
					if(startStation<=10)
					{
						endStation=10;
					}
					else
					{
						endStation=11;
					}
				}
				else if("jianguomen"==endEName)				//终点在建国门
				{
					if(startStation<=16)
					{
						endStation=16;
					}
					else
					{
						endStation=17;
					}
				}
				else if("sihui"==endEName)					//终点在四惠
				{
					endStation=20;
				}
				else										//终点在四惠东
				{
					endStation=21;
				}
			}
			else if(2==startlineNum)						//起点与终点同在2号线
			{
				endlineNum=2;
				if("fuxingmen"==endEName)					//终点在复兴门
				{
					if(startStation<=3)
					{
						endStation=3;
					}
					else
					{
						endStation=4;
					}
				}
				else if("jianguomen"==endEName)				//终点在建国门
				{
					if(startStation<=10)
					{
						endStation=10;
					}
					else
					{
						endStation=11;
					}
				}
				else if("dongzhimen"==endEName)				//终点在东直门
				{
					if(startStation<=13)
					{
						endStation=13;
					}
					else
					{
						endStation=14;
					}
				}
				else										//终点在西直门
				{
					if(startStation<=10)
					{
						endStation=1;
					}
					else
					{
						endStation=18;
					}
				}
			}
			else if(8==startlineNum)						//起点与终点同在8号线
			{
				endlineNum=8;
				if("sihui"==endEName)						//终点在四惠
				{
					endStation=1;
				}
				else										//终点在四惠东
				{
					endStation=2;
				}
			}
			else											//起点与终点同在13号线
			{
				endlineNum=13;
				if("xizhimen"==endEName)					//终点在西直门
				{
					endStation=1;
				}
				else										//终点在东直门
				{
					endStation=15;
				}
			}
			if(startStation>endStation)
			{
				for(i=startStation-1;i>=endStation;i--)
				{
					addlineTemp.Format("%d-%d ",startlineNum,i);
					addline+=addlineTemp;
				}
			}
			else
			{
				for(i=startStation;i<=endStation;i++)
				{
					addlineTemp.Format("%d-%d ",startlineNum,i);
					addline+=addlineTemp;
				}
			}
		}
		else												//起点与终点不在同一线路
		{
			if("xizhimen"==endEName)						//终点为西直门
			{
				if(1==startlineNum)							//起点在1号线
				{
					if(startStation<=10)					//起点在1号线复兴门西侧
					{
						for(i=startStation;i<=10;i++)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
					}
					else									//起点在1号线复兴门东侧
					{
						for(i=startStation-1;i>=11;i--)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
				else										//起点在8号线
				{
					for(i=startStation-1;i>=1;i--)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addline+=addlineTemp;
					}
					for(i=20;i>=11;i--)
					{
						addlineTemp.Format("%d-%d ",1,i);
						addline+=addlineTemp;
					}
				}
				endlineNum=2;
				for(i=3;i>=1;i--)
				{
					addlineTemp.Format("%d-%d ",endlineNum,i);
					addline+=addlineTemp;
				}
			}
			else if("dongzhimen"==endEName)					//终点为东直门
			{
				if(1==startlineNum)							//起点在1号线
				{
					if(startStation<=16)					//起点在1号线建国门西侧
					{
						for(i=startStation;i<=16;i++)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
					}
					else									//起点在1号线建国门东侧
					{
						for(i=startStation-1;i>=17;i--)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
				else										//起点在8号线
				{
					for(i=startStation-1;i>=1;i--)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addline+=addlineTemp;
					}
					for(i=20;i>=17;i--)
					{
						addlineTemp.Format("%d-%d ",1,i);
						addline+=addlineTemp;
					}
				}
				endlineNum=2;
				for(i=11;i<=13;i++)
				{
					addlineTemp.Format("%d-%d ",endlineNum,i);
					addline+=addlineTemp;
				}
			}
			else if("fuxingmen"==endEName)					//终点为复兴门
			{
				endlineNum=2;
				for(i=startStation-1;i>=1;i--)
				{
					addlineTemp.Format("%d-%d ",startlineNum,i);
					addline+=addlineTemp;
				}
				if(8==startlineNum)							//起点在8号线
				{
					for(i=20;i>=11;i--)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
				else										//起点在13号线
				{
					for(i=1;i<=3;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
			else if("jianguomen"==endEName)					//终点为建国门
			{
				endlineNum=2;
				if(8==startlineNum)							//起点在8号线
				{
					for(i=startStation-1;i>=1;i--)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addline+=addlineTemp;
					}
					for(i=20;i>=17;i--)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
				else										//起点在13号线
				{
					for(i=startStation;i<=15;i++)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addline+=addlineTemp;
					}
					for(i=13;i>=11;i--)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
			else											//终点为四惠或四惠东
			{
				if(2==startlineNum)							//起点在2号线
				{
					if(startStation>=11)
					{
						for(i=startStation-1;i>=11;i--)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
					}
					else
					{
						for(i=startStation;i<=10;i++)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
				else										//起点在13号线
				{
					if(startStation<=8)
					{
						for(i=startStation-1;i>=1;i--)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
						for(i=18;i>=11;i--)
						{
							addlineTemp.Format("%d-%d ",2,i);
							addline+=addlineTemp;
						}
					}
					else
					{
						for(i=startStation;i<=15;i++)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
						for(i=13;i>=11;i--)
						{
							addlineTemp.Format("%d-%d ",2,i);
							addline+=addlineTemp;
						}
					}
				}
				endlineNum=1;
				if("sihui"==endEName)
				{
					endStation=20;
				}
				else
				{
					endStation=21;
				}
				for(i=17;i<=endStation;i++)
				{
					addlineTemp.Format("%d-%d ",endlineNum,i);
					addline+=addlineTemp;
				}
			}
		}
		break; 
	case 3:													//起点是交点
		if(endlineNum==startline1 || endlineNum==startline2)//起点与终点在同一线路
		{
			int* twoLines=new int[10];
			twoLines=GetLine2(startline1,startline2);		
			if(1==endlineNum)								//起点与终点同在1号线
			{
				startlineNum=1;
				solution=1;
				if("fuxingmen"==startEName)					//起点在复兴门
				{
					startStation=twoLines[2];
				}
				else if("jianguomen"==startEName)			//起点在建国门
				{
					startStation=twoLines[6];
				}
				else if("sihui"==startEName)				//起点在四惠
				{
					startStation=twoLines[2];
				}
				else										//起点在四惠东
				{
					startStation=twoLines[6];
				}
				if(endStation>=startStation)				//终点在起点东面
				{
					for(i=startStation+1;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
				else										//终点在起点西面
				{
					for(i=startStation;i>endStation;i--)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
			else if(2==endlineNum)							//起点与终点同在2号线
			{
				startlineNum=2;
				solution=2;
				addlineN=new CString[solution];
				if("xizhimen"==startEName)					//起点在西直门
				{
					for(i=1;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addlineN[0]+=addlineTemp;
					}
					for(i=18;i>endStation;i--)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addlineN[1]+=addlineTemp;
					}
				}
				else if("dongzhimen"==startEName)			//起点在东直门
				{
					if(endStation>=14 && endStation<=18)
					{
						for(i=14;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[0]+=addlineTemp;
						}
						for(i=13;i>=1;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[1]+=addlineTemp;
						}
						for(i=18;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[1]+=addlineTemp;
						}
					}
					else
					{
						for(i=14;i<=18;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[0]+=addlineTemp;
						}
						for(i=1;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[0]+=addlineTemp;
						}
						for(i=13;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[1]+=addlineTemp;
						}
					}
				}
				else if("jianguomen"==startEName)			//起点在建国门
				{
					if(endStation>=11 && endStation<=18)
					{
						for(i=11;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[0]+=addlineTemp;
						}
						for(i=10;i>=1;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[1]+=addlineTemp;
						}
						for(i=18;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[1]+=addlineTemp;
						}
					}
					else
					{
						for(i=11;i<=18;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[0]+=addlineTemp;
						}
						for(i=1;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[0]+=addlineTemp;
						}
						for(i=10;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[1]+=addlineTemp;
						}
					}
				}
				else										//起点在复兴门
				{
					if(endStation>=4 && endStation<=18)
					{
						for(i=4;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[0]+=addlineTemp;
						}
						for(i=3;i>=1;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[1]+=addlineTemp;
						}
						for(i=18;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[1]+=addlineTemp;
						}
					}
					else
					{
						for(i=4;i<=18;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[0]+=addlineTemp;
						}
						for(i=1;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[0]+=addlineTemp;
						}
						for(i=3;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addlineN[1]+=addlineTemp;
						}
					}
				}
			}
			else if(8==endlineNum)							//起点与终点同在8号线
			{
				startlineNum=8;
				solution=1;
				int* twoLines=new int[10];
				twoLines=GetLine2(startline1,startline2);
				if("sihui"==startEName)						//起点在四惠
				{
					startStation=twoLines[4];
				}
				else										//起点在四惠东
				{
					startStation=twoLines[8];
				}
				for(i=startStation;i<=endStation;i++)
				{
					addlineTemp.Format("%d-%d ",endlineNum,i);
					addline+=addlineTemp;
				}
			}
			else											//起点与终点同在13号线
			{
				startlineNum=13;
				solution=1;
				if("xizhimen"==startEName)					//起点在西直门
				{
					startStation=1;
					for(i=startStation;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
				else										//起点在东直门
				{
					startStation=15;
					for(i=startStation;i>endStation;i--)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
		}
		else												//起点与终点不在同一线路
		{
			if("xizhimen"==startEName)				//起点为西直门
			{
				startlineNum=2;
				solution=1;
				startStation=1;
				for(i=startStation;i<=3;i++)
				{
					addlineTemp.Format("%d-%d ",startlineNum,i);
					addline+=addlineTemp;
				}
				if(1==endlineNum)					//终点在1号线
				{
					if(endStation<=10)				//1号线复兴门西段
					{
						for(i=10;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
					else							//1号线复兴门东段
					{
						for(i=11;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
				else								//终点在8号线
				{
					for(i=11;i<=20;i++)
					{
						addlineTemp.Format("%d-%d ",1,i);
						addline+=addlineTemp;
					}
					for(i=1;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
			else if("dongzhimen"==startEName)		//起点为东直门
			{
				startlineNum=2;
				solution=1;
				startStation=13;
				for(i=startStation;i>=11;i--)
				{
					addlineTemp.Format("%d-%d ",startlineNum,i);
					addline+=addlineTemp;
				}
				if(1==endlineNum)					//终点在1号线
				{
					if(endStation<=16)				//终点在建国门西侧
					{
						for(i=16;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
					else							//终点在建国门东侧
					{
						for(i=17;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
				else								//终点在8号线
				{
					for(i=17;i<=20;i++)
					{
						addlineTemp.Format("%d-%d ",1,i);
						addline+=addlineTemp;
					}
					for(i=1;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
			else if("fuxingmen"==startEName)		//起点为复兴门
			{
				if(8==endlineNum)					//终点在8号线
				{
					startlineNum=1;
					solution=1;
					startStation=11;
					for(i=startStation;i<=20;i++)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addline+=addlineTemp;
					}
					for(i=1;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
				else								//终点在13号线
				{
					startlineNum=2;
					solution=1;
					startStation=3;
					for(i=startStation;i>=1;i--)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addline+=addlineTemp;
					}
					for(i=1;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
			else if("jianguomen"==startEName)		//起点为建国门
			{
				if(8==endlineNum)					//终点在8号线
				{
					startlineNum=1;
					solution=1;
					startStation=17;
					for(i=startStation;i<=20;i++)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addline+=addlineTemp;
					}
					for(i=1;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
				else								//终点在13号线
				{
					startlineNum=2;
					solution=1;
					startStation=11;
					for(i=startStation;i<=13;i++)
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addline+=addlineTemp;
					}
					for(i=15;i>endStation;i--)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
			else			//起点为四惠或四惠东
			{
				startlineNum=1;
				solution=1;
				if("sihui"==startEName)				//四惠
				{
					startStation=20;
				}
				else								//四惠东
				{
					startStation=21;
				}
				for(i=startStation;i>=17;i--)
				{
					addlineTemp.Format("%d-%d ",startlineNum,i);
					addline+=addlineTemp;
				}
				if(2==endlineNum)					//终点在2号线
				{
					if(endStation<=10)
					{
						for(i=10;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
					else
					{
						for(i=11;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
				else								//终点在13号线
				{
					if(endStation<=8)
					{
						for(i=10;i>=1;i--)
						{
							addlineTemp.Format("%d-%d ",2,i);
							addline+=addlineTemp;
						}
						for(i=1;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
					else
					{
						for(i=11;i<=13;i++)
						{
							addlineTemp.Format("%d-%d ",2,i);
							addline+=addlineTemp;
						}
						for(i=15;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
			}
		}
		break;
	case 4:
		solution=1;
		int startStation1,startStation2,endStation1,endStation2;
		if("xizhimen"==startEName)
		{
			startStation1=18;
			startStation2=1;			
		}
		if("xizhimen"==endEName)
		{
			endStation1=18;
			endStation2=1;
		}
		if("dongzhimen"==startEName)
		{
			startStation1=13;
			startStation2=14;			
		}
		if("dongzhimen"==endEName)
		{
			endStation1=13;
			endStation2=14;
		}
		if("fuxingmen"==startEName)
		{
			startStation1=3;
			startStation2=4;			
		}
		if("fuxingmen"==endEName)
		{
			endStation1=3;
			endStation2=4;
		}
		if("jianguomen"==startEName)
		{
			startStation1=10;
			startStation2=11;			
		}
		if("jianguomen"==endEName)
		{
			endStation1=10;
			endStation2=11;
		}
		if("sihui"==startEName)
		{
			startStation1=20;
			startStation2=21;			
		}
		if("sihui"==endEName)
		{
			endStation1=20;
			endStation2=21;
		}
		if("sihuidong"==startEName)
		{
			startStation1=21;
			startStation2=0;			
		}
		if("sihuidong"==endEName)
		{
			endStation1=21;
			endStation2=0;
		}
		//起点和终点同在2号线
		if((2==startline1 || 2==startline2) && (2==endline1 || 2==endline2))
		{
			startlineNum=2;
			endlineNum=2;
			if(startStation2<=endStation1)
			{
				for(i=startStation2;i<=endStation1;i++)
				{
					addlineTemp.Format("%d-%d ",2,i);
					addline+=addlineTemp;
				}
			}
			else
			{
				for(i=startStation1;i>=endStation2;i--)
				{
					addlineTemp.Format("%d-%d ",2,i);
					addline+=addlineTemp;
				}
			}
		}
		//起点在2号线，终点不在2号线
		else if((2==startline1 || 2==startline2) && (2!=endline1 && 2!=endline2))
		{
			startlineNum=2;
			endlineNum=1;
			if("xizhimen"==startEName || "dongzhimen"==startEName)
			{
				for(i=startStation1;i>=11;i--)
				{
					addlineTemp.Format("%d-%d ",2,i);
					addline+=addlineTemp;
				}
			}
			if("fuxingmen"==startEName)
			{
				startlineNum=1;
				for(i=11;i<=16;i++)
				{
					addlineTemp.Format("%d-%d ",1,i);
					addline+=addlineTemp;
				}
			}
			for(i=17;i<=endStation1;i++)
			{
				addlineTemp.Format("%d-%d ",1,i);
				addline+=addlineTemp;
			}
		}
		//起点不在2号线，终点在2号线
		else if((2!=startline1 && 2!=startline2) && (2==endline1 || 2==endline2))
		{
			startlineNum=1;
			endlineNum=2;
			for(i=startStation1;i>=17;i--)
			{
				addlineTemp.Format("%d-%d ",1,i);
				addline+=addlineTemp;
			}
			if("xizhimen"==endEName || "dongzhimen"==endEName)
			{
				for(i=11;i<=endStation1;i++)
				{
					addlineTemp.Format("%d-%d ",2,i);
					addline+=addlineTemp;
				}
			}
			if("fuxingmen"==endEName)
			{
				endlineNum=1;
				for(i=16;i>=11;i--)
				{
					addlineTemp.Format("%d-%d ",1,i);
					addline+=addlineTemp;
				}
			}
		}
		//起点和终点都不在2号线
		else
		{
			startlineNum=1;
			endlineNum=1;
			if("sihui"==startEName)				//四惠到四惠东
			{
				addlineTemp.Format("%d-%d ",1,21);
				addline+=addlineTemp;
			}
			else								//四惠东到四惠
			{
				addlineTemp.Format("%d-%d ",1,21);
				addline+=addlineTemp;
			}
		}
		break;
	default :
		break;
	}

	//将结果字符串添加到列表框中
	((CListBox*)GetDlgItem(IDC_LIST1))->ResetContent();	//清空以前的内容
	if(1==solution)
	{
		((CListBox*)GetDlgItem(IDC_LIST1))->AddString(GetResultsList(addline));
	}
	else
	{
		for(i=solution-1;i>=0;i--)
		{
			((CListBox*)GetDlgItem(IDC_LIST1))->AddString(GetResultsList(addlineN[i]));
		}
	}
}

int* CSample17Dlg::GetLine2(int line1, int line2)
{
    int* results=new int[10];
    //读取intersectionLines.txt文件到temp_intersectionLinesAll中
	CFile intersectionLinesFile("E:\\subway\\intersectionLines.txt",CFile::modeRead);
	DWORD intersectionLinesLen;
	char* intersectionLinesAll;
	CString temp_intersectionLinesAll;
	CString strResults;
	int intersectionLinesPos1,intersectionLinesPos2;
	intersectionLinesLen=intersectionLinesFile.GetLength();
	intersectionLinesAll=new char[intersectionLinesLen];
	intersectionLinesAll[intersectionLinesLen]=0;
	intersectionLinesFile.Read(intersectionLinesAll,intersectionLinesLen);
	temp_intersectionLinesAll=intersectionLinesAll;
	intersectionLinesFile.Close();
    //获取<line1,line2>之间的字符串strResults
	CString strLine;
	strLine.Format("<%d,%d>",line1,line2);
	intersectionLinesPos1=temp_intersectionLinesAll.Find(strLine);
	intersectionLinesPos2=temp_intersectionLinesAll.Find(strLine,intersectionLinesPos1+strlen(strLine));
	strResults=temp_intersectionLinesAll.Mid(intersectionLinesPos1+strlen(strLine),intersectionLinesPos2-intersectionLinesPos1-strlen(strLine));
    //将strResults中的内容转化为一个数组results，并输出
	int* pos=new int[10];
	pos[0]=-1;
	CString strTemp;
	for(int i=1;i<10;i++)
	{
		pos[i]=strResults.Find(",",pos[i-1]+1);
		strTemp=strResults.Mid(pos[i-1]+1,pos[i]-pos[i-1]-1);
		results[i-1]=atoi(strTemp);
	}
	strTemp=strResults.Mid(pos[9]+1,strlen(strResults)-1);
	results[9]=atoi(strTemp);
	return results;
}

CString CSample17Dlg::GetInsection(CString linepart)
{
	CString* name=new CString[2];
	CString insectName;
	int linepartPos,posTemp1,posTemp2;
	//在GElinepart.txt中的字符串寻找输入子段名的位置
	linepartPos=temp_linepartAll.Find(linepart);
	posTemp1=linepartPos;
	char mark;
	BOOL ismark;
	ismark=FALSE;
	while(FALSE==ismark)
	{
		posTemp1--;
		mark=temp_linepartAll.GetAt(posTemp1);
		if('<'==mark)
		{
			ismark=TRUE;
		}
		if(0==posTemp1)
		{
			ismark=TRUE;
		}
	}
	//获取与该段路线相关的站点名称
	name[0]=temp_linepartAll.Mid(posTemp1+1,linepartPos-posTemp1-2);
	posTemp2=temp_linepartAll.Find('>',linepartPos);
	name[1]=temp_linepartAll.Mid(linepartPos+strlen(linepart)+2,posTemp2-linepartPos-strlen(linepart)-2);
	
	int interTemp1,interTemp2;
	interTemp1=temp_intersectionAll.Find(name[0]);
	interTemp2=temp_intersectionAll.Find(name[1]);
	//判断站点名称是否为交点，是则返回交点名
	if(-1==interTemp1 && -1==interTemp2)		//子段两端站点都不是交点
	{
		insectName="";
	}
	else if(-1==interTemp1 && -1!=interTemp2)	//子段终点是交点
	{
		insectName=name[1];
	}
	else if(-1!=interTemp1 && -1==interTemp2)	//子段起点是交点
	{
		insectName=name[0]; 
	}
	else										//子段两端站点都是交点
	{
		if("1-20"==linepart || "13-1"==linepart)
		{
			insectName="sihui";
		}
		if("1-21"==linepart || "13-2"==linepart)
		{
			insectName="sihuidong";
		}
	}
	return insectName;
}

int* CSample17Dlg::OrderLine(int *lineNum)
{
	int orderTemp;
	//确定返回数组的第一个元素
	for(int i=0;i<=3;i++)
	{
		if(lineNum[i]<=lineNum[0])
		{
			orderTemp=lineNum[0];
			lineNum[0]=lineNum[i];
			lineNum[i]=orderTemp;
		}
	}
	//确定返回数组的第二个元素
	for(i=1;i<=3;i++)
	{
		if(lineNum[i]<=lineNum[1])
		{
			orderTemp=lineNum[1];
			lineNum[1]=lineNum[i];
			lineNum[i]=orderTemp;
		}
	}
	//确定返回数组的第三个元素
	for(i=2;i<=3;i++)
	{
		if(lineNum[i]<=lineNum[2])
		{
			orderTemp=lineNum[2];
			lineNum[2]=lineNum[i];
			lineNum[i]=orderTemp;
		}
	}
	return lineNum;
}

CString CSample17Dlg::GetResultsList(CString addline)
{
	CString linesList;
    int* resultlineTemp=new int[4];
	resultlineTemp[0]=addline.Find("1-");		//查找包含1号线的首个子段位置
	resultlineTemp[1]=addline.Find("2-");		//查找包含2号线的首个子段位置
	resultlineTemp[2]=addline.Find("8-");		//查找包含8号线的首个子段位置
	resultlineTemp[3]=addline.Find("13-");		//查找包含13号线首个的子段位置
	int* resultline=new int[4];
	resultline=OrderLine(resultlineTemp);		//子段位置重新排序
	if(resultline[3]<0)
	{
		AfxMessageBox("内部错误！");
	}
	else if(resultline[2]<0)					//换乘0次
	{
		CString line1;
		int lineTemp1;
		lineTemp1=addline.Find("-",resultline[3]);
		//乘坐线路名称
		line1=addline.Mid(resultline[3],lineTemp1-resultline[3]);
		linesList.Format("%s号线直达",line1);
	}
	else if(resultline[1]<0)					//换乘1次
	{
		int resultPos1;
		CString line1,line2;
		int lineTemp1,lineTemp2;
		CString convertNum,convertName,resultName;
		resultPos1=addline.Find(" ",resultline[3]);
		convertNum=addline.Mid(resultline[3],resultPos1-resultline[3]);
		convertName=GetInsection(convertNum);
		resultName=FormatName(convertName);		//换乘站点名称
		lineTemp1=addline.Find("-",resultline[2]);
		lineTemp2=addline.Find("-",resultline[3]);
		//乘坐线路1和线路2名称
		line1=addline.Mid(resultline[2],lineTemp1-resultline[2]);
		line2=addline.Mid(resultline[3],lineTemp2-resultline[3]);
		linesList.Format("请先乘坐%s号线，在%s下车，然后换乘%s号线",line1,resultName,line2);
	}
	else if(resultline[0]<0)					//换乘2次
	{
		int resultPos1,resultPos2;
		CString line1,line2,line3;
		int lineTemp1,lineTemp2,lineTemp3;
		CString convertNum1,convertName1,resultName1;
		CString convertNum2,convertName2,resultName2;
		resultPos1=addline.Find(" ",resultline[2]);
		convertNum1=addline.Mid(resultline[2],resultPos1-resultline[2]);
		convertName1=GetInsection(convertNum1);
		resultName1=FormatName(convertName1);	//换乘站点1名称
		resultPos2=addline.Find(" ",resultline[3]);
		convertNum2=addline.Mid(resultline[3],resultPos2-resultline[3]);
		convertName2=GetInsection(convertNum2);
		resultName2=FormatName(convertName2);	//换乘站点2名称
		lineTemp1=addline.Find("-",resultline[1]);
		lineTemp2=addline.Find("-",resultline[2]);
		lineTemp3=addline.Find("-",resultline[3]);
		//乘坐线路1、2、3名称
		line1=addline.Mid(resultline[1],lineTemp1-resultline[1]);
		line2=addline.Mid(resultline[2],lineTemp2-resultline[2]);
		line3=addline.Mid(resultline[3],lineTemp3-resultline[3]);
		linesList.Format("请先乘坐%s号线，在%s下车，然后换乘%s号线，在%s下车，再换乘%s号线",line1,resultName1,line2,resultName2,line3);
	}
	else										//换乘3次
	{
		int resultPos1,resultPos2,resultPos3;
		CString line1,line2,line3,line4;
		int lineTemp1,lineTemp2,lineTemp3,lineTemp4;
		CString convertNum1,convertName1,resultName1;
		CString convertNum2,convertName2,resultName2;
		CString convertNum3,convertName3,resultName3;

		resultPos1=addline.Find(" ",resultline[1]);
		convertNum1=addline.Mid(resultline[1],resultPos1-resultline[1]);
		convertName1=GetInsection(convertNum1);
		resultName1=FormatName(convertName1);	//换乘站点1名称

		resultPos2=addline.Find(" ",resultline[2]);
		convertNum2=addline.Mid(resultline[2],resultPos2-resultline[2]);
		convertName2=GetInsection(convertNum2);
		resultName2=FormatName(convertName2);	//换乘站点2名称

		resultPos3=addline.Find(" ",resultline[3]);
		convertNum3=addline.Mid(resultline[3],resultPos3-resultline[3]);
		convertName3=GetInsection(convertNum3);
		resultName3=FormatName(convertName3);	//换乘站点3名称

		lineTemp1=addline.Find("-",resultline[0]);
		lineTemp2=addline.Find("-",resultline[1]);
		lineTemp3=addline.Find("-",resultline[2]);
		lineTemp4=addline.Find("-",resultline[3]);
		//乘坐线路1、2、3、4名称
		line1=addline.Mid(resultline[0],lineTemp1-resultline[0]);
		line2=addline.Mid(resultline[1],lineTemp2-resultline[1]);
		line3=addline.Mid(resultline[2],lineTemp3-resultline[2]);
		line4=addline.Mid(resultline[3],lineTemp4-resultline[3]);
		linesList.Format("请先乘坐%s号线，在%s下车，然后换乘%s号线，在%s下车，再换乘%s号线，在%s下车，最后换乘%s号线",line1,resultName1,line2,resultName2,line3,resultName3,line4);
	}
	return linesList;
}

CString CSample17Dlg::FormatName(CString name)
{
	int namePos,namePos1,namePos2;
	CString formatname;
	//在language.txt的字符串中查找输入的站点名称 
	namePos=temp_languageAll.Find(name);
	namePos1=temp_languageAll.Find("/",namePos);
	namePos2=temp_languageAll.Find(">",namePos);
	formatname=temp_languageAll.Mid(namePos1+1,namePos2-namePos1-1);
	return formatname;
}

void CSample17Dlg::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	//判断是否启动了客户端
	if(FALSE==m_active)
	{
		AfxMessageBox("客户端未启动！");
		return;
	}	
	CString* addlines;
	IFeatureGE* feature;
	int count;
	int i;
	//清除前面的显示
	IFeatureGE oldFeature;
	IFeatureGE startFeature,endFeature;
	IFeatureGE* oldfeature;
	IFeatureCollectionGE oldCollect;
	//获取Temporary Places文件夹中的要素 
	oldFeature=m_geApplication.GetTemporaryPlaces();
	oldCollect=oldFeature.GetChildren();
	oldfeature=new IFeatureGE[oldCollect.GetCount()];
	for(i=0;i<oldCollect.GetCount();i++)
	{
		oldfeature[i]=oldCollect.GetItem(i+1);
		oldfeature[i].SetVisibility(FALSE);
	}
    //根据分析结果显示相应的子段要素
	if(1==solution)
	{
		addlines=GetFilename(addline);		//调用GetFilename获取子段名
		count=atoi(addlines[0]);			//获取要显示的子段数
		feature=new IFeatureGE[count-1];
		for(i=1;i<count;i++)
		{
			feature[i-1]=m_geApplication.GetFeatureByName(addlines[i]);
			feature[i-1].SetVisibility(TRUE);
		}
		startFeature=m_geApplication.GetFeatureByName(m_startName);
		endFeature=m_geApplication.GetFeatureByName(m_endName);
		startFeature.SetVisibility(TRUE);	//显示起点站的地标
		endFeature.SetVisibility(TRUE);		//显示终点站的地标
	}
	else
	{
		int item=((CListBox*)GetDlgItem(IDC_LIST1))->GetCurSel();
		addlines=GetFilename(addlineN[item]);
		count=atoi(addlines[0]);			//获取要显示的子段数
		feature=new IFeatureGE[count-1];
		for(i=1;i<count;i++)
		{
			feature[i-1]=m_geApplication.GetFeatureByName(addlines[i]);
			feature[i-1].SetVisibility(TRUE);
		}
		startFeature=m_geApplication.GetFeatureByName(m_startName);
		endFeature=m_geApplication.GetFeatureByName(m_endName);
		startFeature.SetVisibility(TRUE);	//显示起点站的地标
		endFeature.SetVisibility(TRUE);		//显示终点站的地标
	}
}

CString* CSample17Dlg::GetFilename(CString addline)
{
	CString* resultsTemp;
	CString* results;
	CString temp;
	int num(0);
	int len;
	len=strlen(addline);
	for(int i=0;i<len;i++)			//获取子段的段数
	{
		if(' '==addline.GetAt(i))
			num++;
	}
	resultsTemp=new CString[num+1];
	results=new CString[num+1];
	int* namepos=new int[num];
	namepos[0]=-1;
	for(i=1;i<num;i++)				//获取每个子段在字符串中的位置
	{
		namepos[i]=addline.Find(" ",namepos[i-1]+1);
	}
	//将子段名逐一赋值到resultsTemp中
	for(i=0;i<num-1;i++)
	{
		resultsTemp[i]=addline.Mid(namepos[i]+1,namepos[i+1]-namepos[i]-1);
	}
	resultsTemp[num-1]=addline.Mid(namepos[num-1]+1,len-namepos[num-1]-2);
	temp.Format("%d",num+1);
	resultsTemp[num]=temp;
	//results数组的第一个元素记录了数组的大小			
	results[0]=temp;
	for(i=1;i<=num;i++)
	{
		results[i]=resultsTemp[i-1];
	}
	return results;
}

void CSample17Dlg::OnInitialize() 
{
	// TODO: Add your control notification handler code here
	//判断是否启动了客户端
	if(FALSE==m_active)
	{
		AfxMessageBox("客户端未启动！");
		return;
	}	
	//初始化视图
	m_geApplication.SetCameraParams(39.961489,116.404267,20.0,2,44880.0,0.0,0.0,4.5);
	IFeatureGE allFeature;
	IFeatureGE* allfeature;
	IFeatureCollectionGE allCollect;
	allFeature=m_geApplication.GetTemporaryPlaces();		    //获取Temporary Places文件夹中的内容
	allCollect=allFeature.GetChildren();
	allfeature=new IFeatureGE[allCollect.GetCount()];
	//显示表示地铁线的KML文件
	for(int i=0;i<allCollect.GetCount();i++)
	{
		allfeature[i]=allCollect.GetItem(i+1);
		if(-1!=(allfeature[i].GetName()).Find("-"))
			allfeature[i].SetVisibility(TRUE);
	}	
}
