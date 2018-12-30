// sample19Doc.cpp : implementation of the CSample19Doc class
//

#include "stdafx.h"
#include "sample19.h"

#include "sample19Doc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSample19Doc

IMPLEMENT_DYNCREATE(CSample19Doc, CDocument)

BEGIN_MESSAGE_MAP(CSample19Doc, CDocument)
	//{{AFX_MSG_MAP(CSample19Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample19Doc construction/destruction

CSample19Doc::CSample19Doc()
{
	// TODO: add one-time construction code here

}

CSample19Doc::~CSample19Doc()
{
}

BOOL CSample19Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSample19Doc serialization

void CSample19Doc::Serialize(CArchive& ar)
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
// CSample19Doc diagnostics

#ifdef _DEBUG
void CSample19Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSample19Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample19Doc commands
