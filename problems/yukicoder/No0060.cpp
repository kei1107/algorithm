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
 <url:https://yukicoder.me/problems/no/60>
 問題文============================================================
 魔法少女Madokaは魔女Walpurgisnachtと戦っていた。
 Walpurgisnachtは複数の使い魔を使役しているため、短時間ですべての敵にダメージを与えない限り倒せない。
 そこでMadokaは範囲に対する攻撃魔法を使用し、効率的に敵を倒そうと考えた。
 
 Walpurgisnachtとその使い魔の座標と体力、Madokaが攻撃した範囲と敵に与えるダメージが与えられるので、
 倒せていない敵の残り体力の合計を答えよ。
 =================================================================
 解説=============================================================
 
 二次元imos法を用いて、攻撃魔法の影響範囲を最後にまとめて復元する。
 その後、敵の座標を順番に見て行って、その座標に加わる攻撃ダメージが敵のHPを超えるかどうかを
 確認していけばよい
 
 ================================================================
 */

ll masu[2010][2010];
ll solve(){
    ll res = 0;
    ll N,K; cin >> N >> K;
    vector<ll> X(N),Y(N),HP(N);
    for(int i = 0; i < N;i++) cin >> X[i] >> Y[i] >> HP[i];
    vector<ll> AX(K),AY(K),W(K),H(K),D(K);
    for(int i = 0; i < K;i++){
        cin >> AX[i]>> AY[i] >> W[i] >> H[i] >> D[i];
        
        masu[AX[i]+500][AY[i]+500] += D[i];
        masu[AX[i]+500][AY[i]+500+H[i]+1] -= D[i];
        masu[AX[i]+500+W[i]+1][AY[i]+500] -= D[i];
        masu[AX[i]+500+W[i]+1][AY[i]+500+H[i]+1] += D[i];
    }
    
    for(int i = 0; i < 2010;i++){
        for(int j = 1; j <2010;j++){
            masu[i][j] += masu[i][j-1];
        }
    }
    for(int j = 0; j < 2010;j++){
        for(int i = 1; i < 2010;i++){
            masu[i][j] += masu[i-1][j];
        }
    }
    
    for(int i = 0; i <N;i++){
        res += max(0LL,HP[i]-masu[X[i]+500][Y[i]+500]);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
