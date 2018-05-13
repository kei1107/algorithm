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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1243>
 問題文============================================================
 4x4の左上から順番に1から16の番号が振られたマスが存在する。（urlの図参照)
 
 このマスのうち2x2のマスに雲があり、そのマスに雨を振らせることができ、
 雲のマス(2x2)は一日ごとに上下左右いずれかの方向に0~2マス分
 移動することができる。
 
 ここで制約として、N日間の情報が与えられる。
 1が立っているマスにはn日にて雨を振らせては行けない、すなわち、2x2のマスで覆っては行けない
 また、雨が振られていないマスが7日間続いては行けない。
 
 最初に2x2の雲が 6-7-10-11のマスに存在するとき、制約を満たすような動き方が存在するか
 どうか述べよ
 
 =================================================================
 解説=============================================================
 気合bit情報メモ化シミュレーション
 
 メモ化対象として、 (i日目、雲があるマス情報(ビット),これまでの降雨情報(ビット))の状態をメモする。
 
 これまでの降雨情報に関しては １マスあたり、3bit使って 0から7までの値で過去の降雨情報を表せれる
 ================================================================
 */

map<int,int> mp;
vector<vector<int>> nextS(9);
void init(){
    int masu[4][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11},
        {12,13,14,15},
    };

    int idx = 0;
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            int S = 0;
            S = (1<<masu[i][j]) + (1<<masu[i][j+1]) + (1<<masu[i+1][j]) + (1<<masu[i+1][j+1]);
            mp[S] = idx++;
           //cout << S << " ";
        }
        //cout << endl;
    }
    /*
     51     102     204
     816    1632    3264
     13056  26112   52224
     */
    nextS[0] = vector<int>{51,102,204,816,13056};
    nextS[1] = vector<int>{51,102,204,1632,26112};
    nextS[2] = vector<int>{51,102,204,3264,52224};
    nextS[3] = vector<int>{51,816,1632,3264,13056};
    nextS[4] = vector<int>{102,816,1632,3264,26112};
    nextS[5] = vector<int>{204,816,1632,3264,52224};
    nextS[6] = vector<int>{51,816,13056,26112,52224};
    nextS[7] = vector<int>{102,1632,13056,26112,52224};
    nextS[8] = vector<int>{204,3264,13056,26112,52224};
}
set<tuple<int,int,ll>> memo;
bool dfs(int n,int S,ll clowdcnt,const vector<int>& state){
    if(n == state.size()) return true;
    if(S & state[n]) return false;
    if(memo.find(tuple<int,int,ll>(n,S,clowdcnt))!=memo.end()) return false;
    memo.insert(tuple<int,int,ll>(n,S,clowdcnt));
    for(int i = 0; i < 16; i++){
        ll nonrain = (clowdcnt>>(i*3))&7;
        clowdcnt &= (~(7LL<<(i*3)));
        nonrain++;
        if((S>>i)&1) nonrain = 0;
        if(nonrain == 7) return false;
        clowdcnt |= (nonrain<<(i*3));
    }
    int idx = mp[S];
    for(auto next:nextS[idx]) if(dfs(n+1,next,clowdcnt,state))return true;
    return false;
}
bool solve(int N){
    memo.clear();
    vector<int> state(N);
    for(int i = 0; i < N;i++){
        int B = 0;
        for(int j = 0; j < 16;j++){
            int c; cin >> c;
            B += (c<<j);
        }
        state[i] = B;
    }
    int beginS = (1<<5) + (1<<6) + (1<<9) + (1<<10);
    return dfs(0,beginS,0,state);
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    init();
    int N;
    while(cin >> N,N){
        cout << solve(N) << endl;
    }
    return 0;
}
