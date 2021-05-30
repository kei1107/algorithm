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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_aq>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int H,W; cin >> H >> W;
    int rs,cs,rt,ct; cin >> rs >> cs >> rt >> ct;
    rs--; cs--; rt--;ct--;

    vector<vector<char>> C(H,vector<char>(W));
    for(auto& vec:C)for(auto& in:vec) cin >> in;

    auto dist = make_v<ll>(H,W,4);
    fill_v(dist,LINF);
    int D[4] = {1,0,-1,0};
    
    using Item = tuple<int,int,int>;
    queue<Item> q;

    for(int k = 0; k < 4;k++){
        dist[rs][cs][k] = 0;
        q.emplace(rs,cs,k);
    }

    while(q.size()){
        auto [rn,cn,dir] = q.front(); q.pop();


        for(int k = 0; k < 4;k++){
            int next_rn = rn + D[k];
            int next_cn = cn + D[k^1];

            if(next_rn < 0 || next_rn >= H || next_cn < 0 || next_cn >= W) continue;
            if(C[next_rn][next_cn] == '#') continue;

            if(dist[next_rn][next_cn][k] > dist[rn][cn][dir] + (k!=dir)){
                dist[next_rn][next_cn][k] = dist[rn][cn][dir] + (k!=dir);
                q.emplace(next_rn,next_cn,k);
            }
        }
    }

    res = *min_element(dist[rt][ct].begin(),dist[rt][ct].end());
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}