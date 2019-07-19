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
 <url:https://atcoder.jp/contests/abc129/tasks/abc129_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 愚直に全てのマスに対して、シミュレートするとO(HW*max(H,W))となってTLEする。
 よって、事前に
 
 Left -> Rigntへの光線で各マスがどれだけのマスを照らせれるのか
 Right -> Leftへの "
 Up-> Downへの "
 Down -> Upへの "
 を全て試して、総和の値が最も大きいものが答え
 （各光線で特定のマスが重複して数えられることはないため）
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int H,W; cin >> H >> W;
    vector<string> S(H); for(auto& in:S) cin >> in;
    vector<vector<ll>> M(H,vector<ll>(W));
    
    // Left -> Right
    for(int i = 0; i < H;i++){
        ll v = 0;
        for(int j = 0; j < W;j++){
            if(S[i][j] == '#'){
                v = 0;
                continue;
            }else{
                M[i][j] += v;
                v++;
            }
        }
    }
    
    // Right -> Left
    for(int i = 0; i < H;i++){
        ll v = 0;
        for(int j = W-1; j >= 0;j--){
            if(S[i][j] == '#'){
                v = 0;
                continue;
            }else{
                M[i][j] += v;
                v++;
            }
        }
    }
    
    // Up -> Down
    for(int j = 0; j < W;j++){
        ll v = 0;
        for(int i = 0; i < H;i++){
            if(S[i][j] == '#'){
                v = 0;
                continue;
            }else{
                M[i][j] += v;
                v++;
            }
        }
    }
    
    // Down -> Up
    for(int j = 0; j < W;j++){
        ll v = 0;
        for(int i = H-1; i >= 0;i--){
            if(S[i][j] == '#'){
                v = 0;
                continue;
            }else{
                M[i][j] += v;
                v++;
            }
        }
    }
    
    for(auto vec:M) for(auto& v:vec) res = max(res,v+1);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
