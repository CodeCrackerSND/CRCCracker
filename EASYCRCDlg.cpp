// EASYCRCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EASYCRC.h"
#include "EASYCRCDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


DWORD s_arrdwCrc32Table[256] =
{
	0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA,
	0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
	0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
	0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
	0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE,
	0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
	0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC,
	0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
	0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172,
	0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
	0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940,
	0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
	0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116,
	0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
	0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
	0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,

	0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A,
	0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
	0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818,
	0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
	0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E,
	0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
	0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C,
	0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
	0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2,
	0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
	0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0,
	0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
	0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086,
	0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
	0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4,
	0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,

	0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A,
	0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
	0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8,
	0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
	0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE,
	0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
	0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC,
	0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
	0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252,
	0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
	0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60,
	0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
	0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
	0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
	0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04,
	0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,

	0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A,
	0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
	0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38,
	0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,
	0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E,
	0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
	0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C,
	0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
	0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2,
	0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
	0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0,
	0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
	0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6,
	0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
	0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94,
	0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D,
};


DWORD reverseCrc32Table[256] =
{
    0x00, 0x41, 0xc3, 0x82, 0x86, 0xc7, 0x45, 0x04,
    0x4d, 0x0c, 0x8e, 0xcf, 0xcb, 0x8a, 0x08, 0x49,
    0x9a, 0xdb, 0x59, 0x18, 0x1c, 0x5d, 0xdf, 0x9e,
    0xd7, 0x96, 0x14, 0x55, 0x51, 0x10, 0x92, 0xd3,
    0x75, 0x34, 0xb6, 0xf7, 0xf3, 0xb2, 0x30, 0x71,
    0x38, 0x79, 0xfb, 0xba, 0xbe, 0xff, 0x7d, 0x3c,
    0xef, 0xae, 0x2c, 0x6d, 0x69, 0x28, 0xaa, 0xeb,
    0xa2, 0xe3, 0x61, 0x20, 0x24, 0x65, 0xe7, 0xa6,

    0xea, 0xab, 0x29, 0x68, 0x6c, 0x2d, 0xaf, 0xee,
    0xa7, 0xe6, 0x64, 0x25, 0x21, 0x60, 0xe2, 0xa3,
    0x70, 0x31, 0xb3, 0xf2, 0xf6, 0xb7, 0x35, 0x74,
    0x3d, 0x7c, 0xfe, 0xbf, 0xbb, 0xfa, 0x78, 0x39,
    0x9f, 0xde, 0x5c, 0x1d, 0x19, 0x58, 0xda, 0x9b,
    0xd2, 0x93, 0x11, 0x50, 0x54, 0x15, 0x97, 0xd6,
    0x05, 0x44, 0xc6, 0x87, 0x83, 0xc2, 0x40, 0x01,
    0x48, 0x09, 0x8b, 0xca, 0xce, 0x8f, 0x0d, 0x4c,

    0x95, 0xd4, 0x56, 0x17, 0x13, 0x52, 0xd0, 0x91,
    0xd8, 0x99, 0x1b, 0x5a, 0x5e, 0x1f, 0x9d, 0xdc,
    0x0f, 0x4e, 0xcc, 0x8d, 0x89, 0xc8, 0x4a, 0x0b,
    0x42, 0x03, 0x81, 0xc0, 0xc4, 0x85, 0x07, 0x46,
    0xe0, 0xa1, 0x23, 0x62, 0x66, 0x27, 0xa5, 0xe4,
    0xad, 0xec, 0x6e, 0x2f, 0x2b, 0x6a, 0xe8, 0xa9,
    0x7a, 0x3b, 0xb9, 0xf8, 0xfc, 0xbd, 0x3f, 0x7e,
    0x37, 0x76, 0xf4, 0xb5, 0xb1, 0xf0, 0x72, 0x33,

    0x7f, 0x3e, 0xbc, 0xfd, 0xf9, 0xb8, 0x3a, 0x7b,
    0x32, 0x73, 0xf1, 0xb0, 0xb4, 0xf5, 0x77, 0x36,
    0xe5, 0xa4, 0x26, 0x67, 0x63, 0x22, 0xa0, 0xe1,
    0xa8, 0xe9, 0x6b, 0x2a, 0x2e, 0x6f, 0xed, 0xac,
    0x0a, 0x4b, 0xc9, 0x88, 0x8c, 0xcd, 0x4f, 0x0e,
    0x47, 0x06, 0x84, 0xc5, 0xc1, 0x80, 0x02, 0x43,
    0x90, 0xd1, 0x53, 0x12, 0x16, 0x57, 0xd5, 0x94,
    0xdd, 0x9c, 0x1e, 0x5f, 0x5b, 0x1a, 0x98, 0xd9
};

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEASYCRCDlg dialog

