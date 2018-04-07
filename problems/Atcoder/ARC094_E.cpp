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
 <url:https://arc094.contest.atcoder.jp/tasks/arc094_c>
 問題文============================================================
 非負整数からなる数列 A,B が与えられます。 A,B の長さはともに N であり、
 A の値の総和と B の値の総和は等しいです。 A の i 項目は Ai であり、B の i 項目は Bi です。
 
 とざん君とげざん君は、以下の操作を繰り返します。
 
 もし A,B が列として等しいなら、繰り返しを終了する
 そうでない場合、まずとざん君が A の正の要素を 1 つ選び、1 減らす
 その後、げざん君が B の正の要素を 1 つ選び、1 減らす
 その後、ペットの高橋君に飴を 1 つ食べさせる
 とざん君は繰り返しが終了するまでに高橋君に食べさせる飴の個数を最大に、げざん君は最小にしたいです。
 両者最適に操作を行ったとき、高橋君に食べさせる飴の個数を求めてください。

 =================================================================
 解説=============================================================
 とざん君が圧倒的強者
 
 そして難易度的に　E <<<<<<<< D に感じた
 
 Ai < Bi であればAi個絶対とる
 Ai > Bi があれば
 Ai==BiとなるのはAi個全部取れて
 Ai>Biとなる物に関しては Ai>BiとなるAの総和:=sumAに対して max((sumA-Ai)+(Ai-Bi))が最適
 ================================================================
 */

void solve(){
    ll N; cin >> N;
    vector<ll> A(N),B(N);
    for(int i = 0; i < N;i++) cin >> A[i] >> B[i];
    ll cnt = 0;
    int f = 0;
    for(int i = 0; i < N;i++){
        if(A[i] < B[i]){
            cnt += A[i];
        }else if(A[i] > B[i]){
            f++;
        }
    }
    if(f){
        for(int i = 0; i < N;i++){
            if(A[i] == B[i]) cnt += A[i];
        }
        
        ll sumA = 0;
        for(int i = 0; i < N;i++){
            if(A[i] > B[i]){
                sumA += A[i];
            }
        }
        
        ll tmp = cnt;
        for(int i = 0; i < N;i++){
            if(A[i] > B[i]){
                cnt = max(cnt,tmp+(sumA-A[i]+A[i]-B[i]));
            }
        }
    }
    
    cout << cnt << endl;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
