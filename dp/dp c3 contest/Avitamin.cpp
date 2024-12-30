#include<bits/stdc++.h>
#define int long long
using namespace std;

const int IM=1e18;

int32_t main(){
  int n;cin>>n;
  vector<int> v1(n);
  vector<string> v2(n);
  for(int i=0;i<n;i++) {
    cin>>v1[i]>>v2[i];
  }
  int dp[n][1][1][1];
  for(int i=0;i<n;i++){
    for(int a=0;a<=1;a++){
      for(int b=0;b<=1;b++){
        for(int c=0;c<=1;c++){
          if(a==0 && b==0 && c==0) dp[i][a][b][c]=0;
          else dp[i][a][b][c]=IM;
        }
      }
    }
  }

  int a1=0,b1=0,c1=0;
  for(auto it:v2[0]){
      if(it=='A') a1=1;
      else if(it=='B') b1=1;
      else c1=1;
  }
  dp[0][a1][b1][c1]=v1[0];
  cout<<dp[0][1][1][1]<<endl;

  for(int i=1;i<n;i++){
    a1=0,b1=0,c1=0;
    for(auto it:v2[i]){
      if(it=='A') a1=1;
      else if(it=='B') b1=1;
      else c1=1;
    }
    for(int a=0;a<=1;a++){
      for(int b=0;b<=1;b++){
        for(int c=0;c<=1;c++){
            for(int j=0;j<i;j++){
              dp[i][a][b][c]=min(dp[i][a][b][c],v1[i]+dp[j][a==0?0:a-a1][b==0?0:b-b1][c==0?0:c-c1]);
            }
        }
      }
    }
  }
  int ans=IM;
  for(int i=0;i<n;i++){
    cout<<i<<' '<<dp[i][1][1][1]<<endl;
    ans=min(ans,dp[i][1][1][1]);
  }
  if(ans==IM) cout<<-1<<endl;
  else cout<<ans<<endl;
}