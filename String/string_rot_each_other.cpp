#include<bits/stdc++.h>
using namespace std;
bool areRotation(string s1,string s2)
{
  if(s1.length() !=  s2.length())
  return false;
  
  string temp = s1+s2;;
  
  return(temp.find(s2) != string::npos);

}
int main()
{
    string s1 = "ABC";
    string s2 = "CBA";
    if (areRotation(s1, s2))
        cout << "The strings are rotations of each other." << endl;
    else
        cout << "The strings are not rotations of each other." << endl;
    return 0;
    
}