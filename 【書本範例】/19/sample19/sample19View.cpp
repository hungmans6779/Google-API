// sample19View.cpp : implementation of the CSample19View class
//

#include "stdafx.h"
#include "sample19.h"

#include "sample19Doc.h"
#include "sample19View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "SEARCHNEWS.h"
#include "SEARCHDLG.h"
#include "NEWS.h"
#include "CSTATION.h"
static const CLSID CLSID_ApplicationGE = {0x8097D7E9,0xDB9E,0x4AEF, {0x9B,0x28,0x61,0xD8,0x2A,0x1D,0xF7,0x84}}; 
/////////////////////////////////////////////////////////////////////////////
// CSample19View

IMPLEMENT_DYNCREATE(CSample19View, CView)

BEGIN_MESSAGE_MAP(CSample19View, CView)
	//{{AFX_MSG_MAP(CSample19View)
	ON_COMMAND(IDC_START, OnStart)
	ON_COMMAND(IDC_REPORTS, OnReports)
	ON_COMMAND(IDC_STATION, OnStation)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_LEFT, OnLeft)
	ON_COMMAND(IDM_RIGHT, OnRight)
	ON_COMMAND(IDM_DOWN, OnDown)
	ON_COMMAND(IDM_UP, OnUp)
	ON_COMMAND(IDM_LARGE, OnLarge)
	ON_COMMAND(IDM_SMALL, OnSmall)
	ON_COMMAND(IDC_SEARCH, OnSearch)
	ON_COMMAND(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample19View construction/destruction

CSample19View::CSample19View()
{
	// TODO: add construction code here
	::CoInitialize(NULL);
	m_active=FALSE;
	isPlay=FALSE;
	tourOrAnimate=-1;
}

CSample19View::~CSample19View()
{
}

BOOL CSample19View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSample19View drawing

void CSample19View::OnDraw(CDC* pDC)
{
	CSample19Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSample19View printing

BOOL CSample19View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSample19View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSample19View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSample19View diagnostics

#ifdef _DEBUG
void CSample19View::AssertValid() const
{
	CView::AssertValid();
}

void CSample19View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample19Doc* CSample19View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample19Doc)));
	return (CSample19Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample19View message handlers

void CSample19View::OnStart() 
{
	// TODO: Add your command handler code here
	if(TRUE==m_active)
	{
		AfxMessageBox("客戶端已經啟動！");
		return;
	}
	if(m_geApplication.IsInitialized())
	{
		m_geApplication.CreateDispatch(CLSID_ApplicationGE,NULL);
	}
	m_active=TRUE;		
}

void CSample19View::OnReports() 
{
	// TODO: Add your command handler code here
	//默認文件目錄為臨時文件夾
	if(""==m_geTempFile.GetName())
		m_geTempFile.AttachDispatch(m_geApplication.GetTemporaryPlaces(),TRUE);
	m_geTempFile.Highlight();
	//打開ground.kml文件
	m_geApplication.OpenKmlFile("E:\\olympiad\\ground.kml",1);
	m_geAnimate.AttachDispatch(m_geApplication.GetAnimationController(),TRUE);
	m_geAnimate.Play();
	tourOrAnimate=1;
}

void CSample19View::OnStation() 
{
	// TODO: Add your command handler code here
	IFeatureGE gFeature1,gFeature2,gFeature3,sFeature;
	IFeatureGE* ssFeature;
	IFeatureGE* ggFeature1;
	IFeatureGE* ggFeature2;
	IFeatureGE* ggFeature3;
	IFeatureCollectionGE gCollect1,gCollect2,gCollect3,sCollect;
	int ssNum,ggNum1,ggNum2,ggNum3;
	int i;
	//判斷是否打開場館信息文件
	if(NULL==m_geApplication.GetFeatureByName("stadium"))
	{
		m_geApplication.OpenKmlFile("E:\\olympiad\\stadiums.kml",1);
	}
	//判斷是否打開了ground.kml文件
	if(NULL==m_geApplication.GetFeatureByName("ground"))
	{
		//打開ground.kml文件
		m_geApplication.OpenKmlFile("E:\\olympiad\\ground.kml",1);
	}
	//關閉ground.kml文件的內容
    gFeature1.AttachDispatch(m_geApplication.GetFeatureByName("ground1"),TRUE);
    gFeature2.AttachDispatch(m_geApplication.GetFeatureByName("ground2"),TRUE);
    gFeature3.AttachDispatch(m_geApplication.GetFeatureByName("ground3"),TRUE);
	gCollect1.AttachDispatch(gFeature1.GetChildren(),TRUE);
	gCollect2.AttachDispatch(gFeature2.GetChildren(),TRUE);
	gCollect3.AttachDispatch(gFeature3.GetChildren(),TRUE);
	ggNum1=gCollect1.GetCount();
	ggNum2=gCollect2.GetCount();
	ggNum3=gCollect3.GetCount();
	ggFeature1=new IFeatureGE[ggNum1];
	ggFeature2=new IFeatureGE[ggNum2];
	ggFeature3=new IFeatureGE[ggNum3];
	for(i=0;i<ggNum1;i++)
	{
		ggFeature1[i]=gCollect1.GetItem(i+1);
		ggFeature1[i].SetVisibility(FALSE);
	}
	for(i=0;i<ggNum1;i++)
	{
		ggFeature2[i]=gCollect2.GetItem(i+1);
		ggFeature2[i].SetVisibility(FALSE);
	}
	for(i=0;i<ggNum1;i++)
	{
		ggFeature3[i]=gCollect3.GetItem(i+1);
		ggFeature3[i].SetVisibility(FALSE);
	}
	//默認文件打開目錄為臨時文件夾
	m_geTempFile.Highlight();
	//打開包括北京站相關信息的KML文件
	if(NULL==m_geApplication.GetFeatureByName("beijingzhan.kml"))
		m_geApplication.OpenKmlFile("E:\\olympiad\\beijingzhan.kml",1);
	//獲取打開的KML文件要素
	sFeature.AttachDispatch(m_geApplication.GetFeatureByName("beijingzhan.kml"));
	sCollect.AttachDispatch(sFeature.GetChildren(),TRUE);
	ssNum=sCollect.GetCount();
	ssFeature=new IFeatureGE[ssNum];
	//獲取子要素
	for(i=0;i<ssNum;i++)
	{
		ssFeature[i]=sCollect.GetItem(i+1);
	}
	//設置火車站視圖
	if("beijingzhan"==ssFeature[0].GetName() && TRUE==ssFeature[0].GetHasView())
		m_geApplication.SetFeatureView(ssFeature[0],3.0);
	//顯示火車站對話框
	CCSTATION station;
	int line;
	//獲取對話框中列表框的內容
	if(IDOK==station.DoModal())
	{
		line=station.line;
	}
	//獲取Tour對象
	m_geTour.AttachDispatch(m_geApplication.GetTourController(),TRUE);
	switch(line)
	{
	case 1:
		//顯示北京站到工人體育館的路線，並播放
		if("beijingzhan-works stadium"==ssFeature[1].GetName())
		{
			ssFeature[1].SetVisibility(1);
			ssFeature[2].SetVisibility(0);
			ssFeature[3].SetVisibility(0);
			ssFeature[1].Highlight();
			if(FALSE==isPlay)
			{
				m_geTour.PlayOrPause();
				isPlay=TRUE;
				tourOrAnimate=2;
			}
		}
		break;
	case 2:
		//顯示北京站到國家體育館的路線，並播放
		if("beijingzhan-nation stadium"==ssFeature[2].GetName())
		{
			ssFeature[1].SetVisibility(0);
			ssFeature[2].SetVisibility(1);
			ssFeature[3].SetVisibility(0);
			ssFeature[2].Highlight();
			if(FALSE==isPlay)
			{
				m_geTour.PlayOrPause();
				isPlay=TRUE;
				tourOrAnimate=2;
			}
		}
		break;
	case 3:
		//顯示北京站到首都體育館的路線，並播放
		if("beijingzhan-capital stadium"==ssFeature[3].GetName())
		{
			ssFeature[1].SetVisibility(0);
			ssFeature[2].SetVisibility(0);
			ssFeature[3].SetVisibility(1);
			ssFeature[2].Highlight();
			if(FALSE==isPlay)
			{
				m_geTour.PlayOrPause();
				isPlay=TRUE;
				tourOrAnimate=2;
			}
		}
		break;
	default:
		break;
	}
}

void CSample19View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	
	switch(tourOrAnimate)
	{
	case 1:
		m_geAnimate.Pause();			//停止項目展示
		break;
	case 2:
		m_geTour.PlayOrPause();			//停止路徑展示
		isPlay=FALSE;
		break;
	default:
		break;
	}
	CView::OnRButtonDown(nFlags, point);
}

