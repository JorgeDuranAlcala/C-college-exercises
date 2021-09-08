#include <bits/stdc++.h>
using namespace std;

//vector<int> subset;
vector<int> v = {4, 2, 7, 23};

void search(int n)
{
    for (int b = 0; b < (1 << n); b++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if (b & (1 << i))
                subset.push_back(i);
        }

        for (auto &&i : subset)
        {
            cout << v.at(i) << ", ";
        }
        cout << "\n";
    }
}
int main()
{
    search(4);

    return 0;
}