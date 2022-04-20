#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<unordered_map, unordered_map> calc_pass_rate_instructor(std::string doc_name)
{
    // Calculates the pass rate of each instructor
    std::ifstream document("data/" + doc_name);
    std::string token;
    std::string instructor;
    std::string grade;

    std::getline(document, token); // Get rid of headings
    unordered_map<string, int> instructor_passes;
    unordered_map<string, int> passes_total; //Also need to count the ratio of passes to the total number of students

    int counter = 0;
    int totalStudents = 0;

    while (std::getline(document, token, ','))
    { 
        // Extracts only the instructor id (column 3) and the student's grade (column 6)
        counter++;

        if (counter == 3)
        {
            instructor = token;

            if (instructor_passes.find(instructor) == instructor_passes.end())
            {
                // If the instructor is not already in the unordered maps, we need to put it in. If they are, nothing needs to be done
                instructor_passes.insert({instructor, 0});
                passes_total.insert({instructor, 0});
            }
        }
        else if (counter == 6)
        {
            grade = token.substr(0,1);

            if (grade != "F")
            {
                //If the student did not fail (i.e., they passed), incremented the professors number of passes. Regardless, increment total students.
                int passes = instructor_passes.at(instructor);
                passes++;

                instructor_passes.erase(instructor);
                instructor_passes.insert({instructor, passes});
            }
            
            totalStudents++;
            passes_total.erase(instructor);
            passes_total.insert({instructor, totalStudents});

            counter = 1;
        }
    }

    cout << "KEY\tELEMENT\n";
    for (auto itr = instructor_passes.begin(); itr != instructor_passes.end(); ++itr) {
        cout << itr -> first
             << '\t' 
             << itr -> second 
             << '\n';
    }

    cout << "\n\n\n";

    cout << "KEY\tELEMENT\n";
    for (auto itr = passes_total.begin(); itr != passes_total.end(); ++itr) {
        cout << itr -> first
             << '\t' 
             << itr -> second 
             << '\n';
    }

    return instructor_passes;
}

unordered_map<string, int> withdraw_rate_professor(std::string doc_name)
{
    // Calculates the withdraw rate of each instructor. Note that we do not need to calculate the total number of students again in this function
    // because the total will be the same for each professor regardless.
    std::ifstream document("data/" + doc_name);
    std::string token;
    std::string instructor;
    std::string grade;

    std::getline(document, token); // Get rid of headings
    unordered_map<string, int> instructor_withdrawal;

    int counter = 0;

    while (std::getline(document, token, ','))
    { 
        // Extracts only the instructor id (column 3) and the student's grade (column 6)
        counter++;

        if (counter == 3)
        {
            instructor = token;

            if (instructor_withdrawal.find(instructor) == instructor_withdrawal.end())
            {
                // If the instructor is not already in the unordered map, we need to put it in. If they are, nothing needs to be done
                instructor_withdrawal.insert({instructor, 0});
            }
        }
        else if (counter == 6)
        {
            grade = token.substr(0,1);

            if (grade == "W")
            {
                //If the student withdrew, incremented the professors number of passes. Do nothing they did not withdraw.
                int passes = instructor_withdrawal.at(instructor);
                passes++;

                instructor_withdrawal.erase(instructor);
                instructor_withdrawal.insert({instructor, passes});
            }
            
            counter = 1;
        }
    }


    return instructor_withdrawal;
}
