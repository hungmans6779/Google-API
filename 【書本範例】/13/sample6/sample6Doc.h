// sample6Doc.h : interface of the CSample6Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE6DOC_H__610FE934_26B3_4E26_B4A4_2E17ACE7E641__INCLUDED_)
#define AFX_SAMPLE6DOC_H__610FE934_26B3_4E26_B4A4_2E17ACE7E641__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample6Doc : public CDocument
{
protected: // create from serialization only
	CSample6Doc();
	DECLARE_DYNCREATE(CSample6Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample6Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSample6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample6Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE6DOC_H__610FE934_26B3_4E26_B4A4_2E17ACE7E641__INCLUDED_)
