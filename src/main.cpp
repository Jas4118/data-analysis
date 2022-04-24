#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <algorithm>

#include "aggregation.cpp"

void analyze_data(std::string doc_name, std::string season);

int main()
{
    string course;
    string season;

    cout << "Please enter the name of the course you would like to analyze (1115, 3115, or 3130). Do not include the extension.\n";
    cin >> course;

    cout << "Please enter the season you would like to know (Spring or Fall).\n";
    cin >> season;

    transform(season.begin(), season.end(), season.begin(), ::tolower);
    //Change season input to lowercase to avoid being case sensitive

    if ((course == "1115" || course == "3115" || course == "3130") && (season == "spring" || season == "fall")) {
        analyze_data(course, season);
    } else {
        cout << "You have entered an invalid input.";
    }

    return 0;   
}

void analyze_data(std::string doc_name, std::string season) {
    calc_pass_rate_prof(doc_name);
    calc_withdraw_prof(doc_name);
    calc_pass_rate_course(doc_name, season);
    calc_withdrawal_course(doc_name, season);
}