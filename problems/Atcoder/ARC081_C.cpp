#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc081.contest.atcoder.jp/tasks/arc081_a>
問題文============================================================
 太さが無視できる棒が N 本あります． i 番目の棒の長さは Ai です．
 
 すぬけ君は，これらの棒から 4 本の異なる棒を選び，それらの棒を辺として長方形（正方形を含む）を作りたいです．
 作ることができる最大の長方形の面積を求めてください．
 
=================================================================

解説=============================================================

 最適な選び方は　2本以上ある長さの大きい棒から選んでいけば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    map<ll,ll> mp;
    for(int i = 0; i < N;i++){
        ll A; cin >> A; mp[A]++;
    }
    vector<pll> ps(mp.begin(),mp.end());
    sort(ps.begin(),ps.end());
    reverse(ps.begin(),ps.end());
    
    ll h = 0,w = 0;
    for(int i = 0; i < (int)ps.size();i++){
        if(ps[i].second >= 4){
            if(h == 0) h = w = ps[i].first;
            else w = ps[i].first;
            break;
        }else if(ps[i].second >= 2){
            if(h == 0){
                h = ps[i].first;
                continue;
            }
            if(w == 0){
                w = ps[i].first;
                break;
            }
        }
    }
    cout << h * w << endl;
	return 0;
}
