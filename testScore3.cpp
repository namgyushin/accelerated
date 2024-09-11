//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ios>
using namespace std;

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
    double median = ::median(homeworks);

    return grade(midterm, finalterm, median);
}



int main()
{
    cout << "input name : ";
    string name;
    cin >> name;

    cout << "input midterm finalterm : ";
    double midterm, finalterm;
    cin >> midterm >> finalterm;

    vector<double> homeworks;

    double homework;
    while (cin >> homework)
    {
        homeworks.push_back(homework);      //벡터에 입력하는 함수 push_back
    }

    if (homeworks.size() == 0)
    {
        cerr << "try input homework again" << endl;
        return 1;
    }

    //double median = ::median(homeworks);
    //const double finalScore = grade(midterm, finalterm, median);
    const double finalScore = grade(midterm, finalterm, homeworks);

    std::streamsize prec = cout.precision();
    cout << " Your final score : " << setprecision(3) << finalScore 
    << setprecision(prec) << endl;
    return 0;
}