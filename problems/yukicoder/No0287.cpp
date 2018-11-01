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
 <url:https://yukicoder.me/problems/no/287>
 問題文============================================================
 =================================================================
 解説=============================================================
 半分全列挙の要領でmapなどに詰めて数え上げれば間に合う
 
 (dpでもいけそう....)
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll n; cin >> n;
    map<ll,ll> vals;
    for(int a = 0; a <= n; a++){
        for(int b = 0; b <= n; b++){
            for(int c = 0; c <= n; c++){
                for(int d = 0; d <= n; d++){
                    vals[a+b+c+d]++;
                }
            }
        }
    }
    for(const auto& p:vals){
        res += p.second*vals[6*n-p.first];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
