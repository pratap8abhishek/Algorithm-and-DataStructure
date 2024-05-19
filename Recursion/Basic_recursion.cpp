1. Print name 5 times
2. print Lineraly from 1 to N
3. print from N to 1
4. print linearly from 1 to N [But by BackTracking]
5. print from N to 1 [By Backtracking]


// print name N Times Using Recurssion
#include<bits/stdc++.h>
using namespace std;


void print(const string& name, int n) {
    if (n <= 0) {
        return; 
    }
    cout << name << endl; 
    print(name, n - 1); 
}

int main() {
    int n = 5;
    string name = "Abhishek Pratap Singh";
    print(name, n);
    return 0;
}

// print Lineraly 1 to N
void print1(int i,int n){
 if(i>n){
    return;
 }
 cout<<i<<endl;
 i++;
 print1(i,n);
}
int main(){
int n=10;
print1(1,n);
return 0;
}

// print from N to 1
void print1(int i,int n){
 if(i>n){
    return;
 }
 cout<<n<<endl;
 n--;
 print1(i,n);
}
int main(){
int n=10;
print1(1,n);
return 0;
}

//  print linearly from 1 to N [But by BackTracking]
void print2(int i){
    if(i<1){
        return;
    }
    cout<<i<<endl;
    print2(i-1);
}
int main(){
    int n = 10;
    print2(n);
    return 0;
}

// print from N to 1 [By Backtracking]
void print2(int i){
    if(i<1){
        return;
    }
    cout<<i<<endl;
    print2(i-1);
}
int main(){
    int n = 10;
    print2(n);
    return 0;
}









