#pragma once
#include "MedalRow.h"
#include <iostream>
using namespace std;
//enum typeMedals {Gold, Silver, Bronze};
class MedalsTable
{
public:
	static const int maxSize{ 10 };
private:
	MedalRow* medalRows;
	int size;
	int findCountry(const char* country)const;

public:
	MedalsTable();

	MedalsTable(MedalsTable&& object) //конструктор перемещения
		: medalRows{ object.medalRows }, size{ object.size }
	{
		/* "отбираем" у исходного объекта право владения
		блоком динамической памяти и устанавливаем
		размер блока в 0 */
		object.medalRows = nullptr;
		object.size = 0;
		cout << "Конструктор перемещения "
			<< size << " elements, for " << this
			<< '\n';
	}
	MedalsTable(const MedalsTable& object);// конструктор копирования


	MedalsTable& operator=(MedalsTable&& object); //оператор присваивания


	~MedalsTable();
	MedalRow& operator[](const char* country);
	const MedalRow& operator[](const char* country)const;
	void print()const;
	friend ostream& operator<<(ostream& output, const MedalsTable& temp);//перегрузка cout
	int operator()(const char* countryC);
	friend void countryMedals(const MedalRow& temp);//пишет страну и каких медалей больше
	
};
