
// WordExcelPrintUltimateDlg.h : ͷ�ļ�
//

#pragma once

class CWordExcelPrintUltimateDlgAutoProxy;


// CWordExcelPrintUltimateDlg �Ի���
class CWordExcelPrintUltimateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWordExcelPrintUltimateDlg);
	friend class CWordExcelPrintUltimateDlgAutoProxy;

// ����
public:
	CWordExcelPrintUltimateDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CWordExcelPrintUltimateDlg();

// �Ի�������
	enum { IDD = IDD_WORDEXCELPRINTULTIMATE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	CWordExcelPrintUltimateDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedWord();
	afx_msg void OnBnClickedExcel();
};
