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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_by>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

ll V;
vector<vector<ll>> G;
vector<ll> match;
vector<int> used;

void add_edge(ll u, ll v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(ll v) {
	used[v] = 1;
	for (int i = 0; i < G[v].size(); i++) {
		ll u = G[v][i], w = match[u];
		if (w < 0 || ((used[w] == 0) && dfs(w))) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

ll bipartite_matching() {
	ll res = 0;
	for (int i = 0; i < (int)match.size();i++)match[i] = -1;
	for (int v = 0;v < V;v++) {
		if (match[v] < 0) {
			for (int i = 0; i < (int)used.size();i++)used[i] = 0;
			if (dfs(v))res++;
		}
	}
	return res;
}

template<class Type>
Type solve(Type res = Type()){
    int N, T; cin >> N >> T;
    vector<int> AX(N),AY(N),BX(N),BY(N);
    map<pii,int> mp;
    for(int i = 0; i < N; i++){
        cin >> AX[i] >> AY[i];
        mp[make_pair(AX[i],AY[i])] = i;
    }

    V = 2*N;
    G.resize(V); used.resize(V); match.resize(V);

    int dx[8] = {1,1,0,-1,-1,-1,0,1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};

    for(int i = 0; i < N; i++){
        cin >> BX[i] >> BY[i];
        for(int k = 0; k < 8;k++){
            int TX = BX[i] + T*dx[k];
            int TY = BY[i] + T*dy[k];

            if(mp.count(make_pair(TX,TY))){
                add_edge(mp[make_pair(TX,TY)],N+i);
            }
        }
    }

    auto matching = bipartite_matching();
    cerr << matching << endl;
    if(matching != N){
        cout << "No" << endl;
        return res;    
    }

    cout << "Yes" << endl;
    // cerr << match << endl;
    for(int i = 0; i < N; i++){
        int b_id = match[i] - N;

        for(int k = 0; k < 8; k++){
            int TX = AX[i] + T*dx[k];
            int TY = AY[i] + T*dy[k];

            if(BX[b_id] == TX && BY[b_id] == TY){
                cout << k + 1 << " ";
                break;
            }
        }
    } cout << endl;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}