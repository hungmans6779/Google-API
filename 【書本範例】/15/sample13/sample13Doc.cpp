// sample13Doc.cpp : implementation of the CSample13Doc class
//

#include "stdafx.h"
#include "sample13.h"

#include "sample13Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSample13Doc

IMPLEMENT_DYNCREATE(CSample13Doc, CDocument)

BEGIN_MESSAGE_MAP(CSample13Doc, CDocument)
	//{{AFX_MSG_MAP(CSample13Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample13Doc construction/destruction

CSample13Doc::CSample13Doc()
{
	// TODO: add one-time construction code here

}

CSample13Doc::~CSample13Doc()
{
}

BOOL CSample13Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSample13Doc serialization

void CSample13Doc::Serialize(CArchive& ar)
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
// CSample13Doc diagnostics

#ifdef _DEBUG
void CSample13Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSample13Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample13Doc commands
