#include <iostream>
#include <fstream>
#include <cstdio>

#include "aggregation.cpp"

void analyze_data(std::string doc_name);

int main()
{
    string file;

    cout << "Please enter the name of the file you would like to analyze (1115, 3115, or 3130). Do not include the extension.\n";
    cin >> file;

    if (file == "1115" || file == "3115" || file == "3130") {
        analyze_data(file);
    } else {
        cout << "You have entered an invalid course number.";
    }

    return 0;   
}

void analyze_data(std::string doc_name) {
    calc_pass_rate_prof(doc_name);
    calc_withdraw_prof(doc_name);
    calc_pass_rate_course(doc_name);
    calc_withdrawal_course(doc_name);
}