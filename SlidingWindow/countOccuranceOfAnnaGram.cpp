#include<bits/stdc++.h>
using namespace std;
int countAnagram(string text,string pattern)
{
    int n = text.length();
    int m = pattern.length();

    if(m>n) return 0;

    unordered_map<char,int> patternCount;
    unordered_map<char,int> windowcount;

    // Count frequency of characters in the pattern
    for(char c : pattern){
        patternCount[c]++;
    }
    // Initialize the first window of size `m`
    for(int i=0;i<m;++i){
        windowcount[text[i]]++;
    }

    int anagramCount = 0;
      // Compare the first window with the pattern
    if(windowcount == patternCount){
        anagramCount++;
    }
    for(int i=m;i<n;++i){
        // Add the new character to the current window
        windowcount[text[i]]++;
        
        // Remove the character that is left behind
        char leftChar = text[i-m];
        if(windowcount[leftChar] == 1){
            windowcount.erase(leftChar);
        }else{
            windowcount[leftChar]--;
        }
        // Compare the current window with the pattern
        if(windowcount ==patternCount){
            anagramCount++;
        }
    }
    return anagramCount;
}
int main()
{
    string text = "forxxorfxdofr";
    string pattern = "for";
    int result = countAnagram(text,pattern);
    cout<<"Number of Annagrams:"<<result<<endl;
    return 0;
}