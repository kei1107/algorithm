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
 <url:https://yukicoder.me/problems/no/319>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 2種類の桁dpを行う
 
 まず、この手の範囲がある問題は
 F(x) := 1..Nまでで条件を満たすものの総数
 を定義してやると
 F(B) - F(A-1)
 の形で答えを出す事ができる
 
 よって、今回の問題もこの形式になんとかして落とし込みたい
 一度に全部考えるのは辛いので、この問題を二つの小問題に分割することにする
 
 小問題1. 1..Nまでの数字中に存在する'12'の数
 小問題2. 1..Nまでの数字の中で連続する二つの数字を繋げたときに oooooo1 + 2oooooo となるようなものの個数
 
 小問題1.
 これは単純な桁dpで解く事ができる。具体的には
    dp[桁数][12の数(制約から最大でも6個)][直前に見た桁の値が1か否か][必ず最大値を下回るか否か]
 
 
 小問題2.
 これに関しても桁dpで解く事が可能。この時、先頭および末尾の桁の数が2であれば条件を満たす数字が作れるため、
 先頭および末尾の桁が2であるものの総数を桁dpで計算すればいい
    dp[桁数][先頭の桁の数][末尾の桁の数][必ず最大値を下回るか否か]
 
 
 よって今回の問題の答えは
 小問題1.および2.について F(B) - F(A-1) の形で計算した結果の和を出してやればいい。
 注意事項として、小問題2.についてA自身が先頭および末尾の桁が2である場合は、
 1つだけ余分に数えてしまうことになるためこの場合はあらかじめ答えを1だけ引いておく
 ================================================================
 */

ll dp1[15][10][2][2]; // 桁数,12の数,直前が1か否か,V未満か否か
ll calc1(ll V){ // [1,V]までの数字に12が含まれる数を返す
    ll res = 0;
    string S = to_string(V);
    fill(***dp1,***dp1+15*10*2*2,0);
    dp1[0][0][0][0] = 1;
    for(int i = 0; i < S.length();i++){
        for(int j = 0; j < 10;j++){
            for(int k = 0; k < 2;k++){
                for(int l = 0; l < 2;l++){
                    if(dp1[i][j][k][l] == 0) continue;
                    int lim = l?9:S[i]-'0';
                    for(int d = 0; d <= lim; d++){
                        dp1[i+1][j+((k==1)&&(d==2))][d==1][l|(d<lim)] += dp1[i][j][k][l];
                    }
                }
            }
        }
    }

    for(int j = 0; j < 10;j++){
        for(int k = 0; k < 2;k++){
            for(int l = 0; l < 2;l++){
                res += dp1[S.length()][j][k][l]*j;
            }
        }
    }
    return res;
}

ll dp2[15][10][10][2]; // 桁数,先頭の数,末尾の数,V未満か
ll calc2(ll V){ // 連続する二つの数字を繋げた時に ooooo1 + 2oooooo となるような数
    ll res = 0;
    string S = to_string(V);
    
    fill(***dp2,***dp2+15*10*10*2,0);
    for(int i = 0; i < S.length();i++){
        for(int j = 0; j < 10;j++){
            for(int k = 0; k < 10;k++){
                for(int l = 0; l < 2;l++){
                    int lim = l?9:S[i]-'0';
                    for(int d = 0; d <= lim; d++){
                        dp2[i+1][j][d][l||(d<lim)] += dp2[i][j][k][l];
                    }
                }
            }
        }
        if(i==0){
            int lim = S[i]-'0';
            for(int d = 0; d <= lim;d++) dp2[i+1][d][d][d<lim]++;
        }else{
            int lim = 9;
            for(int d = 0; d <= lim;d++) dp2[i+1][d][d][1]++;
        }
    }
    
    res += dp2[S.length()][2][2][0] + dp2[S.length()][2][2][1];
    return res;
}
ll solve(){
    ll res = 0;
    ll A,B; cin >> A >> B;
    string strA = to_string(A);
    if(strA.front()=='2' && strA.back()=='2') res--;
    res += calc1(B) - calc1(A-1);
    res += calc2(B) - calc2(A-1);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
