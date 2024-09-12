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

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name < s2.name;
}

int main()
{
    vector<Student_info> students;

    string::size_type maxLen = 0;

    try
    {
        Student_info s;
        while (read(cin, s))
        {
            students.push_back(s);

            // if (maxLen < s.name.size())
            // {
            //     maxLen = s.name.size();
            // }
            maxLen = max(maxLen, s.name.size());
        }
    }
    catch (const domain_error& e)
    {
        cerr << e.what() << endl;
        return 1;
    }

    sort(students.begin(), students.end(), compare);


        for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
        {
            const double finalScore = grade(students[i]);

            streamsize prec = cout.precision();

            cout << students[i].name 
            << string(maxLen - students[i].name.size() + 1, ' ')
            << setprecision(3) << finalScore 
            << setprecision(prec) << endl;
        }
    
    

    
    return 0;
}