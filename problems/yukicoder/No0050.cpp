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
 <url:https://yukicoder.me/problems/no/50>
 問題文============================================================
 おもちゃがN個とおもちゃ箱がM個ある。
 おもちゃとおもちゃ箱にはそれぞれ容積が決まっている。
 おもちゃ箱の容積以下のおもちゃをおもちゃ箱に入れることができる。
 おもちゃ箱の容積以下であればおもちゃはいくつでも入る。
 おもちゃ箱をおもちゃ箱に入れてはならない。
 
 例えば、容積2のおもちゃと容積3のおもちゃと容積5のおもちゃ箱がある。
 この場合、おもちゃ2つの容積は足して5なので容積5のおもちゃ箱に入る。
 
 例えば、容積8のおもちゃと容積12のおもちゃと容積10のおもちゃ箱がある。
 この場合、おもちゃ2つの容積は足して20なので容積10のおもちゃ箱に入らない。
 ただし、容積8のおもちゃだけであれば容積10のおもちゃ箱に入る。
 
 おもちゃとおもちゃ箱の情報が与えられる。
 おもちゃをすべて入れることができる最小のおもちゃ箱の数を求めよ。
 ただし、すべてのおもちゃがおもちゃ箱に入りきらなければ-1を答えとする。
 
 =================================================================
 解説=============================================================
 
 dp[S1][S2] := S1の状態のおもちゃが残っている時、S2の箱が使用済みであるか否か
 
 としてbitDP
 
 この時、ある箱bがまとめて入れることができるおもちゃの集合をまとめておくと高速に処理できる
 ================================================================
 */

ll solve(){
    ll res = INF;
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    ll M; cin >> M;
    vector<ll> B(M); for(auto& in:B) cin >> in;
    
    vector<vector<ll>> mask(M);
    for(int i = 0; i < M;i++){
        for(int j = 1; j < (1<<N); j++){
            ll sum = 0;
            for(int k = 0; k < N; k++){
                if((j>>k)&1) sum += A[k];
            }
            if(sum <= B[i]) mask[i].push_back(j);
        }
    }
    for(int i = 0; i < M;i++){
        for(int j = 0; j < mask[i].size();j++){
            for(int k = 0; k < mask[i].size();k++){
                if((mask[i][j]|mask[i][k]) == mask[i][j]) mask[i][k] = mask[i][j];
            }
        }
        sort(mask[i].begin(),mask[i].end());
        mask[i].erase(unique(mask[i].begin(),mask[i].end()),mask[i].end());
    }
    
    vector<vector<int>> dp(1<<N,vector<int>(1<<M,0));
    dp[0][0] = true;
    for(int i = 0; i < (1<<N); i++){
        for(int j = 0; j < (1<<M); j++){
            if(dp[i][j] == 0) continue;
            for(int k = 0; k < M;k++){
                if((j>>k)&1) continue;
                for(auto& S:mask[k]){
                    dp[i|S][j|(1<<k)] = true;
                }
            }
        }
    }
    for(int i = 0; i < (1<<M); i++){
        if(!dp[(1<<N)-1][i]) continue;
        res = min(res,(ll)__builtin_popcount(i));
    }
    return res==INF?-1:res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
