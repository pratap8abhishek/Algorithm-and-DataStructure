#include<bits/stdc++.h>
using namespace std;
int longestSubstringWithKUniqueChars(const string &s,int k){
    int n = s.size();
    if(n ==0 || k == 0){
        return 0;
    }
    unordered_map<char,int> charCount;
    int left = 0,right = 0;
    int maxLength = 0;

    while(right<n){
        charCount[s[right]]++;

        while(charCount.size()>k){
            charCount[s[left]]--;
            if(charCount[s[left]]==0){
                charCount.erase(s[left]);
            }
            left++;
        }
        if(charCount.size() == k){
            maxLength  = max(maxLength,right-left+1);
        }
        right++;
    }
    return maxLength;
}

int main()
{
    string s="aabacbebebe";
    int k = 3;
    int result = longestSubstringWithKUniqueChars(s,k);
    cout << "The length of the longest substring with " << k << " unique characters is: " << result << endl;
    return 0;
}