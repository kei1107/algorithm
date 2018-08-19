#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/120>
 問題文============================================================
 =================================================================
 解説=============================================================
 余っている長さの門松をその長さの数が多い順に貪欲に取って行けば良い
 ================================================================
 */
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> L(N); for(auto& in:L) cin >> in;
    set<ll> s(L.begin(),L.end());
    vector<ll> cnt;
    for(auto it:s) cnt.push_back(count(L.begin(),L.end(),it));

    bool update = true;
    while(update){
        update = false;
        
        sort(cnt.rbegin(),cnt.rend());
        
        int T = 0;
        for(int i = 0; i < cnt.size();i++){
            if(cnt[i]){
                T++; cnt[i]--;
                if(T==3) break;
            }
        }
        if(T==3){
            res++;
            update = true;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll T; cin >> T;
    while(T--){
        cout << solve() << endl;
    }
    return 0;
}
