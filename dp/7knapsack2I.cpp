#include<bits/stdc++.h>
#define int long long
using namespace std;

const int lmt=1e5+1;
vector<vector<int>> dp(100,vector<int>(lmt,INT_MAX));

int32_t main(){
  int n,w;cin>>n>>w;
  vector<int> wt(n),val(n);
  for(int i=0;i<n;i++) cin>>wt[i]>>val[i];
  int p=0;
  for(auto i:val) p+=i;
  dp[0][0]=0;
  dp[0][val[0]]=wt[0];
  for(int i=1;i<n;i++){
    for(int j=0;j<=p;j++){
      dp[i][j]=dp[i-1][j];
      if(j>=val[i]) dp[i][j]=min(dp[i-1][j],wt[i]+dp[i-1][j-val[i]]);
    }
  }
  int ans=0;
  for(int i=1;i<=p;i++){
    if(dp[n-1][i]<=w && dp[n-1][i]!=0) ans=max(ans,i);
  }
  cout<<ans<<endl;
}