#include <iostream>
#include <fstream>
#include <cstdio>
#include "file-manip.cpp"

int main()
{
    count_pass_rate_prof("1115.csv");

    cout << "\n\n\n\n\n\n";

    count_total_students_prof("1115.csv");

    // count_withdraw_prof("1115.csv");

    return 0;
}