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
 <url:https://yukicoder.me/problems/no/408>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 1-u-v
 と
 1-u'-v'
 の関係を列挙し、全探索すればいい
 ================================================================
 */


string solve(){
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> A(M),B(M);
    for(int i = 0; i < M;i++){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    
    vector<vector<int>> GG(N);
    for(auto v:G[0]) for(auto vv:G[v]) GG[vv].push_back(v);
    
    for(int i = 0; i < M;i++){
        if(A[i] == 0 || B[i] == 0) continue;
        
        if(GG[A[i]].size()>3 && GG[B[i]].size()>3) return "YES";
        for(int a : GG[A[i]]){
            for(int b : GG[B[i]]){
                if(a!=b && a!=B[i] && b!=A[i]) return "YES";
            }
        }
    }
    return "NO";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
