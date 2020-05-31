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
 <url:https://atcoder.jp/contests/abc167/tasks/abc167_f>
 問題文============================================================
 F - Bracket Sequencing
 =================================================================
 解説=============================================================

 https://atcoder.jp/contests/abc167/submissions/13148135
 
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<string> S(N); for(auto& in:S) cin >> in;
    
    vector<pll> info(N,pll(LINF,0));
    for(int i = 0; i < N;i++){
        ll now_cost = 0;
        for(auto c:S[i]){
            if(c == '(') now_cost += 1;
            else now_cost -= 1;
            info[i].first = min(info[i].first,now_cost);
        }
        info[i].second = now_cost;
    }
    
    vector<pll> plus,minus;
    for(int i = 0; i < N;i++){
        if(info[i].second >= 0) plus.emplace_back(info[i]);
        else minus.emplace_back(info[i].first-info[i].second,-info[i].second);
    }
    
    sort(plus.begin(),plus.end(),[](const pll& l,const pll& r){
        return l.first > r.first;
    });
    ll x = 0;
    for(auto p:plus){
        if(x + p.first < 0) return "No";
        x += p.second;
    }
    sort(minus.begin(),minus.end(),[](const pll& l,const pll& r){
        return l.first > r.first;
    });

    ll y = 0;
    for(auto p:minus){
        if(y + p.first < 0) return "No";
        y += p.second;
    }
    if(x == y) return "Yes";
    else return "No";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}
