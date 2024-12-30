#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;
const int lmt=1e6+1;
vector<int> v(100);
vector<int> pre(lmt,0),curr(lmt,0);


int32_t main(){
  int n,x;cin>>n>>x;
  for(int i=0;i<n;i++) cin>>v[i];
  for(int i=0;i<=x;i+=v[0]) pre[i]=1;
  for(int i=1;i<n;i++){
    for(int j=0;j<=x;j++){
      curr[j]=pre[j];
      if(j>=v[i]) curr[j]=(curr[j]+curr[j-v[i]])%mod;
    }
    pre=curr;
  }
  cout<<pre[x]<<endl;
}
