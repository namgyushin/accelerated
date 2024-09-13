#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isUpper(string s)
{
    bool result = false;

    for (string::const_iterator it = s.cbegin(); it != s.cend(); ++it)
    {
        //if (*it <= 'A' && *it <= 'Z')
        if (isupper(*it))
        {
            result = true;
            break;
        }
        
    }
    

    return result;
}

int main()
{
    vector<string> lower, upper;

    string s;
    while (cin >> s)
    {
        if (isUpper(s))
        {
            upper.push_back(s);
        }
        else
        {
            lower.push_back(s);
        }
        
    }
    cout << "소문자" << endl;
    for (vector<string>::const_iterator it = lower.cbegin(); it != lower.cend(); ++it)
    {
        cout << *it << endl;
    }
    cout << endl;

    cout << "대문자" << endl;
    for (auto it = upper.cbegin(); it != upper.cend(); ++it)
    {
        cout << *it << endl;
    }



    return 0;
}