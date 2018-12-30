// sample5View.cpp : implementation of the CSample5View class
//

#include "stdafx.h"
#include "sample5.h"

#include "sample5Doc.h"
#include "sample5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static const CLSID CLSID_ApplicationGE = {0x8097D7E9,0xDB9E,0x4AEF, {0x9B,0x28,0x61,0xD8,0x2A,0x1D,0xF7,0x84}}; 
/////////////////////////////////////////////////////////////////////////////
// CSample5View

IMPLEMENT_DYNCREATE(CSample5View, CView)

BEGIN_MESSAGE_MAP(CSample5View, CView)
	//{{AFX_MSG_MAP(CSample5View)
	ON_COMMAND(IDC_START, OnStart)
	ON_COMMAND(IDC_EXIT, OnExit)
	ON_COMMAND(IDC_OPEN, OnOpen)
	ON_COMMAND(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample5View construction/destruction

CSample5View::CSample5View()
{
	// TODO: add construction code here
    ::CoInitialize(NULL);
	m_active=FALSE;
}

CSample5View::~CSample5View()
{
}

BOOL CSample5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSample5View drawing

void CSample5View::OnDraw(CDC* pDC)
{
	CSample5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSample5View printing

BOOL CSample5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSample5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSample5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSample5View diagnostics

#ifdef _DEBUG
void CSample5View::AssertValid() const
{
	CView::AssertValid();
}

void CSample5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample5Doc* CSample5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample5Doc)));
	return (CSample5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample5View message handlers

void CSample5View::OnStart() 
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

void CSample5View::OnExit() 
{
	// TODO: Add your command handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}

void CSample5View::OnOpen() 
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

void CSample5View::OnSave() 
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
