#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;

    for (int i = 0; i < 10; i++)
        vec.push_back(2);

    for (auto i = vec.begin(); i != vec.end(); i++)
        cout << i;

    return 0;
}
