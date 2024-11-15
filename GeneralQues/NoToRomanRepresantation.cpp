#include <bits/stdc++.h>
using namespace std;

string toRoman(int num)
{
    int values[] = {1000, 500, 100, 50, 10, 5, 1};
    char symbols[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    string result = "";

    for (int i = 0; i < 7; i++)
    {
        while (num >= values[i])
        {
            result += symbols[i];
            num -= values[i];
        }
    }
    return result;
}
int main()
{
    int number = 39;
    string roman = toRoman(number);
    cout << roman << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// string Roman(int n)
// {
//     int value[] = {1000, 500, 100, 50, 10, 5, 1};
//     char symbol[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

//     string result = "";
//     int i = 0;
//     while (n > 0)
//     {
//         int div = n / value[i];
//         n %= value[i];

//         if (div == 4)
//         {
//             result += symbol[i];
//             result += symbol[i - 1];
//         }
//         else if (div == 9)
//         {
//             result += symbol[i];
//             result += symbol[i - 2];
//         }
//         else
//         {
//             while (div--)
//             {
//                 result += symbol[i];
//             }
//         }

//         i++;
//     }
//     return result;
// }

// int main()
// {
//     int n = 49;
//     string roman = Roman(n);
//     cout << roman << endl;
//     return 0;
// }