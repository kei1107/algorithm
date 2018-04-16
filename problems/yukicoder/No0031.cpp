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
 <url:https://yukicoder.me/problems/no/31>
 問題文============================================================
 ミックスジュースが切れました。
 ミックスジュースの原材料の表示は、順番に、果物 1，果物 2，…，果物 N となっています。
 既存のそれぞれの果物の100%ジュースを混ぜてミックスジュースを V リットルだけ作りたいです。
 果物 k の100%ジュースは 1 リットルパックのみが売られていて、1 パックあたり Ck 円です。
 V リットルのミックスジュースを、原材料の表示を変更することなく作るための、最小コストを求めるプログラムを書いてください。
 つまり、ミックスジュースにおいて果物 k が占める割合 pk は p1≥p2≥⋯≥pN となる必要があり、
 更に、使われない果物があってもいけません。
 1 リットルパックを買い、その一部のみを使用することも可能です。
 
 1  行目では、果物の種類数を表す整数 N (1≤N≤100) と作りたいミックスジュースの量を表す整数 V (1≤V≤109) が与えられます。
 2 行目では、果物 k の100%ジュースの 1 リットルパックの値段を表す整数 Ck (1≤Ck≤109) が順番にスペース区切りで与えられます。
 
 =================================================================
 解説=============================================================
 
 難しい、、、
 解説みた
 
 
 この問題は mばんめまでのパックを購入するには [1,m]の全てのパックを購入しなければならない
 よって cusum[m]/m が最も小さいものをできるだけまとめて購入したい
 
 しかし、実際は過不足が発生するため、
 発生した過不足をdpによって計算する。
 
 ================================================================
 */


ll solve(){
    ll res = 0;
    ll N,V; cin >> N >> V;
    vector<ll> C(N); for(auto& in:C) cin >> in;
    vector<ll> cusum(N+1,0);
    for(int i = 0; i < N; i++) cusum[i+1] = cusum[i] + C[i];
    V -= N;
    if(V <= 0) return cusum[N];
    
    ll x = 1;
    for(ll i = 2; i <= N; i++){
        if(cusum[i]*x < cusum[x]*i) x = i;
    }
    ll minV = min(10200LL,V);
    vector<ll> dp(minV+1+N,0);
    for(ll i = 0; i <= minV; i++){
        dp[i] = LINF;
        if((V-i)%x==0) dp[i] = (V-i)/x*cusum[x];
    }
    minV = min(10000LL,V);
    for(ll i = minV; i>=0; i--){
        for(int j = 1; j <= N; j++) dp[i] = min(dp[i],dp[i+j]+cusum[j]);
    }
    res = dp[0] + cusum[N];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
