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
 <url:https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

void answer(list<ll> L,vector<pll> Q){
    ll l = L.front(); L.pop_front();
    ll r = L.back(); L.pop_back();

    Q.push_back({r,l});
    L.push_back(r-l);


    cout << L.front()  << endl;
    for(auto p:Q){
        cout << p.first << " " <<p.second << endl;
    }
}
template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    sort(A.begin(),A.end());

    ll Neg = 0;
    for(int i = 0; i < N;i++) if(A[i] < 0) Neg++;

    vector<pll> Q;
    list<ll> L(A.begin(),A.end());
    if(N==2){
        answer(L, Q);
        return 0;
    }
    if(Neg == 0){
        ll l = L.front(); L.pop_front();
        ll r = L.back(); L.pop_back();
        Q.push_back({l,r});
        L.push_front(l-r);
        Neg++;
        N--;
    }
    while(N>2 && Neg >= 2){
        ll l = L.front(); L.pop_front();
        ll r = L.back(); L.pop_back();
        Q.push_back({r,l});
        L.push_back(r-l);
        Neg--;
        N--;
    }
    if(N==2){
        answer(L,Q);
        return 0;
    }
    while(N > 2){
        ll l = L.front(); L.pop_front();
        ll r = L.back(); L.pop_back();
        Q.push_back({l,r});
        L.push_front(l-r);
        N--;
    }
    answer(L, Q);

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
