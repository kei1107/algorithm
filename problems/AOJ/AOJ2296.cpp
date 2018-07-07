#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2296>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 順番に小問題に分割していけば、問題は簡単になる
 
 まず、巡る町を決めたとき、最短でその町をめぐる時間を求める O(2^N*N*N)
 次に、巡る町が決まっているときの重さ制限Wでの最大の利益を求める　O(2^N*MW)
 最後に、巡る町が決まっているとき時間制限Tでの最大の利益を求める　O(2^N*T)
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N,M,W,T; cin >> N >> M >> W >> T;
    vector<string> S(M);
    vector<ll> V(M),P(M),L(N),X(N),Y(N);
    vector<vector<ll>> R(N),Q(N);
    for(int i = 0; i < M;i++) cin >> S[i] >> V[i] >> P[i];
    map<string,int> S2idx;
    for(int i = 0; i < M;i++) S2idx[S[i]]  = i;
    
    for(int i = 0; i < N;i++){
        cin >> L[i] >> X[i] >> Y[i];
        R[i].resize(L[i]); Q[i].resize(L[i]);
        for(int j = 0; j < L[i]; j++){
            string str; cin >> str >> Q[i][j];
            R[i][j] = S2idx[str];
            Q[i][j] = P[R[i][j]] - Q[i][j];
        }
    }
    
    // 巡る町を決めたとき、最短でその町をめぐる時間を求める
    // O(2^N*N*N)
    vector<vector<ll>> traveling(1<<N,vector<ll>(N,LINF));
    vector<ll> traveling_time(1<<N,LINF);
    for(int i = 0; i < N;i++) traveling[1<<i][i] = abs(X[i]) + abs(Y[i]);
    for(int i = 0; i < (1<<N);i++){
        for(int j = 0; j < N;j++){
            if(traveling[i][j] == LINF) continue;
            for(int k = 0; k < N;k++){
                if((i>>k)&1) continue;
                traveling[i|(1<<k)][k] = min(traveling[i|(1<<k)][k],traveling[i][j]+abs(X[j]-X[k])+abs(Y[j]-Y[k]));
            }
        }
    }
    for(int i = 0; i < (1<<N);i++){
        for(int j = 0; j < N;j++){
            traveling_time[i] = min(traveling_time[i],traveling[i][j]+abs(X[j])+abs(Y[j]));
        }
    }

    // 巡る町が決まっているときの重さ制限Wでの最大の利益を求める
    // O(2^N*MW)
    vector<ll> benefit(1<<N);
    vector<ll> benefit_dp(W+1,0);
    for(int i = 0; i < (1<<N);i++){
        vector<ll> items(M,-LINF);
        for(int j = 0; j < N;j++){
            if(!((i>>j)&1)) continue;
            for(int k = 0; k < L[j]; k++){
                items[R[j][k]] = max(items[R[j][k]],Q[j][k]);
            }
        }
        fill(benefit_dp.begin(),benefit_dp.end(),0);
        for(int j = 0; j < M;j++){
            for(ll k = V[j]; k <= W;k++){
                benefit_dp[k] = max(benefit_dp[k],benefit_dp[k-V[j]]+items[j]);
            }
        }
        benefit[i] = benefit_dp[W];
    }
    
    // 巡る町が決まっているとき時間制限Tでの最大の利益を求める
    // O(2^N*T)
    vector<ll> maxbenefit(T+1,0);
    for(int i = 0; i < (1<<N);i++){
        for(ll t = traveling_time[i]; t <= T; t++){
            maxbenefit[t] = max(maxbenefit[t],maxbenefit[t-traveling_time[i]]+benefit[i]);
        }
    }
    res = maxbenefit[T];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
