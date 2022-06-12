#include "MedalRow.h"
#include <cassert>
class MedalsTable
{

private:

	int size = 0;// размер массива множеств
	MedalRow* medalRows;	// указатель массив множеств
	int findCountry(const char* country)const
	{
		for (int i{ 0 }; i < size; ++i)
		{
				if (strcmp(medalRows[i].getCountry(),
					country) == 0)
				{
					return i;
				}
		}
		return -1;
	}

public:
	MedalsTable(int size) : size{ size }
	{
		if (this->size == 0)
		{
			medalRows = nullptr;
		}
		else
		{
			medalRows = new MedalRow[size];
		}		
	}

	MedalsTable() : size{ 0 } {};


	MedalRow& operator[](const char* country)
	{
		int idx{ findCountry(country) };
		if (idx == -1)
		{
			assert(size < MedalsTable::size and
				"Table is FULL!");
			idx = size++;
			medalRows[idx].setCountry(country);
		}
		return medalRows[idx];
	}
	const MedalRow& operator[](const char* country)const
	{
		int idx{ findCountry(country) };
		assert(idx != -1 and "Country not found on const "
			"table");
		return medalRows[idx];
	}
	void print()const
	{
			for (int i{ 0 }; i < size; ++i)
			{
				medalRows[i].print();
			}
	}
	~MedalsTable()
	{
		delete[]medalRows;
	}
	MedalsTable& add(const MedalRow);
};

