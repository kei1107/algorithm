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
 <url:https://yukicoder.me/problems/no/370>
 問題文============================================================
 =================================================================
 解説=============================================================
 ちょっと実装が面倒だけど落ち着いてかけばok
 
 折り返し地点を全探索する。
 ================================================================
 */

int solve(){
    int res = INF;
    int N,M; cin >> N >> M;
    vector<int> D(M+1);
    for(int i = 0; i < M;i++){
        cin >> D[i];
        if(D[i] == 0) N--;
    }
    if(!N) return 0;
    sort(D.begin(),D.end());
    D.erase(unique(D.begin(),D.end()),D.end());
    
    int idx = (int)(lower_bound(D.begin(), D.end(), 0) - D.begin());
    for(int i = 0; i < D.size(); i++){
        if(i == idx) continue;
        if(abs(idx-i) > N) continue;

        int l,r;
        if(i < idx){
            l = i; r = idx + N-(idx-i);
            if(r >= M) continue;
        }else{
            l = idx-(N-(i-idx)); r = i;
            if(l < 0) continue;
        }
        res = min(res,abs(D[l])+abs(D[r]) + min(abs(D[l]),abs(D[r])));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
