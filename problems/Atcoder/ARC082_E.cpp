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
 <url:https://beta.atcoder.jp/contests/arc082/tasks/arc082_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 解説を見た　http://kmjp.hatenablog.jp/entry/2017/09/02/0900
 
 kmjpさんのブログより
 
 今回のスコアは
 「N個のうち各頂点を選ぶ選ばないの２択で、計2^Nの選び方をしたとき、それらの凸包の面積が正となるものは何通りか。」
 というものに変換することができる為、
 
 全体から計算することができる
 
 ================================================================
 */

const ll MOD = 998244353;
vector<ll> fact;
ll N;
ll solve(){
    ll res = 0;
    cin >> N;
    vector<pll> ps(N); for(auto& in:ps) cin >> in.first >> in.second;
    fact.resize(N+1);
    fact[0] = 1;
    for(int i = 1; i <= N;i++) fact[i] = fact[i-1]*2%MOD;

    res = (fact[N] + MOD - 1 - N - N*(N-1)/2)%MOD;
    
    vector<vector<int>> checked(N,vector<int>(N,0));
    for(int i = 0; i < N;i++){
        for(int j = 0; j < i;j++){
            if(checked[i][j]) continue;
            vector<int> idx{i,j};
            for(int k = 0; k < N;k++){
                if(k == i || k == j) continue;
                if((ps[i].first-ps[j].first)*(ps[i].second-ps[k].second)-(ps[i].first-ps[k].first)*(ps[i].second-ps[j].second) == 0){
                    idx.push_back(k);
                }
            }
            for(auto v:idx){
                for(auto vv:idx){
                    checked[v][vv] = 1;
                }
            }
            int sz = (int)idx.size();
            if(sz >= 3){
                res = (res + MOD - fact[sz] + sz + sz*(sz-1)/2 + 1)%MOD;
            }
        }
    }
    (res += MOD)%=MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
