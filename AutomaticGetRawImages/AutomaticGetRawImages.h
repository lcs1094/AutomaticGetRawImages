
// AutomaticGetRawImages.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CAutomaticGetRawImagesApp:
// �� Ŭ������ ������ ���ؼ��� AutomaticGetRawImages.cpp�� �����Ͻʽÿ�.
//

class CAutomaticGetRawImagesApp : public CWinApp
{
public:
	CAutomaticGetRawImagesApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CAutomaticGetRawImagesApp theApp;