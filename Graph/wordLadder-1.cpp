#include<bits/stdc++.h>
using namespace std;

int ladderLength(string startWord,staring targetWord,vector<string>& wordList)
{
    unordered_set<string> wordSet(wordList.begin(),wordList.end());

    if(wordSet.find(targetWord) == wordSet.end())
    return 0;

    queue<pair<string,int>> q;
    q.push({startWord,1});

    while(!q.empty())
    {
        auto[currentWord,length] = q.front();
        q.pop();
        
        // If we reach the targetWord, return the transformation length
        if(currentWord == targetWord)
        return length

        // Try all possible single-character transformations
        for(size_t i = 0; i < currentWOrd.size();++i){
            string tempWord = currentWord;

            for(char ch = 'a';ch <='z';++ch){
                tempWord[i] = ch;

            // If the transformed word is in the wordSet
            if (wordSet.find(tempWord) != wordSet.end()) {
                q.push({tempWord, length + 1});
                wordSet.erase(tempWord); // Remove to avoid revisiting
            }
          }
      }
    }
    return 0;
}
int main()
{
    string startWord = "hit";
    string targetWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = ladderLength(startWord,targetWord,wordList);
    cout<<"Length of shortest transformation,sequence :"<<result<<endl;

    return 0;
}