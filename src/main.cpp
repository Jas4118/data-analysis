#include <iostream>
#include <fstream>
#include <cstdio>

#include "aggregation.cpp"

int main()
{
    string file;

    cout << "Please enter the name of the file you would like to analyze (1115, 3115, or 3130). Do not include the extension.\n";
    cin >> file;

    if (file != "1115" || file != "3115" || file != "3130") {
        cout << "You have entered an invalid course number.";
    } else {
        // calc_pass_rate_prof(file);
        // calc_withdraw_professor(file);
        // calc_pass_rate_course(file);
        calc_withdrawal_course(file);
    }

    return 0;
}