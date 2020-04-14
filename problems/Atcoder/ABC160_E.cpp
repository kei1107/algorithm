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
 <url:https://atcoder.jp/contests/abc160/tasks/abc160_e>
 問題文============================================================
 E - Red and Green Apples
 =================================================================
 解説=============================================================

 食べることが可能であればおいしいリンゴから順に食べて行きたいのがあたり前
 ただ、数の制限があるため、赤と緑リンゴは食べることができない場合がある。

 そこで、すべてのリンゴをおいしい順に大きい順に並べられていると考える。
 この時、順番にリンゴをみて行った時、それまでに食べた赤・緑・無のリンゴの個数をx,y,zとしたとき。

 赤リンゴの場合、x<X かつ x+y+z<X+Yの時食べることができる。
 緑リンゴの場合、y<Y かつ x+y+z<X+Yの時食べることができる。
 無色リンゴの場合、x+y+z<X+Yの時食べることができる。

 上記条件にそってリンゴを食べていけばいい。

 https://atcoder.jp/contests/abc160/submissions/11901180

 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll X,Y,A,B,C; cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A),q(B),r(C);
    for(auto& in:p) cin >> in;
    for(auto& in:q) cin >> in;
    for(auto& in:r) cin >> in;

    vector<pll> V;
    for(auto v:p) V.emplace_back(pll(v,0));
    for(auto v:q) V.emplace_back(pll(v,1));
    for(auto v:r) V.emplace_back(pll(v,2));

    sort(V.rbegin(),V.rend());

    ll x = 0,y = 0,z = 0;
    for(int i = 0; i < (int)V.size();i++){
        ll v,id; tie(v,id) = V[i];
        if(id == 0){
            if(x < X){
                res += v;
                x++;
            }
        }else if(id == 1){
            if(y < Y){
                res += v;
                y++;
            }
        }else{
            res += v;
            z++;
        }
        if(x+y+z == X+Y) break;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
