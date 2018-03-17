#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc080.contest.atcoder.jp/tasks/abc080_d>
問題文============================================================
 joisinoお姉ちゃんは、録画機を用いて N 個のテレビ番組を録画しようとしています。
 
 テレビが受信できるチャンネルは C 個あり、1 から C までの番号がついています。
 
 joisinoお姉ちゃんの録画したいテレビ番組のうち、i 個目のテレビ番組は、
 時刻 si から時刻 ti まで、チャンネル ci で放送されます。(ただし時刻 si を含み、時刻 ti を除く)
 
 ただし、同じチャンネルで複数のテレビ番組が同時に放送されることはありません。
 
 また、録画機は、あるチャンネルの時刻 S から時刻 T までを録画するとき、
 時刻 S−0.5 から時刻 T までの間、他のチャンネルの録画に使うことができません。
 (ただし時刻 S−0.5を含み、時刻 T を除く)
 
 N 個のテレビ番組の全ての放送内容が含まれるように録画するとき、必要な録画機の最小個数を求めてください。
=================================================================

解説=============================================================

 最適な選び方は、録画しなければならない時間が最も近く、終了時間が最も近いものから選んでいく
 選び方である。
 
 priority_queueなどで実現できるが、制約が小さいので、貪欲でも大丈夫
================================================================
*/
ll N,C;
vector<pair<pll,ll>> M;
vector<int> comp;
bool check(ll maxc){
    fill(comp.begin(),comp.end(),0);
    ll pret,prec;
    for(int i = 0; i < maxc;i++){
        pret = -1; prec = -1;
        for(int i = 0; i < N;i++){
            if(comp[i] == 1) continue;
            if(pret < M[i].first.first){
                comp[i] = 1;
                pret = M[i].first.second;
                prec = M[i].second;
            }else if(pret == M[i].first.first){
                if(prec == M[i].second){
                    comp[i] = 1;
                    pret = M[i].first.second;
                    prec = M[i].second;
                    continue;
                }
            }
        }
    }
    for(auto f:comp){
        if(f == 0) return false;
    }
    return true;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> C;
    comp.resize(N);
    M.resize(N);
    for(int i = 0; i < N;i++) cin >> M[i].first.first >> M[i].first.second >> M[i].second;
    sort(M.begin(),M.end());
    
    for(int i = 1; i <= C;i++){
        if(check(i)){
            cout << i << endl;
            break;
        }
    }
	return 0;
}
