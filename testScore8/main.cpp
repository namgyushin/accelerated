//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <ios>
#include "student_info.h"
#include "grade.h"
using namespace std;

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

list<Student_info> extract_fails(list<Student_info>& passes)
{
    list<Student_info> fails;
    
    for (list<Student_info>::iterator it = passes.begin(); it != passes.end(); )
    {
        if (fgrade(*it))
        {
            fails.push_back(*it);
            it = passes.erase(it);
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
    list<Student_info> students;

    string::size_type maxLen = 0;

    ifstream in("./score.dat");

    Student_info s;
    while (read(in, s))
    {
        students.push_back(s);

        maxLen = max(maxLen, s.name.size());
    }

    //sort(students.begin(), students.end(), compare);
    students.sort(compare);

    list<Student_info> passes, fails;
    passes = students;
    fails = extract_fails(passes);

    try 
    {
        cout << "pass list : " << endl;
        for (list<Student_info>::const_iterator it = passes.cbegin(); it != passes.cend(); ++it)
        {
            const double finalScore = grade(*it);

            streamsize prec = cout.precision();

            cout << it->name 
            << string(maxLen - it->name.size() + 1, ' ')
            << setprecision(3) << finalScore 
            << setprecision(prec) << endl;
        }

        cout << endl << "fails list : " << endl;
        for (list<Student_info>::const_iterator it = fails.cbegin(); it != fails.cend(); ++it)
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