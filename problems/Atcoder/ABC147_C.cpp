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
 <url:https://atcoder.jp/contests/abc147/tasks/abc147_c>
 問題文============================================================
 C - HonestOrUnkind2
 =================================================================
 解説=============================================================
 Nが小さいので、N人の正直者と不親切な人の全てのパターンについて全探索できる。
 よって、各パターンについて矛盾がないかを判定していけばいい。

 https://atcoder.jp/contests/abc147/submissions/9121097
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<vector<pii>> G(N);
    for(int i = 0; i < N;i++){
        int A; cin >> A;
        for(int j = 0; j < A;j++){
            int x,y; cin >> x >> y;
            x--;
            G[i].push_back(pii(x,y));
        }
    }

    for(int b = 0; b < (1<<N);b++){
        bool ok = true;

        for(int i = 0; i < N;i++){
            if((b>>i)&1){
                for(auto p:G[i]){
                    if(((b>>p.first)&1) == p.second) continue;
                    ok = false;
                }
            }
        }

        if(ok) res = max(res,(ll)__builtin_popcount(b));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
