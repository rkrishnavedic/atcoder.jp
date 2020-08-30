#include<bits/stdc++.h>
using namespace std;

#define int long long
#define d7 1000000007


int32_t main(){
    
    
    int n;cin>>n;
    
    //dp[i] denote the i-heads so far;
    vector<double> dp(n+1);
    
    dp[0]=1;
    
    for(int i=0;i<n;i++){
        double ph;cin>>ph;
        for(int j=i+1;j>=0;j--){
            dp[j]=(j==0? 0: dp[j-1]*ph)+dp[j]*(1-ph);
        }
    }
    double ans=0;
    for(int i=n;i>n/2;i--){
        ans+=dp[i];
    }
    cout<<fixed<<setprecision(9)<<ans<<endl;
    
    return 0;
}
