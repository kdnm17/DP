#include<bits/stdc++.h>
#define int long long
using namespace std;

int knapsack(vector<int> &wt,vector<int> &val,vector<vector<int>> &dp,int idx,int w){
  if(idx==0){
    if(wt[0]<=w) return val[0];
    else return 0;
  }
  if(dp[idx][w]!=-1) return dp[idx][w];
  int notake=knapsack(wt,val,dp,idx-1,w);
  int take=-1;
  if(wt[idx]<=w) take=val[idx]+knapsack(wt,val,dp,idx-1,w-wt[idx]);
  return dp[idx][w]= max(take,notake);
}

int32_t main(){
  int n,w;cin>>n>>w;
  vector<int> wt(n),val(n);
  for(int i=0;i<n;i++) cin>>wt[i]>>val[i];
  vector<vector<int>> dp(n,vector<int>(w+1,-1));
  cout<<knapsack(wt,val,dp,n-1,w)<<endl;
}