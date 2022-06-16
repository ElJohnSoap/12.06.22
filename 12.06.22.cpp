#include <iostream>
#include "MedalsTable.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    MedalsTable mt1;
    std::cout << "Medals table #1:\n";
    mt1["UKR"][MedalRow::GOLD] = 14;
    mt1["UKR"][MedalRow::SILVER] = 5;
    mt1["HUN"][MedalRow::BRONZE] = 9;
    mt1["HUN"][MedalRow::GOLD] = 7;
    mt1["POL"][MedalRow::GOLD] = 4;
    mt1["POL"][MedalRow::SILVER] = 2;
    mt1.print();
    // создаем константную копию таблицы №1
    std::cout << "\nMedals table #2:\n";
    const MedalsTable mt2{ mt1 };
    //mt2.print();
    // раскомментировав следующую строку можно протестировать
    // проверку отсутствия страны в константной таблице 
    // медалей
    // программа аварийно завершиться, что нормально!
    //mt2["SLO"].print();
    cout << mt2;
    cout << endl;
    cout << mt1("HUN");
    cout << endl;
    return 0;

}