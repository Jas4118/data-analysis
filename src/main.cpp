#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <algorithm>

#include "aggregation.cpp"

void analyze_data(std::string doc_name, std::string season, std::ofstream& outputFile);

int main()
{
    ofstream outputFile;
    outputFile.open("../output/output.txt");

    string course;
    string season;

    cout << "Please enter the name of the course you would like to analyze (1115, 3115, or 3130). Do not include the extension.\n";
    cin >> course;

    transform(season.begin(), season.end(), season.begin(), ::tolower);
    //Change season input to lowercase to avoid being case sensitive

    if (course == "1115" || course == "3115" || course == "3130") {
        analyze_data(course, season, outputFile);
    } else {
        cout << "You have entered an invalid course number.";
    }

    cout << "Data has been successfully written to the output file.";
    return 0;   
}

void analyze_data(std::string doc_name, std::string season, std::ofstream& outputFile) {
    calc_pass_rate_prof(doc_name, outputFile);
    calc_withdraw_prof(doc_name, outputFile);
    calc_pass_rate_course(doc_name, "fall", outputFile);
    calc_pass_rate_course(doc_name, "spring", outputFile);
    calc_withdrawal_course(doc_name, "fall", outputFile);
    calc_withdrawal_course(doc_name, "spring", outputFile);
}