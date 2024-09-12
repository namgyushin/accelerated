#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

vector<string> split(const string& s)
{
    vector<string> words;

    string::size_type i = 0;
    while (i != s.size())
    {
        while (i != s.size() && isspace(s[i]))
        {
            ++i;
        }

        string::size_type j = i;
        while (j != s.size() && !isspace(s[j]))
        {
            ++j;
        }
        if (i != j)
        {
            words.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return words;
}

int main()
{
    // const string title = "just the way you are";
    // vector<string> words = split(title);
    vector<string> words;
    
    string s;
    while (getline(cin, s))
    {
        words = split(s);
    }
    

    for (vector<string>::const_iterator it = words.cbegin(); it != words.cend(); ++it)
    {
        cout << *it << endl;
    }
    

    return 0;
}