#include<bits/stdc++.h>
using namespace std;


int vacation(int n,int idx,vector<vector<int>> &dp,vector<vector<int>> &v){
  if(n==0) return v[n][idx];
  int ans=0;
  if(dp[n][idx]!=-1) return dp[n][idx];
  for(int i=0;i<3;i++){
    if(i!=idx){
      ans=max(ans,v[n][idx]+vacation(n-1,i,dp,v));
    }
  }
  return dp[n][idx]=ans;
}


int main(){
  int n;cin>>n;
  vector<vector<int>> v(n,vector<int> (3));
  for(int i=0;i<n;i++){
    for(int j=0;j<3;j++){
      cin>>v[i][j];
    }
  }
  vector<vector<int>> dp(n,vector<int> (3,-1));
  cout<<max(max(vacation(n-1,0,dp,v),vacation(n-1,1,dp,v)),vacation(n-1,2,dp,v))<<endl;
}