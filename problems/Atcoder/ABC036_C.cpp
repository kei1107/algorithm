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
 <url:https://beta.atcoder.jp/contests/abc036/tasks/abc036_c>
 問題文============================================================
 N 人の人が座っています。 i 番目の人の座圧は ai です。
 すぬけ君は、大小関係を保存したまま座圧のデータを圧縮して保存することにしました。
 以下の条件を満たす数列 b1,…,bN を求めてください。
 bi はすべて非負整数である。
 ai<aj ならば bi<bj である。
 ai=aj ならば bi=bj である。
 上の条件を満たす配列のうち、bi の最大値が最小となる。
 このような条件をみたす b は一意に定まることが知られています。

 =================================================================
 解説=============================================================
 
 そのまま座圧して、それ自身が何番目となるのかを出力すればよい
 ================================================================
 */

void solve(){
    ll N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    vector<ll> tmp = a;
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for(int i = 0; i < N;i++){
        a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
        cout << a[i] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
