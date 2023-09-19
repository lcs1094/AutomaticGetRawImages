
// AutomaticGetRawImagesDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "AutomaticGetRawImages.h"
#include "AutomaticGetRawImagesDlg.h"
#include <queue>
#include <vector>
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAutomaticGetRawImagesDlg 대화 상자



CAutomaticGetRawImagesDlg::CAutomaticGetRawImagesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AUTOMATICGETRAWIMAGES_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutomaticGetRawImagesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAutomaticGetRawImagesDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAutomaticGetRawImagesDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAutomaticGetRawImagesDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAutomaticGetRawImagesDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &CAutomaticGetRawImagesDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAutomaticGetRawImagesDlg 메시지 처리기

BOOL CAutomaticGetRawImagesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CAutomaticGetRawImagesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CAutomaticGetRawImagesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CAutomaticGetRawImagesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAutomaticGetRawImagesDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString strFolderPath;
	// 폴더 선택 다이얼로그
	CFolderPickerDialog Picker(_T(""), OFN_FILEMUSTEXIST);
	if (Picker.DoModal() == IDOK)
	{
		// 선택된 폴더 경로얻음
		strFolderPath = Picker.GetPathName();

		// 경로(strFolderPath)를 이용하여 이후작업 추가
	}

	CString str;
	str.Format(_T("%s"), strFolderPath);
	SetDlgItemText(IDC_EDIT_JPG, str);

	SourcePath = strFolderPath;

	UpdateData(FALSE);
}


void CAutomaticGetRawImagesDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	CString strFolderPath;
	// 폴더 선택 다이얼로그
	CFolderPickerDialog Picker(_T(""), OFN_FILEMUSTEXIST);
	if (Picker.DoModal() == IDOK)
	{
		// 선택된 폴더 경로얻음
		strFolderPath = Picker.GetPathName();

		// 경로(strFolderPath)를 이용하여 이후작업 추가
	}

	CString str;
	str.Format(_T("%s"), strFolderPath);
	SetDlgItemText(IDC_EDIT_RAW, str);

	RAWPath = strFolderPath;

	UpdateData(FALSE);
}


void CAutomaticGetRawImagesDlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	CString strFolderPath;
	// 폴더 선택 다이얼로그
	CFolderPickerDialog Picker(_T(""), OFN_FILEMUSTEXIST);
	if (Picker.DoModal() == IDOK)
	{
		// 선택된 폴더 경로얻음
		strFolderPath = Picker.GetPathName();

		// 경로(strFolderPath)를 이용하여 이후작업 추가
	}

	CString str;
	str.Format(_T("%s"), strFolderPath);
	SetDlgItemText(IDC_EDIT_DIR, str);

	TargetPath = strFolderPath;

	UpdateData(FALSE);
}


void CAutomaticGetRawImagesDlg::OnBnClickedOk()
{
	if (SourcePath.IsEmpty()) {
		AfxMessageBox(_T("JPG 폴더 미설정"));
	}
	else if (RAWPath.IsEmpty()) {
		AfxMessageBox(_T("RAW 폴더 미설정"));
	}
	else if (TargetPath.IsEmpty()) {
		AfxMessageBox(_T("대상 폴더 미설정"));
	}
	else {
		m_pThread = AfxBeginThread(CopyFiles, this);
	}
}

UINT CAutomaticGetRawImagesDlg::CopyFiles(LPVOID param)
{
	std::queue<CString> fileVec;

	CAutomaticGetRawImagesDlg* myself = (CAutomaticGetRawImagesDlg*)param;

	myself->SetDlgItemText(IDC_STATIC_NAME, _T("분석중입니다..."));
	//SetDlgItemText(IDC_STATIC_NAME, _T("분석중입니다..."));
	CString spath;
	spath.Format(_T("%s/*.jpg"), myself->SourcePath);

	// 검색 클래스
	CFileFind sfinder;

	// CFileFind는 파일, 디렉터리가 존재하면 TRUE 를 반환함
	BOOL sbWorking = sfinder.FindFile(spath); //

	CString sfileName;
	CString fileProgress;
	while (sbWorking)
	{
		//다음 파일 or 폴더 가 존재하면다면 TRUE 반환
		sbWorking = sfinder.FindNextFile();

		// folder 일 경우는 continue
		if (sfinder.IsDirectory() || sfinder.IsDots())
			continue;

		// 파일 일때

		//파일의 이름
		CString _fileName = sfinder.GetFileName();

		// 현재폴더 상위폴더 썸네일파일은 제외
		if (_fileName == _T("Thumbs.db")) continue;

		sfileName = sfinder.GetFileTitle();
		fileVec.push_back(sfileName);
		fileProgress.Format(_T("0  /  %d"), fileVec.size());
		//읽어온 파일 이름을 리스트박스에 넣음
	}

	CString tpath;
	tpath.Format(_T("%s/*.cr3"), myself->TargetPath);

	// CFileFind는 파일, 디렉터리가 존재하면 TRUE 를 반환함

	CString fileName;
	CString targetfile;
	CString sourcefile;

	for (int i = 0; i < fileVec.size(); i++)
	{
		fileName = fileVec[i];
		sourcefile.Format(_T("%s\\%s.cr3"), myself->RAWPath, fileName);
		targetfile.Format(_T("%s\\%s.cr3"), myself->TargetPath, fileName);
		myself->SetDlgItemText(IDC_STATIC_NAME, fileName);

		fileProgress.Format(_T("%d / %d"), i + 1, fileVec.size());
		myself->SetDlgItemText(IDC_STATIC_PROGRESS, fileProgress);
		CopyFile(sourcefile, targetfile, FALSE);

	}
	AfxMessageBox(_T("완료"));
	return 0;
}