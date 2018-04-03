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
 <url:https://yukicoder.me/problems/no/17>
 問題文============================================================
 0 からN−1までのN個の地点がある。
 地点から地点の移動コストがM個与えられる。
 また各地点に滞在コストがある。
 
 0地点からN−1地点にたどり着くまでに、 0地点とN−1地点以外の異なる2つの地点に滞在しなければならない。
 滞在する地点は自由に決めて良い。
 この条件での移動コストと滞在コストの合計の最小値を求めよ。
 
 都市を通るけど、滞在しないこともできます。
 =================================================================
 解説=============================================================
 わーシャルフロイドで全頂点間の最短距離を求め
 
 0,N-1以外の2点を全探索して最短コストを求める
 ================================================================
 */

ll solve(){
    ll N; cin >> N;
    vector<ll> S(N);
    for(auto& in:S) cin >> in;
    ll M; cin >> M;
    vector<vector<ll>> G(N,vector<ll>(N,LINF));
    for(int i = 0; i < N;i++) G[i][i] = 0;
    for(int i = 0; i < M;i++){
        ll A,B,C; cin >> A >> B >> C;
        G[A][B] = G[B][A] = min(G[A][B],C);
    }
    for(int i = 0; i < N;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0; k < N;k++){
                G[j][k] = min(G[j][k],G[j][i]+G[i][k]);
            }
        }
    }
    ll res = LINF;
    for(int i = 1; i < N-1;i++){
        for(int j = 1; j < N-1;j++){
            if(i==j) continue;
            res = min(res,G[0][i]+S[i]+G[i][j]+S[j]+G[j][N-1]);
        }
    }
    return res;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
