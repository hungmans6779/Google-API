// sample13View.cpp : implementation of the CSample13View class
//

#include "stdafx.h"
#include "sample13.h"

#include "sample13Doc.h"
#include "sample13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <math.h>
#include "SEARCH.h"
#include "RECORDS.h"
static const double corA=6378137.0;
static const double corE2=0.00669437999013;
static const CLSID CLSID_ApplicationGE = {0x8097D7E9,0xDB9E,0x4AEF, {0x9B,0x28,0x61,0xD8,0x2A,0x1D,0xF7,0x84}}; 
/////////////////////////////////////////////////////////////////////////////
// CSample13View

IMPLEMENT_DYNCREATE(CSample13View, CView)

BEGIN_MESSAGE_MAP(CSample13View, CView)
	//{{AFX_MSG_MAP(CSample13View)
	ON_COMMAND(IDC_EXIT, OnExit)
	ON_COMMAND(IDC_SEARCH, OnSearch)
	ON_COMMAND(IDC_START, OnStart)
	ON_COMMAND(IDC_RECORDS, OnRecords)
	ON_COMMAND(IDC_VISIBLE, OnVisible)
	ON_COMMAND(IDC_CLEARRESULTS, OnClearresults)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample13View construction/destruction

CSample13View::CSample13View()
{
	// TODO: add construction code here
    ::CoInitialize(NULL);
	m_active=FALSE;
	isVisible=FALSE;
	count=0;
	memset((void*)m_geLat,0,100);
	memset((void*)m_geLon,0,100);
}

CSample13View::~CSample13View()
{
}

BOOL CSample13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSample13View drawing

void CSample13View::OnDraw(CDC* pDC)
{
	CSample13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int Width,Height;
	int i;
	double m_scalex,m_scaley;
    //�����e���f���e�שM����
	CRect rect;
	this->GetWindowRect(&rect);
	Width=rect.Width()-100;
	Height=rect.Height()-50;
	CPen Mypen,*p_pen;
	Mypen.CreatePen(PS_SOLID,2,RGB(255,0,0));

	double m_xMax,m_yMax,m_xMin,m_yMin;
	CPoint m_point;
	CPoint m_Orgpoint;
	if(TRUE==isVisible)				//�P�_�O�_�㦳�i��������
	{
        //��l�Ƨ��Ъ��̭�
		m_xMax=m_x[0];
		m_yMax=m_y[0];
		m_xMin=m_x[0];
		m_yMin=m_y[0];
		//�d��Ҧ���m�I���Ъ��̭�
		for(i=0;i<count;i++)
		{
			if(m_x[i]>m_xMax)
				m_xMax=m_x[i];
			if(m_x[i]<m_xMin)
				m_xMin=m_x[i];
			if(m_y[i]>m_yMax)
				m_yMax=m_y[i];
			if(m_y[i]<m_yMin)
				m_yMin=m_y[i];			
		}
		//�ھڳ̭ȩM���f�j�p���s�w�qø�s����Ҥ�
		m_scalex=Width/(m_xMax-m_xMin);
		m_scaley=Height/(m_yMax-m_yMin);
		m_Orgpoint.x=(int)((m_x[0]-m_xMin)*m_scalex);
		m_Orgpoint.y=(int)((m_y[0]-m_yMin)*m_scaley);
		//����ø�s�ϧΪ��ާ@
		for(i=1;i<count;i++)
		{
			m_point.x=(int)((m_x[i]-m_xMin)*m_scalex);
			m_point.y=(int)((m_y[i]-m_yMin)*m_scaley);
			pDC->MoveTo(m_Orgpoint);
			pDC->LineTo(m_point);
			pDC->TextOut(m_Orgpoint.x,m_Orgpoint.y,m_str[i-1]);
			m_Orgpoint=m_point;
		}
		//��X��m���W��
		pDC->TextOut(m_Orgpoint.x,m_Orgpoint.y,m_str[count-1]);
		p_pen=pDC->SelectObject(&Mypen);
	}
	Mypen.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CSample13View printing

BOOL CSample13View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSample13View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSample13View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSample13View diagnostics

#ifdef _DEBUG
void CSample13View::AssertValid() const
{
	CView::AssertValid();
}

void CSample13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample13Doc* CSample13View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample13Doc)));
	return (CSample13Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample13View message handlers

void CSample13View::OnExit() 
{
	// TODO: Add your command handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//�ĥ�Windows�����������Google Earth�Ȥ��
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}

void CSample13View::OnSearch() 
{
	// TODO: Add your command handler code here
	ISearchControllerGE searchControl;
	searchControl.AttachDispatch(m_geApplication.GetSearchController(),TRUE);

	CSEARCH searchDlg;
	if(IDOK==searchDlg.DoModal())
	{
		strSearch=searchDlg.m_strSearch;	//�����J���j���r�Ŧ�
	}
	searchControl.Search(strSearch);		//����j���ާ@
}

void CSample13View::OnStart() 
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
	}	
}


