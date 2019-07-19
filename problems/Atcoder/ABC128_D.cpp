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
 <url:https://atcoder.jp/contests/abc128/tasks/abc128_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 Nが小さいので色々とできる。

 操作に関して、

 操作A,Bを行なっている最中に操作C,Dを行う必要性は全くない

 よって (操作 A or Bを何回か) -> (操作 C or Dを何回か)行うものとして考えていい。

 ここで、筒のどこまでを取り出すのかを決め打ちする
 [0,l) と (r,N-1] の区間を全部取る
 とした時、取ってから負の価値が大きいものから筒に入れなおしていけばいい（K回の操作制限に気をつける）
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,K; cin >> N >> K;
    vector<ll> V(N); for(auto& in:V) cin >> in;

    for(int l = 0; l < N; l++){
        for(int r = l-1; r < N; r++){
            // [0,l) と (r,N-1] の区間を全部取る
            // 取ってから宝石を再度筒に詰めるか決める

            ll lcnt = l;
            ll rcnt = N-1-r;

            if(lcnt + rcnt > K) continue;
            ll T = 0;
            vector<ll> minus;
            for(int ll = 0; ll < l;ll++){
                T += V[ll];
                if(V[ll] < 0) minus.push_back(V[ll]);
            }
            for(int rr = r+1; rr < N; rr++){
                T += V[rr];
                if(V[rr] < 0) minus.push_back(V[rr]);
            }
            sort(minus.begin(),minus.end());
            for(int i = 0; i < (int)minus.size(); i++){
                if(minus[i] >= 0) break;
                if(lcnt + rcnt + i+1 > K) break;
                T -= minus[i];
            }

            res = max(res,T);
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
