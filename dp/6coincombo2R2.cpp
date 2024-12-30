#include<bits/stdc++.h>
#define int long long
using namespace std;
//TLE code
const int mod=1e9+7;
vector<int> v(100);
vector<vector<int>> dp(100,vector<int>(1e6,-1));

int coincombo(int idx,int sum){
  // cout<<'e'<<endl;
  if(idx<0){
    if(sum==0) return 1;
    return 0;
  }
  if(dp[idx][sum]!=-1) return dp[idx][sum];
  int ans=0;
  int notake=coincombo(idx-1,sum);
  int take=0;
  if(v[idx]<=sum) take=coincombo(idx,sum-v[idx]);
  return dp[idx][sum]=take+notake;
}

int32_t main(){
  int n,x;cin>>n>>x;
  for(int i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  cout<<coincombo(n-1,x)<<endl;
}
