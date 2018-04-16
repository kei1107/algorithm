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
 <url:https://tenka1-2016-qualb.contest.atcoder.jp/tasks/tenka1_2016_qualB_c>
 問題文============================================================
 天下一プログラマーコンテスト1999本戦では N 人の参加者が総当り戦を行い、
 総当り戦の結果と予選の順位によって本戦の順位を付けました。
 
 本戦では、総当り戦で勝った数によって順位を付け、総当り戦で勝った数が同じ場合は、
 予選の順位が高いほうが上位になるものとしました。
 
 予選順位が同じ参加者はいないものとします。
 
 アンドウくんとハシモトくんは総当り戦の対戦記録を付けていて、各対戦について、
 それぞれが「XさんがYさんに勝った」と「YさんがXさんに負けた」という 2 つの記録を付けます。
 
 アンドウくんは記録を間違えることはありません。
 
 アンドウくんが「予選順位 i 位の人が予選順位 j 位の人に勝った」と記録している場合
 Ai,j=1 であり、そうでない場合 Ai,j=0 です。
 
 しかし、ハシモトくんがある 1 つの記録を正しく付けることができる確率は P=p⁄q であり、
 確率 1−P で勝敗を間違えてしまいます。
 
 各記録は独立事象であるものとします。
 
 例えば、ある対戦について、確率 (1−P)2 で勝敗を逆に記録してしまったり、
 確率 P(1−P) で両方勝ったと記録してしまったりします。
 
 対戦記録からXさんが総当り戦で勝った数を求めるときは
 「Xさんが誰かに勝った」という記録がいくつあるかで定めるものとします。
 
 アンドウくんが付けた対戦記録から求められる順位とハシモトくんが付けた対戦記録から
 求められる順位が一致する確率を求めてください。
 
 =================================================================
 解説=============================================================
 
 解説みた < https://tenka1-2016-qualb.contest.atcoder.jp/tasks/tenka1_2016_qualB_c>
 
 まぢ無理
 ================================================================
 */

typedef long double ld;
ld solve(){
    ld res = 0;
    int N; cin >> N; double p,q; char c; cin >> p >> c >> q;
    ld P = p/q;
    vector<vector<int>> A(N,vector<int>(N,0));
    for(auto& a:A) for(auto& in:a) cin >> in;
    vector<pii> rank(N);
    vector<int> win(N);
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++) win[i] += A[i][j];
        rank[i] = {-win[i],i};
    }
    sort(rank.begin(),rank.end());
    reverse(rank.begin(),rank.end());
    
    vector<ld> from(N+1),to(N+1);
    vector<vector<ld>> dp(N+1,vector<ld>(N+1,0.0)),dpwin(N+1,vector<ld>(N+1,0.0));
    for(int i = 0; i < N; i++){
        fill(from.begin(),from.end(),0.0);
        from[0] = 1;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            fill(to.begin(),to.end(),0.0);
            for(int k = 0; k < N;k++){
                if(from[k]){
                    if(A[i][j] == 1) {to[k+1]+=from[k]*P; to[k]+=from[k]*(1-P);}
                    if(A[i][j] == 0) {to[k+1]+=from[k]*(1-P); to[k]+=from[k]*P;}
                }
            }
            swap(from,to);
        }
        for(int j = 0; j < N; j++){
            dp[i][j]=from[j];
        }
    }
    for(int i = 0; i < N;i++) dpwin[rank.front().second][i]=dp[rank.front().second][i];
    for(int i = 0; i < N-1;i++){
        int pre = rank[i].second;
        int cur = rank[i+1].second;
        
        for(int j = 0; j < N;j++){
            for(int k = 0; k < N;k++){
                if(j>k)continue;
                if(j==k && cur>pre) continue;
                dpwin[cur][k] += dpwin[pre][j]*dp[cur][k];
            }
        }
    }
    for(int i = 0; i <= N; i++) res += dpwin[rank.back().second][i];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) <<  solve() << endl;
    return 0;
}
