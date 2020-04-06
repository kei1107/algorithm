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
 <url:https://atcoder.jp/contests/abc157/tasks/abc157_e>
 問題文============================================================
 E - Simple String Queries
 =================================================================
 解説=============================================================

 制約の大きさから各クエリに対して愚直に文字列の更新や文字列の種類を数え上げても間に合わない。
 ここで、type2のクエリの際に数えるべき文字の種類が高々26種類(アルファベットの種類)しかないことに注目する。
 すなわち、各アルファベットに対して、そのアルファベットが文字列S中のl文字目からr文字目の間に少なくとも1つ存在するか判定できればよい。
 これは、各アルファベットが存在する位置をsetなどで管理する事で高速に判定可能となる。

 よって、type1ではsetの更新処理・type2では各アルファベットに対して上記の判定処理を行えば解ける

 https://atcoder.jp/contests/abc157/submissions/11594336
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    string S; cin >> S;
    vector<set<int>> alpha(26);
    for(int i = 0; i < N;i++){
        int c = S[i] - 'a';
        alpha[c].insert(i);
    }
    int Q; cin >> Q;
    while(Q--){
        int com; cin >> com;
        if(com == 1){
            int i; char c; cin >> i >> c;
            i--;

            int ic = c - 'a';
            int jc = S[i] - 'a';

            alpha[jc].erase(i);
            alpha[ic].insert(i);
            S[i] = c;
        }else{
            int l,r; cin >> l >> r;
            l--; r--;
            int num = 0;
            for(int c = 0; c < 26; c++){
                auto it = alpha[c].lower_bound(l);
                if(it == alpha[c].end()) continue;
                if(l <= *it && *it <= r) num++;
            }
            cout << num << endl;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
