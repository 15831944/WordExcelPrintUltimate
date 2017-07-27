
// DlgProxy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WordExcelPrintUltimate.h"
#include "DlgProxy.h"
#include "WordExcelPrintUltimateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWordExcelPrintUltimateDlgAutoProxy

IMPLEMENT_DYNCREATE(CWordExcelPrintUltimateDlgAutoProxy, CCmdTarget)

CWordExcelPrintUltimateDlgAutoProxy::CWordExcelPrintUltimateDlgAutoProxy()
{
	EnableAutomation();
	
	// ΪʹӦ�ó������Զ��������ڻ״̬ʱһֱ���� 
	//	���У����캯������ AfxOleLockApp��
	AfxOleLockApp();

	// ͨ��Ӧ�ó����������ָ��
	//  �����ʶԻ���  ���ô�����ڲ�ָ��
	//  ָ��Ի��򣬲����öԻ���ĺ���ָ��ָ��
	//  �ô���
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CWordExcelPrintUltimateDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CWordExcelPrintUltimateDlg)))
		{
			m_pDialog = reinterpret_cast<CWordExcelPrintUltimateDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CWordExcelPrintUltimateDlgAutoProxy::~CWordExcelPrintUltimateDlgAutoProxy()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	//	������������ AfxOleUnlockApp��
	//  ���������������⣬�⻹���������Ի���
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CWordExcelPrintUltimateDlgAutoProxy::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CWordExcelPrintUltimateDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CWordExcelPrintUltimateDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_IWordExcelPrintUltimate ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {D835C838-DC60-4B8B-AD42-FB9E54417843}
static const IID IID_IWordExcelPrintUltimate =
{ 0xD835C838, 0xDC60, 0x4B8B, { 0xAD, 0x42, 0xFB, 0x9E, 0x54, 0x41, 0x78, 0x43 } };

BEGIN_INTERFACE_MAP(CWordExcelPrintUltimateDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CWordExcelPrintUltimateDlgAutoProxy, IID_IWordExcelPrintUltimate, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ���ڴ���Ŀ�� StdAfx.h �ж���
// {5CE108BC-836E-41CE-9946-02DD894E5A53}
IMPLEMENT_OLECREATE2(CWordExcelPrintUltimateDlgAutoProxy, "WordExcelPrintUltimate.Application", 0x5ce108bc, 0x836e, 0x41ce, 0x99, 0x46, 0x2, 0xdd, 0x89, 0x4e, 0x5a, 0x53)


// CWordExcelPrintUltimateDlgAutoProxy ��Ϣ�������
