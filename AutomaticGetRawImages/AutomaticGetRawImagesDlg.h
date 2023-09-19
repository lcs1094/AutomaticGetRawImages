
// AutomaticGetRawImagesDlg.h : ��� ����
//

#pragma once


// CAutomaticGetRawImagesDlg ��ȭ ����
class CAutomaticGetRawImagesDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CAutomaticGetRawImagesDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTOMATICGETRAWIMAGES_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;
	CString SourcePath;
	CString RAWPath;
	CString TargetPath;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CWinThread* m_pThread;
	static UINT CopyFiles(LPVOID param);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedOk();
};
