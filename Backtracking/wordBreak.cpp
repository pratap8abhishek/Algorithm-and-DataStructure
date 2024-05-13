#include<bits/stdtr1c++.h>
using namespace std;

int dictionaryContains(string &word){
    string dictionary[] = {"i","love","sam","sung","mobile","samsung"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for(int i=0; i<n; i++)
        if(dictionary[i].compare(word) == 0)
            return true;

    return false;
}

void wordBreakUtil(string str, int n, string result)
{
    for(int i=1; i<=n; i++)
    {
        string prefix = str.substr(0, i);

        if(dictionaryContains(prefix))
        {
            if(i == n)
            {
                result += prefix;
                cout << result << endl;
                return;
            }
            wordBreakUtil(str.substr(i, n - i), n - i, result + prefix + " ");
        }
    }
}

void wordBreak(string str)
{
    wordBreakUtil(str, str.size(), "");
}

int main()
{
    wordBreak("ilovesamsungmobile");
    return 0;
}