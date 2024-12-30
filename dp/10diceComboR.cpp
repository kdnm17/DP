#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> dp(1e6+1,-1);
const int mod=1e9+7;

int dicecombo(int sum){
  if(sum==0) return 1;
 if(sum<0) return 0;
  if(dp[sum]!=-1) return dp[sum];
  int ans=0;
  for(int i=1;i<=6;i++){
    if(i<=sum) ans=(ans+dicecombo(sum-i))%mod;
  }
  return dp[sum]=ans;
}

int32_t main(){
  int n;cin>>n;
  cout<<dicecombo(n);
}