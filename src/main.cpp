#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <algorithm>

using namespace std;

#include "aggregation.cpp"

void analyze_data(std::string doc_name, std::ofstream& outputFile);

int main()
{
    string course;

    cout << "Please enter the name of the course you would like to analyze (1115, 3115, or 3130). Do not include the extension.\n";
    cin >> course;

    ofstream outputFile;
    outputFile.open(course + ".txt");

    if (course == "1115" || course == "3115" || course == "3130") {
        analyze_data(course, outputFile);
        cout << "The analysis has been successfully written to the output file.";
    } else {
        cout << "You have entered an invalid course number.";
        outputFile << "You have entered an invalid course number.";
    }

    return 0;   
}

void analyze_data(std::string doc_name, std::ofstream& outputFile) {
    //Calls all of the functions needed to output all of the analyzed data
    calc_pass_rate_prof(doc_name, outputFile);
    calc_withdraw_prof(doc_name, outputFile);
    calc_pass_rate_course(doc_name, "fall", outputFile);
    calc_pass_rate_course(doc_name, "spring", outputFile);
    calc_withdrawal_course(doc_name, "fall", outputFile);
    calc_withdrawal_course(doc_name, "spring", outputFile);
    calc_overall_pass_course(doc_name, outputFile);
    calc_overall_withdraw_course(doc_name, outputFile);
}