void CSample19View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    double* curPoint=new double[2];
	double lon,lat;
	curPoint=CordChange(point);
	lon=curPoint[0];
	lat=curPoint[1];
	//獲取場館地理坐標
	double worksLat,worksLon;
	double nationLat,nationLon;
	double capitalLat,capitalLon;
	worksLat=39.92959;
	worksLon=116.44091;
	nationLat=39.97452;
	nationLon=116.38183;
	capitalLat=39.94228;
	capitalLon=116.32150;
	CString strTime=CTime::GetCurrentTime().Format("%Y-%m-%d   %H:%M:%S");
	//點擊工人體育場彈出對話框
	if(TRUE==InOrOut(lon,lat,worksLon,worksLat))
	{
		CNEWS newsDlg;
		newsDlg.m_time=strTime;
		newsDlg.m_stadium="工人體育館賽況";
		newsDlg.m_news=ReadFile("E:\\olympiad\\工人體育館賽況.txt");
		newsDlg.DoModal();
	}
	//點擊國家體育場彈出對話框
	if(TRUE==InOrOut(lon,lat,nationLon,nationLat))
	{
		CNEWS newsDlg;
		newsDlg.m_time=strTime;
		newsDlg.m_stadium="國家體育館賽況";
		newsDlg.m_news=ReadFile("E:\\olympiad\\國家體育館賽況.txt");
		newsDlg.DoModal();
	}
	//點擊首都體育場彈出對話框
	if(TRUE==InOrOut(lon,lat,capitalLon,capitalLat))
	{
		CNEWS newsDlg;
		newsDlg.m_time=strTime;
		newsDlg.m_stadium="首都體育館賽況";
		newsDlg.m_news=ReadFile("E:\\olympiad\\首都體育館賽況.txt");
		newsDlg.DoModal();
	}
	CView::OnLButtonDown(nFlags, point);
}

