// sample19Doc.h : interface of the CSample19Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE19DOC_H__E7A5EF1E_119A_4166_9E46_3D9F08EA1ED8__INCLUDED_)
#define AFX_SAMPLE19DOC_H__E7A5EF1E_119A_4166_9E46_3D9F08EA1ED8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample19Doc : public CDocument
{
protected: // create from serialization only
	CSample19Doc();
	DECLARE_DYNCREATE(CSample19Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample19Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSample19Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample19Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE19DOC_H__E7A5EF1E_119A_4166_9E46_3D9F08EA1ED8__INCLUDED_)
