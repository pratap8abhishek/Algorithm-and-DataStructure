#include <bits/stdc++.h>
using namespace std;
string findLargestPrifix(const string *str, int n)
{
    if (n == 0)
        return " ";

    string prifix = str[0];

    for (int i = 1; i < n; ++i)
    {
        int j = 0;
        while (j < prifix.size() && j < str[i].size() && prifix[j] == str[i][j])
        {
            ++j;
        }
        prifix = prifix.substr(0, j);
    }
    return prifix;
}
int main()
{
    string str[] = {"amazon", "amazed", "amaze", "amazing", "amazes"};
    int n = sizeof(str) / sizeof(str[0]);
    string Largest_prifix = findLargestPrifix(str, n);
    cout << "Largest Prifix of Given Set is " << Largest_prifix << " ";
    return 0;
}