// sample5Doc.h : interface of the CSample5Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE5DOC_H__39729593_9A29_40E3_9C38_2D1F3933B935__INCLUDED_)
#define AFX_SAMPLE5DOC_H__39729593_9A29_40E3_9C38_2D1F3933B935__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample5Doc : public CDocument
{
protected: // create from serialization only
	CSample5Doc();
	DECLARE_DYNCREATE(CSample5Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample5Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSample5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample5Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE5DOC_H__39729593_9A29_40E3_9C38_2D1F3933B935__INCLUDED_)
