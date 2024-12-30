#include<bits/stdc++.h>
using namespace std;


int frog(int n,vector<int> &dp,vector<int> &h){
  if(n==0) return 0;
  if(n==1) return h[1]-h[0];
  if(dp[n]!=-1) return dp[n];
  int l,r;
  l=abs(h[n]-h[n-1])+frog(n-1,dp,h);
  r=abs(h[n]-h[n-2])+frog(n-2,dp,h);
  return dp[n]=min(l,r);
}


int main(){
  int n;cin>>n;
  vector<int> dp(n,-1);
  vector<int> h(n);
  for(int i=0;i<n;i++) cin>>h[i];
  cout<<frog(n-1,dp,h)<<endl;
}