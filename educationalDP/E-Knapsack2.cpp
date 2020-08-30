#include<bits/stdc++.h>
using namespace std;

#define int long long
int INF = INT_MAX;

void maxself(int &a, int b) {a=max(a,b);}
void minself(int &a, int b) {a=min(a,b);}

int32_t main(){
    int n,w;cin>>n>>w;
    vector<int> values(n), wieght(n);

    for(int i=0;i<n;i++){
        cin>>wieght[i]>>values[i];
    }
    int sum_value=0;
    for(auto x: values){
        sum_value+=x;
    }
    vector<int> dp(sum_value+1, INF);
    dp[0]=0;
    //dp[i] is the minimum total weight of items with total value exactly i
    for(int i=0;i<n;i++){
        for(int value_already=sum_value-values[i]; value_already>=0; value_already--){
            minself(dp[value_already+values[i]], dp[value_already]+wieght[i]);
        }
    }
    int ans=0;
    for(int i=sum_value;i>=0;i--){
        if(dp[i]<=w) maxself(ans, i);
    }
    cout<<ans<<endl;
    
    return 0;
}
