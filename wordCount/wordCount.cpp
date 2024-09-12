//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> words;
    vector<int> counts;
    string word;

    while (cin >> word)
    {
        vector<string>::size_type i;
        for (i = 0; i != words.size(); i++)
        {
            if (word == words[i])
            {
                break;
            }
            
        }
        if (i == words.size())
        {
            words.push_back(word);
            counts.push_back(1);
        }
        else
        {
            ++counts[i];
        }
        
    }

    

    for (vector<string>::size_type i = 0; i != words.size(); i++)
    {
        cout << words[i] << " : " << counts[i] << endl;
    }
    
   
    return 0;
}