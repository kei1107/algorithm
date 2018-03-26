#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1LL<<55; // !!
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }


/*
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day1/problems/D>
問題文============================================================
 AORイカちゃんは縦 1 横 N の大きさの水槽をもらった。水槽は水を入れるのに十分な高さがある。
 水槽には N−1 個の仕切りがあり N 個の区画に等間隔に区切られている。
 ここに水を注いだところ、各区画の水の高さは ai になった。
 
 AORイカちゃんはいくつか仕切りを取り除き、区画の数を M 個以下にすることにした。
 仕切りを取り除き終わった時、各区画の水の高さの総和の最大値を求めよ。
 
 なお、仕切りの厚さは無視できるものとする。
=================================================================

解説=============================================================

 mem[i][j] := [0,i]で区間の個数がj個の時
 としてメモ化再帰
 計算都合上 LINFが小さすぎても大きすぎてもいけない
================================================================
*/

#define MAX_N 550
ll N,M;
double a[MAX_N],cusum[MAX_N];
double mem[MAX_N][MAX_N]; // mem[i][j] := [0,i]で区間の個数がj個の時
bool checked[MAX_N][MAX_N];

double rec(int p,int cnt){
    if(p == N) return cnt == M ? 0:-LINF;
    if(checked[p][cnt]) return mem[p][cnt];
    checked[p][cnt] = true;
    
    double res = -LINF;
    for(int i = p; i < N;i++){
        double t = (cusum[i+1]-cusum[p])/(i+1-p);
        res = max(res,t+rec(i+1,cnt+1));
    }
    
    return mem[p][cnt] = res;
}
double solve(){
    cin >> N >> M;
    for(int i = 0; i < N;i++) cin >> a[i];
    for(int i = 0; i < N;i++){ cusum[i+1] = cusum[i] + a[i]; }
    return rec(0,0);
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(10) << solve() << endl;
	return 0;
}
