// sample18Doc.cpp : implementation of the CSample18Doc class
//

#include "stdafx.h"
#include "sample18.h"

#include "sample18Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSample18Doc

IMPLEMENT_DYNCREATE(CSample18Doc, CDocument)

BEGIN_MESSAGE_MAP(CSample18Doc, CDocument)
	//{{AFX_MSG_MAP(CSample18Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample18Doc construction/destruction

CSample18Doc::CSample18Doc()
{
	// TODO: add one-time construction code here

}

CSample18Doc::~CSample18Doc()
{
}

BOOL CSample18Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSample18Doc serialization

void CSample18Doc::Serialize(CArchive& ar)
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
// CSample18Doc diagnostics

#ifdef _DEBUG
void CSample18Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSample18Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample18Doc commands
