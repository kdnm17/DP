#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;
vector<int> v(100);
vector<int> dp(1e6+1,-1);
vector<int> result(1,-1);

int coincombo(int n,int sum){
  if(sum==0) return 1;
  if(sum<0) return 0;
  if(dp[sum]!=-1) return dp[sum];
  int ans=0;
  for(int i=0;i<n;i++){
    if(result[result.size()-1]<=v[i]){
      int p=coincombo(n,sum-v[i]);
      if(p!=0) result.push_back(v[i]);
       ans=(ans+p)%mod;
    }
  }
  return dp[sum]=ans;
}

int32_t main(){
  int n,x;cin>>n>>x;
  for(int i=0;i<n;i++) cin>>v[i];
  cout<<coincombo(n,x)<<endl;
}
