#include<bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <map>
// #include <fstream>
using namespace std;

int main()
{
    map<string, int> words;

    ifstream in("lylics.txt");

    string word;
    while (in >> word)
    {
        ++words[word];
    }
    
    for (auto it = words.cbegin(); it != words.cend(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
    

    return 0;
}