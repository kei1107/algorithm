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
 <url:https://csacademy.com/contest/round-76/task/candy-boxes/>
 問題文============================================================
 N個の箱がある、各箱には最初いくつかの飴が入っている。
 
 M個のイベントが与えられる。
 イベント1 : 箱Xから飴を一つ取り出す。箱Xには少なくとも一つの飴が入っていなければならない。
 イベント2 : 飴を一つ受け取り、任意の箱に入れることができる。
 
 全てのイベントを満たすように行動したとき、時系列順にイベント２で入れた箱の番号の述べよ
 
 尚、必ず全てのイベントを満たすような解が存在することが保証されている
 =================================================================
 解説=============================================================
 
 飴をすぐに使わずにストックしておく。
 各イベントの操作は次のようにすればよい
 
 イベント１: 最初の箱の状態からイベント１が発生したらその箱の飴を取り出す。
            （箱の飴がなければストックから用いて、もともと入っていたことにする。）
 イベント２: 飴1個ストックする
 
 最後に、残っている飴の分だけ適当に箱に入れたことにすれば条件を満たす
 
 ================================================================
 */

void solve(){
    ll N,M; cin >> N >> M;
    vector<ll> candy(N);
    for(auto& in:candy) cin >> in;
    vector<int> ans;
    int query = 0;
    for(int i = 0; i < M;i++){
        int q; cin >> q;
        if(q == 1){
            int x; cin >> x;
            if(candy[x-1] == 0) ans.push_back(x);
            else candy[x-1]--;
        }else{
            query++;
        }
    }
    
    while(ans.size() < query){
        ans.push_back(1);
    }
    for(int i = 0; i < query;i++){
        cout << ans[i] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
