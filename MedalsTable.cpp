#include "MedalsTable.h"
#include <iostream>
using namespace std;
int MedalsTable::findCountry(const char* country) const
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

MedalsTable::MedalsTable()
{
    int size = 0;
    medalRows = nullptr;
}

MedalsTable::MedalsTable(const MedalsTable& object)
    : medalRows{ new MedalRow[object.size] }, size{ object.size }
    {
        for (int i{ 0 }; i < size; ++i)
        {
            medalRows[i] = object.medalRows[i];
        };
        cout << "Конструктор копирования "
            << size << " elements, for " << this
            << '\n';
    }

MedalsTable& MedalsTable::operator=(MedalsTable&& object)
{
    {
        if (!(this == &object))
        {
            delete medalRows;
            medalRows = object.medalRows;
            size = object.size;
            object.medalRows = nullptr;
            object.size = 0;
        }
        std::cout << "оператор присваивания "
            << size << " elements, for " << this
            << '\n';
        return *this;
    }
}



MedalsTable::~MedalsTable()
{
    delete[]medalRows;
    cout << "Деструктор" << this << "/n";
}

MedalRow& MedalsTable::operator[](const char* country)
{
    int idx{ findCountry(country) };
    if (idx == -1)
    {
   
        if (medalRows == nullptr) {
            idx = size++;
            medalRows = new MedalRow[size];
            medalRows[idx].setCountry(country);

        }
        else
        {
            MedalRow* temp = new MedalRow[size];
            for (int i = 0; i < size; i++) {
                temp[i] = medalRows[i];
            }
            delete[]medalRows;
            size++;
            medalRows = new MedalRow[size];
            for (int i = 0; i < size - 1; i++) {
                medalRows[i] = temp[i];
            }
            delete[]temp;
            idx = size - 1;
            medalRows[idx].setCountry(country);
        }
    }
    return medalRows[idx];
}

const MedalRow& MedalsTable::operator[](const char* country) const
{
    int idx{ findCountry(country) };
    assert(idx != -1 and "Country not found on const "
        "table");
    return medalRows[idx];
}

void MedalsTable::print() const
{
    for (int i{ 0 }; i < size; ++i)
    {
        medalRows[i].print();
    }
}

int MedalsTable::operator()(const char* countryC)
{
    int idx{ findCountry(countryC) };
    if (idx == -1)
    {
        cout << "Страна не найдена";
    }
    else
    {
        if (medalRows[idx].getMedals(0) > medalRows[idx].getMedals(1))
        {
          return (medalRows[idx].getMedals(0) > medalRows[idx].getMedals(2))
                ? medalRows[idx].getMedals(0) :  medalRows[idx].getMedals(2);
        }
        else
        {
            return (medalRows[idx].getMedals(1) > medalRows[idx].getMedals(2))
                  ? medalRows[idx].getMedals(1) : medalRows[idx].getMedals(2);
        }
    }
}
void countryMedals(const MedalRow& temp)
{
    cout << temp.getCountry();

}
;


ostream& operator<<(ostream& output, const MedalsTable& temp)
{
    if (temp.medalRows != nullptr)
    {
        for (int i = 0; i < temp.size; i++)
        {
            output << temp.medalRows[i];
        }
        cout << endl;
    }
        else output << "\nArray nullptr\n";
        return output;
}
