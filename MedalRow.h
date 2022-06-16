#pragma once
#include <iostream>
#include <cassert>
using namespace std;
class MedalRow
{
	char country[4];
	int medals[3];
public:
	static const int GOLD{ 0 };
	static const int SILVER{ 1 };
	static const int BRONZE{ 2 };
	MedalRow(const char* countryP, const int* medalsP);
	MedalRow() : MedalRow(nullptr, nullptr) {};
	MedalRow& setCountry(const char* countryP);
	const char* getCountry()const { return country; };
	int& operator[](int idx);
	int operator[](int idx)const;
	void print()const;
	friend ostream& operator<<(ostream& output, const MedalRow& temp);//перегрузка cout
	const int getMedals(int idx)const { return medals[idx]; };
	friend void MedalsTable::countryMedals(const MedalsTable& temp);
	
};

