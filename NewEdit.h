#if !defined(AFX_NEWEDIT_H__485B1030_B2FD_49AC_BC12_48317ED91908__INCLUDED_)
#define AFX_NEWEDIT_H__485B1030_B2FD_49AC_BC12_48317ED91908__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// NewEdit window

class NewEdit : public CEdit
{
// Construction
public:
	NewEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NewEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~NewEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(NewEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChangeCbChain(HWND hWndRemove, HWND hWndAfter);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWEDIT_H__485B1030_B2FD_49AC_BC12_48317ED91908__INCLUDED_)
