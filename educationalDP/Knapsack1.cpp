#include<bits/stdc++.h>
using namespace std;

#define int long long

void maxself(int &a, int b) {a=max(a,b);}

int main(){
    int n,w;cin>>n>>w;
    vector<int> dp(w+1);
    //dp[i] is the maximum total value of the items with total weight <=i
    for(int i=0;i<n;i++){
        int weight, value;cin>>weight>>value;
        for(int wt_already=w-weight;wt_already>=0;wt_already--){
            maxself(dp[wt_already+weight], dp[wt_already]+value);
        }
    }
    cout<<dp[w]<<endl;
    
    return 0;
}
