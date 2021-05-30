#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_aj>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,Q; cin >> N >> Q;

    vector<vector<ll>> P(N,vector<ll>(2));
    for(auto& in:P) cin >> in[0] >> in[1];
    vector<vector<pll>> a(4,vector<pll>(N,pll(-LINF,-1)));
    for(int i = 0; i < N;i++){
        for(int s = 0; s < 4; s++){
            ll y = 0;
            for(int j = 0; j < 2;j++){
                if((s>>j)&1){
                    y += P[i][j];
                }else{
                    y -= P[i][j];
                }
            }
            a[s][i] = pll(y,i);
        }
    }
    for(int s = 0; s < 4; s++){
        sort(a[s].rbegin(),a[s].rend());
    }

    while(Q--){
        int q; cin >> q; q--;

        ll ret = numeric_limits<ll>::min();
        ll id = -1;
        for(unsigned s = 0; s < 4; s++){
            unsigned t = ~s & 3;

            ll y = 0;
            for(int j = 0; j < 2; j++){
                if((t>>j)&1){
                    y += P[q][j];
                }else{
                    y -= P[q][j];
                }
            }

            for(int i = 0; i < 2;i++){
                if(a[s][i].second == q) continue;
                if(ret < a[s][i].first + y){
                    ret = a[s][i].first + y;
                    id = a[s][i].second;
                }
            }
        }
        cout << abs(P[q][0] - P[id][0]) + abs(P[q][1] - P[id][1]) << endl;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}