#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc161/tasks/abc161_d>
 問題文============================================================
 D - Lunlun Number
 =================================================================
 解説=============================================================

 あるルンルン数から次のルンルン数への遷移は末尾1桁に応じて最大3パターンで遷移できる。
 昇順にルンルン数を見ていきたいので、1...9から順に1->10,11,12・2->21,22,23・3->...
 と次々にルンルン数を生成していくことで解ける。
 これはdequeなどを用いることで簡単に実装できる。

 https://atcoder.jp/contests/abc161/submissions/11910632

 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll K; cin >> K;

    deque<ll> dq;
    for(int i = 1; i <= 9;i++) dq.push_back(i);

    for(int k = 0; k < K-1;k++){
        ll x = dq.front(); dq.pop_front();

        if(x%10 != 0) dq.push_back(10*x+x%10-1);
        dq.push_back(10*x + x%10);
        if(x%10 != 9) dq.push_back(10*x+x%10+1);
    }
    res = dq.front();
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
