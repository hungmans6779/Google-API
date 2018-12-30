// sample8Doc.cpp : implementation of the CSample8Doc class
//

#include "stdafx.h"
#include "sample8.h"

#include "sample8Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSample8Doc

IMPLEMENT_DYNCREATE(CSample8Doc, CDocument)

BEGIN_MESSAGE_MAP(CSample8Doc, CDocument)
	//{{AFX_MSG_MAP(CSample8Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample8Doc construction/destruction

CSample8Doc::CSample8Doc()
{
	// TODO: add one-time construction code here

}

CSample8Doc::~CSample8Doc()
{
}

BOOL CSample8Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSample8Doc serialization

void CSample8Doc::Serialize(CArchive& ar)
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
// CSample8Doc diagnostics

#ifdef _DEBUG
void CSample8Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSample8Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample8Doc commands
