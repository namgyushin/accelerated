#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <iterator>
using namespace std;

int main()
{
    vector<int> vec = {3, 1, 2, 3, 4, 3, 3, 5 };

    vector<int>::iterator it = remove(vec.begin(), vec.end(), 3);
    vec.erase(it, vec.end());

    copy(vec.cbegin(), vec.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}