#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://onlinejudge.u-aizu.ac.jp/problems/1626>
 問題文============================================================
 =================================================================
 解説=============================================================
 数学
 
 とある未知の階nから連続してc個のビルを借りて条件を満たすと仮定すると
 
 n*c + c*(c-1)/2 = b
 
 が成り立つ
 nについて整理すると
 
 n = (2*b - (c*c - c))/(2*c)
 
 右辺が自然数となるとき条件を満たす
 
 この時右辺の分子式は正でなければならないのでcの範囲は高々
 
 1 <= c <= √b + α
 
 となって愚直に探索ができる
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    
    ll b;
    while(cin >> b,b){
        ll ans1 = b , ans2 = 1;
        ll c = 2;
        while(2*b > c*c - c){
            if((2*b-(c*c-c))%(2*c) == 0){
                ans1 = min(ans1,(2*b-(c*c-c))/(2*c));
                ans2 = c;
            }
            c++;
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
