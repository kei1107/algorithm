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
 <url:https://yukicoder.me/problems/no/368>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 各Aの素因数を調べて、指数が多い順にK個取っていって積を作ればいい
 ================================================================
 */

const ll MOD = 1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

map<ll,vector<ll>> mp;
void PrimeFact(ll n,map<ll,ll>& M){
    while(n!=1){
        if(n == 2 || n == 3){
            M[n]++;
            n/=n;
            continue;
        }
        bool prime_flag = false;
        for(int i = 2;i*i <= n;i++){
            if(n%i==0){
                M[i]++;
                n/=i;
                prime_flag = true;
                break;
            }
        }
        if(!prime_flag){M[n]++; n/= n;}
    }
}
ll solve(){
    ll res = 1;
    ll N,K; cin >> N >> K;
    for(int i = 0; i < N;i++){
        ll A; cin >> A;
        map<ll,ll> M;
        PrimeFact(A, M);
        for(auto p:M){
            mp[p.first].push_back(p.second);
        }
    }
    for(auto& p:mp){
        sort(p.second.rbegin(),p.second.rend());
        ll S = 0;
        for(int i = 0; i < min(K,(ll)p.second.size());i++) S += p.second[i];
        for(int i = 0; i < S;i++) (res *= p.first)%=MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
