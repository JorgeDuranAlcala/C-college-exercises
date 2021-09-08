#include <bits/stdc++.h>
using namespace std;

int pokeCompStrategy = 1;

typedef struct Pokemon
{
    string name;
    int attack, defense;

    bool operator<(const Pokemon &p)
    {
        if (attack != p.attack)
            return attack < p.attack;
        else
            return p.attack;
    }

} Poke;

bool comp(Poke a, Poke b)
{
    switch (pokeCompStrategy)
    {
    case 1:
        if (b.attack != a.attack)
            return b.attack < a.attack;
        else
            return a.attack;
    default:
        if (b.defense != a.defense)
            return b.defense < a.defense;
        else
            return a.defense;
    }
}

int binarySearch(int *arr, int left, int right, int target)
{
    if (left <= right)
    {
        int middle = (left + right) / 2;
        if (arr[middle] == target)
        {
            return arr[middle];
        }
        else if (target < arr[middle])
            return binarySearch(arr, left, middle - 1, target);
        else if (target > arr[middle])
            return binarySearch(arr, middle + 1, right, target);
    }
    return -1;
}

int main()
{
    int v[] = {44, 2, 34, 53, 2, 1, -2, 21, 2};
    int sizeofv = sizeof(v) / sizeof(v[0]);
    int my_target;
    sort(v, v + sizeofv);
    for (auto &&i : v)
    {
        cout << i << ", ";
    }

    cout << "\n";

    cin >> my_target;

    int found = binarySearch(v, 0, sizeofv - 1, my_target);
    cout << "found: " << found << "\n";
    /* auto a = upper_bound(v, v + sizeofv, my_target);
    auto b = lower_bound(v, v + sizeofv, my_target); */
    auto b = equal_range(v, v + sizeofv, my_target);
    cout << "num of occurencies: " << b.second - b.first << "\n";
    string x;
    /* 

    string str = "littlemonkey";
    sort(str.begin(), str.end());

    for (auto &&i : str)
    {
        cout << i;
    } */

    /* vector<pair<int, int>> v;
    v.push_back({1, 2});
    v.push_back({2, 3});
    v.push_back({-1, 5});
    sort(v.begin(), v.end());
    for (auto &&i : v)
    {
        cout << "(" << i.first << "," << i.second << ")"
             << ", ";
    } */

    /* vector<Poke> pokedex;
    pokedex.push_back({name : "Pikachu", attack : 80, defense : 30});
    pokedex.push_back({name : "Charizard", attack : 130, defense : 40});
    pokedex.push_back({name : "Bulbasor", attack : 70, defense : 50});
    pokedex.push_back({name : "Squirtle", attack : 60, defense : 35});

    pokeCompStrategy = 0;
    sort(pokedex.begin(), pokedex.end(), comp);

    for (auto &&p : pokedex)
    {
        cout << "name: " << p.name << " attack: " << p.attack << " defense: " << p.defense << "\n";
    }
 */
    return 0;
}
