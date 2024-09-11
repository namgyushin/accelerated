//#include <bits/stdc++.h>
#include <iostream>
#include <string>
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

    int count = 0;
    double sum = 0;
    double homework;
    while (cin >> homework)
    {
        sum += homework;
        ++count;
    }

    const double finalScore = 0.2 * midterm + 0.4 * finalterm + 0.4 * sum / count;

    std::streamsize prec = cout.precision();
    cout << " Your final score : " << setprecision(3) << finalScore 
    << setprecision(prec) << endl;
    return 0;
}