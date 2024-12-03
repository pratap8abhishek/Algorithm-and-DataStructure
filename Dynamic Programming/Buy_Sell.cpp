#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &price, int start, int end) {
    int res = 0;
    for(int i = start;i < end; i++){
        for(int j = i+1; j <= end;j++){
            if(price[j] > price[i]){
                int curr = (price[j] - price[i])+
                maxProfit(price,start,i-1)+maxProfit(price,j+1,end);
                res = max(res,curr);
            }
        }

    }
    return res;
}

int maxProfit(vector<int> &prices){
    return maxProfit(prices,0,prices.size()-1);
}
int main(){
    vector<int> prices = {100,180,260,310,40,535,695};
    cout<<maxProfit(prices);
    return 0;
}



// int maxProfit(vector<int> &price) {
//     int res = 0;
//     for(int i = 1; i < price.size();i++){
//         if(price[i] > price[i-1]){
//             res += price[i] - price[i-1]; 
//         }
//     }
//     return res;
// }
// int main(){
//     vector<int> prices = {100,180,260,310,40,535,695};
//     cout<<maxProfit(prices);
//     return 0;
// }