#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "input your name : ";
    string name;
    cin >> name;

    const int pad_r = 1;
    const int pad_c = 2;
    const string greeting = "hello, " + name + "!";
    const int rows = 3 + 2 * pad_r;
    const string::size_type cols = greeting.size() + 2 + 2 * pad_c;

    for(int r = 0; r != rows; ++r)
    {
        string::size_type c = 0;
        while (c != cols)
        {
            if (r == pad_r + 1 && c == pad_c +1)
            {
                cout << greeting;
                c = c + greeting.size();
            }
            else if (r == 0 || r == rows-1 ||c == 0 || c == cols-1)
            {
                cout << "*";
                ++c;
            }
            else
            {
                cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}