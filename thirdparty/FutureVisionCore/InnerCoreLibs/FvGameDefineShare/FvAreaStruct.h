//{future header message}
#ifndef __FvAreaRange_H__
#define __FvAreaRange_H__

#include <FvPowerDefines.h>
#include <FvKernel.h>


struct FvAreaRange
{
	enum GameAreaType
	{
		AREA_ROUND,//! Բ��
		AREA_RECT,//! ����
		AREA_SECTOR,//! ����
	};
	FvAreaRange():m_uiType(AREA_ROUND), m_uiMinRange(0), m_uiMaxRange(0)
	{}
	FvAreaRange(const GameAreaType uiType, const FvInt32 uiMinRange, const FvInt32 uiMaxRange)
		:m_uiType(uiType), m_uiMinRange(uiMinRange), m_uiMaxRange(uiMaxRange)
	{}
	FvUInt32 m_uiType;								// ��Χ����
	FvInt32 m_uiMinRange;									// ��С����(Բ)��С�뾶:��(����)��:��(����)����
	FvInt32 m_uiMaxRange;								// ������(Բ)���뾶:��(����)��:��(����)�뾶

};
#endif //__FvAreaRange_H__
