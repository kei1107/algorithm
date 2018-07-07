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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2780>
 問題文============================================================
 
 N個の数列から任意の二つの要素選択する
 その二つの要素の積が 123  456  234 6789
 のように順番に値が1繰り上がる形になっているものがある時、その値の最大を出力せよ
 =================================================================
 解説=============================================================
 愚直に全部試す
 ================================================================
 */
ll solve(){
    ll res = -1;
    ll N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            ll A = a[i]*a[j];
            string sA = to_string(A);
            [&](){
                for(int k = 0; k < sA.length()-1;k++){
                    if(sA[k]-'0'+1==sA[k+1]-'0') continue;
                    return;
                }
                res = max(res,A);
            }();
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
