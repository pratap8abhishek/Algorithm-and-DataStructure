#include<bits/stdc++.h>
using namespace std;
int printCountRec(int dist)
{
    if(dist < 0)
    return 0;
    if(dist == 0)
    return 1;

    return printCountRec(dist-1)+printCountRec(dist-2)+printCountRec(dist-3);
}


int main()
{
    int dist = 4;
    cout<< printCountRec(dist);
    return 0;
}


// Soluation Using Dynamic Programming
int printCountDP(int dist)
{
    int count[dist+1];

    count[0] = 1;

     if(dist >= 1)
            count[1] = 1;
            
     if(dist >= 2)
              count[2] = 2;

    for (int i=3; i<=dist; i++)
       count[i] = count[i-1] + count[i-2] + count[i-3];

    return count[dist];          
}

int main()
{
    int dist = 4;
    cout<< printCountDP(dist);
    return 0;
}