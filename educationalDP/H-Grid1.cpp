#include<bits/stdc++.h>
using namespace std;

#define int long long
#define d7 1000000007


int32_t main(){
    
    
    int n,m;cin>>n>>m;
    
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>> dp(n,vector<int>(m));
    
    dp[0][0]=1;
    
    for(int i=0;i<m;i++){
        if(a[0][i]=='.'){
            if(i>0) dp[0][i]=dp[0][i-1];
        }else{
            dp[0][i]=0;
            break;
        }
    }
    for(int i=0;i<n;i++){
         if(a[i][0]=='.'){
             if(i>0) dp[i][0]=dp[i-1][0];
         }else{
             dp[i][0]=0;
             break;
         }
     }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]=='.'){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%d7;
            }else{
                dp[i][j]=0;
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    
    
    return 0;
}
