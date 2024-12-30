#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int IM=1e18;

int32_t main(){
  int n;cin>>n;
  vector<int> s(n),c(n);
  for(int i=0;i<n;i++) cin>>s[i];
  for(int i=0;i<n;i++) cin>>c[i];
  vector<vector<int>> dp(n,vector<int>(4,IM));
  dp[0][1]=c[0];
  for(int i=1;i<n;i++){
    for(int k=1;k<=3;k++){
      for(int j=0;j<i;j++){
        if(k==1) dp[i][k]=min(dp[i][k],c[i]);
        else if(s[i]>s[j]) dp[i][k]=min(dp[i][k],c[i]+dp[j][k-1]);
      }
    }
  }
  int ans=IM;
  for(int i=2;i<n;i++){
    ans=min(ans,dp[i][3]);
  }
  if(ans!=IM)  cout<<ans<<endl;
  else cout<<-1<<endl;
} 