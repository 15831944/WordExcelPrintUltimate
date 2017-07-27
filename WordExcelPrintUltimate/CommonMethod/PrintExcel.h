
#pragma once

#include "../MsExcel/CMsExcelWorksheet.h"
#include "../MsExcel/CMsExcelWorksheets.h"
#include "../MsExcel/CMsExcelWorkbook.h"
#include "../MsExcel/CMsExcelWorkbooks.h"
#include "../MsExcel/CMsExcelApplication.h"
#include "../MsExcel/CMsExcelPageSetup.h"

#include "../WpsExcel/CWpsExcelWorksheet.h"
#include "../WpsExcel/CWpsExcelWorksheets.h"
#include "../WpsExcel/CWpsExcelWorkbook.h"
#include "../WpsExcel/CWpsExcelWorkbooks.h"
#include "../WpsExcel/CWpsExcelApplication.h"
#include "../WpsExcel/CWpsExcelPageSetup.h"

#include "CommonMethod.h"

class PrintExcel
{
public:
	PrintExcel();
	~PrintExcel();
	
	/**
	*  @brief    ����word��ӡʵ��
	*
	*  @return   ���ش����״̬
	*/
	PrintErrorStatus BeginPrintOutExcel();
	
	/**
	*  @brief    ִ�д�ӡ
	*
	*  @param    CString strSourceFile			Ҫ��ӡ��Դ�ļ�������·��
	*  @param    CString strOutputFilename		Ҫ�������ָ��Ŀ¼����·������ֱ���ڴ�ӡ����ӡ��������L""����
	*  @param    CString strPrinterName			ָ����ӡ�������ƣ�������ϵͳĬ�ϴ�ӡ����ӡ��������L""����
	*  @param    XlPaperSize dmPaperType		��ӡ��ֽ�Ŵ�С
	*  @param    XlPageOrientation dmOrient		��ӡ�ķ��򣨺����ӡOR�����ӡ��
	*  @param    long lCopies					��ӡ�ķ���
	*  @return   PrintErrorStatus				���ش����״̬
	*/
	PrintErrorStatus PrintOutExcel(CString strSourceFile, CString strOutputFilename, CString strPrinterName, XlPaperSize dmPaperType, XlPageOrientation dmOrient, long lCopies);
	
	/**
	*  @brief    ����ʵ��
	*
	*  @return   void
	*/
	void EndPrintOutExcel();
private:
	
	/**
	*  @brief    ��ӡ΢�� excel
	*
	*  @param    CString strSourceFile			Ҫ��ӡ��Դ�ļ�������·��
	*  @param    CString strOutputFilename		Ҫ�������ָ��Ŀ¼����·������ֱ���ڴ�ӡ����ӡ��������L""����
	*  @param    CString strDefaultPrinter		Ĭ�ϴ�ӡ��������
	*  @param    XlPaperSize dmPaperType		��ӡ��ֽ�Ŵ�С
	*  @param    XlPageOrientation dmOrient		��ӡ�ķ��򣨺����ӡOR�����ӡ��
	*  @param    long lCopies					��ӡ�ķ���
	*  @return   PrintErrorStatus				���ش����״̬
	*/
	PrintErrorStatus PrintOutMsExcel(CString strSourceFile, CString strOutputFilename, CString strDefaultPrinter, XlPaperSize dmPaperType, XlPageOrientation dmOrient, long lCopies);
	
	/**
	*  @brief    ��ӡ��ɽ excel
	*
	*  @param    CString strSourceFile			Ҫ��ӡ��Դ�ļ�������·��
	*  @param    CString strOutputFilename		Ҫ�������ָ��Ŀ¼����·������ֱ���ڴ�ӡ����ӡ��������L""����
	*  @param    CString strDefaultPrinter		Ĭ�ϴ�ӡ��������
	*  @param    XlPaperSize dmPaperType		��ӡ��ֽ�Ŵ�С
	*  @param    XlPageOrientation dmOrient		��ӡ�ķ��򣨺����ӡOR�����ӡ��
	*  @param    long lCopies					��ӡ�ķ���
	*  @return   PrintErrorStatus				���ش����״̬
	*/
	PrintErrorStatus PrintOutWpsExcel(CString strSourceFile, CString strOutputFilename, CString strDefaultPrinter, XlPaperSize dmPaperType, XlPageOrientation dmOrient, long lCopies);
	
	/**
	*  @brief    ����ʵ��
	*
	*  @return   void
	*/
	void QuitMsDispatch();
	
	/**
	*  @brief    ����ʵ��
	*
	*  @return   void
	*/
	void QuitWpsDispatch();

private:
	CMsExcelApplication _excelMsApp;
	CWpsExcelApplication _excelWpsApp;
	bool _bIsMsExcel;
	COleVariant _vOpt;
};