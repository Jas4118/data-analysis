#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

void calc_pass_rate_instructor(std::string doc_name)
{
    // Calculates the pass rate of the passed course document/csv file
    std::ifstream document("data/" + doc_name);
    std::string token;

    std::getline(document, token);
    int counter = 0;

    while (std::getline(document, token, ','))
    {
        counter++;

        
        if (counter == 3)
        {
        std:
            cout << token + "\n";
        }
        else if (counter == 6)
        {
        std2:
            cout << token.substr(0, 1) + "\n";
            counter = 1;
        }
    }
}


