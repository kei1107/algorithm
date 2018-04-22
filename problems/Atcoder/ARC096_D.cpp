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
 <url:https://arc096.contest.atcoder.jp/tasks/arc096_b>
 問題文============================================================
 日本料理店「停止寿司」は円形のカウンターが一つあるだけのシンプルな店です。
 カウンターの外周の長さは C メートルで、カウンターの内部に客が立ち入ることはできません。
 
 中橋くんが入店し、カウンターのそばまで案内されました。
 いま、カウンター上には N 貫の寿司が置かれています。
 そのうち i 貫目は中橋くんがいる位置から xi メートル時計回りに進んだ位置に置かれており、
 vi キロカロリーの栄養価を持ちます。
 
 中橋くんはカウンターの外周を自由に歩き回ることができます。
 寿司が置かれている位置にたどり着いたら、その寿司を食べて寿司が持つ栄養価を摂取することができます
 （当然、その寿司は消えます）。ただし、歩く際に 1 メートルあたり 1 キロカロリーを消費します。
 
 満足したら、いつでも好きな位置から店を出ることができます（始めにいた位置に戻らなくても構いません）。
 店を出るまでに最大で差し引き何キロカロリーを摂取することができるでしょうか？
 すなわち、退店するまでに摂取した栄養価の合計から消費したエネルギーを引いた値の最大値はいくらでしょうか？
 なお、他に客はおらず、新たな寿司がカウンターに追加されることもないものとします。
 また、中橋くんは十分な栄養を蓄えているため、どれだけ歩いてエネルギーを消費しても餓死しないものとします。
 
 =================================================================
 解説=============================================================
 
 時計周りのみ
 反時計回りのみ
 時計周りから反時計回り
 反時計回りから時計回り
 の４パターンを探索する。
 
 累積和などで事前処理をしておくと、各パターンの最適行動がO(1)で判定でき、O(N)で全体計算できる
 ================================================================
 */

ll N,C;
vector<ll> x,v;
ll solve(){
    ll res = 0;
    cin >> N >> C;
    x.resize(N); v.resize(N);
    for(int i = 0; i < N;i++) cin >> x[i] >> v[i];
    
    vector<ll> cusum(N+1,0);
    vector<ll> rcusum(N+1,0);
    for(int i = 0; i <N;i++){
        cusum[i+1] = cusum[i] + v[i];
    }
    for(int i = 0; i < N;i++){
        cusum[i+1] -= x[i];
        res = max(res,cusum[i+1]);
    }

    reverse(x.begin(),x.end()); reverse(v.begin(),v.end());
    for(int i = 0; i < N;i++){
        rcusum[i+1] = rcusum[i] + v[i];
    }
    for(int i = 0; i < N;i++){
        rcusum[i+1] -= (C-x[i]);
        res = max(res,rcusum[i+1]);
    }
  
    vector<ll> check(N+1,0);
    for(int i = 1; i <= N;i++){
        check[i] = max(rcusum[i],check[i-1]);

    }

    reverse(x.begin(),x.end());
    for(int i = 1; i < N; i++){
        res = max(res,cusum[i]-x[i-1]+check[N-i]);
    }
    
    check.assign(N+1,0);
    for(int i = 1; i <= N;i++){
        check[i] = max(cusum[i],check[i-1]);
    }
    reverse(x.begin(),x.end());
    for(int i = 1; i < N;i++){
        res = max(res,rcusum[i]-(C-x[i-1])+check[N-i]);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
