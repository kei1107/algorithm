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
 <url:https://yukicoder.me/problems/no/90>
 問題文============================================================
 ここに0番〜(N-1)番の品物がある。
 また、
 item1 item2 score
 という形式で書かれた得点表がある。
 品物を並べた時、item1がitem2よりも前であればscore点を獲得できるという意味である。
 
 得点表が与えられるので、品物を適切に並び替えた時、獲得できる得点を最大化したい。そのときの得点を出力せよ。

 =================================================================
 解説=============================================================
 
 Nの制約が小さいのでパターンを全列挙できる
 
 O(N!*N)
 十分間に合う
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    vector<ll> item1(M),item2(M),score(M);
    for(int i = 0; i < M;i++) cin >> item1[i] >> item2[i] >> score[i];
    
    vector<ll> per(N,0);
    vector<ll> rank(N,0);
    iota(per.begin(),per.end(),0);
    do{
        ll score_sum = 0;
        for(int i = 0; i < N;i++) rank[per[i]] = i;
        for(int i = 0; i < M;i++){
            if(rank[item1[i]] < rank[item2[i]]) score_sum += score[i];
        }
        res = max(res,score_sum);
    }while(next_permutation(per.begin(),per.end()));
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
