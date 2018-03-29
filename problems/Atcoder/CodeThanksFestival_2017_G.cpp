#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://code-thanks-festival-2017-open.contest.atcoder.jp/tasks/code_thanks_festival_2017_g>
問題文============================================================
 イルカの手元には 1 から N までの番号が付いた N 種類の薬品があります。
 また、薬品の取り扱いについて書かれたリストが手元にあります。
 このリストには M 個の項目があり、
 リストの上から i(1≦i≦M) 番目の項目には「番号 ai と 番号 bi の薬品を混合すると毒が発生する。」と書いてあります。
 
 イルカは、リストに基づいて毒が発生しないように、
 できる限り多くの種類の薬品を混合したいと考えています。
 イルカは最大で何種類の薬品を混合できますか?

=================================================================

解説=============================================================

 難しい。。。。
 
 半分全列挙 + bitdp を行う。
 ※ 頂点は0-indexとする
 まず、頂点集合を前半 V1 , と後半 V2 に分ける
 
 ここで、前半のみでの条件を満たすような独立な集合を求める(:= dp1)
 
 次に、dp1での集合 S に対して、　後半部V2 との辺が貼られていない集合 dp2 を求める
 この時、ex. dp2[101] := 110 であれば 頂点 0 or 2 は　頂点 3 との辺が貼られており、考慮できないことを示す
 
 最後に、後半の頂点集合に対して、その部分集合 S で見たときの条件を満たす最大個数をdp3とする
 dp2[101] := 110 の例において,
 辺(4,5)が存在しなければ dp3[dp2[101]] = dp3[110] = 2
         存在すれば     dp3[dp2[101]] = 1
 といったような風になる
 
 最後に前半の頂点集合 bit から dp3[dp2[bit]] とすることで後半で得られる頂点の個数がわかるので
 条件を満たす全ての前半bitに対して __buildin_popcount(bit) + dp3[dp2[bit]] の最大数が答え
 
================================================================
*/

int solve(){
    int res = 0;
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N,vector<int>(N,0));
    for(int i = 0; i < M; i++){
        int a,b; cin >> a >> b; a--; b--;
        G[a][b] = G[b][a] = true;
    }
    int N1 = N/2, N2 = N - N1;
    
    // dp1[S] := 集合Sが条件を満たすかどうか
    vector<int> dp1(1<<N1,false);
    dp1[0] = true;
    for(int bit = 0; bit < (1<<N1);bit++){
        if(!dp1[bit])continue;
        for(int i = 0; i < N1;i++){
            if((bit>>i)&1)continue;
            [&]{
                for(int j = 0; j < N1;j++) if((bit>>j)&1 && G[i][j]) return;
                dp1[bit|(1<<i)] = true;
            }();
        }
    }
    
    // dp2[S] := 前半の集合Sと独立な後半の頂点集合
    vector<int> dp2(1<<N1,-1);
    dp2[0] = (1<<N2)-1;
    for(int bit = 0; bit < (1<<N1); bit++){
        if(dp2[bit] == -1) continue;
        for(int i = 0; i < N1;i++){
            if((bit>>i)&1)continue;
            int k = 0;
            for(int j = 0; j < N2;j++){
                if(G[i][N1+j]) k |= (1<<j);
            }
            dp2[bit|(1<<i)] &= dp2[bit]&(~k);
        }
    }
    
    // dp3[S] := 後半の頂点集合で、作れる独立な頂点集合の個数の最大値
    vector<int> dp3(1<<N2,-1);
    dp3[0] = 0;
    for(int bit = 0; bit < (1<<N2);bit++){
        if(dp3[bit] == -1)continue;
        for(int i = 0; i < N2;i++){
            if((bit>>i)&1)continue;
            [&]{
                for(int j = 0; j < N2;j++){
                    if(!((bit>>j)&1)) continue;
                    if(G[N1+i][N1+j]){
                        dp3[bit|1<<i] = max(dp3[bit|1<<i],dp3[bit]);
                        return;
                    }
                }
                dp3[bit|1<<i] = max(dp3[bit|1<<i],dp3[bit]+1);
            }();
        }
    }
    for(int bit = 0; bit < (1<<N1); bit++){
        if(dp1[bit] == false) continue;
        res = max(res,__builtin_popcount(bit)+dp3[dp2[bit]]);
    }
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
