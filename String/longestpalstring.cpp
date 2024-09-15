#include<bits/stdc++.h>
using namespace std;
  int maxLength;
  string res;
  void cSibUtil(string& s,int l,int r)
  {
    while(l>=0 && r < s.length() && s[l] == s[r]){
        l--;
        r++;
    }
    if(r-l-1 >= maxlength){
        res = s.substr(l+1,r-l-1);
        maxlength = r-l-1;
    }
    return;
  }
int longestpalSubstr(string str){
 res = "";
 maxlength = 1;
 for(int i=0;i<str.length();i++){
     cSubUtil(str,i,i);
     cSubUtil(str,i,i+1);
 }
 cout<<res<<"\n";
}
int main(){
  string str = "forgeeksskeegfor";
  cout<<" "<<longestpalSubstr(str);<<endl;
  return 0;
}