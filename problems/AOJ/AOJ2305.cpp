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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2305>
 問題文============================================================
 いい数列が次のように定義される
 i番目に小さい数字はi+1番目を割ることができる
 
 ここで、ある昇順な数列が与えられる。
 この数列の各要素を任意の値に変更して良いとき、いい数列にしたい。
 ただし、値を変更するとき |変更後の値-元々の値|/元々の値 の　コストがかかる
 
 全ての値に関して、変更に伴うコストの最大値を最小にしたい。
 =================================================================
 解説=============================================================
 
 意外とdpで間に合う
 
 先に次遷移としていける値を求めて起き、
 
 dp[i][j] := i番目の値を見た時、今の値がjであるときのコストの最大の最小
 
 とすればいける
 ================================================================
 */
typedef long double ld;
ld solve(){
    ld res = 0;
    int N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    ll MAXA = *a.rbegin();
    vector<vector<ld>> dp(N+1,vector<ld>(2*MAXA+1,INF));
    vector<vector<ll>> Next(2*MAXA+1);
    for(int i = 1; i <= 2*MAXA;i++){
        for(int j = i; j <= 2*MAXA;j+=i){
            Next[i].push_back(j);
        }
    }
    for(int i = 1; i <= 2*MAXA;i++) dp[0][i] = 0; //abs(i-a[0])/(ld)a[0];
    for(int i = 0; i < N;i++){
        for(int j = 1; j <= 2*MAXA;j++){
            for(int k = 0; k < Next[j].size(); k++){
                dp[i+1][Next[j][k]] = min(dp[i+1][Next[j][k]],
                                          max(dp[i][j],abs(Next[j][k]-a[i])/(ld)a[i]));
            }
        }
    }
    res = *min_element(dp[N].begin(), dp[N].end());
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
