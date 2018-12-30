// sample8Doc.h : interface of the CSample8Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE8DOC_H__BA29619C_1ECF_4484_8650_5E609D9867E4__INCLUDED_)
#define AFX_SAMPLE8DOC_H__BA29619C_1ECF_4484_8650_5E609D9867E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample8Doc : public CDocument
{
protected: // create from serialization only
	CSample8Doc();
	DECLARE_DYNCREATE(CSample8Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample8Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSample8Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample8Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE8DOC_H__BA29619C_1ECF_4484_8650_5E609D9867E4__INCLUDED_)
