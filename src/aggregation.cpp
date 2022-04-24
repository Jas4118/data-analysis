#include <cstdio>
#include <string>
#include <unordered_map>

#include "file-manip.cpp"

void calc_pass_rate_course(std::string doc_name)
{
    //Calculates and writes the pass rate per course

    cout << "\nThis is the percent of students that did not fail, withdraw, or withdraw unofficially for the course " + doc_name + ".\n\n";

    cout << count_passed_course(doc_name);
}

void calc_pass_rate_prof(std::string doc_name)
{
    //Calculates and writes the pass rate per professor
    unordered_map<string, float> instructors_passes = count_pass_rate_prof(doc_name);
    unordered_map<string, float> instructors_students = count_total_students_prof(doc_name);

    unordered_map<string, float> professor_ratio;

    // cout << "\n\n\n";

    for(auto it_m1 = instructors_passes.cbegin(), end_m1 = instructors_passes.cend(),
        it_m2 = instructors_students.cbegin(), end_m2 = instructors_students.cend();
        it_m1 != end_m1 || it_m2 != end_m2;)
    {
        //Loop through both maps simultaneously
        if(it_m1 != end_m1) {
            string instructor = it_m1 -> first;
            float passed_students = it_m1 -> second;
            float total_students = it_m2 -> second;

            professor_ratio.insert({instructor, (passed_students / total_students) });
            //Put the ratio into the new map. Do not need to check if an instructor is already in the map because that is not possible.

            // std::cout << "m1: " << it_m1->first << " " << it_m1->second << " | ";
            ++it_m1;
        }

        if(it_m2 != end_m2) {
            // std::cout << "m2: " << it_m2->first << " " << it_m2->second << std::endl;
            ++it_m2;
        }
    }

    cout << "\nThis is the percent of students that did not fail, did not withdraw, and did not unofficially withdraw. (if we only include the students that did not fail, an entirely different story is painted.\n\n";

    for (auto itr = professor_ratio.begin(); itr != professor_ratio.end(); ++itr) {
        cout << itr -> first
             << '\t' 
             << itr -> second 
             << '\n';
    }
}

void calc_withdraw_professor(std::string doc_name)
{
    //Calculates and writes the wijthdraw rate per professor
    unordered_map<string, float> instructors_withdraws = count_withdraw_prof(doc_name);
    unordered_map<string, float> instructors_students = count_total_students_prof(doc_name);

    unordered_map<string, float> professor_ratio;

    // cout << "\n\n\n";
    cout << "\nThis is the percent of students that withdraw, either officially or unofficially (W or WU)\n\n";

    for(auto it_m1 = instructors_withdraws.cbegin(), end_m1 = instructors_withdraws.cend(),
        it_m2 = instructors_students.cbegin(), end_m2 = instructors_students.cend();
        it_m1 != end_m1 || it_m2 != end_m2;)
    {
        //Loops through both maps simultaneously
        if(it_m1 != end_m1) {
            string instructor = it_m1 -> first;
            float passed_students = it_m1 -> second;
            float total_students = it_m2 -> second;

            professor_ratio.insert({instructor, (passed_students / total_students) });
            //Put the ratio into the new map. Do not need to check if an instructor is already in the map because that is not possible.

            // std::cout << "m1: " << it_m1->first << " " << it_m1->second << " | ";
            ++it_m1;
        }

        if(it_m2 != end_m2) {
            // std::cout << "m2: " << it_m2->first << " " << it_m2->second << std::endl;
            ++it_m2;
        }
    }

    // cout << "\n\n\n";

    for (auto itr = professor_ratio.begin(); itr != professor_ratio.end(); ++itr) {
        cout << itr -> first
             << '\t' 
             << itr -> second 
             << '\n';
    }
}