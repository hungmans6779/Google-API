// sample7View.cpp : implementation of the CSample7View class
//

#include "stdafx.h"
#include "sample7.h"

#include "sample7Doc.h"
#include "sample7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static const CLSID CLSID_ApplicationGE = {0x8097D7E9,0xDB9E,0x4AEF, {0x9B,0x28,0x61,0xD8,0x2A,0x1D,0xF7,0x84}}; 
/////////////////////////////////////////////////////////////////////////////
// CSample7View

IMPLEMENT_DYNCREATE(CSample7View, CView)

BEGIN_MESSAGE_MAP(CSample7View, CView)
	//{{AFX_MSG_MAP(CSample7View)
	ON_COMMAND(IDC_START, OnStart)
	ON_COMMAND(IDC_OPEN, OnOpen)
	ON_COMMAND(IDC_SAVE, OnSave)
	ON_COMMAND(IDC_CHANGE, OnChange)
	ON_COMMAND(IDC_EXIT, OnExit)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample7View construction/destruction

CSample7View::CSample7View()
{
	// TODO: add construction code here
    ::CoInitialize(NULL);
}

CSample7View::~CSample7View()
{
}

BOOL CSample7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSample7View drawing

void CSample7View::OnDraw(CDC* pDC)
{
	CSample7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSample7View printing

BOOL CSample7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSample7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSample7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSample7View diagnostics

#ifdef _DEBUG
void CSample7View::AssertValid() const
{
	CView::AssertValid();
}

void CSample7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample7Doc* CSample7View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample7Doc)));
	return (CSample7Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample7View message handlers

void CSample7View::OnStart() 
{
	// TODO: Add your command handler code here
	if(TRUE==m_active)
	{
		AfxMessageBox("�Ȥ�ݤw�g�ҰʡI");
		return;
	}
    m_active=TRUE;
	if(m_geApplication.IsInitialized())
	{
		m_geApplication.CreateDispatch(CLSID_ApplicationGE,NULL);
		if(!m_geApplication.IsOnline())
		{
			AfxMessageBox("�w�g�s���W�A�Ⱦ��I");
		}
	}		
}

void CSample7View::OnOpen() 
{
	// TODO: Add your command handler code here
	if(FALSE==m_active)
	{
		AfxMessageBox("�Ȥ�ݥ��ҰʡI");
		return;
	}

	CFileDialog geOpenDlg(TRUE);			//��l�Ƥ@�ӥ��}��ܮت���H
	geOpenDlg.m_ofn.lpstrTitle="Goolge Earth��󥴶}��ܮ�";
	geOpenDlg.m_ofn.lpstrFilter="KML Files(*.kml)\0*.kml\0All Files(*.*)\0*.*\0\0";
    //����KML��󪺥��}�ާ@
	if(IDOK==geOpenDlg.DoModal())
	{
		m_geApplication.OpenKmlFile(geOpenDlg.GetPathName(),TRUE);
	}	
}

void CSample7View::OnSave() 
{
	// TODO: Add your command handler code here
	if(FALSE==m_active)
	{
		AfxMessageBox("�Ȥ�ݥ��ҰʡI");
		return;
	}

	CFileDialog geSaveDlg(FALSE);			//��l�Ƥ@�ӫO�s��ܮت���H
	geSaveDlg.m_ofn.lpstrTitle="Goolge Earth�϶H�O�s��ܮ�";
	geSaveDlg.m_ofn.lpstrFilter="JPG Files(*.jpg)\0*.jpg\0All Files(*.*)\0*.*\0\0";	
	geSaveDlg.m_ofn.lpstrDefExt="jpg";
    //�N��e���ϫO�s��JPEG�榡���¥չ϶H
	if(IDOK==geSaveDlg.DoModal())
	{
		m_geApplication.SaveScreenShot(geSaveDlg.GetPathName(),100);
	}	
}

void CSample7View::OnChange() 
{
	// TODO: Add your command handler code here
	int i(0),j(0),k(0);
	//�ЫثD�ҺA��ܮ�
	pChangeDlg=new CCHANGEDLG();
	pChangeDlg->Create(IDD_CHANGEDLG,this);
	pChangeDlg->ShowWindow(SW_SHOW);

	//����W��hubei��kml���
	m_geFeature.AttachDispatch(m_geApplication.GetFeatureByName("hubei"),TRUE);
	//���hubei���n��
	m_geCollection.AttachDispatch(m_geFeature.GetChildren(),TRUE);

	int countUp;
	countUp=m_geCollection.GetCount();	//���hubei��󧨤������ƥ�
    
	int* fileCount;
	fileCount=new int[countUp];
	IFeatureGE* feature;
	feature=new IFeatureGE[countUp];
	IFeatureCollectionGE* collection;
	collection=new IFeatureCollectionGE[countUp];

	for(i=0;i<countUp;i++)
	{
		//���hubei��󤤪��l���n��
		feature[i].AttachDispatch(m_geCollection.GetItem(i+1),TRUE);
		collection[i].AttachDispatch(feature[i].GetChildren(),TRUE);
		//����U�l��󤤪��a�Эn���ƥ�
		fileCount[i]=collection[i].GetCount();
	}
//����a�Эn���`��
	fileSum=0;
	for(i=0;i<countUp;i++)
	{
		fileSum+=fileCount[i];
	}

//���s�w�q�a�Эn���Ʋ�
	bFeature=new IFeatureGE[fileSum];
	for(i=0;i<countUp;i++)
	{
		for(j=0;j<fileCount[i];j++)
		{
			bFeature[k].AttachDispatch(collection[i].GetItem(j+1),TRUE);
			k++;
		}
	}
	
	SetTimer(1,1500,NULL);
}

void CSample7View::OnExit() 
{
	// TODO: Add your command handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//�ĥ�Windows�����������Google Earth�Ȥ��
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}

void CSample7View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//����b��ܮس����i���Ϥ����j���s������
	m_viewCount=pChangeDlg->m_viewCount;

	//�L�om_viewCount��
	int viewItem;
	viewItem=m_viewCount%fileSum;

	if(TRUE==bFeature[viewItem].GetHasView())	//�P�_�ӭn���O�_�i��
	{
		//�N���Ϥ��߲��ʨ�ӭn���Ҧb��m
		m_geApplication.SetFeatureView(bFeature[viewItem],3);
	}
	else
	{
		AfxMessageBox("KML��󤣬O�G�ťؿ��I");
		return;									//�p�G�ӭn�����i���A�h�ڵ����
	}

	//m_geTimer�Ψӱ���Timer()���
	BOOL m_geTimer;
	//�P�_�O�_����վ�ާ@
	m_geTimer=pChangeDlg->IsTimer;
	if(m_geTimer==FALSE)
	{
		KillTimer(1);	//����Timer()���
	}
	CView::OnTimer(nIDEvent);
}
