#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
  int n,w;cin>>n>>w;
  vector<int> wt(n),val(n);
  for(int i=0;i<n;i++) cin>>wt[i]>>val[i];
  vector<vector<int>> dp(n,vector<int>(w+1,0));
  for(int i=wt[0];i<=w;i++) dp[0][i]=val[0];
  for(int i=1;i<n;i++){
    for(int j=0;j<=w;j++){
      int notake=dp[i-1][j];
      int take=-1;
      if(wt[i]<=j) take=val[i]+dp[i-1][j-wt[i]];
      dp[i][j]=max(take,notake);
    }
  }
    cout<<dp[n-1][w]<<endl;
}