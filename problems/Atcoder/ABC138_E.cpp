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
 <url:https://atcoder.jp/contests/abc138/tasks/abc138_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 i番目から文字cまでに最短何文字で到達できるかを前処理で計算しておいて
 tの文字に対して計算した値を加算していく
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    string s,t; cin >> s >> t;
    
    map<char,bool> mp;
    for(auto c:s) mp[c] = true;
    for(auto c:t){
        if(mp.count(c)) continue;
        return -1;
    }

    int slen = (int)s.length();
    vector<vector<int>> vs(slen+1,vector<int>(26,-INF));
    for(int i = slen-1; i >= 0; i--){
        for(int j = 0; j < 26;j++){
            vs[i][j] = vs[i+1][j] + 1;
        }
        vs[i][s[i]-'a'] = 1;
    }
    // cout << vs << endl;


//    for(int j = 0; j < 26;j++){
//        cout << (char)(j+'a') << " : ";
//        for(int i = 0; i <= slen;i++){
//            if(vs[i][j] <= 0) cout << "INF ";
//            else cout <<  vs[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
    res = 0;
    int now = 0;
    int idx = 0;
    while(idx < t.length()){
//        cout << idx << endl;
//        cout << now << " " << res << endl;
        char c = t[idx];
        c -= 'a';
        if(vs[now][c] <= 0){
            res += s.length() - now;
            now = 0;
            continue;
        }else{
            res += vs[now][c];
            now += vs[now][c];
            idx++;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
