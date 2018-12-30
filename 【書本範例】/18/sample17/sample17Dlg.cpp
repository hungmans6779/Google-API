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
		AfxMessageBox("�Ȥ�ݤw�g�ҰʡI");
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
	//�ĥ�Windows�����������Google Earth�Ȥ��
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();	
}

void CSample17Dlg::OnQuery1() 
{
	// TODO: Add your control notification handler code here
	//�P�_�Ȥ�ݬO�_�Ұ�
	if(FALSE==m_active)
	{
		AfxMessageBox("�Ȥ�ݥ��ҰʡI");
		return;
	}
    //Ū��language.txt��󤤪����e��temp_languageAll��
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
    //Ū��GElinepart.txt��󤤪����e��temp_linepartAll��
	CFile linepartFile("E:\\subway\\GElinepart.txt",CFile::modeRead);
	DWORD linepartLen;
	char* linepartAll;
	linepartLen=linepartFile.GetLength();
	linepartAll=new char[linepartLen];
	linepartAll[linepartLen]=0;
	linepartFile.Read(linepartAll,linepartLen);
	temp_linepartAll=linepartAll;
	linepartFile.Close();
    //Ū��intersection.txt��󤤪����e��temp_intersectionAll��
	CFile intersectionFile("E:\\subway\\intersection.txt",CFile::modeRead);
	DWORD intersectionLen;
	char* intersectionAll;
	intersectionLen=intersectionFile.GetLength();
	intersectionAll=new char[intersectionLen];
	intersectionAll[intersectionLen]=0;
	intersectionFile.Read(intersectionAll,intersectionLen);
	temp_intersectionAll=intersectionAll;
	intersectionFile.Close();
    //Ū��linerelation.txt��󤤪����e��temp_linerelationAll��
	CFile linerelationFile("E:\\subway\\linerelation.txt",CFile::modeRead);
	DWORD linerelationLen;
	char* linerelationAll;
	linerelationLen=linerelationFile.GetLength();
	linerelationAll=new char[linerelationLen];
	linerelationAll[linerelationLen]=0;
	linerelationFile.Read(linerelationAll,linerelationLen);
	temp_linerelationAll=linerelationAll;
	linerelationFile.Close();

	//�N�Τ��J���~�r�Φ��ഫ�������������Φ�
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

	//�d�߯��I���W�A����ر��p�A���I�M�D���I
	//���btemp_intersectionAll���d��A�P�_�ӯ��I�O�_�����I
	int intersectionPos1,intersectionPos2;
	intersectionPos1=temp_intersectionAll.Find(startEName);
	intersectionPos2=temp_intersectionAll.Find(endEName);

	int startPos1,startPos2,endPos1,endPos2;
	int startlineNum,startStation,endlineNum,endStation;
	int startline1,startline2;							//�_�I�Ҧb�u��
	int endline1,endline2;								//���I�Ҧb�u��
	int option;
	int lineRelationPos1,lineRelationPos2;
	CString lineRelation;
	CString temp_startEName,temp_endEName;
	CString startNumName,endNumName;
	CString strlineRelation1,strlineRelation2;
	temp_startEName.Format("<%s>",startEName);
	temp_endEName.Format("</%s>",endEName);
	if(-1==intersectionPos1 && -1==intersectionPos2)	//�_�I�M���I�����O���I
	{
		option=1;
		//����_�I�Ҧb�u���M���W
		startPos1=temp_linepartAll.Find(temp_startEName);
		startPos2=temp_linepartAll.Find("</",startPos1);
		startNumName=temp_linepartAll.Mid(startPos1+strlen(temp_startEName),startPos2-startPos1-strlen(temp_startEName));
		int breakStartNumName;
		breakStartNumName=startNumName.Find("-");
		startlineNum=atoi(startNumName.Left(breakStartNumName));
		startStation=atoi(startNumName.Right(strlen(startNumName)-breakStartNumName-1));
		//������I�Ҧb�u���M���W
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
	else if(-1==intersectionPos1 && -1!=intersectionPos2)	//���I�O���I
	{
		option=2;
		//����_�I�Ҧb�u���M���W
		startPos1=temp_linepartAll.Find(temp_startEName);
		startPos2=temp_linepartAll.Find("</",startPos1);
		startNumName=temp_linepartAll.Mid(startPos1+strlen(temp_startEName),startPos2-startPos1-strlen(temp_startEName));
		int breakStartNumName;
		breakStartNumName=startNumName.Find("-");
		startlineNum=atoi(startNumName.Left(breakStartNumName));
		startStation=atoi(startNumName.Right(strlen(startNumName)-breakStartNumName-1));

		//������I�H��
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
	else if(-1==intersectionPos2 && -1!=intersectionPos1)	//�_�I�O���I
	{
		option=3;
		//����_�I�H��
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

		//������I�Ҧb�u���M���W
		endPos1=temp_linepartAll.Find(temp_endEName);
		endPos2=temp_linepartAll.Find(">",endPos1-6);
		endNumName=temp_linepartAll.Mid(endPos2+1,endPos1-endPos2-1);
		int breakEndNumName;
		breakEndNumName=endNumName.Find("-");
		endlineNum=atoi(endNumName.Left(breakEndNumName));
		endStation=atoi(endNumName.Right(strlen(endNumName)-breakEndNumName-1));
	}
	else													//�_�I�M���I���O���I
	{
		option=4;
		//����_�I�H��
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
		//������I�H��
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

	//�T�w�˸����u���W
	int i;
	CString addlineTemp;
	addline="";
	switch(option)
	{
	case 1:
		if(startlineNum==endlineNum)
		{
			//���F
			if(2==startlineNum)				//2���u��ؤ��
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
			else							//�D2���u�@�ؤ��
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
					//�����@��
					int* twoLines=new int[10];
					twoLines=GetLine2(startlineNum,endlineNum);
					switch(twoLines[0]+twoLines[1])
					{
					case 2:						//1���u�M8���u
						solution=2;
						addlineN=new CString[solution];
						if(1==startlineNum)		//1���u����8���u
						{
							//�q�L���I1
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
							//�q�L���I2
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
						else					//8���u����1���u
						{
							//�q�L���I1
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
							//�q�L���I2
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
					case 3:									//13���u�M2���u
						solution=4;
						addlineN=new CString[solution];
						if(13==startlineNum)				//13���u��2���u
						{
							for(i=startStation-1;i>=twoLines[2];i--)	//13���u����
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
							for(i=twoLines[4];i<=endStation;i++)		//2���u����
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[0]+=addlineTemp;
							}
							for(i=twoLines[5];i>endStation;i--)
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[1]+=addlineTemp;
							}
							if(endStation>=twoLines[9])					//���I�b�F�����P�誽���_�q
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
							else										//���I�b2���u�F�����P�誽���n�q
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
						else								//2���u��13���u
						{
							for(i=startStation;i<=18;i++)	//2���u����
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[0]+=addlineTemp;
							}
							for(i=startStation-1;i>=1;i--)
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[1]+=addlineTemp;
							}
							if(startStation>=twoLines[7])					//�_�I�b�F�����P�誽���_�q
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
							else											//�_�I�b�F�����P�誽���n�q
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
							for(i=twoLines[4];i<=endStation;i++)			//13���u����
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
					case 4:									//1���u�M2���u
						solution=4;
						addlineN=new CString[solution];
						if(1==startlineNum)					//1���u����2���u
						{
							if(startStation<=twoLines[2])	//�_�I�b�_������
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
							else if(startStation>twoLines[7])	//�_�I�b�ذ���F��
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
							else			//�_�I�b�_�����M�ذ������
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
							if(endStation<=twoLines[4])	//���I�b�誽���M�_��������
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
							else if(endStation<=twoLines[8])	//���I�b�_�����P�ذ���n�q
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
							else			//���I�b�誽���P�ذ���_�q
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
						else									//2���u��1���u
						{
							if(startStation<=twoLines[2])		//�_�I�b�誽���M�_��������
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
							else if(startStation<=twoLines[6])	//����ڸ������뽨�����϶�
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
							else								//�������ֱ���뽨���ű���
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
							if(endStation<=twoLines[4])		//�յ��ڸ�������
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
							else if(endStation>=twoLines[9])	//�յ��ڽ����Ŷ���
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
							else								//�յ��ڸ����źͽ�����֮��
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
					//���˶���
					int* twoLines1=new int[10];
					int* twoLines2=new int[10];
					twoLines1=GetLine2(startlineNum,atoi(lineRelation));
					twoLines2=GetLine2(atoi(lineRelation),endlineNum);
					if("1"==lineRelation)			//2��1��8
					{
						solution=4;
						addlineN=new CString[solution];
						if(2==startlineNum)			//2���߻���1���ߣ��ٻ���8����
						{
							if(startStation<=twoLines1[2])	//�������ֱ�ź͸����Ŷ�
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
							else if(startStation<=twoLines1[6])	//����ڸ����źͽ������϶�
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
							else							//����ڸ����źͽ����ű���
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
							for(i=twoLines1[5];i<=twoLines2[2];i++)	//1���߲��֣������ŵ��Ļݣ�
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[0]+=addlineTemp;
							}
							for(i=twoLines1[5];i<=twoLines2[6];i++)	//1���߲��֣������ŵ��Ļݶ���
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines1[9];i<=twoLines2[2];i++)	//1���߲��֣������ŵ��Ļݣ�
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[2]+=addlineTemp;
							}
							for(i=twoLines1[9];i<=twoLines2[6];i++)	//1���߲��֣������ŵ��Ļݶ���
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[3]+=addlineTemp;
							}
							for(i=twoLines2[4];i<=endStation;i++)	//8���߲��֣��Ļݣ�
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[0]+=addlineTemp;
								addlineN[2]+=addlineTemp;
							}
							for(i=twoLines2[8];i<=endStation;i++)	//8���߲��֣��Ļݶ���
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[1]+=addlineTemp;
								addlineN[3]+=addlineTemp;
							}
						}
						else										//8���߻���1���ߣ��ٻ���2����
						{
							for(i=startStation-1;i>=twoLines1[6];i--)	//8���߲��֣��Ļݣ�
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[0]+=addlineTemp;
								addlineN[2]+=addlineTemp;
							}
							for(i=startStation-1;i>=twoLines1[2];i--)	//8���߲��֣��Ļݶ���
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[1]+=addlineTemp;
								addlineN[3]+=addlineTemp;
							}
						}
					}
					else											//1��2��13
					{
						solution=4;
						addlineN=new CString[solution];
						if(1==startlineNum)							//1���߻���2���ߣ��ٻ���13����
						{
							if(startStation<=twoLines1[2])			//�����1���߸���������
							{
								for(i=startStation;i<=twoLines1[2];i++)	//1���߲��֣������ţ�
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation;i<=twoLines1[6];i++)	//1���߲��֣������ţ�
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else if(startStation<=twoLines1[6])		//�����1���߸������뽨����֮��
							{
								for(i=startStation-1;i>=twoLines1[3];i--)//1���߲��֣������ţ�
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation;i<=twoLines1[6];i++)	//1���߲��֣������ţ�
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else									//�����1���߽����Ŷ���
							{
								for(i=startStation-1;i>=twoLines1[3];i--)//1���߲��֣������ţ�
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=startStation-1;i>=twoLines1[7];i--)//1���߲��֣������ţ�
								{
									addlineTemp.Format("%d-%d ",startlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							for(i=twoLines1[4];i>=twoLines2[4];i--)			//2���߲��֣������ŵ���ֱ�ţ�
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[0]+=addlineTemp;
							}
							for(i=twoLines1[5];i<=twoLines2[6];i++)			//2���߲��֣������ŵ���ֱ�ţ�
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines1[8];i>=twoLines2[4];i--)			//2���߲��֣������ŵ���ֱ�ţ�
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[2]+=addlineTemp;
							}
							for(i=twoLines1[9];i<=twoLines2[6];i++)			//2���߲��֣������ŵ���ֱ�ţ�
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[3]+=addlineTemp;
							}
							for(i=twoLines2[4];i<=endStation;i++)			//13���߲��֣���ֱ�ţ�
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[0]+=addlineTemp;
								addlineN[2]+=addlineTemp;
							}
							for(i=twoLines2[8];i>endStation;i--)			//13���߲��֣���ֱ�ţ�
							{
								addlineTemp.Format("%d-%d ",endlineNum,i);
								addlineN[1]+=addlineTemp;
								addlineN[3]+=addlineTemp;
							}
						}
						else										//13���߻���2���ߣ��ٻ���1����
						{
							for(i=startStation-1;i>=twoLines1[2];i--)	//13���߲��֣���ֱ�ţ�
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[0]+=addlineTemp;
								addlineN[2]+=addlineTemp;
							}
							for(i=startStation;i<=twoLines1[6];i++)		//13���߲��֣���ֱ�ţ�
							{
								addlineTemp.Format("%d-%d ",startlineNum,i);
								addlineN[1]+=addlineTemp;
								addlineN[3]+=addlineTemp;
							}
							for(i=twoLines1[9];i<=18;i++)				//2���߲��֣���ֱ�ŵ������ţ�
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines1[4];i<=twoLines2[2];i++)		//2���߲��֣���ֱ�ŵ������ţ�
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[0]+=addlineTemp;
								addlineN[1]+=addlineTemp;
							}
							for(i=twoLines1[5];i>=twoLines2[5];i--)		//2���߲��֣���ֱ�ŵ������ţ�
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[2]+=addlineTemp;
							}
							for(i=twoLines1[8];i>=twoLines2[7];i--)		//2���߲��֣���ֱ�ŵ������ţ�
							{
								addlineTemp.Format("%d-%d ",atoi(lineRelation),i);
								addlineN[3]+=addlineTemp;
							}
							if(endStation<=twoLines2[4])				//�յ���1���߸���������
							{
								for(i=twoLines2[4];i>endStation;i--)	//�����ų���
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines2[8];i>endStation;i--)	//�����ų���
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else if(endStation<=twoLines2[8])			//�յ���1���߸������뽨����֮��
							{
								for(i=twoLines2[5];i<=endStation;i++)	//�����ų���
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines2[8];i>endStation;i--)	//�����ų���
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[2]+=addlineTemp;
									addlineN[3]+=addlineTemp;
								}
							}
							else										//�յ���1���߽����Ŷ���
							{
								for(i=twoLines2[5];i<=endStation;i++)	//�����ų���
								{
									addlineTemp.Format("%d-%d ",endlineNum,i);
									addlineN[0]+=addlineTemp;
									addlineN[1]+=addlineTemp;
								}
								for(i=twoLines2[9];i<=endStation;i++)	//�����ų���
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
				//��������8��1��2��13
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
				if(8==startlineNum)					//8���߻���1���ߣ��ٻ���2���ߣ��ٻ���13����
				{
					for(i=startStation-1;i>=twoLines1[6];i--)	//8���߲��֣��Ļݣ�
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[0]+=addlineTemp;
						addlineN[2]+=addlineTemp;
					}
					for(i=startStation-1;i>=twoLines1[2];i--)	//8���߲��֣��Ļݶ���
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[1]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines1[8];i>=twoLines2[3];i--)		//1���ߣ��Ļݵ������ţ�
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[0]+=addlineTemp;
					}
					for(i=twoLines1[4];i>=twoLines2[3];i--)		//1���ߣ��Ļݶ��������ţ�
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[1]+=addlineTemp;
					}
					for(i=twoLines1[8];i>=twoLines2[7];i--)		//1���ߣ��Ļݵ������ţ�
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[2]+=addlineTemp;
					}
					for(i=twoLines1[4];i>=twoLines2[7];i--)		//1���ߣ��Ļݶ��������ţ�
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines2[4];i>=twoLines3[2];i--)		//2���ߣ������ŵ���ֱ�ţ�
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[0]+=addlineTemp;
						addlineN[1]+=addlineTemp;
					}
					for(i=twoLines2[9];i<=twoLines3[6];i++)		//2���ߣ������ŵ���ֱ�ţ�
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[2]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines3[4];i<=endStation;i++)		//13���ߣ���ֱ�ţ�
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addlineN[0]+=addlineTemp;
						addlineN[1]+=addlineTemp;
					}
					for(i=twoLines3[8];i>endStation;i--)		//13���ߣ���ֱ�ţ�
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addlineN[2]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
				}
				else								//13���߻���2���ߣ��ٻ���1���ߣ��ٻ���8����
				{
					for(i=startStation-1;i>=twoLines1[2];i--)		//13���ߣ���ֱ�ţ�
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[0]+=addlineTemp;
						addlineN[1]+=addlineTemp;
					}
					for(i=startStation;i<=twoLines1[6];i++)			//13���ߣ���ֱ�ţ�
					{
						addlineTemp.Format("%d-%d ",startlineNum,i);
						addlineN[2]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines1[4];i<=twoLines2[2];i++)			//2���ߣ���ֱ�ŵ������ţ�
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[0]+=addlineTemp;
						addlineN[1]+=addlineTemp;
					}
					for(i=twoLines1[8];i>=twoLines2[7];i--)			//2���ߣ���ֱ�ŵ������ţ�
					{
						addlineTemp.Format("%d-%d ",lineRelation1,i);
						addlineN[2]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines2[5];i<=twoLines3[2];i++)			//1���ߣ������ŵ��Ļݣ�
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[0]+=addlineTemp;
					}
					for(i=twoLines2[5];i<=twoLines3[6];i++)			//1���ߣ������ŵ��Ļݶ���
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[1]+=addlineTemp;
					}
					for(i=twoLines2[9];i<=twoLines3[2];i++)			//1���ߣ������ŵ��Ļݣ�
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[2]+=addlineTemp;
					}
					for(i=twoLines2[9];i<=twoLines3[6];i++)			//1���ߣ������ŵ��Ļݶ���
					{
						addlineTemp.Format("%d-%d ",lineRelation2,i);
						addlineN[3]+=addlineTemp;
					}
					for(i=twoLines3[4];i<=endStation;i++)			//8���ߣ��Ļݣ�
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addlineN[0]+=addlineTemp;
						addlineN[2]+=addlineTemp;
					}
					for(i=twoLines3[8];i<=endStation;i++)			//8���ߣ��Ļݶ���
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addlineN[1]+=addlineTemp;
						addlineN[3]+=addlineTemp;
					}
				}
			}
		}
		break;
	case 2:													//�յ��ǽ���
		solution=1;
		if(startlineNum==endline1 || startlineNum==endline2)//������յ���ͬһ��·
		{
			if(1==startlineNum)								//������յ�ͬ��1����
			{
				endlineNum=1;
				if("fuxingmen"==endEName)					//�յ��ڸ�����
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
				else if("jianguomen"==endEName)				//�յ��ڽ�����
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
				else if("sihui"==endEName)					//�յ����Ļ�
				{
					endStation=20;
				}
				else										//�յ����Ļݶ�
				{
					endStation=21;
				}
			}
			else if(2==startlineNum)						//������յ�ͬ��2����
			{
				endlineNum=2;
				if("fuxingmen"==endEName)					//�յ��ڸ�����
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
				else if("jianguomen"==endEName)				//�յ��ڽ�����
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
				else if("dongzhimen"==endEName)				//�յ��ڶ�ֱ��
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
				else										//�յ�����ֱ��
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
			else if(8==startlineNum)						//������յ�ͬ��8����
			{
				endlineNum=8;
				if("sihui"==endEName)						//�յ����Ļ�
				{
					endStation=1;
				}
				else										//�յ����Ļݶ�
				{
					endStation=2;
				}
			}
			else											//������յ�ͬ��13����
			{
				endlineNum=13;
				if("xizhimen"==endEName)					//�յ�����ֱ��
				{
					endStation=1;
				}
				else										//�յ��ڶ�ֱ��
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
		else												//������յ㲻��ͬһ��·
		{
			if("xizhimen"==endEName)						//�յ�Ϊ��ֱ��
			{
				if(1==startlineNum)							//�����1����
				{
					if(startStation<=10)					//�����1���߸���������
					{
						for(i=startStation;i<=10;i++)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
					}
					else									//�����1���߸����Ŷ���
					{
						for(i=startStation-1;i>=11;i--)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
				else										//�����8����
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
			else if("dongzhimen"==endEName)					//�յ�Ϊ��ֱ��
			{
				if(1==startlineNum)							//�����1����
				{
					if(startStation<=16)					//�����1���߽���������
					{
						for(i=startStation;i<=16;i++)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
					}
					else									//�����1���߽����Ŷ���
					{
						for(i=startStation-1;i>=17;i--)
						{
							addlineTemp.Format("%d-%d ",startlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
				else										//�����8����
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
			else if("fuxingmen"==endEName)					//�յ�Ϊ������
			{
				endlineNum=2;
				for(i=startStation-1;i>=1;i--)
				{
					addlineTemp.Format("%d-%d ",startlineNum,i);
					addline+=addlineTemp;
				}
				if(8==startlineNum)							//�����8����
				{
					for(i=20;i>=11;i--)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
				else										//�����13����
				{
					for(i=1;i<=3;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
			else if("jianguomen"==endEName)					//�յ�Ϊ������
			{
				endlineNum=2;
				if(8==startlineNum)							//�����8����
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
				else										//�����13����
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
			else											//�յ�Ϊ�Ļݻ��Ļݶ�
			{
				if(2==startlineNum)							//�����2����
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
				else										//�����13����
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
	case 3:													//����ǽ���
		if(endlineNum==startline1 || endlineNum==startline2)//������յ���ͬһ��·
		{
			int* twoLines=new int[10];
			twoLines=GetLine2(startline1,startline2);		
			if(1==endlineNum)								//������յ�ͬ��1����
			{
				startlineNum=1;
				solution=1;
				if("fuxingmen"==startEName)					//����ڸ�����
				{
					startStation=twoLines[2];
				}
				else if("jianguomen"==startEName)			//����ڽ�����
				{
					startStation=twoLines[6];
				}
				else if("sihui"==startEName)				//������Ļ�
				{
					startStation=twoLines[2];
				}
				else										//������Ļݶ�
				{
					startStation=twoLines[6];
				}
				if(endStation>=startStation)				//�յ�����㶫��
				{
					for(i=startStation+1;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
				else										//�յ����������
				{
					for(i=startStation;i>endStation;i--)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
			}
			else if(2==endlineNum)							//������յ�ͬ��2����
			{
				startlineNum=2;
				solution=2;
				addlineN=new CString[solution];
				if("xizhimen"==startEName)					//�������ֱ��
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
				else if("dongzhimen"==startEName)			//����ڶ�ֱ��
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
				else if("jianguomen"==startEName)			//����ڽ�����
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
				else										//����ڸ�����
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
			else if(8==endlineNum)							//������յ�ͬ��8����
			{
				startlineNum=8;
				solution=1;
				int* twoLines=new int[10];
				twoLines=GetLine2(startline1,startline2);
				if("sihui"==startEName)						//������Ļ�
				{
					startStation=twoLines[4];
				}
				else										//������Ļݶ�
				{
					startStation=twoLines[8];
				}
				for(i=startStation;i<=endStation;i++)
				{
					addlineTemp.Format("%d-%d ",endlineNum,i);
					addline+=addlineTemp;
				}
			}
			else											//������յ�ͬ��13����
			{
				startlineNum=13;
				solution=1;
				if("xizhimen"==startEName)					//�������ֱ��
				{
					startStation=1;
					for(i=startStation;i<=endStation;i++)
					{
						addlineTemp.Format("%d-%d ",endlineNum,i);
						addline+=addlineTemp;
					}
				}
				else										//����ڶ�ֱ��
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
		else												//������յ㲻��ͬһ��·
		{
			if("xizhimen"==startEName)				//���Ϊ��ֱ��
			{
				startlineNum=2;
				solution=1;
				startStation=1;
				for(i=startStation;i<=3;i++)
				{
					addlineTemp.Format("%d-%d ",startlineNum,i);
					addline+=addlineTemp;
				}
				if(1==endlineNum)					//�յ���1����
				{
					if(endStation<=10)				//1���߸���������
					{
						for(i=10;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
					else							//1���߸����Ŷ���
					{
						for(i=11;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
				else								//�յ���8����
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
			else if("dongzhimen"==startEName)		//���Ϊ��ֱ��
			{
				startlineNum=2;
				solution=1;
				startStation=13;
				for(i=startStation;i>=11;i--)
				{
					addlineTemp.Format("%d-%d ",startlineNum,i);
					addline+=addlineTemp;
				}
				if(1==endlineNum)					//�յ���1����
				{
					if(endStation<=16)				//�յ��ڽ���������
					{
						for(i=16;i>endStation;i--)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
					else							//�յ��ڽ����Ŷ���
					{
						for(i=17;i<=endStation;i++)
						{
							addlineTemp.Format("%d-%d ",endlineNum,i);
							addline+=addlineTemp;
						}
					}
				}
				else								//�յ���8����
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
			else if("fuxingmen"==startEName)		//���Ϊ������
			{
				if(8==endlineNum)					//�յ���8����
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
				else								//�յ���13����
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
			else if("jianguomen"==startEName)		//���Ϊ������
			{
				if(8==endlineNum)					//�յ���8����
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
				else								//�յ���13����
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
			else			//���Ϊ�Ļݻ��Ļݶ�
			{
				startlineNum=1;
				solution=1;
				if("sihui"==startEName)				//�Ļ�
				{
					startStation=20;
				}
				else								//�Ļݶ�
				{
					startStation=21;
				}
				for(i=startStation;i>=17;i--)
				{
					addlineTemp.Format("%d-%d ",startlineNum,i);
					addline+=addlineTemp;
				}
				if(2==endlineNum)					//�յ���2����
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
				else								//�յ���13����
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
		//�����յ�ͬ��2����
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
		//�����2���ߣ��յ㲻��2����
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
		//��㲻��2���ߣ��յ���2����
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
		//�����յ㶼����2����
		else
		{
			startlineNum=1;
			endlineNum=1;
			if("sihui"==startEName)				//�Ļݵ��Ļݶ�
			{
				addlineTemp.Format("%d-%d ",1,21);
				addline+=addlineTemp;
			}
			else								//�Ļݶ����Ļ�
			{
				addlineTemp.Format("%d-%d ",1,21);
				addline+=addlineTemp;
			}
		}
		break;
	default :
		break;
	}

	//������ַ�����ӵ��б����
	((CListBox*)GetDlgItem(IDC_LIST1))->ResetContent();	//�����ǰ������
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
    //��ȡintersectionLines.txt�ļ���temp_intersectionLinesAll��
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
    //��ȡ<line1,line2>֮����ַ���strResults
	CString strLine;
	strLine.Format("<%d,%d>",line1,line2);
	intersectionLinesPos1=temp_intersectionLinesAll.Find(strLine);
	intersectionLinesPos2=temp_intersectionLinesAll.Find(strLine,intersectionLinesPos1+strlen(strLine));
	strResults=temp_intersectionLinesAll.Mid(intersectionLinesPos1+strlen(strLine),intersectionLinesPos2-intersectionLinesPos1-strlen(strLine));
    //��strResults�е�����ת��Ϊһ������results�������
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
	//��GElinepart.txt�е��ַ���Ѱ�������Ӷ�����λ��
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
	//��ȡ��ö�·����ص�վ������
	name[0]=temp_linepartAll.Mid(posTemp1+1,linepartPos-posTemp1-2);
	posTemp2=temp_linepartAll.Find('>',linepartPos);
	name[1]=temp_linepartAll.Mid(linepartPos+strlen(linepart)+2,posTemp2-linepartPos-strlen(linepart)-2);
	
	int interTemp1,interTemp2;
	interTemp1=temp_intersectionAll.Find(name[0]);
	interTemp2=temp_intersectionAll.Find(name[1]);
	//�ж�վ�������Ƿ�Ϊ���㣬���򷵻ؽ�����
	if(-1==interTemp1 && -1==interTemp2)		//�Ӷ�����վ�㶼���ǽ���
	{
		insectName="";
	}
	else if(-1==interTemp1 && -1!=interTemp2)	//�Ӷ��յ��ǽ���
	{
		insectName=name[1];
	}
	else if(-1!=interTemp1 && -1==interTemp2)	//�Ӷ�����ǽ���
	{
		insectName=name[0]; 
	}
	else										//�Ӷ�����վ�㶼�ǽ���
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
	//ȷ����������ĵ�һ��Ԫ��
	for(int i=0;i<=3;i++)
	{
		if(lineNum[i]<=lineNum[0])
		{
			orderTemp=lineNum[0];
			lineNum[0]=lineNum[i];
			lineNum[i]=orderTemp;
		}
	}
	//ȷ����������ĵڶ���Ԫ��
	for(i=1;i<=3;i++)
	{
		if(lineNum[i]<=lineNum[1])
		{
			orderTemp=lineNum[1];
			lineNum[1]=lineNum[i];
			lineNum[i]=orderTemp;
		}
	}
	//ȷ����������ĵ�����Ԫ��
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
	resultlineTemp[0]=addline.Find("1-");		//���Ұ���1���ߵ��׸��Ӷ�λ��
	resultlineTemp[1]=addline.Find("2-");		//���Ұ���2���ߵ��׸��Ӷ�λ��
	resultlineTemp[2]=addline.Find("8-");		//���Ұ���8���ߵ��׸��Ӷ�λ��
	resultlineTemp[3]=addline.Find("13-");		//���Ұ���13�����׸����Ӷ�λ��
	int* resultline=new int[4];
	resultline=OrderLine(resultlineTemp);		//�Ӷ�λ����������
	if(resultline[3]<0)
	{
		AfxMessageBox("�ڲ�����");
	}
	else if(resultline[2]<0)					//����0��
	{
		CString line1;
		int lineTemp1;
		lineTemp1=addline.Find("-",resultline[3]);
		//������·����
		line1=addline.Mid(resultline[3],lineTemp1-resultline[3]);
		linesList.Format("%s����ֱ��",line1);
	}
	else if(resultline[1]<0)					//����1��
	{
		int resultPos1;
		CString line1,line2;
		int lineTemp1,lineTemp2;
		CString convertNum,convertName,resultName;
		resultPos1=addline.Find(" ",resultline[3]);
		convertNum=addline.Mid(resultline[3],resultPos1-resultline[3]);
		convertName=GetInsection(convertNum);
		resultName=FormatName(convertName);		//����վ������
		lineTemp1=addline.Find("-",resultline[2]);
		lineTemp2=addline.Find("-",resultline[3]);
		//������·1����·2����
		line1=addline.Mid(resultline[2],lineTemp1-resultline[2]);
		line2=addline.Mid(resultline[3],lineTemp2-resultline[3]);
		linesList.Format("���ȳ���%s���ߣ���%s�³���Ȼ�󻻳�%s����",line1,resultName,line2);
	}
	else if(resultline[0]<0)					//����2��
	{
		int resultPos1,resultPos2;
		CString line1,line2,line3;
		int lineTemp1,lineTemp2,lineTemp3;
		CString convertNum1,convertName1,resultName1;
		CString convertNum2,convertName2,resultName2;
		resultPos1=addline.Find(" ",resultline[2]);
		convertNum1=addline.Mid(resultline[2],resultPos1-resultline[2]);
		convertName1=GetInsection(convertNum1);
		resultName1=FormatName(convertName1);	//����վ��1����
		resultPos2=addline.Find(" ",resultline[3]);
		convertNum2=addline.Mid(resultline[3],resultPos2-resultline[3]);
		convertName2=GetInsection(convertNum2);
		resultName2=FormatName(convertName2);	//����վ��2����
		lineTemp1=addline.Find("-",resultline[1]);
		lineTemp2=addline.Find("-",resultline[2]);
		lineTemp3=addline.Find("-",resultline[3]);
		//������·1��2��3����
		line1=addline.Mid(resultline[1],lineTemp1-resultline[1]);
		line2=addline.Mid(resultline[2],lineTemp2-resultline[2]);
		line3=addline.Mid(resultline[3],lineTemp3-resultline[3]);
		linesList.Format("���ȳ���%s���ߣ���%s�³���Ȼ�󻻳�%s���ߣ���%s�³����ٻ���%s����",line1,resultName1,line2,resultName2,line3);
	}
	else										//����3��
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
		resultName1=FormatName(convertName1);	//����վ��1����

		resultPos2=addline.Find(" ",resultline[2]);
		convertNum2=addline.Mid(resultline[2],resultPos2-resultline[2]);
		convertName2=GetInsection(convertNum2);
		resultName2=FormatName(convertName2);	//����վ��2����

		resultPos3=addline.Find(" ",resultline[3]);
		convertNum3=addline.Mid(resultline[3],resultPos3-resultline[3]);
		convertName3=GetInsection(convertNum3);
		resultName3=FormatName(convertName3);	//����վ��3����

		lineTemp1=addline.Find("-",resultline[0]);
		lineTemp2=addline.Find("-",resultline[1]);
		lineTemp3=addline.Find("-",resultline[2]);
		lineTemp4=addline.Find("-",resultline[3]);
		//������·1��2��3��4����
		line1=addline.Mid(resultline[0],lineTemp1-resultline[0]);
		line2=addline.Mid(resultline[1],lineTemp2-resultline[1]);
		line3=addline.Mid(resultline[2],lineTemp3-resultline[2]);
		line4=addline.Mid(resultline[3],lineTemp4-resultline[3]);
		linesList.Format("���ȳ���%s���ߣ���%s�³���Ȼ�󻻳�%s���ߣ���%s�³����ٻ���%s���ߣ���%s�³�����󻻳�%s����",line1,resultName1,line2,resultName2,line3,resultName3,line4);
	}
	return linesList;
}

CString CSample17Dlg::FormatName(CString name)
{
	int namePos,namePos1,namePos2;
	CString formatname;
	//��language.txt���ַ����в��������վ������ 
	namePos=temp_languageAll.Find(name);
	namePos1=temp_languageAll.Find("/",namePos);
	namePos2=temp_languageAll.Find(">",namePos);
	formatname=temp_languageAll.Mid(namePos1+1,namePos2-namePos1-1);
	return formatname;
}

void CSample17Dlg::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	//�ж��Ƿ������˿ͻ���
	if(FALSE==m_active)
	{
		AfxMessageBox("�ͻ���δ������");
		return;
	}	
	CString* addlines;
	IFeatureGE* feature;
	int count;
	int i;
	//���ǰ�����ʾ
	IFeatureGE oldFeature;
	IFeatureGE startFeature,endFeature;
	IFeatureGE* oldfeature;
	IFeatureCollectionGE oldCollect;
	//��ȡTemporary Places�ļ����е�Ҫ�� 
	oldFeature=m_geApplication.GetTemporaryPlaces();
	oldCollect=oldFeature.GetChildren();
	oldfeature=new IFeatureGE[oldCollect.GetCount()];
	for(i=0;i<oldCollect.GetCount();i++)
	{
		oldfeature[i]=oldCollect.GetItem(i+1);
		oldfeature[i].SetVisibility(FALSE);
	}
    //���ݷ��������ʾ��Ӧ���Ӷ�Ҫ��
	if(1==solution)
	{
		addlines=GetFilename(addline);		//����GetFilename��ȡ�Ӷ���
		count=atoi(addlines[0]);			//��ȡҪ��ʾ���Ӷ���
		feature=new IFeatureGE[count-1];
		for(i=1;i<count;i++)
		{
			feature[i-1]=m_geApplication.GetFeatureByName(addlines[i]);
			feature[i-1].SetVisibility(TRUE);
		}
		startFeature=m_geApplication.GetFeatureByName(m_startName);
		endFeature=m_geApplication.GetFeatureByName(m_endName);
		startFeature.SetVisibility(TRUE);	//��ʾ���վ�ĵر�
		endFeature.SetVisibility(TRUE);		//��ʾ�յ�վ�ĵر�
	}
	else
	{
		int item=((CListBox*)GetDlgItem(IDC_LIST1))->GetCurSel();
		addlines=GetFilename(addlineN[item]);
		count=atoi(addlines[0]);			//��ȡҪ��ʾ���Ӷ���
		feature=new IFeatureGE[count-1];
		for(i=1;i<count;i++)
		{
			feature[i-1]=m_geApplication.GetFeatureByName(addlines[i]);
			feature[i-1].SetVisibility(TRUE);
		}
		startFeature=m_geApplication.GetFeatureByName(m_startName);
		endFeature=m_geApplication.GetFeatureByName(m_endName);
		startFeature.SetVisibility(TRUE);	//��ʾ���վ�ĵر�
		endFeature.SetVisibility(TRUE);		//��ʾ�յ�վ�ĵر�
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
	for(int i=0;i<len;i++)			//��ȡ�ӶεĶ���
	{
		if(' '==addline.GetAt(i))
			num++;
	}
	resultsTemp=new CString[num+1];
	results=new CString[num+1];
	int* namepos=new int[num];
	namepos[0]=-1;
	for(i=1;i<num;i++)				//��ȡÿ���Ӷ����ַ����е�λ��
	{
		namepos[i]=addline.Find(" ",namepos[i-1]+1);
	}
	//���Ӷ�����һ��ֵ��resultsTemp��
	for(i=0;i<num-1;i++)
	{
		resultsTemp[i]=addline.Mid(namepos[i]+1,namepos[i+1]-namepos[i]-1);
	}
	resultsTemp[num-1]=addline.Mid(namepos[num-1]+1,len-namepos[num-1]-2);
	temp.Format("%d",num+1);
	resultsTemp[num]=temp;
	//results����ĵ�һ��Ԫ�ؼ�¼������Ĵ�С			
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
	//�ж��Ƿ������˿ͻ���
	if(FALSE==m_active)
	{
		AfxMessageBox("�ͻ���δ������");
		return;
	}	
	//��ʼ����ͼ
	m_geApplication.SetCameraParams(39.961489,116.404267,20.0,2,44880.0,0.0,0.0,4.5);
	IFeatureGE allFeature;
	IFeatureGE* allfeature;
	IFeatureCollectionGE allCollect;
	allFeature=m_geApplication.GetTemporaryPlaces();		    //��ȡTemporary Places�ļ����е�����
	allCollect=allFeature.GetChildren();
	allfeature=new IFeatureGE[allCollect.GetCount()];
	//��ʾ��ʾ�����ߵ�KML�ļ�
	for(int i=0;i<allCollect.GetCount();i++)
	{
		allfeature[i]=allCollect.GetItem(i+1);
		if(-1!=(allfeature[i].GetName()).Find("-"))
			allfeature[i].SetVisibility(TRUE);
	}	
}
