#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://cf17-relay-open.contest.atcoder.jp//tasks/relay2_d>
 問題文============================================================
 無向グラフ G が与えられます。G は N 個の頂点と M 本の辺を持ちます。
 G の頂点には 1 から N までの番号が付けられており、G の i 番目の辺 (1≤i≤M) は頂点 ai と bi を結びます。
 G は自己辺や多重辺を持ちません。
 
 あなたは、G の二頂点間に辺を付け足す操作を繰り返し行うことができます。
 ただし、その結果 G が自己辺や多重辺を持ってはなりません。
 また、頂点 1 と 2 が直接的または間接的に辺で結ばれてしまうと、
 あなたの身体を 1000000007 ボルトの電圧が襲います。これも避けなければなりません。
 
 これらの条件のもとで、最大で何本の辺を付け足すことができるでしょうか？
 なお、頂点 1 と頂点 2 がはじめから直接的または間接的に辺で結ばれていることはありません。
 =================================================================
 解説=============================================================
 頂点1に繋がっている集合1と頂点2に繋がっている集合2、
 頂点1と2のどちらにも繋がっていない集合3に分ける。
 
 ある集合に着目した時、その集合で加えることのできる辺は、完全グラフになるまで加えることができるため、
 集合数 := S とすれば S*(S-1)/2 - (集合内の辺の数) となる。
 
 ここで、集合3について、この集合は集合1or2と合流させることで加えることのできる辺の本数は多くなる
 よって集合１と集合2のうち頂点数の大きい方の集合と集合3を合流させれば、その集合たちで完全グラフに
 なるまで加えた辺の本数がこたえ
 
 ================================================================
 */

void dfs(ll n,vector<int>& can_use,vector<vector<ll>>& G,int f){
    for(auto next:G[n]){
        if(can_use[next] == 0){
            can_use[next] = f;
            dfs(next,can_use,G,f);
        }
    }
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    vector<vector<ll>> G(N);
    vector<pll> ab(M);
    for(int i = 0; i < M;i++){
        ll a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        ab[i] = {a,b};
    }
    vector<int> can_use(N,0);
    can_use[0] = 1;
    dfs(0,can_use,G,1);
    can_use[1] = 2;
    dfs(1,can_use,G,2);

    ll cnt1 = 0,cnt2 = 0;
    
    for(auto use:can_use){
        if(use == 1)cnt1++;
        if(use == 2)cnt2++;
    }
    
    bool f = false;
    if(cnt1 < cnt2){
        f = true;
    }
    for(auto use:can_use){
        if(use == 0){
            if(f){
                cnt2++;
            }else{
                cnt1++;
            }
        }
    }
    
    ll e_cnt1 = 0,e_cnt2 = 0;
    for(int i = 0; i < M;i++){
        if(can_use[ab[i].first] == 0){
            if(f){
                e_cnt2++;
            }else{
                e_cnt1++;
            }
        }
        if(can_use[ab[i].first] == 1) e_cnt1++;
        if(can_use[ab[i].first] == 2) e_cnt2++;
    }
    ll ans1 = (cnt1*(cnt1 -1))/2 - e_cnt1;
    ll ans2 = (cnt2*(cnt2-1))/2 - e_cnt2;
    cout << ans1 + ans2 << endl;
    return 0;
}
