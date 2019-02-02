//
//	UXReaderDestination.cpp
//	UXReader v0.1
//
//	Copyright � 2017-2019 Julius Oklamcak. All rights reserved.
//

#include "stdafx.hpp"
#include "UXReaderDestination.hpp"

using namespace UXReader;

//
//	UXReaderDestination methods
//

UXReader::UXReaderDestination::UXReaderDestination(void)
{
	//DBLog(L"%S 0x%p\n", __FUNCSIG__, this);

	m_PageIndex = NEGATORY;
}

UXReader::UXReaderDestination::UXReaderDestination(const int index, bool hasX, bool hasY, bool hasZ, double x, double y, double z)
{
	//DBLog(L"%S 0x%p\n", __FUNCSIG__, this);

	if (hasX) { m_X = x; m_HasX = hasX; }
	if (hasY) { m_Y = y; m_HasY = hasY; }
	if (hasZ) { m_Z = z; m_HasZ = hasZ; }

	m_PageIndex = index;
}

UXReader::UXReaderDestination::~UXReaderDestination(void)
{
	//DBLog(L"%S 0x%p\n", __FUNCSIG__, this);
}

int UXReader::UXReaderDestination::PageIndex(void) const
{
	//DBLog(L"%S\n", __FUNCSIG__);

	return m_PageIndex;
}

int UXReader::UXReaderDestination::PageNumber(void) const
{
	//DBLog(L"%S\n", __FUNCSIG__);

	return (m_PageIndex + 1);
}

bool UXReader::UXReaderDestination::hasX(void) const
{
	//DBLog(L"%S\n", __FUNCSIG__);

	return m_HasX;
}

double UXReader::UXReaderDestination::X(void) const
{
	//DBLog(L"%S\n", __FUNCSIG__);

	return m_X;
}

bool UXReader::UXReaderDestination::hasY(void) const
{
	//DBLog(L"%S\n", __FUNCSIG__);

	return m_HasY;
}

double UXReader::UXReaderDestination::Y(void) const
{
	//DBLog(L"%S\n", __FUNCSIG__);

	return m_Y;
}

bool UXReader::UXReaderDestination::hasZ(void) const
{
	//DBLog(L"%S\n", __FUNCSIG__);

	return m_HasZ;
}

double UXReader::UXReaderDestination::Z(void) const
{
	//DBLog(L"%S\n", __FUNCSIG__);

	return m_Z;
}

void UXReader::UXReaderDestination::Description(void) const
{
	DBLog(L"%S %i x:%i:%g y:%i:%g z:%i:%g\n", __FUNCSIG__, m_PageIndex, m_HasX, m_X, m_HasY, m_Y, m_HasZ, m_Z);
}
