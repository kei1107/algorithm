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
 <url:https://beta.atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_f>
 問題文============================================================
 埼大君はMaximum小学校の職員で、給食の献立作成担当をしています。
 そろそろ献立表を作らなくてはいけない時期になってきたので、埼大君は献立表を考えることにしました。
 献立はバランスが大事です。和食ばかりの献立や、洋食ばかりの献立では生徒に飽きられてしまいます。
 
 そこで、まずその日に出すメニューのジャンルを決めることにしました。メニューは、
 
 和食のメニュー
 洋食のメニュー
 中華のメニュー
 和食洋食混合のメニュー
 和食中華混合のメニュー
 洋食中華混合のメニュー
 和・洋・中ごちゃまぜメニュー
 の 7 種類です。
 
 今回考えたいのは「どの連続した K 日間でも同じジャンルが含まれるメニューを出す日をL日以下」
 という条件を満たしたN日間の給食の献立です。
 
 ここで、混合メニューやごちゃまぜメニューを出すと、その中に含まれるすべてのジャンルを出したことになります。
 例えば和洋混合メニューを出したとすると、その日は和食メニューと洋食メニューを両方出したことになります。
 詳しくは下の表を参照してください。
 
 さて、それを見ていた組み合わせマスターのあなたはふと思いました。
 
 「これは、何通り考えられるだろう、、、？？？」
 
 この条件を満たす献立の組み合わせの総数を求めてください。
 
 なお、答えは非常に大きくなる可能性があるため、1000000007の余りの形で出力してください。
 =================================================================
 解説=============================================================
 
 状態保存のbitDPっぽいのでbitDPをゴリゴリかく。
 
 dp[i][S] := i日目の時、直近K-1日間の食事状況がSとなる献立の組み合わせの総数
 ================================================================
 */

const ll MOD = 1e9+7;
#define MAX_N 370
ll dp[MAX_N][1<<12];
int wa =  1 | (1<<3) | (1<<6) | (1<<9) | (1<<12);
int chu = 2 | (1<<4) | (1<<7) | (1<<10) | (1<<13);
int you = 4 | (1<<5) | (1<<8) | (1<<11) | (1<<14);
ll solve(){
    ll res = 0;
    ll N,K,L; cin >> N >> K >> L;
    dp[0][0] = 1;
    int base = 1<<(3*(K-1));
    for(int i = 0; i < N;i++){
        for(int j = 0; j < base;j++){
            if(dp[i][j] == 0) continue;
            for(int k = 1; k < (1<<3);k++){
                int S = (j<<3) | k;
                if(__builtin_popcount(S&wa) > L) continue;
                if(__builtin_popcount(S&chu) > L) continue;
                if(__builtin_popcount(S&you) > L) continue;
                (dp[i+1][S&(base-1)] += dp[i][j])%=MOD;
            }
        }
    }
    for(int j = 0; j < base;j++) (res += dp[N][j])%=MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
