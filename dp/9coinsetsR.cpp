#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int mod=1e9+7;
vector<int> dp(1e6+1,-1);

int coinset(int sum,int n){
  if(sum==0) return 1;
  if(n==0) return 0; 
  if(dp[sum]!=-1) return dp[sum];
  int notake=coinset(sum,n-1);
  int take=0;
  if(sum>=n) take=coinset(sum-n,n-1);
  return dp[sum]=(take+notake)%mod;
}
 
int32_t main(){
	int t;t=1;
	while(t--){
		int n;cin>>n;
		int sum=(n*(n+1))/2;
    if(sum%2!=0){
      cout<<0<<endl;continue;
    }
		cout<<coinset(sum,n)/2<<endl;
	}
}