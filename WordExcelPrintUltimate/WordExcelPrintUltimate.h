
// WordExcelPrintUltimate.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWordExcelPrintUltimateApp: 
// �йش����ʵ�֣������ WordExcelPrintUltimate.cpp
//

class CWordExcelPrintUltimateApp : public CWinApp
{
public:
	CWordExcelPrintUltimateApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWordExcelPrintUltimateApp theApp;