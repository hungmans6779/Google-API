// sample6View.cpp : implementation of the CSample6View class
//

#include "stdafx.h"
#include "sample6.h"

#include "sample6Doc.h"
#include "sample6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static const CLSID CLSID_ApplicationGE = {0x8097D7E9,0xDB9E,0x4AEF, {0x9B,0x28,0x61,0xD8,0x2A,0x1D,0xF7,0x84}};
/////////////////////////////////////////////////////////////////////////////
// CSample6View

IMPLEMENT_DYNCREATE(CSample6View, CView)

BEGIN_MESSAGE_MAP(CSample6View, CView)
	//{{AFX_MSG_MAP(CSample6View)
	ON_COMMAND(IDC_START, OnStart)
	ON_COMMAND(IDC_OPEN, OnOpen)
	ON_COMMAND(IDC_ADJUST, OnAdjust)
	ON_COMMAND(IDC_SAVE, OnSave)
	ON_COMMAND(IDC_EXIT, OnExit)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample6View construction/destruction

CSample6View::CSample6View()
{
	// TODO: add construction code here
    ::CoInitialize(NULL);
	m_active=FALSE;
}

CSample6View::~CSample6View()
{
}

BOOL CSample6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSample6View drawing

void CSample6View::OnDraw(CDC* pDC)
{
	CSample6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSample6View printing

BOOL CSample6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSample6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSample6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSample6View diagnostics

#ifdef _DEBUG
void CSample6View::AssertValid() const
{
	CView::AssertValid();
}

void CSample6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample6Doc* CSample6View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample6Doc)));
	return (CSample6Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample6View message handlers

void CSample6View::OnStart() 
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

void CSample6View::OnOpen() 
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

void CSample6View::OnAdjust() 
{
	// TODO: Add your command handler code here
	if(FALSE==m_active)
	{
		AfxMessageBox("�Ȥ�ݥ��ҰʡI");
		return;
	}
	//�ЫثD�ҺA��ܮ�
	pAdjustDlg=new CADJUSTDLG();
	pAdjustDlg->Create(IDD_ADJUSTDLG,this);
	pAdjustDlg->m_slide1.SetPos(50);	//��l�Ʒƶ���
	pAdjustDlg->m_slide3.SetPos(50);
	pAdjustDlg->ShowWindow(SW_SHOW);	//��ܹ�ܮ�

	m_geCamera=m_geApplication.GetCamera(TRUE);
	oldRange=m_geCamera.GetRange();		//�����e����
	SetTimer(1,2000,NULL);				//�Ұʩw�ɾ��A�]�m�w�ɾ����T���ɶ���2��

}

void CSample6View::OnSave() 
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

void CSample6View::OnExit() 
{
	// TODO: Add your command handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//�ĥ�Windows�����������Google Earth�Ȥ��
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();	
}

void CSample6View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//����ƶ���
	dlgRange=pAdjustDlg->m_slide1.GetPos();
	dlgTilt=(pAdjustDlg->m_slide2.GetPos()*90)/100;
	dlgAzimuth=((pAdjustDlg->m_slide3.GetPos()-50)*180)/50;
	if(dlgRange>50)
	{
		geMutiple=((dlgRange-50)/10.0+1.0)*10;	 //�p���Y�p����
	}
	else if(dlgRange<50)
	{
		geMutiple=(10.0/((50-dlgRange)+10))*0.1; //�p���j����	
	}
	else
	{
		geMutiple=1.0;
	}

	BOOL m_geTimer;								 //m_geTimer�Ψӱ���Timer()���
	m_geTimer=pAdjustDlg->IsTimer;               //�P�_�O�_����վ�ާ@

	if(m_geTimer==FALSE)
	{
		KillTimer(1);							 //�����w�ɾ�
	}
	m_geCamera.SetRange(geMutiple*oldRange);     //���s�]�m��e����
	m_geCamera.SetTilt((double)dlgTilt);		 //���s�]�m��e�ɱ׵���
	m_geCamera.SetAzimuth((double)dlgAzimuth);   //���s�]�m��e������
	m_geApplication.SetCamera(m_geCamera,1.5);   //��s����
	CView::OnTimer(nIDEvent);
}
