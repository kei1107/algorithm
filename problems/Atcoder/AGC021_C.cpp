#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;


/*
 <url:https://agc021.contest.atcoder.jp/tasks/agc021_c>
 問題文============================================================
 問題文
 高橋君は、縦 N マス横 M マスのマス目を持っています。
 次の条件をすべて満たすように、縦 1 マス横 2 マスのタイル A 枚と、
 縦 2 マス横 1 マスのタイル B 枚を マス目に置くことができるかどうかを判定し、可能なら置き方をひとつ構成してください。
 
 マス目の上に、全てのタイルを置かなければならない。
 タイルはマス目からはみ出してはならず、また異なるタイル同士が重なってはならない。
 マス目やタイルを回転させてはならない。
 全てのタイルは、マス目のちょうど 2 マスを完全に覆う。
 制約
 1≤N,M≤1000
 0≤A,B≤500000
 N,M,A,B は整数である

 =================================================================
 解説=============================================================
 
 前提として、タイルを置くには 2*A + 2*B <= N*M を満たさなければならない
 
 N,M共に偶数である時、
 タイルはそれぞれ 1x2 と 2x1 という形であるため、
 2x2の区間に 1x2のタイルと 2x1 のタイルを同時に置くことが出来ず、
 1x2 を 2枚 、2x1 を　2枚　置いて行けば 2x2のマスを最大限有用に用いることができる
 
 よって、2x2のマスごとにタイルの置き方を考えて行けば良い
 
 ここて、N,Mのどちらか、もしくは片方が奇数の場合を考える
 例えばNが奇数の時
     2x1 のタイルをギリギリまでおいたとしてもN行目が丸々余ることになる。
     よって、N行目の部分に 1x2 のタイルを独占して置くことができる
 
 Mが奇数の場合も同様の考えができる
 
 
 最後に、例外パターンとして
 
     <>^
     ^.v
     v<>
 
 のような置き方が考えられるため、このような形が作れる盤面とタイルの枚数に注意して復元すれば良い
 
 ================================================================
 */
void solve_C();
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve_C();
    return 0;
}

void solve_C(){
    ll N,M,A,B; cin >> N >> M >> A >> B;
    if(2*A + 2*B > N*M){
        cout << "NO" << endl;
        return;
    }
    
    ll nN = N,nM = M;
    vector<vector<char>> c(N+1,vector<char>(M+1,'.'));
    if(N%2 == 1 && M%2 == 1){
        N--; M--;
        for(ll w = 1; w <= M; w+=2){
            if(A == 0) break;
            c[nN][w] = '<'; c[nN][w+1] = '>';
            A--;
        }
        for(ll h = 1; h <= N; h+=2){
            if(B == 0) break;
            c[h][nM] = '^'; c[h+1][nM] = 'v';
            B--;
        }
    }else if(N%2 == 1){
        N--;
        for(ll w = 1; w <= M; w+=2){
            if(A == 0) break;
            c[nN][w] = '<'; c[nN][w+1] = '>';
            A--;
        }
    }else if(M%2 == 1){
        M--;
        for(ll h = 1; h <= N; h+=2){
            if(B == 0) break;
            c[h][nM] = '^'; c[h+1][nM] = 'v';
            B--;
        }
    }
    
    if(2*A + 2*B > N*M){
        cout << "NO" << endl;
        return;
    }
    
    for(ll i = 1; i <= N; i+=2){
        for(ll j = 1; j <= M; j+=2){
            if(A == 0 && B == 0) continue;
            if(i == N - 1 && j == M - 1 && nN%2 == 1 && nM%2 == 1 && A == 1 && B == 1){
                
                for(ll ii = N - 1; ii <= N+1; ii++){
                    for(ll jj = M - 1; jj <= M+1; jj++){
                        c[ii][jj] = '.';
                    }
                }
                c[N-1][M-1] = '^'; c[N][M-1] = 'v';
                c[N-1][M] = '<'; c[N-1][M+1] = '>';
                c[N][M+1] = '^'; c[N+1][M+1] = 'v';
                c[N+1][M-1] = '<'; c[N+1][M] = '>';
                A--; B--;
                continue;
            }
            
            if(A >= 2){
                c[i][j] = '<'; c[i][j+1] = '>';
                A--;
                c[i+1][j] = '<'; c[i+1][j+1] = '>';
                A--;
            }else if(B >= 2){
                c[i][j] = '^'; c[i+1][j] = 'v';
                B--;
                c[i][j+1] = '^'; c[i+1][j+1] = 'v';
                B--;
            }else if(A == 1){
                c[i][j] = '<'; c[i][j+1] = '>';
                A--;
            }else if(B == 1){
                c[i][j] = '^'; c[i+1][j] = 'v';
                B--;
            }
        }
    }
    if(A != 0 || B != 0){
        cout << "NO" << endl;
        return;
    }else{
        cout << "YES" << endl;
        for(ll i = 1; i <= nN;i++){
            for(ll j = 1; j <= nM; j++){
                cout << c[i][j];
            }
            cout << endl;
        }
    }
    return;
}
