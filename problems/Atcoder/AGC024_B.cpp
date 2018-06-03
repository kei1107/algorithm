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
 <url:https://beta.atcoder.jp/contests/agc024/tasks/agc024_b>
 問題文============================================================
 =================================================================
 解説============================================================= 
 本番中に解けなかった。反省
 
 任意の要素を取り出して前後に移すことができるということは
 相対的な順序を変更されない数字達を作ることができる。
 
 この数字をすでに順番的に揃っているもので最大のものとすれば、
 それ以外を前方または後方に移せばいいため。。。
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> P(N);
    for(auto& in:P) {cin >> in; in--; }
    vector<ll> a(N);
    for(int i = 0; i < N;i++){
        a[P[i]] = i;
    }
    ll now = 1;
    ll tmp = 1;
    for(int i = 0; i < N-1;i++){
        if(a[i] < a[i+1]){
            now++;
            tmp = max(tmp,now);
        }else{
            now = 1;
        }
    }
    res = N - tmp;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
