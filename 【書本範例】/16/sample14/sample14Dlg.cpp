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
		AfxMessageBox("�Ȥ�ݤw�g�ҰʡI");
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
	CString* strSearch;					   //�ΨӫO�s.txt��󤤪��r�Ŧ�
	CString strTemp;
	CString pathName;					   //�����|�W
	int i(0);
	int count(0);
	strTemp="";

	//�]�m���}����ܮ�
	CFileDialog geOpenDlg(TRUE);
	geOpenDlg.m_ofn.lpstrTitle="�Х��}��q�j�����ƾڤ��";
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

	//Ū����󪺷j���r�Ŧ�ƥ�
	while(file.ReadString(strTemp))
	{
		count++;
	}
	file.Close();
	//���s���}���A����j���r�Ŧ�
	file.Open(pathName,CFile::modeRead);
	strSearch=new CString[count];
	while(file.ReadString(strTemp))
	{
		//�N�j���r�Ŧ�O�s�bstrSearch�Ʋդ�
		strSearch[i]=strTemp;
		i++;
	}
	file.Close();

	//�}�l�j��
	m_geSearchControl.AttachDispatch(m_geApplication.GetSearchController(),TRUE);
	for(i=0;i<count;i++)
	{
		m_geSearchControl.Search(strSearch[i]);
	}

	i=0;
	IFeatureCollectionGE collect;
	strCount+=count;					   //����h�Ӥ�󪺷j���r�Ŧꤧ�M
	while(i<strCount)
	{
		//����j�����G���n�����X
		collect=m_geSearchControl.GetResults();
		i++;
	}

	m_geFeature=new IFeatureGE[strCount];
	//�C�����}�s�����A�M�ťH�e���C��ؤ��e
	((CListBox*)GetDlgItem(IDC_LIST1))->ResetContent();
	//�N�j�����G���X�����n���W�v�@�K�[��C��ؤ�
	for(i=0;i<strCount;i++)
	{
		m_geFeature[i]=collect.GetItem(i+1);
		((CListBox*)GetDlgItem(IDC_LIST1))->AddString(m_geFeature[i].GetName());
	}

	strFlag=new CString[strCount];		   //�ΨӰO�����ݭn��ܪ��n��
	for(i=0;i<strCount;i++)
	{
		strFlag[i]="";
	}
}

void CSample14Dlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	int i,j;
	//�P�_�O�_�����񤺮e
	if(0==strCount)
	{
		return;
	}
	//���ITourControllerGE��
	m_geTour.AttachDispatch(m_geApplication.GetTourController(),TRUE);
	if(FALSE==isPlay)
	{
		for(i=0;i<strCount;i++)
		{
			//�N���G���X�����Ҧ����e��l�ƨ켽�񤺮e��
			m_geFeature[i].SetVisibility(TRUE);
			for(j=0;j<strCount;j++)
			{
				//�ھڥΤ��ܡA�������ݭn���񪺭n��
				if(0==strcmp(m_geFeature[i].GetName(),strFlag[j]))
				{
					m_geFeature[i].SetVisibility(FALSE);
				}
			}
		}
		m_speed.SetPos(10);				//��l�Ƽ���t��
		m_geFeature[0].Highlight();		//�襤Search���O���Ĥ@�ӭn��
		UpdateData(TRUE);
		//�ھڤ奻�ؤ��e�A�]�m���񪺴`������
		m_geTour.SetCycles(m_cycles);
		//�ھڷƶ��ȡA�]�m����t��
		m_geTour.SetSpeed(m_speed.GetPos()*0.05);
		m_geTour.PlayOrPause();			//���漽��ާ@
		isPlay=TRUE;
	}
}

void CSample14Dlg::OnPause() 
{
	// TODO: Add your control notification handler code here
	//�P�_�O�_�����񤺮e
	if(0==strCount)
	{
		return;
	}
	//�b���񪺹L�{���Ȱ�
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
	//�ĥ�Windows�����������Google Earth�Ȥ��
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}

void CSample14Dlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	int i;
	//�P�_�O�_�����񤺮e
	if(0==strCount)
	{
		return;
	}
    //�b���񪺹L�{������
	if(TRUE==isPlay)
	{
		//�N��e�j�����G���X�����Ҧ��n�������X���񤺮e
		for(i=0;i<strCount;i++)
		{
			m_geFeature[i].SetVisibility(FALSE);
		}
		//�N��e���񪺤��e���s�w���Search����O��
		if(FALSE==m_geFeature[0].GetHighlighted())
		{
			m_geFeature[0].Highlight();
		}
		m_geTour.Stop();					//�����e���ʺA���
		isPlay=FALSE;
	}	
}

void CSample14Dlg::OnRemove() 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("�������C��ؤ��n���������e�I");
	isRemove=TRUE;							//�T�������C��ت��ƥ�
}

void CSample14Dlg::OnClearresults() 
{
	// TODO: Add your control notification handler code here
	//�P�_�C��جO�_����
	if(0==strCount)
	{
		return;
	}
	//�M�ŷj�����G���������e
	m_geSearchControl.ClearResults();
	//�M�ŦC��ؤ������e
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
		//����C��ؤ����������e
		item=((CListBox*)GetDlgItem(IDC_LIST1))->GetCurSel();
		((CListBox*)GetDlgItem(IDC_LIST1))->GetText(item,strItem);
		//�ھ����������e�T�w����ܪ��n��
		for(i=0;i<strCount;i++)
		{
			if(0==strcmp(m_geFeature[i].GetName(),strItem))
			{
				strFlag[i]=strItem;
			}
		}
		//�R���C��ؤ����������e
		((CListBox*)GetDlgItem(IDC_LIST1))->DeleteString(item);
	}
	isRemove=FALSE;					//�@���u�ಾ���@���O��
}
