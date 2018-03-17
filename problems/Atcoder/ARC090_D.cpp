#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc090.contest.atcoder.jp/tasks/arc090_b>
問題文============================================================
 x 軸上に N 人の人が立っています。 人 i の位置を xi とします。
 任意の i に対して、xi は 0 以上 109 以下の整数です。
 同じ位置に複数の人が立っていることもありえます。
 
 これらの人の位置に関する情報が M 個与えられます。
 このうち i 個めの情報は (Li,Ri,Di) という形をしています。
 この情報は、人 Ri は人 Li よりも距離 Di だけ右にいること、
 すなわち、xRi−xLi=Di が成り立つことを表します。
 
 これら M 個の情報のうちのいくつかに誤りがある可能性があることがわかりました。
 与えられる M 個すべての情報と矛盾しないような値の組 (x1,x2,…,xN) が存在するかどうか判定してください。
=================================================================

解説=============================================================

 互いに到達できる頂点集合の中で、一つの頂点を基準位置として、
 グラフのように各頂点を辿っていきながら矛盾がないかどうか確認していけば良い
 
================================================================
*/
int N,M;
struct edge{
    int L,R,D;
    edge(){}
    edge(int L,int R,int D):L(L),R(R),D(D){}
};
vector<vector<edge>> G;

bool dfs(int n,bool first,vector<int>& checked,vector<ll>& loc){
    if(first) loc[n] = 0;
    checked[n] = 1;
    for(edge& e:G[n]){
        if(checked[e.R] == 0){
            loc[e.R] = loc[e.L] + e.D;
            if(!dfs(e.R,false,checked,loc))return false;
        }else{
            if(loc[e.R] != loc[e.L] + e.D) return false;
        }
    }
    return true;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    G.resize(N);
    for(int i = 0; i < M;i++){
        int L,R,D; cin >> L >> R >> D;
        L--; R--;
        G[L].push_back(edge(L,R,D));
        G[R].push_back(edge(R,L,-D));
    }
    
    vector<int> checked(N,0);
    vector<ll> loc(N,LINF);
    for(int i = 0; i < N;i++){
        if(checked[i]) continue;
        if(!dfs(i,true,checked,loc)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
	return 0;
}
