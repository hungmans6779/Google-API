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
		AfxMessageBox("客戶端已經啟動！");
		return;
	}
    m_active=TRUE;
	if(m_geApplication.IsInitialized())
	{
		m_geApplication.CreateDispatch(CLSID_ApplicationGE,NULL);
		if(!m_geApplication.IsOnline())
		{
			AfxMessageBox("已經連接上服務器！");
		}
	}		
}

void CSample7View::OnOpen() 
{
	// TODO: Add your command handler code here
	if(FALSE==m_active)
	{
		AfxMessageBox("客戶端未啟動！");
		return;
	}

	CFileDialog geOpenDlg(TRUE);			//初始化一個打開對話框的對象
	geOpenDlg.m_ofn.lpstrTitle="Goolge Earth文件打開對話框";
	geOpenDlg.m_ofn.lpstrFilter="KML Files(*.kml)\0*.kml\0All Files(*.*)\0*.*\0\0";
    //完成KML文件的打開操作
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
		AfxMessageBox("客戶端未啟動！");
		return;
	}

	CFileDialog geSaveDlg(FALSE);			//初始化一個保存對話框的對象
	geSaveDlg.m_ofn.lpstrTitle="Goolge Earth圖象保存對話框";
	geSaveDlg.m_ofn.lpstrFilter="JPG Files(*.jpg)\0*.jpg\0All Files(*.*)\0*.*\0\0";	
	geSaveDlg.m_ofn.lpstrDefExt="jpg";
    //將當前視圖保存為JPEG格式的黑白圖象
	if(IDOK==geSaveDlg.DoModal())
	{
		m_geApplication.SaveScreenShot(geSaveDlg.GetPathName(),100);
	}	
}

void CSample7View::OnChange() 
{
	// TODO: Add your command handler code here
	int i(0),j(0),k(0);
	//創建非模態對話框
	pChangeDlg=new CCHANGEDLG();
	pChangeDlg->Create(IDD_CHANGEDLG,this);
	pChangeDlg->ShowWindow(SW_SHOW);

	//獲取名為hubei的kml文件
	m_geFeature.AttachDispatch(m_geApplication.GetFeatureByName("hubei"),TRUE);
	//獲取hubei文件要素
	m_geCollection.AttachDispatch(m_geFeature.GetChildren(),TRUE);

	int countUp;
	countUp=m_geCollection.GetCount();	//獲取hubei文件夾中的文件數目
    
	int* fileCount;
	fileCount=new int[countUp];
	IFeatureGE* feature;
	feature=new IFeatureGE[countUp];
	IFeatureCollectionGE* collection;
	collection=new IFeatureCollectionGE[countUp];

	for(i=0;i<countUp;i++)
	{
		//獲取hubei文件中的子文件要素
		feature[i].AttachDispatch(m_geCollection.GetItem(i+1),TRUE);
		collection[i].AttachDispatch(feature[i].GetChildren(),TRUE);
		//獲取各子文件中的地標要素數目
		fileCount[i]=collection[i].GetCount();
	}
//獲取地標要素總數
	fileSum=0;
	for(i=0;i<countUp;i++)
	{
		fileSum+=fileCount[i];
	}

//重新定義地標要素數組
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
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}

void CSample7View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//獲取在對話框單擊【視圖切換】按鈕的次數
	m_viewCount=pChangeDlg->m_viewCount;

	//過濾m_viewCount值
	int viewItem;
	viewItem=m_viewCount%fileSum;

	if(TRUE==bFeature[viewItem].GetHasView())	//判斷該要素是否可視
	{
		//將視圖中心移動到該要素所在位置
		m_geApplication.SetFeatureView(bFeature[viewItem],3);
	}
	else
	{
		AfxMessageBox("KML文件不是二級目錄！");
		return;									//如果該要素不可視，則拒絕顯示
	}

	//m_geTimer用來控制Timer()函數
	BOOL m_geTimer;
	//判斷是否停止調整操作
	m_geTimer=pChangeDlg->IsTimer;
	if(m_geTimer==FALSE)
	{
		KillTimer(1);	//關閉Timer()函數
	}
	CView::OnTimer(nIDEvent);
}