CEASYCRCDlg::CEASYCRCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEASYCRCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEASYCRCDlg)
	m_xedit2 = _T("");
	m_xedit3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEASYCRCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEASYCRCDlg)
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT2, m_xedit2);
	DDV_MaxChars(pDX, m_xedit2, 8);
	DDX_Text(pDX, IDC_EDIT3, m_xedit3);
	DDV_MaxChars(pDX, m_xedit3, 8);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEASYCRCDlg, CDialog)
	//{{AFX_MSG_MAP(CEASYCRCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEASYCRCDlg message handlers

BOOL CEASYCRCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEASYCRCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEASYCRCDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEASYCRCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEASYCRCDlg::OnButton1() 
{
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, NULL, this);

	if(dlg.DoModal() == IDOK)
		SetDlgItemText(IDC_EDIT1, dlg.GetPathName());	
}

//////////////////////////////////////////////////////////////////////////////
// Helper method to reflect a value, i.e. swap positions of bits 0 and 7,
// 1 and 6, etc.
//////////////////////////////////////////////////////////////////////////////
DWORD Reflect(DWORD value, int count)
{
    for(int i = 0; i < count / 2; i++) {
        DWORD tmp = ((value >> i) ^ (value >> (count - 1 - i))) & 1;
        value ^= ((tmp << i) | (tmp << (count - 1 - i)));
    }
    return value;
} 


//////////////////////////////////////////////////////////////////////////////
// Calculate lookup tables for any polynomial. The default tables use the
// polynomial 0x04c11db7.
//////////////////////////////////////////////////////////////////////////////
void CalculateTables(DWORD polynomial)
{
    // Create CRC lookup table
    for(int i = 0; i < 256; i++) {
        s_arrdwCrc32Table[i] = Reflect(i, 8) << 24;
        for (int j = 0; j < 8; j++) {
            s_arrdwCrc32Table[i] = (s_arrdwCrc32Table[i] << 1) ^ (s_arrdwCrc32Table[i] & (1 << 31) ? 
                            polynomial : 0);
        }
        s_arrdwCrc32Table[i] = Reflect(s_arrdwCrc32Table[i], 32);
    }
    
    // Create reverse CRC lookup table
    for (int j = 0; j < 256; j++) {
        for (int i = 0; i < 256; i++) {
            if ((j ^ (s_arrdwCrc32Table[i] >> 24)) == 0) {
                reverseCrc32Table[j] = i;
                break;
            }
        }
    }
}

DWORD CalculateCRC(unsigned char* bytes, DWORD size_to, DWORD to_skip)
{
	DWORD Result = 0;
	DWORD dwCrc32 = 0xFFFFFFFF;

			// There is a bug in the Microsoft compilers where inline assembly
			// code cannot access static member variables.  This is a work around
			// for that bug.  For more info see Knowledgebase article Q88092
			LPVOID ptrCrc32Table = &s_arrdwCrc32Table;

				// Register use:
				//		eax - CRC32 value
				//		ebx - a lot of things
				//		ecx - CRC32 value
				//		edx - address of end of buffer
				//		esi - address of start of buffer
				//		edi - CRC32 table
				__asm
				{
					// Save the esi and edi registers
					push esi
					push edi

					mov ecx, dwCrc32  // load in ecx the value of dwCrc32
					                  // - FIRST TIME IS 0xFFFFFFFF

					lea edi, s_arrdwCrc32Table	// Load the CRC32 table

					mov edx, bytes			// Load buffer
					add edx, size_to    	// Load dwBytesRead
					sub edx, to_skip        // substract size to skipp
				    mov esi, bytes		    // Calculate the end of the buffer

				crc32loop:
					xor eax, eax				// Clear the eax register
					
					mov al, cl					// Copy low of crc value into al

					xor al, byte ptr [esi]  // Create the index into the CRC32 table
					                        // by xoring low of CRC with current source byte


					mov eax, [edi + eax * 4]	// Get the value out of the table
					shr ecx, 8                  // divide ecx (ecx=curent crc value)
					xor ecx, eax				// xor CRC with the current byte

					inc esi						// Advance the source pointer

					cmp edx, esi				// Have we reached the end of the buffer?
					jne crc32loop

					mov eax,ecx

					// ecx now contain CRC value
					mov Result,ecx

					// Restore the edi and esi registers
					pop edi
					pop esi
				}

//if (to_skip==0)  // if is final value negate it
Result = ~Result;  // negate CRC
return Result;
}

