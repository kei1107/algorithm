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
 <url:https://codeforces.com/contest/1203/problem/D2>
 問題文============================================================
 =================================================================
 解説=============================================================
 左からi文字みたときの一致度、右からi文字みたときの一致度をあらかじめ求めておく
 
 その後二分探索で最大の長さを求める
 これは各i文字目に対して事前に作成した
 「左からi文字みたときの一致度、右からi文字みたときの一致度」を用いることでO(|s|)で判定できる
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    string s,t; cin >> s >> t;
    
    int slen = (int)s.length();
    int tlen = (int)t.length();
    
    // 左からi文字みたときの一致度、右からi文字みたときの一致度
    vector<int> L(slen+1),R(slen+1);
    
    for(int i = 1; i <= slen;i++){
        if(L[i-1] == tlen){
            L[i] = L[i-1];
        }else{
            L[i] = L[i-1] + (t[L[i-1]] == s[i-1]);
        }
        if(R[i-1] == tlen){
            R[i] = R[i-1];
        }else{
            R[i] = R[i-1] + (t[tlen-1-R[i-1]] == s[slen-1-(i-1)]);
        }
    }
    //    cout << L << endl;
    //    cout << R << endl;
    
    auto ok = [&](int m){
        bool ret = false;
        
        for(int i = 0; i+m<=slen;i++){
            if(L[i] + R[slen-(i+m)] >= tlen) ret = true;
        }
        return ret;
    };
    
    int l = 0, r = INF;
    while(r-l>1){
        int m = (l+r)/2;
        if(ok(m)){
            l = m;
        }else{
            r = m;
        }
    }
    res = l;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
