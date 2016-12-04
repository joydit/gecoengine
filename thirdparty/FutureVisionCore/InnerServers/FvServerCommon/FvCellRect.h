//{future header message}
#ifndef __FvCellRect_H__
#define __FvCellRect_H__

#include "FvServerCommon.h"
#include <FvVector3.h>
#include <FvVector4.h>
#include <FvBinaryStream.h>


class FV_SERVERCOMMON_API FvCellRect
{
public:
	FvCellRect():m_fLB(0.0f),m_fRB(0.0f),m_fBB(0.0f),m_fTB(0.0f) {}
	FvCellRect(float l, float r, float b, float t):m_fLB(l),m_fRB(r),m_fBB(b),m_fTB(t) {}
	FvCellRect(const FvCellRect& kRect):m_fLB(kRect.m_fLB),m_fRB(kRect.m_fRB),m_fBB(kRect.m_fBB),m_fTB(kRect.m_fTB) {}
	FvCellRect& operator=(const FvCellRect& kRect) { m_fLB=kRect.m_fLB;m_fRB=kRect.m_fRB;m_fBB=kRect.m_fBB;m_fTB=kRect.m_fTB; return *this; }
	FvCellRect& operator=(const FvVector4& kRect) { m_fLB=kRect.x;m_fRB=kRect.y;m_fBB=kRect.z;m_fTB=kRect.w; return *this; }
	//! fOffset>0 �������; fOffset<0 �ڽ�����
	FvCellRect(const FvCellRect& kRect, float fOffset):m_fLB(kRect.m_fLB-fOffset),m_fRB(kRect.m_fRB+fOffset),m_fBB(kRect.m_fBB-fOffset),m_fTB(kRect.m_fTB+fOffset) {}
	FvCellRect(const FvVector4& kRect):m_fLB(kRect.x),m_fRB(kRect.y),m_fBB(kRect.z),m_fTB(kRect.w) {}

	void	Set(float l, float r, float b, float t)
	{
		m_fLB = l;
		m_fRB = r;
		m_fBB = b;
		m_fTB = t;
	}

	float	LeftBorder() const		{ return m_fLB; }
	float	RightBorder() const		{ return m_fRB; }
	float	BottomBorder() const	{ return m_fBB; }
	float	TopBorder() const		{ return m_fTB; }

	void	ConvertToVector4(FvVector4& vect) { vect.x=m_fLB; vect.y=m_fRB; vect.z=m_fBB; vect.w=m_fTB; }

	//! �жϵ�kPos�Ƿ���������
	bool	IsPointIn(const FvVector3& kPos) const
	{
		return kPos.x>=m_fLB && kPos.x<m_fRB &&
			kPos.y>=m_fBB && kPos.y<m_fTB;
	}

	//! �жϵ�kPos�Ƿ������������
	bool	IsPointInRectOut(const FvVector3& kPos, float fOffset) const
	{
		return FvCellRect(*this, fOffset).IsPointIn(kPos);
	}

	//! �жϵ�kPos�Ƿ����ڽ�������
	bool	IsPointInRectIn(const FvVector3& kPos, float fOffset) const
	{
		return FvCellRect(*this, -fOffset).IsPointIn(kPos);
	}

	//! �жϵ�kPos�Ƿ����������ӻ���
	bool	IsPointInOffsetOut(const FvVector3& kPos, float fOffset) const
	{
		return !IsPointIn(kPos) && FvCellRect(*this, fOffset).IsPointIn(kPos);
	}

	//! �жϵ�kPos�Ƿ���������ڽӻ���
	bool	IsPointInOffsetIn(const FvVector3& kPos, float fOffset) const
	{
		return IsPointIn(kPos) && !FvCellRect(*this, -fOffset).IsPointIn(kPos);
	}

	friend FvBinaryIStream& operator>>(FvBinaryIStream& kIS, FvCellRect& kRect);
	friend FvBinaryOStream& operator<<(FvBinaryOStream& kOS, const FvCellRect& kRect);

protected:
	float m_fLB, m_fRB, m_fBB, m_fTB;	//! m_fLB<=m_fRB, m_fBB<=m_fTB
										//! ��Χ[m_fLB, m_fRB), [m_fBB, m_fTB)
};

FV_IOSTREAM_IMP_BY_MEMCPY(FV_INLINE, FvCellRect)


#endif//__FvCellRect_H__
