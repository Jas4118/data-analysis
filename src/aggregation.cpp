#include "file-manip.cpp"
#include <cstdio>
#include <string>
#include <unordered_map>

void calc_pass_rate_prof()
{
    unordered_map<string, float> instructors_passes = count_pass_rate_prof("1115.csv");
    unordered_map<string, float> instructors_students = count_total_students_prof("1115.csv");

    unordered_map<string, float> professor_ratio;

    cout << "\n\n\n";

    for(auto it_m1 = instructors_passes.cbegin(), end_m1 = instructors_passes.cend(),
        it_m2 = instructors_students.cbegin(), end_m2 = instructors_students.cend();
        it_m1 != end_m1 || it_m2 != end_m2;)
    {
        if(it_m1 != end_m1) {
            string instructor = it_m1 -> first;
            float passed_students = it_m1 -> second;
            float total_students = it_m2 -> second;

            professor_ratio.insert({instructor, (passed_students / total_students) });

            std::cout << "m1: " << it_m1->first << " " << it_m1->second << " | ";
            ++it_m1;
        }

        if(it_m2 != end_m2) {
            std::cout << "m2: " << it_m2->first << " " << it_m2->second << std::endl;
            ++it_m2;
        }
    }

    cout << "\n\n\n";

    for (auto itr = professor_ratio.begin(); itr != professor_ratio.end(); ++itr) {
        cout << itr -> first
             << '\t' 
             << itr -> second 
             << '\n';
    }
}