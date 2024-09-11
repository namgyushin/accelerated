//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ios>

using namespace std;
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

    sort(homeworks.begin(), homeworks.end());

    vector<double>::size_type/*int*/ mid = homeworks.size() / 2;

    double median;
    if (homeworks.size() % 2 != 0)
    {
        median = homeworks[mid];
    }
    else
    {
        median = (homeworks[mid] + homeworks[mid-1]) / 2;
    }

    const double finalScore = 0.2 * midterm + 0.4 * finalterm + 0.4 * median;

    std::streamsize prec = cout.precision();
    cout << " Your final score : " << setprecision(3) << finalScore 
    << setprecision(prec) << endl;
    return 0;
}