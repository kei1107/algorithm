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
<url:https://beta.atcoder.jp/contests/arc093/tasks/arc093_a>
問題文============================================================
 x 軸上に N 個の観光スポットがあり、1,2,…,N の番号がついています。
 観光スポット i は座標 Ai の点にあります。 また、x 軸上を座標 a の点から座標 b の点まで移動するには |a−b| 円かかります。
 
 あなたは x 軸上を旅行する計画を立てました。
 計画では、最初に座標 0 の点を出発し、N 個の観光スポットを番号順に訪れ、
 最後に座標 0 の点に戻ってくることになっています。
 
 ところが、旅行の直前に急用が入り、N 個すべての観光スポットを訪れる時間的余裕がなくなってしまいました。
 そこで、ある i を選び、観光スポット i を訪れるのを取りやめることにしました。
 それ以外の観光スポットは予定通り番号順に訪れます。
 また、最初に座標 0 の点を出発し、最後に座標 0 の点に戻ってくることについても、予定に変更はありません。
 
 i=1,2,…,N それぞれについて、観光スポット i を訪れるのを取りやめたときの、
 旅行中の移動にかかる金額の総和を求めてください。
=================================================================

解説=============================================================

 A[0] = 0 , A[N+1] = 0
 として累積和をとる
 
 答えは各iについて
 　cusum - abs(A[i] - A[i-1]) - abs(A[i+1] - A[i]) + abs(A[i+1] - A[i-1])
 
================================================================
*/
void solve(){
    ll N; cin >> N;
    vector<ll> A(N+2,0);
    for(int i = 1; i <= N;i++) cin >> A[i];
    ll cusum = 0;
    for(int i = 1; i <= N+1;i++){
        cusum += abs(A[i] - A[i-1]);
    }
   // cusum += abs(A[N] - A[0]);
    
    for(int i = 1; i <= N;i++){
        cout << cusum - abs(A[i] - A[i-1]) - abs(A[i+1] - A[i]) + abs(A[i+1] - A[i-1]) << endl;
    }
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve();
    return 0;
}

