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
 <url:https://atcoder.jp/contests/abc140/tasks/abc140_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 この手の問題は、範囲でみるのではなく。
 
 X_L,RがP_iとなる場合の数がいくつかを調べるのが定石
 
 この時、P_iについて大きい順に見て行った時、setなどにそのindexを詰めておけば
 P_iよりも左側にある直近２つのP_iよりも大きい要素のindexと
 P_iよりも右側にある直近２つのP_iよりも大きい要素のindexがO(NlogN)で分かる。
 あとは数学で個数を数え上げることができる。
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    
    vector<pll> P(N);
    for(int i = 0; i < N;i++){
        cin >> P[i].first;
        P[i].second = i+1;
    }
    sort(P.rbegin(),P.rend());
    set<ll> S;
    S.insert(0); S.insert(N+1);
    S.insert(P.front().second); P.erase(P.begin());

    for(auto p:P){
        ll v,id; tie(v,id) = p;

        auto it = S.lower_bound(id);
        ll x1,x2,x3,x4;

        x3 = *it;
        {
            it++;
            if(it == S.end()){
                x4 = x3;
            }else{
                x4 = *it;
            }
            it--;
            it--;
        }
        x2 = *it;
        {
            if(it == S.begin()){
                x1 = x2;
            }else{
                it--;
                x1 = *it;
            }
        }
        res += v * ((x2 - x1) * (x3 - id) + (id - x2) * (x4 - x3));
        S.insert(id);
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
