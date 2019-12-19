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
 <url:https://atcoder.jp/contests/abc144/tasks/abc144_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 チーム全体の成績について 二分探索でとく

 まず前提として、初期の状態からチーム成績を最小にするには
 一番消化コストの低い人が一番食べにくいも食べ物を
 二番目の人は二番目に食べにくいものを...
 と行ったふう選択して行けばいい

 ここで、消化コストを減らすことができると考えた時
 チームの成績をmにしたいとすれば

 消化コストが昇順・食べにくさが降順に並んでいる列を順番に見た時
 i番目の人は消化コストをm/F[i]まで減らさなければならない

 よって、成績を決め打ちしたときに必要な修行回数が一意に決定することができるため、
 O(N logN)で二分探索によって解ける。

 提出：https://atcoder.jp/contests/abc144/submissions/8670034
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,K; cin >> N >> K;
    vector<ll> A(N),F(N);

    for(auto& in:A) cin >> in;
    for(auto& in:F) cin >> in;

    sort(A.begin(),A.end());
    sort(F.rbegin(),F.rend());

    //　二分探索
    auto ok = [&](ll m){
        ll leftK = K;
        for(int i = 0; i < N;i++){
            ll Lower = m/F[i];
            leftK -= max(0LL,A[i]-Lower);
            if(leftK < 0) break;
        }
        return leftK >= 0;
    };


    ll l = -1, r = LINF;
    while((r-l)>1){
        ll m = (l+r)/2;
        if(ok(m)) r = m;
        else l = m;
    }
    res = r;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
