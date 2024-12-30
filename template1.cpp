#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less 
using namespace __gnu_pbds; 
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set; 
#define _GLIBCXX_DEBUG
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define scan(arr) for(auto &i:arr)cin>>i;
#define VI vector<int>
#define VVI vector<VI>
#define PII pair<int, int>
#define SI set<int>
#define MSI multiset<int>
#define OS ordered_set
#define MII map<int, int>
#define all(x) (x).begin(), (x).end()
#define lcm(a,b) a/__gcd(a,b)*b
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define setBits(x) __builtin_popcountll(x)
#define result(x) cout<<(x ? "YES\n" : "NO\n")
const int N=1500001;
const int M=998244353;
const int M2=998244353;
const int inf=1e18;




// Overload for std::pair
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << p.first << " " << p.second << 'n';
    return os;
}

// Overload for std::array
template <typename T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& arr) {
    for (size_t i = 0; i < N; ++i) {
        os << arr[i];
        if (i != N - 1) os << " ";
    }
    os << "\n";
    return os;
}

// Overload operator<< to print an array
ostream& operator<<(ostream& os, int arr[]) {
    // Assuming 'n' is the size of the array
    for (int i = 0; i < 100; ++i) {
        os << arr[i] << " ";
    }
    return os;
}

// Overload for std::vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) os << " ";
    }
    os << "\n";
    return os;
}

// Overload for std::set
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
    
    for (auto it = s.begin(); it != s.end(); ++it) {
        os << *it;
        if (next(it) != s.end()) os << " ";
    }
    os << "\n";
    return os;
}

// Overload for std::map
template <typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        os << it->first << " " << it->second<<'\n';
        
    }
    
    return os;
}

// Overload for std::vector<std::vector<T>>
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& vec2D) {
    for (const auto& row : vec2D) {
        os << row << "\n"; // Use vector overload
    }
    os << "\n";
    return os;
}

// Function to print a 2D raw array
template <typename T, size_t Rows, size_t Cols>
ostream& operator<<(ostream& os, const T (&arr)[Rows][Cols]) {
    
    for (size_t i = 0; i < Rows; ++i) {
        
        for (size_t j = 0; j < Cols; ++j) {
            os << arr[i][j]<<" ";
        }
        os << "\n";
    }
    os << "\n";
    return os;
}


int binexp2(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=(ans * a) % M;
        a=(a * a) % M;
        b>>=1;
    }
    return ans;
}


int binMul(int a,int b){
    int ans=0;
    while(b){
        if(b&1)ans=(ans+a)%M;
        a=(a+a)%M;
        b>>=1;
    }
    return ans;
}


vector<bool>prime;
VI hp;
void sieve(){
    hp.resize(N,0);
    prime.resize(N,0);
    FOR(i,0,N)prime[i]=1,hp[i]=0;
    prime[0]=prime[1]=0;
    FOR(i,2,N){
        if(!hp[i]){
            for(int j=i;j<N;j+=i){
                hp[j]=i;
                if(j>i)
                prime[j]=0;
            }
        }
    }
}


VI fact;
void pre(){
    fact.resize(N,0);
    fact[0]=fact[1]=1;
    FOR(i,2,N){
        fact[i]=fact[i-1]*i;
        fact[i]%=M;
    }
}


void prefix(int *pref,int *arr,int n,int i){
    pref[i]=arr[0];
    FOR(j,i+1,n+i){
        pref[j]=pref[j-1]+arr[j-i];
    }
}
void prefixvec(VI pref,VI arr,int n,int i){
    pref[i]=arr[0];
    FOR(j,i+1,n+i){
        pref[j]=pref[j-1]+arr[j-i];
    }
}



//function<return_type(data_type,...)> name ;
void solve1() {

    string s;
    cin>>s;
    int n=s.size();
    
    FOR(i,0,n){
        int curr=s[i]-'0';
        int k=i;
        for(int j=i+1;j<i+9 && j<n;j++){
            int val=(s[j]-'0')-(j-i);
            if(val>curr)curr=val,k=j;
        }
        rotate(s.begin()+i,s.begin()+k,s.begin()+k+1);
        s[i]=curr+'0';
    }
    cout<<s<<endl;

    

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve1();
    }    
    return 0;
}