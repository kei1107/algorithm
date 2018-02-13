#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
 <url:https://www.ioi-jp.org/joi/2008/2009-ho-prob_and_sol/2009-ho.pdf>
 問題文============================================================
 あなたは J 君と一緒にあみだくじを使って遊んでいる．
 あみだくじは n 本の縦棒とm 本の横棒からなる．
 縦棒には左から順に 1 から n の番号がついており，縦棒 i の下端には正整数 si が書かれている．
 
 縦棒 i の一番上から順に道をたどっていき到達した下端に書かれている整数が，
 縦棒 i を選んだ場合の得点である．
 
 J 君は縦棒 1 から縦棒 k までの連続した k 本を選ぶことにした．
 それら k 本の縦棒を選んだときの点数の合計が J 君の得点となる．
 ただし，あなたはあみだくじ内の横棒を一本選び，その横棒をあみだくじから削除することができる．
 （削除しなくてもよい．）
 もし，あなたが横棒を一本削除した場合は，削除後のあみだくじにおいて，
 縦棒 1 から縦棒 k までの連続した k 本の縦棒を選んだときの点数の合計が J 君の得点となる．
 入力としてあみだくじの形と J 君の選ぶ縦棒の本数 k が与えられたとき，
 J 君の得点の最小値を求めるプログラムを作成せよ．
 =================================================================
 解説=============================================================
 
 単純に棒を削除して辿って行くのではO(mk)で間に合わない
 
 しかし、一つの棒に、その棒が無い場合、上に行った時の番号と下に行った時の番号を保持しておけば
 O(m)で解ける
 
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int n,m,h,k; cin >> n >> m >> h >> k;
    vector<int> ue(n),sita(n);
    vector<pii> bou(m);
    for(int i = 0; i < n;i++){ ue[i] = i; cin >> sita[i]; }
    for(auto &in:bou){ cin >> in.second >> in.first; in.second--; }
    sort(bou.begin(),bou.end());
    
    vector<pii> ue_num(m),sita_num(m);
    for(int i = 0; i < m;i++){
        ue_num[i].first = ue[bou[i].second]; ue_num[i].second = ue[bou[i].second+1];
        swap(ue[bou[i].second],ue[bou[i].second+1]);
        int j = m-i-1;
        sita_num[j].first = sita[bou[j].second]; sita_num[j].second = sita[bou[j].second+1];
        swap(sita[bou[j].second],sita[bou[j].second+1]);
    }
    int sum = accumulate(sita.begin(), sita.begin()+k,0);
    int ans = sum;
    for(int i = 0; i < m;i++){
        if(ue_num[i].first < k && ue_num[i].second >= k){
            ans = min(sum-(sita_num[i].second-sita_num[i].first),ans);
        }
    }
    cout << ans << endl;
    return 0;
}
