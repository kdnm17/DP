#include <bits/stdc++.h>
using namespace std;
#define int long long 
int isprime[10000001];

int binrep(int x) {
    vector<int> v;
    while (x != 0) {
        v.push_back(x % 2);
        x /= 2;
    }
    reverse(v.begin(), v.end());
    for (auto i : v) cout << i ;
    return 0;
}

int binxpo(int a, int b) {
    if(b==0) return 1;
    int res=binxpo(a,b/2);
    if(b%2==1) return res*res*a;
    else return res*res;
}

int nCr(int n,int r) {
    int res=1;
    for (int i=0;i<r;i++) {
        res*=(n-r+1+i);
        res/=(i+1);
    }
    return res;
}

int32_t main()
{    
    
    for(int i=0;i<=1e7;i++) isprime[i]=1;
    isprime[0]=isprime[1]=0;
    for(int i=2;i*i<=1e7;i++){
        if(isprime[i]){
            for(int j=i*i;j<=1e7;j+=i){
                isprime[j]=0;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
      int n,k;
      cin>>n>>k;
      vector<int>v(n);
      vector<int>ans(n);
      int sum=0;
      for(int i=0;i<n;i++) cin>>v[i];
      sort(v.begin(),v.end());
      for(int i=0;i<n;i++){
          int idx=i+1;
          sum+=v[i];
          if(idx<=k) ans[i]=sum;
          else{
              int x=1;
              ans[i]=sum;
              int y=i-x*k-(x-1);
              while(y>=0){
                  ans[i]-=v[y];
                  x++;
                  y=i-x*k-(x-1);
              }
          }
      }
      //4 1 6 10 2 
      //1 2 4 6 10   1 
      for(int i=0;i<n;i++){
          cout<<ans[i]<<" ";
      }
      cout<<"\n";
    }
    return 0;
}