double* CSample19View::CordChange(CPoint point)
{
    double* gePot=new double[2];
	int x,y;
	x=point.x;
	y=point.y;
	//獲取VC視圖區域
	CRect viewRect;
	GetClientRect(&viewRect);
    //獲取Google Earth視圖窗口
	OLE_HANDLE hRenderWnd;
	hRenderWnd=m_geApplication.GetRenderHwnd();
	CWnd* pWnd=CWnd::FromHandle((HWND)hRenderWnd);
	//獲取Google Earth視圖區域
	CRect geRect;
	pWnd->GetClientRect(&geRect);

	double scalex,scaley;				//獲取兩個窗口的x、y方向比值
	scalex=geRect.right/viewRect.right;
	scaley=geRect.bottom/viewRect.bottom;
	//轉換VC點到Google Earth上
	CPoint gePoint;
	gePoint.x=(int)(x*scalex);
	gePoint.y=(int)(y*scaley);
	//轉換為Google Earth標準坐標
	//坐標系平移
	double geX,geY;
	geX=gePoint.x-geRect.right/2.0;
	geY=geRect.bottom/2.0-gePoint.y;
    //坐標系縮放
	geX/=(geRect.right/2.0);
	geY/=(geRect.bottom/2.0);
	//轉換為Google Earth的經緯度
	IPointOnTerrainGE pointOnTerrain;
	pointOnTerrain.AttachDispatch(m_geApplication.GetPointOnTerrainFromScreenCoords(geX,geY),TRUE);
	gePot[0]=pointOnTerrain.GetLongitude();
	gePot[1]=pointOnTerrain.GetLatitude();
	return gePot;
}

BOOL CSample19View::InOrOut(double pointx, double pointy, double focusx, double focusy)
{
	BOOL inorout;
	double delta;
	delta=0.0025;
	if((pointx>focusx-delta && pointx<focusx+delta) && (pointy>focusy-delta && pointy<focusy+delta))
	{
		inorout=TRUE;
	}
	else
	{
		inorout=FALSE;
	}
	return inorout;
}

CString CSample19View::ReadFile(CString pathname)
{
	CString strAll;
	CFile file(pathname,CFile::modeRead);
	DWORD len;
	char* Allchar;
	len=file.GetLength();
	Allchar=new char[len];
	Allchar[len]=0;
	file.Read(Allchar,len);				//將文件中的內容讀取到dbAll中
	strAll=Allchar;
	file.Close();
	return strAll;
}

