// sample13Doc.h : interface of the CSample13Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE13DOC_H__C6D25B78_36ED_41C0_BD13_ED53B71DCD7F__INCLUDED_)
#define AFX_SAMPLE13DOC_H__C6D25B78_36ED_41C0_BD13_ED53B71DCD7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample13Doc : public CDocument
{
protected: // create from serialization only
	CSample13Doc();
	DECLARE_DYNCREATE(CSample13Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample13Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSample13Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample13Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE13DOC_H__C6D25B78_36ED_41C0_BD13_ED53B71DCD7F__INCLUDED_)
