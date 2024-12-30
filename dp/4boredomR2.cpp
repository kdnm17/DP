#include<bits/stdc++.h>
#define int long long
using namespace std;

map<int,int> m;
vector<int> v;

int boredom(vector<int> &dp,int n){
  if(n<0) return 0;
  if(n==0) return v[0]*m[v[0]];
  if(dp[n]!=-1) return dp[n];
  int l=boredom(dp,n-1);
  int r;
  if(m.find(v[n]-1)!=m.end()) r=v[n]*m[v[n]]+boredom(dp,n-2);
  else r=v[n]*m[v[n]]+boredom(dp,n-1);
  return dp[n]=max(l,r);
}


int32_t main(){
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  for(int i=0;i<n;i++){
    m[arr[i]]++;
  }
  vector<int> dp(m.size(),-1);
  for(auto i:m) v.push_back(i.first);
  cout<<boredom(dp,v.size()-1)<<endl;
}
