// sample6Doc.cpp : implementation of the CSample6Doc class
//

#include "stdafx.h"
#include "sample6.h"

#include "sample6Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSample6Doc

IMPLEMENT_DYNCREATE(CSample6Doc, CDocument)

BEGIN_MESSAGE_MAP(CSample6Doc, CDocument)
	//{{AFX_MSG_MAP(CSample6Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample6Doc construction/destruction

CSample6Doc::CSample6Doc()
{
	// TODO: add one-time construction code here

}

CSample6Doc::~CSample6Doc()
{
}

BOOL CSample6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSample6Doc serialization

void CSample6Doc::Serialize(CArchive& ar)
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
// CSample6Doc diagnostics

#ifdef _DEBUG
void CSample6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSample6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample6Doc commands
