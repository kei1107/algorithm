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
 <url:https://atcoder.jp/contests/abc146/tasks/abc146_f>
 問題文============================================================
 F - Sugoroku
 =================================================================
 解説=============================================================
 
 最短手数で辞書順最小が答えなので、
 理想的な動きとすれば最短手数を満たす範囲で
 最初のうちはできるだけ小さい値で移動しつつ、後半はできるだけ大きい値で移動するということがしたい
 
 これは、実は双六を逆から考えることによって簡単に実装できる。
 双六を逆から考えて、移動できる最大の移動を行なっていく、逆から考えることによって
 後半（正順の双六での前半）は小さい値での移動となり自ずと辞書順最小となる。
 
 https://atcoder.jp/contests/abc146/submissions/9106372
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    string S; cin >> S;
    for(auto& c:S) c -= '0';

    reverse(S.begin(),S.end());
    
    vector<int> idx;
    for(int i = 0; i <= N;i++){
        if(S[i] == 0) idx.push_back(i);
    }
    idx.push_back(INF);
    
    int now = 0;
    while(idx[now] != N){
        if(idx[now+1]-idx[now] > M) return vector<ll>{-1};
        int next = now+1;
        while(idx[next+1]-idx[now] <= M){
            next++;
        }
        
        res.push_back(idx[next]-idx[now]);
        now = next;
        
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<vector<ll>>() << endl;
    return 0;
}
