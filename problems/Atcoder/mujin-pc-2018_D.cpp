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
 <url:https://beta.atcoder.jp/contests/mujin-pc-2018/tasks/mujin_pc_2018_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 メモ化再帰したらマニアった
 ================================================================
 */



int rev(int x){
    if(x < 10)return x;
    if(x < 100)return 10*(x%10)+x/10;
    return 100*(x%10)+(x-(x/100)*100-x%10)+x/100;
}

int state[1000][1000];
int rec(int x,int y,int dep){
    if(state[x][y]) return state[x][y];
    if(x == 0 || y == 0) return 2;
    if(dep == 100000) return 1;

    if(x < y) x = rev(x);
    else y = rev(y);
    if(x < y) y = y-x;
    else x = x-y;
    
    
    return state[x][y] = rec(x,y,dep+1);
}

ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;

    for(int i = 1; i<= N;i++){
        for(int j = 1; j <= M;j++){
            if(rec(i,j,0) == 1) res++;
        }
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
