// sample18Doc.h : interface of the CSample18Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE18DOC_H__19857C35_3666_492A_9460_09636C7797F6__INCLUDED_)
#define AFX_SAMPLE18DOC_H__19857C35_3666_492A_9460_09636C7797F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample18Doc : public CDocument
{
protected: // create from serialization only
	CSample18Doc();
	DECLARE_DYNCREATE(CSample18Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample18Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSample18Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample18Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE18DOC_H__19857C35_3666_492A_9460_09636C7797F6__INCLUDED_)
