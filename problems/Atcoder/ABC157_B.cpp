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
 <url:https://atcoder.jp/contests/abc157/tasks/abc157_b>
 問題文============================================================
 B - Bingo
 =================================================================
 解説=============================================================
 頑張って全通り見る

 https://atcoder.jp/contests/abc157/submissions/11558609
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    auto B = make_v<int>(3,3);

    map<int,pii> mp;
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            int A; cin >> A;
            mp[A] = pii(i,j);
        }
    }
    int N; cin >> N;
    for(int i = 0; i < N;i++){
        int b; cin >> b;
        if(mp.count(b)){
            B[mp[b].first][mp[b].second] = 1;
        }
    }

    // 縦・横
    for(int i = 0; i < 3;i++){
        if(B[0][i] & B[1][i] & B[2][i]) return "Yes";
        if(B[i][0] & B[i][1] & B[i][2]) return "Yes";
    }
    // 斜め
    if(B[0][0] & B[1][1] & B[2][2]) return "Yes";
    if(B[2][0] & B[1][1] & B[0][2]) return "Yes";

    return "No";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}
