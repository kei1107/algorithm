#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_ba>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

vector<int> fibo_vs = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597};

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;

    auto memo = make_v<int>(N);
    fill_v(memo,-INF);

    int cnt = 0;
    auto ask = [&](int v){
        if(v < 0 || v >= N) return -INF;
        if(memo[v] != -INF) return memo[v];
        cnt++;
        assert(v+1 >= 1 && v+1 <= N);
        cout << "? " << v+1 << endl;
        cin >> memo[v];
        assert(memo[v] >= 0);
        return memo[v];
    };

    if(N < 10){
        int max_v = -1;
        for(int i = 0; i < N;i++){
            max_v = max(max_v,ask(i));
        }
        cout << "! " << max_v << endl;
        return res;
    }

    auto it = lower_bound(fibo_vs.begin(),fibo_vs.end(),N+1) - fibo_vs.begin();
    int l = -1, r = fibo_vs[it] - 1;
    int m0 = l + fibo_vs[it-2];
    int m1 = l + fibo_vs[it-1];

    while(r-l > 3){
        assert(cnt <= 15);
        //cout << l << " " << r << endl;
        if(ask(m0) < ask(m1)){
            int tm0 = m0;
            int tm1 = m1;
            int tr = r;

            l = tm0;
            m0 = tm1;
            m1 = tr - tm1 + tm0;
        }else{
            int tm0 = m0;
            int tm1 = m1;
            int tl = l;

            r = tm1;
            m1 = tm0;
            m0 = tl + tm1 - tm0;
        }
    }

    assert(cnt <= 15);
    int max_v =  max({ask(l+1),ask(r-1)});
    cout << "! " << max_v << endl;
    // cerr << cnt << endl;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}