#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums(10);

    for (int i = 1; i <= 10; ++i)
    {
        int capacity = nums.capacity();

        nums.push_back(i);
    }
    return 0;
}
