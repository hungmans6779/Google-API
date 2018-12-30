// sample18View.cpp : implementation of the CSample18View class
//

#include "stdafx.h"
#include "sample18.h"

#include "sample18Doc.h"
#include "sample18View.h"
#include "Drew.h"
#include "Math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static const CLSID CLSID_ApplicationGE = {0x8097D7E9,0xDB9E,0x4AEF, {0x9B,0x28,0x61,0xD8,0x2A,0x1D,0xF7,0x84}}; 
/////////////////////////////////////////////////////////////////////////////
// CSample18View

IMPLEMENT_DYNCREATE(CSample18View, CView)

BEGIN_MESSAGE_MAP(CSample18View, CView)
	//{{AFX_MSG_MAP(CSample18View)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample18View construction/destruction

CSample18View::CSample18View()
{
	// TODO: add construction code here
	Width=776;
	Height=610;
	dia=FALSE;
	m_active=FALSE;
	::CoInitialize(NULL);
}

CSample18View::~CSample18View()
{
}

BOOL CSample18View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSample18View drawing

void CSample18View::OnDraw(CDC* pDC)
{
	CSample18Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSample18View printing

BOOL CSample18View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSample18View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSample18View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSample18View diagnostics

#ifdef _DEBUG
void CSample18View::AssertValid() const
{
	CView::AssertValid();
}

void CSample18View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample18Doc* CSample18View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample18Doc)));
	return (CSample18Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample18View message handlers

void CSample18View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_active==TRUE)
	{
		double x,y;
		x=(double)(point.x-Width/2)/Width;
		y=(double)(610-point.y-Height/2)/Height;
		IPointOnTerrainGE gePoint;		//定義IPointOnTerrainGE類的對象
		//獲取用戶輸入的當前屏幕坐標
		gePoint=m_geApplication.GetPointOnTerrainFromScreenCoords(x,y+0.31);
		mlon=gePoint.GetLongitude();	//獲取地理坐標的經度
		mlat=gePoint.GetLatitude();		//獲取地理坐標的緯度
		AfxMessageBox("已選擇目標點！");
		CView::RedrawWindow(NULL,NULL,RDW_UPDATENOW);
		return;
	}
	
	if(m_geApplication.IsInitialized())
	{
		m_geApplication.CreateDispatch(CLSID_ApplicationGE,NULL);
		AfxMessageBox("已經連接上服務器,請選擇目標點！");
		CView::RedrawWindow(NULL,NULL,RDW_UPDATENOW);
	}
	m_active=TRUE;
	j=1;	
	CView::OnRButtonDown(nFlags, point);
}

