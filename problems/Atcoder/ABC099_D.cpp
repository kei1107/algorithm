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
 <url:https://beta.atcoder.jp/contests/abc099/tasks/abc099_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 条件より余りが0,1,2になるグループの色を決め打ちすればよい
 この時、初期状態の時に各グループの各色がいくつ存在するのか配列でまとめておけば
 O(N^3*C)で解ける
 ================================================================
 */

ll solve(){
    ll res = LINF;
    ll N,C; cin >> N >> C;
    vector<vector<ll>> D(C+1,vector<ll>(C+1));
    vector<vector<ll>> c(N+1,vector<ll>(N+1));
    for(int i = 1; i <= C;i++)for(int j = 1; j <= C;j++) cin >> D[i][j];
    for(int i = 1; i <= N;i++)for(int j = 1; j <= N;j++) cin >> c[i][j];
    vector<vector<ll>> cnt(3,vector<ll>(C+1));
    for(int i = 1; i<=N;i++)for(int j = 1;j<=N;j++) cnt[(i+j)%3][c[i][j]]++;
    for(int c1 = 1; c1 <= C; c1++){
        for(int c2 = 1; c2 <=C; c2++){
            for(int c3 = 1; c3 <= C;c3++){
                if(c1 == c3) continue;
                if(c1 == c2) continue;
                if(c2 == c3) continue;
                ll T = 0;
                for(int j = 1; j <= C;j++) T += cnt[0][j]*D[j][c1];
                for(int j = 1; j <= C;j++) T += cnt[1][j]*D[j][c2];
                for(int j = 1; j <= C;j++) T += cnt[2][j]*D[j][c3];
                res = min(res,T);
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
