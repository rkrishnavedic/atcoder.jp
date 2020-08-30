//Giving Runtime / Wrong answer when submitted... To be checked further!
#include<bits/stdc++.h>
using namespace std;

#define int long long

void max_self(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> b) {
    if(a.first<b.first){
        a.first=b.first;
        a.second=b.second;
    }
    return;
}

int32_t main(){
    
    string s,t;
    cin>>s>>t;
    
    int n=s.size();
    int m=t.size();
    
    vector<vector<pair<int, pair<int,int>>>> dp(n+1, vector<pair<int,pair<int,int>>>(m+1,{0,{0,0}}));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i]==t[j]){
                max_self(dp[i+1][j+1],{dp[i][j].first+1,{i,j}});
            }
            max_self(dp[i+1][j], {dp[i][j].first,{i,j}});
            max_self(dp[i][j+1], {dp[i][j].first,{i,j}});
             //cout<<dp[i][j].first<<" ";
        }
       
        //cout<<endl;
    }
    
    string ans;
    int i=n,j=m;
    while(i>0 and j>0){
        if(dp[i][j].second.first<i and dp[i][j].second.second<j){
            ans.push_back(s[i-1]);i--;j--;
        }else{
            if(dp[i][j].second.first<i){
                i--;
            }else{
                j--;
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    cout<<ans<<endl;
    
    
    return 0;
}
