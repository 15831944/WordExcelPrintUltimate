
#pragma once

#include "../MsWord/CMsWordApplication.h"
#include "../MsWord/CMsWordDocument0.h"
#include "../MsWord/CMsWordDocuments.h"
#include "../MsWord/CMSWordPageSetup.h"

#include "../WpsWord/CWpsWordApplication.h"
#include "../WpsWord/CWpsWordDocument0.h"
#include "../WpsWord/CWpsWordDocuments.h"
#include "../WpsWord/CWpsWordPageSetup.h"

#include "CommonMethod.h"


class PrintWord
{
public:
	PrintWord();
	~PrintWord();
	
	/**
	*  @brief    ����word��ӡʵ��
	*
	*  @return   ���ش����״̬
	*/
	PrintErrorStatus BeginPrintOutWord();
	
	/**
	*  @brief    ִ�д�ӡ
	*
	*  @param    CString strSourceFile			Ҫ��ӡ��Դ�ļ�������·��
	*  @param    CString strOutputFilename		Ҫ�������ָ��Ŀ¼����·������ֱ���ڴ�ӡ����ӡ��������L""����
	*  @param    CString strPrinterName			ָ����ӡ�������ƣ�������ϵͳĬ�ϴ�ӡ����ӡ��������L""����
	*  @param    WdPaperSize dmPaperType		��ӡ��ֽ�Ŵ�С
	*  @param    WdOrientation dmOrient			��ӡ�ķ��򣨺����ӡOR�����ӡ��
	*  @param    long lCopies					��ӡ�ķ���
	*  @return   PrintErrorStatus				���ش����״̬
	*/
	PrintErrorStatus PrintOutWord(CString strSourceFile, CString strOutputFilename, CString strPrinterName, WdPaperSize dmPaperType, WdOrientation dmOrient, long lCopies);
	
	/**
	*  @brief    ����ʵ��
	*
	*  @return   void
	*/
	void EndPrintOutWord();


private:
	
	/**
	*  @brief    ��ӡ΢�� word
	*
	*  @param    CString strSourceFile				Ҫ��ӡ��Դ�ļ�������·��
	*  @param    CString strOutputFilename			Ҫ�������ָ��Ŀ¼����·������ֱ���ڴ�ӡ����ӡ��������L""����
	*  @param    CString strDefaultPrinter			Ĭ�ϴ�ӡ��������
	*  @param    WdPaperSize dmPaperType			��ӡ��ֽ�Ŵ�С
	*  @param    WdOrientation dmOrient				��ӡ�ķ��򣨺����ӡOR�����ӡ��
	*  @param    long lCopies						��ӡ�ķ���
	*  @return   PrintErrorStatus					���ش����״̬
	*/
	PrintErrorStatus PrintOutMSWord(CString strSourceFile, CString strOutputFilename, CString strDefaultPrinter, WdPaperSize dmPaperType, WdOrientation dmOrient, long lCopies);
	
	/**
	*  @brief    ��ӡ��ɽ word
	*
	*  @param    CString strSourceFile				Ҫ��ӡ��Դ�ļ�������·��
	*  @param    CString strOutputFilename			Ҫ�������ָ��Ŀ¼����·������ֱ���ڴ�ӡ����ӡ��������L""����
	*  @param    CString strDefaultPrinter			Ĭ�ϴ�ӡ��������
	*  @param    WdPaperSize dmPaperType			��ӡ��ֽ�Ŵ�С
	*  @param    WdOrientation dmOrient				��ӡ�ķ��򣨺����ӡOR�����ӡ��
	*  @param    long lCopies						��ӡ�ķ���
	*  @return   PrintErrorStatus					���ش����״̬
	*/
	PrintErrorStatus PrintOutWPSWord(CString strSourceFile, CString strOutputFilename, CString strDefaultPrinter, WdPaperSize dmPaperType, WdOrientation dmOrient, long lCopies);
	
	/**
	*  @brief    ����ʵ��
	*
	*  @return   void
	*/
	void QuitMsDispatch();

private:
	CMsWordApplication _wordApp;		//wordʵ��
	bool _bIsMsWord;					//�Ƿ�Ϊ΢��word
	COleVariant _vOpt;
};