// sample8View.cpp : implementation of the CSample8View class
//

#include "stdafx.h"
#include "sample8.h"

#include "sample8Doc.h"
#include "sample8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "SEARCH.h"
static const CLSID CLSID_ApplicationGE = {0x8097D7E9,0xDB9E,0x4AEF, {0x9B,0x28,0x61,0xD8,0x2A,0x1D,0xF7,0x84}}; 
/////////////////////////////////////////////////////////////////////////////
// CSample8View

IMPLEMENT_DYNCREATE(CSample8View, CView)

BEGIN_MESSAGE_MAP(CSample8View, CView)
	//{{AFX_MSG_MAP(CSample8View)
	ON_COMMAND(IDC_START, OnStart)
	ON_COMMAND(IDC_OPEN, OnOpen)
	ON_COMMAND(IDC_LOCALSEARCH, OnLocalsearch)
	ON_COMMAND(IDC_SAVE, OnSave)
	ON_COMMAND(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample8View construction/destruction

CSample8View::CSample8View()
{
	// TODO: add construction code here
    ::CoInitialize(NULL);
}

CSample8View::~CSample8View()
{
}

BOOL CSample8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSample8View drawing

void CSample8View::OnDraw(CDC* pDC)
{
	CSample8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSample8View printing

BOOL CSample8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSample8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSample8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSample8View diagnostics

#ifdef _DEBUG
void CSample8View::AssertValid() const
{
	CView::AssertValid();
}

void CSample8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample8Doc* CSample8View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample8Doc)));
	return (CSample8Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample8View message handlers

void CSample8View::OnStart() 
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

void CSample8View::OnOpen() 
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

void CSample8View::OnLocalsearch() 
{
	// TODO: Add your command handler code here
	int i(0),j(0),k(0),m(0),n(0),l(0);
	BOOL IsSearch(FALSE);		//判斷是否查找到了結果
    CString fileName;			//定義所要查找的文件名
	CSEARCH searchDlg;
	if(IDOK==searchDlg.DoModal())
	{
		fileName=searchDlg.m_filename;
	}

	IFeatureCollectionGE myCollection;
	IFeatureGE myFeature;
	//獲取My Places文件夾
	myFeature.AttachDispatch(m_geApplication.GetMyPlaces(),TRUE);
	myCollection.AttachDispatch(myFeature.GetChildren());

	//獲取My Places文件夾下的文件數
	int myCount;
	myCount=myCollection.GetCount();
	IFeatureGE* myfeature1;
	myfeature1=new IFeatureGE[myCount];

	for(i=0;i<myCount;i++)
	{
		myfeature1[i]=myCollection.GetItem(i+1);	//獲取My Places文件夾下的子要素
	}

	CString name1;				//第一層文件的文件名
	int name1Len;				//第一層文件的文件名長度
	CString name2;				//第二層文件的文件名
	int name2Len;				//第二層文件的文件名長度
	CString name3;				//第三層文件的文件名
	int name3Len;				//第三層文件的文件名長度

	//第二層文件要素的集合
	IFeatureCollectionGE mycollection1;
	IFeatureGE* myfeature2;		//第二層文件的要素
	int cCount1;				//定義第二層文件數
	//第三層文件要素的集合
	IFeatureCollectionGE mycollection2;
	IFeatureGE* myfeature3;		//第三層文件的要素
	int cCount2;				//定義第三層文件數

	//在MyPlaces文件夾中查找
	for(i=0;i<myCount;i++)
	{
		if(TRUE==myfeature1[i].GetHasView())		//有視圖則核對文件名是否相同
		{
			name1=myfeature1[i].GetName();
			name1Len=name1.GetLength();
			for(j=1;j<name1Len;j++)
			{
				//刪除文件名中多餘的空格字符
				if(' '==name1.GetAt(j) && ','==name1.GetAt(j-1))
				{
					name1.Delete(j,1);
					name1Len--;
				}
			}
			//如果文件名相同，則將客戶端視圖中心移動到該文件要素的位置
			if(0==strcmp(fileName,name1))
			{
				IsSearch=TRUE;
				m_geApplication.SetFeatureView(myfeature1[i],3.0);
			}
		}
		else									    //無視圖則繼續搜索
		{
			mycollection1.AttachDispatch(myfeature1[i].GetChildren());
			if(mycollection1!=NULL)
			{
				cCount1=mycollection1.GetCount();
				myfeature2=new IFeatureGE[cCount1];
				//獲取二層文件下的子要素
				for(k=0;k<cCount1;k++)
				{
					myfeature2[k]=mycollection1.GetItem(k+1);
				}
				
				for(k=0;k<cCount1;k++)
				{
					if(TRUE==myfeature2[k].GetHasView()) //有視圖則核對文件名是否相同
					{
						name2=myfeature2[k].GetName();
						name2Len=name2.GetLength();
						for(m=1;m<name2Len;m++)
						{
							//刪除文件名中的空格字符
							if(' '==name2.GetAt(m) && ','==name2.GetAt(m-1))
							{
								name2.Delete(m,1);
								name2Len--;
							}
						}
						if(0==strcmp(fileName,name2))
						{
							IsSearch=TRUE;
							m_geApplication.SetFeatureView(myfeature2[k],3.0);
						}
					}
					else								 //無視圖則繼續搜索
					{
						mycollection2.AttachDispatch(myfeature2[k].GetChildren());
						if(mycollection2!=NULL)
						{
							cCount2=mycollection2.GetCount();
							myfeature3=new IFeatureGE[cCount2];
							//獲取三層文件下的子要素
							for(n=0;n<cCount2;n++)
							{
								myfeature3[n]=mycollection2.GetItem(n+1);
							}
							
							for(n=0;n<cCount2;n++)
							{
								if(TRUE==myfeature3[n].GetHasView())
								{
									name3=myfeature3[n].GetName();
									name3Len=name3.GetLength();
									for(l=1;l<name3Len;l++)
									{
										//刪除文件名中的空格字符
										if(' '==name3.GetAt(l) && ','==name2.GetAt(l-1))
										{
											name3.Delete(l,1);
											name3Len--;
										}
									}
									if(0==strcmp(fileName,name3))
									{
										IsSearch=TRUE;
										m_geApplication.SetFeatureView(myfeature3[n],3.0);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	IFeatureCollectionGE tempCollection;
	IFeatureGE tempFeature;
	//獲取Temporary Places文件夾
	tempFeature.AttachDispatch(m_geApplication.GetTemporaryPlaces(),TRUE);
	tempCollection.AttachDispatch(tempFeature.GetChildren());

	int tempCount;
	//獲取Temporary Places文件夾中的文件數
	tempCount=tempCollection.GetCount();
	IFeatureGE* tempfeature1;
	tempfeature1=new IFeatureGE[tempCount];

	//獲取Temporary Places文件夾下的子要素
	for(i=0;i<tempCount;i++)
	{
		tempfeature1[i]=tempCollection.GetItem(i+1);
	}

	IFeatureCollectionGE tempcollection1;
	IFeatureGE* tempfeature2;
	IFeatureCollectionGE tempcollection2;
	IFeatureGE* tempfeature3;

	//在Temporary Places文件夾中查找
	for(i=0;i<tempCount;i++)
	{
		if(TRUE==tempfeature1[i].GetHasView())		//有視圖則核對文件名是否相同
		{
			name1=tempfeature1[i].GetName();
			name1Len=name1.GetLength();
			for(j=1;j<name1Len;j++)
			{
				//刪除文件名中的空格字符
				if(' '==name1.GetAt(j) && ','==name1.GetAt(j-1))
				{
					name1.Delete(j,1);
					name1Len--;
				}
			}
			if(0==strcmp(fileName,name1))
			{
				IsSearch=TRUE;
				m_geApplication.SetFeatureView(tempfeature1[i],3.0);
			}
		}
		else									    //無視圖則繼續搜索
		{
			tempcollection1.AttachDispatch(tempfeature1[i].GetChildren());
			if(tempcollection1!=NULL)
			{
				cCount1=tempcollection1.GetCount();
				tempfeature2=new IFeatureGE[cCount1];
				//獲取二層文件下的子要素
				for(k=0;k<cCount1;k++)
				{
					tempfeature2[k]=tempcollection1.GetItem(k+1);
				}
				
				for(k=0;k<cCount1;k++)
				{
					if(TRUE==tempfeature2[k].GetHasView()) //有視圖則核對文件名是否相同
					{
						name2=tempfeature2[k].GetName();
						name2Len=name2.GetLength();
						for(m=1;m<name2Len;m++)
						{
							//刪除文件名中的空格字符
							if(' '==name2.GetAt(m) && ','==name2.GetAt(m-1))
							{
								name2.Delete(m,1);
								name2Len--;
							}
						}
						if(0==strcmp(fileName,name2))
						{
							IsSearch=TRUE;
							m_geApplication.SetFeatureView(tempfeature2[k],3.0);
						}
					}
					else								 //無視圖則繼續搜索
					{
						tempcollection2.AttachDispatch(tempfeature2[k].GetChildren());
						if(tempcollection2!=NULL)
						{
							cCount2=tempcollection2.GetCount();
							tempfeature3=new IFeatureGE[cCount2];
							//獲取三層文件下的子要素
							for(n=0;n<cCount2;n++)
							{
								tempfeature3[n]=tempcollection2.GetItem(n+1);
							}
							
							for(n=0;n<cCount2;n++)
							{
								if(TRUE==tempfeature3[n].GetHasView())
								{
									name3=tempfeature3[n].GetName();
									name3Len=name3.GetLength();
									for(l=1;l<name3Len;l++)
									{
										//刪除文件名中的空格字符
										if(' '==name3.GetAt(l) && ','==name2.GetAt(l-1))
										{
											name3.Delete(l,1);
											name3Len--;
										}
									}
									if(0==strcmp(fileName,name3))
									{
										IsSearch=TRUE;
										m_geApplication.SetFeatureView(tempfeature3[n],3.0);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//不能搜索到文件，彈出對話框提示
	if(FALSE==IsSearch)
	{
		AfxMessageBox("沒有你想要的文件！");
	}
}

void CSample8View::OnSave() 
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

void CSample8View::OnExit() 
{
	// TODO: Add your command handler code here
	HWND hwnd;
	hwnd=(HWND)m_geApplication.GetMainHwnd();
	//採用Windows消息函數關閉Google Earth客戶端
	::SendMessage(hwnd,WM_CLOSE,NULL,NULL);
	m_geApplication.ReleaseDispatch();		
}