void CEASYCRCDlg::OnButton2() 
{

DWORD dwCrc32, dwErrorCode = NO_ERROR, dwBytesRead, FileSize;
BYTE * FileOffset;

DWORD NewCRC;
char szFilename[400];
HANDLE hFile = NULL;
dwCrc32 = 0xFFFFFFFF;
char str_crc[12];

GetDlgItem(IDC_EDIT2)->GetWindowText(str_crc, 12);
char * p;
NewCRC = strtoul( str_crc, &p, 16 );

GetDlgItem(IDC_EDIT1)->GetWindowText(szFilename, 400);

	try
	{
		// Open the file
		hFile = CreateFile(szFilename,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_FLAG_SEQUENTIAL_SCAN,
			NULL);
		if(hFile == INVALID_HANDLE_VALUE)
			dwErrorCode = GetLastError();
		else
		{
						// There is a bug in the Microsoft compilers where inline assembly
			// code cannot access static member variables.  This is a work around
			// for that bug.  For more info see Knowledgebase article Q88092
			LPVOID ptrCrc32Table = &s_arrdwCrc32Table;

            FileSize = GetFileSize (hFile,0);

FileOffset = (unsigned char *)GlobalAlloc (GMEM_ZEROINIT,FileSize);


if ( ReadFile (hFile,FileOffset,FileSize,&dwBytesRead,0) != 0) 
{


//////////////////////////////////////////////////////////////////////////////
// Finds reverse CRC patch bytes. The method returns four bytes that
// can be appended to the CRC in order to get the desired CRC
//////////////////////////////////////////////////////////////////////////////

	DWORD crc_ = CalculateCRC(FileOffset, FileSize, 4);
	unsigned char patchBytes[4];
	int crcIdx[4];
    int j;


    DWORD iterCrc = ~NewCRC;
    for (j = 3; j >= 0; j--) {
        crcIdx[j] = reverseCrc32Table[iterCrc >> 24];
        iterCrc = (iterCrc ^ s_arrdwCrc32Table[crcIdx[j]]) << 8;
    }

    DWORD crc = ~crc_;
    for (j = 0; j < 4; j++) {
        patchBytes[j] = (unsigned char)((crc ^ crcIdx[j]) & 0xff);
    	crc = (crc >> 8) ^ s_arrdwCrc32Table[patchBytes[j] ^ (crc & 0xff)];
    }

	GlobalFree(FileOffset);

wsprintf(szFilename,"%02X%02X%02X%02X",patchBytes[0],patchBytes[1],patchBytes[2],patchBytes[3]);  // convert number to hexa string
CharUpper(szFilename);
GetDlgItem(IDC_EDIT3)->SetWindowText(szFilename);


		 }  // END READ
		 
		 else
		 {
         GetDlgItem(IDC_EDIT3)->SetWindowText("ERROR");

		 }

	}
	}
	catch(...)
	{
		// An unknown exception happened
		dwErrorCode = ERROR_CRC;
		GetDlgItem(IDC_EDIT3)->SetWindowText("ERROR");
	}

	if(hFile != NULL) CloseHandle(hFile);




}

void CEASYCRCDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
DWORD dwCrc32, dwErrorCode = NO_ERROR;
DWORD dwBytesRead;
DWORD Result,FileSize;
BYTE * FileOffset;

DWORD NewCRC;
char szFilename[400];
HANDLE hFile = NULL;
dwCrc32 = 0xFFFFFFFF;
char str_crc[12];

GetDlgItem(IDC_EDIT2)->GetWindowText(str_crc, 12);
char * p;
NewCRC = strtoul( str_crc, &p, 16 );

GetDlgItem(IDC_EDIT1)->GetWindowText(szFilename, 400);

	try
	{
		// Open the file
		hFile = CreateFile(szFilename,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_FLAG_SEQUENTIAL_SCAN,
			NULL);
		if(hFile == INVALID_HANDLE_VALUE)
			dwErrorCode = GetLastError();
		else
		{
						// There is a bug in the Microsoft compilers where inline assembly
			// code cannot access static member variables.  This is a work around
			// for that bug.  For more info see Knowledgebase article Q88092
			LPVOID ptrCrc32Table = &s_arrdwCrc32Table;

            FileSize = GetFileSize (hFile,0);

FileOffset = (unsigned char *)GlobalAlloc (GMEM_ZEROINIT,FileSize);


if ( ReadFile (hFile,FileOffset,FileSize,&dwBytesRead,0) != 0) 
{
Result = CalculateCRC(FileOffset, FileSize, 0);
GlobalFree(FileOffset);
}  // END READ

else
{
GetDlgItem(IDC_EDIT3)->SetWindowText("ERROR");
}

	}
	}
	catch(...)
	{
		// An unknown exception happened
		dwErrorCode = ERROR_CRC;
		GetDlgItem(IDC_EDIT3)->SetWindowText("ERROR");
	}

	if(hFile != NULL) CloseHandle(hFile);



wsprintf(szFilename,"%x",Result);  // convert number to hexa string
CharUpper(szFilename);
GetDlgItem(IDC_EDIT3)->SetWindowText(szFilename);
}
