#pragma once

// ����״̬
enum PrintErrorStatus
{
	ePrintOk = 0,

	ePrintOfficeThrowException = 1,		// ��ӡ�������׳��쳣
	ePrintDocumentBeenOpened = 2,	// ģ���ĵ��ѱ��򿪣���ر��ĵ���
	ePrintWPSVersionBelow2010 = 3,  // �밲װWps office2010���ϰ汾
	ePrintNoneWpsOfficeInstall = 4,		// �밲װOffice��Wps
};

// word��ӡ������
enum WdOrientation
{
	wpsOrientPortrait = 0,		//����
	wpsOrientLandscape = 1		//����
};

// word��ӡֽ�Ŵ�С
enum WdPaperSize
{
	wpsPaper10x14 = 0,
	wpsPaper11x17 = 1,
	wpsPaperLetter = 2,
	wpsPaperLetterSmall = 3,
	wpsPaperLegal = 4,
	wpsPaperExecutive = 5,
	wpsPaperA3 = 6,
	wpsPaperA4 = 7,
	wpsPaperA4Small = 8,
	wpsPaperA5 = 9,
	wpsPaperB4 = 10,
	wpsPaperB5 = 11,
	wpsPaperCSheet = 12,
	wpsPaperFanfoldLegalGerman = 13,
	wpsPaperFanfoldStdGerman = 14,
	wpsPaperFanfoldUS = 15,
	wpsPaperFolio = 16,
	wpsPaperLedger = 17,
	wpsPaperNote = 18,
	wpsPaperQuarto = 19,
	wpsPaperStatement = 20,
	wpsPaperTabloid = 21,
	wpsPaperEnvelope9 = 22,
	wpsPaperEnvelope10 = 23,
	wpsPaperEnvelope11 = 24,
	wpsPaperEnvelope14 = 25,
	wpsPaperEnvelopeB4 = 26,
	wpsPaperEnvelopeB5 = 27,
	wpsPaperEnvelopeB6 = 28,
	wpsPaperEnvelopeC3 = 29,
	wpsPaperEnvelopeC4 = 30,
	wpsPaperEnvelopeC5 = 31,
	wpsPaperEnvelopeC6 = 32,
	wpsPaperEnvelopeC65 = 33,
	wpsPaperEnvelopeDL = 34,
	wpsPaperEnvelopeItaly = 35,
	wpsPaperEnvelopeMonarch = 36,
	wpsPaperEnvelopePersonal = 37,
	wpsPaperCustom = 38
};

// excel��ӡ����
enum XlPageOrientation
{
	xlLandscape = 2,		//����
	xlPortrait = 1			//����
};

// excel��ӡֽ�Ŵ�С
enum XlPaperSize
{
	xlPaper10x14 = 16,
	xlPaper11x17 = 17,
	xlPaperA3 = 8,
	xlPaperA4 = 9,
	xlPaperA4Small = 10,
	xlPaperA5 = 11,
	xlPaperB4 = 12,
	xlPaperB5 = 13,
	xlPaperCsheet = 24,
	xlPaperDsheet = 25,
	xlPaperEnvelope10 = 20,
	xlPaperEnvelope11 = 21,
	xlPaperEnvelope12 = 22,
	xlPaperEnvelope14 = 23,
	xlPaperEnvelope9 = 19,
	xlPaperEnvelopeB4 = 33,
	xlPaperEnvelopeB5 = 34,
	xlPaperEnvelopeB6 = 35,
	xlPaperEnvelopeC3 = 29,
	xlPaperEnvelopeC4 = 30,
	xlPaperEnvelopeC5 = 28,
	xlPaperEnvelopeC6 = 31,
	xlPaperEnvelopeC65 = 32,
	xlPaperEnvelopeDL = 27,
	xlPaperEnvelopeItaly = 36,
	xlPaperEnvelopeMonarch = 37,
	xlPaperEnvelopePersonal = 38,
	xlPaperEsheet = 26,
	xlPaperExecutive = 7,
	xlPaperFanfoldLegalGerman = 41,
	xlPaperFanfoldStdGerman = 40,
	xlPaperFanfoldUS = 39,
	xlPaperFolio = 14,
	xlPaperLedger = 4,
	xlPaperLegal = 5,
	xlPaperLetter = 1,
	xlPaperLetterSmall = 2,
	xlPaperNote = 18,
	xlPaperQuarto = 15,
	xlPaperStatement = 6,
	xlPaperTabloid = 3,
	xlPaperUser = 256
};

class CCommonMethod
{
public:
	
	/**
	*  @brief    ���exe·��
	*
	*  @return   CString
	*/
	static CString GetPath();

	
	/**
	*  @brief    ���Visual Studio2008����excel automation��ȡExcel�ĵ�����ʱ�������ʾ��������һ����������������,�˲����޷���ɵ�����
	*
	*  @return   void
	*/
	static void AvoidOtherProgrameRunning();

	
	/**
	*  @brief    ���Ĭ�ϴ�ӡ��
	*
	*  @return   CString
	*/
	static CString GetDeafultPrinter();

	
	/**
	*  @brief    ����Ĭ�ϴ�ӡ��
	*
	*  @param    CString strActivePrinter
	*  @return   CString
	*/
	static CString SetPrinterPara(CString strActivePrinter);

	
	/**
	*  @brief    ���û�Ĭ�ϴ�ӡ��
	*
	*  @param    CString strDefaultPrinter
	*  @return   void
	*/
	static void ResetDeafultPrinter(CString strDefaultPrinter);

	static void Sample();
};