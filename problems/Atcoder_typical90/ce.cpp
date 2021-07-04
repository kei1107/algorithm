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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_ce>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a,b; cin >> a >> b;
        a--; b--;

        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    int Q; cin >> Q;
    vector<int> x(Q),y(Q);
    for(int i = 0; i < Q;i++){
        cin >> x[i] >> y[i];
        x[i]--;
    }
    size_t B = size_t(sqrt(2*M));

    vector<int> L_id;
    for(int i = 0; i < N; i++){
        if(G[i].size() >= B) L_id.emplace_back(i);
    }

    auto connect = make_v<int>(N,L_id.size());
    for(auto i = 0u; i < L_id.size(); i++){
        connect[L_id[i]][i] = true;
        for(auto j: G[L_id[i]]){
            connect[j][i] = true;
        }
    }

    vector<int> update(N,-1),update_L(L_id.size(),-1);

    for(int i = 0; i < Q; i++){
        int last = update[x[i]];
        for(auto j = 0u; j < L_id.size(); j++){
            if(connect[x[i]][j]){
                last = max(last,update_L[j]);
            }
        }

        cout << (last != -1? y[last] : 1) << endl;

        if(G[x[i]].size() < B){
            update[x[i]] = i;
            for(auto j : G[x[i]]){
                update[j] = i;
            }
        }else{
            auto id = distance(L_id.begin(),find(L_id.begin(),L_id.end(), x[i]));
            update_L[id] = i;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}