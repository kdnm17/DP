
#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> dp(1e5+1,-1);


int lp(int x,unordered_map<int,vector<int>> &mp){
    if(mp.find(x)==mp.end()) return 0;
    if(dp[x]!=-1) return dp[x];
    int ans=0;
    for(int i=0;i<mp[x].size();i++){
        int p=1+lp(mp[x][i],mp);
        ans=max(ans,p);
    }
    return dp[x]=ans;
}

int32_t main(){
    int n,m;cin>>n>>m;
    //can use vecot<vecto<int>>
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        mp[a].push_back(b);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,lp(i,mp));
    }
    cout<<ans<<endl;

}
