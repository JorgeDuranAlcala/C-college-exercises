#include <bits/stdc++.h>
using namespace std;

void urlify(char *, int len);

int main()
{

    char *my_str = "Mr brown fuck you  ";
    /* vector<string> chars;
    for (auto &&i : my_str)
    {
        chars.push_back(i);
    }

    string s; */

    urlify(my_str, 18);
    cout << my_str;

    return 0;
}

void urlify(char *str, int len)
{
    string isA;
    for (int i = 0; i < len - 1; i++)
    {
        isA = str[i] != ' ' ? "letter" : "space";
        if (isA == "space")
        {
            str[i] = '%';
        }
    }
    cout << str;
}
