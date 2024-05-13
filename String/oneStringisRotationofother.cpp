#include <bits/stdtr1c++.h>
using namespace std;
bool check_rotation(string &str1)
{
    stack<char> st;

    for (int i = 0; i < str1.length(); i++)
    {
        st.push(str1[i]);
    }
    str1.clear();
    while (!st.empty())
    {
        str1.push_back(st.top());
        st.pop();
    }
}
int main()
{
    string str1 = "AACD";
    check_rotation(str1);
    cout << "Reversed string is : " << str1;
    return 0;
}