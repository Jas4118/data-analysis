#include <iostream>
#include <fstream>
#include <cstdio>

#include "aggregation.cpp"

int main()
{
    string file;

    cout << "Please enter the name of the file you would like to analyze (1115, 3115, or 3130). Do not include the extension.\n";
    cin >> file;

    // calc_withdraw_professor(file);
    count_passed_course(file);

    return 0;
}