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
 <url:https://yukicoder.me/problems/no/202>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 全探索する必要はなく、一定の領域内だけを探してやれば良い
 ================================================================
 */

const ll MAX = 20000;
vector<ll> G[MAX+1];
bool check(ll X,ll Y){
    for(ll x = max(0LL,X-20); x <= min(MAX,X+20);x++){
        ll ind = lower_bound(G[x].begin(),G[x].end(),max(0LL,Y-20)) - G[x].begin();
        while(ind < G[x].size() && G[x][ind] <= min(MAX,Y+20)){
            ll y = G[x][ind];
            
            ll absx = abs(x-X),absy = abs(y-Y);
            if(absx*absx+absy*absy<20*20) return false;
            ind++;
        }
    }
    return true;
}
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    while(N--){
        ll X,Y; cin >> X >> Y;
        if(check(X,Y)){
            G[X].push_back(Y);
            sort(G[X].begin(),G[X].end());
            res++;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