void CSample18View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}	
	double x,y;
	double scale;
	x=(double)(point.x-Width/2)/Width;
	y=(double)(610-point.y-Height/2)/Height;
	IPointOnTerrainGE gePoint;		//定義IPointOnTerrainGE類的對象
	//獲取用戶輸入的當前屏幕坐標
	gePoint=m_geApplication.GetPointOnTerrainFromScreenCoords(x,y+0.31);
	double dlon,dlat;
	dlon=gePoint.GetLongitude();	//獲取地理坐標的經度
	dlat=gePoint.GetLatitude();		//獲取地理坐標的緯度
	//將地理坐標轉換為度、分、秒的形式
	if (j==1)
	{
		plon=dlon;			//先前經度
		plat=dlat;			//先前緯度
	}
	tlon=dlon;				//當前經度
	tlat=dlat;				//當前緯度
	ICameraInfoGE camera;
	camera.AttachDispatch(m_geApplication.GetCamera(1),TRUE);
	scale=58340.0*100.0/camera.GetRange();
	if (abs((int)(mlon*scale-tlon*scale))<1 && abs((int)(mlat*scale-tlat*scale))<1)
		AfxMessageBox("已到達目的地！");
	CView::RedrawWindow(NULL,NULL,RDW_UPDATENOW);	
	int i;
	double a,b,r,llon,llat;
	double mt[2],lt[2],ml[2];		//短線兩頂點
	Drew *dlg=new Drew;
	if(dia==TRUE)
		dlg->DestroyWindow();
	dlg->Create(IDD_DIALOG1,this);
	dia=TRUE;
	dlg->ShowWindow(SW_SHOW);
	CDC* pDC=dlg->GetDC();
	pDC->Ellipse(5,5,105,105);
	r=6371000;
	llon=(tlon-plon)*r;
	llat=(tlat-plat)*r;
	if (j==1)
		b=0;
	else if(llat<0)
		b=3.14+atan(llon/llat);
	else if(llat>0&&llon<0)
		b=6.28+atan(llon/llat);
	else 
		b=atan(llon/llat);
	a=90;
	for(i=1;i<=16;i++)
	{
		mt[0]=55+0*cos((i-1)*3.14/8-b)-(-50)*sin((i-1)*3.14/8-b);
		mt[1]=55+0*sin((i-1)*3.14/8-b)+(-50)*cos((i-1)*3.14/8-b);
		lt[0]=55+0*cos((i-1)*3.14/8-b)-(-45)*sin((i-1)*3.14/8-b);
		lt[1]=55+0*sin((i-1)*3.14/8-b)+(-45)*cos((i-1)*3.14/8-b);
		pDC->MoveTo((int)mt[0],(int)mt[1]);
		pDC->LineTo((int)lt[0],(int)lt[1]);
		if(i==1)
			pDC->TextOut((int)mt[0]-5,(int)mt[1]-5,"N");
		if(i==5)
			pDC->TextOut((int)mt[0]-5,(int)mt[1]-5,"E");
		if(i==9)
			pDC->TextOut((int)mt[0]-5,(int)mt[1]-5,"S");
		if(i==13)
			pDC->TextOut((int)mt[0]-5,(int)mt[1]-5,"W");
	}
	pDC->MoveTo(55,55);
	pDC->LineTo(55,5);
	llon=(mlon-tlon)*r;
	llat=(mlat-tlat)*r;
	if (j==1)
		a=0;
	else if(llat<0)
		a=3.14+atan(llon/llat);
	else if(llat>0&&llon<0)
		a=6.28+atan(llon/llat);
	else 
		a=atan(llon/llat);
	ml[0]=55+0*cos(a-b)-(-50)*sin(a-b);
	ml[1]=55+0*sin(a-b)+(-50)*cos(a-b);
	pDC->MoveTo(55,55);
	pDC->LineTo((int)ml[0],(int)ml[1]);
	pDC->ReleaseAttribDC();
	j++;
	plon=tlon;
	plat=tlat;	
	CView::OnLButtonDown(nFlags, point);
}

void CSample18View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}	
	double x,y;
	x=(double)(point.x-Width/2)/Width;
	y=(double)(610-point.y-Height/2)/Height;
	IPointOnTerrainGE gePoint;		//定義IPointOnTerrainGE類的對象
	//獲取用戶輸入的當前屏幕坐標
	gePoint=m_geApplication.GetPointOnTerrainFromScreenCoords(x,y+0.31);
	double dlon,dlat;
	dlon=gePoint.GetLongitude();	//獲取地理坐標的經度
	dlat=gePoint.GetLatitude();		//獲取地理坐標的緯度
	//將地理坐標轉換為度、分、秒的形式
	dlon=dlon*3600;
	dlat=dlat*3600;
	
	int islon,islat;
	islon=(int)dlon;
	islat=(int)dlat;

	geoLon1=islon/3600;
	islon=islon%3600;
	geoLon2=islon/60;
	geoLon3=islon%60;

	geoLat1=islat/3600;
	islat=islat%3600;
	geoLat2=islat/60;
	geoLat3=islat%60;
	CString Longout,Latout,str;
	Longout+="經度:";
	str.Format("%d",geoLon1);
	Longout+=str;
	Longout+="分";
	str.Format("%d",geoLon2);
	Longout+=str;
	str.Format("%d",geoLon3);
	Longout+="秒";
	Longout+=str;
	Latout+="緯度:";
	str.Format("%d",geoLat1);
	Latout+=str;
	Latout+="分";
	str.Format("%d",geoLat2);
	Latout+=str;
	Latout+="秒";
	str.Format("%d",geoLat3);
	Latout+=str;
	AfxMessageBox(Longout+Latout);
	CView::RedrawWindow(NULL,NULL,RDW_UPDATENOW);	
	CView::OnLButtonDblClk(nFlags, point);
}
