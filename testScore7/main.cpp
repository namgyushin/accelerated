//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <ios>
#include "student_info.h"
#include "grade.h"
using namespace std;

// vector<Student_info> extract_fails(vector<Student_info>& students)
// {
//     vector<Student_info> passes, fails;
    
//     for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
//     {
//         if (grade(students[i]) >= 60)
//         {
//             passes.push_back(students[i]);
//         }
//         else
//         {
//             fails.push_back(students[i]);
//         }
//     }
//     students = passes;

//     return fails;
// }

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

// vector<Student_info> extract_fails(vector<Student_info>& passes)
// {
//     vector<Student_info> fails;
    
//     for (vector<Student_info>::size_type i = 0; i != passes.size(); )
//     {
//         if (fgrade(passes[i]))
//         {
//             fails.push_back(passes[i]);
//             passes.erase(passes.begin() + i);
//         }
//         else
//         {
//             ++i;
//         }
//     }

//     return fails;
// }

vector<Student_info> extract_fails(vector<Student_info>& passes)
{
    vector<Student_info> fails;
    
    for (vector<Student_info>::iterator it = passes.begin(); it != passes.end(); )
    {
        if (fgrade(*it))
        {
            fails.push_back(*it);
            passes.erase(it);
        }
        else
        {
            ++it;
        }
    }
    

    return fails;
}

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name < s2.name;
}

int main()
{
    vector<Student_info> students;

    string::size_type maxLen = 0;
    Student_info s;
    while (read(cin, s))
    {
        students.push_back(s);

        maxLen = max(maxLen, s.name.size());
    }

    sort(students.begin(), students.end(), compare);

    vector<Student_info> passes, fails;
    passes = students;
    fails = extract_fails(passes);

    try 
    {
        cout << "pass list : " << endl;
        for (vector<Student_info>::size_type i = 0; i != passes.size(); ++i)
        {
            const double finalScore = grade(passes[i]);

            streamsize prec = cout.precision();

            cout << passes[i].name 
            << string(maxLen - passes[i].name.size() + 1, ' ')
            << setprecision(3) << finalScore 
            << setprecision(prec) << endl;
        }

        cout << endl << "fails list : " << endl;
        for (vector<Student_info>::const_iterator it = fails.cbegin(); it != fails.cend(); ++it)
        {
            const double finalScore = grade(*it);

            streamsize prec = cout.precision();

            cout << it->name 
            << string(maxLen - it->name.size() + 1, ' ')
            << setprecision(3) << finalScore 
            << setprecision(prec) << endl;
        }
    }
    catch (const domain_error& e)
    {
        cerr << e.what() << endl;
        return 1;
    }

    
    return 0;
}