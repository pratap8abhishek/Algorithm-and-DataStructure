#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> findLadders(string startWord, string targetWord, vector<string>& wordList)
{
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    vector<vector<string>> result;

    // If targetWord is not in wordList, return empty result
    if (!wordSet.count(targetWord)) return result;

    queue<vector<string>> paths; // queue to store paths
    paths.push({startWord});
    unordered_set<string> visited;
    visited.insert(startWord);

    bool found = false;

    while (!paths.empty() && !found) {
        int size = paths.size();
        unordered_set<string> levelVisited;

        for (int i = 0; i < size; ++i) {
            vector<string> path = paths.front();
            paths.pop();

            string lastWord = path.back();

                        for (int j = 0; j < lastWord.size(); ++j) {
                string temp = lastWord;

                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[j] = c;

                    if (wordSet.count(temp) && !visited.count(temp)) {
                        vector<string> newPath = path;
                        newPath.push_back(temp);

                        if (temp == targetWord) {
                            result.push_back(newPath);
                            found = true;
                        } else {
                            paths.push(newPath);
                            levelVisited.insert(temp);
                        }
                    }
                }
            }
        }

        // Mark words visited at this level
        for (const string& word : levelVisited) {
            visited.insert(word);
        }
    }
    return result;
}





int main()
{
  string startWord = "der";
  string targetWord = "dfs";
  vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};

   vector<vector<string>> sequences = findLadders(startWord, targetWord, wordList);

   for(const auto& sequence : sequences){
    for(const auto& word : sequence)
    {
        cout << word <<" ";
    }
   } 
   return 0;
}