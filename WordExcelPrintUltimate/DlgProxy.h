
// DlgProxy.h: ͷ�ļ�
//

#pragma once

class CWordExcelPrintUltimateDlg;


// CWordExcelPrintUltimateDlgAutoProxy ����Ŀ��

class CWordExcelPrintUltimateDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CWordExcelPrintUltimateDlgAutoProxy)

	CWordExcelPrintUltimateDlgAutoProxy();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��

// ����
public:
	CWordExcelPrintUltimateDlg* m_pDialog;

// ����
public:

// ��д
	public:
	virtual void OnFinalRelease();

// ʵ��
protected:
	virtual ~CWordExcelPrintUltimateDlgAutoProxy();

	// ���ɵ���Ϣӳ�亯��

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CWordExcelPrintUltimateDlgAutoProxy)

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

