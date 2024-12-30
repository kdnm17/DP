#include<bits/stdc++.h>
using namespace std;

vector<int> arr(100);
vector<vector<int>> dp(100,vector<int> (1e4+1,0));

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<n;i++) cin>>arr[i];
		int sum=0;
		for(int i=0;i<n;i++) sum+=arr[i];
		dp[0][0]=dp[0][arr[0]]=1;
		for(int i=1;i<n;i++){
           for(int j=0;j<=sum;j++){
			dp[i][j]=dp[i-1][j];
			if(dp[i][j]==0 && j>=arr[i]) dp[i][j]=dp[i][j-arr[i]];
		   }
		}
		for(int i=0;i<n;i++){
			int flag=0;
			for(int j=1;j<=sum;j++){
              if(dp[n-1][j]){
				for(int k=arr[i]*arr[i];k<=j;k*=arr[i]){
					if(k==j){
						flag=1;break;
					}
				}
			  }
			  if(flag) break;
			}
			if(flag) cout<<1<<' ';
			else cout<<0<<' ';
		}
		cout<<endl;
	}
}