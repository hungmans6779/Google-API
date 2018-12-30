// sample7Doc.cpp : implementation of the CSample7Doc class
//

#include "stdafx.h"
#include "sample7.h"

#include "sample7Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSample7Doc

IMPLEMENT_DYNCREATE(CSample7Doc, CDocument)

BEGIN_MESSAGE_MAP(CSample7Doc, CDocument)
	//{{AFX_MSG_MAP(CSample7Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample7Doc construction/destruction

CSample7Doc::CSample7Doc()
{
	// TODO: add one-time construction code here

}

CSample7Doc::~CSample7Doc()
{
}

BOOL CSample7Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSample7Doc serialization

void CSample7Doc::Serialize(CArchive& ar)
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
// CSample7Doc diagnostics

#ifdef _DEBUG
void CSample7Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSample7Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample7Doc commands
