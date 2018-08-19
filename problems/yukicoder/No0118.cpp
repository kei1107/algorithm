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
 <url:https://yukicoder.me/problems/no/118>
 問題文============================================================
 =================================================================
 解説=============================================================
 門松列を作れと言っても、結局は相異なる値の数字3つがあれば作ることができるので、
 この問題は数列の中から相異なる3つの数字の取り方の総数を答えれば良い
 
 これは、ソート済みの数列に対して順番に値を見て行き、
 その値を相異なる数字の真ん中の値とすれば、
 （それよりも小さい値の数）x (それよりも大きい値の数）
 として個数がわかるので、全てのいちについて試せば良い
 ================================================================
 */

const ll MOD = 1e9+7;
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    sort(A.begin(),A.end());
    for(int i = 0; i < N;i++){
        ll V = A[i];
        ll l = lower_bound(A.begin(), A.end(), V) - A.begin();
        ll r = N - (upper_bound(A.begin(),A.end(),V) - A.begin());
        (res += l*r)%=MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
