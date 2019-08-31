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
 <url:https://codeforces.com/contest/1203/problem/E>
 問題文============================================================
 =================================================================
 解説=============================================================
 事前に体重に関してソートしていく。
 
 昇順に並んだ値を順番に見て行ったとき、以降の重複の関係から
 優先順位は -1 > 0 > +1 の体重変化となる
 
 よって、使用ずみの体重に関してmap等で管理しつつ貪欲に値を見ていけばいい
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<int> a(n); for(auto& in:a) cin >> in;
    sort(a.begin(),a.end());
    map<int,bool> mp;
    
    for(int i = 0; i < n;i++){
        for(int j = max(1,a[i]-1); j <= a[i]+1; j++){
            if(mp.count(j)) continue;
            
            mp[j] = true;
            break;
        }
    }
    res = mp.size();
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
