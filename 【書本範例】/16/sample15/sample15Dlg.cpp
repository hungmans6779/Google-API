// sample15Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "sample15.h"
#include "sample15Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "CREATE.h"
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
// CSample15Dlg dialog

CSample15Dlg::CSample15Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSample15Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSample15Dlg)
	m_from = _T("");
	m_to = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample15Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSample15Dlg)
	DDX_Text(pDX, IDC_EDIT1, m_from);
	DDX_Text(pDX, IDC_EDIT2, m_to);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSample15Dlg, CDialog)
	//{{AFX_MSG_MAP(CSample15Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_PATH_SEARCH, OnPathSearch)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample15Dlg message handlers

BOOL CSample15Dlg::OnInitDialog()
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
	m_from="beijing";
	m_to="wuhan";
	isPlay=FALSE;
	isSearch=FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSample15Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSample15Dlg::OnPaint() 
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
HCURSOR CSample15Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSample15Dlg::OnStart() 
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

void CSample15Dlg::OnPathSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	//打開GEdatabase.txt，根據用戶輸入進行搜索
	CFile dbFile("E:\\GEdatabase.txt",CFile::modeRead);
	DWORD dbLen;
	char* dbAll;
	dbLen=dbFile.GetLength();
	dbAll=new char[dbLen];
	dbAll[dbLen]=0;
	dbFile.Read(dbAll,dbLen);				//將文件中的內容讀取到dbAll中
	CString temp_dbAll;
	temp_dbAll=dbAll;

	CString fromStr1,fromStr2;
	CString toStr1,toStr2;
	fromStr1.Format("<%s>",m_from);
	fromStr2.Format("</%s>",m_from);
	toStr1.Format("<%s>",m_to);
	toStr2.Format("</%s>",m_to);
	//搜索起點和終點的坐標信息
	int dbPos1,dbPos2,dbPos3,dbPos4;
	dbPos1=temp_dbAll.Find(fromStr1)+strlen(fromStr1);
	dbPos2=temp_dbAll.Find(fromStr2);
	dbPos3=temp_dbAll.Find(toStr1)+strlen(toStr1);
	dbPos4=temp_dbAll.Find(toStr2);
	CString dataStrFrom;
	dataStrFrom=temp_dbAll.Mid(dbPos1,dbPos2-dbPos1);
	CString dataStrTo;
	dataStrTo=temp_dbAll.Mid(dbPos3,dbPos4-dbPos3);
	dbFile.Close();
	//獲取起點經緯度
	int intervalFrom,intervalTo;
	intervalFrom=dataStrFrom.Find(",");
	CString dataLatFrom,dataLonFrom;
	dataLatFrom=dataStrFrom.Left(intervalFrom);
	dataLonFrom=dataStrFrom.Right(strlen(dataStrFrom)-intervalFrom-1);
	//獲取終點經緯度終點
	intervalTo=dataStrTo.Find(",");
	CString dataLatTo,dataLonTo;
	dataLatTo=dataStrTo.Left(intervalTo);
	dataLonTo=dataStrTo.Right(strlen(dataStrTo)-intervalTo-1);

	//讀取模板文件
	CFile modelFile("E:\\model.kml",CFile::modeRead);
	DWORD writeLen;
	char* writeAll;
	writeLen=modelFile.GetLength();
	writeAll=new char[writeLen];
	writeAll[writeLen]=0;
	modelFile.Read(writeAll,writeLen);		//將文件中的內容讀取到writeAll中
	CString str_Writeall;
	str_Writeall=writeAll;
	modelFile.Close();
    //起點和終點格式轉換
	double startPotx,startPoty,endPotx,endPoty;
	startPotx=atof(dataLatFrom);
	startPoty=atof(dataLonFrom);
	endPotx=atof(dataLatTo);
	endPoty=atof(dataLonTo);

	//插入起點地標
	int startInsert1,startInsert2;
	startInsert1=str_Writeall.Find("from:");
	startInsert2=str_Writeall.Find("</Placemark>");
	CString startStr,startTemp1,startTemp2,startInsertStr;
	startStr=str_Writeall.Mid(startInsert1,startInsert2-startInsert1+strlen("</Placemark>"));
    int startInsert3,startInsert4,startInsert5,startInsert6;
	startInsert3=startStr.Find("</name>");
	startStr.Insert(startInsert3,m_from);
	startInsert4=startStr.Find("</longitude>");
	startStr.Insert(startInsert4,dataLonFrom);
	startInsert5=startStr.Find("</latitude>");
	startStr.Insert(startInsert5,dataLatFrom);
	startInsert6=startStr.Find("</coordinates>");
	startTemp1.Format("%.5f,%.5f,0",startPoty,startPotx);
	startStr.Insert(startInsert6,startTemp1);

	//插入終點地標
	int endInsert1,endInsert2;
	endInsert1=str_Writeall.Find("to:");
	endInsert2=str_Writeall.Find("</Placemark>",endInsert1);
	CString endStr,endTemp1,endTemp2,endInsertStr;
	endStr=str_Writeall.Mid(endInsert1,endInsert2-endInsert1+strlen("</Placemark>"));
    int endInsert3,endInsert4,endInsert5,endInsert6;
	endInsert3=endStr.Find("</name>");
	endStr.Insert(endInsert3,m_to);
	endInsert4=endStr.Find("</longitude>");
	endStr.Insert(endInsert4,dataLonTo);
	endInsert5=endStr.Find("</latitude>");
	endStr.Insert(endInsert5,dataLatTo);
	endInsert6=endStr.Find("</coordinates>");
	endTemp1.Format("%.5f,%.5f,0",endPoty,endPotx);
	endStr.Insert(endInsert6,endTemp1);

	//根據起點和終點的位置進行判斷
	int option;
	if(startPotx<endPotx && startPoty<endPoty)
		option=1;
	if(startPotx<endPotx && startPoty>endPoty)
		option=2;
	if(startPotx>endPotx && startPoty<endPoty)
		option=3;
	if(startPotx>endPotx && startPoty>endPoty)
		option=4;

	double rangeX,rangeY;
	int partNum;
	double partRangex,partRangey;
	double* lat;
	double* lon;
	int i,j(0);

	//檢查起點和終點數據
	switch(option)
	{
	case 1:
		rangeX=endPotx-startPotx;
		rangeY=endPoty-startPoty;
		break;
	case 2:
		rangeX=endPotx-startPotx;
		rangeY=startPoty-endPoty;
		break;
	case 3:
		rangeX=startPotx-endPotx;
		rangeY=endPoty-startPoty;
		break;
	case 4:
		rangeX=startPotx-endPotx;
		rangeY=startPoty-endPoty;
		break;
	default:
		break;
	}

	//將路徑分為幾段
	if(rangeX>rangeY)
	{
		partNum=(int)rangeX/0.9;
	}
	else
	{
		partNum=(int)rangeY/0.9;
	}
	if(0==partNum)
	{
		partNum=1;
	}
	//定義兩個二維數組
	typedef double* DoubleArrayPtr;
	DoubleArrayPtr* lineLat=new DoubleArrayPtr[partNum];
	for(i=0;i<partNum;i++)
	{
		lineLat[i]=new double[100];
	}
	DoubleArrayPtr* lineLon=new DoubleArrayPtr[partNum];
	for(i=0;i<partNum;i++)
	{
		lineLon[i]=new double[100];
	}
	double deltax,deltay;

	switch(option)
	{
	case 1:									//情況1：終點在起點的東北方向
		if(1==partNum)						//分段數為1，數組賦值
		{
			lat=new double[partNum];
			lon=new double[partNum];
			lat[0]=startPotx;
			lon[0]=startPoty;
			lat[1]=endPotx;
			lon[1]=endPoty;
			partRangex=rangeX;
			partRangey=rangeY;
		}
		else								//分段數大於1，數組賦值
		{
			partRangex=rangeX/partNum;
			partRangey=rangeY/partNum;
			
			lat=new double[partNum];
			lon=new double[partNum];
			lat[0]=startPotx;
			lon[0]=startPoty;
			lat[partNum-1]=endPotx;
			lon[partNum-1]=endPoty;
			
			for(i=1;i<partNum-1;i++)
			{
				if(0==i%2)
				{
					lat[i]=lat[0]+partRangex*i;
					lon[i]=lon[i-1];
				}
				else
				{
					lat[i]=lat[i-1];
					lon[i]=lon[0]+partRangey*i;
				}
			}
		}
		
		//為二維數組賦值，內插路徑點
		deltax=partRangex/100.0;
		deltay=partRangey/100.0;
		for(i=0;i<partNum;i++)
		{
			lineLat[i][0]=lat[i];
			lineLon[i][0]=lon[i];
			switch(j%5)
			{
			case 0:
				lineLat[i][j]=lat[i]+j*deltax;
				lineLon[i][j]=lon[i]+(j-1)*deltay;
				break;
			case 1:
				lineLat[i][j]=lat[i]+j*deltax+0.00005;
				lineLon[i][j]=lon[i]+(j-1)*deltay-0.00004;
				break;
			case 2:
				lineLat[i][j]=lat[i]+j*deltax+0.00005;
				lineLon[i][j]=lon[i]+(j-1)*deltay+0.00004;
				break;
			case 3:
				lineLat[i][j]=lat[i]+j*deltax-0.00005;
				lineLon[i][j]=lon[i]+(j-1)*deltay+0.00004;
				break;
			case 4:
				lineLat[i][j]=lat[i]+(j-1)*deltax;
				lineLon[i][j]=lon[i]+j*deltay;
				break;
			default:
				break;
			}
		}
		break;
	case 2:									//情況2：終點在起點的西北方向
		if(1==partNum)						//分段數為1，數組賦值
		{
			lat=new double[partNum];
			lon=new double[partNum];
			lat[0]=startPotx;
			lon[0]=startPoty;
			lat[1]=endPotx;
			lon[1]=endPoty;
			partRangex=rangeX;
			partRangey=rangeY;
		}
		else								//分段數大於1，數組賦值
		{
			partRangex=rangeX/partNum;
			partRangey=rangeY/partNum;
			
			lat=new double[partNum];
			lon=new double[partNum];
			lat[0]=startPotx;
			lon[0]=startPoty;
			lat[partNum-1]=endPotx;
			lon[partNum-1]=endPoty;
			
			for(i=1;i<partNum-1;i++)
			{
				if(0==i%2)
				{
					lat[i]=lat[0]+partRangex*i;
				}
				else
				{
					lat[i]=lat[i-1];
				}
			}
			for(i=1;i<partNum-1;i++)
			{
				if(0==i%2)
				{
					lon[i]=lon[i-1];
				}
				else
				{
					lon[i]=lon[0]-partRangey*i;
				}
			}
		}

		//為二維數組賦值，內插路徑點
		deltax=partRangex/100.0;
		deltay=partRangey/100.0;
		for(i=0;i<partNum;i++)
		{
			lineLat[i][0]=lat[i];
			lineLon[i][0]=lon[i];
			for(j=1;j<100;j++)
			{
				switch(j%5)
				{
				case 0:
					lineLat[i][j]=lat[i]+j*deltax;
					lineLon[i][j]=lon[i]-(j-1)*deltay;
					break;
				case 1:
					lineLat[i][j]=lat[i]+j*deltax+0.00005;
					lineLon[i][j]=lon[i]-(j-1)*deltay-0.00004;
					break;
				case 2:
					lineLat[i][j]=lat[i]+j*deltax+0.00005;
					lineLon[i][j]=lon[i]-(j-1)*deltay+0.00004;
					break;
				case 3:
					lineLat[i][j]=lat[i]+j*deltax-0.00005;
					lineLon[i][j]=lon[i]-(j-1)*deltay+0.00004;
					break;
				case 4:
					lineLat[i][j]=lat[i]+(j-1)*deltax;
					lineLon[i][j]=lon[i]-j*deltay;
					break;
				default:
					break;
				}
			}
		}
		break;
	case 3:									//情況3：終點在起點的東南方向
		if(1==partNum)						//分段數為1，數組賦值
		{
			lat=new double[partNum];
			lon=new double[partNum];
			lat[0]=startPotx;
			lon[0]=startPoty;
			lat[1]=endPotx;
			lon[1]=endPoty;
			partRangex=rangeX;
			partRangey=rangeY;
		}
		else								//分段數大於1，數組賦值
		{
			partRangex=rangeX/partNum;
			partRangey=rangeY/partNum;
			
			lat=new double[partNum];
			lon=new double[partNum];
			lat[0]=startPotx;
			lon[0]=startPoty;
			lat[partNum-1]=endPotx;
			lon[partNum-1]=endPoty;
			
			for(i=1;i<partNum-1;i++)
			{
				if(0==i%2)
				{
					lat[i]=lat[0]-partRangex*i;
				}
				else
				{
					lat[i]=lat[i-1];
				}
			}
			for(i=1;i<partNum-1;i++)
			{
				if(0==i%2)
				{
					lon[i]=lon[i-1];
				}
				else
				{
					lon[i]=lon[0]+partRangey*i;
				}
			}
		}
		
		//為二維數組賦值，內插路徑點
		deltax=partRangex/100.0;
		deltay=partRangey/100.0;
		for(i=0;i<partNum;i++)
		{
			lineLat[i][0]=lat[i];
			lineLon[i][0]=lon[i];
			for(j=1;j<100;j++)
			{
				switch(j%5)
				{
				case 0:
					lineLat[i][j]=lat[i]-j*deltax;
					lineLon[i][j]=lon[i]+(j-1)*deltay;
					break;
				case 1:
					lineLat[i][j]=lat[i]-j*deltax+0.00005;
					lineLon[i][j]=lon[i]+(j-1)*deltay-0.00004;
					break;
				case 2:
					lineLat[i][j]=lat[i]-j*deltax+0.00005;
					lineLon[i][j]=lon[i]+(j-1)*deltay+0.00004;
					break;
				case 3:
					lineLat[i][j]=lat[i]-j*deltax-0.00005;
					lineLon[i][j]=lon[i]+(j-1)*deltay+0.00004;
					break;
				case 4:
					lineLat[i][j]=lat[i]-(j-1)*deltax;
					lineLon[i][j]=lon[i]+j*deltay;
					break;
				default:
					break;
				}
			}
		}
		break;
	case 4:									//情況4：終點在起點的西南方向
		if(1==partNum)						//分段數為1，數組賦值
		{
			lat=new double[partNum];
			lon=new double[partNum];
			lat[0]=startPotx;
			lon[0]=startPoty;
			lat[1]=endPotx;
			lon[1]=endPoty;
			partRangex=rangeX;
			partRangey=rangeY;
		}
		else								//分段數大於1，數組賦值
		{
			partRangex=rangeX/partNum;
			partRangey=rangeY/partNum;
			
			lat=new double[partNum];
			lon=new double[partNum];
			lat[0]=startPotx;
			lon[0]=startPoty;
			lat[partNum-1]=endPotx;
			lon[partNum-1]=endPoty;
			
			for(i=1;i<partNum-1;i++)
			{
				if(0==i%2)
				{
					lat[i]=lat[0]-partRangex*i;
				}
				else
				{
					lat[i]=lat[i-1];
				}
			}
			for(i=1;i<partNum-1;i++)
			{
				if(0==i%2)
				{
					lon[i]=lon[i-1];
				}
				else
				{
					lon[i]=lon[0]-partRangey*i;
				}
			}
		}
		
		//為二維數組賦值，內插路徑點
		deltax=partRangex/100.0;
		deltay=partRangey/100.0;
		for(i=0;i<partNum;i++)
		{
			lineLat[i][0]=lat[i];
			lineLon[i][0]=lon[i];
			for(j=1;j<100;j++)
			{
				switch(j%5)
				{
				case 0:
					lineLat[i][j]=lat[i]-j*deltax;
					lineLon[i][j]=lon[i]-(j-1)*deltay;
					break;
				case 1:
					lineLat[i][j]=lat[i]-j*deltax+0.00005;
					lineLon[i][j]=lon[i]-(j-1)*deltay-0.00004;
					break;
				case 2:
					lineLat[i][j]=lat[i]-j*deltax+0.00005;
					lineLon[i][j]=lon[i]-(j-1)*deltay+0.00004;
					break;
				case 3:
					lineLat[i][j]=lat[i]-j*deltax-0.00005;
					lineLon[i][j]=lon[i]-(j-1)*deltay+0.00004;
					break;
				case 4:
					lineLat[i][j]=lat[i]-(j-1)*deltax;
					lineLon[i][j]=lon[i]-j*deltay;
					break;
				default:
					break;
				}
			}
		}
		break;
	default:
		break;
	}

	//將路徑各段的線組合在一起
	CString* lineStr;
	CString* strAll;
	lineStr=new CString[partNum];
	strAll=new CString[partNum];
	CString lineTemp;
	for(i=0;i<partNum;i++)
	{
		for(j=0;j<100;j++)
		{
			lineTemp.Format("%.5f,%.5f,0 ",lineLon[i][j],lineLat[i][j]);
			lineStr[i]+=lineTemp;
		}
	}

	//讀取數據格式文件
	CFile readFile("E:\\format.kml",CFile::modeRead);
	DWORD readLen;
	char* readAll;
	readLen=readFile.GetLength();
	readAll=new char[readLen];
	readAll[readLen]=0;
	readFile.Read(readAll,readLen);

	//插入生成的起點數據到格式化的字符串中
	CString temp_strAll;
	temp_strAll=readAll;
	int insertPos1;
	insertPos1=temp_strAll.Find("</coordinates>");
	for(i=0;i<partNum;i++)
	{
		strAll[i]=temp_strAll;
		strAll[i].Insert(insertPos1,lineStr[i]);
	}

	//插入生成的起點數據到格式化的字符串中
	int insertPos2;
	for(i=0;i<partNum;i++)
	{
		insertPos2=str_Writeall.Find("</MultiGeometry>");
		str_Writeall.Insert(insertPos2,strAll[i]);
	}	
	readFile.Close();

	//將格式化字符串添加到str_Writeall中
	CString temp1,temp2;
    temp1=str_Writeall.Mid(startInsert1,startInsert2-startInsert1+strlen("</Placemark>"));
	str_Writeall.Replace(temp1,startStr);
	int endInsert7,endInsert8;
	endInsert7=str_Writeall.Find("to:");
	endInsert8=str_Writeall.Find("</Placemark>",endInsert7);
    temp2=str_Writeall.Mid(endInsert7,endInsert8-endInsert7+strlen("</Placemark>"));
	str_Writeall.Replace(temp2,endStr);

    //創建文件對話框
    CCREATE createDlg;
	if(IDOK==createDlg.DoModal())
	{
		pathName.Format("E:\\%s.kml",createDlg.m_lineFile);
	}
	else
	{
		AfxMessageBox("請輸入要創建的文件名！");
		return;
	}

	//創建一個子模板文件，並複製模板文件中的內容
	CFile childFile(pathName,CFile::modeCreate|CFile::modeWrite);
	childFile.Write(writeAll,writeLen);
	childFile.Close();

	//在子模板文件中寫入str_Writeall
	CFile writeFile(pathName,CFile::modeWrite);
	char* addLine;
	int len_addLine;
	len_addLine=strlen(str_Writeall);
	addLine=new char[len_addLine];
	addLine=str_Writeall.GetBuffer(0);
	writeFile.Write(addLine,len_addLine);
	writeFile.Close();
	isSearch=TRUE;

	IFeatureGE feature,feature1,feature2,feature3;
	IFeatureCollectionGE collect;
    //打開KML文件
	m_geApplication.OpenKmlFile(pathName,TRUE);
	//獲取KML文件	
	feature3.AttachDispatch(m_geApplication.GetFeatureByName("lujin"),TRUE);
	feature.AttachDispatch(feature3.GetParent(),TRUE);
	collect.AttachDispatch(feature.GetChildren(),TRUE);
	feature1.AttachDispatch(collect.GetItem(1),TRUE);
	feature2.AttachDispatch(collect.GetItem(2),TRUE);
	//將播放位置定位到路徑要素
	feature1.Highlight();
	feature2.Highlight();
	feature3.Highlight();
}

void CSample15Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}

void CSample15Dlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	//判斷是否啟動了Google Earth
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}
    //判斷是否執行了搜索操作
	if(FALSE==isSearch)
	{
		AfxMessageBox("請先搜索！");
		return;
	}
    //動態顯示路徑
	tourControl.AttachDispatch(m_geApplication.GetTourController(),TRUE);
	tourControl.SetSpeed(5.0);
	if(FALSE==isPlay)
	{
		tourControl.PlayOrPause();
		isPlay=TRUE;
	}
}

void CSample15Dlg::OnPause() 
{
	// TODO: Add your control notification handler code here
	//判斷是否啟動了Google Earth
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}
    //判斷是否執行了搜索操作
	if(FALSE==isSearch)
	{
		AfxMessageBox("請先搜索！");
		return;
	}
    //暫停動態顯示
	if(TRUE==isPlay)
	{
		tourControl.PlayOrPause();
		isPlay=FALSE;
	}	
}
