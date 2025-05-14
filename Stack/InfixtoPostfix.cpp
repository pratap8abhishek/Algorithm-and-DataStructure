#include<bits/stdc++.h>
using namespace std;

int precdence(char c){
    if(c == '^')
      return 3;
    else if(c == '/' || c == '*')
      return 2;
    else if(c == '+' || c == '-')
      return 1;
    else   
      return -1;              
}

string infixToPostfix(string s){
    stack<char> st;
    string res;

    for(int i = 0;i < s.length();i++){
        char c = s[i];

     if((c >= 'a'&& c <='z') || (c >= 'A'&& c <='Z') || (c >= '0'&& c <='9'))
     res += c;

     else if(c == '(')
      st.push('(');

     else if(c == ')'){
        while(st.top() != '('){
            res += st.top();
            st.pop();
        }
        st.pop();
     }
     else{
        while(!st.empty() && (precdence(c) <= precdence(st.top()) || (precdence(c) == precdence(st.top()) && c != '^'))){
            res += st.top();
            st.pop();
        }
        st.push(c);
     }    
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}
int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(exp);
    return 0;
}