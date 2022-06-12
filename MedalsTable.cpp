#include "MedalsTable.h"

MedalsTable& MedalsTable::add(const MedalRow)
{
	int* temp = new MedalRow[size + 1];
	temp[sizeArrSet] = c;
	delete[]arrSet;
	arrSet = temp;
	sizeArrSet = sizeArrSet + 1;

	return *this;
}
Set& Set::add(const int c)
{
	int* temp = new int[sizeArrSet + 1];
	for (int i = 0; i < sizeArrSet; i++)
	{
		if (arrSet[i] == c)
		{
			return *this;
		}
		temp[i] = arrSet[i];
	}
	temp[sizeArrSet] = c;
	delete[]arrSet;
	arrSet = temp;
	sizeArrSet = sizeArrSet + 1;

	return *this;
}
