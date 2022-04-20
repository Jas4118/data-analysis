#include <iostream>
#include <fstream>
#include <cstdio>
#include "file-manip.cpp"

int main()
{
    calc_pass_rate_instructor("1115.csv");

    cout << "\n\n\n\n\n\n";

    withdraw_rate_professor("1115.csv");

    return 0;
}