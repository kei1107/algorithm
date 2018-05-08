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
 <url:https://yukicoder.me/problems/no/68>
 問題文============================================================
 ユウキさんは N 本の棒を持っていて、i 番目の棒の長さは Li です。
 棒は（長さを分割する方向に）自由に切ることができますが、繋げることはできません。
 ユウキさんは同じ長さの棒を作りたいのですが、何本であればどのぐらいの長さにできるかが気になっています。
 同じ長さの棒を K1,K2,…,KQ 本作るとしたら、その時の棒の長さの最大値をそれぞれ求めるプログラムを書いて下さい。
 =================================================================
 解説=============================================================
 
 解説を見た。
 
 ある棒について着目した時、その棒の長さを L ,その棒から a本の棒を作るとすれば、
 長さL/aが最大の長さとなる。
 つまり、a+1本目が欲しければ最大の長さは L/(a+1)となる
 
 よって、 L/aについてpriority_queueなどで整理して、全体の棒の使用本数を 0本から初めて、
 L/(a+1)の大きい順に処理を行っていき、先に500000までのテーブルを作成しておけばよい
 ================================================================
 */

typedef long double ld;
#define MAX_K 500001
ld query[MAX_K];

struct bou{
    ld L;
    ll x;
    bou(){}
    bou(ld l,ll x):L(l),x(x){}
    bool operator < (const bou& b) const{
        return (L/(x+1)) < (b.L/(b.x+1));
    }
};
void solve(){
    ll N; cin >> N;
    priority_queue<bou> pq;
    vector<ll> L(N); for(auto& in:L){ cin >> in; pq.push(bou(in,0)); }
    for(int i = 1; i < MAX_K; i++){
        auto b = pq.top(); pq.pop();
       // cout << b.L << " " << b.x << endl;
        b.x++;
        query[i] = b.L/b.x;
        pq.push(b);
    }
    ll Q; cin >> Q;
    vector<ll> K(Q); for(auto& in:K){
        cin >> in;
        cout << fixed << setprecision(12) <<  query[in] << endl;
    }
    
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
