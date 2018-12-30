// sample5Doc.cpp : implementation of the CSample5Doc class
//

#include "stdafx.h"
#include "sample5.h"

#include "sample5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSample5Doc

IMPLEMENT_DYNCREATE(CSample5Doc, CDocument)

BEGIN_MESSAGE_MAP(CSample5Doc, CDocument)
	//{{AFX_MSG_MAP(CSample5Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample5Doc construction/destruction

CSample5Doc::CSample5Doc()
{
	// TODO: add one-time construction code here

}

CSample5Doc::~CSample5Doc()
{
}

BOOL CSample5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSample5Doc serialization

void CSample5Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSample5Doc diagnostics

#ifdef _DEBUG
void CSample5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSample5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample5Doc commands
