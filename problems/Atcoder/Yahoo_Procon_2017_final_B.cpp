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
 <url:https://yahoo-procon2017-final-open.contest.atcoder.jp/tasks/yahoo_procon2017_final_b>
 問題文============================================================
 ACoder では，チーム高橋とチーム青木の 2 チーム対抗でのプログラミングコンテストを開こうとしています．
 チーム高橋の参加者の候補は N 人いて，チーム高橋の i 番目の候補者の実力は Ai で表されます．
 また，チーム青木の参加者の候補は M 人いて，チーム青木の i 番目の候補者の実力は Bi で表されます．
 
 コンテストを開く前に，チーム高橋，チーム青木のそれぞれから K 人ずつの参加者を選ぶことにしました．
 参加者は，それぞれのチームの参加者の候補から選ばれます．
 ここで，K 人ずつの参加者を選んだときの，チーム間の実力差を次のように定義することにしました．
 
 チーム高橋の参加者の中で i 番目に実力の値が大きい人の実力を Xi，
 チーム青木の参加者の中で i 番目に実力の値が大きい人の実力を Yi とする．
 このとき，チーム間の実力差は，max(|X1−Y1|,|X2−Y2|,…,|XK−YK|) である．
 各チームの参加者を決めたときの，チーム間の実力差の最小値を求めてください．

 =================================================================
 解説=============================================================
 
 まず、A,Bをソートしておくと嬉しい
 
 ここで、参加者はK人と固定されており、
 実力差を固定した時、にぶたんを行うことによってその実力差となるペアが最大何組できるかどうかを
 貪欲に求めることができる。
 
 よって、実力差についてにぶたんを行う
 評価関数 C(m) : = 最大の実力差がmの時に作れるペアの最大数
 とすれば良い
 ================================================================
 */


int N,M,K;
vector<ll> A(N),B(M);

ll  C(ll m){
    ll res = 0;
    ll Br = M;
    for(int i = N-1;i>=0;i--){
        long idxr = upper_bound(B.begin(),B.end(),A[i]+m) - B.begin();
        long idxl = lower_bound(B.begin(), B.end(),A[i]-m) - B.begin();
        if(idxr == 0) continue;
        if(idxr <= Br){
            if(abs(A[i]-B[idxr-1]) <= m){ res++; Br = idxr-1; }
        }else if(idxl < Br){
            if(abs(A[i]-B[Br-1]) <= m) { res++; Br = Br-1;}
        }
    }
    return res;
}
ll solve(){
    ll res = LINF;
    cin >> N >> M >> K;
    A.resize(N); B.resize(M);
    for(auto& in:A) cin >> in;
    for(auto& in:B) cin >> in;
    sort(A.begin(),A.end()); sort(B.begin(),B.end());
    ll l = -1, r = INF;
    while(r-l>1){
        ll m = (l+r)/2;
        if(C(m)>=K){
            r = m;
        }else{
            l = m;
        }
    }
    return res = r;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
