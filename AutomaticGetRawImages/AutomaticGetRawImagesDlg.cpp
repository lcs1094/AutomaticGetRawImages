
// AutomaticGetRawImagesDlg.cpp : ���� ����
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


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CAutomaticGetRawImagesDlg ��ȭ ����



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


// CAutomaticGetRawImagesDlg �޽��� ó����

BOOL CAutomaticGetRawImagesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CAutomaticGetRawImagesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CAutomaticGetRawImagesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAutomaticGetRawImagesDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString strFolderPath;
	// ���� ���� ���̾�α�
	CFolderPickerDialog Picker(_T(""), OFN_FILEMUSTEXIST);
	if (Picker.DoModal() == IDOK)
	{
		// ���õ� ���� ��ξ���
		strFolderPath = Picker.GetPathName();

		// ���(strFolderPath)�� �̿��Ͽ� �����۾� �߰�
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
	// ���� ���� ���̾�α�
	CFolderPickerDialog Picker(_T(""), OFN_FILEMUSTEXIST);
	if (Picker.DoModal() == IDOK)
	{
		// ���õ� ���� ��ξ���
		strFolderPath = Picker.GetPathName();

		// ���(strFolderPath)�� �̿��Ͽ� �����۾� �߰�
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
	// ���� ���� ���̾�α�
	CFolderPickerDialog Picker(_T(""), OFN_FILEMUSTEXIST);
	if (Picker.DoModal() == IDOK)
	{
		// ���õ� ���� ��ξ���
		strFolderPath = Picker.GetPathName();

		// ���(strFolderPath)�� �̿��Ͽ� �����۾� �߰�
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
		AfxMessageBox(_T("JPG ���� �̼���"));
	}
	else if (RAWPath.IsEmpty()) {
		AfxMessageBox(_T("RAW ���� �̼���"));
	}
	else if (TargetPath.IsEmpty()) {
		AfxMessageBox(_T("��� ���� �̼���"));
	}
	else {
		m_pThread = AfxBeginThread(CopyFiles, this);
	}
}

UINT CAutomaticGetRawImagesDlg::CopyFiles(LPVOID param)
{
	std::queue<CString> fileVec;

	CAutomaticGetRawImagesDlg* myself = (CAutomaticGetRawImagesDlg*)param;

	myself->SetDlgItemText(IDC_STATIC_NAME, _T("�м����Դϴ�..."));
	//SetDlgItemText(IDC_STATIC_NAME, _T("�м����Դϴ�..."));
	CString spath;
	spath.Format(_T("%s/*.jpg"), myself->SourcePath);

	// �˻� Ŭ����
	CFileFind sfinder;

	// CFileFind�� ����, ���͸��� �����ϸ� TRUE �� ��ȯ��
	BOOL sbWorking = sfinder.FindFile(spath); //

	CString sfileName;
	CString fileProgress;
	while (sbWorking)
	{
		//���� ���� or ���� �� �����ϸ�ٸ� TRUE ��ȯ
		sbWorking = sfinder.FindNextFile();

		// folder �� ���� continue
		if (sfinder.IsDirectory() || sfinder.IsDots())
			continue;

		// ���� �϶�

		//������ �̸�
		CString _fileName = sfinder.GetFileName();

		// �������� �������� ����������� ����
		if (_fileName == _T("Thumbs.db")) continue;

		sfileName = sfinder.GetFileTitle();
		fileVec.push_back(sfileName);
		fileProgress.Format(_T("0  /  %d"), fileVec.size());
		//�о�� ���� �̸��� ����Ʈ�ڽ��� ����
	}

	CString tpath;
	tpath.Format(_T("%s/*.cr3"), myself->TargetPath);

	// CFileFind�� ����, ���͸��� �����ϸ� TRUE �� ��ȯ��

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
	AfxMessageBox(_T("�Ϸ�"));
	return 0;
}