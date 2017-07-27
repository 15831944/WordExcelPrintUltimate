#include "stdafx.h"
#include "CommonMethod.h"
#include "WINSPOOL.H" 

CString CCommonMethod::GetPath()
{
	CString strPath;

	// ��ȡacad.exe�ļ�·��
	TCHAR* pBuffer = strPath.GetBuffer(MAX_PATH);
	GetModuleFileName(GetModuleHandle(NULL), pBuffer, MAX_PATH);
	strPath.ReleaseBuffer();

	// ȥ��acad.exe�ļ���
	strPath = strPath.Left(strPath.ReverseFind(L'\\') + 1);

	return strPath;
}

void CCommonMethod::AvoidOtherProgrameRunning()
{
	// ���Visual Studio2008����excel automation��ȡExcel�ĵ�����ʱ�������ʾ��������һ����������������,�˲����޷���ɵ�����
	AfxOleGetMessageFilter()->EnableBusyDialog(FALSE);
	AfxOleGetMessageFilter()->SetBusyReply(SERVERCALL_RETRYLATER);
	AfxOleGetMessageFilter()->EnableNotRespondingDialog(TRUE);
	AfxOleGetMessageFilter()->SetMessagePendingDelay(-1);
}

CString CCommonMethod::GetDeafultPrinter()
{
	// �õ�Ĭ�ϴ�ӡ�豸����
	CString strDefualtDev = TEXT("");
	PRINTDLG pd;
	LPDEVMODE lpDevMode;
	if (AfxGetApp()->GetPrinterDeviceDefaults(&pd))
	{
		lpDevMode = (LPDEVMODE)GlobalLock(pd.hDevMode);
		if (lpDevMode)
		{
			strDefualtDev = lpDevMode->dmDeviceName;
		}
		GlobalUnlock(pd.hDevMode);
	}
	return strDefualtDev;
}

CString CCommonMethod::SetPrinterPara(CString strActivePrinter)
{
	if (strActivePrinter == L"") return L"";

	// �õ�Ĭ�ϴ�ӡ�豸����
	CString strDefualtDev = TEXT("");
	PRINTDLG pd;
	LPDEVMODE lpDevMode;
	if (AfxGetApp()->GetPrinterDeviceDefaults(&pd))
	{
		lpDevMode = (LPDEVMODE)GlobalLock(pd.hDevMode);
		if (lpDevMode)
		{
			strDefualtDev = lpDevMode->dmDeviceName;
		}
		GlobalUnlock(pd.hDevMode);
	}
	// ָ���Ĵ�ӡ������
	::SetDefaultPrinter(strActivePrinter);
	// �õ��ո��趨�Ĵ�ӡ������
	if (AfxGetApp()->GetPrinterDeviceDefaults(&pd))
	{
		lpDevMode = (LPDEVMODE)GlobalLock(pd.hDevMode);
		if (lpDevMode)
		{
			lpDevMode->dmPaperSize = DMPAPER_A3;    // �趨��ӡֽ�ŷ���
			lpDevMode->dmOrientation = DMORIENT_LANDSCAPE; // �趨�����ӡ
			lpDevMode->dmPrintQuality = 600;     // �趨��ӡ���ֱ���
		}
		GlobalUnlock(pd.hDevMode);
	}

	return strDefualtDev;
}

void CCommonMethod::ResetDeafultPrinter(CString strDefaultPrinter)
{
	if (strDefaultPrinter != L"")
	{
		/// ��ԭĬ�ϵĴ�ӡ�豸�趨
		::SetDefaultPrinter(strDefaultPrinter);
	}
}

void CCommonMethod::Sample()
{
	UINT iBuffSize = DeviceCapabilities(L"Microsoft Print to PDF", NULL, DC_PAPERNAMES, NULL, NULL);
	if (iBuffSize > 0)
	{
		TCHAR  szPaperNameList[32][64];
		UINT iFlag = DeviceCapabilities(L"Microsoft Print to PDF", NULL, DC_PAPERNAMES, (LPWSTR)szPaperNameList, NULL);
		if (iFlag != -1)
		{
			for (int i = 0; i < iBuffSize; i++)
			{
				CString str = szPaperNameList[i];
				int j = 0;
				//m_vecPaperName.push_back(szPaperNameList[i]);
			}
		}
	}

	iBuffSize = DeviceCapabilities(L"Microsoft Print to PDF", NULL, DC_PAPERS, NULL, NULL);
	if (iBuffSize > 0)
	{
		WORD arrPaperSize[32];
		memset(arrPaperSize, 0, 32 * sizeof(WORD));
		UINT iFlag = DeviceCapabilities(L"Microsoft Print to PDF", NULL, DC_PAPERS, (LPWSTR)arrPaperSize, NULL);
		if (iFlag != -1)
		{
			for (int i = 0; i < iBuffSize; i++)
			{
				WORD str = arrPaperSize[i];
				int j = 0;
				//m_vecPaperSize.push_back(arrPaperSize[i]);
			}
		}
	}
}