void CSample13View::OnRecords() 
{
	// TODO: Add your command handler code here
	//�קK�~�ާ@
	if(FALSE==m_active)
	{
		AfxMessageBox("�Ȥ�ݥ��ҰʡI");
		return;
	}

	//�����e�̹������I���a�z���СA�ëO�s�b�Ʋդ�
	IPointOnTerrainGE m_gePotTerrain;
	m_gePotTerrain.AttachDispatch(m_geApplication.GetPointOnTerrainFromScreenCoords(0.0,0.0));
    m_geLat[count]=m_gePotTerrain.GetLatitude();
	m_geLon[count]=m_gePotTerrain.GetLongitude();
	m_geAlt[count]=m_gePotTerrain.GetAltitude();

	//�g�n���ഫ���������ЧΦ�
	double N;
	N=sqrt(1-corE2*sin(m_geLat[count])*sin(m_geLat[count]));
	N=corA/N;
	m_x[count]=(N+m_geAlt[count])*(cos(m_geLat[count]))*(cos(m_geLon[count]));
	m_y[count]=(N+m_geAlt[count])*(cos(m_geLat[count]))*(sin(m_geLon[count]));

	//�O����e��m���W��
	CRECORDS recordDlg;
	recordDlg.m_count=count;
	recordDlg.m_records=strSearch;		//��s��e�O���ƥ�
	if(IDOK==recordDlg.DoModal())
	{
		m_str[count]=recordDlg.m_records;
	}

	count++;
}

double CSample13View::distance(double x1, double y1, double x2, double y2)
{
	double dis;
	dis=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
	dis=sqrt(dis);
	return dis;
}

void CSample13View::OnVisible() 
{
	// TODO: Add your command handler code here
	//�קK�D�k�ާ@
	if(count>0)
	{
		isVisible=TRUE;
	}
	else
	{
		AfxMessageBox("�D�k�ާ@�I");
		return;
	}	
	CClientDC dc(this);
	int Width,Height;
	int i;
	double m_scalex,m_scaley;
	//�����e���f���e�שM����
	CRect rect;
	this->GetWindowRect(&rect);
	Width=rect.Width()-100;
	Height=rect.Height()-50;
	CPen Mypen,*p_pen;
	Mypen.CreatePen(PS_SOLID,2,RGB(255,0,0));

	double m_xMax,m_yMax,m_xMin,m_yMin;
	CPoint m_point;
	CPoint m_Orgpoint;
	//��l�Ƨ��Ъ��̭�
	m_xMax=m_x[0];
	m_yMax=m_y[0];
	m_xMin=m_x[0];
	m_yMin=m_y[0];
	//�d��Ҧ���m�I���Ъ��̭�
	for(i=0;i<count;i++)
	{
		if(m_x[i]>m_xMax)
			m_xMax=m_x[i];
		if(m_x[i]<m_xMin)
			m_xMin=m_x[i];
		if(m_y[i]>m_yMax)
			m_yMax=m_y[i];
		if(m_y[i]<m_yMin)
			m_yMin=m_y[i];			
	}
	//�ھڳ̭ȩM���f�j�p���s�w�qø�s����Ҥ�
	m_scalex=Width/(m_xMax-m_xMin);
	m_scaley=Height/(m_yMax-m_yMin);
	m_Orgpoint.x=(int)((m_x[0]-m_xMin)*m_scalex);
	m_Orgpoint.y=(int)((m_y[0]-m_yMin)*m_scaley);
	//����ø�s�ϧΪ��ާ@
	for(i=1;i<count;i++)
	{
		m_point.x=(int)((m_x[i]-m_xMin)*m_scalex);
		m_point.y=(int)((m_y[i]-m_yMin)*m_scaley);
		dc.MoveTo(m_Orgpoint);
		dc.LineTo(m_point);
		dc.TextOut(m_Orgpoint.x,m_Orgpoint.y,m_str[i-1]);
		m_Orgpoint=m_point;
	}
	//��X��m���W��
	dc.TextOut(m_Orgpoint.x,m_Orgpoint.y,m_str[count-1]);
	p_pen=dc.SelectObject(&Mypen);
	Mypen.DeleteObject();	
}

void CSample13View::OnClearresults() 
{
	// TODO: Add your command handler code here
	if(count>0)						//���O���h�M��
	{
		for(int i=0;i<count;i++)
		{
			m_geLat[count]=0.0;
			m_geLon[count]=0.0;
			m_geAlt[count]=0.0;
			m_x[i]=0.0;
			m_y[i]=0.0;
		}
		count=0;
		isVisible=FALSE;			//�������OnDraw()���
	}
	else							//�L�O���h��^
	{
		AfxMessageBox("�D�k�ާ@�I");
		return;
	}
}
