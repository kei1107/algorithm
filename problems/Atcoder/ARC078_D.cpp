#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://arc078.contest.atcoder.jp/tasks/arc078_b>
 問題文============================================================
 フェネックとすぬけくんがボードゲームで遊んでいます。
 
 このボードゲームには 1 番から N 番までの番号がついた N 個のマスと、
 マスどうしをつなぐ N−1 本の道が存在しています。
 ai 番のマスと bi 番のマスは i 番目の道を介して隣り合っています。
 どの 2 つのマスも隣接するマスをいくつか辿って必ず辿り着くことが可能です。
 すなわち、グラフ理論の言葉を用いると、マスと道から構成されるグラフは木です。
 
 はじめに 1 番のマスは黒く、N 番のマスは白く塗られています。
 その他のマスはまだ色が塗られていません。
 先手のフェネックと後手のすぬけくんは残りのマスに交互に色を塗ります。
 自分の手番において、2 人はそれぞれ以下のような行動を行います。
 
 フェネック：黒く 塗られたマスに隣接したマスであって、色が塗られていないマスを 1 つ選んで 黒く 塗る。
 すぬけくん：白く 塗られたマスに隣接したマスであって、色が塗られていないマスを 1 つ選んで 白く 塗る。
 
 手番のプレイヤーがマスに色を塗ることができなかったとき、敗者となります。
 フェネックとすぬけくんが最適に行動したとき勝者はどちらか判定してください。
 =================================================================
 
 解説=============================================================
 
 木構造になっており、閉路が存在しないので問題を簡単にできる
 
 まず、木構造から 1 から N までに唯一　一本の経路で到達できる
 そして、その経路において、より多く自分の色で塗れば、途中の分岐などを全て
 その色で塗ることができる。
 よって、その経路をできる限り抑えさえすれば最も多くの頂点を取得することができる
 
 これは、フェネック側から見た頂点iの深さを Fennec[i] , す抜け側を Snuke[i]とすれば
 
 Fennec[i] >= Snuke[i] であれば、その頂点は Fennecのものとなる
 
 よって、これで取得できる頂点の最大個数を互いに出すことだできる
 
 最後に、その個数（ cnt_f,cnt_s とする）が
 cnt_f > cnt_s であれば Fennecが勝利する
 
 
 ================================================================
 */
ll N;

void dfs(ll n,ll dep,vector<ll>& checked,vector<vector<ll>>&G){
    checked[n] = dep;
    for(ll next : G[n]){
        if(checked[next] != -1) continue;
        dfs(next,dep+1,checked,G);
    }
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    vector<vector<ll>> G(N);
    for(int i = 0; i < N-1;i++){
        ll a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    vector<ll> Fennec(N,-1),Snuke(N,-1);
    dfs(0,0,Fennec,G);
    dfs(N-1,0,Snuke,G);
    
    ll Fennec_have = 0, Snuke_have = 0;
    for(int i = 0; i < N;i++){
        if(Fennec[i] <= Snuke[i]) Fennec_have++;
        else Snuke_have++;
    }
    if(Fennec_have > Snuke_have){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
    return 0;
}
