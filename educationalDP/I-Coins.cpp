#include<bits/stdc++.h>
using namespace std;

#define int long long
#define d7 1000000007


int32_t main(){
    
    
    int n;cin>>n;
    
    //dp[i] denote the i-heads so far;
    vector<double> dp(n+1);
    
    dp[0]=1;
    
    for(int i=1;i<=n;i++){
        double ph;cin>>ph;
        //input p_h its head probability of the i_th coin, then with i_th coin we can be sure upto dp[i] only 
        //That's why we compute from i=0...upto i_th then,
        // let say we know the answer upto i-1 th coin, then for i_th one we can make the
        //case j>0:  dp[j]=dp[j-1]*(ph) + dp[j]*(1-ph);
        // case j=0: dp[j]=dp[j]*(1-ph).. only 
        
        for(int j=i;j>=0;j--){
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
