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
 <url:https://atcoder.jp/contests/abc158/tasks/abc158_d>
 問題文============================================================
 D - String Formation
 =================================================================
 解説=============================================================

 そのまま文字列の反転や前後に文字を挿入するとTLEする。
 ここで、文字列の反転したクエリは文字列自体を反転させる必要がなく、
 文字の挿入する場所(先端・末尾)を入れ替えることで対処可能である。
 その為、配列の前後に文字をO(1)で追加できるデータ構造(deque)を用いてこの処理を行なっていけばいい。
 最後に文字列の状態が反転になっている場合に注意して文字列として復元すればいい。

 https://atcoder.jp/contests/abc158/submissions/11618368
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    string S; cin >> S;

    deque<char> Sq;
    for(auto c:S) Sq.push_back(c);
    bool turn = false;

    int Q; cin >> Q;
    while(Q--){
        int T; cin >> T;
        if(T == 1){
            turn = !turn;
        }else{
            int F; char c; cin >> F >> c;
            F--;
            if(turn) F = !F;

            if(F){
                Sq.push_back(c);
            }else{
                Sq.push_front(c);
            }
        }
    }
    if(turn) reverse(Sq.begin(),Sq.end());
    res = string(Sq.begin(),Sq.end());
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}
