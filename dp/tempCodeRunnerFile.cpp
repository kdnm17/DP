#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;
const int lmt=1e6+1;
vector<int> v(100);
vector<int> dp(lmt,0);


int32_t main(){
  int n,x;cin>>n>>x;
  for(int i=0;i<n;i++) cin>>v[i];
  dp[0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<=x;j++){
      if(j>=v[i]) dp[j]=(dp[j]+dp[j-v[i]])%mod;
    }
  }
  cout<<dp[x]<<endl;
}
