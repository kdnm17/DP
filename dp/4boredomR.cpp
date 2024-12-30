#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> dp(1e5+1,-1);
vector<int> freq(1e5+1,0);

int boredom(int n){
  // cout<<'e'<<endl;
  if(n==0) return 0;
  if(n==1) return freq[1];
  if(dp[n]!=-1) return dp[n];
  int l=boredom(n-1);
  int r=n*freq[n]+boredom(n-2);
  return dp[n]=max(l,r);
}


int32_t main(){
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  for(int i=0;i<n;i++){
    freq[arr[i]]++;
  }
  int mx=1e5;
  cout<<boredom(mx);
}