void CSample19View::OnLeft() 
{
	// TODO: Add your command handler code here
	m_geCamera.AttachDispatch(m_geApplication.GetCamera(1),TRUE);
	m_geExtents.AttachDispatch(m_geApplication.GetViewExtents(),TRUE);
	geLeft=m_geExtents.GetWest();
	geRight=m_geExtents.GetEast();
	geTop=m_geExtents.GetNorth();
	geBottom=m_geExtents.GetSouth();
	geRange=m_geCamera.GetRange();
	double delta;					//定義平移距離大小
	delta=(geRight-geLeft)/4;
	//計算平移後的視圖中心位置
	double xFocus,yFocus;
	xFocus=(geLeft+geRight)/2+delta;
	yFocus=(geTop+geBottom)/2;
	//平移
	m_geApplication.SetCameraParams(yFocus,xFocus,100.0,1,geRange,0.0,0.0,1.5);
}

void CSample19View::OnRight() 
{
	// TODO: Add your command handler code here
	m_geCamera.AttachDispatch(m_geApplication.GetCamera(1),TRUE);
	m_geExtents.AttachDispatch(m_geApplication.GetViewExtents(),TRUE);
	geLeft=m_geExtents.GetWest();
	geRight=m_geExtents.GetEast();
	geTop=m_geExtents.GetNorth();
	geBottom=m_geExtents.GetSouth();
	geRange=m_geCamera.GetRange();
	double delta;					//定義平移距離大小
	delta=(geRight-geLeft)/4;
	//計算平移後的視圖中心位置
	double xFocus,yFocus;
	xFocus=(geLeft+geRight)/2-delta;
	yFocus=(geTop+geBottom)/2;
	//平移
	m_geApplication.SetCameraParams(yFocus,xFocus,100.0,1,geRange,0.0,0.0,1.5);
}

void CSample19View::OnDown() 
{
	// TODO: Add your command handler code here
	m_geCamera.AttachDispatch(m_geApplication.GetCamera(1),TRUE);
	m_geExtents.AttachDispatch(m_geApplication.GetViewExtents(),TRUE);
	geLeft=m_geExtents.GetWest();
	geRight=m_geExtents.GetEast();
	geTop=m_geExtents.GetNorth();
	geBottom=m_geExtents.GetSouth();
	geRange=m_geCamera.GetRange();
	double delta;					//定義平移距離大小
	delta=(geTop-geBottom)/4;
	//計算平移後的視圖中心位置
	double xFocus,yFocus;
	xFocus=(geLeft+geRight)/2;
	yFocus=(geTop+geBottom)/2+delta;
	//平移
	m_geApplication.SetCameraParams(yFocus,xFocus,100.0,1,geRange,0.0,0.0,1.5);
}

void CSample19View::OnUp() 
{
	// TODO: Add your command handler code here
	m_geCamera.AttachDispatch(m_geApplication.GetCamera(1),TRUE);
	m_geExtents.AttachDispatch(m_geApplication.GetViewExtents(),TRUE);
	geLeft=m_geExtents.GetWest();
	geRight=m_geExtents.GetEast();
	geTop=m_geExtents.GetNorth();
	geBottom=m_geExtents.GetSouth();
	geRange=m_geCamera.GetRange();
	double delta;					//定義平移距離大小
	delta=(geTop-geBottom)/4;
	//計算平移後的視圖中心位置
	double xFocus,yFocus;
	xFocus=(geLeft+geRight)/2;
	yFocus=(geTop+geBottom)/2-delta;
	//平移
	m_geApplication.SetCameraParams(yFocus,xFocus,100.0,1,geRange,0.0,0.0,1.5);		
}

void CSample19View::OnLarge() 
{
	// TODO: Add your command handler code here
	double newRange;
	ICameraInfoGE newCamera;
	m_geCamera.AttachDispatch(m_geApplication.GetCamera(1),TRUE);
	//設定放大倍數
	newRange=m_geCamera.GetRange()*0.5;
	m_geCamera.SetRange(newRange);
	m_geCamera.SetAzimuth(0.0);
	m_geCamera.SetTilt(0.0);
	//重新設定視圖
	m_geApplication.SetCamera(m_geCamera,3.0);
}

void CSample19View::OnSmall() 
{
	// TODO: Add your command handler code here
	double newRange;
	ICameraInfoGE newCamera;
	m_geCamera.AttachDispatch(m_geApplication.GetCamera(1),TRUE);
	//設定縮小倍數
	newRange=m_geCamera.GetRange()*2.0;
	m_geCamera.SetRange(newRange);
	m_geCamera.SetAzimuth(0.0);
	m_geCamera.SetTilt(0.0);
	//重新設定視圖
	m_geApplication.SetCamera(m_geCamera,3.0);	
}

