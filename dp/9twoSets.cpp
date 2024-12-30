#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int mod=1e9+7;
vector<int> pre(1e6+1,0),curr(1e6+1,0);
 
int modulo(int a, int b, int n) {
  int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;  // multiplying with base
    }
    y = (y * y) % n;  // squaring the base
    b /= 2;
  }
  return x % n;
}

 
int32_t main(){
	int t;t=1;
	while(t--){
		int n;cin>>n;
		int sum=(n*(n+1))/2;
    if(sum%2!=0){
      cout<<0<<endl;continue;
    }
		pre[0]=pre[1]=1;
		for(int i=2;i<=n;i++){
      for(int j=0;j<=(sum/2);j++){
			curr[j]=pre[j];
			if(j>=i) curr[j]=(curr[j]%mod+pre[j-i]%mod)%mod;
		   }
       pre=curr;
		}
    cout<<(pre[sum/2]*modulo(2, mod - 2, mod))%mod<<endl;
	}
}