#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <numeric>
using namespace std;

int main()
{
    vector<double> vec = {1.1, 2.2, 3.3, 4.4, 5.5};

    double sum;
    // sum = 0.0;
    // for (double d : vec)
    // {
    //     sum = sum + d;
    // }

    sum = accumulate(vec.cbegin(), vec.cend(), 0.0);    //누적 합
    
    cout << "sum : " << sum << endl;

    return 0;
}