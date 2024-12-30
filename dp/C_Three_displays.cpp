#include<bits/stdc++.h>
#define int long long 
using namespace std;


int32_t main(){
  int n;cin>>n;
  vector<int> s(n),c(n);
  for(int i=0;i<n;i++) cin>>s[i];
  for(int i=0;i<n;i++) cin>>c[i];
  vector<vector<int>> dp(n,vector<int>(4,-1));
  dp[0][1]=c[0];
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      for(int k=1;k<=3;k++){
        int notake=dp[j][k];
        int take=-1;
        if(k==1) take=c[i];
        else if(s[i]>s[j]){
          if(dp[j][k-1]!=-1) take=c[i]+dp[j][k-1];
        } 
        if(take==-1 && notake==-1) dp[i][k]=-1;
        else if(take==-1 || notake==-1) dp[i][k]=max(take,notake);
        else dp[i][k]=min(take,notake);
      }
    }
  }
  cout<<dp[n-1][3]<<endl;
} 