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
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 愚直に探索すると間に合わない。
 
 よって、2つの要素は全探索しつつ、setやセグ木を使って高速にしてやればいい
 ================================================================
 */

ll solve(){
    ll res(0);
    int N,M; cin >> N >> M;
    vector<vector<int>> E(M,vector<int>(N));
    for(auto& vec:E) for(auto& in:vec) cin >> in;
    
    int maxv = 0;
    for(int _ = 0; _ < M; _++){
        int T = 0;
        
        const vector<int>& e = E[_];
        for(int i = 0; i < N;i++){
            set<int> lsec,msec,rsec;
            for(int j = 0; j < i; j++) lsec.insert(e[j]);
            for(int j = i+1; j < N;j++) rsec.insert(e[j]);
            
            for(int j = i+1; j < N;j++){
                int t = 0;
                
                rsec.erase(e[j]);
                
                if(lsec.size()){
                    if(e[i] < e[j] && *lsec.rbegin() > e[i]) t = max({t,e[j],*lsec.rbegin()});
                    if(e[i] > e[j] && *lsec.begin() < e[i]) t = max({t,e[i]});
                }
                if(msec.size()){
                    if(*msec.rbegin()>max(e[i],e[j])) t = max(t,*msec.rbegin());
                    if(*msec.begin()<min(e[i],e[j])) t = max(t,max(e[i],e[j]));
                }
                if(rsec.size()){
                    if(e[i] > e[j] && *rsec.rbegin()>e[j]) t = max(t,max(e[i],*rsec.rbegin()));
                    if(e[i] < e[j] && *rsec.begin()<e[j]) t = max(t,e[j]);
                }
                
                T += t;
                msec.insert(e[j]);
            }
            
        }

        cout << T << endl;
        if(T > maxv){
            maxv = T;
            res = _;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
