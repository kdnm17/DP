#include<bits/stdc++.h>
using namespace std;




int main(){
  int n;cin>>n;
  vector<int> dp(n,-1);
  vector<int> h(n);
  for(int i=0;i<n;i++) cin>>h[i];
  dp[0]=0;dp[1]=abs(h[1]-h[0]);
  for(int i=2;i<n;i++){
    int l=dp[i-1]+abs(h[i]-h[i-1]);
    int r=dp[i-2]+abs(h[i]-h[i-2]);
    dp[i]=min(l,r);
  }
  cout<<dp[n-1]<<endl;
}