//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <ios>
using namespace std;



struct Student_info
{
    string name;
    double midterm;
    double finalterm;
    vector<double> homeworks;
};

istream& read_hw(istream& in, vector<double>& homeworks)
{
    if (in)
    {
        homeworks.clear();

        double homework;
        while (in >> homework)
        {
            homeworks.push_back(homework);
        }

        in.clear();
    }
    return in;
}

istream& read(istream& in, Student_info& s)
{
    cin >> s.name >> s.midterm >> s.finalterm;
    read_hw(in, s.homeworks);

    return in;
}

double median(const vector<double>& vec)
{
    vector<double> vec2 = vec;
    sort(vec2.begin(), vec2.end());

    const vector<double>::size_type mid = vec2.size() / 2;
    double median;
    if (vec2.size() % 2 != 0)
    {
        median = vec2[mid];
    }
    else
    {
        median = (vec2[mid] + vec2[mid-1]) / 2;
    }
    return median;
}

double grade(double midterm, double finalterm, double homework)
{
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

double grade(double midterm, double finalterm, const vector<double>& homeworks)
{
    if (homeworks.size() == 0)
    {
        throw domain_error("no homework");
    }

    double median = ::median(homeworks);

    return grade(midterm, finalterm, median);
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.finalterm, s.homeworks);
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

        // if (maxLen < s.name.size())
        // {
        //     maxLen = s.name.size();
        // }
        maxLen = max(maxLen, s.name.size());
    }

    sort(students.begin(), students.end(), compare);

    try 
    {
        for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
        {
            const double finalScore = grade(students[i]);

            streamsize prec = cout.precision();

            cout << students[i].name 
            << string(maxLen - students[i].name.size() + 1, ' ')
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