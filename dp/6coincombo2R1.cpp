#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;
vector<int> v(100);
vector<vector<int>> dp(1e6+1,vector<int>(100,-1));

int coincombo(int n,int sum,int prev){
  // cout<<'e'<<endl;
  if(sum==0) return 1;
  if(sum<0) return 0;
  if(dp[sum][prev]!=-1) return dp[sum][prev];
  int ans=0;
  for(int i=prev;i<n;i++){
    ans=(ans+coincombo(n,sum-v[i],i))%mod;
  }
  return dp[sum][prev]=ans;
}

int32_t main(){
  int n,x;cin>>n>>x;
  for(int i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.begin()+n);
  for(int i=0;i<n;i++) cout<<v[i]<<' ';
  cout<<endl; 
  int ans=0;
  for(int i=0;i<n;i++){
    ans=(ans+coincombo(n,x-v[i],i))%mod;
  }
  cout<<ans<<endl;
}
