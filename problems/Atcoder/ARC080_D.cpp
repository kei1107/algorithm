#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc080.contest.atcoder.jp/tasks/arc080_b>
問題文============================================================
 縦 H 行、横 W 列のマス目があります。
 すぬけ君は、このマス目を色 1, 2, …, N で塗り分けようとしています。 このとき、次の条件が成り立つようにします。
 
 各 i (1≤i≤N) について、色 i のマスはちょうど ai 個存在する。 ただし、a1+a2+…+aN=HW である。
 
 各 i (1≤i≤N) について、色 i のマスは上下左右に連結である。
 すなわち、どの色 i のマスからどの色 i のマスへも、上下左右に隣り合う色 i のマスのみを辿って行き来できる。
 
 条件を満たす塗り分け方をひとつ求めてください。 解は必ず存在することが示せます。

=================================================================

解説=============================================================

 蛇のようにマスをなぞりながら値を入れていけばok
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll H,W; cin >> H >> W;
    ll N; cin >> N;
    vector<ll> a(N);
    for(auto& in:a) cin >> in;
    
    
    vector<vector<int>> masu(H+2,vector<int>(W+2,-1));
    for(int i = 1; i <=H;i++) for(int j = 1; j<= W;j++) masu[i][j] = 0;
    
    int aidx = 0;
    for(int i = 1; i<= H;i++){
        if(i%2 == 1){
            for(int j = 1; j <= W;j++){
                masu[i][j] = aidx+1;
                a[aidx]--;
                if(a[aidx] == 0) aidx++;
            }
        }else{
            for(int j = W; j >= 1;j--){
                masu[i][j] = aidx+1;
                a[aidx]--;
                if(a[aidx] == 0) aidx++;
            }
        }
    }
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W;j++){
            cout << masu[i][j] << " ";
        }
        cout << endl;
    }
    
	return 0;
}
