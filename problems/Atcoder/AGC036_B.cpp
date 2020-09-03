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
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

set<int> st[200005];
template<class Type>
Type solve(Type res = Type()){
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    for(auto& in:A) cin >> in;
    for(int i = 0; i < N;i++){
        st[A[i]].emplace(i);
    }

    ll now = 0;
    ll cnt = 1;
    while(true){
        ll val = A[now];

        auto next_it = st[val].upper_bound(now);

        if(next_it == st[val].end()){
            next_it = st[val].begin();
            cnt++;
        }
        now = (*next_it + 1)%N;
        if(now == 0) break;
    }
    K %= cnt;

    now = 0;
    cnt = 0;
    while(cnt < K-1){
        ll val = A[now];
        auto next_it = st[val].upper_bound(now);
        if(next_it == st[val].end()){
            next_it = st[val].begin();
            cnt++;
        }
        now = (*next_it + 1)%N;
    }

    while(now < N){
        ll val = A[now];
        auto next_it = st[val].upper_bound(now);
        if(next_it == st[val].end()){
            res.emplace_back(val);
            now++;
        }else{
            now = (*next_it + 1);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<vector<ll>>() << endl;
    return 0;
}