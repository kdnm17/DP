#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;
vector<int> arr(1e5);
vector<vector<int>> dp(1e5,vector<int>(101,-1));

int arrayd(int idx,int prev,int m){
  if(idx==0){
    if(arr[idx]==0){
      if(prev>1 && prev<m) return 3;
      else return 2;
    }
    else{
      if(abs(arr[0]-prev)>1) return 0;
      else return 1;
    }
  }
  if(dp[idx][prev]!=-1) return dp[idx][prev];
  int ans=0;
  if(arr[idx]==0){
     for(int i=prev-1;i<=prev+1;i++){
      if(i!=0 && i<=m) ans=(ans+arrayd(idx-1,i,m))%mod;
     }
  }
  else{
    if(abs(arr[idx]-prev)>1) return 0;
    else ans=arrayd(idx-1,arr[idx],m);
  }
  return dp[idx][prev]=ans;
}

int32_t main(){
  int n,m;cin>>n>>m;
  for(int i=0;i<n;i++) cin>>arr[i];
  if(m==1){
    cout<<1<<endl;
  }
  else if(n==1){
    if(arr[0]!=0) cout<<1<<endl;
    else cout<<m<<endl;
  }
  else{
    int ans=0;
     if(arr[n-1]!=0) ans=arrayd(n-2,arr[n-1],m);
     else{
      for(int i=1;i<=m;i++) ans=(ans+arrayd(n-2,i,m))%mod;
     }
     cout<<ans<<endl;
  }

}
