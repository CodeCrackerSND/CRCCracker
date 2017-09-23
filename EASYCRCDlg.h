// EASYCRCDlg.h : header file
//

#include "NewEdit.h"

#if !defined(AFX_EASYCRCDLG_H__8EC91CF7_7396_4C6D_8624_AB74A0ECE19F__INCLUDED_)
#define AFX_EASYCRCDLG_H__8EC91CF7_7396_4C6D_8624_AB74A0ECE19F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEASYCRCDlg dialog

class CEASYCRCDlg : public CDialog
{
// Construction
public:
	CEASYCRCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEASYCRCDlg)
	enum { IDD = IDD_EASYCRC_DIALOG };
	NewEdit	m_edit3;
	NewEdit	m_edit2;
	CString	m_xedit2;
	CString	m_xedit3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEASYCRCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEASYCRCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EASYCRCDLG_H__8EC91CF7_7396_4C6D_8624_AB74A0ECE19F__INCLUDED_)
