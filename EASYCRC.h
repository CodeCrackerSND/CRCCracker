// EASYCRC.h : main header file for the EASYCRC application
//

#if !defined(AFX_EASYCRC_H__C97C03D6_3AD5_4D4A_B073_71673C5B934D__INCLUDED_)
#define AFX_EASYCRC_H__C97C03D6_3AD5_4D4A_B073_71673C5B934D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEASYCRCApp:
// See EASYCRC.cpp for the implementation of this class
//

class CEASYCRCApp : public CWinApp
{
public:
	CEASYCRCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEASYCRCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEASYCRCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EASYCRC_H__C97C03D6_3AD5_4D4A_B073_71673C5B934D__INCLUDED_)