void CSample19View::OnSearch() 
{
	// TODO: Add your command handler code here
	//默認文件目錄為臨時文件夾
	if(""==m_geTempFile.GetName())
		m_geTempFile.AttachDispatch(m_geApplication.GetTemporaryPlaces(),TRUE);
	m_geTempFile.Highlight();
	//判斷是否打開了ground.kml文件
	if(NULL==m_geApplication.GetFeatureByName("ground"))
	{
		//打開ground.kml文件
		m_geApplication.OpenKmlFile("E:\\olympiad\\ground.kml",1);
	}
	//判斷是否打開了stadium.kml文件
	if(NULL==m_geApplication.GetFeatureByName("stadium"))
	{
		//打開ground.kml文件
		m_geApplication.OpenKmlFile("E:\\olympiad\\stadiums.kml",1);
	}
	ITimeGE beginTime,endTime;
	ITimeIntervalGE interval;
	IFeatureGE beginFeature,endFeature;
	CString strTime;
	CSEARCHDLG searchDlg;
	int item;
	//獲取用戶所要查找的比賽項目
	if(IDOK==searchDlg.DoModal())
		item=searchDlg.m_item;
	CSEARCHNEWS newsDlg;
	switch(item)
	{
	case 0:
		newsDlg.m_stadium="首都體育館";
		//獲取比賽開始時間
		beginFeature=m_geApplication.GetFeatureByName("tianjing1");
		interval=beginFeature.GetTimeInterval();
		beginTime=interval.GetBeginTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",beginTime.GetMonth(),beginTime.GetDay(),beginTime.GetHour(),beginTime.GetMinute(),beginTime.GetSecond());
		newsDlg.m_begintime=strTime;
		//獲取比賽結束時間
		endFeature=m_geApplication.GetFeatureByName("tianjing3");
		interval=endFeature.GetTimeInterval();
		endTime=interval.GetEndTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",endTime.GetMonth(),endTime.GetDay(),endTime.GetHour(),endTime.GetMinute(),endTime.GetSecond());
		newsDlg.m_endtime=strTime;
		break;
	case 1:
		newsDlg.m_stadium="首都體育館";
		//獲取比賽開始時間
		beginFeature=m_geApplication.GetFeatureByName("zuqiu1");
		interval=beginFeature.GetTimeInterval();
		beginTime=interval.GetBeginTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",beginTime.GetMonth(),beginTime.GetDay(),beginTime.GetHour(),beginTime.GetMinute(),beginTime.GetSecond());
		newsDlg.m_begintime=strTime;
		//獲取比賽結束時間
		endFeature=m_geApplication.GetFeatureByName("zuqiu3");
		interval=endFeature.GetTimeInterval();
		endTime=interval.GetEndTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",endTime.GetMonth(),endTime.GetDay(),endTime.GetHour(),endTime.GetMinute(),endTime.GetSecond());
		newsDlg.m_endtime=strTime;
		break;
	case 2:
		newsDlg.m_stadium="工人體育館";
		//獲取比賽開始時間
		beginFeature=m_geApplication.GetFeatureByName("pingpangqiu1");
		interval=beginFeature.GetTimeInterval();
		beginTime=interval.GetBeginTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",beginTime.GetMonth(),beginTime.GetDay(),beginTime.GetHour(),beginTime.GetMinute(),beginTime.GetSecond());
		newsDlg.m_begintime=strTime;
		//獲取比賽結束時間
		endFeature=m_geApplication.GetFeatureByName("pingpangqiu3");
		interval=endFeature.GetTimeInterval();
		endTime=interval.GetEndTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",endTime.GetMonth(),endTime.GetDay(),endTime.GetHour(),endTime.GetMinute(),endTime.GetSecond());
		newsDlg.m_endtime=strTime;
		break;
	case 3:
		newsDlg.m_stadium="工人體育館";
		//獲取比賽開始時間
		beginFeature=m_geApplication.GetFeatureByName("lanqiu1");
		interval=beginFeature.GetTimeInterval();
		beginTime=interval.GetBeginTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",beginTime.GetMonth(),beginTime.GetDay(),beginTime.GetHour(),beginTime.GetMinute(),beginTime.GetSecond());
		newsDlg.m_begintime=strTime;
		//獲取比賽結束時間
		endFeature=m_geApplication.GetFeatureByName("lanqiu3");
		interval=endFeature.GetTimeInterval();
		endTime=interval.GetEndTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",endTime.GetMonth(),endTime.GetDay(),endTime.GetHour(),endTime.GetMinute(),endTime.GetSecond());
		newsDlg.m_endtime=strTime;
		break;
	case 4:
		newsDlg.m_stadium="國家體育館";
		//獲取比賽開始時間
		beginFeature=m_geApplication.GetFeatureByName("juzhong1");
		interval=beginFeature.GetTimeInterval();
		beginTime=interval.GetBeginTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",beginTime.GetMonth(),beginTime.GetDay(),beginTime.GetHour(),beginTime.GetMinute(),beginTime.GetSecond());
		newsDlg.m_begintime=strTime;
		//獲取比賽結束時間
		endFeature=m_geApplication.GetFeatureByName("juzhong3");
		interval=endFeature.GetTimeInterval();
		endTime=interval.GetEndTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",endTime.GetMonth(),endTime.GetDay(),endTime.GetHour(),endTime.GetMinute(),endTime.GetSecond());
		newsDlg.m_endtime=strTime;
		break;
	case 5:
		newsDlg.m_stadium="國家體育館";
		//獲取比賽開始時間
		beginFeature=m_geApplication.GetFeatureByName("sheji1");
		interval=beginFeature.GetTimeInterval();
		beginTime=interval.GetBeginTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",beginTime.GetMonth(),beginTime.GetDay(),beginTime.GetHour(),beginTime.GetMinute(),beginTime.GetSecond());
		newsDlg.m_begintime=strTime;
		//獲取比賽結束時間
		endFeature=m_geApplication.GetFeatureByName("sheji3");
		interval=endFeature.GetTimeInterval();
		endTime=interval.GetEndTime();
		strTime.Format("%d月%d日 %.2d:%.2d:%.2d",endTime.GetMonth(),endTime.GetDay(),endTime.GetHour(),endTime.GetMinute(),endTime.GetSecond());
		newsDlg.m_endtime=strTime;
		break;
	default:
		break;
	}
	//關閉ground.kml文件的內容
	IFeatureGE gFeature1,gFeature2,gFeature3;
	IFeatureGE* ggFeature1;
	IFeatureGE* ggFeature2;
	IFeatureGE* ggFeature3;
	IFeatureCollectionGE gCollect1,gCollect2,gCollect3;
	int ggNum1,ggNum2,ggNum3;
    gFeature1.AttachDispatch(m_geApplication.GetFeatureByName("ground1"),TRUE);
    gFeature2.AttachDispatch(m_geApplication.GetFeatureByName("ground2"),TRUE);
    gFeature3.AttachDispatch(m_geApplication.GetFeatureByName("ground3"),TRUE);
	gCollect1.AttachDispatch(gFeature1.GetChildren(),TRUE);
	gCollect2.AttachDispatch(gFeature2.GetChildren(),TRUE);
	gCollect3.AttachDispatch(gFeature3.GetChildren(),TRUE);
	ggNum1=gCollect1.GetCount();
	ggNum2=gCollect2.GetCount();
	ggNum3=gCollect3.GetCount();
	ggFeature1=new IFeatureGE[ggNum1];
	ggFeature2=new IFeatureGE[ggNum2];
	ggFeature3=new IFeatureGE[ggNum3];
	for(int i=0;i<ggNum1;i++)
	{
		ggFeature1[i]=gCollect1.GetItem(i+1);
		ggFeature1[i].SetVisibility(FALSE);
	}
	for(i=0;i<ggNum1;i++)
	{
		ggFeature2[i]=gCollect2.GetItem(i+1);
		ggFeature2[i].SetVisibility(FALSE);
	}
	for(i=0;i<ggNum1;i++)
	{
		ggFeature3[i]=gCollect3.GetItem(i+1);
		ggFeature3[i].SetVisibility(FALSE);
	}
	//移動視圖到比賽地點
	IFeatureGE placeFeature;
	if(IDOK==newsDlg.DoModal())
	{
		switch(item)
		{
		case 0:
		case 1:
			placeFeature=m_geApplication.GetFeatureByName("capital stadium");
			m_geApplication.SetFeatureView(placeFeature,3.0);
			break;
		case 2:
		case 3:
			placeFeature=m_geApplication.GetFeatureByName("works stadium");
			m_geApplication.SetFeatureView(placeFeature,3.0);
			break;
		case 4:
		case 5:
			placeFeature=m_geApplication.GetFeatureByName("nation stadium");
			m_geApplication.SetFeatureView(placeFeature,3.0);
			break;
		default:
			break;
		}
	}
}

void CSample19View::OnExit() 
{
	// TODO: Add your command handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}
