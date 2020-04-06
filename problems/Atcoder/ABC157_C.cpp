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
 <url:https://atcoder.jp/contests/abc157/tasks/abc157_c>
 問題文============================================================
 C - Guess The Number
 =================================================================
 解説=============================================================

 M個の条件を矛盾がないかを確かめつつチョックし、その後、100 or 10 or 1に対して
 条件を満たす桁を書き換えたものを出力すればいい。
 ただし、N=1,M=0の場合は答えが0となるので、そこだけ注意

 https://atcoder.jp/contests/abc157/submissions/11575862
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    map<int,int> mp;
    for(int i = 0; i < M;i++){
        int s,c; cin >> s >> c;
        s--;
        if(mp.count(s)){
            if(mp[s] != c) return -1;
        }else{
            mp[s] = c;
        }
    }
    string ans(N,'0');
    if(N != 1) ans[0] = '1';

    for(int i = 0; i < N;i++){
        if(mp.count(i)){
            ans[i] = mp[i] + '0';
        }
    }

    res = atol(ans.c_str());

    if(to_string(res).length() != N) return -1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
