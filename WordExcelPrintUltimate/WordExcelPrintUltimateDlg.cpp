
// WordExcelPrintUltimateDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WordExcelPrintUltimate.h"
#include "WordExcelPrintUltimateDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include "CommonMethod/PrintWord.h"
#include "CommonMethod/PrintExcel.h"
#include "CommonMethod/CommonMethod.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWordExcelPrintUltimateDlg �Ի���


IMPLEMENT_DYNAMIC(CWordExcelPrintUltimateDlg, CDialogEx);

CWordExcelPrintUltimateDlg::CWordExcelPrintUltimateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWordExcelPrintUltimateDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CWordExcelPrintUltimateDlg::~CWordExcelPrintUltimateDlg()
{
	// ����öԻ������Զ���������
	//  ���˴���ָ��öԻ���ĺ���ָ������Ϊ NULL���Ա�
	//  �˴���֪���öԻ����ѱ�ɾ����
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CWordExcelPrintUltimateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWordExcelPrintUltimateDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDWord, &CWordExcelPrintUltimateDlg::OnBnClickedWord)
	ON_BN_CLICKED(IDEXCEL, &CWordExcelPrintUltimateDlg::OnBnClickedExcel)
END_MESSAGE_MAP()


// CWordExcelPrintUltimateDlg ��Ϣ�������

BOOL CWordExcelPrintUltimateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CWordExcelPrintUltimateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CWordExcelPrintUltimateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���û��ر� UI ʱ������������Ա���������ĳ��
//  �������Զ�����������Ӧ�˳���  ��Щ
//  ��Ϣ�������ȷ����������: �����������ʹ�ã�
//  ������ UI�������ڹرնԻ���ʱ��
//  �Ի�����Ȼ�ᱣ�������

void CWordExcelPrintUltimateDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CWordExcelPrintUltimateDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CWordExcelPrintUltimateDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CWordExcelPrintUltimateDlg::CanExit()
{
	// �����������Ա�����������Զ���
	//  �������Իᱣ�ִ�Ӧ�ó���
	//  ʹ�Ի���������������� UI ����������
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}


void CWordExcelPrintUltimateDlg::OnBnClickedWord()
{
	CCommonMethod::Sample();
	PrintWord pw;
	//��ʼ��ӡ
	pw.BeginPrintOutWord();

	//ִ�д�ӡ
	CString strAppPath = CCommonMethod::GetPath();
	CString strSourceFile = strAppPath + L"�����˵��.doc";
	CString strOutputFilename = strAppPath + L"word.pdf";
	pw.PrintOutWord(strSourceFile, strOutputFilename, L"Microsoft Print to PDF", WdPaperSize::wpsPaperA3, WdOrientation::wpsOrientLandscape, 1);

	strOutputFilename = strAppPath + L"word1.pdf";
	pw.PrintOutWord(strSourceFile, strOutputFilename, L"Microsoft Print to PDF", WdPaperSize::wpsPaperA4, WdOrientation::wpsOrientPortrait, 1);

	//������ӡ
	pw.EndPrintOutWord();

	CDialogEx::OnOK();
}


void CWordExcelPrintUltimateDlg::OnBnClickedExcel()
{
	PrintExcel pe;

	//��ʼ��ӡ
	pe.BeginPrintOutExcel();

	//ִ�д�ӡ
	CString strAppPath = CCommonMethod::GetPath();
	CString strSourceFile = strAppPath + L"�����˵��.xls";
	CString strOutputFilename = strAppPath + L"excel.pdf";

	pe.PrintOutExcel(strSourceFile, strOutputFilename, L"Microsoft Print to PDF", XlPaperSize::xlPaperA3, XlPageOrientation::xlLandscape, 1);

	strOutputFilename = strAppPath + L"excel1.pdf";
	pe.PrintOutExcel(strSourceFile, strOutputFilename, L"Microsoft Print to PDF", XlPaperSize::xlPaperA4, XlPageOrientation::xlPortrait, 1);

	//������ӡ
	pe.EndPrintOutExcel();

	CDialogEx::OnOK();
}
