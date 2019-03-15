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
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://atcoder.jp/contests/code-thanks-festival-2018-open/tasks/code_thanks_festival_2018_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 貪欲法　解説AC
 
 値の小さい頂点から順に確かめていく
 
 >> https://img.atcoder.jp/code-thanks-festival-2018/editorial.pdf
 ================================================================
 */

#define MAXN 300
vector<vector<int>> G(MAXN);
vector<int> p(MAXN);
vector<int> used(MAXN);
vector<int> dep(MAXN);
vector<int> visit;
int root = -1;
int N,M,K;

void dfs(int n,int target,int d){
    dep[n] = d;
    if(n == target || used[n]) return;
    visit.push_back(d);
    for(auto next:G[n]) dfs(next,target,d+1);
}
bool check(int i,int j){
    fill(dep.begin(),dep.begin()+N,0);
    visit.clear();
    dfs(root,j,1);
    if(dep[j] == 0) return false;
    if(visit.size() < M-i-1) return false;
    if(i==M-1){
        return (dep[j]==K);
    }else{
        sort(visit.begin(),visit.end());
        int u = 0,v = 0;
        for(int k = 0; k < M-i-1;k++){
            u += visit[k];
            v += visit[visit.size()-1-k];
        }
        return (u <= K-dep[j] && K-dep[j] <= v);
    }
}

template<class Type>
Type solve(Type res = Type()){
    cin >> N >> M >> K;
    
    // make graph
    for(int i = 0; i < N;i++){
        cin >> p[i]; p[i]--;
        if(p[i] != -1) G[p[i]].push_back(i);
        else root = i;
    }
    
    for(int i = 0; i < M;i++){
        bool update = false;
        for(int j = 0; j < N;j++){
            if(used[j]) continue;
            if(check(i,j)){
                res.push_back(j+1);
                used[j] = true;
                K-=dep[j];
                update = true;
                break;
            }
        }
        if(!update){
            res = Type{-1};
            return res;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<vector<ll>>() << endl;
    return 0;
}
