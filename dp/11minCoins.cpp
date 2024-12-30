#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> dp(1e6+1,INT_MAX);

int32_t main(){
  int n,x;cin>>n>>x;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  for(auto i:v) dp[i]=1;
  dp[0]=0;
  for(int i=1;i<=x;i++){
    for(int j=0;j<n;j++){
      if(v[j]<=i) dp[i]=min(dp[i],1+dp[i-v[j]]);
    }
  }
  if(dp[x]>1e6) cout<<-1;
  else cout<<dp[x];
}