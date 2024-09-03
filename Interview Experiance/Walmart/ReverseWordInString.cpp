#include<bits/stdc++.h>
using namespace std;
void reverse(string str)
{
 vector<string> words;
 stringstream ss(str);
 string word;

 while(ss >> word){
    words.push_back(word);
    reverse(words.begin(),words.end());

    for(int i=0;i<words.size();i++){
        cout << words[i];
        if (i != words.size() - 1) {
            cout << " ";  
        }
    }
 }
}
int main(){
 string S = "Abhishek Pratap Singh";
 reverse(S);
 return 0;
}