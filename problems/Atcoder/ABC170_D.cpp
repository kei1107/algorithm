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
 <url:https://atcoder.jp/contests/abc170/tasks/abc170_d>
 問題文============================================================
 D - Not Divisible
 =================================================================
 解説=============================================================

 Aiを昇順に並べ替える。

 Aiを順番に見て行ったとき、Aiが未チェックかつ同じ値が複数なければ答えに1加算する
 また、未チェックのAiに対して1...1000'000のAiの倍数をすべてチェック済とする。
 これは、エラトステネスの篩と同じ処理でできるので間に合う

 https://atcoder.jp/contests/abc170/submissions/14407376
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<int> A(N); for(auto& in:A) cin >> in;
    sort(A.begin(),A.end());

    int MAX_N = 1000'000;
    vector<bool> used(MAX_N+1);
    map<int,int> mp;
    for(auto a:A) mp[a]++;
    for(int i = 0; i < N;i++){
        if(used[A[i]]) continue;
        if(mp[A[i]] == 1) res++;
        for(int j = 1; j*A[i] <= MAX_N;j++){
            used[A[i]*j] = true;
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
