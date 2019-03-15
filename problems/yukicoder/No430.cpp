#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/430>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 Cの文字列が短いので、Sの全ての部分列について保持しておくことが可能。
 計算量削減のためにハッシュ値で持った。
 ================================================================
 */

struct RH {
    vector<unsigned long long> p,hash;
    unsigned long long base,m;
    // m : 1000000007, 1000000009, 1000000021...
    RH(){base=10007;m=1000000007;}
    void init(const string s) {
        unsigned long long q=1,n=s.size();
        p.resize(n+1);hash.resize(n+1);p[0]=q;hash[0]=0;
        for(int i=0;i<n;i++){
            if(m == 0){p[i+1]=p[i]*base; hash[i+1]=s[i]+hash[i]*base;}
            else {p[i+1]=p[i]*base%m; hash[i+1]=(s[i]+hash[i]*base)%m;}
        }
    }
    unsigned long long h(int i)const{return hash[i];}
    unsigned long long h(int i,int j)const{
        if(m==0) return h(j)-h(i)*p[j-i];
        else return (h(j)-h(i)*p[j-i]%m+m)%m;
    }
};

map<ll,int> mp[11];
template<class T>
T solve(T res = T()){
    string S; cin >> S;
    RH rh; rh.init(S);
    
    for(int i = 0; i < S.length();i++){
        for(int j = 1; j <= 10;j++){
            mp[j][rh.h(i,i+j)]++;
        }
    }
    
    int M; cin >> M;
    while(M--){
        string C; cin >> C;
        RH crh; crh.init(C);
        res += mp[C.length()][crh.h(C.length())];
    }

    for(int i = 0; i < M;i++){
        
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
