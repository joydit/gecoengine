//{future header message}
#ifndef __FvStringFilter_H__
#define __FvStringFilter_H__

#include <vector>
#include <map>
#include "FvKernel.h"
#include "FvBaseTypes.h"


//! FvStringFilter����С��ģ�����ؼ��ֵ�����
class FV_KERNEL_API FvStringFilter
{
public:
	FvStringFilter();
	~FvStringFilter();

	void	SetMark(char cMark) { m_cMark=cMark; }

	void	AddUnLawKeyWord(const FvString& kANSIWord);											//! kANSIWordΪANSI��ʽ
	void	AddUnLawKeyWords(const FvString& kANSIWordsStream);									//! kANSIWordsStreamΪANSI��ʽ,\n����,һ��һ���ؼ���

	bool	HasUnLawKeyWord(const FvString& kUTF8Str) const;									//! kUTF8StrΪUTF-8��ʽ
	bool	CheckAndReplaceUnLawKeyWords(const FvString& kUTF8Src, FvString& kUTF8Des) const;	//! kUTF8Src,kUTF8DesΪUTF-8��ʽ

protected:
	typedef std::vector<FvString> UnLawKeyWords;
	UnLawKeyWords	m_kUnLawKeyWords;
	char			m_cMark;
};


//! FvMassStringFilter���ڴ��ģ�����ؼ��ֵ�����
class FV_KERNEL_API FvMassStringFilter
{
public:
	FvMassStringFilter();
	~FvMassStringFilter();

	void	SetMark(char cMark) { m_cMark=cMark; }

	void	AddUnLawKeyWords(const FvString& kANSIWordsStream);									//! kANSIWordsStreamΪANSI��ʽ,\n����,һ��һ���ؼ���

	bool	HasUnLawKeyWord(const FvString& kUTF8Str) const;									//! kUTF8StrΪUTF-8��ʽ
	bool	CheckAndReplaceUnLawKeyWords(const FvString& kUTF8Src, FvString& kUTF8Des) const;	//! kUTF8Src,kUTF8DesΪUTF-8��ʽ

protected:
	typedef std::vector<FvString> UnLawKeyWords;
	UnLawKeyWords* FindKeyWords(FvUInt64 uiWord) const;
	typedef std::map<FvUInt64, UnLawKeyWords*> UnLawKeyWordMap;
	void AddUnLawKeyWord(const FvString& kANSIWord, UnLawKeyWordMap& kMap);

protected:
	typedef std::pair<FvUInt64, UnLawKeyWords*> UnLawKeyWordsPair;
	FvUInt32			m_uiUnLawKeyWordsPairArraySize;
	UnLawKeyWordsPair*	m_pkUnLawKeyWordsPairArray;
	char				m_cMark;
};


void FV_KERNEL_API ANSI_To_UTF8(FvString& kStr);
void UTF8_To_ANSI(FvString& kStr);
void ANSI_To_UTF16(const FvString& kSrc, FvWString& kDes);
void UTF16_To_ANSI(const FvWString& kSrc, FvString& kDes);
void UTF8_To_UTF16(const FvString& kSrc, FvWString& kDes);
void UTF16_To_UTF8(const FvWString& kSrc, FvString& kDes);

//! ȡ����һ��UTF8����
size_t GetUTF8Word(const char* pcUTF8Str, size_t uiOffset, FvUInt64& kUTF8Word);


//! ͳ���ַ����е�"����"
//! kStr: UTF8��ʽ�ַ���
//! iAsciiCoef: Ascii�ַ������"����"
//! iNotAsciiCoef: ��Ascii�ַ������"����"
int CalcWordCnt(const FvString& kUTF8Str, int iAsciiCoef=1, int iNotAsciiCoef=1);

FvUInt16 FV_KERNEL_API UTF8_TO_UNICODE(const char* pcUTF8Str,wchar_t* pwcUnicodeStr,FvUInt8 uiUnicodeLen);


namespace StrFilterTest
{
	static void Test()
	{
		//! ͳ���ַ����е�"����"
		{
			FvString kANSIStr("KMP�������ǹ�����DFA��������ģ�⣬");
			//! �ַ�������ΪUTF8��ʽ,ת��UTF8��ʽ
			ANSI_To_UTF8(kANSIStr);
			//! ͳ���ַ����е�"����",ANSI�ַ���1��,��ANSI�ַ���2��
			int iCnt = CalcWordCnt(kANSIStr, 1, 2);
		}

		//! �����ּ��
		{
			FvStringFilter kFilter;

			//! ����������,�����ε�����ʾ'#'
			kFilter.SetMark('#');

			//! ���������"ABC",ANSI��ʽ
			kFilter.AddUnLawKeyWord("ABC");

			//! ����������б�
			//! ���ļ�test.csv�ж�ȡ,һ��һ��������,ANSI��ʽ
			//! test.csv������:
			//! DDD
			//! FFF
			{
				FILE* pkFile = NULL;
				fopen_s(&pkFile, "test.csv", "rt");
				if(!pkFile)
					return;
				fseek(pkFile, 0, SEEK_END);
				size_t uiFileSize = ftell(pkFile);
				char* pkBuf = new char[uiFileSize];
				fseek(pkFile, 0, SEEK_SET);
				fread(pkBuf, uiFileSize, 1, pkFile);
				fclose(pkFile);

				kFilter.AddUnLawKeyWords(pkBuf);
			}

			//! ����ַ������Ƿ���������
			FvString kANSIStr("AAABC����DDFFFDDE");
			//! �ַ�������ΪUTF8��ʽ,ת��UTF8��ʽ
			ANSI_To_UTF8(kANSIStr);
			if(kFilter.HasUnLawKeyWord(kANSIStr))
			{
				//! ����������
				UTF8_To_ANSI(kANSIStr);
				printf("%s\n", kANSIStr.c_str());
			}

			//! ��鲢���������滻������
			FvString kUTF8DesStr;
			if(kFilter.CheckAndReplaceUnLawKeyWords(kANSIStr, kUTF8DesStr))
			{
				//! ����������
				UTF8_To_ANSI(kUTF8DesStr);
				printf("%s\n", kUTF8DesStr.c_str());
			}
		}
	}
}

#endif//__FvStringFilter_H__