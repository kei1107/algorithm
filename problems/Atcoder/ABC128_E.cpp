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
 <url:https://atcoder.jp/contests/abc128/tasks/abc128_e>
 問題文============================================================
 =================================================================
 解説=============================================================

 各工事により、どの時刻から出発した人が足止めとなるかを考える
 
 時刻Dに出発した人が Si,Ti,Xiで足止めとなるのは

 Si <= D + Xi < Ti
 より、
 si - Xi <= D < Ti - Xi
 を満たす時である。
 このDの範囲は、各工事に対して、事前に求めておくことができる。

 あとは、各Diに対して足止めとなるかどうかをmapなどを用いつつ順番に計算してけばいい
 O((N+Q)logN)
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,Q; cin >> N >> Q;

    using Item = tuple<ll,ll,ll>;
    vector<Item> events(N);
    for(int i = 0; i < N;i++){
        ll S,T,X; cin >> S >> T >> X;
        events[i] = Item(S,T,X);
    }
    sort(events.begin(),events.end());
    vector<ll> D(Q);
    for(auto& in:D) cin >> in;

    map<ll,ll> mp;
    vector<vector<ll>> E(Q+1);
    for(int i = 0; i < N;i++){
        ll S,T,X; tie(S,T,X) = events[i];

        ll LT = S-X, RT = T - X;
        ll LD = lower_bound(D.begin(),D.end(),LT) - D.begin();
        ll RD = lower_bound(D.begin(),D.end(),RT) - D.begin();

        E[LD].push_back(X);
        E[RD].push_back(-X);
    }


    for(int i = 0; i < Q;i++){
        for(auto x:E[i]){
            if(x>=0){
                mp[x]++;
            }else{
                x = -x;
                mp[x]--;

                if(mp[x]==0){
                    mp.erase(x);
                }
            }
        }
        if(mp.empty()){
            cout << -1 << endl;
        }else{
            cout << mp.begin()->first << endl;
        }
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}

